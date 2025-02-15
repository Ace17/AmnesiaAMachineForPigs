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

#include "../common/EditorAction.h"

#include "ParticleEditorTypes.h"

class cParticleEditor;

enum eEditorParticleEmitterFloatProperty
{
};

enum eEditorParticleEmitterVec3Property
{
};

enum eEditorParticleEmitterVec2Property
{
};

enum eEditorParticleEmitterStringProperty
{
};

enum eEditorParticleEmitterBoolProperty
{
};

//--------------------------------------------------------------------------------------

class cParticleEditorActionCreateEmitter : public iEditorActionWorldModifier
{
public:
	cParticleEditorActionCreateEmitter();
	void Do();
	void Undo();
};

class cParticleEditorActionDeleteEmitter : public iEditorActionWorldModifier
{
public:
	cParticleEditorActionDeleteEmitter();
	void Do();
	void Undo();
};

class cParticleEditorActionSetEmitterFloatProperty : public iEditorActionWorldModifier
{
public:
	cParticleEditorActionSetEmitterFloatProperty();
	void Do();
	void Undo();
};

class cParticleEditorActionSetEmitterVec3Property : public iEditorActionWorldModifier
{
public:
	cParticleEditorActionSetEmitterVec3Property();
	void Do();
	void Undo();
};

class cParticleEditorActionSetEmitterVec2Property : public iEditorActionWorldModifier
{
public:
	cParticleEditorActionSetEmitterVec2Property();
	void Do();
	void Undo();
};

class cParticleEditorActionSetEmitterStringProperty : public iEditorActionWorldModifier
{
public:
	cParticleEditorActionSetEmitterStringProperty();
	void Do();
	void Undo();
};

class cParticleEditorActionSetEmitterBoolProperty : public iEditorActionWorldModifier
{
public:
	cParticleEditorActionSetEmitterBoolProperty();
	void Do();
	void Undo();
};

//--------------------------------------------------------------------------------------

