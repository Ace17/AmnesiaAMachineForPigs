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

#ifndef LUX_PLAYER_STATE_INTERACT_SWING_DOOR_H
#define LUX_PLAYER_STATE_INTERACT_SWING_DOOR_H

//----------------------------------------------

#include "LuxPlayerState_InteractRotateBase.h"

//----------------------------------------------

class cLuxInteractData_SwingDoor;

//------------------------------------

class cLuxPlayerState_InteractSwingDoor_SaveData : public iLuxPlayerState_InteractRotateBase_SaveData
{
    kSerializableClassInit(cLuxPlayerState_InteractSwingDoor_SaveData) public:
};
//----------------------------------------------

class cLuxPlayerState_InteractSwingDoor : public iLuxPlayerState_InteractRotateBase
{
    typedef iLuxPlayerState_InteractRotateBase super_class;

public:
    cLuxPlayerState_InteractSwingDoor(cLuxPlayer* apPlayer);
    virtual ~cLuxPlayerState_InteractSwingDoor();

    /////////////////////////////////
    // Save data stuff
    virtual bool IsSaved() { return false; }
    iLuxPlayerState_SaveData* CreateSaveData();

    void SaveToSaveData(iLuxPlayerState_SaveData* apSaveData);
    void LoadFromSaveDataBeforeEnter(cLuxMap* apMap, iLuxPlayerState_SaveData* apSaveData);
    void LoadFromSaveDataAfterEnter(cLuxMap* apMap, iLuxPlayerState_SaveData* apSaveData);

protected:
    float GetSpeedAdd(cCamera* apCam);
    void OnThrow();

    cLuxInteractData_SwingDoor* mpSwingDoorData;
};

//----------------------------------------------

#endif // LUX_PLAYER_STATE_INTERACT_SWING_DOOR_H
