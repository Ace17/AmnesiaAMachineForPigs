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

    void SetInt(int alVarId, int alX);
    void SetFloat(int alVarId, float afX);
    void SetVec2f(int alVarId, float afX, float afY);
    void SetVec3f(int alVarId, float afX, float afY, float afZ);
    void SetVec4f(int alVarId, float afX, float afY, float afZ, float afW);

    void SetMatrixf(int alVarId, const cMatrixf& aMtx);

private:
    void LogProgramInfoLog();

    GLuint mlHandle;
    static int mlCurrentProgram;

    struct cGLSLParam
    {
        GLint mlId = -1;
        tString msName;
    };

    std::vector<cGLSLParam> mvParameters;
};
}; // namespace hpl
