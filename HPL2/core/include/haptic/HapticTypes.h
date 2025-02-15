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

#include "system/SystemTypes.h"

#include <list>
#include <map>
#include <vector>

namespace hpl
{

//----------------------------------------------

enum eHapticShapeType
{
    eHapticShapeType_Box,
    eHapticShapeType_Sphere,
    eHapticShapeType_Cylinder,
    eHapticShapeType_Capsule,
    eHapticShapeType_Mesh,
    eHapticShapeType_Compund,
    eHapticShapeType_LastEnum
};

//----------------------------------------------

enum eHapticForceType
{
    eHapticForceType_Impulse,
    eHapticForceType_Spring,
    eHapticForceType_SineWave,
    eHapticForceType_SawWave,
    eHapticForceType_Viscosity,
    eHapticForceType_LastEnum
};

//----------------------------------------------

enum eHapticSurfaceType
{
    eHapticSurfaceType_Simple,
    eHapticSurfaceType_Rough,
    eHapticSurfaceType_Frictional,
    eHapticSurfaceType_Sticky,
    eHapticSurfaceType_LastEnum
};

//----------------------------------------------

class iHapticShape;
class iHapticForce;
class iHapticSurface;

//----------------------------------------------

typedef std::vector<iHapticShape*> tHapticShapeVec;
typedef tHapticShapeVec::iterator tHapticShapeVecIt;

typedef std::list<iHapticShape*> tHapticShapeList;
typedef tHapticShapeList::iterator tHapticShapeListIt;

typedef std::list<iHapticForce*> tHapticForceList;
typedef tHapticForceList::iterator tHapticForceListIt;

typedef std::list<iHapticSurface*> tHapticSurfaceList;
typedef tHapticSurfaceList::iterator tHapticSurfaceListIt;

typedef std::map<tString, iHapticSurface*> tHapticSurfaceMap;
typedef tHapticSurfaceMap::iterator tHapticSurfaceMapIt;

typedef cSTLIterator<iHapticShape*, tHapticShapeList, tHapticShapeListIt> cHapticShapeIterator;

//----------------------------------------------

}; // namespace hpl
