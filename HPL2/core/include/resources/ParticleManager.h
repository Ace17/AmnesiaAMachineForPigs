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
#include "resources/ResourceManager.h"

class TiXmlElement;

namespace hpl
{

class cGraphics;
class cResources;
class cParticleSystem;
class cParticleSystemData;
class cXmlElement;

//----------------------------------------------------

typedef std::map<tString, cParticleSystemData*> tParticleSystemData3DMap;
typedef tParticleSystemData3DMap::iterator tParticleSystemData3DMapIt;

//----------------------------------------------------

class cParticleManager : public iResourceManager
{
public:
    cParticleManager(cGraphics* apGraphics, cResources* apResources);
    ~cParticleManager();

    cParticleSystem* CreatePS(const tString& asName, const tString& asType, cVector3f avSize);

    /////////////////////////////////////////////////
    // This method is a hack, just so everyone knows
    cParticleSystem* CreatePS(const tString& asName, const tString& asDataName, cXmlElement* apElement, cVector3f avSize);

    void AddData(cParticleSystemData* apData);

    void Preload(const tString& asFile);

    void Destroy(iResourceBase* apResource);
    void Unload(iResourceBase* apResource);

private:
    cGraphics* mpGraphics;
    cResources* mpResources;

    std::list<cParticleSystem*> mlstSystems;
};

}; // namespace hpl
