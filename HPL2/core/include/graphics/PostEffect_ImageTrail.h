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

class cPostEffectParams_ImageTrail : public iPostEffectParams
{
public:
    cPostEffectParams_ImageTrail()
        : iPostEffectParams("ImageTrail")
        ,

        mfAmount(0.3f)
    {
    }

    kPostEffectParamsClassInit(cPostEffectParams_ImageTrail)

          float mfAmount;
};

//------------------------------------------

class cPostEffectType_ImageTrail : public iPostEffectType
{
    friend class cPostEffect_ImageTrail;

public:
    cPostEffectType_ImageTrail(cGraphics* apGraphics, cResources* apResources);
    virtual ~cPostEffectType_ImageTrail();

    iPostEffect* CreatePostEffect(iPostEffectParams* apParams);

private:
    iGpuProgram* mpProgram;
};

//------------------------------------------

class cPostEffect_ImageTrail : public iPostEffect
{
public:
    cPostEffect_ImageTrail(cGraphics* apGraphics, cResources* apResources, iPostEffectType* apType);
    ~cPostEffect_ImageTrail();

    void Reset();

private:
    void OnSetActive(bool abX);
    void OnSetParams();
    iPostEffectParams* GetTypeSpecificParams() { return &mParams; }

    iTexture* RenderEffect(iTexture* apInputTexture, iFrameBuffer* apFinalTempBuffer);

    iFrameBuffer* mpAccumBuffer;
    iTexture* mpAccumTexture;

    cPostEffectType_ImageTrail* mpImageTrailType;
    cPostEffectParams_ImageTrail mParams;

    bool mbClearFrameBuffer;
};

//------------------------------------------

}; // namespace hpl
