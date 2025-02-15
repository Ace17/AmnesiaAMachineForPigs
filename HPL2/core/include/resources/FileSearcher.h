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

#include "resources/ResourcesTypes.h"
#include "system/SystemTypes.h"

#include <map>

namespace hpl
{

class iLowLevelResources;

//----------------------------------

class cFileSearcherEntry
{
public:
    cFileSearcherEntry(const tWString& asPath);

    tWString msPath;
    tWStringVec mvPathDirs;
};

//----------------------------------

typedef std::multimap<tString, cFileSearcherEntry> tFilePathMap;
typedef tFilePathMap::iterator tFilePathMapIt;

//----------------------------------

class cFileSearcher
{
public:
    cFileSearcher();
    ~cFileSearcher();

    /**
     * Adds a directory that will be searched when looking for files.
     * \param asMask What files that should be searched for, for example: "*.jpeg".
     * \param asPath The path to the directory.
     */
    void AddDirectory(const tWString& asSearchPath, const tString& asMask, bool abAddSubDirectories);

    /**
     * Clears all directories
     */
    void ClearDirectories();

    /**
     * Gets a file pointer and searches through all added resources.
     * \param asName Name of the file.
     * \return Path to the file. "" if file is not found.
     */
    const tWString& GetFilePath(const tString& asFileNameAndPath, int* apEqualCount = NULL);

private:
    tFilePathMap m_mapFiles;
    tWStringSet m_setLoadedDirs;

    tWString msNull;
};

}; // namespace hpl
