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

#include "EditorTypes.h"

//-------------------------------------------------------

class iTypeNode;

//-------------------------------------------------------

typedef std::vector<iTypeNode*> tTypeNodeVec;

//-------------------------------------------------------

class iEdWorld;

//-------------------------------------------------------

class iTypeNode
{
public:
	iTypeNode(iEdWorld*, int, const tWString&, iTypeNode*);

	bool Init();

	const tWString& GetName() { return msName; }
	tWString GetFullName();

	bool IsA(int);
	bool IsA(const tWString&);

	virtual iTypeNode* GetTypeByName(const tWString&);
	virtual iTypeNode* GetTypeByID(int);
	virtual iTypeNode* GetTypeByXmlElement(cXmlElement*);

protected:
	bool AddChildType(iTypeNode*);

	/////////////////////////////////////////////////
	// Interface for adding properties to a type
	void AddInt();
	void AddFloat();
	void AddBool();
	void AddStr();
	void AddColor();
	void AddVec2f();
	void AddVec3f();
	void AddTexture();
	void AddMaterial();
	void AddSound();
	void AddMesh();


	iEdWorld* mpWorld;
	int mlID;
	tWString msName;

	iTypeNode* mpParentType;
	tTypeNodeVec mvChildTypes;
};

//-------------------------------------------------------

