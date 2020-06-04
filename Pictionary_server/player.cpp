#include "player.h"

Player::Player() : m_pseudo(""), m_score(0), m_rank(1), m_playerState(guesser)
{

}

Player::Player(QString pseudo) : m_pseudo(pseudo), m_score(0), m_rank(1), m_playerState(guesser)
{

}

Player::~Player()
{

}

quint16 Player::getRank() const
{
    return this->m_rank;
}
quint16 Player::getScore() const
{
    return this->m_score;
}
QString Player::getPseudo() const
{
    return this->m_pseudo;
}

void Player::setRank(quint16 rank)
{
    this->m_rank = rank;
}
void Player::setScore(quint16 score)
{
    this->m_score = score;
}

void Player::setState(playerState state)
{
    this->m_playerState = state;
}
