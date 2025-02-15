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

class cWidgetButton;

//---------------------------------------------

class cWidgetSlider : public iWidget
{
public:
    cWidgetSlider(cGuiSet* apSet, cGuiSkin* apSkin, eWidgetSliderOrientation aOrientation);
    virtual ~cWidgetSlider();

    int GetValue() { return mlValue; }
    void SetValue(int alValue, bool abGenCallback = true);

    int GetMaxValue() { return mlMaxValue; }
    void SetMaxValue(int alMax);

    int GetButtonValueAdd() { return mlButtonValueAdd; }
    void SetButtonValueAdd(int alAdd);

    int GetBarClickValueAdd() { return mlBarClickValueAdd; }
    void SetBarClickValueAdd(int alAdd);

    int GetBarValueSize() { return mlBarValueSize; }
    void SetBarValueSize(int alSize);

    float GetButtonSize() const { return mfButtonSize; }

protected:
    /////////////////////////
    // Own functions
    void UpdateBarProperties();

    bool ArrowButtonDown(iWidget* apWidget, const cGuiMessageData& aData);
    kGuiCallbackDeclarationEnd(ArrowButtonDown);

    /////////////////////////
    // Implemented functions
    void OnInit();
    void OnLoadGraphics();
    void OnChangeSize();
    void OnChangePosition();

    void OnDraw(float afTimeStep, cGuiClipRegion* apClipRegion);

    bool OnMouseMove(const cGuiMessageData& aData);
    bool OnMouseDown(const cGuiMessageData& aData);
    bool OnMouseUp(const cGuiMessageData& aData);
    bool OnMouseEnter(const cGuiMessageData& aData);
    bool OnMouseLeave(const cGuiMessageData& aData);

    bool OnMouseDoubleClick(const cGuiMessageData& aData);

    bool OnLostFocus(const cGuiMessageData& aData);

    bool OnUIArrowPress(const cGuiMessageData& aData);
    bool OnUIArrowRelease(const cGuiMessageData& aData);

    bool OnUIButtonPress(const cGuiMessageData& aData);
    bool OnUIButtonRelease(const cGuiMessageData& aData);

    /////////////////////////
    // Data
    eWidgetSliderOrientation mOrientation;

    bool mbPressed;

    float mfButtonSize;

    int mlValue;
    int mlMaxValue;
    int mlButtonValueAdd;
    int mlBarClickValueAdd;
    int mlBarValueSize; // This is how big the bar is compared to the max value of the slider
    float mfValueStep;

    cVector3f mvBarPos;
    cVector2f mvBarSize;
    float mfSliderSize;
    cRect2f mBarRect;
    float mfMaxPos;
    float mfMinPos;

    cVector2f mvRelMousePos;

    cWidgetButton* mvButtons[2];

    cGuiGfxElement* mpGfxButtonBackground;
    cGuiGfxElement* mvGfxBorders[4];
    cGuiGfxElement* mvGfxCorners[4];

    cGuiGfxElement* mvGfxArrow[2];
    cGuiGfxElement* mpGfxBackground;
};

}; // namespace hpl
