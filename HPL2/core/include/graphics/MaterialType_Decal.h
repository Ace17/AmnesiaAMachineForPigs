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

#include "graphics/Material.h"
#include "graphics/MaterialType.h"

namespace hpl
{

//---------------------------------------------------
// Decal
//---------------------------------------------------

class cMaterialType_Decal_Vars : public iMaterialVars
{
public:
    cMaterialType_Decal_Vars() {}
    ~cMaterialType_Decal_Vars() {}
};

//-----------------------------------------------------

class cMaterialType_Decal : public iMaterialType
{
public:
    cMaterialType_Decal(cGraphics* apGraphics, cResources* apResources);
    ~cMaterialType_Decal();

    void DestroyProgram(cMaterial* apMaterial, eMaterialRenderMode aRenderMode, iGpuProgram* apProgram);

    iTexture* GetTextureForUnit(cMaterial* apMaterial, eMaterialRenderMode aRenderMode, int alUnit);
    iTexture* GetSpecialTexture(cMaterial* apMaterial, eMaterialRenderMode aRenderMode, iRenderer* apRenderer, int alUnit);

    iGpuProgram* GetGpuProgram(cMaterial* apMaterial, eMaterialRenderMode aRenderMode);

    void SetupTypeSpecificData(eMaterialRenderMode aRenderMode, iGpuProgram* apProgram, iRenderer* apRenderer);
    void SetupMaterialSpecificData(eMaterialRenderMode aRenderMode, iGpuProgram* apProgram, cMaterial* apMaterial, iRenderer* apRenderer);
    void SetupObjectSpecificData(eMaterialRenderMode aRenderMode, iGpuProgram* apProgram, iRenderable* apObject, iRenderer* apRenderer);

    iMaterialVars* CreateSpecificVariables();
    void LoadVariables(cMaterial* apMaterial, cResourceVarsObject* apVars);
    void GetVariableValues(cMaterial* apMaterial, cResourceVarsObject* apVars);

    void CompileMaterialSpecifics(cMaterial* apMaterial);

private:
    void LoadData();
    void DestroyData();
};

//---------------------------------------------------

}; // namespace hpl
