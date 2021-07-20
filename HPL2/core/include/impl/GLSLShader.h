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
#include "math/MathTypes.h"
#include "system/SystemTypes.h"
#include <GL/glew.h>

namespace hpl
{
class cGLSLShader : public iGpuShader
{
public:
    cGLSLShader(const tString& asName, eGpuShaderType aType);
    ~cGLSLShader();

    bool Reload();
    void Unload();
    void Destroy();

    bool SamplerNeedsTextureUnitSetup() { return true; }

    tString GetProgramName() { return msName; }

    bool CreateFromFile(const tWString& asFile, const tString& asEntry = "main", bool abPrintInfoIfFail = true);
    bool CreateFromString(const char* apStringData, const tString& asEntry = "main", bool abPrintInfoIfFail = true);

    // GLSL Specific
    GLuint GetHandle() { return mlHandle; }

protected:
    void LogShaderInfoLog();
    void LogShaderCode(const char* apStringData);
    GLenum GetGLShaderType(eGpuShaderType aType);

    GLuint mlHandle;
};
}; // namespace hpl
