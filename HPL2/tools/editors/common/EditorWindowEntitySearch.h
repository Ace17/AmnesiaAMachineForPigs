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

#include "EditorWindow.h"

class cEditorEditModeSelect;

enum eEditorEntityType;

class cEditorWindowEntitySearch : public iEditorWindowPopUp
{
public:
	cEditorWindowEntitySearch(iEditorBase* apEditor);
	~cEditorWindowEntitySearch();


protected:
	bool SearchParam_OnChange(iWidget* apWidget,const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(SearchParam_OnChange);

	bool InputCallback(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(InputCallback);

	bool StringLocation_OnCheckChange(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(StringLocation_OnCheckChange);

	void UpdateFoundEntities();
	void UpdateItemHighlight();

	void OnInitLayout();
	void OnUpdate(float afTimeStep);
	void OnWorldModify();
	void OnSelectionChange();

	void OnSetActive(bool abX);

	////////////////////////////////////
	// Data

	cEditorEditModeSelect* mpEditMode;
	tEntityWrapperList mlstFoundEntities;
	bool mbStartingWithLocation;
	bool mbMustUpdateList;
	bool mbUpdateHighlights;

	////////////////////////
	// Layout stuff

	cWidgetLabel* mpLabelSearch;
	cWidgetTextBox* mpInputSearch;

	cWidgetLabel* mpLabelInside;
	cWidgetComboBox* mpComboBoxInside;
	cWidgetMultiPropertyListBox* mpListFoundEntities;
	cWidgetButton* mvButtons[4];
};

