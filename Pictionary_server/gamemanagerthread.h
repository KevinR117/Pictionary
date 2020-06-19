#ifndef GAMEMANAGERTHREAD_H
#define GAMEMANAGERTHREAD_H

#include <QThread>

class GameManagerThread : public QThread
{

    Q_OBJECT

public:
    GameManagerThread();

    virtual void run() override;

    QString getTimeRemaining() const;

signals:
    void nextPlayerDrawing();

    void timeToSend(int time);

    void roundEnd();

    void drawingSessionEnd();

private slots:
    void receiveNbPlayers(int nbPlayers);

    void finishSessionNow();

private:

    unsigned long long m_nbRounds;
    int m_nbPlayers;
    int m_timeRemaining;
    bool m_sessionStillAlive;
};

#endif // GAMEMANAGERTHREAD_H
