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
            m_players.erase(m_players.begin() + i);
        }
    }
}
