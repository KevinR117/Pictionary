#include "serverwindow.h"

ServerWindow::ServerWindow() : QWidget()
{
    setWindowTitle("Pictionary server");

    m_serverState = new QLabel;
    m_exitButton = new QPushButton("Stop server");

    QObject::connect(m_exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_serverState);
    layout->addWidget(m_exitButton);
    setLayout(layout);

    m_server = new QTcpServer(this);
    if (!m_server->listen(QHostAddress::Any, 50885))
    {
        m_serverState->setText(tr("The server can't start. Reason : </br>") + m_server->errorString());
    } else {
        m_serverState->setText(tr("The server started successfully and is listening on : <strong>") + QString::number(m_server->serverPort()) + tr("</strong>.</br> Clients can connect to the server now"));
        QObject::connect(m_server, SIGNAL(newConnection()), this, SLOT(newClientConnection()));
    }

    m_playerList = new PlayerList();

    m_lenData = 0;

    m_disconnectedPlayer = tr("");

    m_round = new Round();
    QObject::connect(this, SIGNAL(enoughPlayers()), this, SLOT(launchGame()));
}

void ServerWindow::newClientConnection()
{
    if (!m_round->isStarted())
    {
        QTcpSocket *newClient = m_server->nextPendingConnection();
        m_clients << newClient;

        QObject::connect(newClient, SIGNAL(readyRead()), this, SLOT(receivedData()));
        QObject::connect(newClient, SIGNAL(disconnected()), this, SLOT(clientDisconnection()));
    }
}

void ServerWindow::clientDisconnection()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
    {
        return;
    } else
    {
        m_clients.removeOne(socket);
        socket->deleteLater();
    }
}

void ServerWindow::receivedData()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
    {
        return;
    }

    QDataStream in(socket);

    if (m_lenData == 0)
    {
        if (socket->bytesAvailable() < (int) sizeof(quint16))
        {
            return;
        } else
        {
            in >> m_lenData;
        }
    }

    if (socket->bytesAvailable() < m_lenData)
    {
        return;
    }

    quint16 dataType;
    in >> dataType;

    if (dataType == 0)
    {
        QString playerPseudoToSendToEveryOne;
        in >> playerPseudoToSendToEveryOne;

        Player *newPlayer = new Player(playerPseudoToSendToEveryOne);
        m_playerList->addPlayer(*newPlayer);
        m_playerList->rankLastPlayer();

        sendPlayersToEveryOne(m_playerList->getPlayers(), m_playerList->getPlayers().size());
    } else if (dataType == 1)
    {
        QString messageToSendToEveryOne;
        in >> messageToSendToEveryOne;

        sendMessageToEveryOne(messageToSendToEveryOne);
    } else if (dataType == 2)
    {
        in >> m_disconnectedPlayer;
        m_playerList->deletePlayer(m_disconnectedPlayer);

        m_playerList->rankAfterDisconnection();

        sendPlayersToEveryOne(m_playerList->getPlayers(), m_playerList->getPlayers().size());
    } else if (dataType == 3)
    {
        QString readyPlayerPseudo;
        in >> readyPlayerPseudo;

        QString readyMessage;
        in >> readyMessage;

        unsigned long long index = m_playerList->indexOfPlayer(readyPlayerPseudo);
        m_playerList->setPlayerReady(index);

        sendMessageToEveryOne(tr("<strong>") + readyPlayerPseudo + tr("</strong> : ") + readyMessage);

        isReadyToPlay();
    }

    m_lenData = 0;

    m_disconnectedPlayer = tr("");
}

void ServerWindow::sendMessageToEveryOne(const QString &message)
{
    QByteArray package;
    QDataStream out(&package, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << (quint16) 1;
    out << message;
    out.device()->seek(0);
    out << (quint16) (package.size() - sizeof(quint16));

    for (int i = 0; i < m_clients.size(); i++)
    {
        m_clients[i]->write(package);
    }
}

void ServerWindow::sendPlayersToEveryOne(const std::vector<Player>, quint16 size)
{   
    QByteArray package;
    QDataStream out(&package, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << (quint16) 0;
    out << size;
    for (unsigned long long i = 0; i < size; i++)
    {
        out << tr("<strong>") + m_playerList->getPlayers()[i].getPseudo() + tr("</strong>");
        out << m_playerList->getPlayers()[i].getScore();
        out << m_playerList->getPlayers()[i].getRank();
    }
    out.device()->seek(0);
    out << (quint16) (package.size() - sizeof(quint16));

    for (int i = 0; i < m_clients.size(); i++)
    {
        m_clients[i]->write(package);
    }
}

bool ServerWindow::arePlayersReady()
{
    for (unsigned long long i = 0; i < m_playerList->getPlayers().size(); i++)
    {
        if (!m_playerList->getPlayers()[i].getReadyness())
        {
            return false;
        }
    }
    return true;
}

void ServerWindow::isReadyToPlay()
{
    if (m_playerList->getPlayers().size() >= 2 and arePlayersReady())
    {
        emit(enoughPlayers());
    }
}

void ServerWindow::launchGame()
{
    m_round->startRound();
}
