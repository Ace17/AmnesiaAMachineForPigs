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

#include "gui/GuiSkin.h"
#include "gui/WidgetMenu.h"

namespace hpl
{

class cWidgetContextMenu : public iWidgetMenu
{
public:
    cWidgetContextMenu(cGuiSet* apSet, cGuiSkin* apSkin);
    ~cWidgetContextMenu();

    ////////////////////////////////////
    // iWidgetMenu implemented functions
    void AddSeparator();
    void Hide();

    void SavePrevAttentionWidget();

    float GetMenuItemWidth();

protected:
    ////////////////////////////////////
    // iWidgetMenu implemented functions

    void UpdateMenuItemsPos(cWidgetMenuItem* apNewItem);
    void UpdateMenuItemsSize(cWidgetMenuItem* apNewItem);
    void UpdateMenuWidth(float afWidth);

    void OnChildMenuHide();

    ////////////////////////////////////
    // iWidget implemented functions

    void OnDraw(float afTimeStep, cGuiClipRegion* apClipRegion);

    void OnUpdate(float afTimeStep);

    void OnInit();

    bool OnMouseDown(const cGuiMessageData& aData) { return true; }
    bool OnMouseUp(const cGuiMessageData& aData) { return true; }

    bool OnMouseEnter(const cGuiMessageData& aData);
    bool OnMouseLeave(const cGuiMessageData& aData);

    bool OnKeyPress(const cGuiMessageData& aData);

    bool OnLostFocus(const cGuiMessageData& aData);
    bool OnGotFocus(const cGuiMessageData& aData);

    void OnLoadGraphics();

    /////////////////////////
    // Data
    float mfTimer;
    float mfHideTime;

    // Skin attributes
    float mfItemHPadding;
    float mfItemTextLeftPadding;
    float mfItemTextRightPadding;
    float mfItemVPadding;
    float mfItemSeparation;
    float mfItemArrowIconSize;
    float mfItemCheckIconSize;

    // Graphics
    cGuiGfxElement* mpGfxBackground;

    cGuiGfxElement* mvGfxBorders[4];
    cGuiGfxElement* mvGfxCorners[4];
};
}; // namespace hpl

