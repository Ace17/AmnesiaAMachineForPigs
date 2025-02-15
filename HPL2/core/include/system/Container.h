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

#include "system/MemoryManager.h"

#include <list>
#include <map>
#include <vector>

namespace hpl
{

//---------------------------------

class iContainerIterator
{
    friend class cSerializeClass;

public:
    virtual ~iContainerIterator() {}

protected:
    virtual bool HasNext() = 0;

    virtual void* NextPtr() = 0;
};

//---------------------------------

class iContainer
{
    friend class cSerializeClass;

public:
    virtual size_t Size() = 0;
    virtual void Clear() = 0;
    ~iContainer() {}

protected:
    virtual void AddVoidPtr(void** apPtr) = 0;
    virtual void AddVoidClass(void* apClass) = 0;

    virtual iContainerIterator* CreateIteratorPtr() = 0;
};

//---------------------------------

class iContainerKeyPair
{
public:
    virtual ~iContainerKeyPair() {}

    virtual size_t Size() = 0;

    virtual void AddVoidPtr(void* apKey, void** apClass) = 0;
    virtual void AddVoidClass(void* apKey, void* apClass) = 0;
};

//---------------------------------

template<class T>
class cContainerVecIterator : public iContainerIterator
{
    void* NextPtr() { return &Next(); }

public:
    cContainerVecIterator(std::vector<T>* apVec)
    {
        mpVec = apVec;
        if (apVec->empty())
            mIt = apVec->end();
        else
            mIt = apVec->begin();
    }
    ~cContainerVecIterator() {}

    bool HasNext() { return mIt != mpVec->end(); }

    T& Next()
    {
        T& val = *mIt;
        mIt++;
        return val;
    }

    T& PeekNext() { return *mIt; }

    void Erase()
    {
        if (mIt != mpVec->end())
            mIt = mpVec->erase(mIt);
    }

private:
    std::vector<T>* mpVec;
    typename std::vector<T>::iterator mIt;
};

////////////////////////////

template<class T>
class cContainerVec : public iContainer
{
private:
    void AddVoidPtr(void** apPtr) { mvVector.push_back(*((T*)apPtr)); }
    void AddVoidClass(void* apClass) { mvVector.push_back(*((T*)apClass)); }
    iContainerIterator* CreateIteratorPtr() { return hplNew(cContainerVecIterator<T>, (&mvVector)); }

public:
    cContainerVec() {}
    ~cContainerVec() {}

    //////////////////////
    size_t Size() { return mvVector.size(); }

    void Clear() { mvVector.clear(); }

    //////////////////////

    void Reserve(size_t alSize) { mvVector.reserve(alSize); }

    void Resize(size_t alSize) { mvVector.resize(alSize); }

    void Add(T aVal) { mvVector.push_back(aVal); }

    //////////////////////

    cContainerVecIterator<T> GetIterator() { return cContainerVecIterator<T>(&mvVector); }

    //////////////////////

    T& operator[](size_t alX) { return mvVector[alX]; }

    //////////////////////

    std::vector<T> mvVector;
};

//---------------------------------

template<class T>
class cContainerListIterator : public iContainerIterator
{
    void* NextPtr() { return &Next(); }

public:
    cContainerListIterator(std::list<T>* apVec)
    {
        mpVec = apVec;
        if (apVec->empty())
            mIt = apVec->end();
        else
            mIt = apVec->begin();
    }

    ~cContainerListIterator() {}

    bool HasNext() { return mIt != mpVec->end(); }

    T& Next()
    {
        T& val = *mIt;
        mIt++;
        return val;
    }

    T& PeekNext() { return *mIt; }

    void Erase()
    {
        if (mIt != mpVec->end())
            mIt = mpVec->erase(mIt);
    }

private:
    std::list<T>* mpVec;
    typename std::list<T>::iterator mIt;
};

////////////////////////////

template<class T>
class cContainerList : public iContainer
{
private:
    void AddVoidPtr(void** apPtr) { mvVector.push_back(*((T*)apPtr)); }
    void AddVoidClass(void* apClass) { mvVector.push_back(*((T*)apClass)); }
    iContainerIterator* CreateIteratorPtr() { return hplNew(cContainerListIterator<T>, (&mvVector)); }

public:
    cContainerList() {}

    //////////////////////
    size_t Size() { return mvVector.size(); }

    void Clear() { mvVector.clear(); }
    //////////////////////

    void Add(T aVal) { mvVector.push_back(aVal); }

    //////////////////////

    cContainerListIterator<T> GetIterator() { return cContainerListIterator<T>(&mvVector); }

    //////////////////////

    std::list<T> mvVector;
};

//---------------------------------

}; // namespace hpl
