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
    m_times[m_activeSide] -= delta;
    updateFlag();
}

void Clock::updateFlag()
{
    if (m_times[Left] <= 0.0f && !m_flaggedFirst[Right]) {
        m_flaggedFirst[Left] = true;
    } else if (m_times[Right] < 0.0f && !m_flaggedFirst[Left]) {
        m_flaggedFirst[Right] = true;
    }
}

void Clock::hit()
{
    if (m_activeSide == Left) {
        m_activeSide = Right;
    } else {
        m_activeSide = Left;
    }
}

float Clock::getTime(Side side)
{
    return m_times[side];
}

bool Clock::flaggedFirst(Side side)
{
    return m_flaggedFirst[side];
}

Clock::Side Clock::activeSide()
{
    return (Clock::Side)m_activeSide;
}
