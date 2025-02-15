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

#include "scene/Light.h"

namespace hpl
{

class cResources;
class iTexture;
class cFrustum;

//------------------------------------------

class cLightSpot : public iLight
{
#ifdef __GNUC__
    typedef iLight __super;
#endif
public:
    cLightSpot(tString asName, cResources* apResources);
    ~cLightSpot();

    const cMatrixf& GetViewMatrix();
    const cMatrixf& GetProjectionMatrix();
    const cMatrixf& GetViewProjMatrix();

    void SetFOV(float afAngle);
    inline float GetFOV() const { return mfFOV; }

    inline float GetTanHalfFOV() const { return mfTanHalfFOV; }
    inline float GetCosHalfFOV() const { return mfCosHalfFOV; }

    void SetAspect(float afAngle)
    {
        mfAspect = afAngle;
        mbProjectionUpdated = true;
    }
    float GetAspect() { return mfAspect; }

    void SetNearClipPlane(float afX)
    {
        mfNearClipPlane = afX;
        mbProjectionUpdated = true;
    }
    float GetNearClipPlane() { return mfNearClipPlane; }

    void SetRadius(float afX);

    cFrustum* GetFrustum();

    iTexture* GetSpotFalloffMap();
    void SetSpotFalloffMap(iTexture* apTexture);

    bool CollidesWithBV(cBoundingVolume* apBV);
    bool CollidesWithFrustum(cFrustum* apFrustum);

private:
    void ExtraXMLProperties(TiXmlElement* apMainElem);
    void UpdateBoundingVolume();

    cMatrixf m_mtxProjection;
    cMatrixf m_mtxViewProj;
    cMatrixf m_mtxView;

    cFrustum* mpFrustum;

    iTexture* mpSpotFalloffMap;

    float mfFOV;
    float mfAspect;
    float mfNearClipPlane;

    bool mbFovUpdated;
    float mfTanHalfFOV;
    float mfCosHalfFOV;

    bool mbProjectionUpdated;
    bool mbViewProjUpdated;
    bool mbFrustumUpdated;

    int mlViewProjMatrixCount;
    int mlViewMatrixCount;
    int mlFrustumMatrixCount;
};

}; // namespace hpl
