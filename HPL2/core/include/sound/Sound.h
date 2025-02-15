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

#include "engine/Updateable.h"

namespace hpl
{

class iLowLevelSound;
class cResources;
class cSoundHandler;
class cMusicHandler;

class cSound : public iUpdateable
{
public:
    cSound(iLowLevelSound* apLowLevelSound);
    ~cSound();

    void Init(cResources* apResources,
          int alSoundDeviceID,
          bool abUseEnvAudio,
          int alMaxChannels,
          int alStreamUpdateFreq,
          bool abUseThreading,
          bool abUseVoiceManagement,
          int alMaxMonoSourceHint,
          int alMaxStereoSourceHint,
          int alStreamingBufferSize,
          int alStreamingBufferCount,
          bool abEnableLowLevelLog);

    void Update(float afTimeStep);

    iLowLevelSound* GetLowLevel() { return mpLowLevelSound; }
    cSoundHandler* GetSoundHandler() { return mpSoundHandler; }
    cMusicHandler* GetMusicHandler() { return mpMusicHandler; }

private:
    iLowLevelSound* mpLowLevelSound;
    cResources* mpResources;
    cSoundHandler* mpSoundHandler;
    cMusicHandler* mpMusicHandler;
};

}; // namespace hpl
