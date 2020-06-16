#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QtWidgets>
#include <QtNetwork>
#include <QPair>

#include "playerlist.h"
#include "gamemanagerthread.h"

class ServerWindow : public QWidget
{

    Q_OBJECT

public:
    ServerWindow();

    //Send the message sent by a player to every one
    void sendMessageToEveryOne(const QString &message);

    //Send the player pseydo to every one
    void sendPlayersToEveryOne(const std::vector<Player>, quint16 size);

    //Send the pseudo of the drawer to designate the good one
    void sendDrawerToEveryOne(int i);

    //If there are enough players, the signal enoughPlayers() is emitted
    void isReadyToPlay();

    //Return true if all the players in the game are ready
    bool arePlayersReady() const;

signals:
    void enoughPlayers();

    void nbPlayers(int);

private slots:

    //Used when a new client connect to the server
    void newClientConnection();

    //Used when a client leaves the server
    void clientDisconnection();

    //Used when a message has been received from a player
    void receivedData();

    //Used when the game is launched
    void launchGame();

    void nextPlayerToDraw();

private:
    QLabel *m_serverState;
    QPushButton *m_exitButton;
    QTcpServer *m_server;
    QList<QTcpSocket *> m_clients;
    PlayerList *m_playerList;
    quint16 m_lenData;
    QString m_disconnectedPlayer;
    bool m_gameStarted;
    GameManagerThread *m_thread;
};

#endif // SERVERWINDOW_H
