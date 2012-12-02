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

MainWindow::MainWindow()
{
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setSpacing(1);

    m_leftWidget = new QLCDNumber();
    m_leftWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    hbox->addWidget(m_leftWidget);

    m_rightWidget = new QLCDNumber();
    m_rightWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    hbox->addWidget(m_rightWidget);

    m_clock = new FisherClock(10, 10, 5, 5);

    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(tick()));
    m_timer->start((int)(m_delta * 1000));

    QWidget *centralWidget = new QWidget();
    centralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    centralWidget->setLayout(hbox);

    this->setWindowTitle("Chess Clock");
    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete m_clock;
}

void MainWindow::tick()
{
    m_clock->tick(m_delta);
    m_leftWidget->display("55");
    m_rightWidget->display("777");
}
