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

#include "physics/PhysicsJoint.h"

namespace hpl
{

class cGraphics;
class cResources;
class cSystem;
class cSound;
class cScene;
class cInput;
class cEngine;

//---------------------------------------

class cScriptJointCallback : public iPhysicsJointCallback
{
public:
    cScriptJointCallback(cScene* apScene);

    void OnMinLimit(iPhysicsJoint* apJoint);
    void OnMaxLimit(iPhysicsJoint* apJoint);

    bool IsScript() { return true; }

    tString msMaxFunc;
    tString msMinFunc;

    cScene* mpScene;
};

//---------------------------------------

class cScriptFuncs
{
public:
    static void Init(cGraphics* apGraphics, cResources* apResources, cSystem* apSystem, cInput* apInput, cScene* apScene, cSound* apSound, cEngine* apGame);
};

}; // namespace hpl
