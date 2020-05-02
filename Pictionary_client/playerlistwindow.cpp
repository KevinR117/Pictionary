#include "playerlistwindow.h"

PlayerListWindow::PlayerListWindow()
{
    m_playerListLayout = new QGridLayout();
    m_players = new QTextEdit();
    m_players->setReadOnly(true);

    m_playerListLayout->addWidget(m_players, 0, 0, 9, 3);
}

QGridLayout* PlayerListWindow::getPlayerListLayout() const
{
    return this->m_playerListLayout;
}
