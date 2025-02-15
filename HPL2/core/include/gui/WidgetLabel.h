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

class cWidgetLabel : public iWidget
{
public:
    cWidgetLabel(cGuiSet* apSet, cGuiSkin* apSkin);
    virtual ~cWidgetLabel();

    void SetTextAlign(eFontAlign aType) { mTextAlign = aType; }
    eFontAlign GetTextAlign() { return mTextAlign; }

    bool GetWordWrap() { return mbWordWrap; }
    void SetWordWrap(bool abX) { mbWordWrap = abX; }

    void SetMaxTextLength(int alLength);
    int GetMaxTextLength() { return mlMaxCharacters; }

    void SetAutogenerateSize(bool abX);
    bool GetAutogenerateSize() { return mbAutogenerateSize; }

    void SetDefaultFontSize(const cVector2f& avSize);

    void SetDrawBackGround(bool abX) { mbDrawBackGround = abX; }
    bool GetDrawBackGround() { return mbDrawBackGround; }

    void SetBackGroundColor(const cColor& aColor) { mBackGroundColor = aColor; }
    const cColor& GetBackGroundColor() { return mBackGroundColor; }

    void SetScrollWaitTime(float afX) { mfWaitToScrollTime = afX; }
    float GetScrollWaitTime() { return mfWaitToScrollTime; }

    void SetScrollOffset(float afX) { mfWordWrapOffset = afX; }

    void SetScrollSpeedMul(float afX) { mfScrollSpeedMul = afX; }
    float GetScrollSpeedMul() { return mfScrollSpeedMul; }

protected:
    /////////////////////////
    // Own Funcs
    void DrawText(float afTimeStep, cGuiClipRegion* apClipRegion);

    /////////////////////////
    // Implemented functions
    void OnLoadGraphics();

    void OnUpdate(float afTimeStep);

    void OnChangeText();

    void OnDraw(float afTimeStep, cGuiClipRegion* apClipRegion);
    void OnDrawAfterClip(float afTimeStep, cGuiClipRegion* apClipRegion);

    bool OnMouseMove(const cGuiMessageData& aData);
    bool OnMouseDown(const cGuiMessageData& aData);
    bool OnMouseUp(const cGuiMessageData& aData);
    bool OnMouseEnter(const cGuiMessageData& aData);
    bool OnMouseLeave(const cGuiMessageData& aData);

    /////////////////////////
    // Data
    eFontAlign mTextAlign;
    bool mbWordWrap;
    float mfWordWrapRowsHeight;
    float mfWordWrapOffset;
    float mfScrollSpeedMul;
    float mfScrollTimer;
    float mfWaitToScrollTime;
    bool mbScrollingDown;

    float mfBackgroundZ;
    cGuiGfxElement* mpGfxBackground;

    bool mbDrawBackGround;
    cColor mBackGroundColor;

    int mlMaxCharacters;

    bool mbAutogenerateSize;
};

}; // namespace hpl
