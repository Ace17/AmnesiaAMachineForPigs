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

#include "EditorEditMode.h"
#include "../leveleditor/LevelEditorStaticObjectCombo.h"

//--------------------------------------------------------------

enum eCombinePickMode
{
	eCombinePickMode_Add,
	eCombinePickMode_Remove,
	eCombinePickMode_Toggle,
};

//--------------------------------------------------------------

class cEditorEditModeCombine : public iEditorEditMode
{
public:
	cEditorEditModeCombine(iEditorBase* apEditor);
	~cEditorEditModeCombine();

	void OnViewportMouseDown(int alButtons);
	void OnViewportMouseUp(int alButtons);

	void OnEditorUpdate(float afTimeStep);

	void DrawPostGrid(cEditorWindowViewport* apViewport, cRendererCallbackFunctions* apFunctions, const cVector3f& avPos);

	void Reset();

	///////////////////////////////////
	// Interface for window
	const tStaticObjectComboList& GetCombos();
	cLevelEditorStaticObjectCombo* GetCombo(int alID);

	void AddCombo();
	void RemoveCombo(int alID);
	void SetComboColor(int alID, const cColor& aCol);

protected:
	iEditorWindow* CreateSpecificWindow();

	/**
	 * Functions that do the actual picking
	 */
	void DoRayPicking(cLevelEditorStaticObjectCombo* apCombo, cEditorWindowViewport* apViewport, cEntityPicker* apPicker);
	void DoBoxPicking(cLevelEditorStaticObjectCombo* apCombo, cEditorWindowViewport* apViewport, cEntityPicker* apPicker);
	
	/**
	 * Create an action according to pick mode
	 */
	iEditorAction* CreateProperAction(cLevelEditorStaticObjectCombo* apCombo, iEntityWrapper* apObj,  eCombinePickMode aMode);

	/**
	 * Returns true if the user is not attempting to do a box picking (box is too small)
	 */
	bool IsRayPickingActive();

	///////////////////////////////////
	// Data
	bool mbPressed;
	cRect2l mMouseRect;

	tEntityWrapperList mlstEntsToBePicked;

	cUIPickFilter* mpFilter;
	cUIPickMethod* mpRay;
	cUIPickMethod* mpBox;
};

//--------------------------------------------------------------

