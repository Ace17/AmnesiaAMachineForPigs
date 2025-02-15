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
class iGpuShader;
class cParserVarContainer;

//---------------------------------------------------

#define kPC_VertexBit eFlagBit_0
#define kPC_FragmentBit eFlagBit_1

//---------------------------------------------------

struct cProgramComboVariable
{
    tString msVarName;
    int mlId;
};

typedef std::list<cProgramComboVariable> tProgramComboVariableList;
typedef tProgramComboVariableList::iterator tProgramComboVariableListIt;

//---------------------------------------------------

class cProgramComboShader;

typedef std::map<unsigned int, cProgramComboShader*> tProgramComboShaderMap;
typedef tProgramComboShaderMap::iterator tProgramComboShaderMapIt;

//---------------------------------------------------

class cProgramComboProgram;

typedef std::map<unsigned int, cProgramComboProgram*> tProgramComboProgramMap;
typedef tProgramComboProgramMap::iterator tProgramComboProgramMapIt;

//---------------------------------------------------

struct cProgramComboSettingsVar
{
    tString msName;
    tString msValue;
};

//---------------------------------------------------

class cProgramComboSettings
{
public:
    tString msName;

    tString msVtxShader;
    tString msFragShader;

    std::vector<cProgramComboFeature> mvFeatures;
    std::vector<cProgramComboSettingsVar> mvDefaultVars;
};

//---------------------------------------------------

class cProgramComboManager
{
public:
    cProgramComboManager(const tString& asName, cGraphics* apGraphics, cResources* apResources, int alNumOfMainModes);
    ~cProgramComboManager();

    void SetName(const tString& asName) { msName = asName; }

    iGpuProgram* GenerateProgram(int alMainMode, int alFlags);

    void SetupGenerateProgramData(int alMainMode,
          const tString& asModeName,
          const tString& asVtxShaderName,
          const tString& asFragShaderName,
          const cProgramComboFeature* apFeatures,
          int alFeatureNum,
          cParserVarContainer& avDefaultVars);

    void AddUniform(int alMainMode, const tString& asVarName, int alId);

    void DestroyGeneratedProgram(int alMainMode, iGpuProgram* apProgram);
    void DestroyGeneratedShader(int alMainMode, iGpuShader* apShader, eGpuShaderType aType);

    iGpuShader* CreateShader(const tString& asName, eGpuShaderType aType, cParserVarContainer* apVars, bool abAddtoList);
    iGpuProgram* CreateProgram(const tString& asName, bool abAddtoList);

    /**
     * Do NOT use these to destroy program create with SetupProgramModeData
     */
    void DestroyShader(iGpuShader* apShader);
    void DestroyProgram(iGpuProgram* apProgram);

    iGpuProgram* CreateProgramFromShaders(const tString& asProgramName,
          const tString& asVtxShaderName,
          const tString& asFragShaderName,
          cParserVarContainer* apVars,
          bool abAddtoList);
    iGpuProgram* CreateProgramFromShaders(const tString& asProgramName, iGpuShader* apVtxShader, iGpuShader* apFragShader, bool abAddtoList);

    void DestroyShadersAndPrograms();

private:
    tString GenerateProgramName(int alMainMode, int alBitFlags);

    iGpuShader* GetShaderForCombo(int alMainMode, int alBitFlags, const tString& asShaderName, tFlag aShaderType);
    iGpuShader* CreateShaderFromFeatures(const tString& asShaderFile,
          tFlag aShaderType,
          int alBitFlags,
          cProgramComboFeature* apFeatures,
          int alFeatureNum,
          cProgramComboSettingsVar* apDefaultVars,
          int alDefaultVarsNum);

    /*void CreateValidShaderCombos(	const tString& asFile, tFlag aShaderType, iGpuShader **apShaderVec,
                                                                    cProgramComboFeature *apFeatures, int alCombinations, int alFeatureNum,
                                                                    cParserVarContainer &avDefaultVars);
    void CreateProgramCombos(	int alMode,
                                                            cProgramComboProgram *apProgramDataVec,
                                                            iGpuShader **apVtxShaderVec,iGpuShader **apFragShaderVec,
                                                            cProgramComboFeature *apFeatures, int alCombinations, int alFeatureNum);
    iGpuShader* GetShaderWithCombo(	iGpuShader **apShaderVec, tFlag aShaderType, int alBitFlag,
                                                                    cProgramComboFeature *apFeatures, int alFeatureNum);*/

    cGraphics* mpGraphics;
    cResources* mpResources;

    tString msName;

    std::vector<tProgramComboVariableList> mvVarLists;
    std::vector<cProgramComboSettings> mvSettings;

    const int mlNumOfMainModes;

    std::vector<tProgramComboProgramMap> mvProgramSets;
    std::vector<tProgramComboShaderMap> mvVtxShaderSets;
    std::vector<tProgramComboShaderMap> mvFragShaderSets;

    tGpuShaderList mlstExtraShaders;
    tGpuProgramList mlstExtraPrograms;
};

//---------------------------------------------------

}; // namespace hpl
