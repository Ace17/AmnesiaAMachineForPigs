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
#include "math/MathTypes.h"
#include "system/SerializeClass.h"
#include "system/SystemTypes.h"

namespace hpl
{

class iLowLevelGraphics;
class cBoundingVolume;

class cBVTempArray
{
public:
    const float* mpArray;
    int mlSize;
};

enum eBVCollision
{
    eBVCollision_Inside,
    eBVCollision_Outside,
    eBVCollision_Intersect,
    eBVCollision_LastEnum
};

typedef std::list<cBVTempArray> tBVTempArrayList;
typedef tBVTempArrayList::iterator tBVTempArrayListIt;

class cShadowVolumeBV
{
public:
    cPlanef mvPlanes[12];
    int mlPlaneCount;
    tVector3fVec mvPoints;
    int mlCapPlanes;

    bool CollideBoundingVolume(cBoundingVolume* aBV);

private:
    bool CollideBVSphere(cBoundingVolume* aBV);
    bool CollideBVAABB(cBoundingVolume* aBV);
};

class cBoundingVolume : public iSerializable
{
    friend class cMath;
    kSerializableClassInit(cBoundingVolume) public : cBoundingVolume();

    const cVector3f& GetMax();
    const cVector3f& GetMin();

    const cVector3f& GetLocalMax();
    const cVector3f& GetLocalMin();

    void SetLocalMinMax(const cVector3f& mvMin, const cVector3f& mvMax);

    void SetPosition(const cVector3f& avPos);
    cVector3f GetPosition();

    void SetSize(const cVector3f& avSize);
    cVector3f GetSize();

    void SetTransform(const cMatrixf& a_mtxTransform);
    const cMatrixf& GetTransform();

    cVector3f GetLocalCenter();
    cVector3f GetWorldCenter();

    float GetRadius();

    void AddArrayPoints(const float* apArray, int alNumOfVectors);
    void CreateFromPoints(int alStride);

    cShadowVolumeBV* GetShadowVolume(const cVector3f& avLightPos, float afLightRange, bool abForceUpdate);

    // Debug:
    void DrawEdges(const cVector3f& avLightPos, float afLightRange, iLowLevelGraphics* apLowLevelGraphics);
    void UpdateSize();

    cMatrixf m_mtxTransform;

    cVector3f mvLocalMax;
    cVector3f mvLocalMin;

    cVector3f mvMax;
    cVector3f mvMin;

    cVector3f mvPivot;

    cVector3f mvWorldMax;
    cVector3f mvWorldMin;

    cVector3f mvPosition;
    cVector3f mvSize;
    float mfRadius;

private:
    bool mbPositionUpdated;
    bool mbSizeUpdated;

    tBVTempArrayList mlstArrays;

    cShadowVolumeBV mShadowVolume;
    bool mbShadowPlanesNeedUpdate;
};
}; // namespace hpl
