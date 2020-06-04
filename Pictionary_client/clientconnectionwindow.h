#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QtWidgets>

class ClientConnectionWindow : public QWidget
{

    Q_OBJECT

public:
    ClientConnectionWindow();

    //Return the connection Layout
    QGridLayout* getConnectionLayout() const;

    //Return the connection button
    QPushButton* getConnectionButton() const;

    //Return the connection status of the player
    QLabel* getConnectionStatus() const;

    //Return the IP of the server
    QLineEdit* getServerIP() const;

    //Return the port used by the host
    QSpinBox* getPort() const;

    //Return the pseudo entered by the player
    QString getPseudo() const;

    //Return the QLineEdit used to chose one's pseudo. It will permit to desactivate it when the player is connected, so the player is well deleted when the player leave the game
    QLineEdit* getPseudoLineEdit() const;

private:
    QGridLayout *m_connectionLayout;
    QLabel *m_connectionStatus;
    QPushButton *m_connectionButton;
    QLineEdit *m_serverIP;
    QSpinBox *m_port;
    QLineEdit *m_pseudo;
};

#endif // CLIENTWINDOW_H
