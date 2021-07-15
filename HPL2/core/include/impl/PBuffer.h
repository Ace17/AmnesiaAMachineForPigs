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

#ifndef HPL_P_BUFFER_H
#define HPL_P_BUFFER_H

#include <GL/glew.h>
#ifdef WIN32
#include <GL/wglew.h>
#endif
#include "graphics/GraphicsTypes.h"

#include <vector>
namespace hpl
{
class iLowLevelGraphics;

class cPBuffer
{
public:
    cPBuffer(iLowLevelGraphics* apLowLevelGraphics, bool abShareObjects, bool abUseMipMaps = false, bool abUseDepth = true, bool abUseStencil = true);
    ~cPBuffer();

    bool Init(unsigned int alWidth, unsigned int alHeight, cColor aCol);

    int MakeCurrentContext();

    void Bind();
    void UnBind();

private:
#ifdef WIN32
    HDC mDeviceContext;
    HGLRC mGLContext;
    HPBUFFERARB mPBuffer;
#elif defined(__linux__)
    Display* gDpy;
    GLXContext glCtx;
    GLXPbuffer gPBuffer;
#endif

    int mlWidth;
    int mlHeight;

    bool mbShareObjects;
    iLowLevelGraphics* mpLowLevelGraphics;

    std::vector<int> mvAttribBuffer;
    std::vector<int> mvAttribFormat;
};

}; // namespace hpl
#endif // HPL_P_BUFFER_H
