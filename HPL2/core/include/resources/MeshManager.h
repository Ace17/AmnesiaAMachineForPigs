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
#include "resources/ResourceManager.h"
#include "resources/ResourcesTypes.h"

namespace hpl
{

class cGraphics;
class cResources;
class cMesh;
class iVertexBuffer;

class cMeshManager : public iResourceManager
{
public:
    cMeshManager(cGraphics* apGraphics, cResources* apResources);
    ~cMeshManager();

    cMesh* CreateMesh(const tString& asName, tMeshLoadFlag aFlag = 0);

    /**
     * Loads only the vertex buffer from the first submesh. Vertexbuffer must be deleted!
     */
    iVertexBuffer* CreateVertexBufferFromMesh(const tString& asName, tVertexElementFlag alVtxToCopy);

    void Destroy(iResourceBase* apResource);
    void Unload(iResourceBase* apResource);

    void SetFastloadMaterial(const tString& asFile) { msFastloadMaterial = asFile; }
    void SetUseFastloadMaterial(bool abX) { mbUseFastloadMaterial = abX; }
    const tString& GetFastloadMaterial() { return msFastloadMaterial; }
    bool GetUseFastloadMaterial() { return mbUseFastloadMaterial; }

private:
    cGraphics* mpGraphics;
    cResources* mpResources;

    tString msFastloadMaterial;
    bool mbUseFastloadMaterial;
};

}; // namespace hpl
