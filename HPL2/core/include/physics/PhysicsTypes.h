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

#include "math/MathTypes.h"

namespace hpl
{

//-----------------------------------------

enum eCollideShapeType
{
    eCollideShapeType_Null,
    eCollideShapeType_Box,
    eCollideShapeType_Sphere,
    eCollideShapeType_Cylinder,
    eCollideShapeType_Capsule,
    eCollideShapeType_ConvexHull,
    eCollideShapeType_Mesh,
    eCollideShapeType_Compound,
    eCollideShapeType_StaticScene,
    eCollideShapeType_LastEnum
};

//-----------------------------------------

enum ePhysicsAccuracy
{
    ePhysicsAccuracy_Low,
    ePhysicsAccuracy_Medium,
    ePhysicsAccuracy_High,
    ePhysicsAccuracy_LastEnum
};

//----------------------------------------------------

enum eVelocityAxes
{
    eVelocityAxes_XZ,
    eVelocityAxes_Y,
    eVelocityAxes_XYZ,
    eVelocityAxes_LastEnum
};

//----------------------------------------------------

typedef tFlag tPhysicsConnectionFlag;

#define ePhysicsConnectionFlag_DependOnBodyRotation (0x00000001)
#define ePhysicsConnectionFlag_AlignBodyCenter (0x00000002)
#define ePhysicsConnectionFlag_AlignBodyRotation (0x00000004)
#define ePhysicsConnectionFlag_DisableBodyGravity (0x00000008)
#define ePhysicsConnectionFlag_AffectChar (0x00000010)
#define ePhysicsConnectionFlag_AlignCharRotation (0x00000020)
#define ePhysicsConnectionFlag_DependOnCharRotation (0x00000040)
#define ePhysicsConnectionFlag_AllowCollision (0x00000080)

//----------------------------------------------------

class iVerletParticleContainer;

typedef std::list<iVerletParticleContainer*> tVerletParticleContainerList;
typedef tVerletParticleContainerList::iterator tVerletParticleContainerListIt;

//----------------------------------------------------

class cPhysicsRayParams
{
public:
    float mfT;
    float mfDist;
    cVector3f mvNormal;
    cVector3f mvPoint;
};

//----------------------------------------------------

class iPhysicsBody;

class iPhysicsRayCallback
{
public:
    virtual ~iPhysicsRayCallback() {}
    virtual bool BeforeIntersect(iPhysicsBody* pBody) { return true; }
    virtual bool OnIntersect(iPhysicsBody* pBody, cPhysicsRayParams* apParams) = 0;
};

//----------------------------------------------------

class cCollideData;

class iPhysicsWorldCollisionCallback
{
public:
    virtual ~iPhysicsWorldCollisionCallback() {}
    virtual void OnCollision(iPhysicsBody* apBody, cCollideData* apCollideData) = 0;
};

//----------------------------------------------------
} // namespace hpl

