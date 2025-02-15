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

#include "resources/VideoLoaderHandler.h"

#include "graphics/Graphics.h"
#include "resources/Resources.h"
#include "resources/VideoLoader.h"
#include "scene/Scene.h"
#include "system/LowLevelSystem.h"
#include "system/String.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cVideoLoaderHandler::cVideoLoaderHandler(cResources* apResources, cGraphics* apGraphics)
{
    mpResources = apResources;
    mpGraphics = apGraphics;
}

//-----------------------------------------------------------------------

cVideoLoaderHandler::~cVideoLoaderHandler()
{
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

iVideoStream* cVideoLoaderHandler::LoadVideo(const tWString& asFile)
{
    iVideoLoader* pVideoLoader = static_cast<iVideoLoader*>(GetLoaderForFile(asFile));

    if (pVideoLoader)
    {
        return pVideoLoader->LoadVideo(asFile);
    }

    return NULL;
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cVideoLoaderHandler::SetupLoader(iResourceLoader* apLoader)
{
    iVideoLoader* pVideoLoader = static_cast<iVideoLoader*>(apLoader);

    pVideoLoader->mpLowLevelGraphics = mpGraphics->GetLowLevel();
}

//-----------------------------------------------------------------------
} // namespace hpl
