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

#include "EditorVar.h"

//----------------------------------------------------------------------

class iEditorBase;

class cEditorEditModeSelect;
class cEntityWrapperBillboard;
class cEntitySelectorHighlighter;

//----------------------------------------------------------------------

class cEditorWindowEntityEditBoxBillboard : public cEditorWindowEntityEditBox
{
public:
	cEditorWindowEntityEditBoxBillboard(cEditorEditModeSelect* apEditMode,cEntityWrapperBillboard* apArea);
	virtual ~cEditorWindowEntityEditBoxBillboard();

	void Create();
protected:
	void AddPropertySetBillboard(cWidgetTab* apParentTab);

	void OnUpdate(float afTimeStep);

	bool InputCallback(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(InputCallback);

	bool HighlighterCallback(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(HighlighterCallback);

	bool WindowSpecificInputCallback(iEditorInput* apInput);

	tWStringVec mvLoadedFiles;
	tWString msLastPath;

	cWidgetTab* mpTabGeneral;
	cWidgetTab* mpTabBillboard;

	cEntityWrapperBillboard* mpEntity;

	cEditorInputEnum* mpInpType;
	cEditorInputNumber* mpInpOffset;
	cEditorInputVec2* mpInpSize;
	cEditorInputColorFrame* mpInpColor;

	cEditorInputFile* mpInpMaterial;

	cEditorInputText* mpInpConnectedLight;
	cWidgetButton* mpBConnectLight;

	cEditorInputBool* mpInpHalo;
	cEditorInputVec3* mpInpHaloSourceSize;

	cEntitySelectorHighlighter* mpLightHighlighter;
};

//----------------------------------------------------------------------


