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

#include "haptic/Haptic.h"

#include "haptic/LowLevelHaptic.h"
#include "system/LowLevelSystem.h"

namespace hpl
{

bool cHaptic::mbIsUsed = false;

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cHaptic::cHaptic(iLowLevelHaptic* apLowLevelHaptic)
    : iUpdateable("HPL_Haptic")
{
    mpLowLevelHaptic = apLowLevelHaptic;
}

//-----------------------------------------------------------------------

cHaptic::~cHaptic()
{
    Log("Exiting Haptic Module\n");
    Log("--------------------------------------------------------\n");

    Log("--------------------------------------------------------\n\n");
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cHaptic::Update(float afTimeStep)
{
    if (mbIsUsed == false)
        return;

    mpLowLevelHaptic->Update(afTimeStep);
}

//-----------------------------------------------------------------------

void cHaptic::Init(cResources* apResources)
{
    if (mbIsUsed == false)
        return;

    Log("Initializing Haptic Module\n");
    Log("--------------------------------------------------------\n");

    if (mpLowLevelHaptic->Init(apResources) == false)
    {
        SetIsUsed(false);
    }

    Log("--------------------------------------------------------\n\n");
}

//-----------------------------------------------------------------------

} // namespace hpl
