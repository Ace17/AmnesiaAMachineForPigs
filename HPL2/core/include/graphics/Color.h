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
#include <vector>

namespace hpl
{

class cColor
{
public:
    union
    {
        struct
        {
            float r, g, b, a;
        };
        float v[4];
    };

    cColor(float afR, float afG, float afB, float afA);
    cColor(float afR, float afG, float afB);
    cColor();
    cColor(float afVal);
    cColor(float afVal, float afA);

    cColor operator*(float afVal) const;
    cColor operator/(float afVal) const;

    cColor operator+(const cColor& aCol) const;
    cColor operator-(const cColor& aCol) const;
    cColor operator*(const cColor& aCol) const;
    cColor operator/(const cColor& aCol) const;

    bool operator==(cColor aCol) const;

    tString ToString() const;

    tString ToFileString() const;

    void FromVec(float* apV);
};

typedef std::list<cColor> tColorList;
typedef tColorList::iterator tColorListIt;

typedef std::vector<cColor> tColorVec;
typedef tColorVec::iterator tColorVecIt;

}; // namespace hpl
