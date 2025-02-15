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


#include "EditorEditModeSelectTool.h"


class cEditorEditModeSelectToolRotate : public cEditorEditModeSelectTool
{
public:
	cEditorEditModeSelectToolRotate(cEditorEditModeSelect* apParent, cEditorSelection* apSelection);

	bool IsActive();

	bool CheckRayIntersectsAxis(eSelectToolAxis aeAxis, const cVector3f& avRayStart, const cVector3f& avRayEnd){return false;}
	bool PointIntersectsAxis(eSelectToolAxis aeAxis, const cVector2f& avPoint);

	void CheckMouseOverAxis();

	cMatrixf& GetTransformMatrix();

	void DrawAxes(cEditorWindowViewport* apViewport, cRendererCallbackFunctions *apFunctions, float afAxisLength);
	
	void UpdateTransformation();


	void UpdateToolBoundingVolume();

	iEditorAction* CreateAction();

	void Reset();
	
	
	cPlanef mClipPlane;

	std::vector<cRect2f> mRectAxisAreaSphCoords[3];
	cRect2f mrectXAxisSphCoords1;
	cRect2f mrectXAxisSphCoords2;

	cRect2f mrectYAxisSphCoords1;
	cRect2f mrectYAxisSphCoords2;

	cRect2f mrectZAxisSphCoords1;
	cRect2f mrectZAxisSphCoords2;
	cRect2f mrectZAxisSphCoords3;

	cVector3f mvMouseDownCoords;
	cVector3f mvMouseUpCoords;

	cVector2f mvOldMousePos;
	cVector2f mvMousePos;

	cVector3f mvDisplacement;

	cVector3f mvReferenceRotation;

	cVector3f mvTangentVector;

	cVector3f mvScreenSpaceTangentVector;

};

