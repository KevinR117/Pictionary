#include "timer.h"

Timer::Timer()
{
    m_timerLayout = new QGridLayout();

    m_timeRemaining = new QLineEdit(tr("80"));
    m_timeRemaining->setAlignment(Qt::AlignHCenter);
    m_timeRemaining->setReadOnly(true);

    m_timerLayout->addWidget(m_timeRemaining, 0, 0);
}

QGridLayout* Timer::getTimerLayout() const
{
    return this->m_timerLayout;
}

QLineEdit* Timer::setTimeRemaining(QString time)
{
    this->m_timeRemaining->setText(time);
    return this->m_timeRemaining;
}
