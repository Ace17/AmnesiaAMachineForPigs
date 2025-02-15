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

#include "sound/Sound.h"

#include "resources/Resources.h"
#include "sound/LowLevelSound.h"
#include "sound/MusicHandler.h"
#include "sound/SoundHandler.h"
#include "system/LowLevelSystem.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cSound::cSound(iLowLevelSound* apLowLevelSound)
    : iUpdateable("HPL_Sound")
{
    mpLowLevelSound = apLowLevelSound;
}

//-----------------------------------------------------------------------

cSound::~cSound()
{
    Log("Exiting Sound Module\n");
    Log("--------------------------------------------------------\n");

    hplDelete(mpSoundHandler);
    hplDelete(mpMusicHandler);

    Log("--------------------------------------------------------\n\n");
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cSound::Update(float afTimeStep)
{
    mpSoundHandler->Update(afTimeStep);
    mpMusicHandler->Update(afTimeStep);

    mpLowLevelSound->UpdateSound(afTimeStep);
}

//-----------------------------------------------------------------------

void cSound::Init(cResources* apResources,
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
      bool abEnableLowLevelLog)
{
    mpResources = apResources;

    Log("Initializing Sound Module\n");
    Log("--------------------------------------------------------\n");

    mpLowLevelSound->Init(alSoundDeviceID, abUseEnvAudio, alMaxChannels, alStreamUpdateFreq, abUseThreading, abUseVoiceManagement, alMaxMonoSourceHint, alMaxStereoSourceHint,
          alStreamingBufferSize, alStreamingBufferCount, abEnableLowLevelLog);

    mpSoundHandler = hplNew(cSoundHandler, (mpLowLevelSound, mpResources));
    mpMusicHandler = hplNew(cMusicHandler, (mpLowLevelSound, mpResources));

    Log("--------------------------------------------------------\n\n");
}

//-----------------------------------------------------------------------

} // namespace hpl
