#include "gamemanagerthread.h"

GameManagerThread::GameManagerThread() : m_round(nullptr), m_nbRounds(5), m_nbPlayers(0)
{

}

void GameManagerThread::run()
{
    emit(nextPlayerDrawing());
    m_round = new Round(m_nbPlayers);
}

void GameManagerThread::receiveNbPlayers(int nbPlayers)
{
    m_nbPlayers = nbPlayers;
}
