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

namespace hpl
{

class cInput;
class cSystem;
class cGraphics;
class cResources;
class cScene;
class cSound;
class cPhysics;
class cAI;
class cHaptic;
class cGui;

class iLowLevelEngineSetup
{
public:
    virtual ~iLowLevelEngineSetup() {}

    virtual cInput* CreateInput(cGraphics* apGraphics) = 0;
    virtual cSystem* CreateSystem() = 0;
    virtual cGraphics* CreateGraphics() = 0;
    virtual cResources* CreateResources(cGraphics* apGraphics) = 0;
    virtual cScene*
    CreateScene(cGraphics* apGraphics, cResources* apResources, cSound* apSound, cPhysics* apPhysics, cSystem* apSystem, cAI* apAI, cGui* apGui, cHaptic* apHaptic) = 0;
    virtual cSound* CreateSound() = 0;
    virtual cPhysics* CreatePhysics() = 0;
    virtual cAI* CreateAI() = 0;
    virtual cHaptic* CreateHaptic() = 0;
};
}; // namespace hpl
