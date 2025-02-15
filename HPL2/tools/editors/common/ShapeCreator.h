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

class iEditorEditMode;
class cEditorWindowViewport;

class iShapeCreator
{
public:
	iShapeCreator(iEditorEditMode* apEditMode) : mpEditMode(apEditMode), mbDragging(true) {}

	virtual void OnViewportMouseDown(int alButtons)=0;
	virtual void OnViewportMouseUp(int alButtons)=0;

	virtual void Draw(cEditorWindowViewport* apViewport, cRendererCallbackFunctions* apFunctions)=0;

	virtual void OnEditorUpdate()=0;

	virtual bool IsDoneCreating()=0;
	virtual void Reset()=0;

	void SetDraggingEnabled(bool abX) { mbDragging = abX; }
	bool IsDraggingEnabled() { return mbDragging; }

protected:
	void StoreMousePosition(const cVector3f& avX)
	{
		mvPoints.push_back(avX);
		OnStoreMousePosition(avX);

	}
	virtual void OnStoreMousePosition(const cVector3f& avX)=0;

	iEditorEditMode* mpEditMode;
	bool mbDragging;
	tVector3fVec mvPoints;
	cVector3f mvTempPoint;

	cVector3f mvDebugPos;
};

