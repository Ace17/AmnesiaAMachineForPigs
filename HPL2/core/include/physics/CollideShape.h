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

#include "math/BoundingVolume.h"
#include "math/MathTypes.h"
#include "physics/PhysicsTypes.h"

namespace hpl
{

//-----------------------------------------------

class iPhysicsWorld;

//-----------------------------------------------

class iCollideShape
{
public:
    iCollideShape(iPhysicsWorld* apWorld)
        : mlUserCount(0)
        , mpWorld(apWorld)
    {
    }
    virtual ~iCollideShape() {}

    virtual iCollideShape* GetSubShape(int alIdx) = 0;
    virtual int GetSubShapeNum() = 0;

    const cVector3f& GetSize() { return mvSize; }

    float GetRadius() { return mvSize.x; }
    float GetHeight() { return mvSize.y; }
    float GetWidth() { return mvSize.x; }
    float GetDepth() { return mvSize.z; }

    const cMatrixf& GetOffset() { return m_mtxOffset; }

    eCollideShapeType GetType() { return mType; }

    void IncUserCount() { mlUserCount++; }
    void DecUserCount() { mlUserCount--; }

    bool HasUsers() { return mlUserCount > 0; }
    int GetUserCount() { return mlUserCount; }

    float GetVolume() { return mfVolume; }

    cBoundingVolume& GetBoundingVolume() { return mBoundingVolume; }

protected:
    cVector3f mvSize;
    eCollideShapeType mType;
    cMatrixf m_mtxOffset;

    int mlUserCount;

    iPhysicsWorld* mpWorld;
    float mfVolume;

    cBoundingVolume mBoundingVolume;
};
}; // namespace hpl
