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

class iEntityWrapper;
class cEditorWindowViewport;
class iEditorEditMode;

class cEntityIcon
{
public:
	cEntityIcon(iEntityWrapper* apParent, const tString& asIconGfxName);
	~cEntityIcon();

	bool Check2DBoxIntersect(cEditorWindowViewport*, const cRect2l&);
	bool CheckRayIntersect(cEditorWindowViewport* , cVector3f* , tVector3fVec*, float* apT=NULL);

	void DrawIcon(cEditorWindowViewport* apViewport, 
				  cRendererCallbackFunctions* apFunctions, 
				  iEditorEditMode* apEditMode, 
				  bool abIsSelected,
				  const cVector3f& avPos,
				  bool abIsActive,
				  const cColor& aDisabledCol=cColor(0.1f, 1));

	cRect2l GetIconClipRectangle(cEditorWindowViewport* apViewport, iEntityWrapper* apEntity);

	cBoundingVolume* GetPickBV(cEditorWindowViewport* apViewport, const cVector3f& avSize=0.06f);

	void SetVisible(bool abX) { mbVisible = abX; }
protected:
	iEntityWrapper* mpParent;
	iTexture* mvIconGfx[2];

	cBoundingVolume mIconBV;
	bool mbVisible;
};

//-----------------------------------------------------------------------

