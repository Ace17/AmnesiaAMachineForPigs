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

#include "resources/ResourceLoaderHandler.h"

#include "resources/ResourceLoader.h"
#include "system/LowLevelSystem.h"
#include "system/String.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

iResourceLoaderHandler::~iResourceLoaderHandler()
{
    STLDeleteAll(mlstLoaders);
}
//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void iResourceLoaderHandler::AddLoader(iResourceLoader* apLoader)
{
    mlstLoaders.push_back(apLoader);

    // call implemented method to set it up.
    SetupLoader(apLoader);

    // Add all supported types from the loader
    tStringListIt it = apLoader->mlstExtensions.begin();
    for (; it != apLoader->mlstExtensions.end(); ++it)
    {
        mvSupportedTypes.push_back(*it);
    }
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PROTECTED METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

iResourceLoader* iResourceLoaderHandler::GetLoaderForFile(const tWString& asFileName)
{
    return GetLoaderForFile(cString::To8Char(asFileName));
}

//-----------------------------------------------------------------------

iResourceLoader* iResourceLoaderHandler::GetLoaderForFile(const tString& asFileName)
{
    tString sLowExt = cString::ToLowerCase(cString::GetFileExt(asFileName));

    tResourceLoaderListIt it = mlstLoaders.begin();
    for (; it != mlstLoaders.end(); it++)
    {
        iResourceLoader* pLoader = *it;

        if (pLoader->IsSupported(sLowExt))
        {
            return pLoader;
        }
    }
    Error("No loader for file extension '%s' found!\n", sLowExt.c_str());
    return NULL;
}

//-----------------------------------------------------------------------

} // namespace hpl
