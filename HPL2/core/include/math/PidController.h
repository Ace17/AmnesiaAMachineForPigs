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

template<class T>
class cPidController
{
public:
    float p, i, d;
    //////////////////////////////////////////
    // Constructors
    /////////////////////////////////////////
    cPidController() { Reset(); }
    cPidController(float afP, float afI, float afD, int alErrorNum)
    {
        p = afP;
        i = afI;
        d = afD;
        SetErrorNum(alErrorNum);
        Reset();
    }

    //////////////////////////////////////////
    // Public
    /////////////////////////////////////////

    //------------------------------------
    T Output(T aError, float afTimeStep)
    {
        mvErrors[mlErrorNum] = aError;
        mvTimeSteps[mlErrorNum] = afTimeStep;

        integral = 0;
        size_t lCount = mvErrors.size();
        for (size_t error = 0; error < lCount; ++error)
        {
            integral += mvErrors[error] * mvTimeSteps[error];
        }

        derivative = 0.0f;
        if (mlLastNum >= 0)
        {
            derivative = (mvErrors[mlErrorNum] - mvErrors[mlLastNum]) / afTimeStep;
        }

        mlLastNum = mlErrorNum;
        mlErrorNum++;
        if (mlErrorNum >= (int)mvErrors.size())
            mlErrorNum = 0;

        return mvErrors[mlLastNum] * p + integral * i + derivative * d;
    }

    //------------------------------------

    void SetErrorNum(int alErrorNum)
    {
        mvErrors.resize(alErrorNum, 0);
        mvTimeSteps.resize(alErrorNum, 0);
    }

    //------------------------------------

    void Reset()
    {
        mlErrorNum = 0;
        mlLastNum = -1;
        mvTimeSteps.assign(mvTimeSteps.size(), 0);

        integral = 0;
        derivative = 0;
    }

    //------------------------------------

    T GetLastError()
    {
        if (mlLastNum >= 0)
            return mvErrors[mlLastNum];
        return 0;
    }

    T GetLastDerivative() { return derivative; }

    T GetLastIntegral() { return integral; }

    //------------------------------------

private:
    std::vector<T> mvErrors;
    std::vector<float> mvTimeSteps;

    T integral, derivative;

    int mlErrorNum;
    int mlLastNum;
};

//---------------------------------

typedef cPidController<float> cPidControllerf;
typedef cPidController<cVector3f> cPidControllerVec3;
}; // namespace hpl
