#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player();
    Player(QString pseudo);

    ~Player();

    enum playerState{drawer = 1, guesser = 0};

    //Return the rank of the player at this moment of the game
    quint16 getRank() const;

    //Return the score of the player at this moment of the game
    quint16 getScore() const;

    //Return the pseudo of the player
    QString getPseudo() const;

    //Return the strong pseudo of the player
    QString getStrongPseudo() const;

    //Return true if the player is ready to play
    bool getReadyness() const;

    //Return the state of the player : guesser or drawer
    playerState getState() const;

    //Set the rank of the player to a given value
    void setRank(quint16 rank);

    //Set the score of the player to a given value
    void setScore(quint16 score);

    //Set the player state to a given value between drawer and guesser
    void setState(playerState state);

    //Set player state to drawer
    void draw();

    //Set the player state to guesser
    void guess();

    //Set the player to ready to play
    void setReady();

private:
    QString m_pseudo;
    QString m_strongPseudo;
    int m_score;
    int m_rank;
    playerState m_playerState;
    bool m_playerReady;
};

#endif // PLAYER_H
