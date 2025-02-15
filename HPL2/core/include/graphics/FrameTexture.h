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

#include "graphics/FrameBase.h"

namespace hpl
{

class iTexture;
class cFrameSubImage;
class cImageManager;

class cFrameTexture : public iFrameBase
{
public:
    cFrameTexture(iTexture* pTex, int alHandle, cImageManager* apImageManager, bool abIsCustom);
    ~cFrameTexture();

    iTexture* GetTexture();
    int GetHandle() { return mlHandle; }

    inline bool IsCustom() { return mbIsCustom; }

    /**
     * Creates a subimage in frame at pos and with size messured in pixel. Only works on custom frames!
     */
    cFrameSubImage* CreateCustomImage(const cVector2l& avPixelPos, const cVector2l& avPixelSize);

private:
    iTexture* mpTexture;
    int mlHandle;

    bool mbIsCustom;

    cImageManager* mpImageManager;
};

}; // namespace hpl
