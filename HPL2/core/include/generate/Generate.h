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

#include "generate/GenerateTypes.h"
#include "graphics/GraphicsTypes.h"
#include "math/MathTypes.h"
#include "system/SystemTypes.h"

namespace hpl
{

//-------------------------------------

class cGraphics;
class cResources;

class cVoxelMap;

//-------------------------------------

class cGenerate
{
public:
    cGenerate();
    ~cGenerate();

    void Init(cResources* apResources, cGraphics* apGraphics);

    cVoxelMap* CreateVoxelMap(const cVector3l& avSize);
    void DestroyVoxelMap(cVoxelMap* apMap);

private:
    cResources* mpResources;
    cGraphics* mpGraphics;
};

}; // namespace hpl
