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

#ifndef HPL_HPL_H
#define HPL_HPL_H

#include "ai/AI.h"
#include "ai/AINodeContainer.h"
#include "ai/AINodeGenerator.h"
#include "ai/AStar.h"
#include "ai/StateMachine.h"
#include "engine/Engine.h"
#include "engine/EngineInitVars.h"
#include "engine/LowLevelEngineSetup.h"
#include "engine/SaveGame.h"
#include "engine/ScriptFuncs.h"
#include "engine/Updateable.h"
#include "engine/Updater.h"
#include "generate/Generate.h"
#include "generate/GenerateTypes.h"
#include "generate/VoxelMap.h"
#include "graphics/Animation.h"
#include "graphics/AnimationTrack.h"
#include "graphics/Bitmap.h"
#include "graphics/Bone.h"
#include "graphics/BoneState.h"
#include "graphics/DecalCreator.h"
#include "graphics/FontData.h"
#include "graphics/FrameBitmap.h"
#include "graphics/FrameBuffer.h"
#include "graphics/FrameSubImage.h"
#include "graphics/FrameTexture.h"
#include "graphics/GPUProgram.h"
#include "graphics/GPUShader.h"
#include "graphics/Graphics.h"
#include "graphics/LowLevelGraphics.h"
#include "graphics/Material.h"
#include "graphics/MaterialType.h"
#include "graphics/Mesh.h"
#include "graphics/MeshCreator.h"
#include "graphics/OcclusionQuery.h"
#include "graphics/PostEffect.h"
#include "graphics/PostEffectComposite.h"
#include "graphics/PostEffect_Bloom.h"
#include "graphics/PostEffect_ColorConvTex.h"
#include "graphics/PostEffect_ColorGrading.h"
#include "graphics/PostEffect_ImageTrail.h"
#include "graphics/PostEffect_RadialBlur.h"
#include "graphics/RenderList.h"
#include "graphics/RendererDeferred.h"
#include "graphics/RendererSimple.h"
#include "graphics/Skeleton.h"
#include "graphics/SubMesh.h"
#include "graphics/Texture.h"
#include "graphics/TextureCreator.h"
#include "graphics/VertexBuffer.h"
#include "graphics/VideoStream.h"
#include "gui/Gui.h"
#include "gui/GuiGfxElement.h"
#include "gui/GuiMaterial.h"
#include "gui/GuiPopUp.h"
#include "gui/GuiPopUpColorPicker.h"
#include "gui/GuiPopUpFilePicker.h"
#include "gui/GuiPopUpMessageBox.h"
#include "gui/GuiSet.h"
#include "gui/GuiSkin.h"
#include "gui/Widget.h"
#include "gui/WidgetButton.h"
#include "gui/WidgetCheckBox.h"
#include "gui/WidgetComboBox.h"
#include "gui/WidgetContextMenu.h"
#include "gui/WidgetDummy.h"
#include "gui/WidgetFrame.h"
#include "gui/WidgetGroup.h"
#include "gui/WidgetImage.h"
#include "gui/WidgetLabel.h"
#include "gui/WidgetListBox.h"
#include "gui/WidgetMainMenu.h"
#include "gui/WidgetMenuItem.h"
#include "gui/WidgetMultiPropertyListBox.h"
#include "gui/WidgetSlider.h"
#include "gui/WidgetTabFrame.h"
#include "gui/WidgetTextBox.h"
#include "gui/WidgetWindow.h"
#include "haptic/Haptic.h"
#include "haptic/HapticForce.h"
#include "haptic/HapticShape.h"
#include "haptic/HapticSurface.h"
#include "haptic/LowLevelHaptic.h"
#include "input/Action.h"
#include "input/Gamepad.h"
#include "input/Input.h"
#include "input/InputDevice.h"
#include "input/Keyboard.h"
#include "input/LowLevelInput.h"
#include "input/Mouse.h"
#include "math/BoundingVolume.h"
#include "math/CRC.h"
#include "math/Frustum.h"
#include "math/Math.h"
#include "math/MathTypes.h"
#include "math/PidController.h"
#include "math/Spring.h"
#include "physics/CharacterBody.h"
#include "physics/CollideData.h"
#include "physics/CollideShape.h"
#include "physics/LowLevelPhysics.h"
#include "physics/Physics.h"
#include "physics/PhysicsBody.h"
#include "physics/PhysicsController.h"
#include "physics/PhysicsJoint.h"
#include "physics/PhysicsJointBall.h"
#include "physics/PhysicsJointHinge.h"
#include "physics/PhysicsJointScrew.h"
#include "physics/PhysicsJointSlider.h"
#include "physics/PhysicsMaterial.h"
#include "physics/PhysicsRope.h"
#include "physics/PhysicsWorld.h"
#include "physics/SurfaceData.h"
#include "resources/AnimationManager.h"
#include "resources/BinaryBuffer.h"
#include "resources/BitmapLoader.h"
#include "resources/BitmapLoaderHandler.h"
#include "resources/ConfigFile.h"
#include "resources/EngineFileLoading.h"
#include "resources/EntFileManager.h"
#include "resources/EntityLoader_Object.h"
#include "resources/FileSearcher.h"
#include "resources/FontManager.h"
#include "resources/GpuShaderManager.h"
#include "resources/ImageManager.h"
#include "resources/LanguageFile.h"
#include "resources/LowLevelResources.h"
#include "resources/MaterialManager.h"
#include "resources/MeshLoader.h"
#include "resources/MeshLoaderHandler.h"
#include "resources/MeshManager.h"
#include "resources/ParticleManager.h"
#include "resources/Resources.h"
#include "resources/ScriptManager.h"
#include "resources/SoundEntityManager.h"
#include "resources/SoundManager.h"
#include "resources/TextureManager.h"
#include "resources/VideoManager.h"
#include "resources/WorldLoader.h"
#include "resources/WorldLoaderHandler.h"
#include "resources/XmlDocument.h"
#include "scene/AnimationState.h"
#include "scene/Beam.h"
#include "scene/BillBoard.h"
#include "scene/Camera.h"
#include "scene/DummyRenderable.h"
#include "scene/FogArea.h"
#include "scene/LightBox.h"
#include "scene/LightPoint.h"
#include "scene/LightSpot.h"
#include "scene/MeshEntity.h"
#include "scene/NodeState.h"
#include "scene/ParticleEmitter_UserData.h"
#include "scene/ParticleSystem.h"
#include "scene/RenderableContainer.h"
#include "scene/RopeEntity.h"
#include "scene/Scene.h"
#include "scene/SoundEntity.h"
#include "scene/Viewport.h"
#include "scene/World.h"
#include "sound/LowLevelSound.h"
#include "sound/MusicHandler.h"
#include "sound/Sound.h"
#include "sound/SoundChannel.h"
#include "sound/SoundData.h"
#include "sound/SoundEntityData.h"
#include "sound/SoundEnvironment.h"
#include "sound/SoundHandler.h"
#include "system/Container.h"
#include "system/LogicTimer.h"
#include "system/LowLevelSystem.h"
#include "system/Mutex.h"
#include "system/Platform.h"
#include "system/PreprocessParser.h"
#include "system/SHA1.h"
#include "system/Script.h"
#include "system/SerializeClass.h"
#include "system/String.h"
#include "system/System.h"
#include "system/SystemTypes.h"
#include "system/Thread.h"

#endif // HPL_HPL_H
