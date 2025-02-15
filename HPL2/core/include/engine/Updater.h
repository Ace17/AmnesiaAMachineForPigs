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

#include "engine/EngineTypes.h"
#include "system/SystemTypes.h"

#include <list>
#include <map>

namespace hpl
{

class iUpdateable;
class iLowLevelSystem;

typedef std::list<iUpdateable*> tUpdateableList;
typedef tUpdateableList::iterator tUpdateableListIt;

typedef std::map<tString, tUpdateableList> tUpdateContainerMap;
typedef tUpdateContainerMap::iterator tUpdateContainerMapIt;

class cUpdater
{
public:
    cUpdater(iLowLevelSystem* apLowLevelSystem);
    ~cUpdater();

    void Reset();

    void BroadcastMessageToAll(eUpdateableMessage aMessage, float afX = 0);
    void RunMessage(eUpdateableMessage aMessage, float afX = 0);

    /**
     * Sets the active update container to be used.
     * \param asContainer Name of the contianer
     * \return
     */
    bool SetContainer(tString asContainer);

    /**
     * Gets the name of the current container in use.
     * \return name of current container.
     */
    tString GetCurrentContainerName();
    /**
     * Adds a new container
     * \todo change name to state instead of container?
     * \param asName Name for the new container.
     * \return
     */
    bool AddContainer(tString asName);
    /**
     * Adds a new update in a container.
     * \param asContainer Container name
     * \param apUpdate pointer to the class that will be updated
     * \return
     */
    bool AddUpdate(tString asContainer, iUpdateable* apUpdate);
    /**
     * Adds a global update that runs no matter what container is set
     * \param apUpdate
     * \return
     */
    bool AddGlobalUpdate(iUpdateable* apUpdate);

private:
    tString msCurrentUpdates;

    tUpdateContainerMap m_mapUpdateContainer;

    iLowLevelSystem* mpLowLevelSystem;

    tUpdateableList* mpCurrentUpdates;
    tUpdateableList mlstGlobalUpdateableList;
};
}; // namespace hpl
