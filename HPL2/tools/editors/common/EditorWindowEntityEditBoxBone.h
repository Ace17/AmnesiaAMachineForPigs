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

#include "EditorWindowEntityEditBox.h"

//----------------------------------------------------------------------

class iEntityWrapper;
class cEditorEditModeSelect;
class cEntityWrapperBone;

//----------------------------------------------------------------------

class cEditorWindowEntityEditBoxBone : public cEditorWindowEntityEditBox
{
public:
	cEditorWindowEntityEditBoxBone(cEditorEditModeSelect* apEditMode,cEntityWrapperBone* apObject);
	virtual ~cEditorWindowEntityEditBoxBone();

	void Create();

protected:
	void OnUpdate(float afTimeStep); 

	//////////////////////////////////
	// Data
	cWidgetTab* mpTabGeneral;
	cWidgetTab* mpTabAttachments;	
	
	cEntityWrapperBone* mpEntity;
};

//----------------------------------------------------------------------


