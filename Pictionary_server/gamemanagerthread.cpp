#include "gamemanagerthread.h"

GameManagerThread::GameManagerThread() : m_nbRounds(5), m_nbPlayers(0)
{

}

void GameManagerThread::run()
{
    for (unsigned long long i = 0; i < m_nbRounds; i++)
    {
        for (int j = 0; j < m_nbPlayers; j++)
        {
            emit(nextPlayerDrawing());

            std::this_thread::sleep_for(std::chrono::milliseconds(10000));

            int timeRemaining = 10;
            while (timeRemaining != 0)
            {
                emit(timeToSend(timeRemaining));
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                timeRemaining -= 1;
            }
        }
    }
}

void GameManagerThread::receiveNbPlayers(int nbPlayers)
{
    m_nbPlayers = nbPlayers;
}
