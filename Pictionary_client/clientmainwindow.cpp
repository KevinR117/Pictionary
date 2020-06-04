#include "clientmainwindow.h"

ClientMainWindow::ClientMainWindow()
{
    setWindowTitle(tr("Pictionary"));

    m_socket = new QTcpSocket(this);

    m_mainLayout = new QGridLayout();

    m_connectionWindow = new ClientConnectionWindow();
    m_chatWindow = new Chat();
    m_playerListWindow = new PlayerListWindow();
    m_hiddenWordWindow = new HiddenWord();
    m_timerWindow = new Timer();
    m_whiteBoardWindow = new WhiteBoardWindow();

    m_mainLayout->addLayout(m_connectionWindow->getConnectionLayout(), 0, 0, 1, 10);
    m_mainLayout->addLayout(m_chatWindow->getChatLayout(), 1, 7, 6, 3);
    m_mainLayout->addLayout(m_playerListWindow->getPlayerListLayout(), 2, 0, 4, 3);
    m_mainLayout->addLayout(m_hiddenWordWindow->getHiddenWordLayout(), 1, 2, 1, 5);
    m_mainLayout->addLayout(m_timerWindow->getTimerLayout(), 1, 0, 1, 2);
    m_mainLayout->addLayout(m_hiddenWordWindow->getChoseWordLayout(), 6, 0, 1, 3);
    m_mainLayout->addLayout(m_whiteBoardWindow->getWhiteBoardLayout(), 1, 3, 6, 4);

    setLayout(m_mainLayout);

    m_lenData = 0;

    QObject::connect(m_connectionWindow->getConnectionButton(), SIGNAL(clicked()), this, SLOT(onClickedConnectionButton()));
    QObject::connect(m_chatWindow->getSendButton(), SIGNAL(clicked()), this, SLOT(onClickedSendButton()));
    QObject::connect(m_whiteBoardWindow->getReadyButton(), SIGNAL(clicked()), this, SLOT(onClickedReadyButton()));

    QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(onConnectedClient()));
    QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnectedClient()));

    QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(receivedData()));
}

void ClientMainWindow::onClickedConnectionButton()
{
    m_connectionWindow->getConnectionButton()->setEnabled(false);
    m_connectionWindow->getConnectionStatus()->setText(tr("Connexion en cours..."));

    m_socket->abort();
    m_socket->connectToHost(m_connectionWindow->getServerIP()->text(), m_connectionWindow->getPort()->value());
}

void ClientMainWindow::onConnectedClient()
{
    m_connectionWindow->getConnectionStatus()->setText(tr("Connexion réussie !"));

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    sendPlayerPseudo();

    m_connectionWindow->getPseudoLineEdit()->setReadOnly(true);
}

void ClientMainWindow::onDisconnectedClient()
{
    m_connectionWindow->getConnectionStatus()->setText(tr("Client déconnecté"));
}

void ClientMainWindow::onClickedSendButton()
{
    QByteArray package;
    QDataStream out(&package, QIODevice::WriteOnly);

    QString messageToSend = tr("<strong>") + m_connectionWindow->getPseudo() + tr("</strong> : ") + m_chatWindow->getMyMessage()->text();

    out << (quint16) 0;
    out << (quint16) 1;
    out << messageToSend;
    out.device()->seek(0);
    out << (quint16) (package.size() - sizeof(quint16));

    m_socket->write(package);

    m_chatWindow->getMyMessage()->clear();
    m_chatWindow->getMyMessage()->setFocus();
}

void ClientMainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return && m_socket->state() == QAbstractSocket::UnconnectedState)
    {
        onClickedConnectionButton();
    } else if (event->key() == Qt::Key_Return && m_chatWindow->getMyMessage()->text() != tr("") && m_socket->state() == QAbstractSocket::ConnectedState)
    {
        onClickedSendButton();
    }
}

void ClientMainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();

    QByteArray package;
    QDataStream out(&package, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << (quint16) 2;
    out << m_connectionWindow->getPseudo();
    out.device()->seek(0);
    out << (quint16) (package.size() - sizeof(quint16));

    m_socket->write(package);
}

void ClientMainWindow::receivedData()
{
    QDataStream in(m_socket);

    if (m_lenData == 0)
    {
        if (m_socket->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
        } else
        {
            in >> m_lenData;
        }
    }

    if (m_socket->bytesAvailable() < m_lenData)
    {
        return;
    }

    quint16 typeData;
    in >> typeData;

    if (typeData == 1)
    {
        QString receivedMessage;
        in >> receivedMessage;

        m_chatWindow->getMessages()->append(receivedMessage);
    } else if (typeData == 0)
    {
        m_playerListWindow->getPlayers()->clear();

        quint16 size;
        in >> size;
        for (unsigned long long i = 0; i < size; i++)
        {
            QString receivedPseudo;
            in >> receivedPseudo;
            quint16 receivedScore;
            quint16 receivedRank;
            in >> receivedScore;
            in >> receivedRank;

            QString score;
            QString rank;

            m_playerListWindow->getPlayers()->append(receivedPseudo + tr(", Points : ") +score.setNum(receivedScore) + tr(", Rang : ") +rank.setNum(receivedRank));
        }
    }

    m_lenData = 0;
}

void ClientMainWindow::sendPlayerPseudo()
{

    QByteArray package;
    QDataStream out(&package, QIODevice::WriteOnly);

    QString pseudoToSend = m_connectionWindow->getPseudo();

    out << (quint16) 0;
    out << (quint16) 0;
    out << pseudoToSend;
    out.device()->seek(0);
    out << (quint16) (package.size() - sizeof(quint16));

    m_socket->write(package);
}

void ClientMainWindow::onClickedReadyButton()
{
    QByteArray package;
    QDataStream out(&package, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << (quint16) 3;
    out.device()->seek(0);
    out << (quint16) (package.size() - sizeof(quint16));

    m_socket->write(package);
}
