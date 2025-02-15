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

#include "engine/EngineTypes.h"
#include "engine/Updateable.h"
#include "resources/MeshLoader.h"
#include "scene/Camera.h"
#include "system/SystemTypes.h"

#include <list>

namespace hpl
{

class cAI;
class cGraphics;
class cResources;
class cSystem;
class cSound;
class cPhysics;
class cHaptic;
class cGui;

class cCamera;
class cFrustum;
class cWorld;
class cViewport;

//--------------------------------------------------------------------

#define tSceneRenderFlag_World 0x00000001
#define tSceneRenderFlag_Gui 0x00000002
#define tSceneRenderFlag_PostEffects 0x00000004
#define tSceneRenderFlag_All 0xFFFFFFFF

//--------------------------------------------------------------------

class cScene : public iUpdateable
{
public:
    cScene(cGraphics* apGraphics, cResources* apResources, cSound* apSound, cPhysics* apPhysics, cSystem* apSystem, cAI* apAI, cGui* apGui, cHaptic* apHaptic);
    ~cScene();

    void Reset();

    /**
     * Called by cEngine
     */
    void Render(float afFrameTime, tFlag alFlags);

    void PostUpdate(float afTimeStep);

    ///// VIEW PORT METHODS ////////////////////

    cViewport* CreateViewport(cCamera* apCamera = NULL, cWorld* apWorld = NULL, bool abPushFront = false);
    void DestroyViewport(cViewport* apViewPort);
    bool ViewportExists(cViewport* apViewPort);

    void SetCurrentListener(cViewport* apViewPort);

    ///// CAMERA METHODS ////////////////////

    cCamera* CreateCamera(eCameraMoveMode aMoveMode);
    void DestroyCamera(cCamera* apCam);

    ///// WORLD METHODS ////////////////////

    cWorld* LoadWorld(const tString& asFile, tWorldLoadFlag aFlags);
    cWorld* CreateWorld(const tString& asName);
    void DestroyWorld(cWorld* apWorld);
    bool WorldExists(cWorld* apWorld);

private:
    void Render3DGui(cViewport* apViewPort, cFrustum* apFrustum, float afTimeStep);
    void RenderPrePostEffectScreenGui(cViewport* apViewPort, float afTimeStep);
    void RenderScreenGui(cViewport* apViewPort, float afTimeStep);

    cGraphics* mpGraphics;
    cResources* mpResources;
    cSound* mpSound;
    cPhysics* mpPhysics;
    cSystem* mpSystem;
    cAI* mpAI;
    cGui* mpGui;
    cHaptic* mpHaptic;

    cViewport* mpCurrentListener;

    std::list<cViewport*> mlstViewports;
    std::list<cWorld*> mlstWorlds;
    std::list<cCamera*> mlstCameras;
};

}; // namespace hpl
