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

class cPostEffectParams_Bloom : public iPostEffectParams
{
public:
    cPostEffectParams_Bloom()
        : iPostEffectParams("Bloom")
        , mvRgbToIntensity(0.3f, 0.58f, 0.12f)
        , mlBlurIterations(2)
        , mfBlurSize(1.0f)
    {
    }

    kPostEffectParamsClassInit(cPostEffectParams_Bloom)

          cVector3f mvRgbToIntensity;

    float mfBlurSize;
    int mlBlurIterations;
};

//------------------------------------------

class cPostEffectType_Bloom : public iPostEffectType
{
    friend class cPostEffect_Bloom;

public:
    cPostEffectType_Bloom(cGraphics* apGraphics, cResources* apResources);
    virtual ~cPostEffectType_Bloom();

    iPostEffect* CreatePostEffect(iPostEffectParams* apParams);

private:
    iGpuProgram* mpBlurProgram[2];
    iGpuProgram* mpBloomProgram;
};

//------------------------------------------

}; // namespace hpl
