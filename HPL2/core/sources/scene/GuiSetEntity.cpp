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

#include "scene/GuiSetEntity.h"

#include "gui/Gui.h"
#include "gui/GuiSet.h"

namespace hpl
{

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

cGuiSetEntity::cGuiSetEntity(const tString asName, cGuiSet* apSet)
    : iRenderable(asName)
{
    mpGuiSet = apSet;

    mBoundingVolume.SetSize(apSet->Get3DSize());
}

//-----------------------------------------------------------------------

cGuiSetEntity::~cGuiSetEntity()
{
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

void cGuiSetEntity::SetGuiSet(cGuiSet* apSet)
{
    mpGuiSet = apSet;
    mBoundingVolume.SetSize(apSet->Get3DSize());
}

//-----------------------------------------------------------------------

cMatrixf* cGuiSetEntity::GetModelMatrix(cFrustum* apFrustum)
{
    m_mtxTemp = GetWorldMatrix();
    return &m_mtxTemp;
}

//-----------------------------------------------------------------------

int cGuiSetEntity::GetMatrixUpdateCount()
{
    return GetTransformUpdateCount();
}

//-----------------------------------------------------------------------

} // namespace hpl
