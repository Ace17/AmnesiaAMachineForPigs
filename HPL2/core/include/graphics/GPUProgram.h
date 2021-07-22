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

class iGpuShader;
class cResources;

//---------------------------------------------------

class iGpuProgram
{
public:
    iGpuProgram(const tString& asName, eGpuProgramFormat aProgramFormat);
    virtual ~iGpuProgram();

    const tString& GetName() { return msName; }

    void SetShader(eGpuShaderType aType, iGpuShader* apShader);
    iGpuShader* GetShader(eGpuShaderType aType) { return mpShader[aType]; }

    void SetAutoDestroyShaders(bool abX) { mbAutoDestroyShaders = abX; }
    bool GetAutoDestroyShaders() { return mbAutoDestroyShaders; }

    void SetResources(cResources* apResources) { mpResources = apResources; }

    virtual bool Link() = 0;

    virtual void Bind() = 0;
    virtual void UnBind() = 0;

    virtual int GetVariableId(const tString& asName) = 0;
    virtual bool GetVariableAsId(const tString& asName, int alId) = 0;

    virtual void SetInt(int alVarId, int alX) = 0;
    virtual void SetFloat(int alVarId, float afX) = 0;
    virtual void SetVec2f(int alVarId, float afX, float afY) = 0;
    virtual void SetVec3f(int alVarId, float afX, float afY, float afZ) = 0;
    virtual void SetVec4f(int alVarId, float afX, float afY, float afZ, float afW) = 0;
    virtual void SetMatrixf(int alVarId, const cMatrixf& mMtx) = 0;

    void SetVec2f(int alVarId, const cVector2f avVec) { SetVec2f(alVarId, avVec.x, avVec.y); }
    void SetVec3f(int alVarId, const cVector3f& avVec) { SetVec3f(alVarId, avVec.x, avVec.y, avVec.z); }
    void SetColor3f(int alVarId, const cColor& aCol) { SetVec3f(alVarId, aCol.r, aCol.g, aCol.b); }
    void SetColor4f(int alVarId, const cColor& aCol) { SetVec4f(alVarId, aCol.r, aCol.g, aCol.b, aCol.a); }

    eGpuProgramFormat GetFormat() { return mProgramFormat; }

    void SetUserId(unsigned int alX) { mlUserId = alX; }
    unsigned int GetUserId() { return mlUserId; }

protected:
    tString msName;
    cResources* mpResources;
    unsigned int mlUserId;

    eGpuProgramFormat mProgramFormat;

    iGpuShader* mpShader[2];

    bool mbAutoDestroyShaders;
};

//---------------------------------------------------

}; // namespace hpl
