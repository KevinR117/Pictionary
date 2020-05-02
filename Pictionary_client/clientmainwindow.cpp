#include "clientmainwindow.h"

ClientMainWindow::ClientMainWindow()
{
    setWindowTitle(tr("Pictionary"));

    m_socket = new QTcpSocket(this);

    m_mainLayout = new QGridLayout();

    m_connectionWindow = new ClientConnectionWindow();
    m_chatWindow = new Chat();
    m_playerListWindow = new PlayerListWindow();

    m_mainLayout->addLayout(m_connectionWindow->getConnectionLayout(), 0, 0, 1, 4);
    m_mainLayout->addLayout(m_chatWindow->getChatLayout(), 1, 3, 6, 1);
    m_mainLayout->addLayout(m_playerListWindow->getPlayerListLayout(), 2, 0, 5, 1);

    setLayout(m_mainLayout);

    m_lenMessage = 0;

    QObject::connect(m_connectionWindow->getConnectionButton(), SIGNAL(clicked()), this, SLOT(onClickedConnectionButton()));
    QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(onConnectedClient()));
    QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnectedClient()));

    QObject::connect(m_chatWindow->getSendButton(), SIGNAL(clicked()), this, SLOT(onClickedSendButton()));
    QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(receivedMessage()));
}

void ClientMainWindow::onClickedConnectionButton()
{
    m_connectionWindow->getConnectionButton()->setEnabled(false);
    m_connectionWindow->getConnectionStatus()->setText(tr("Connexion en cours..."));

    m_socket->abort();
    m_socket->connectToHost(m_connectionWindow->getServerIP()->text(), m_connectionWindow->getPort()->value());
    m_player = new Player(m_connectionWindow->getPseudo());

    QByteArray package;
    QDataStream out(&package, QIODevice::WriteOnly);

    QString pseudoToSend = tr("<strong>") + m_player->getPseudo() + tr("</strong>");

    out << (quint16) 0;
    out << pseudoToSend;
    out.device()->seek(0);
    out << (quint16) (package.size() - sizeof(quint16));

    m_socket->write(package);
}

void ClientMainWindow::onConnectedClient()
{
    m_connectionWindow->getConnectionStatus()->setText(tr("Connexion réussie !"));
}

void ClientMainWindow::onDisconnectedClient()
{
    m_connectionWindow->getConnectionStatus()->setText(tr("Client déconnecté"));
}

void ClientMainWindow::onClickedSendButton()
{
    QByteArray package;
    QDataStream out(&package, QIODevice::WriteOnly);

    QString messageToSend = tr("<strong>") + m_player->getPseudo() + tr("</strong> : ") + m_chatWindow->getMyMessage()->text();

    out << (quint16) 0;
    out << messageToSend;
    out.device()->seek(0);
    out << (quint16) (package.size() - sizeof(quint16));

    m_socket->write(package);

    m_chatWindow->getMyMessage()->clear();
    m_chatWindow->getMyMessage()->setFocus();
}

void ClientMainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return && m_chatWindow->getMyMessage()->text() != tr("") && m_socket->state() == QAbstractSocket::ConnectedState)
    {
        onClickedSendButton();
    }
}

void ClientMainWindow::receivedMessage()
{
    QDataStream in(m_socket);

    if (m_lenMessage == 0)
    {
        if (m_socket->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
        } else
        {
            in >> m_lenMessage;
        }
    }

    if (m_socket->bytesAvailable() < m_lenMessage)
    {
        return;
    }

    QString receivedMessage;
    in >> receivedMessage;

    m_chatWindow->getMessages()->append(receivedMessage);

    m_lenMessage = 0;
}
