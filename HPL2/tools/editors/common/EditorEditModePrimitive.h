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

//---------------------------------------------------------------------------

class cEditorEditModePrimitives;

//---------------------------------------------------------------------------

class iPrimitiveMeshCreator
{
public:
	iPrimitiveMeshCreator(cEditorEditModePrimitives* apEditMode);

	void SetPrimitiveType(iEntityWrapperType* apType) { mpType = apType; }

	virtual void OnViewportMouseDown(int alButtons){}
	virtual void OnViewportMouseUp(int alButtons){}

	virtual void Draw(cEditorWindowViewport* apViewport, cRendererCallbackFunctions* apFunctions, const cVector3f& avPos)=0;

	virtual iEntityWrapperData* CreateData();
	virtual void SetUpData(iEntityWrapperData*);
    
	virtual void Reset(){}

	virtual bool IsDoneCreating()=0;
protected:
	cEditorEditModePrimitives* mpEditMode;
	iEntityWrapperType* mpType;
};

//---------------------------------------------------------------------------

class cPrimitiveMeshCreatorPlane : public iPrimitiveMeshCreator
{
public:
	cPrimitiveMeshCreatorPlane(cEditorEditModePrimitives* apEditMode);

    void OnViewportMouseDown(int alButtons);
	void OnViewportMouseUp(int alButtons);

	void Draw(cEditorWindowViewport* apViewport, cRendererCallbackFunctions* apFunctions, const cVector3f& avPos);

	void SetUpData(iEntityWrapperData* apData);

	void Reset();

	bool IsDoneCreating();

	void StoreMousePosition();

protected:
	void SortCorners();
	tVector3fVec mvCorners;
};

//---------------------------------------------------------------------------

class cEditorEditModePrimitives : public iEditorEditModeObjectCreator
{
public:
	cEditorEditModePrimitives(iEditorBase* apEditor, iEditorWorld* apEditorWorld);
	~cEditorEditModePrimitives();

    void OnViewportMouseDown(int alButtons);
	void OnViewportMouseUp(int alButtons);

	void DrawPostGrid(cEditorWindowViewport* apViewport, cRendererCallbackFunctions* apFunctions, const cVector3f& avPos);

	iEntityWrapperData* CreateObjectData();

	void SetPrimitiveType(int alX);
protected:
	iEditorWindow* CreateSpecificWindow();
	void CreateTypes();

	iPrimitiveMeshCreator* mpCurrentCreator;
	std::vector<iPrimitiveMeshCreator*> mvMeshCreators;
};

//---------------------------------------------------------------------------

