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

#include "gui/GuiTypes.h"

#include <map>

namespace hpl
{

class cGui;
class cGuiGfxElement;
class iFontData;
class iGuiMaterial;

//-------------------------------------

class cGuiSkinFont
{
public:
    cGuiSkinFont(cGui* apGui);
    ~cGuiSkinFont();

    iFontData* mpFont;
    cVector2f mvSize;
    cColor mColor;
    iGuiMaterial* mpMaterial;

private:
    cGui* mpGui;
};

//-------------------------------------

class cGuiSkin
{
public:
    cGuiSkin(const tString& asName, cGui* apGui);
    ~cGuiSkin();

    const tString& GetName() { return msName; }

    bool LoadFromFile(const tWString& asFile);

    cGuiGfxElement* GetGfx(eGuiSkinGfx aType);
    cGuiSkinFont* GetFont(eGuiSkinFont aType);
    const cVector3f& GetAttribute(eGuiSkinAttribute aType);

private:
    tString msName;
    cGui* mpGui;

    std::vector<cGuiGfxElement*> mvGfxElements;
    std::vector<cGuiSkinFont*> mvFonts;
    std::vector<cVector3f> mvAttributes;
};

}; // namespace hpl
