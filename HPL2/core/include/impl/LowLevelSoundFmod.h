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

#include "sound/LowLevelSound.h"

namespace hpl
{

class cLowLevelSoundFmod : public iLowLevelSound
{
public:
    cLowLevelSoundFmod();
    ~cLowLevelSoundFmod();

    void GetSupportedFormats(tStringList& alstFormats);

    iSoundData* LoadSoundData(const tString& asName, const tString& asFilePath, const tString& asType, bool abStream, bool abLoopStream);

    void UpdateSound(float afTimeStep);

    void SetListenerAttributes(const cVector3f& avPos, const cVector3f& avVel, const cVector3f& avForward, const cVector3f& avUp);
    void SetListenerPosition(const cVector3f& avPos);

    void SetSetRolloffFactor(float afFactor);

    void SetListenerAttenuation(bool abEnabled);

    virtual void SetVolume(float afVolume);

private:
    tString mvFormats[30];
};
}; // namespace hpl
