#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <QtWidgets>
#include <QtNetwork>
#include <QKeyEvent>
#include <string>

#include "chat.h"
#include "clientconnectionwindow.h"
#include "playerlistwindow.h"
#include "hiddenword.h"
#include "timer.h"
#include "whiteboardwindow.h"

class ClientMainWindow : public QWidget
{

    Q_OBJECT

public:
    ClientMainWindow();

    //This is an alias for onClickedSendButton(), they do the same action
    void keyPressEvent(QKeyEvent *event) override;

    //Used to send the player pseudo to delete when the main client window is closed before disconnecting the player himself
    void closeEvent(QCloseEvent *event) override;

    //When a player has connected successfully, it send to the server the player pseudo
    void sendPlayerPseudo();

public slots:

    //Used when connection button is clicked
    void onClickedConnectionButton();

    //Used when the client is successfully connected to the server
    void onConnectedClient();

    //Used when the client leave the game
    void onDisconnectedClient();

    //Used when the send button is clicked
    void onClickedSendButton();

    //Used when the ready button is clicked
    void onClickedReadyButton();

    //Used when the server send us a message that has been sent by another player
    void receivedData();

private:
    QGridLayout *m_mainLayout;
    ClientConnectionWindow *m_connectionWindow;
    Chat *m_chatWindow;
    PlayerListWindow *m_playerListWindow;
    HiddenWord *m_hiddenWordWindow;
    Timer *m_timerWindow;
    WhiteBoardWindow *m_whiteBoardWindow;
    QTcpSocket *m_socket;
    quint16 m_lenData;
};

#endif // CLIENTMAINWINDOW_H
