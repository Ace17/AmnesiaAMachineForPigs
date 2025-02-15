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

#include "../common/EditorBaseClasses.h"

#include "../common/EditorTypes.h"

#include "MaterialEditorTypes.h"

//--------------------------------------------------------------------

class iEditorWindow;

class iEditorEditMode;
class cEditorWindowViewport;
class cEditorActionHandler;

class cLevelEditor;
class cEditorGrid;
class iEditorWorld;

class cEditorWindowTextureBrowser;
class cEditorWindowOptions;
class cEditorWindowMaterialEditor;

//--------------------------------------------------------------------

class cMaterialEditor : public iEditorBase
{
public:
	cMaterialEditor(const tString& asCommandLine);
	~cMaterialEditor();

protected:
	///////////////////////////
	// Own functions
	void LoadEditorSession(iXmlDocument* apDoc, cXmlElement** apElement) {}
	void SaveEditorSession(iXmlDocument* apDoc, cXmlElement** apElement) {}
	
	void AppSpecificReset(){}
	void AppSpecificLoad(iXmlDocument* apDoc){}
	void AppSpecificSave(iXmlDocument* apDoc){}

	void SetUpWindowAreas(){}
	void InitRenderTarget(const cVector2f& avSize){}
	void CreateViewports(){}
	

	void UpdateEditMenu();

	///////////////////////////
	// Implemented functions
	void OnSetUpDirectories();

	void OnUpdate(float afTimeStep);

	void OnSetSelectedViewport(){}

	void OnPostUpdateLayout();

	void OnInit();
	void OnInitInput();
	void OnInitLayout();

	void OnLoadConfig();
	void OnSaveConfig();

	void SetUpClassDefinitions(cEditorUserClassDefinitionManager* apManager) {}

	iEditorWorld* CreateSpecificWorld() { return NULL; }
	iEditorWindowLowerToolbar* CreateSpecificLowerToolbar() { return NULL; }
	iEditorWindowEditModeSidebar* CreateEditModeSidebar() { return NULL; }

	///////////////////////////
	// Data


	///////////////////////
	// Config stuff
	cConfigFile* mpLocalConfig;

	tString msCommandLineFile;
};

//----------------------------------------------------------


