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

#include "engine/Updateable.h"
#include "haptic/HapticTypes.h"
#include "physics/PhysicsMaterial.h"
#include "system/SystemTypes.h"

#include <list>
#include <map>

namespace hpl
{

class iLowLevelPhysics;
class iPhysicsWorld;
class cSurfaceData;
class cResources;
class iHapticSurface;
class cHaptic;

//------------------------------------------------

typedef std::list<iPhysicsWorld*> tPhysicsWorldList;
typedef tPhysicsWorldList::iterator tPhysicsWorldListIt;

typedef std::map<tString, cSurfaceData*> tSurfaceDataMap;
typedef tSurfaceDataMap::iterator tSurfaceDataMapIt;

typedef cSTLMapIterator<cSurfaceData*, tSurfaceDataMap, tSurfaceDataMapIt> cSurfaceDataIterator;

//------------------------------------------------

class cPhysicsImpactCount
{
public:
    cPhysicsImpactCount() { mfCount = 0; }

    float mfCount;
};

typedef std::list<cPhysicsImpactCount> tPhysicsImpactCountList;
typedef tPhysicsImpactCountList::iterator tPhysicsImpactCountListIt;

//------------------------------------------------

class cPhysics : public iUpdateable
{
public:
    cPhysics(iLowLevelPhysics* apLowLevelPhysics);
    ~cPhysics();

    void Init(cResources* apResources);

    void Update(float afTimeStep);

    iPhysicsWorld* CreateWorld(bool abAddSurfaceData);
    void DestroyWorld(iPhysicsWorld* apWorld);

    cSurfaceData* CreateSurfaceData(const tString& asName);
    cSurfaceData* GetSurfaceData(const tString& asName);
    bool LoadSurfaceData(const tString& asFile, cHaptic* apHaptic = NULL);

    iLowLevelPhysics* GetLowLevel() { return mpLowLevelPhysics; }

    void SetImpactDuration(float afX) { mfImpactDuration = afX; }
    float GetImpactDuration() { return mfImpactDuration; }

    void SetMaxImpacts(int alX) { mlMaxImpacts = alX; }
    int GetMaxImpacts() { return mlMaxImpacts; }
    int GetNumOfImpacts() { return (int)mlstImpactCounts.size(); }

    bool CanPlayImpact();
    void AddImpact();

    cSurfaceDataIterator GetSurfaceDataIterator() { return cSurfaceDataIterator(&m_mapSurfaceData); }

    void SetDebugLog(bool abX) { mbLog = abX; }
    bool GetDebugLog() { return mbLog; }

private:
    eHapticSurfaceType GetHapticSurface(const char* apName);

    ePhysicsMaterialCombMode GetCombMode(const char* apName);

    void UpdateImpactCounts(float afTimeStep);

    iLowLevelPhysics* mpLowLevelPhysics;
    cResources* mpResources;

    tPhysicsWorldList mlstWorlds;
    tSurfaceDataMap m_mapSurfaceData;

    tPhysicsImpactCountList mlstImpactCounts;
    float mfImpactDuration;
    int mlMaxImpacts;
    bool mbLog;
};

}; // namespace hpl
