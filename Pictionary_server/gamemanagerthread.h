#ifndef GAMEMANAGERTHREAD_H
#define GAMEMANAGERTHREAD_H

#include <QThread>

#include "round.h"

class GameManagerThread : public QThread
{

    Q_OBJECT

public:
    GameManagerThread();

    virtual void run() override;

signals:
    void nextPlayerDrawing();

private slots:
    void receiveNbPlayers(int nbPlayers);

private:

    Round *m_round;
    unsigned long long m_nbRounds;
    int m_nbPlayers;
};

#endif // GAMEMANAGERTHREAD_H
