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

#include "resources/ResourceBase.h"
#include "system/SystemTypes.h"

namespace hpl
{

class cSoundManager;
class iSoundChannel;

class iSoundData : public iResourceBase
{
public:
    iSoundData(const tString& asName, const tWString& asFullPath, bool abStream)
        : iResourceBase(asName, asFullPath, 0)
        , mpSoundManger(NULL)
        , mbStream(abStream)
    {
    }

    virtual ~iSoundData() {}

    virtual bool CreateFromFile(const tWString& asFile) = 0;

    virtual iSoundChannel* CreateChannel(int alPriority) = 0;

    virtual bool IsStereo() = 0;

    bool IsStream() { return mbStream; }
    void SetLoopStream(bool abX) { mbLoopStream = abX; }
    bool GetLoopStream() { return mbLoopStream; }

    bool Reload() { return false; }
    void Unload() {}
    void Destroy() {}

    void SetSoundManager(cSoundManager* apSoundManager) { mpSoundManger = apSoundManager; }

protected:
    bool mbStream;
    bool mbLoopStream;
    cSoundManager* mpSoundManger;
};
}; // namespace hpl
