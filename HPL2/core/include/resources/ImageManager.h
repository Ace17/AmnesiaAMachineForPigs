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

#include "math/MathTypes.h"
#include "resources/ResourceManager.h"

namespace hpl
{

class cResources;
class cFrameSubImage;
class cFrameTexture;
class cFrameBitmap;
class iLowLevelGraphics;
class cBitmap;
class cBitmapLoaderHandler;
class iTexture;

typedef std::list<cFrameBitmap*> tFrameBitmapList;
typedef tFrameBitmapList::iterator tFrameBitmapListIt;

typedef std::map<int, cFrameTexture*> tFrameTextureMap;
typedef tFrameTextureMap::iterator tFrameTextureMapIt;

class cImageManager : public iResourceManager
{
    friend class cFrameTexture;

public:
    cImageManager(cResources* mpResources, iLowLevelGraphics* apLowLevelGraphics, iLowLevelSystem* apLowLevelSystem);
    ~cImageManager();

    void Destroy(iResourceBase* apResource);

    void Unload(iResourceBase* apResource);

    // Image specifc
    iResourceBase* CreateInFrame(const tString& asName, int alFrameHandle);
    cFrameSubImage* CreateImage(const tString& asName, int alFrameHandle = -1);
    /**
     * Draws all updated content to textures. THis must be done before a loaded image can be used.
     * Use this as unoften as possible.
     * \return Number of bitmaps flushes
     */
    int FlushAll();
    void ReorganizeAll();

    cFrameSubImage* CreateFromBitmap(const tString& asName, cBitmap* apBmp, int alFrameHandle = -1);

    cFrameTexture* CreateCustomFrame(iTexture* apTexture);

    cFrameTexture* GetFrameTexture(int alHandle);

    int CreateFrame(cVector2l avSize);
    void SetFrameLocked(int alHandle, bool abLocked);

private:
    iLowLevelGraphics* mpLowLevelGraphics;
    cBitmapLoaderHandler* mpBitmapLoaderHandler;

    tFrameBitmapList mlstBitmapFrames;
    tFrameTextureMap m_mapTextureFrames;

    cVector2l mvFrameSize;
    int mlFrameHandle;

    cFrameSubImage* FindImage(const tString& asName, tWString& asFilePath);
    cFrameSubImage* AddToFrame(cBitmap* apBmp, const tWString& asFullPath, int alFrameHandle);
    cFrameBitmap* CreateBitmapFrame(cVector2l avSize);
};

}; // namespace hpl
