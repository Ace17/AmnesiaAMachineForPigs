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

#include "input/InputDevice.h"
#include "input/InputTypes.h"
#include "math/MathTypes.h"

namespace hpl
{

class iMouse : public iInputDevice
{
public:
    iMouse(tString asName);
    virtual ~iMouse() {}

    /**
     * Check if a mouse button is down
     * \param eMouseButton the button to check
     * \return
     */
    virtual bool ButtonIsDown(eMouseButton) = 0;
    /**
     * Get the absolute pos of the mouse.
     * \return
     */
    virtual cVector2l GetAbsPosition() = 0;
    /**
     * Get the relative movement.
     * \return
     */
    virtual cVector2l GetRelPosition() = 0;
    /**
     * \param eMouseButton The button to change to string.
     * \return The name of the button as a string.
     */
    virtual tString ButtonToString(eMouseButton);
    /**
     * \param tString Name of the button
     * \return enum of the button.
     */
    virtual eMouseButton StringToButton(const tString&);
};

}; // namespace hpl

