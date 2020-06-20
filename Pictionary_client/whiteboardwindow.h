#ifndef WHITEBOARDWINDOW_H
#define WHITEBOARDWINDOW_H

#include <QtWidgets>
#include <QList>

#include "scribblearea.h"

class WhiteBoardWindow : public QWidget
{

    Q_OBJECT

public:
    WhiteBoardWindow();

    //Return the White Board Layout
    QGridLayout* getWhiteBoardLayout() const;

    //Return the Ready button
    QPushButton* getReadyButton() const;

    void createActions();

private slots:
    void penColor();

    void penWidth();

private :
    QGridLayout *m_whiteBoardLayout;
    QPushButton *m_readyButton;
    ScribbleArea *m_scribbleArea;
    QAction *m_penColorAct;
    QAction *m_penWidthAct;
    QAction *m_clearScreenAct;
};

#endif // WHITEBOARDWINDOW_H
