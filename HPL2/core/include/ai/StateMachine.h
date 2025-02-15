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
#include "system/SystemTypes.h"

#include <map>

namespace hpl
{

//-----------------------------------------
class cStateMachine;

class iAIState
{
    friend class cStateMachine;

public:
    iAIState();
    virtual ~iAIState() {}

    virtual void OnUpdate(float afTime) = 0;

    virtual void OnEnterState(int alLastState) = 0;
    virtual void OnLeaveState(int alNextState) = 0;

    int GetId() { return mlId; }
    const tString& GetName() { return msName; }
    float GetUpdateStep() { return mfUpdateStep; }

    void Sleep(float afTime);

protected:
    int mlId;
    tString msName;
    float mfUpdateStep;
    cStateMachine* mpStateMachine;

private:
    void Update(float afTime);
    void SetStateMachine(cStateMachine* apStateMachine) { mpStateMachine = apStateMachine; }

    float mfTimeCount;
};

typedef std::map<int, iAIState*> tAIStateMap;
typedef tAIStateMap::iterator tAIStateMapIt;

//-----------------------------------------

class cStateMachine
{
public:
    cStateMachine();
    virtual ~cStateMachine();

    void Update(float afTime);

    /**
     * Adds a new state to the state machine. The state machine will destroy them when deleted.
     */
    void AddState(iAIState* apState, const tString& asName, int alId, float afUpdateStep);

    void ChangeState(int alId);

    void SetActive(bool abX) { mbActive = abX; }
    bool IsActive() { return mbActive; }

    iAIState* GetState(int alId);

    iAIState* CurrentState();

private:
    bool mbActive;

    tAIStateMap m_mapStates;

    iAIState* mpCurrentState;
};

}; // namespace hpl
