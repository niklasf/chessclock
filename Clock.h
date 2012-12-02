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
        Clock(float leftTime, float rightTime);
        virtual void tick(float delta);
        virtual void hit();
        float getLeftTime();
        float getRightTime();
        bool getLeftFlaggedFirst();
        bool getRightFlaggedFirst();

    protected:
        float m_leftTime;
        float m_rightTime;
        bool m_leftFlaggedFirst;
        bool m_rightFlaggedFirst;
        bool m_leftActive;
};

#endif
