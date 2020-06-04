#ifndef ROUND_H
#define ROUND_H

#include <QtWidgets>

class Round : public QWidget
{
public:
    Round();

    //Return true if the round is already started. In this case, new players can't connect to the server anymore
    bool isStarted();

public slots:
    void startRound();

private:
    bool m_roundStarted;
};

#endif // ROUND_H
