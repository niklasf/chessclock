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

#include "BronsteinClock.h"

void BronsteinClock::hit()
{
    m_currentThinkingTimes[Left] = m_thinkingTimes[Left];
    m_currentThinkingTimes[Right] = m_thinkingTimes[Right];
    Clock::hit();
}

void BronsteinClock::tick(float delta)
{
    if (m_currentThinkingTimes[m_activeSide] > 0.0f) {
        m_currentThinkingTimes[m_activeSide] -= delta;
        if (m_currentThinkingTimes[m_activeSide] < 0.0f) {
            m_times[m_activeSide] += m_currentThinkingTimes[m_activeSide];
        }
    } else {
        m_times[m_activeSide] -= delta;
    }

   updateFlag();
}
