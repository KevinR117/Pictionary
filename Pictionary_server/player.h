#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player();
    Player(QString pseudo);

    ~Player();

    enum playerState{drawer, guesser};

    //Return the rank of the player at this moment of the game
    quint16 getRank() const;

    //Return the score of the player at this moment of the game
    quint16 getScore() const;

    //Return the pseudo of the player
    QString getPseudo() const;

    //Set the rank of the player to a given value
    void setRank(quint16 rank);

    //Set the score of the player to a given value
    void setScore(quint16 score);

    //Set the player state to a given value between drawer and guesser
    void setState(playerState state);

private:
    QString m_pseudo;
    int m_score;
    int m_rank;
    playerState m_playerState;
};

#endif // PLAYER_H
