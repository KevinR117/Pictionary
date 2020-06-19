#include "playerlist.h"

PlayerList::PlayerList()
{

}

PlayerList::PlayerList(Player player)
{
    m_players.push_back(player);
    player.setRank(1);
}

PlayerList::~PlayerList()
{

}

std::vector<Player> PlayerList::getPlayers() const
{
    return this->m_players;
}

void PlayerList::addPlayer(Player player)
{
    this->m_players.push_back(player);
}

void PlayerList::rankLastPlayer()
{
    this->m_players[m_players.size() - 1].setRank(m_players.size());
}

void PlayerList::rankAfterDisconnection()
{
    for (unsigned long long i = 0; i < m_players.size(); i++)
    {
        m_players[i].setRank(i + 1);
    }
}

void PlayerList::roundEndingRanking()
{
    for (unsigned long long i = 0; i < m_players.size() - 1; i++)
    {
        for (unsigned long long j(i); j < m_players.size() - 1; i++)
        {
            if (m_players[j].getScore() > m_players[j + 1].getScore())
            {
                m_players[j], m_players[j + 1] = m_players[i + 1], m_players[i];
                m_players[j].setRank(j + 1);
                m_players[j + 1].setRank(j + 2);
            }
        }
    }
}

void PlayerList::deletePlayer(const QString &pseudo)
{
    for (unsigned long long i = 0; i < m_players.size(); i++)
    {
        if (m_players[i].getPseudo() == pseudo)
        {
            for (unsigned long long k = i; k < m_players.size() - 1; k++)
            {
                m_players[k] = m_players[k + 1];
            }
            m_players.pop_back();
        }
    }
}

unsigned long long PlayerList::indexOfPlayer(QString &pseudo) const
{
    unsigned long long index = 0;
    for (unsigned long long i = 0; i < m_players.size(); i++)
    {
        if (m_players[i].getPseudo() == pseudo || m_players[i].getStrongPseudo() == pseudo)
        {
            index = i;
            break;
        }
    }
    return index;
}

void PlayerList::setPlayerReady(unsigned long long index)
{
    m_players[index].setReady();
}

void PlayerList::setPlayerState(Player::playerState state, unsigned long long index)
{
    m_players[index].setState(state);
}

void PlayerList::setPlayerStateToDrawer(unsigned long long index)
{
    m_players[index].draw();
}

void PlayerList::setPlayerStateToGuesser(unsigned long long index)
{
    m_players[index].guess();
}

void PlayerList::addScore(unsigned long long index, int score)
{
    m_players[index].setScore(m_players[index].getScore() + score);
}
