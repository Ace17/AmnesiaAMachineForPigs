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

class iOcclusionQuery
{
public:
    virtual ~iOcclusionQuery() {}

    /**
     * Starts the query. Must be followed by an End().
     */
    virtual void Begin() = 0;
    /**
     * Ends the current query. Must have been started with a Begin()
     */
    virtual void End() = 0;

    /**
     * Fetches the result of he query. Should not be done until all is rendered.
     */
    virtual bool FetchResults() = 0;

    /**
     * Get the number of samples that passed stencil and depth test in the query begin/end.
     */
    virtual unsigned int GetSampleCount() = 0;
};

}; // namespace hpl
