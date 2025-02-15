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

#ifndef LUX_COMPLETION_COUNT_HANDLER_H
#define LUX_COMPLETION_COUNT_HANDLER_H

//----------------------------------------------

#include "LuxBase.h"

//----------------------------------------

class cLuxCompletionCountHandler : public iLuxUpdateable
{
    friend class cLuxMusicHandler_SaveData;

public:
    cLuxCompletionCountHandler();
    ~cLuxCompletionCountHandler();

    void LoadFonts();
    void OnStart();
    void Update(float afTimeStep);
    void Reset();
    void OnDraw(float afFrameTime);

    void OnMapExit(cLuxMap* apMap);

    void ShowCompletionIncrease(float afPrevius, float afNew, float afDelay);

public:
    int mlQuestCompletionValue;
    int mlItemCompletionValue;
    int mlNoteCompletionValue;
    int mlDiaryCompletionValue;
    int mlFlashbackCompletionValue;
    int mlChestCompletionValue;

private:
    //////////////////
    // Data
    iFontData* mpFont;

    //////////////////
    // Variables
    bool mbActive;
    float mfAlpha;

    float mfDelay;
    float mfNewAmount;
    float mfDisplayedAmount;
    float mfDisableDelay;
};

//----------------------------------------------

#endif // LUX_COMPLETION_COUNT_HANDLER_H
