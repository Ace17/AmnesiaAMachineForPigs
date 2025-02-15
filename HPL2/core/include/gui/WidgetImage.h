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

#include "gui/Widget.h"

namespace hpl
{

class cGuiSkinFont;

class cWidgetImage : public iWidget
{
public:
    cWidgetImage(cGuiSet* apSet, cGuiSkin* apSkin);
    virtual ~cWidgetImage();

    void SetImage(cGuiGfxElement* apGfx);
    cGuiGfxElement* GetImage() { return mpGfxImage; }

protected:
    /////////////////////////
    // Implemented functions
    void OnLoadGraphics();
    void OnChangeSize();

    void OnDraw(float afTimeStep, cGuiClipRegion* apClipRegion);

    bool OnMouseMove(const cGuiMessageData& aData);
    bool OnMouseDown(const cGuiMessageData& aData);
    bool OnMouseUp(const cGuiMessageData& aData);
    bool OnMouseEnter(const cGuiMessageData& aData);
    bool OnMouseLeave(const cGuiMessageData& aData);

    /////////////////////////
    // Data
    cGuiGfxElement* mpGfxImage;
};

}; // namespace hpl
