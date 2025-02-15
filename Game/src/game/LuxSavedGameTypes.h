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

#ifndef LUX_SAVED_GAME_TYPES_H
#define LUX_SAVED_GAME_TYPES_H

//----------------------------------------------

#include "LuxBase.h"
#include "LuxSavedEngineTypes.h"
#include "LuxSavedMap.h"

//----------------------------------------------

class cLuxPlayer;
class cLuxPlayerHands;
class cLuxInventory;
class cLuxInventory_Item;
class cLuxMap;
class iLuxPlayerState_SaveData;
class cLuxMusicHandler;
class cLuxGlobalDataHandler;
class cLuxHintHandler;
class cLuxSavedGameMapCollection;
class cLuxSanityHandler;
class cLuxLoadScreenHandler;

//----------------------------------------------

class cLuxLoadScreenHandler_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxLoadScreenHandler_SaveData) public : void FromLoadScreenHandler(cLuxLoadScreenHandler* apData);
    void ToLoadScreenHandler(cLuxMap* apMap, cLuxLoadScreenHandler* apData);

    tString msLoadTextCat;
    tString msLoadTextEntry;
    tString msLoadTextImage;
    int mlTextRandomNum;
    int mlPrevTextNumBitFlags;
};

class cLuxPreloadedSound_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxPreloadedSound_SaveData) public : tString msName;
};

class cLuxSoundManager_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxSoundManager_SaveData) public : void FromSoundManager(cSoundManager* apData);
    void ToSoundManager(cSoundManager* apData);

    cContainerList<cLuxPreloadedSound_SaveData> mlstPreloadedSounds;
};

//----------------------------------------------

// class cLuxInsanityHandler_Event_SaveData : public iSerializable
//{
//	kSerializableClassInit(cLuxInsanityHandler_Event_SaveData)
// public:
//	bool mbUsed;
//};
//
////----------------------------------------------
//
// class cLuxInsanityHandler_Set_SaveData : public iSerializable
//{
//	kSerializableClassInit(cLuxInsanityHandler_Set_SaveData)
// public:
//	cLuxInsanityHandler_Set_SaveData(){}
//	cLuxInsanityHandler_Set_SaveData(const tString& asName) : msName(asName){}
//
//	tString msName;
//};
//
////----------------------------------------------
//
// class cLuxInsanityHandler_SaveData : public iSerializable
//{
//   kSerializableClassInit(cLuxInsanityHandler_SaveData)
// public:
//	void FromInsanityHandler(cLuxInsanityHandler *apData);
//	void ToInsanityHandler(cLuxMap *apMap, cLuxInsanityHandler *apData);
//
//	float mfNewEventCount;
//	cContainerVec<cLuxInsanityHandler_Event_SaveData> mvEvents;
//	cContainerVec<cLuxInsanityHandler_Set_SaveData> mvDisabledSets;
//};

//----------------------------------------------

class cLuxHintHandler_Hint_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxHintHandler_Hint_SaveData) public : tString msName;
};

class cLuxHintHandler_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxHintHandler_SaveData) public : void FromHintHandler(cLuxHintHandler* apData);
    void ToHintHandler(cLuxMap* apMap, cLuxHintHandler* apData);

    cContainerList<cLuxHintHandler_Hint_SaveData> mlstHintsGiven;
    cContainerList<cLuxHintHandler_Hint_SaveData> mlstHintsBlocked;
};

//----------------------------------------------

class cLuxGlobalDataHandler_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxGlobalDataHandler_SaveData) public : void FromGlobalDataHandler(cLuxGlobalDataHandler* apData);
    void ToGlobalDataHandler(cLuxMap* apMap, cLuxGlobalDataHandler* apData);

    cContainerList<cLuxScriptVar> mlstVars;
};

//----------------------------------------------

class cLuxEffectHandler_SoundMul_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxEffectHandler_SoundMul_SaveData) public : void FromEntry(cMultipleSettingsHandler::cGSEntry* apEntry);
    void ToEntry(int alIdx, cMultipleSettingsHandler* apHandler);

    bool mbActive;
    float mfVal;
    float mfDest;
    float mfSpeed;
    tFlag mTypes;
    bool mbDestroyAtDest;
};

class cLuxEffectHandler_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxEffectHandler_SaveData) public : void FromEffectHandler(cLuxEffectHandler* apEffects);
    void ToEffectHandler(cLuxMap* apMap, cLuxEffectHandler* apEffects);

    bool mbFade_Active;
    float mfFade_GoalAlpha;
    float mfFade_Alpha;
    float mfFade_FadeSpeed;

    bool mbImageTrail_Active;
    float mfImageTrail_Amount;
    float mfImageTrail_AmountGoal;
    float mfImageTrail_FadeSpeed;

    bool mbSepiaColor_Active;
    float mfSepiaColor_Amount;
    float mfSepiaColor_AmountGoal;
    float mfSepiaColor_FadeSpeed;

    bool mbRadialBlur_Active;
    float mfRadialBlur_Size;
    float mfRadialBlur_BlurStartDist;
    float mfRadialBlur_SizeGoal;
    float mfRadialBlur_FadeSpeed;

    tString msVoiceOverCallback;
    cContainerVec<cLuxVoiceData> mvVoiceData;
    cContainerVec<cTextQueueEntry> mvTextQueue;
    bool mbVoiceActive;
    float mfVoice_ElapsedTime;
    tString msVoice_Name;
    float mfVoice_MinDistance;
    float mfVoice_MaxDistance;
    cVector3f mvVoice_Position;
    bool mbVoice_3D;
    tString msEffect_Name;

    cContainerVec<cLuxEffectHandler_SoundMul_SaveData> mvGlobalSoundVolumeMul;
    cContainerVec<cLuxEffectHandler_SoundMul_SaveData> mvGlobalSoundSpeedMul;
};

//----------------------------------------------

class cLuxMusicHandler_Music_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxMusicHandler_Music_SaveData) public : tString msFile;
    float mfVolume;
    bool mbLoop;
    bool mbResume;
    bool mbSpecialEffect;
};

class cLuxMusicHandler_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxMusicHandler_SaveData) public : void FromMusicHandler(cLuxMusicHandler* apMusic);
    void ToMusicHandler(cLuxMap* apMap, cLuxMusicHandler* apMusic);

    tString msCurrentMusic;
    float mfCurrentMusicVolume;
    float mfCurrentMusicVolumeAdd;
    float mfCurrentMusicMaxVolume;
    float mfCurrentMusicTime;
    bool mbCurrentMusicLoop;

    int mlCurrentMaxPrio;
    bool mbEnemyClosePlaying;
    bool mbAttackPlaying;
    bool mbSearchPlaying;

    cContainerVec<cLuxMusicHandler_Music_SaveData> mvMusic;
    cContainerVec<int> mvAttackerIDs;
    cContainerVec<int> mvSearcherIDs;
};

//----------------------------------------------

class cLuxJournal_DiaryCont_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxJournal_DiaryCont_SaveData) public : tString msType;
    cContainerVec<cLuxDiary> mvDiaries;
};

//----------------------------------------------

class cLuxJournal_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxJournal_SaveData) public : cLuxJournal_SaveData();
    ~cLuxJournal_SaveData();

    void FromJournal(cLuxJournal* apJournal);
    void ToJournal(cLuxMap* apMap, cLuxJournal* apJournal);

    int mlLastReadTextCat;
    int mlLastReadTextEntry;
    int mlLastReadTextType;
    int mlLastReadHint;
    int mlLastReadDocument;

    cContainerVec<cLuxNote> mvNotes;
    cContainerVec<cLuxHint> mvHints;
    cContainerVec<cLuxJournal_DiaryCont_SaveData> mvDiaryConts;
    cContainerVec<cLuxQuestNote> mvQuestNotes;
};

//----------------------------------------------

class cLuxInventory_Item_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxInventory_Item_SaveData) public : void FromItem(cLuxInventory_Item* apItem);

    tString msName;
    int mlType;
    tString msSubType;
    tString msVal;
    tString msExtraVal;

    tString msImageFile;

    float mfAmount;
    int mlCount;
    tString msGameNameEntry;
    tString msGameDescEntry;
};

//----------------------------------------------

class cLuxInventory_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxInventory_SaveData) public : cLuxInventory_SaveData();
    ~cLuxInventory_SaveData();

    void FromInventory(cLuxInventory* apInventory);
    void ToInventory(cLuxMap* apMap, cLuxInventory* apInventory);

    bool mbDisabled;

    int mlEquippedHandItem;

    cContainerVec<cLuxInventory_Item_SaveData> mvItems;
    cContainerVec<cLuxCombineItemsCallback> mvCombineCallbacks;
};

//----------------------------------------------

class cLuxPlayerHands_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxPlayerHands_SaveData) public : void FromPlayerHands(cLuxPlayerHands* apPlayerHands);
    void ToPlayerHands(cLuxMap* apMap, cLuxPlayerHands* apPlayerHands);

    int mlState;
    tString msCurrentHandObject;
    tString msCurrentAnim;
    cEngineMeshEntity_SaveData mMesh;

    float mfHandObjectChargeCount;
    int mlHandObjectState;
    bool mbHandObjectAttackDown;
    bool mbHandObjectInteractDown;
    float mfHandObjectAlpha;
};

//----------------------------------------------

class cLuxFlashbackData_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxFlashbackData_SaveData) public : tString msFile;
    tString msCallback;

    cLuxFlashbackData_SaveData(){};
    ~cLuxFlashbackData_SaveData(){};
};

class cLuxPlayer_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxPlayer_SaveData) public : cLuxPlayer_SaveData();
    ~cLuxPlayer_SaveData();

    void FromPlayer(cLuxPlayer* apPlayer);
    void ToPlayer(cLuxMap* apMap, cLuxPlayer* apPlayer);

    int mlState;
    iLuxPlayerState_SaveData* mpStateData;

    bool mbActive;

    float mfHealth;
    float mfTerror;
    float mfInfection;
    int mlCoins;
    int mlTinderboxes;

    bool mbIsInWater;
    tString msWaterStepSound;
    float mfWaterSpeedMul;

    bool mbCrouching;

    bool mbJumpDisabled;
    bool mbCrouchDisabled;

    bool mbUsesDragFootsteps;

    float mfInteractionMoveSpeedMul;
    float mfEventMoveSpeedMul;
    float mfEventRunSpeedMul;
    float mfScriptMoveSpeedMul;
    float mfScriptRunSpeedMul;
    float mfHurtMoveSpeedMul;
    float mfInfectionCollapseSpeedMul;
    float mfStaminaSpeedMul;

    float mfLookSpeedMul;

    float mfAspectMul;
    float mfFOVMul;
    float mfAspectMulGoal;
    float mfFOVMulGoal;
    float mfAspectMulSpeed;
    float mfFOVMulSpeed;

    float mfRoll;
    float mfRollGoal;
    float mfRollSpeedMul;
    float mfRollMaxSpeed;

    bool mbFadingPitch;
    float mfPitchGoal;
    float mfPitchSpeedMul;
    float mfPitchMaxSpeed;

    cVector3f mvCamAnimPos;
    cVector3f mvCamAnimPosGoal;
    float mfCamAnimPosSpeedMul;
    float mfCamAnimPosMaxSpeed;

    cVector2f mvHeadSpinSpeed;

    bool mbScriptShowFocusIconAndCrossHair;

    bool mbNoFallDamage;

    bool mbLanternOn;
    bool mbLanternDisabled;
    bool mbLanternFlickering;
    float mfLanternFlickeringSpeed;

    tString msDeathHintCat;
    tString msDeathHintEntry;

    bool mbRandomEscapeFail;
    int mlRandomEscapeFailCount;

    bool mbSpawnPSActive;
    tString mbSpawnPSFile;

    bool mbFlashbackActive;
    float mfFlashbackStartCount;
    float mfFlashDelay;
    tString msFlashbackFile;
    tString msFlashbackCallback;
    cContainerList<cLuxFlashbackData_SaveData> mlstFlashbackQueue;

    bool mbInfectionCollapse_Active;
    int mlInfectionCollapse_State;
    float mfInfectionCollapse_HeightAdd;
    float mfInfectionCollapse_Roll;
    float mfInfectionCollapse_Timer;

    float mfSanity_TimeAtHighInfection;

    bool mbLookAt_Active;
    cVector3f mvLookAt_TargetPos;
    cVector3f mvLookAt_CurrentSpeed;
    float mfLookAt_SpeedMul;
    float mfLookAt_MaxSpeed;
    tString msLookAt_AtTargetCallback;
    float mfLookAt_DestFovMul;
    float mfLookAt_Fov;
    float mfLookAt_FovSpeed;
    float mfLookAt_FovMaxSpeed;

    cVector3f mvCameraAngles;
    cEngineCharacterBody_SaveData mCharBody;

    float mfPitchMaxLimit;
    float mfPitchMinLimit;
    float mfYawMaxLimit;
    float mfYawMinLimit;

    bool mbVoiceFlashback_IsDelaying;
    bool mbVoiceFlashback_IsPlaying;
    bool mbVoiceFlashback_UseEffects;
    bool mbVoiceFlashback_ObstructMovement;

    float mfVoiceFlashback_EffectFadeInTime;
    float mfVoiceFlashback_EffectFadeOutTime;
    float mfVoiceFlashback_SepiaAmount;
    float mfVoiceFlashback_LightFadeAmount;
    float mfVoiceFlashback_ImageTrailAmount;
    float mfVoiceFlashback_BlurStartDistance;
    float mfVoiceFlashback_BlurAmount;
    float mfVoiceFlashback_FovMultiplier;
    float mfVoiceFlashback_MoveSpeedMultiplier;
    float mfVoiceFlashback_MouseSensitivityModifier;

    tString msVoiceFlashback_StopSound;

    cContainerVec<cLuxHeadPosAdd> mvHeadPosAdds;

    cContainerVec<int> mvTerrorEnemyIDs;

    cLuxPlayerHands_SaveData mPlayerHands;
    cContainerList<cLuxCollideCallback_SaveData> mlstCollideCallbacks;
};

//----------------------------------------------

class cLuxSaveGame_SaveData : public iSerializable
{
    kSerializableClassInit(cLuxSaveGame_SaveData) public : cLuxSaveGame_SaveData();

    tString msMapFolder;
    cLuxSavedMap mMap;

    cLuxInventory_SaveData mInventory;
    cLuxJournal_SaveData mJournal;
    cLuxPlayer_SaveData mPlayer;
    cLuxMusicHandler_SaveData mMusicHandler;
    cLuxEffectHandler_SaveData mEffectHandler;
    cLuxGlobalDataHandler_SaveData mGlobalDataHandler;
    cLuxHintHandler_SaveData mHintHandler;
    // cLuxInsanityHandler_SaveData mInsanityHandler;
    cLuxLoadScreenHandler_SaveData mLoadScreenHandler;
    cLuxSoundManager_SaveData mSoundManager;

    cLuxSavedGameMapCollection* mpSavedMaps;
};

//----------------------------------------------

#endif // #ifndef LUX_SAVED_GAME_TYPES_H
