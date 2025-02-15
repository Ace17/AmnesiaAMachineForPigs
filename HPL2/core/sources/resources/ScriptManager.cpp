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

#include "resources/ScriptManager.h"

#include "resources/Resources.h"
#include "system/LowLevelSystem.h"
#include "system/Script.h"
#include "system/String.h"
#include "system/System.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cScriptManager::cScriptManager(cSystem* apSystem, cResources* apResources)
    : iResourceManager(apResources->GetFileSearcher(), apResources->GetLowLevel(), apResources->GetLowLevelSystem())
{
    mpSystem = apSystem;
    mpResources = apResources;
}

cScriptManager::~cScriptManager()
{
    DestroyAll();
    Log(" Done with scripts\n");
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

iScript* cScriptManager::CreateScript(const tString& asName, tString* apCompileMessages)
{
    tWString sPath;
    iScript* pScript;
    tString asNewName;

    BeginLoad(asName);

    if (cString::GetFileExt(asName) != "chps")
        asNewName = cString::SetFileExt(asName, "hps");
    else
        asNewName = cString::SetFileExt(asName, "chps");

    pScript = static_cast<iScript*>(this->FindLoadedResource(asNewName, sPath));

    if (pScript == NULL && sPath != _W(""))
    {
        pScript = mpSystem->GetLowLevel()->CreateScript(asNewName);

        if (pScript->CreateFromFile(sPath, apCompileMessages) == false)
        {
            hplDelete(pScript);
            EndLoad();
            return NULL;
        }

        AddResource(pScript);
    }

    if (pScript)
        pScript->IncUserCount();
    else
        Error("Couldn't create script '%s'\n", asNewName.c_str());

    EndLoad();
    return pScript;
}

//-----------------------------------------------------------------------

void cScriptManager::Unload(iResourceBase* apResource)
{
}
//-----------------------------------------------------------------------

void cScriptManager::Destroy(iResourceBase* apResource)
{
    apResource->DecUserCount();

    if (apResource->HasUsers() == false)
    {
        RemoveResource(apResource);
        hplDelete(apResource);
    }
}

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
} // namespace hpl
