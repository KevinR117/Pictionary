#ifndef GAMEMANAGERTHREAD_H
#define GAMEMANAGERTHREAD_H

#include <QtCore>

class GameManagerThread : public QThread
{
public:
    GameManagerThread();

    void run() override;
};

#endif // GAMEMANAGERTHREAD_H
