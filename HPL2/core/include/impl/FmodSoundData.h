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

#include "sound/SoundData.h"
#include <fmod/fmod.h>

namespace hpl
{

class cFmodSoundData : public iSoundData
{
public:
    cFmodSoundData(const tString& asName, bool abStream);
    ~cFmodSoundData();

    bool CreateFromFile(const tWString& asFile);

    iSoundChannel* CreateChannel(int alPriority);

    bool IsStream() { return mbStream; }

    bool IsStereo() { return false; }

    // FMOD Specific
    FSOUND_SAMPLE* GetSample() { return mpSample; }
    FSOUND_STREAM* GetStream() { return mpStream; }

private:
    FSOUND_SAMPLE* mpSample;
    FSOUND_STREAM* mpStream;
};
}; // namespace hpl
