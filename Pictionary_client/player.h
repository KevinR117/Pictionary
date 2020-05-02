#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player();
    Player(QString pseudo);

    ~Player();

    //Return the rank of the player at this moment of the game
    int getRank() const;

    //Return the score of the player at this moment of the game
    int getScore() const;

    //Return the pseudo of the player
    QString getPseudo() const;

    //Set the rank of the player to a given value
    void setRank(int rank);

    //Set the score of the player to a given value
    void setScore(int score);

private:
    QString m_pseudo;
    int m_score;
    int m_rank;
};

#endif // PLAYER_H
