#ifndef TIMER_H
#define TIMER_H

#include <QtWidgets>

class Timer : public QWidget
{

    Q_OBJECT

public:
    Timer();

    //Returns the timer Layout
    QGridLayout* getTimerLayout() const;

    //Set the time remaining to the given value
    QLineEdit* setTimeRemaining(QString time);

private:
    QGridLayout *m_timerLayout;
    QLineEdit *m_timeRemaining;
};

#endif // TIMER_H
