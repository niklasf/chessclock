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

#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
   public:

        enum Side {
            Left = 0,
            Right = 1,
        };

        Clock(float leftTime, float rightTime) {
            m_times[Left] = leftTime;
            m_times[Right] = rightTime;
            m_flaggedFirst[Left] = false;
            m_flaggedFirst[Right] = false;
            m_activeSide = Left;
        }

        virtual void tick(float delta);

        virtual void hit();

        float getTime(Side side);

        bool flaggedFirst(Side side);

        Side activeSide();

    protected:

        void updateFlag();

        float m_times[2];

        bool m_flaggedFirst[2];

        int m_activeSide;
};

#endif
