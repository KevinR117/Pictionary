#ifndef PLAYERLISTWINDOW_H
#define PLAYERLISTWINDOW_H

#include <QtWidgets>

class PlayerListWindow : public QWidget
{

    Q_OBJECT

public:
    PlayerListWindow();

    //Return the player list Layout
    QGridLayout* getPlayerListLayout() const;

    //Return the list of players already connected
    QTextEdit* getPlayers() const;

private:
    QGridLayout *m_playerListLayout;
    QTextEdit *m_players;
};

#endif // PLAYERLISTWINDOW_H
