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
#include "physics/PhysicsJointHinge.h"

namespace hpl
{

class cPhysicsJointHingeNewton : public iPhysicsJointNewton<iPhysicsJointHinge>
{
public:
    cPhysicsJointHingeNewton(const tString& asName,
          iPhysicsBody* apParentBody,
          iPhysicsBody* apChildBody,
          iPhysicsWorld* apWorld,
          const cVector3f& avPivotPoint,
          const cVector3f& avPinDir);
    ~cPhysicsJointHingeNewton();

    void SetMaxAngle(float afAngle);
    void SetMinAngle(float afAngle);
    float GetMaxAngle();
    float GetMinAngle();

    cVector3f GetVelocity();
    cVector3f GetAngularVelocity();
    float GetForceSize();

    float GetDistance();
    float GetAngle();

private:
    cMatrixf m_mtxLocalPinPivot0;
    cMatrixf m_mtxLocalPinPivot1;

    float mfPreviousAngle;

    void SubmitConstraints(dFloat afTimestep, int alThreadIndex);
    void GetInfo(NewtonJointRecord* apInfo);

    // static unsigned LimitCallback(const NewtonJoint* pHinge, NewtonHingeSliderUpdateDesc* pDesc);
};
}; // namespace hpl
