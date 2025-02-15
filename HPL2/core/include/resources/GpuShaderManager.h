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

#include "graphics/GPUShader.h"
#include "resources/ResourceManager.h"

namespace hpl
{

//------------------------------------

class iLowLevelGraphics;
class cParserVarContainer;
class cPreprocessParser;

//------------------------------------

class cGpuShaderManager : public iResourceManager
{
public:
    cGpuShaderManager(cFileSearcher* apFileSearcher, iLowLevelGraphics* apLowLevelGraphics, iLowLevelResources* apLowLevelResources, iLowLevelSystem* apLowLevelSystem);
    ~cGpuShaderManager();

    void CheckFeatureSupport();

    /**
     * Creates a new GPU program
     * \param asName name of the program
     * \param asEntry the entry point of the program (usually "main")
     * \param aType type of the program
     * \return
     */
    iGpuShader* CreateShader(const tString& asName, eGpuShaderType aType, cParserVarContainer* apVarContainer);

    void Destroy(iResourceBase* apResource);
    void Unload(iResourceBase* apResource);

private:
    bool IsShaderSupported(const tString& asName, eGpuShaderType aType);

    iLowLevelGraphics* mpLowLevelGraphics;
    cPreprocessParser* mpPreprocessParser;
};

}; // namespace hpl
