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

#include "scene/LightPoint.h"

#include "engine/Engine.h"
#include "graphics/LowLevelGraphics.h"
#include "math/Math.h"
#include "scene/Camera.h"
#include "scene/Scene.h"
#include "scene/World.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cLightPoint::cLightPoint(tString asName, cResources* apResources)
    : iLight(asName, apResources)
{
    mLightType = eLightType_Point;

    UpdateBoundingVolume();
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cLightPoint::UpdateBoundingVolume()
{
    mBoundingVolume.SetSize(mfRadius * 2);
    mBoundingVolume.SetPosition(GetWorldPosition());
}
//-----------------------------------------------------------------------

} // namespace hpl
