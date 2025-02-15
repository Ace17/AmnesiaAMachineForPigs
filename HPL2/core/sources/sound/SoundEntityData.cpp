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

#include "sound/SoundEntityData.h"

#include "impl/tinyXML/tinyxml.h"
#include "math/Math.h"
#include "resources/LowLevelResources.h"
#include "resources/Resources.h"
#include "resources/SoundManager.h"
#include "resources/XmlDocument.h"
#include "sound/Sound.h"
#include "sound/SoundChannel.h"
#include "sound/SoundHandler.h"
#include "system/LowLevelSystem.h"
#include "system/String.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cSoundEntityData::cSoundEntityData(const tString& asName, cResources* apResources, cSound* apSound)
    : iResourceBase(asName, _W(""), 0)
{
    mpResources = apResources;
    mpSound = apSound;

    mbFadeStart = false;
    mbFadeStop = false;

    mfAIVolume = 1;
    mfVolume = 1;
    mfMaxDistance = 0;
    mfMinDistance = 0;

    mbStream = false;
    mbLoop = false;
    mbUse3D = true;

    mbKeepPlayingOutOfRange = false;

    mfRandom = 1;
    mfInterval = 0;

    for (int i = 0; i < 3; i++)
    {
        mlPrevious[i] = -1;
    }
}

//-----------------------------------------------------------------------

cSoundEntityData::~cSoundEntityData()
{
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

static tString gsEmptyString = "";

const tString& cSoundEntityData::GetSoundName(eSoundEntityType aType, int alIdx)
{
    if ((int)mvSoundNameVecs[aType].size() <= alIdx)
        return gsEmptyString;

    return mvSoundNameVecs[aType][alIdx];
}

const tString& cSoundEntityData::GetRandomSoundName(eSoundEntityType aType, bool abSkipPrevious)
{
    if (mvSoundNameVecs[aType].empty())
        return gsEmptyString;
    int lSize = (int)mvSoundNameVecs[aType].size();
    if (lSize == 1)
        return mvSoundNameVecs[aType][0];

    int lRand = cMath::RandRectl(0, lSize - 1);
    if (abSkipPrevious && lRand == mlPrevious[aType])
    {
        lRand = (lRand + 1) % lSize;
    }

    mlPrevious[aType] = lRand;

    return mvSoundNameVecs[aType][lRand];
}

//-----------------------------------------------------------------------

int cSoundEntityData::GetSoundNum(eSoundEntityType aType)
{
    return (int)mvSoundNameVecs[aType].size();
}

//-----------------------------------------------------------------------

void cSoundEntityData::SetSoundName(const tString& asName, eSoundEntityType aType, int alIdx)
{
    if ((int)mvSoundNameVecs[aType].size() <= alIdx)
        return;

    mvSoundNameVecs[aType][alIdx] = asName;
}

void cSoundEntityData::AddSoundName(const tString& asName, eSoundEntityType aType)
{
    mvSoundNameVecs[aType].push_back(asName);
}

//-----------------------------------------------------------------------

void cSoundEntityData::PreloadSoundsOfType(eSoundEntityType aType)
{
    for (size_t i = 0; i < mvSoundNameVecs[aType].size(); ++i)
    {
        tString& sName = mvSoundNameVecs[aType][i];

        // No need to remove pointer as this is done when creating a channel!
        mpResources->GetSoundManager()->CreateSoundData(sName, false);
    }
}

void cSoundEntityData::PreloadSounds()
{
    if (mbStream)
        return;

    for (int i = 0; i < 3; ++i)
        PreloadSoundsOfType((eSoundEntityType)i);
}

//-----------------------------------------------------------------------

void cSoundEntityData::LoadSoundsInElement(cXmlElement* apElement, tStringVec* apStringVec)
{
    if (apElement == NULL)
        return;

    cXmlNodeListIterator it = apElement->GetChildIterator();
    while (it.HasNext())
    {
        cXmlElement* pChild = it.Next()->ToElement();

        apStringVec->push_back(pChild->GetAttributeString("File"));
    }
}

bool cSoundEntityData::CreateFromFile(const tWString& asFile)
{
    SetFullPath(asFile);

    iXmlDocument* pDoc = mpResources->GetLowLevel()->CreateXmlDocument();
    if (pDoc->CreateFromFile(asFile.c_str()) == false)
    {
        Error("Couldn't load sound entity data '%s'!\n", cString::To8Char(asFile).c_str());
        hplDelete(pDoc);
        return false;
    }

    ////////////////////////////////////////////////
    // SOUNDS
    cXmlElement* pSoundsElem = pDoc->GetFirstElement("SOUNDS");
    if (pSoundsElem == NULL)
    {
        Error("Couldn't find SOUNDS element in '%s'!\n", asFile.c_str());
        hplDelete(pDoc);
        return false;
    }

    LoadSoundsInElement(pSoundsElem->GetFirstElement("Main"), &mvSoundNameVecs[eSoundEntityType_Main]);
    LoadSoundsInElement(pSoundsElem->GetFirstElement("Start"), &mvSoundNameVecs[eSoundEntityType_Start]);
    LoadSoundsInElement(pSoundsElem->GetFirstElement("Stop"), &mvSoundNameVecs[eSoundEntityType_Stop]);

    ////////////////////////////////////////////////
    // PROPERTIES
    cXmlElement* pPropElem = pDoc->GetFirstElement("PROPERTIES");
    if (pPropElem == NULL)
    {
        Error("Couldn't find PROPERTIES element in '%s'!\n", asFile.c_str());
        hplDelete(pDoc);
        return false;
    }

    mbUse3D = pPropElem->GetAttributeBool("Use3D", true);
    mbLoop = pPropElem->GetAttributeBool("Loop", true);
    mbStream = pPropElem->GetAttributeBool("Stream", true);

    mbBlockable = pPropElem->GetAttributeBool("Blockable", false);
    mfBlockVolumeMul = pPropElem->GetAttributeFloat("BlockVolumeMul", 0.6f);

    mfVolume = pPropElem->GetAttributeFloat("Volume", 1);
    mfMaxDistance = pPropElem->GetAttributeFloat("MaxDistance", 1);
    mfMinDistance = pPropElem->GetAttributeFloat("MinDistance", 1);

    mfAIVolume = pPropElem->GetAttributeFloat("AIVolume", mfVolume);

    mbFadeStart = pPropElem->GetAttributeBool("FadeStart", true);
    mbFadeStop = pPropElem->GetAttributeBool("FadeStop", true);

    mfRandom = pPropElem->GetAttributeFloat("Random", 1);
    mfInterval = pPropElem->GetAttributeFloat("Interval", 0);

    mlPriority = pPropElem->GetAttributeInt("Priority", 0);

    mbKeepPlayingOutOfRange = pPropElem->GetAttributeBool("KeepPlayingOutOfRange", false);

    hplDelete(pDoc);

    return true;
}

//-----------------------------------------------------------------------

} // namespace hpl
