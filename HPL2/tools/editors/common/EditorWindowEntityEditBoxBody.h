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
class cEntityWrapperBody;

//----------------------------------------------------------------------

class cEditorWindowEntityEditBoxBody : public cEditorWindowEntityEditBox
{
public:
	cEditorWindowEntityEditBoxBody(cEditorEditModeSelect* apEditMode,cEntityWrapperBody* apObject);
	virtual ~cEditorWindowEntityEditBoxBody();

	void Create();

	void AddAttachedChild(iEntityWrapper* apChild);
	void RemoveAttachedChild(iEntityWrapper* apChild);

protected:
	void OnUpdate(float afTimeStep); 

	void AddPropertySetBody(cWidgetTab* apParentTab);

	bool InputCallback(iWidget* apWidget, const cGuiMessageData& aData);
	kGuiCallbackDeclarationEnd(InputCallback);

	bool WindowSpecificInputCallback(iEditorInput* apInput);

	//////////////////////////////////
	// Data
	cWidgetTab* mpTabGeneral;
	cWidgetTab* mpTabBody;
	cWidgetTab* mpTabAttachments;

	cWidgetLabel* mpLabelMaterial;
	cWidgetComboBox* mpComboBoxMaterial;
	cWidgetLabel* mpLabelMass;
	cWidgetTextBox* mpInputMass;
	cWidgetLabel* mpLabelAngularDamping;
	cWidgetTextBox* mpInputAngularDamping;
	cWidgetLabel* mpLabelLinearDamping;
	cWidgetTextBox* mpInputLinearDamping;
	cWidgetLabel* mpLabelMaxAngularSpeed;
	cWidgetTextBox* mpInputMaxAngularSpeed;
	cWidgetLabel* mpLabelMaxLinearSpeed;
	cWidgetTextBox* mpInputMaxLinearSpeed;
	
	cEditorInputNumber* mpInpBuoyancyDensityMul;

	cWidgetCheckBox* mpCheckBoxBlocksSound;
	cWidgetCheckBox* mpCheckBoxContinuousCollision;
	cWidgetCheckBox* mpCheckBoxCanAttachCharacter;
	cWidgetCheckBox* mpCheckBoxPushedByCharacterGravity;
	cWidgetCheckBox* mpCheckBoxCollideCharacter;
	cWidgetCheckBox* mpCheckBoxCollideNonCharacter;
	cWidgetCheckBox* mpCheckBoxVolatile;
	cEditorInputBool* mpInpUseSurfaceEffects;
	cEditorInputBool* mpInpHasGravity;

	cEntityWrapperBody* mpEntity;
};

//----------------------------------------------------------------------


