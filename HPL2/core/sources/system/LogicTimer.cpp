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

#include "system/LogicTimer.h"

#include "system/LowLevelSystem.h"
#include "system/Platform.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cLogicTimer::cLogicTimer(int alUpdatesPerSec, iLowLevelSystem* apLowLevelSystem)
{
    mlMaxUpdates = alUpdatesPerSec / 10;
    mlUpdateCount = 0;

    mpLowLevelSystem = apLowLevelSystem;

    SetUpdatesPerSec(alUpdatesPerSec);
}

//-----------------------------------------------------------------------

cLogicTimer::~cLogicTimer()
{
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------
void cLogicTimer::Reset()
{
    mlLocalTime = (double)cPlatform::GetApplicationTime();
}

//-----------------------------------------------------------------------

bool cLogicTimer::WantUpdate()
{
    ++mlUpdateCount;
    if (mlUpdateCount > mlMaxUpdates)
        return false;

    if (mlLocalTime < (double)cPlatform::GetApplicationTime())
    {
        Update();
        return true;
    }
    return false;
}

//-----------------------------------------------------------------------

void cLogicTimer::EndUpdateLoop()
{
    if (mlUpdateCount > mlMaxUpdates)
    {
        Reset();
    }

    mlUpdateCount = 0;
}

//-----------------------------------------------------------------------

void cLogicTimer::SetUpdatesPerSec(int alUpdatesPerSec)
{
    mlLocalTimeAdd = 1000.0 / ((double)alUpdatesPerSec);
    Reset();
}

//-----------------------------------------------------------------------

void cLogicTimer::SetMaxUpdates(int alMax)
{
    mlMaxUpdates = alMax;
}

//-----------------------------------------------------------------------

int cLogicTimer::GetUpdatesPerSec()
{
    return (int)(1000.0 / ((double)mlLocalTimeAdd));
}

//-----------------------------------------------------------------------

float cLogicTimer::GetStepSize()
{
    return ((float)mlLocalTimeAdd) / 1000.0f;
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cLogicTimer::Update()
{
    mlLocalTime += mlLocalTimeAdd;
}

//-----------------------------------------------------------------------

} // namespace hpl
