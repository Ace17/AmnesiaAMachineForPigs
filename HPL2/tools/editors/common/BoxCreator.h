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

#include "StdAfx.h"

#include "EditorAxisAlignedPlane.h"
#include "ShapeCreator.h"

//-----------------------------------------------------------

using namespace hpl;

class iEditorEditMode;
class cEditorWindowViewport;

//-----------------------------------------------------------

///////////////////////////////////////////////////////
// Box Creator
//  Used to create box shapes through User Interface (via click and drag)
class cBoxCreator : public iShapeCreator
{
public:
	cBoxCreator(iEditorEditMode* apEditMode);

	/////////////////////////////////////////////////
	// Methods for interaction with viewports
	void OnViewportMouseDown(int alButtons);
	void OnViewportMouseUp(int alButtons);

	/**
	 * Draws the creator
	 */
	void Draw(cEditorWindowViewport* apViewport, cRendererCallbackFunctions* apFunctions);

	/**
	 * To be called by Update in the editor base, updates the current state
	 */
	void OnEditorUpdate();

	/**
	 * Returns true if the creation is finished
	 * \return 
	 */
	bool IsDoneCreating();
	void Reset();

	//////////////////////////////////////////
	// Center and size for the created box
	cVector3f GetBoxCenter();
	cVector3f GetBoxSize();

	/**
	 * Size that will be set when using quick creation (clicking once without dragging)
	 * \param avX 
	 */
	void SetDefaultSize(const cVector3f& avX) { mvDefaultSize = avX; }

private:
	void OnStoreMousePosition(const cVector3f& avX);

	cVector3f mvDefaultSize;

	ePlaneNormal mPlaneNormal;
	cPlanef mBoxHeightPlane;
};

//-----------------------------------------------------------


