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

//---------------------------------------------------------

#include "EditorWindow.h"
#include "EditorEditModeCombine.h"

//---------------------------------------------------------

/////////////////////////////////////////////////////////////
// cEditorWindowCombine
//	Window belonging to EditModeCombine. Holds inputs to
//	manage the EditMode operation
class cEditorWindowCombine : public iEditModeWindow
{
public:
	cEditorWindowCombine(iEditorEditMode* apEditMode);

	/**
	 * Returns combo currently selected in the ComboBox
	 */
	cLevelEditorStaticObjectCombo* GetCurrentCombo();

	/** 
	 * Returns selected operation mode (add or remove objects)
	 */
	eCombinePickMode GetPickMode();

	/**
	 * Returns if all combos should be displayed
	 */
	bool GetShowAllCombos() { return mpInpShowAll->GetValue(); }

protected:
	void OnInitLayout();
	void OnUpdate(float afTimeStep);

	bool ButtonPressed(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(ButtonPressed);

	bool WindowSpecificInputCallback(iEditorInput* apInput);

	//////////////////////////////////////
	// Layout stuff
	cWidgetButton* mpBAddComb;
	cWidgetButton* mpBRemComb;

	cEditorInputBool* mpInpShowAll;

	cEditorInputEnum* mpInpCombinations;
	cEditorInputBool* mvInpPickModes[3];
	cEditorInputColorFrame* mpInpCombColor;

	cWidgetListBox* mpLBStaticObjects;
	bool mbAddedNewCombo;

	// Combo extra data
	tIntVec mvComboIDs;
};

//---------------------------------------------------------

