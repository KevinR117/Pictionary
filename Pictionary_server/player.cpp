#include "player.h"

Player::Player() : m_pseudo(""), m_strongPseudo("") , m_score(0), m_rank(1), m_playerState(guesser), m_playerReady(false)
{

}

Player::Player(QString pseudo) : m_pseudo(pseudo), m_strongPseudo("<strong>" + pseudo + "</strong>") , m_score(0), m_rank(1), m_playerState(guesser), m_playerReady(false)
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

QString Player::getStrongPseudo() const
{
    return this->m_strongPseudo;
}

bool Player::getReadyness() const
{
    return this->m_playerReady;
}

Player::playerState Player::getState() const
{
    return this->m_playerState;
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

void Player::draw()
{
    this->m_playerState = Player::playerState::drawer;
}

void Player::guess()
{
    this->m_playerState = Player::playerState::guesser;
}

void Player::setReady()
{
    this->m_playerReady = true;
}
