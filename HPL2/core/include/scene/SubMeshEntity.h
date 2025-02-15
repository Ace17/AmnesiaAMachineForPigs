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
#include "graphics/Renderable.h"
#include "math/MathTypes.h"
#include "math/MeshTypes.h"
#include "scene/Entity3D.h"
#include "system/SystemTypes.h"

#include <map>
#include <vector>

namespace hpl
{

class cMaterialManager;
class cSubMesh;
class cMeshEntity;
class cNode3D;
class cMaterial;

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------

class cSubMeshEntityBodyUpdate : public iEntityCallback
{
public:
    void OnTransformUpdate(iEntity3D* apEntity);
};

//-----------------------------------------------------------------------

class cSubMeshEntity : public iRenderable
{
#ifdef __GNUC__
    typedef iRenderable __super;
#endif
    friend class cMeshEntity;

public:
    cSubMeshEntity(const tString& asName, cMeshEntity* apMeshEntity, cSubMesh* apSubMesh, cMaterialManager* apMaterialManager);
    ~cSubMeshEntity();

    cMaterial* GetMaterial();

    bool UpdateGraphicsForViewport(cFrustum* apFrustum, float afFrameTime);
    void UpdateGraphicsForFrame(float afFrameTime);

    iVertexBuffer* GetVertexBuffer();

    cBoundingVolume* GetBoundingVolume();
    cBoundingVolume* GetSubMeshBoundingVolume();

    cMatrixf* GetModelMatrix(cFrustum* apFrustum);

    int GetMatrixUpdateCount();

    eRenderableType GetRenderType() { return eRenderableType_SubMesh; }

    cSubMesh* GetSubMesh() const { return mpSubMesh; }

    void SetLocalNode(cNode3D* apNode);
    cNode3D* GetLocalNode();

    void* GetUserData() { return mpUserData; }
    void SetUserData(void* apData) { mpUserData = apData; }

    void SetIsOccluder(bool abX) { mbIsOccluder = abX; }
    bool IsOccluder() { return mbIsOccluder; }

    // Entity implementation
    tString GetEntityType() { return "SubMesh"; }

    void UpdateLogic(float afTimeStep);

    cTriangleData& GetTriangle(int alIndex);
    int GetTriangleNum();
    tTriangleDataVec* GetTriangleVecPtr();

    void SetUpdateBody(bool abX);
    bool GetUpdateBody();

    void SetCustomMaterial(cMaterial* apMaterial, bool abDestroyOldCustom = true);
    cMaterial* GetCustomMaterial() { return mpMaterial; }

private:
    void OnTransformUpdated();

    cSubMesh* mpSubMesh;
    cMeshEntity* mpMeshEntity;

    cMaterial* mpMaterial;

    cNode3D* mpLocalNode;

    cMaterialManager* mpMaterialManager;

    iVertexBuffer* mpDynVtxBuffer;
    tTriangleDataVec mvDynTriangles;

    cSubMeshEntityBodyUpdate* mpEntityCallback;
    bool mbUpdateBody;

    bool mbIsOccluder;
    bool mbGraphicsUpdated;
    int mlBoneMatricesUpdateCount;
    float mfDistanceToFrustum;

    char mlStaticNullMatrixCount;
    void* mpUserData;
};

typedef std::vector<cSubMeshEntity*> tSubMeshEntityVec;
typedef std::vector<cSubMeshEntity*>::iterator tSubMeshEntityVecIt;

typedef std::multimap<tString, cSubMeshEntity*> tSubMeshEntityMap;
typedef tSubMeshEntityMap::iterator tSubMeshEntityMapIt;

}; // namespace hpl
