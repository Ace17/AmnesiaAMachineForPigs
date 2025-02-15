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

namespace hpl
{

//----------------------------------------------

class cTriangleData
{
public:
    cVector3f normal;
    bool facingLight;

    cTriangleData() {}
    cTriangleData(const cVector3f& avNormal) { normal = avNormal; }
};

typedef std::vector<cTriangleData> tTriangleDataVec;
typedef tTriangleDataVec::iterator tTriangleDataVecIt;

//----------------------------------------------

class cTriEdge
{
public:
    int point1, point2;
    mutable int tri1, tri2;
    bool invert_tri2;

    cTriEdge() {}
    cTriEdge(int alPoint1, int alPoint2, int alTri1, int alTri2)
    {
        point1 = alPoint1;
        point2 = alPoint2;
        tri1 = alTri1;
        tri2 = alTri2;
    }
};

typedef std::vector<cTriEdge> tTriEdgeVec;
typedef tTriEdgeVec::iterator tTriEdgeVecIt;

//----------------------------------------------

}; // namespace hpl
