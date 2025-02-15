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

#include "EditorEditMode.h"

#include "EditorTypes.h"

//------------------------------------------------------------

class iEditorBase;

class cEditorWindowViewport;

class cEditorWindowLights;
class iEditorWorld;
class iShapeCreator;

//------------------------------------------------------------

class cEditorEditModeLights : public iEditorEditModeObjectCreator
{
public:
	cEditorEditModeLights(iEditorBase* apEditor,
						  iEditorWorld* apEditorWorld);
	~cEditorEditModeLights();

	void DrawObjectPreview(cEditorWindowViewport* apViewport, cRendererCallbackFunctions *apFunctions, const cMatrixf& amtxTransform, bool abPreCreationActive);
	void OnViewportMouseDown(int alButtons);
	void OnViewportMouseUp(int alButtons);
	void OnEditorUpdate(float afTimeStep);
protected:
	iEditorWindow* CreateSpecificWindow();
	void CreateTypes();
	bool SetUpCreationData(iEntityWrapperData*);
	void OnSetSubType(int);

	std::vector<iShapeCreator*> mvShapeCreators;
	iShapeCreator* mpCurrentCreator;
};

//------------------------------------------------------------


