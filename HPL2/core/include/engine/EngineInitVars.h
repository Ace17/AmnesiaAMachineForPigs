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

#include "graphics/GraphicsTypes.h"
#include "math/MathTypes.h"
#include "system/SystemTypes.h"

namespace hpl
{

//---------------------------------------

class cEngineInitVars
{
public:
    ////////////////////////////////
    // Game
    class cEngineVars
    {
    public:
        cEngineVars()
            : mlUpdateRate(60)
            , mlMaxFramesPerSec(60)
        {
        }

        int mlUpdateRate;
        int mlMaxFramesPerSec;
    };
    cEngineVars mGame;

    ////////////////////////////////
    // Graphics
    class cGraphicsVars
    {
    public:
        cGraphicsVars()
            : mvScreenSize(800, 600)
            , mlDisplay(0)
            , mlScreenBpp(32)
            , mbFullscreen(false)
            , mlMultisampling(0)
            , msWindowCaption("")
            , mvWindowPosition(-1)
            , mGpuProgramFormat(eGpuProgramFormat_LastEnum)
        {
        }

        cVector2l mvScreenSize;
        int mlDisplay;
        int mlScreenBpp;
        bool mbFullscreen;
        int mlMultisampling;
        tString msWindowCaption;
        cVector2l mvWindowPosition;
        eGpuProgramFormat mGpuProgramFormat;
    };
    cGraphicsVars mGraphics;

    ////////////////////////////////
    // Sound
    class cSoundVars
    {
    public:
        cSoundVars()
            : mlSoundDeviceID(-1)
            , mbUseEnvironmentalAudio(false)
            , mbUseThreading(true)
            , mbUseVoiceManagement(true)
            , mbLowLevelLogging(false)
            , mlStreamUpdateFreq(10)
            , mlMaxChannels(32)
            , mlMaxMonoChannelsHint(0)
            , mlMaxStereoChannelsHint(0)
            , mlStreamBufferSize(524288)
            , mlStreamBufferCount(2)
        {
        }

        int mlSoundDeviceID;
        bool mbUseEnvironmentalAudio;
        bool mbUseThreading;
        bool mbUseVoiceManagement;
        bool mbLowLevelLogging;
        int mlStreamUpdateFreq;
        int mlMaxChannels;
        int mlMaxMonoChannelsHint;
        int mlMaxStereoChannelsHint;
        int mlStreamBufferSize;
        int mlStreamBufferCount;
    };
    cSoundVars mSound;
};

//---------------------------------------

}; // namespace hpl

