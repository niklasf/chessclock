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

#include "FisherClock.h"

void FisherClock::hit()
{
    if (m_leftActive) {
        m_leftTime += m_leftIncrement;
    } else {
        m_rightTime += m_rightIncrement;
    }
    Clock::hit();
}

float FisherClock::getLeftIncrement()
{
    return m_leftIncrement;
}

float FisherClock::getRightIncrement()
{
    return m_rightIncrement;
}
