#include "clientconnectionwindow.h"

ClientConnectionWindow::ClientConnectionWindow()
{
    m_connectionStatus = new QLabel();
    m_connectionStatus->setText(tr("Entrez l'IP et le port :"));
    m_serverIP = new QLineEdit();
    m_serverIP->setPlaceholderText("IP");
    m_port = new QSpinBox();
    m_port->setRange(50885, 50885);

    m_pseudo = new QLineEdit();
    m_pseudo->setPlaceholderText("Pseudo");

    m_connectionButton = new QPushButton("Se connecter");

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(m_connectionStatus);
    layout->addWidget(m_serverIP);
    layout->addWidget(m_port);

    m_connectionLayout = new QGridLayout();
    m_connectionLayout->addLayout(layout, 0, 0);
    m_connectionLayout->addWidget(m_pseudo, 0, 2);
    m_connectionLayout->addWidget(m_connectionButton, 0, 3);
}

QGridLayout* ClientConnectionWindow::getConnectionLayout() const
{
    return this->m_connectionLayout;
}

QPushButton* ClientConnectionWindow::getConnectionButton() const
{
    return this->m_connectionButton;
}

QLabel* ClientConnectionWindow::getConnectionStatus() const
{
    return this->m_connectionStatus;
}

QLineEdit* ClientConnectionWindow::getServerIP() const
{
    return this->m_serverIP;
}

QSpinBox* ClientConnectionWindow::getPort() const
{
    return this->m_port;
}

QString ClientConnectionWindow::getPseudo() const
{
    return this->m_pseudo->text();
}

QLineEdit* ClientConnectionWindow::getPseudoLineEdit() const
{
    return this->m_pseudo;
}
