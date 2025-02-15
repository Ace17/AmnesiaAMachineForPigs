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

#include "resources/ResourceBase.h"

#ifdef __GNUC__
#if defined __ppc__ || defined(__LP64__)
#define __stdcall
#else
#define __stdcall __attribute__((stdcall))
#endif
#endif

namespace hpl
{

class iScript : public iResourceBase
{
public:
    iScript(const tString& asName, const tWString& asFullPath)
        : iResourceBase(asName, asFullPath, 0)
    {
    }
    virtual ~iScript() {}

    bool Reload() { return false; }
    void Unload() {}
    void Destroy() {}

    virtual bool CreateFromFile(const tWString& asFile, tString* apCompileMessages = NULL) = 0;

    virtual void AddArg(const tString& asArg) = 0;

    /**
     * Runs a func in the script, for example "test(15)"
     * \param asFuncLine the line of code
     * \return true if everything was ok, else false
     */
    virtual bool Run(const tString& asFuncLine) = 0;

    // virtual bool Run(int alHandle)=0;
};
}; // namespace hpl
