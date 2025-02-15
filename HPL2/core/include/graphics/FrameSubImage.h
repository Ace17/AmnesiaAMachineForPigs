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
#include "resources/ResourceBase.h"

#include <vector>

namespace hpl
{

class cFrameTexture;
class cFrameBitmap;
class iTexture;
class cFBitmapImage;

//----------------------------------------------------

class cFrameSubImage : public iResourceBase
{
    friend class cFBitmapImage;
    friend class cFrameBitmap;
    friend class cImageManager;

public:
    cFrameSubImage(const tString& asName,
          const tWString& asFullPath,
          cFrameTexture* apFrameTex,
          cFrameBitmap* apFrameBmp,
          cRect2l aRect,
          cVector2l avSrcSize,
          int alHandle,
          cFBitmapImage* apFrameBitmapImage);
    ~cFrameSubImage();

    bool Reload();
    void Unload();
    void Destroy();

    // Image specific
    int GetHeight() const { return mRect.h; }
    int GetWidth() const { return mRect.w; }
    cVector2l GetSize() const { return cVector2l(mRect.w, mRect.h); }
    cVector2l GetPosition() const { return cVector2l(mRect.x, mRect.y); }

    int GetSourceWidth() const { return mvSourceSize.x; }
    int GetSourceHeight() const { return mvSourceSize.y; }

    iTexture* GetTexture() const;

    cFrameTexture* GetFrameTexture() const { return mpFrameTexture; }
    cFrameBitmap* GetFrameBitmap() const { return mpFrameBitmap; }

    tVertexVec GetVertexVecCopy(const cVector2f& avPos, const cVector2f& avSize);
    const tVertexVec& GetVertexVec() { return mvVtx; }

    int GetUpdateCount() { return mlUpdateCount; }

    void Flush();

    void SetNeedUpdateUvs();

private:
    void UpdateUvs();

    cFrameTexture* mpFrameTexture;
    cFrameBitmap* mpFrameBitmap;
    cFBitmapImage* mpFrameBitmapImage;

    cVector2l mvSourceSize;
    cRect2l mRect;
    tVertexVec mvVtx;

    int mlHandle;

    bool mbNeedUvUpdate;
    int mlUpdateCount;
};

typedef std::vector<cFrameSubImage*> tResourceImageVec;
typedef tResourceImageVec::iterator tResourceImageVecIt;

}; // namespace hpl

