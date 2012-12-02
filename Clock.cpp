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

#include "Clock.h"

void Clock::tick(float delta)
{
    if (m_leftActive) {
        m_leftTime -= delta;
    } else {
        m_rightTime -= delta;
    }
    updateFlag();
}

void Clock::updateFlag()
{
    if (m_leftTime <= 0.0f && !m_rightFlaggedFirst) {
        m_leftFlaggedFirst = true;
    } else if (m_rightTime < 0.0f && !m_leftFlaggedFirst) {
        m_rightFlaggedFirst = true;
    }
}

void Clock::hit()
{
    m_leftActive = !m_leftActive;
}

float Clock::getLeftTime()
{
    return m_leftTime;
}

float Clock::getRightTime()
{
    return m_rightTime;
}

bool Clock::getLeftFlaggedFirst()
{
    return m_leftFlaggedFirst;
}

bool Clock::getRightFlaggedFirst()
{
    return m_rightFlaggedFirst;
}
