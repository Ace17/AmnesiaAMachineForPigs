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

#include "sound/SoundChannel.h"

#include "resources/SoundManager.h"
#include "sound/SoundData.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

iSoundChannel::iSoundChannel(iSoundData* apData, cSoundManager* apSoundManger)
{
    mbLooping = false;
    mbPaused = true;
    mbPositionRelative = false;

    mfSpeed = 1;
    mfVolume = 1;
    mfMaxDistance = 0;
    mfMinDistance = 0;

    mpData = apData;
    mpData->IncUserCount();

    mpSoundManger = apSoundManger;

    mvVelocity = cVector3f(0, 0, 0);
    mvPosition = cVector3f(0, 0, 0);
    mvRelPosition = cVector3f(0, 0, 0);

    mbBlockable = false;
    mfBlockVolumeMul = 1;

    mbAffectedByEnv = false;

    mlPriorityModifier = 0;

    mbStopUsed = false;
}

//-----------------------------------------------------------------------

iSoundChannel::~iSoundChannel()
{
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void iSoundChannel::DestroyData()
{
    if (mpSoundManger)
    {
        mpSoundManger->Destroy(mpData);
    }
}

//-----------------------------------------------------------------------

} // namespace hpl
