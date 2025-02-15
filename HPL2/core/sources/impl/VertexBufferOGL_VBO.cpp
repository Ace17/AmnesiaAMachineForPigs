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

#include "impl/VertexBufferOGL_VBO.h"

#include "graphics/Renderer.h"
#include "impl/LowLevelGraphicsSDL.h"
#include "math/Math.h"
#include "system/LowLevelSystem.h"
#include <GL/glew.h>

#include <memory.h>

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cVertexBufferOGL_VBO::cVertexBufferOGL_VBO(iLowLevelGraphics* apLowLevelGraphics,
      eVertexBufferDrawType aDrawType,
      eVertexBufferUsageType aUsageType,
      int alReserveVtxSize,
      int alReserveIdxSize)
    : iVertexBufferOpenGL(apLowLevelGraphics, eVertexBufferType_Hardware, aDrawType, aUsageType, alReserveVtxSize, alReserveIdxSize)
{
    mlElementHandle = 0;
}

//-----------------------------------------------------------------------

cVertexBufferOGL_VBO::~cVertexBufferOGL_VBO()
{
    for (size_t i = 0; i < mvElementArrays.size(); ++i)
    {
        cVtxBufferGLElementArray* pElement = mvElementArrays[i];

        glDeleteBuffersARB(1, (GLuint*)&pElement->mlGLHandle);
    }

    glDeleteBuffersARB(1, (GLuint*)&mlElementHandle);
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cVertexBufferOGL_VBO::UpdateData(tVertexElementFlag aTypes, bool abIndices)
{
    GLenum usageType = GL_STATIC_DRAW_ARB;
    if (mUsageType == eVertexBufferUsageType_Dynamic)
        usageType = GL_DYNAMIC_DRAW_ARB;
    else if (mUsageType == eVertexBufferUsageType_Stream)
        usageType = GL_STREAM_DRAW_ARB;

    // Create the VBO vertex arrays
    for (size_t i = 0; i < mvElementArrays.size(); ++i)
    {
        cVtxBufferGLElementArray* pElement = mvElementArrays[i];

        if ((aTypes & pElement->mFlag) && pElement->mlGLHandle > 0)
        {
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, pElement->mlGLHandle);

            int lSize = (int)pElement->Size() * GetVertexFormatByteSize(pElement->mFormat);
            glBufferDataARB(GL_ARRAY_BUFFER_ARB, lSize, NULL, usageType);
            glBufferDataARB(GL_ARRAY_BUFFER_ARB, lSize, pElement->GetArrayPtr(), usageType);
        }
    }
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

    // Create the VBO index array
    if (abIndices)
    {
        glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, mlElementHandle);

        // glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB,GetIndexNum()*sizeof(unsigned int),
        //	NULL, usageType);

        glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, GetIndexNum() * sizeof(unsigned int), &mvIndexArray[0], usageType);

        // TODO: Same as with vertex, for stream and dynamic.

        glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);
    }
}

//-----------------------------------------------------------------------

void cVertexBufferOGL_VBO::Draw(eVertexBufferDrawType aDrawType)
{
    eVertexBufferDrawType drawType = aDrawType == eVertexBufferDrawType_LastEnum ? mDrawType : aDrawType;

    ///////////////////////////////
    // Get the draw type
    GLenum mode = GetDrawModeFromDrawType(drawType);

    //////////////////////////////////
    // Bind and draw the buffer
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, mlElementHandle);

    int lSize = mlElementNum;
    if (mlElementNum < 0)
        lSize = GetIndexNum();

    glDrawElements(mode, lSize, GL_UNSIGNED_INT, (char*)NULL);
    // glDrawRangeElements(mode,0,GetVertexNum(),lSize,GL_UNSIGNED_INT, NULL);

    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

    iRenderer::IncDrawCalls();
}

//-----------------------------------------------------------------------

void cVertexBufferOGL_VBO::Bind()
{
    SetVertexStates();
}

//-----------------------------------------------------------------------

void cVertexBufferOGL_VBO::UnBind()
{
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

    for (size_t i = 0; i < mvElementArrays.size(); ++i)
    {
        cVtxBufferGLElementArray* pElement = mvElementArrays[i];

        // Log("Unbinding %d handle %d, type: %d\n",i,pElement->mlGLHandle, pElement->mType);

        int lTextureUnit = GetVertexElementTextureUnit(pElement->mType);
        if (lTextureUnit >= 0)
            glClientActiveTextureARB(GL_TEXTURE0_ARB + lTextureUnit);

        glDisableClientState(GetGLArrayFromVertexElement(pElement->mType));
    }
    glClientActiveTextureARB(GL_TEXTURE0_ARB);
}

//-----------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
/////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cVertexBufferOGL_VBO::CompileSpecific()
{
    GLenum usageType = GL_STATIC_DRAW_ARB;
    if (mUsageType == eVertexBufferUsageType_Dynamic)
        usageType = GL_DYNAMIC_DRAW_ARB;
    else if (mUsageType == eVertexBufferUsageType_Stream)
        usageType = GL_STREAM_DRAW_ARB;

    // Create the VBO vertex arrays
    for (size_t i = 0; i < mvElementArrays.size(); ++i)
    {
        cVtxBufferGLElementArray* pElement = mvElementArrays[i];

        glGenBuffersARB(1, (GLuint*)&pElement->mlGLHandle);
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, pElement->mlGLHandle);

        glBufferDataARB(GL_ARRAY_BUFFER_ARB, pElement->Size() * GetVertexFormatByteSize(pElement->mFormat), pElement->GetArrayPtr(), usageType);

        // Log("Compiling handle %d, type: %d element num: %d\n",pElement->mlGLHandle, pElement->mType, pElement->mlElementNum);

        glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
    }

    // Create the VBO index array
    glGenBuffersARB(1, (GLuint*)&mlElementHandle);
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, mlElementHandle);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, GetIndexNum() * sizeof(unsigned int), &mvIndexArray[0], usageType);
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);
}

//-----------------------------------------------------------------------

iVertexBufferOpenGL* cVertexBufferOGL_VBO::CreateDataCopy(tVertexElementFlag aFlags,
      eVertexBufferDrawType aDrawType,
      eVertexBufferUsageType aUsageType,
      int alReserveVtxSize,
      int alReserveIdxSize)
{
    return hplNew(cVertexBufferOGL_VBO, (mpLowLevelGraphics, aDrawType, aUsageType, alReserveVtxSize, alReserveIdxSize));
}

//-----------------------------------------------------------------------

void cVertexBufferOGL_VBO::SetVertexStates()
{
    ////////////////////////////////////////
    // Set all vertices except position
    bool bHadExtraTextureUnit = false;
    for (size_t i = 0; i < mvElementArrays.size(); ++i)
    {
        cVtxBufferGLElementArray* pElement = mvElementArrays[i];
        if (pElement->mType == eVertexBufferElement_Position)
            continue; // Make sure postion is called last...

        // Log("Binding %d handle %d, type: %d\n",i,pElement->mlGLHandle, pElement->mType);

        GLenum GLType = GetGLTypeFromVertexFormat(pElement->mFormat);
        int lSize = pElement->mlElementNum;

        int lTextureUnit = GetVertexElementTextureUnit(pElement->mType);
        if (lTextureUnit >= 0)
        {
            if (lTextureUnit > 0)
                bHadExtraTextureUnit = true;
            glClientActiveTextureARB(GL_TEXTURE0_ARB + lTextureUnit);
        }

        glEnableClientState(GetGLArrayFromVertexElement(pElement->mType));

        glBindBufferARB(GL_ARRAY_BUFFER_ARB, pElement->mlGLHandle);

        switch (pElement->mType)
        {
        case eVertexBufferElement_Normal:
            // Log(" Normal\n");
            glNormalPointer(GLType, 0, (char*)NULL);
            break;

        case eVertexBufferElement_Color0:
            // Log(" Color\n");
            glColorPointer(lSize, GLType, 0, (char*)NULL);
            break;

        case eVertexBufferElement_Color1:
            // Log(" Color2\n");
            glSecondaryColorPointerEXT(lSize, GLType, 0, (char*)NULL);
            break;

        case eVertexBufferElement_Texture1Tangent:
        case eVertexBufferElement_Texture0:
        case eVertexBufferElement_Texture1:
        case eVertexBufferElement_Texture2:
        case eVertexBufferElement_Texture3:
        case eVertexBufferElement_Texture4:
            // Log(" Texture\n");
            glTexCoordPointer(lSize, GLType, 0, (char*)NULL);
            break;
            // TODO: User types
        }
    }
    if (bHadExtraTextureUnit)
        glClientActiveTextureARB(GL_TEXTURE0_ARB);

    ////////////////////////////////////////
    // Set position vertex, so it is set last.
    for (size_t i = 0; i < mvElementArrays.size(); ++i)
    {
        cVtxBufferGLElementArray* pElement = mvElementArrays[i];
        if (pElement->mType != eVertexBufferElement_Position)
            continue; // Only set position

        // Log("Binding %d handle %d, type: %d\n",i,pElement->mlGLHandle, pElement->mType);

        GLenum GLType = GetGLTypeFromVertexFormat(pElement->mFormat);
        int lSize = pElement->mlElementNum;

        glEnableClientState(GetGLArrayFromVertexElement(pElement->mType));

        glBindBufferARB(GL_ARRAY_BUFFER_ARB, pElement->mlGLHandle);

        glVertexPointer(lSize, GLType, 0, (char*)NULL);
    }

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
}

//-----------------------------------------------------------------------

} // namespace hpl
