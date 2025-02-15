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

#pragma once

#include "graphics/PostEffect.h"

namespace hpl
{

//------------------------------------------

class cPostEffectParams_RadialBlur : public iPostEffectParams
{
public:
    cPostEffectParams_RadialBlur()
        : iPostEffectParams("RadialBlur")
        , mfSize(0.06f)
        , mfAlpha(1.0f)
        , mfBlurStartDist(0)
    {
    }

    kPostEffectParamsClassInit(cPostEffectParams_RadialBlur)

          float mfSize;
    float mfAlpha;
    float mfBlurStartDist;
};

//------------------------------------------

class cPostEffectType_RadialBlur : public iPostEffectType
{
    friend class cPostEffect_RadialBlur;

public:
    cPostEffectType_RadialBlur(cGraphics* apGraphics, cResources* apResources);
    virtual ~cPostEffectType_RadialBlur();

    iPostEffect* CreatePostEffect(iPostEffectParams* apParams);

private:
    iGpuProgram* mpProgram;
};

//------------------------------------------

class cPostEffect_RadialBlur : public iPostEffect
{
public:
    cPostEffect_RadialBlur(cGraphics* apGraphics, cResources* apResources, iPostEffectType* apType);
    ~cPostEffect_RadialBlur();

    void Reset();

private:
    void OnSetParams();
    iPostEffectParams* GetTypeSpecificParams() { return &mParams; }

    iTexture* RenderEffect(iTexture* apInputTexture, iFrameBuffer* apFinalTempBuffer);

    void RenderBlur(iTexture* apInputTex);

    cPostEffectType_RadialBlur* mpRadialBlurType;
    cPostEffectParams_RadialBlur mParams;
};

//------------------------------------------

}; // namespace hpl
