/*
 * Copyright © 2011-2020 Frictional Games
 *
 * This file is part of Amnesia: A Machine For Pigs.
 *
 * Amnesia: A Machine For Pigs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Amnesia: A Machine For Pigs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Amnesia: A Machine For Pigs.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "graphics/PostEffectComposite.h"

#include "graphics/GPUProgram.h"
#include "graphics/GPUShader.h"
#include "graphics/Graphics.h"
#include "graphics/LowLevelGraphics.h"
#include "graphics/PostEffect.h"
#include "graphics/Texture.h"
#include "graphics/VertexBuffer.h"
#include "system/LowLevelSystem.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cPostEffectComposite::cPostEffectComposite(cGraphics* apGraphics)
{
    mpGraphics = apGraphics;
    SetupRenderFunctions(mpGraphics->GetLowLevel());

    cVector2l vSize = mpLowLevelGraphics->GetScreenSizeInt();
    for (int i = 0; i < 2; ++i)
    {
        mpFinalTempBuffer[i] = mpGraphics->GetTempFrameBuffer(vSize, ePixelFormat_RGBA, i);
    }
}

//-----------------------------------------------------------------------

cPostEffectComposite::~cPostEffectComposite()
{
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cPostEffectComposite::Render(float afFrameTime, cFrustum* apFrustum, iTexture* apInputTexture, cRenderTarget* apRenderTarget)
{
    ////////////////////////////////
    // Set up stuff needed for rendering
    BeginRendering(afFrameTime, apFrustum, apInputTexture, apRenderTarget);

    ////////////////////////////////
    // Iterate post effects and find the last one.
    iPostEffect* pLastEffect = NULL;
    tPostEffectMapIt it = m_mapPostEffects.begin();
    for (; it != m_mapPostEffects.end(); ++it)
    {
        iPostEffect* pPostEffect = it->second;
        if (pPostEffect->IsActive() == false)
            continue;

        pLastEffect = pPostEffect;
    }

    ////////////////////////////////
    // Iterate post effects and render them
    int lCurrentTempBuffer = 0;
    iTexture* pInputTex = apInputTexture;
    it = m_mapPostEffects.begin();
    for (; it != m_mapPostEffects.end(); ++it)
    {
        iPostEffect* pPostEffect = it->second;
        if (pPostEffect->IsActive() == false)
            continue;

        bool bLastEffect = pPostEffect == pLastEffect;

        pInputTex = pPostEffect->Render(this, pInputTex, mpFinalTempBuffer[lCurrentTempBuffer], bLastEffect);

        lCurrentTempBuffer = lCurrentTempBuffer == 0 ? 1 : 0;
    }

    ///////////////////////////////
    // Reset rendering stuff
    EndRendering();
}

//-----------------------------------------------------------------------

void cPostEffectComposite::AddPostEffect(iPostEffect* apPostEffect, int alPrio)
{
    if (apPostEffect == NULL)
        return;

    m_mapPostEffects.insert(tPostEffectMap::value_type(alPrio, apPostEffect));
    mvPostEffects.push_back(apPostEffect);
}

//-----------------------------------------------------------------------

bool cPostEffectComposite::HasActiveEffects()
{
    if (mvPostEffects.empty())
        return false;

    bool bActiveEffect = false;
    for (size_t i = 0; i < mvPostEffects.size(); ++i)
    {
        if (mvPostEffects[i]->IsActive())
        {
            bActiveEffect = true;
            break;
        }
    }

    return bActiveEffect;
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cPostEffectComposite::BeginRendering(float afFrameTime, cFrustum* apFrustum, iTexture* apInputTexture, cRenderTarget* apRenderTarget)
{
    ///////////////////////////////
    // Init the render functions
    mfCurrentFrameTime = afFrameTime;

    InitAndResetRenderFunctions(apFrustum, apRenderTarget, false);

    ///////////////////////////////
    // Init the render states
    mpLowLevelGraphics->SetColorWriteActive(true, true, true, true);

    mpLowLevelGraphics->SetCullActive(true);
    mpLowLevelGraphics->SetCullMode(eCullMode_CounterClockwise);

    SetDepthTest(false);
    SetDepthWrite(false);
    mpLowLevelGraphics->SetDepthTestFunc(eDepthTestFunc_LessOrEqual);

    mpLowLevelGraphics->SetColor(cColor(1, 1, 1, 1));

    for (int i = 0; i < kMaxTextureUnits; ++i)
        mpLowLevelGraphics->SetTexture(i, NULL);
}

//-----------------------------------------------------------------------

void cPostEffectComposite::EndRendering()
{
    /////////////////////////////////////////////
    // Reset all rendering states
    SetBlendMode(eMaterialBlendMode_None);
    SetChannelMode(eMaterialChannelMode_RGBA);

    /////////////////////////////////////////////
    // Unbind all rendering data
    for (int i = 0; i < kMaxTextureUnits; ++i)
    {
        if (mvCurrentTexture[i])
            mpLowLevelGraphics->SetTexture(i, NULL);
    }

    if (mpCurrentProgram)
        mpCurrentProgram->UnBind();
    if (mpCurrentVtxBuffer)
        mpCurrentVtxBuffer->UnBind();

    /////////////////////////////////////////////
    // Clean up render functions
    ExitAndCleanUpRenderFunctions();
}

//-----------------------------------------------------------------------

/*void cPostEffectComposite::CopyToFrameBuffer(iTexture *apOutputTexture)
{
        SetDepthTest(false);
        SetDepthWrite(false);
        SetBlendMode(eMaterialBlendMode_None);
        SetAlphaMode(eMaterialAlphaMode_Solid);
        SetChannelMode(eMaterialChannelMode_RGBA);

        SetFrameBuffer(mpCurrentRenderTarget->mpFrameBuffer,true);

        SetFlatProjection();

        SetProgram(NULL);
        SetTexture(0,apOutputTexture);
        SetTextureRange(NULL, 1);

        ////////////////////////////////////
        //Draw the accumulation buffer to the current frame buffer
        //Since the texture v coordinate is reversed, need to do some math.
        cVector2f vViewportPos((float)mpCurrentRenderTarget->mvPos.x, (float)mpCurrentRenderTarget->mvPos.y);
        cVector2f vViewportSize((float)mvRenderTargetSize.x, (float)mvRenderTargetSize.y);
        DrawQuad(	cVector2f(0,0),1,
                                cVector2f(vViewportPos.x, (mvScreenSizeFloat.y - vViewportSize.y)-vViewportPos.y ),
                                cVector2f(vViewportPos.x + vViewportSize.x,mvScreenSizeFloat.y - vViewportPos.y),
                                true);
}*/

//-----------------------------------------------------------------------

} // namespace hpl
