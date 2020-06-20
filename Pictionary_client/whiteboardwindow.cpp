#include "whiteboardwindow.h"

WhiteBoardWindow::WhiteBoardWindow()
{
    m_whiteBoardLayout = new QGridLayout();
    m_readyButton = new QPushButton("Prêt");

    m_scribbleArea = new ScribbleArea(this);

    m_whiteBoardLayout->addWidget(m_scribbleArea, 0, 0, 1, 1);
    m_whiteBoardLayout->addWidget(m_readyButton, 10, 0, 1, 1);
}

QGridLayout* WhiteBoardWindow::getWhiteBoardLayout() const
{
    return this->m_whiteBoardLayout;
}

QPushButton* WhiteBoardWindow::getReadyButton() const
{
    return this->m_readyButton;
}

void WhiteBoardWindow::penColor()
{
    QColor newColor = QColorDialog::getColor(m_scribbleArea->getPenColor());
    if (newColor.isValid())
    {
        m_scribbleArea->setPenColor(newColor);
    }
}

void WhiteBoardWindow::penWidth()
{
    bool ok = false;
    int newWidth = QInputDialog::getInt(this, tr("Size of the pen"), tr("Please select the pen width : "), 1, 50, 1, ok);
    if (ok)
    {
        m_scribbleArea->setPenWidth(newWidth);
    }
}

void WhiteBoardWindow::createActions()
{
    m_penColorAct = new QAction(tr("&Pen Color ..."), this);
    QObject::connect(m_penColorAct, SIGNAL(triggered()), this, SLOT(penColor()));

    m_penWidthAct = new QAction(tr("&Pen Width ..."), this);
    QObject::connect(m_penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));

    m_clearScreenAct = new QAction(tr("&Clear Screen ..."), this);
    QObject::connect(m_clearScreenAct, SIGNAL(triggered()), m_scribbleArea, SLOT(clearImage()));
}
