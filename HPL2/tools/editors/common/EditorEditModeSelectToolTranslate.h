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
//---------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////
// SELECT TOOL TRANSLATE
////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------

class cEditorEditModeSelectToolTranslate : public cEditorEditModeSelectTool
{
public:
	cEditorEditModeSelectToolTranslate(cEditorEditModeSelect* apParent, cEditorSelection* apSelection);

	bool IsActive();

	bool CheckRayIntersectsAxis(eSelectToolAxis aeAxis, const cVector3f& avRayStart, const cVector3f& avRayEnd);

	void CheckMouseOverAxis();

	void UpdateTransformation();

	void StartTransform(const cVector3f& avEditCursor);

	cMatrixf& GetTransformMatrix();

	iEditorAction* CreateAction();


	void DrawAxes(cEditorWindowViewport* apViewport, cRendererCallbackFunctions *apFunctions, float afAxisLength);

	void UpdateToolBoundingVolume();

	cVector3f mvAxisMin[3];
	cVector3f mvAxisMax[3];
	cVector3f mvHeadMin[3];
	cVector3f mvHeadMax[3];

	cVector3f mvAxesPlaneBoxMin;
	cVector3f mvAxesPlaneBoxMax[3];

	tVertexVec mvArrowQuads[4];

	cPlanef mTranslationPlane;

};
