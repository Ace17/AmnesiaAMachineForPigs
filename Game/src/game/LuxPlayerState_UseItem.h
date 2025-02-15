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

#ifndef LUX_PLAYER_STATE_USE_ITEM_H
#define LUX_PLAYER_STATE_USE_ITEM_H

//----------------------------------------------

#include "LuxPlayerState_DefaultBase.h"

//----------------------------------------------

class cLuxPlayer;
class cLuxInventory_Item;

//------------------------------------

class cLuxPlayerState_UseItem_SaveData : public iLuxPlayerState_DefaultBase_SaveData
{
    kSerializableClassInit(cLuxPlayerState_UseItem_SaveData) public:
};

//----------------------------------------------

class cLuxPlayerState_UseItem : public iLuxPlayerState_DefaultBase
{
    typedef iLuxPlayerState_DefaultBase super_class;

public:
    cLuxPlayerState_UseItem(cLuxPlayer* apPlayer);
    virtual ~cLuxPlayerState_UseItem();

    void OnDraw(cGuiSet* apGuiSet, float afFrameTime) {} // Skip any special drawing.

    void ImplementedOnEnterState(eLuxPlayerState aPrevState);

    bool ImplementedDoAction(eLuxPlayerAction aAction, bool abPressed);

    void ImplementedUpdate(float afTimeStep);

    cGuiGfxElement* GetCrosshair();
    bool OnDrawCrossHair(cGuiGfxElement* apGfx, const cVector3f& avPos, const cVector2f& avSize);

    /////////////////////////////////
    // Save data stuff
    virtual bool IsSaved() { return true; }
    iLuxPlayerState_SaveData* CreateSaveData();

    void SaveToSaveData(iLuxPlayerState_SaveData* apSaveData);
    void LoadFromSaveDataBeforeEnter(cLuxMap* apMap, iLuxPlayerState_SaveData* apSaveData);
    void LoadFromSaveDataAfterEnter(cLuxMap* apMap, iLuxPlayerState_SaveData* apSaveData);

protected:
    bool ShowOutlineOnEntity(iLuxEntity* apEntity, iPhysicsBody* apBody, const cVector3f& avFocusPos);
    void UseItem();

    cLuxInventory_Item* mpCurrentItem;
    cLinearOscillation mFlashOscill;

    float mfMinUseItemDistance;
};

//----------------------------------------------

#endif // LUX_PLAYER_STATE_USE_ITEM_H
