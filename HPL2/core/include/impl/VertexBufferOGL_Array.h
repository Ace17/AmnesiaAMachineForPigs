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

#include "impl/VertexBufferOpenGL.h"

namespace hpl
{

class cVertexBufferOGL_Array : public iVertexBufferOpenGL
{
public:
    cVertexBufferOGL_Array(iLowLevelGraphics* apLowLevelGraphics, eVertexBufferDrawType aDrawType, eVertexBufferUsageType aUsageType, int alReserveVtxSize, int alReserveIdxSize);
    ~cVertexBufferOGL_Array();

    void UpdateData(tVertexElementFlag aTypes, bool abIndices);

    void Draw(eVertexBufferDrawType aDrawType);

    void Bind();
    void UnBind();

private:
    void CompileSpecific();
    iVertexBufferOpenGL* CreateDataCopy(tVertexElementFlag aFlags, eVertexBufferDrawType aDrawType, eVertexBufferUsageType aUsageType, int alReserveVtxSize, int alReserveIdxSize);

    void SetVertexStates();
};

}; // namespace hpl
