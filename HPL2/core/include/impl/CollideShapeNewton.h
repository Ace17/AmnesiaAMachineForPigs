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

#if defined(__linux__) || defined(__APPLE__)
#include <unistd.h>
#endif
#include "math/MathTypes.h"
#include "physics/CollideShape.h"

#include <Newton.h>

namespace hpl
{

class iVertexBuffer;
class iCollideShape;
class cBinaryBuffer;

typedef std::vector<iCollideShape*> tCollideShapeVec;
typedef tCollideShapeVec::iterator tCollideShapeVecIt;

class cCollideShapeNewton : public iCollideShape
{
public:
    cCollideShapeNewton(eCollideShapeType aType, const cVector3f& avSize, cMatrixf* apOffsetMtx, NewtonWorld* apNewtonWorld, iPhysicsWorld* apWorld);
    ~cCollideShapeNewton();

    iCollideShape* GetSubShape(int alIdx);
    int GetSubShapeNum();

    cVector3f GetInertia(float afMass);

    void CreateStaticSceneFromShapeVec(tCollideShapeVec& avShapes, tMatrixfVec* apMatrices);
    void CreateCompoundFromShapeVec(tCollideShapeVec& avShapes);
    void CreateFromVertices(const unsigned int* apIndexArray, int alIndexNum, const float* apVertexArray, int alVtxStride, int alVtxNum);

    void SaveToSerializedData(cBinaryBuffer* apBinBuffer);
    void CreateFromSerializedData(cBinaryBuffer* apBinBuffer);

    NewtonCollision* GetNewtonCollision() { return mpNewtonCollision; }

private:
    NewtonCollision* mpNewtonCollision;
    NewtonWorld* mpNewtonWorld;

    tCollideShapeVec mvSubShapes;
};
}; // namespace hpl
