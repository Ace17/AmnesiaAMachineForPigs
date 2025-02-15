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
#include "physics/PhysicsMaterial.h"

#include <Newton.h>

namespace hpl
{

class iPhysicsBody;

//------------------------------------------

class cNewtonLockBodyUntilReturn
{
public:
    cNewtonLockBodyUntilReturn(const NewtonBody* apNewtonBody);
    ~cNewtonLockBodyUntilReturn();

private:
    const NewtonBody* mpNewtonBody;
};

//------------------------------------------

class cPhysicsMaterialNewton : public iPhysicsMaterial
{
public:
    cPhysicsMaterialNewton(const tString& asName, iPhysicsWorld* apWorld, int alMatId = -1);
    ~cPhysicsMaterialNewton();

    void SetElasticity(float afElasticity);
    float GetElasticity() const;
    void SetStaticFriction(float afElasticity);
    float GetStaticFriction() const;
    void SetKineticFriction(float afElasticity);
    float GetKineticFriction() const;

    void SetFrictionCombMode(ePhysicsMaterialCombMode aMode);
    ePhysicsMaterialCombMode GetFrictionCombMode() const;
    void SetElasticityCombMode(ePhysicsMaterialCombMode aMode);
    ePhysicsMaterialCombMode GetElasticityCombMode() const;

    void UpdateMaterials();

    int GetId() { return mlMaterialId; }

private:
    float Combine(ePhysicsMaterialCombMode aMode, float afX, float afY);

    static int OnAABBOverlapCallback(const NewtonMaterial* apMaterial, const NewtonBody* apBody0, const NewtonBody* apBody1, int alThreadIndex);

    static void ContactsProcessCallback(const NewtonJoint* apContactJoint, dFloat afTimestep, int alThreadIndex);

    /*static int BeginContactCallback(const NewtonMaterial* apMaterial,
                                                                    const NewtonBody* apBody0, const NewtonBody* apBody1, int alThreadIndex);

    static int ProcessContactCallback(	const NewtonMaterial* apMaterial,
                                                                            const NewtonBody* apBody0, const NewtonBody* apBody1,
                                                                            dFloat afTimestep, int alThreadIndex);

    static void EndContactCallback(		const NewtonMaterial* apMaterial, const NewtonBody* apBody0, const NewtonBody* apBody1,
                                                                            int alThreadIndex);*/

    NewtonWorld* mpNewtonWorld;

    int mlMaterialId;

    ePhysicsMaterialCombMode mFrictionMode;
    ePhysicsMaterialCombMode mElasticityMode;

    float mfElasticity;
    float mfStaticFriction;
    float mfKineticFriction;
};
}; // namespace hpl
