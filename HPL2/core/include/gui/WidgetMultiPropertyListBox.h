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

#include "gui/WidgetListBoxBase.h"

namespace hpl
{

class cWidgetLabel;

//-------------------------------------------------------------------

class cSubList
{
public:
    cSubList(const tString& asName, const int alIndex, eFontAlign aAlign)
        : msName(asName)
        , mlIndex(alIndex)
        , mAlign(aAlign)
    {
    }

    tString msName;
    int mlIndex;
    eFontAlign mAlign;
};

//-------------------------------------------------------------------

typedef std::vector<cSubList> tSubListVec;
typedef tSubListVec::iterator tSubListVecIt;

typedef std::vector<cWidgetLabel*> tLabelVec;
typedef tLabelVec::iterator tLabelVecIt;

//-------------------------------------------------------------------

class cWidgetMultiPropertyListBox : public iWidgetListBoxBase
{
public:
    cWidgetMultiPropertyListBox(cGuiSet* apSet, cGuiSkin* apSkin);
    virtual ~cWidgetMultiPropertyListBox();

    void AddColumn(const tString& asName, const int alIndex, eFontAlign aAlign = eFontAlign_Left);

    void SetColumnWidth(const int alIdx, float afWidth);

    cVector3f GetItemStartPos();

protected:
    ////////////////////////
    // Own functions
    void UpdateColumns();

    ////////////////////////
    // Implemented functions
    void DrawItems(float afTimeStep, cGuiClipRegion* apClipRegion);

    void OnLoadGraphics();

    //////////////////////////////
    // Data

    tSubListVec mvSubLists;
    tLabelVec mvColumns;

    float mfIconSize;
};
}; // namespace hpl

