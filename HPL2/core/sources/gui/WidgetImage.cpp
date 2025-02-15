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

#include "gui/WidgetImage.h"

#include "gui/Gui.h"
#include "gui/GuiGfxElement.h"
#include "gui/GuiSet.h"
#include "gui/GuiSkin.h"
#include "math/Math.h"
#include "system/LowLevelSystem.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cWidgetImage::cWidgetImage(cGuiSet* apSet, cGuiSkin* apSkin)
    : iWidget(eWidgetType_Image, apSet, apSkin)
{
    mpGfxImage = NULL;
}

//-----------------------------------------------------------------------

cWidgetImage::~cWidgetImage()
{
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cWidgetImage::SetImage(cGuiGfxElement* apGfx)
{
    if (mpGfxImage == apGfx)
        return;

    mpGfxImage = apGfx;
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PROTECTED METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cWidgetImage::OnLoadGraphics()
{
}

//-----------------------------------------------------------------------

void cWidgetImage::OnChangeSize()
{
}

//-----------------------------------------------------------------------

void cWidgetImage::OnDraw(float afTimeStep, cGuiClipRegion* apClipRegion)
{
    ////////////////////////////////
    // Background
    if (mpGfxImage)
    {
        mpSet->DrawGfx(mpGfxImage, GetGlobalPosition(), mvSize, mColorMul);
    }
}

//-----------------------------------------------------------------------

bool cWidgetImage::OnMouseMove(const cGuiMessageData& aData)
{
    return true;
}

//-----------------------------------------------------------------------

bool cWidgetImage::OnMouseDown(const cGuiMessageData& aData)
{
    if (aData.mlVal == eGuiMouseButton_WheelUp || aData.mlVal == eGuiMouseButton_WheelDown)
        return false;

    return true;
}

//-----------------------------------------------------------------------

bool cWidgetImage::OnMouseUp(const cGuiMessageData& aData)
{
    if (aData.mlVal == eGuiMouseButton_WheelUp || aData.mlVal == eGuiMouseButton_WheelDown)
        return false;

    return true;
}

//-----------------------------------------------------------------------

bool cWidgetImage::OnMouseEnter(const cGuiMessageData& aData)
{
    return false;
}

//-----------------------------------------------------------------------

bool cWidgetImage::OnMouseLeave(const cGuiMessageData& aData)
{
    return false;
}

//-----------------------------------------------------------------------

} // namespace hpl
