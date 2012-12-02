/*
 * This file is part of Chessclock.
 *
 * Chessclock is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Chessclock is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Chessclock. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FISHERCLOCK_H
#define FISHERCLOCK_H

#include "Clock.h"

class FisherClock : public Clock
{
    public:
        FisherClock(float leftTime, float rightTime, float leftIncrement, float rightIncrement) : Clock(leftTime, rightTime) {
            m_leftIncrement = leftIncrement;
            m_rightIncrement = rightIncrement;
        }

        virtual void hit();
        float getLeftIncrement();
        float getRightIncrement();

    protected:
        float m_leftIncrement;
        float m_rightIncrement;
};

#endif
