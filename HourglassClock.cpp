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

#include "HourglassClock.h"

void HourglassClock::tick(float delta)
{
    if (m_activeSide == Left) {
        m_times[Left] -= delta;
        m_times[Right] += delta;
    } else {
        m_times[Right] -= delta;
        m_times[Left] += delta;
    }
    updateFlag();
}
