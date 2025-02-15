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
using namespace hpl;

#include "LevelEditorWindow.h"

#include "LevelEditorTypes.h"

//---------------------------------------------------------------

class cLevelEditor;


//---------------------------------------------------------------

class cLevelEditorWindowGroup : public iEditorWindowPopUp
{
public:
	cLevelEditorWindowGroup(cLevelEditor* apEditor);
	~cLevelEditorWindowGroup();


protected:
	////////////////////////////////
	// Own functions
	bool MainMenu_ItemClick(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(MainMenu_ItemClick);

	bool GroupList_OnSelectionChange(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(GroupList_OnSelectionChange);

	bool EntityList_OnSelectionChange(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(EntityList_OnSelectionChange);

	bool VisibilityCheckBox_OnChange(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(VisibilityCheckBox_OnChange);

	bool Name_OnEnter(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(Name_OnEnter);

	void UpdateGroupList();
	void UpdateEntityList();
	void UpdateGroupParams();
	////////////////////////////////
	// Implemented functions
	void OnInitLayout();

	void OnWorldModify();

	void OnUpdate(float afTimeStep);

	////////////////////////////////
	// Data
	tGroupMap* mpGroupMap;
	tIntVec		mvGroupIDs;

	bool mbMustUpdateGroupList;
	bool mbMustUpdateList;

	cWidgetMainMenu* mpMainMenu;
	cWidgetMenuItem* mpMainMenuNew;
	cWidgetMenuItem* mpMainMenuDelete;
	cWidgetMenuItem* mpMainMenuAddSelected;
	cWidgetMenuItem* mpMainMenuRemoveSelected;
	cWidgetMenuItem* mpMainMenuSelect;
	cWidgetMenuItem* mpMainMenuDeselect;
	cWidgetMenuItem* mpMainMenuExit;

	cWidgetTextBox* mpInputName;
	cWidgetListBox* mpListGroups;
	cWidgetMultiPropertyListBox* mpListGroupEntities;
	cWidgetCheckBox* mpCheckBoxGroupVisibility;

};

//--------------------------------------------------------------------

