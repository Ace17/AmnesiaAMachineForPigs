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

class cWidgetMainMenu : public iWidgetMenu
{
public:
    cWidgetMainMenu(cGuiSet* apSet, cGuiSkin* apSkin);
    ~cWidgetMainMenu();

    //////////////////////////////
    // Implemented iWidgetMenu functions
    void Hide();

protected:
    //////////////////////////////
    // Implemented iWidgetMenu functions

    void UpdateMenuItemsPos(cWidgetMenuItem* apNewItem);
    void UpdateMenuItemsSize(cWidgetMenuItem* apNewItem);

    void OnChildMenuHide();

    //////////////////////////////
    // Implemented iWidget functions
    void OnDraw(float afTimeStep, cGuiClipRegion* apClipRegion);

    void OnUpdate(float afTimeStep);

    void OnInit();

    void OnLoadGraphics();

    /////////////////////////////
    // Data

    float mfItemSeparation;
    float mfItemVPadding;
    float mfItemTextPadding;

    cGuiGfxElement* mpGfxBackground;
};
}; // namespace hpl

