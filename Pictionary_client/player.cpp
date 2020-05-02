#include "player.h"

Player::Player() : m_pseudo(""), m_score(0), m_rank(0)
{

}

Player::Player(QString pseudo) : m_pseudo(pseudo), m_score(0), m_rank(0)
{

}

Player::~Player()
{

}

int Player::getRank() const
{
    return this->m_rank;
}
int Player::getScore() const
{
    return this->m_score;
}
QString Player::getPseudo() const
{
    return this->m_pseudo;
}
void Player::setRank(int rank)
{
    this->m_rank = rank;
}
void Player::setScore(int score)
{
    this->m_score = score;
}
