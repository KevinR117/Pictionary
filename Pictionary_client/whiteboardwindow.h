#ifndef WHITEBOARDWINDOW_H
#define WHITEBOARDWINDOW_H

#include <QtWidgets>

class WhiteBoardWindow : public QWidget
{

    Q_OBJECT

public:
    WhiteBoardWindow();

    //Return the White Board Layout
    QGridLayout* getWhiteBoardLayout() const;

    //Return the Ready button
    QPushButton* getReadyButton() const;

private :
    QGridLayout *m_whiteBoardLayout;
    QPushButton *m_readyButton;
};

#endif // WHITEBOARDWINDOW_H
