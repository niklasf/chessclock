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
    m_currentLeftThinkingTime = m_leftThinkingTime;
    m_currentRightThinkingTime = m_rightThinkingTime;
    Clock::hit();
}

void BronsteinClock::tick(float delta)
{
    if (m_leftActive) {
        if (m_currentLeftThinkingTime > 0.0f) {
            m_currentLeftThinkingTime -= delta;
            if (m_currentLeftThinkingTime < 0.0f) {
                m_leftTime += m_currentLeftThinkingTime;
            }
        } else {
            m_leftTime -= delta;
        }
    } else {
        if (m_currentRightThinkingTime > 0.0f) {
            m_currentRightThinkingTime -= delta;
            if (m_currentRightThinkingTime < 0.0f) {
                m_rightTime += m_currentRightThinkingTime;
            }
        } else {
            m_rightTime -= delta;
        }
   }
}

float BronsteinClock::getLeftThinkingTime()
{
    return m_leftThinkingTime;
}

float BronsteinClock::getRightThinkingTime()
{
    return m_rightThinkingTime;
}
