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

#include "resources/ResourceManager.h"

namespace hpl
{

class cSound;
class cResources;
class iSoundData;

typedef std::list<iSoundData*> tSoundDataList;
typedef tSoundDataList::iterator tSoundDataListIt;

class cSoundManager : public iResourceManager
{
public:
    cSoundManager(cSound* apSound, cResources* apResources);
    ~cSoundManager();

    iSoundData* CreateSoundData(const tString& asName, bool abStream, bool abLoopStream = false);

    void Destroy(iResourceBase* apResource);
    void Unload(iResourceBase* apResource);

    void DestroyAll();

private:
    cSound* mpSound;
    cResources* mpResources;

    tStringList mlstFileFormats;

    tSoundDataList mlstStreamData;

    iSoundData* FindSampleData(const tString& asName, tWString& asFilePath);
    void FindStreamPath(const tString& asName, tWString& asFilePath);
};

}; // namespace hpl
