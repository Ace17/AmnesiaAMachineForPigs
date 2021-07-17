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

#include "impl/PhysicsJointNewton.h"
#include "physics/PhysicsJointSlider.h"

namespace hpl
{

class cPhysicsJointSliderNewton : public iPhysicsJointNewton<iPhysicsJointSlider>
{
public:
    cPhysicsJointSliderNewton(const tString& asName,
          iPhysicsBody* apParentBody,
          iPhysicsBody* apChildBody,
          iPhysicsWorld* apWorld,
          const cVector3f& avPivotPoint,
          const cVector3f& avPinDir);
    ~cPhysicsJointSliderNewton();

    void SetMaxDistance(float afX);
    void SetMinDistance(float afX);
    float GetMaxDistance();
    float GetMinDistance();

    cVector3f GetVelocity();
    cVector3f GetAngularVelocity();
    float GetForceSize();

    float GetDistance();
    float GetAngle();

private:
    static unsigned LimitCallback(const NewtonJoint* pSlider, NewtonHingeSliderUpdateDesc* pDesc);

    float mfPreviousDist;
};
}; // namespace hpl
