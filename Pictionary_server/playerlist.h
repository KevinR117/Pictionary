#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include <QtWidgets>

#include <vector>
#include "player.h"

class PlayerList : public QWidget
{
public:
    PlayerList();
    PlayerList(Player player);

    ~PlayerList();

    //Return the list of players which are present in the game
    std::vector<Player> getPlayers() const;

    //Add a player to the list
    void addPlayer(Player player);

    //Delete a player from the list
    void deletePlayer(const QString& pseudo);

    //give the rank to the last player registered
    void rankLastPlayer();

    //At the end of a tour and after points have been granted to every player, we sort the player list to updtate it. This method needs to be called at the end of every round
    void roundEndingRanking();

private:
    std::vector<Player> m_players;
};

#endif // PLAYERLIST_H
