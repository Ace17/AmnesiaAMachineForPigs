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

namespace hpl
{

enum eThreadPrio
{
    eThreadPrio_Low,
    eThreadPrio_Normal,
    eThreadPrio_High,

    eThreadPrio_LastEnum,
};

class iThreadClass
{
public:
    virtual ~iThreadClass() {}
    virtual void UpdateThread() = 0;
};

class iThread
{
public:
    iThread();
    virtual ~iThread() {}

    void SetThreadClass(iThreadClass* apThreadClass) { mpThreadClass = apThreadClass; }
    void SetUpdateRate(float afUpdateRate);
    void SetSleepTime(unsigned int alSleepTime) { mlSleepTime = alSleepTime; }

    bool IsActive() { return mbThreadActive; }

    unsigned long GetSleepTime() { return mlSleepTime; }

    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Sleep(unsigned int alSleepTime) = 0;

    virtual void SetPriority(eThreadPrio aPrio) = 0;
    eThreadPrio GetPriority() { return mPrio; }

protected:
    static int MainThreadFunc(void* apThread);
    virtual int TranslateEnginePrio(eThreadPrio aPrio) = 0;

    unsigned long mlSleepTime;
    bool mbThreadActive;

private:
    iThreadClass* mpThreadClass;
    eThreadPrio mPrio;
};
}; // namespace hpl
