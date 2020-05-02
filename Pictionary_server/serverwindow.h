#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QtWidgets>
#include <QtNetwork>

class ServerWindow : public QWidget
{

    Q_OBJECT

public:
    ServerWindow();

    //Send the message sent by a player to every one
    void sendMessageToEveryOne(const QString &message);

    //Send the player pseydo to every one
    void sendPlayerPseudoToEveryOne(const QString &pseudo);

private slots:

    //Used when a new client connect to the server
    void newClientConnection();

    //Used when a client leaves the server
    void clientDisconnection();

    //Used when a message has been received from a player
    void receivedData();

private:
    QLabel *m_serverState;
    QPushButton *m_exitButton;

    QTcpServer *m_server;
    QList<QTcpSocket *> m_clients;

    quint16 m_lenData;
};

#endif // SERVERWINDOW_H
