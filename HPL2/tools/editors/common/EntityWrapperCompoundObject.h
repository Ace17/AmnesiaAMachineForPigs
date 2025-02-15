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

#include "EntityWrapper.h"

//--------------------------------------------------------------------------

class cEntityWrapperTypeCompoundObject : public iEntityWrapperTypeAggregate
{
public:
	cEntityWrapperTypeCompoundObject();

protected:
	iEntityWrapperData* CreateSpecificData();
};

//--------------------------------------------------------------------------

class cEntityWrapperDataCompoundObject : public iEntityWrapperDataAggregate
{
public:
	cEntityWrapperDataCompoundObject(iEntityWrapperType* apType);
	~cEntityWrapperDataCompoundObject();

protected:
	iEntityWrapper* CreateSpecificEntity();
};

//--------------------------------------------------------------------------

class cEntityWrapperCompoundObject : public iEntityWrapperAggregate
{
public:
	cEntityWrapperCompoundObject(iEntityWrapperData* apData);
	~cEntityWrapperCompoundObject();

	void OnAddComponent(iEntityWrapper* apEntity);
	void OnRemoveComponent(iEntityWrapper* apEntity);

	void Draw(cEditorWindowViewport* apViewport, cRendererCallbackFunctions* apFunctions, iEditorEditMode* apEditMode, bool abIsSelected, const cColor& aHighlightCol=cColor(1,1), const cColor& aDisabledCol=cColor(0.5f,1));
	cEditorWindowEntityEditBox* CreateEditBox(cEditorEditModeSelect* apEditMode);

protected:

};

//--------------------------------------------------------------------------

