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

//------------------------------------------------------------

#include "EditorWindow.h"

//------------------------------------------------------------

class cEditorWindowOptions : public iEditorWindowPopUp
{
public:
	cEditorWindowOptions(iEditorBase* apEditor);

protected:
	void OnInitLayout();
	void PostInitLayout();
	void OnUpdate(float afTimeStep);

	bool WindowSpecificInputCallback(iEditorInput* apInput);


	///////////////////////////////////
	// Layout
	// General
	cEditorInputNumber* mpInpUndoStackSize;

	cEditorInputVec2* mpInpResolution;
	
	cEditorInputColorFrame* mpInpBackgroundColor;
	cEditorInputNumber* mpInpDisabledCoverage;

	// Input
	cEditorInputNumber* mpInpTumbleFactor;
	cEditorInputNumber* mpInpTrackFactor;
	cEditorInputNumber* mpInpZoomFactor;
	cEditorInputNumber* mpInpMouseWheelZoom;

	cEditorInputNumber* mpInpRotateSnap;
	cEditorInputNumber* mpInpScaleSnap;

	// Performance
	cEditorInputBool* mpInpLightsActive;
	cEditorInputBool* mpInpPSActive;
	cEditorInputBool* mpInpWorldReflection;

	cEditorInputBool* mpInpShowSkybox;
	cEditorInputBool* mpInpShowFog;

	cEditorInputEnum* mpInpTextureQuality;

	cEditorInputVec2* mpInpCamPlanes;
};

//------------------------------------------------------------


