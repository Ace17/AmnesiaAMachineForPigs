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

#include "graphics/GPUProgram.h"

#include "resources/GpuShaderManager.h"
#include "resources/Resources.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

iGpuProgram::iGpuProgram(const tString& asName, eGpuProgramFormat aProgramFormat)
{
    msName = asName;

    mpResources = NULL;

    mProgramFormat = aProgramFormat;

    mbAutoDestroyShaders = true;

    for (int i = 0; i < 2; ++i)
        mpShader[i] = NULL;

    mlUserId = 0;
}

iGpuProgram::~iGpuProgram()
{
    if (mbAutoDestroyShaders && mpResources)
    {
        for (int i = 0; i < 2; ++i)
        {
            if (mpShader[i])
                mpResources->GetGpuShaderManager()->Destroy(mpShader[i]);
        }
    }
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void iGpuProgram::SetShader(eGpuShaderType aType, iGpuShader* apShader)
{
    mpShader[aType] = apShader;
}

//-----------------------------------------------------------------------

} // namespace hpl
