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

#include "MainWindow.h"
#include "FisherClock.h"
#include <stdlib.h>
#include <QColorGroup>
#include <phonon/mediaobject.h>
#include <phonon/audiooutput.h>
#include <phonon/backendcapabilities.h>

MainWindow::MainWindow()
{
    m_audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    m_soundPlayer = new Phonon::MediaObject(this);
    m_hitLeftSound = new Phonon::MediaSource("./hit-left.wav");
    m_hitRightSound = new Phonon::MediaSource("./hit-right.wav");
    Phonon::createPath(m_soundPlayer, m_audioOutput);

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setSpacing(1);

    m_leftWidget = new QLCDNumber(10);
    m_leftWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    hbox->addWidget(m_leftWidget);

    m_rightWidget = new QLCDNumber(10);
    m_rightWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    hbox->addWidget(m_rightWidget);

    m_clock = new FisherClock(10, 12, 4, 5);

    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(tick()));
    m_timer->start((int)(m_delta * 1000));

    QWidget *centralWidget = new QWidget();
    centralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    centralWidget->setLayout(hbox);

    this->setWindowTitle("Chess Clock");
    this->setCentralWidget(centralWidget);
    this->resize(400, 100);
}

MainWindow::~MainWindow()
{
    delete m_clock;
}

QString MainWindow::formatTime(float time)
{
    QString result;

    if (time < 0.0f) {
        result.append('-');
    }

    float absTime = fabs(time);

    int hours = (int)(absTime / (60.0f * 60.0f));
    if (hours) {
        result.append(QString::number(hours));
        result.append(':');
    }

    int minutes = (int)(absTime / 60.0f - hours * 60.0f);
    if (minutes < 10) {
        result.append('0');
    }
    result.append(QString::number(minutes));
    result.append(':');

    int seconds = ((int)absTime) % 60;
    if (seconds < 10) {
        result.append('0');
    }
    result.append(QString::number(seconds));

    if (absTime < 10.0f) {
        float remainder = absTime - seconds - 60.0f * minutes - 60.0f * 60.0f * hours;
        int mills = (int)(remainder * 1000);
        result.append(':');
        if (mills < 100) {
            result.append('0');
        }
        if (mills < 10) {
            result.append('0');
        }
        result.append(QString::number(mills));
    }

    return result;
}

void MainWindow::tick()
{
    m_clock->tick(m_delta);

    QPalette defaultPalette;

    QPalette leftPalette = m_leftWidget->palette();
    if (m_clock->getLeftFlaggedFirst()) {
        leftPalette.setColor(QPalette::Foreground, Qt::red);
    } else {
        leftPalette.setColor(QPalette::Foreground, defaultPalette.color(QPalette::Foreground));
    }
    m_leftWidget->setPalette(leftPalette);
    m_leftWidget->display(formatTime(m_clock->getLeftTime()));

    QPalette rightPalette = m_rightWidget->palette();
    if (m_clock->getRightFlaggedFirst()) {
        rightPalette.setColor(QPalette::Foreground, Qt::red);
    }
    else {
        rightPalette.setColor(QPalette::Foreground, defaultPalette.color(QPalette::Foreground));
    }
    m_rightWidget->setPalette(rightPalette);
    m_rightWidget->display(formatTime(m_clock->getRightTime()));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    hit();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    hit();
}

void MainWindow::hit()
{
    m_soundPlayer->clear();
    m_soundPlayer->setCurrentSource(*m_hitLeftSound);
    m_soundPlayer->play();
    m_clock->hit();
}
