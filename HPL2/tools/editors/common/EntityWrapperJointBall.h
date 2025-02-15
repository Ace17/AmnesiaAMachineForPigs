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

#include "StdAfx.h"

using namespace hpl;

#include "EntityWrapperJoint.h"

//-----------------------------------------------------------------

enum eJointBallFloat
{
	eJointBallFloat_MaxConeAngle = eJointFloat_LastEnum, 
	eJointBallFloat_MaxTwistAngle,

	eJointBallFloat_LastEnum,
};

//-----------------------------------------------------------------

class cEntityWrapperTypeJointBall : public iEntityWrapperTypeJoint
{
public:
	cEntityWrapperTypeJointBall();

protected:
	iEntityWrapperData* CreateSpecificData();
};

//-----------------------------------------------------------------

class cEntityWrapperDataJointBall : public iEntityWrapperDataJoint
{
public:
	cEntityWrapperDataJointBall(iEntityWrapperType*);
	
protected:
	iEntityWrapper* CreateSpecificEntity();

};

//-----------------------------------------------------------------

class cEntityWrapperJointBall : public iEntityWrapperJoint
{
public:
	cEntityWrapperJointBall(iEntityWrapperData*);

	bool SetProperty(int, const float&);
	bool GetProperty(int, float&);

	void SetMaxConeAngle(float afX) { mfMaxConeAngle = afX; }
	void SetMaxTwistAngle(float afX) { mfMaxTwistAngle = afX; }
	
	float GetMaxConeAngle() { return mfMaxConeAngle; }
	float GetMaxTwistAngle() { return mfMaxTwistAngle; }
	
	//void Draw(cEditorWindowViewport* apViewport, cRendererCallbackFunctions* apFunctions, iEditorEditMode* apEditMode, bool abIsSelected);

	//void SaveToElement(cXmlElement* apElement);
	
protected:
	float mfMaxConeAngle;
	float mfMaxTwistAngle;
};

//-----------------------------------------------------------------

