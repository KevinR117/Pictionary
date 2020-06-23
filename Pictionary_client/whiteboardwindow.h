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

    //Return the Scribble area
    ScribbleArea* getScribbleArea() const;

signals:
    void newImageAvailable();

private slots:
    void penColor();

    void penWidth();

    void imageHasChanged();

private :
    QGridLayout *m_whiteBoardLayout;
    QPushButton *m_readyButton;
    ScribbleArea *m_scribbleArea;
    QPushButton *m_colorButton;
    QPushButton *m_widthButton;
};

#endif // WHITEBOARDWINDOW_H
