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

#include "graphics/GraphicsTypes.h"
#include "haptic/HapticTypes.h"
#include "math/MathTypes.h"

namespace hpl
{

class iHapticSurface;
class iLowLevelGraphics;
class iPhysicsBody;
class cSubMeshEntity;

class iHapticShape
{
public:
    iHapticShape(const tString& asName, eHapticShapeType aType)
        : mpSurface(NULL)
        , mType(aType)
        , msName(asName)
        , mpBody(NULL)
        , mpSubMeshEntity(NULL)
        , mlTransformCount(-1)
    {
    }
    virtual ~iHapticShape() {}

    eHapticShapeType GetType() { return mType; }
    const tString& GetName() { return msName; }

    virtual void SetEnabled(bool abX) = 0;
    virtual bool GetEnabled() = 0;

    virtual void SetTransform(const cMatrixf& a_mtxTransform) = 0;
    virtual cMatrixf GetTransform() = 0;

    virtual cVector3f GetAppliedForce() = 0;

    virtual void SetSurface(iHapticSurface* apSurface) = 0;

    virtual void RenderDebug(iLowLevelGraphics* apLowLevel, const cColor& aColor) = 0;

    iHapticSurface* GetSurface() const { return mpSurface; }

    cVector3f GetSize() const { return mvSize; }

    iPhysicsBody* GetBody() const { return mpBody; }
    void SetBody(iPhysicsBody* apBody) { mpBody = apBody; }

    cSubMeshEntity* GetSubMeshEntity() const { return mpSubMeshEntity; }
    void SetSubMeshEntity(cSubMeshEntity* apSubMeshEntity) { mpSubMeshEntity = apSubMeshEntity; }

    int GetTransformCount() const { return mlTransformCount; }
    void SetTransformCount(int alX) { mlTransformCount = alX; }

protected:
    tString msName;
    iHapticSurface* mpSurface;
    eHapticShapeType mType;
    cVector3f mvSize;

    iPhysicsBody* mpBody;
    cSubMeshEntity* mpSubMeshEntity;
    int mlTransformCount;
};

}; // namespace hpl
