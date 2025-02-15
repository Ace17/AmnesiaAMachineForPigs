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

namespace hpl
{

//-----------------------------------------

class cBitmapData
{
public:
    cBitmapData();
    ~cBitmapData();

    void SetData(const unsigned char* apData, int alSize);

    unsigned char* mpData;
    int mlSize;
};

//-----------------------------------------

class cBitmap
{
public:
    cBitmap();
    ~cBitmap();

    inline const cVector3l& GetSize() const { return mvSize; }
    inline int GetWidth() const { return mvSize.x; }
    inline int GetHeight() const { return mvSize.y; }
    inline int GetDepth() const { return mvSize.z; }

    void SetSize(const cVector3l& avSize) { mvSize = avSize; }

    inline ePixelFormat GetPixelFormat() const { return mPixelFormat; }
    inline char GetBytesPerPixel() const { return mlBytesPerPixel; }
    inline int GetNumOfMipMaps() const { return mlNumOfMipMaps; }
    inline int GetNumOfImages() const { return mlNumOfImages; }

    void SetPixelFormat(ePixelFormat aFormat) { mPixelFormat = aFormat; }
    void SetBytesPerPixel(char alBpp) { mlBytesPerPixel = alBpp; }

    cBitmapData* GetData(int alImage, int alMipMapLevel);
    void SetUpData(int alNumOfImages, int alNumOfMipmaps);
    inline bool IsCompressed() const { return mbDataIsCompressed; }
    void SetIsCompressed(bool abX) { mbDataIsCompressed = abX; }

    inline const tWString& GetFileName() const { return msFileName; }
    void SetFileName(const tWString& asFileName) { msFileName = asFileName; }

    void CreateData(const cVector3l& avSize, ePixelFormat aFormat, int alImage, int alMipMap);

    void Clear(const cColor& aColor, int alImage, int alMipMap);

    void Blit(cBitmap* apSrc,
          const cVector3l& avDestPosition,
          const cVector3l& avSrcSize,
          const cVector3l& avSrcPosition,
          int alDestImage = 0,
          int alDestMipMap = 0,
          int alSrcImage = 0,
          int alSrcMipMap = 0);

    void SetPixel(int alImage, int alMipMapLevel, const cVector3l& avPixelPos, unsigned char* apPixelData);
    void GetPixel(int alImage, int alMipMapLevel, const cVector3l& avPixelPos, unsigned char* apDestPixelData);

private:
    void CopyPixel(unsigned char* apDest, ePixelFormat aDestFormat, unsigned char* apSrc, ePixelFormat aSrcFormat);
    unsigned char* ConvertDataToFormat(unsigned char* apPixelData, ePixelFormat aSrcFormat, ePixelFormat aDestFormat);
    unsigned char* ConvertDataToRGBA(unsigned char* apPixelData, ePixelFormat aFormat);

    std::vector<cBitmapData> mvImages;
    bool mbDataIsCompressed;

    tWString msFileName;

    cVector3l mvSize;
    ePixelFormat mPixelFormat;

    char mlBytesPerPixel;

    int mlNumOfImages;
    int mlNumOfMipMaps;
};
}; // namespace hpl
