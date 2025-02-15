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

#include "EditorWindowObjectBrowser.h"

//----------------------------------------------------------

class cEditorEditModeStaticObjects;

class cEditorObjectIndexStaticObjects;
class cEditorObjectIndexDirStaticObjects;
class cEditorObjectIndexEntryStaticObject;


//----------------------------------------------------------

class cEditorObjectIndexEntryStaticObject : public iEditorObjectIndexEntryMeshObject
{
public:
	cEditorObjectIndexEntryStaticObject(cEditorObjectIndexDirStaticObjects* apDir);
};

class cEditorObjectIndexDirStaticObjects : public iEditorObjectIndexDir
{
public:
	cEditorObjectIndexDirStaticObjects(cEditorObjectIndexStaticObjects* apIndex, cEditorObjectIndexDirStaticObjects* apParent=NULL);

	iEditorObjectIndexEntry* CreateEntry();
};

class cEditorObjectIndexStaticObjects : public iEditorObjectIndex
{
public:
	cEditorObjectIndexStaticObjects(iEditorBase* apEditor, const tWString& asBaseFolder);

	iEditorObjectIndexDir* CreateDir(iEditorObjectIndexDir* apParent=NULL);
};

//----------------------------------------------------------

class cEditorWindowStaticObjects : public cEditorWindowObjectBrowser
{
public:
	cEditorWindowStaticObjects(cEditorEditModeStaticObjects* apEditMode, const tWStringVec& avBaseDirs);
	~cEditorWindowStaticObjects();

	void SetEditMode(cEditorEditModeStaticObjects* apEditMode) { mpEditMode = apEditMode; }

	void Reset();

protected:
	iEditorObjectIndex* CreateSpecificIndex(iEditorBase* apEditor, const tWString& asFolder);

	void OnInit(){}
	void OnInitLayout();
	void OnLoadLevel(){}
	void OnUpdate(float afTimeStep){}
	//void OnSetActive(bool abX);

	void ResetInputs();

	cMeshEntity* CreatePreviewEntity(iEditorObjectIndexEntryMeshObject* apEntry);


	////////////////////////////////////////////////////
	// Data
	cEditorEditModeStaticObjects* mpEditMode;

	tWString msBaseDir;
	tWStringVec mvDirectories;
};

//----------------------------------------------------------

