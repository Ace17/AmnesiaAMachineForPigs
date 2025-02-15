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

#include "hpl.h"

#include "LevelEditorWindow.h"

using namespace hpl;

//---------------------------------------------------------------

class cLevelEditor;

//---------------------------------------------------------------

class cLevelEditorLowerToolbar : public iLevelEditorWindow
{
public:
	cLevelEditorLowerToolbar(cLevelEditor* apEditor);
	~cLevelEditorLowerToolbar();

	void OnUpdate(float afTimeStep);

protected:
	////////////////////////////////
	// Own functions
	bool ButtonPressed(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(ButtonPressed);

	bool CheckBoxChange(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(CheckBoxChange);

	bool TextBoxChange(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(TextBoxChange);

	////////////////////////////////
	// Implemented functions
	void OnInitLayout();

	////////////////////////////////
	// Data
	cWidgetButton* mvButtons[5];

	cWidgetGroup*	mpGridControlsGroup;
	cWidgetLabel*	mvLabels[2];
	cWidgetTextBox* mvTextBoxes[2];

	cWidgetCheckBox* mpSnapToGridCheckBox;

	cWidgetCheckBox* mpCheckBoxGlobalAmbientLight;
	cWidgetCheckBox* mpCheckBoxGlobalPointLight;

};

//--------------------------------------------------------------------

