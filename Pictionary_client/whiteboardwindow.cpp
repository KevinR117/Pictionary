#include "whiteboardwindow.h"

WhiteBoardWindow::WhiteBoardWindow()
{
    m_whiteBoardLayout = new QGridLayout();
    m_readyButton = new QPushButton("Prêt");
    m_readyButton->setEnabled(false);

    m_whiteBoardLayout->addWidget(m_readyButton, 10, 0, 1, 1);
}

QGridLayout* WhiteBoardWindow::getWhiteBoardLayout() const
{
    return this->m_whiteBoardLayout;
}
