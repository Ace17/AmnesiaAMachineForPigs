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

//----------------------------------------------------------

class cEditorEditModePrimitives;

//----------------------------------------------------------

class cEditorWindowPrimitives : public iEditModeObjectCreatorWindow
{
public:
	cEditorWindowPrimitives(cEditorEditModePrimitives* apEditMode);
	~cEditorWindowPrimitives();

	void Reset();

	const tString& GetMaterial();
	cVector3f GetTileAmount();
	cVector3f GetTileOffset();
	float GetTextureAngle();
	bool GetAlignToWorld();
	bool GetCollides();
	bool GetCastShadows();

protected:
	void OnInit(){}
	void OnInitLayout();

	void OnLoadLevel(){}
	void OnUpdate(float afTimeStep){}

	void OnSetActive(bool abX);

 	void ResetInputs();

	bool WindowSpecificInputCallback(iEditorInput*);

	////////////////////////////////////////////////////
	// Data
	
	// Layout stuff
	// General
	cEditorInputEnum* mpInpPrimitiveType;
	cEditorInputFile* mpInputMaterial;
	cEditorInputBool* mpInputCastShadows;
	cEditorInputBool* mpInpCollides;

	// Plane
	cEditorInputNumber* mpInpTextureAngle;
	cEditorInputVec3* mpInputTileAmount;
	cEditorInputVec3* mpInputTileOffset;
	cEditorInputBool* mpInputAlignToWorld;

	tWStringVec mvFilesToLoad;
};

//----------------------------------------------------------

