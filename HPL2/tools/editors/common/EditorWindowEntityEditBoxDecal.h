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
class cEntityWrapperDecal;

//----------------------------------------------------------------------

class cEditorWindowEntityEditBoxDecal : public cEditorWindowEntityEditBox
{
public:
	cEditorWindowEntityEditBoxDecal(cEditorEditModeSelect* apEditMode,cEntityWrapperDecal* apObject);
	virtual ~cEditorWindowEntityEditBoxDecal();

	void Create();
protected:
	void AddDecalPropertySet(cWidgetTab* apParentTab);
	void OnUpdate(float afTimeStep);

	bool InputCallback(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(InputCallback);

	bool WindowSpecificInputCallback(iEditorInput* apInput);

	cWidgetTab* mpTabGeneral;
	cWidgetTab* mpTabDecal;

	cEntityWrapperDecal* mpEntity;

	std::vector<cWidgetButton*> mvBSurfaceTypes;

	cEditorInputFile* mpInpMaterial;
	cEditorInputColorFrame* mpInpColor;

	cEditorInputEnum* mpInpSubDivisions;
	cEditorInputEnum* mpInpCurrentSubDiv;

	cEditorInputNumber* mpInpOffset;
	cEditorInputNumber* mpInpMaxTris;

	bool mbClearingSubDivValues;
};

//----------------------------------------------------------------------


