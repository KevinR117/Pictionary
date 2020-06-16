#ifndef ROUND_H
#define ROUND_H

#include <QtWidgets>

#include "player.h"

class Round : public QWidget
{
public:
    Round();
    Round(int nb_players);

private:
    int m_nbPlayers;
};

#endif // ROUND_H
