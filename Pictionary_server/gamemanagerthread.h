#ifndef GAMEMANAGERTHREAD_H
#define GAMEMANAGERTHREAD_H

#include <QThread>

class GameManagerThread : public QThread
{

    Q_OBJECT

public:
    GameManagerThread();

    virtual void run() override;

signals:
    void nextPlayerDrawing();

    void timeToSend(int time);

private slots:
    void receiveNbPlayers(int nbPlayers);

private:

    unsigned long long m_nbRounds;
    int m_nbPlayers;
};

#endif // GAMEMANAGERTHREAD_H
