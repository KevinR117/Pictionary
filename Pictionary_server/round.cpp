#include "round.h"

Round::Round() : m_roundStarted(false)
{

}

void Round::startRound()
{
    m_roundStarted = true;
}

bool Round::isStarted()
{
    if (m_roundStarted)
    {
        return true;
    }
    return false;
}
