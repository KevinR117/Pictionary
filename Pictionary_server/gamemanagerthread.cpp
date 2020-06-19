#include "gamemanagerthread.h"

GameManagerThread::GameManagerThread() : m_nbRounds(5), m_nbPlayers(0), m_timeRemaining(80), m_sessionStillAlive(true)
{

}

void GameManagerThread::run()
{
    for (unsigned long long i = 0; i < m_nbRounds; i++)
    {
        for (int j = 0; j < m_nbPlayers; j++)
        {
            m_sessionStillAlive = true;

            emit(nextPlayerDrawing());

            std::this_thread::sleep_for(std::chrono::milliseconds(10000));

            m_timeRemaining = 80;
            while (m_timeRemaining != -1 && m_sessionStillAlive == true)
            {
                emit(timeToSend(m_timeRemaining));
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                m_timeRemaining -= 1;
            }
            emit(drawingSessionEnd());
        }
        emit(roundEnd());
    }
}

void GameManagerThread::receiveNbPlayers(int nbPlayers)
{
    m_nbPlayers = nbPlayers;
}

QString GameManagerThread::getTimeRemaining() const
{
    return QString::number(m_timeRemaining);
}

void GameManagerThread::finishSessionNow()
{
    m_sessionStillAlive = false;
}
