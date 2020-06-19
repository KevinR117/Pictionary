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

    //Return the index of the player given into the players list
    unsigned long long indexOfPlayer(QString &pseudo) const;

    //Add a player to the list
    void addPlayer(Player player);

    //Delete a player from the list
    void deletePlayer(const QString& pseudo);

    //Give the rank to the last player registered
    void rankLastPlayer();

    //Set the concerned player readyness to true
    void setPlayerReady(unsigned long long index);

    //Change the state of the chosen player
    void setPlayerState(Player::playerState state, unsigned long long index);

    //Change the state of the chosen player to drawer
    void setPlayerStateToDrawer(unsigned long long index);

    //Change the state of the chosen player to guesser
    void setPlayerStateToGuesser(unsigned long long index);

    //Re-rank players properly after a disconnection of a player, whatever his position
    void rankAfterDisconnection();

    //At the end of a tour and after points have been granted to every player, we sort the player list to updtate it. This method needs to be called at the end of every round
    void roundEndingRanking();

private:
    std::vector<Player> m_players;
};

#endif // PLAYERLIST_H
