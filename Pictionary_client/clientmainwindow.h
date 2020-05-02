#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <QtWidgets>
#include <QtNetwork>
#include <QKeyEvent>

#include "chat.h"
#include "clientconnectionwindow.h"
#include "player.h"

class ClientMainWindow : public QWidget
{

    Q_OBJECT

public:
    ClientMainWindow();

    //this is an alias for onClickedSendButton(), they do the same action
    void keyPressEvent(QKeyEvent *event);

public slots:

    //Used when connection button is clicked
    void onClickedConnectionButton();

    //Used when the client is successfully connected to the server
    void onConnectedClient();

    //Used when the client leave the game
    void onDisconnectedClient();

    //Used when the send button is clicked
    void onClickedSendButton();

    //Used when the server send us a message that has been sent by another player
    void receivedMessage();

private:
    QGridLayout *m_mainLayout;
    ClientConnectionWindow *m_connectionWindow;
    Chat *m_chatWindow;
    Player *m_player;

    QTcpSocket *m_socket;

    quint16 m_lenMessage;
};

#endif // CLIENTMAINWINDOW_H
