#ifndef PLAYERLISTWINDOW_H
#define PLAYERLISTWINDOW_H

#include <QtWidgets>

class PlayerListWindow : public QWidget
{
public:
    PlayerListWindow();

    //Return the player list Layout
    QGridLayout* getPlayerListLayout() const;

private:
    QGridLayout *m_playerListLayout;
    QTextEdit *m_players;
};

#endif // PLAYERLISTWINDOW_H
