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

#include "../common/EdModule.h"
#include "../common/EditMode.h"

//-----------------------------------------------------------------------

class iEdAction;
class iEdWorld;

class cActionHandler;
class cDirectoryHandler;

class cViewportHandler;

//-----------------------------------------------------------------------

/**
 * \ingroup leveleditor
 *
 *
 *
 * \version 1.0
 * first version
 *
 * \date 10-27-2010
 *
 * \author Luis
 *
 */
class iEditor : public iUpdateable
{
public:
	iEditor(const tWString&, const tWString&);
	virtual ~iEditor();

	/**
	 *
	 * \param cEngine* 
	 * \param char* 
	 * \param char* 
	 * \param bool 
	 * \return 
	 */
	cEngine* Init(cEngine*, const char*, const char*, bool);

	///////////////////////////////////////////////
	// World (Scene)
	iEdWorld* GetWorld();

	///////////////////////////////////////////////
	// Action management
	cActionHandler* GetActionHandler() { return mpActionHandler; }
	void AddAction(iEdAction*);

	///////////////////////////////////////////////
	// Directory Management
	cDirectoryHandler* GetDirHandler() { return mpDirHandler; }
	
	const tWString& GetWorkingDir();
	const tWString& GetHomeDir();
	const tWString& GetTempDir();
	const tWString& GetThumbnailDir();

	const tWString& GetMainLookUpDir(int);
	tWStringVec GetLookUpDirs(int);

	tWString GetPathRelToWD(const tWString&);

protected:
	virtual void SetUpWorld()=0;
	virtual void SetUpDirectories();
	virtual void OnSetUpDirectories()=0;

	////////////////////////////////////////////////////////////////////
	// Data
	tWString msName;
	tWString msCaption;

	// 
	cActionHandler* mpActionHandler;
	cDirectoryHandler* mpDirHandler;

	//
	tEdModuleVec	mvModules;

	// Engine related data
	bool mbDestroyEngineOnExit;
	cEngine*		mpEngine;
	iFrameBuffer*	mpFrameBuffer;
	cViewport*		mpViewport;

	cGuiSet*		mpSet;
	cGuiSkin*		mpSkin;
};

