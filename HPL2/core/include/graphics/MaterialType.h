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

#include "engine/EngineTypes.h"
#include "graphics/GraphicsTypes.h"
#include "math/MathTypes.h"
#include "system/SystemTypes.h"

namespace hpl
{

//---------------------------------------------------

class cGraphics;
class cResources;
class iTexture;
class iGpuProgram;
class cMaterial;
class iRenderable;
class iRenderer;
class cProgramComboManager;
class cResourceVarsObject;
class iMaterialVars;

//---------------------------------------------------

#define kPC_VertexBit eFlagBit_0
#define kPC_FragmentBit eFlagBit_1

//---------------------------------------------------

class cMaterialUsedTexture
{
public:
    eMaterialTexture mType;
};

//---------------------------------------------------

class cMaterialUserVariable
{
public:
    tString msName;
    eVariableType mType;
    tString msValue;
    tString msDescription;
    tStringVec mvEnumValues;
};

//---------------------------------------------------

class iMaterialType
{
public:
    iMaterialType(cGraphics* apGraphics, cResources* apResources);
    virtual ~iMaterialType();

    virtual void DestroyProgram(cMaterial* apMaterial, eMaterialRenderMode aRenderMode, iGpuProgram* apProgram) = 0;

    void SetName(const tString& asName);
    const tString& GetName() { return msName; }

    bool IsTranslucent() { return mbIsTranslucent; }
    bool IsDecal() { return mbIsDecal; }

    virtual iTexture* GetTextureForUnit(cMaterial* apMaterial, eMaterialRenderMode aRenderMode, int alUnit) = 0;
    virtual iGpuProgram* GetGpuProgram(cMaterial* apMaterial, eMaterialRenderMode aRenderMode) = 0;

    virtual void SetupTypeSpecificData(eMaterialRenderMode aRenderMode, iGpuProgram* apProgram, iRenderer* apRenderer) = 0;
    virtual void SetupMaterialSpecificData(eMaterialRenderMode aRenderMode, iGpuProgram* apProgram, cMaterial* apMaterial, iRenderer* apRenderer) = 0;
    virtual void SetupObjectSpecificData(eMaterialRenderMode aRenderMode, iGpuProgram* apProgram, iRenderable* apObject, iRenderer* apRenderer) = 0;

    int GetUsedTextureNum() { return (int)mvUsedTextures.size(); }
    cMaterialUsedTexture* GetUsedTexture(int alIdx) { return &mvUsedTextures[alIdx]; }

    int GetUserVariableNum() { return (int)mvUserVariables.size(); }
    cMaterialUserVariable* GetUserVariable(int alIdx);
    cMaterialUserVariable* GetUserVariable(const tString& asName);

    void Reload();

    virtual void LoadData() = 0;
    virtual void DestroyData() = 0;

    virtual iMaterialVars* CreateSpecificVariables() = 0;
    virtual void LoadVariables(cMaterial* apMaterial, cResourceVarsObject* apVars) = 0;
    virtual void GetVariableValues(cMaterial* apMaterial, cResourceVarsObject* apVars) = 0;

    virtual void CompileMaterialSpecifics(cMaterial* apMaterial) = 0;

    inline bool HasTypeSpecifics(eMaterialRenderMode aMode) const { return mbHasTypeSpecifics[aMode]; }

protected:
    void AddUsedTexture(eMaterialTexture aType);

    void AddVar(const tString& asName, eVariableType aType, const tString& asDefaultValue, const tString& asDesc = "", const tStringVec& avEnumValues = tStringVec());

    void AddVarBool(const tString& asName, bool abDefaultValue, const tString& asDesc = "");
    void AddVarInt(const tString& asName, int alDefaultValue, const tString& asDesc = "");
    void AddVarFloat(const tString& asName, float afDefaultValue, const tString& asDesc = "");
    void AddVarVec2(const tString& asName, const cVector2f& avDefaultValue, const tString& asDesc = "");
    void AddVarVec3(const tString& asName, const cVector3f& avDefaultValue, const tString& asDesc = "");
    void AddVarString(const tString& asName, const tString& asDefaultValue, const tString& asDesc = "");
    void AddVarColor(const tString& asName, const cColor& aDefaultValue, const tString& asDesc = "");
    void AddVarEnum(const tString& asName, const tString& asDefaultValue, const tStringVec& avEnumValues, const tString& asDesc = "");

    cGraphics* mpGraphics;
    cResources* mpResources;

    tString msName;

    bool mbIsTranslucent = false;
    bool mbIsDecal = false;

    bool mbHasTypeSpecifics[eMaterialRenderMode_LastEnum] {};

    std::vector<cMaterialUsedTexture> mvUsedTextures;
    std::vector<cMaterialUserVariable> mvUserVariables;

    cProgramComboManager* mpProgramManager = nullptr;
};

//---------------------------------------------------

}; // namespace hpl
