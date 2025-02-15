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

#include "../common/StdAfx.h"

using namespace hpl;

#include "EditorWindow.h"
#include "EditorEditModeSelect.h"

//---------------------------------------------------

class cEditorEditModeSelect;

//---------------------------------------------------

class cEditorWindowSelect : public iEditModeWindow
{
public:
	cEditorWindowSelect(cEditorEditModeSelect* apEditMode);

	eSelectToolMode GetToolMode() { return mToolMode; }

	void SetSelectableTools(bool abTranslate, bool abRotate, bool abScale);

	/**
	 * Adds a button to be able to filter the given type
	 */
	void AddFilter(eEditorEntityType aType);

protected:
	bool TypeChange(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(TypeChange);

	bool ButtonPressed(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(ButtonPressed);

	bool FilterButtonPressed(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(FilterButtonPressed);

	void UpdateButtonHighLight();
	void UpdateFilterButtons();

	void OnInitLayout();
	void OnUpdate(float afTimeStep);
	void OnSetActive(bool abX);

	eSelectToolMode mToolMode;

	cWidgetGroup* mpObjectTypeGroup;
	std::list<cWidgetButton*> mlstBFilters;

	cWidgetCheckBox* mpCBSelectAll;
	cWidgetCheckBox* mpCBSelectMultipleTypes;

	cWidgetGroup* mpToolSelectGroup;
	cWidgetButton* mvButtons[3];

	cGuiGlobalShortcut* mvShortcuts[3];
};

//---------------------------------------------------

