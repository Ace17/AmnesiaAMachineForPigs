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

#include "graphics/GPUProgram.h"
#include "graphics/GPUShader.h"
#include "math/MathTypes.h"
#include "system/SystemTypes.h"
#include <GL/glew.h>

namespace hpl
{

//-----------------------------------------------------

class cGLSLParam
{
public:
    cGLSLParam()
        : mlId(-1)
        , msName("")
    {
    }
    cGLSLParam(GLint alId, const tString& asName)
        : mlId(alId)
        , msName(asName)
    {
    }

    tString msName;
    GLint mlId;
};

//-----------------------------------------------------

class cGLSLProgram : public iGpuProgram
{
public:
    cGLSLProgram(const tString& asName);
    ~cGLSLProgram();

    bool Link();

    void Bind();
    void UnBind();

    int GetVariableId(const tString& asName);
    bool GetVariableAsId(const tString& asName, int alId);

    bool SetInt(int alVarId, int alX);
    bool SetFloat(int alVarId, float afX);
    bool SetVec2f(int alVarId, float afX, float afY);
    bool SetVec3f(int alVarId, float afX, float afY, float afZ);
    bool SetVec4f(int alVarId, float afX, float afY, float afZ, float afW);

    bool SetMatrixf(int alVarId, const cMatrixf& aMtx);

private:
    void LogProgramInfoLog();

    GLuint mlHandle;
    static int mlCurrentProgram;

    std::vector<cGLSLParam> mvParameters;
};
}; // namespace hpl
