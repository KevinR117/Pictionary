#include "whiteboardwindow.h"

WhiteBoardWindow::WhiteBoardWindow()
{
    m_whiteBoardLayout = new QGridLayout();
    m_readyButton = new QPushButton("Prêt");

    m_colorButton = new QPushButton("couleur du trait");
    m_widthButton = new QPushButton("épaisseur");

    m_scribbleArea = new ScribbleArea(this);

    m_whiteBoardLayout->addWidget(m_scribbleArea, 0, 0, 8, 2);
    m_whiteBoardLayout->addWidget(m_colorButton, 9, 0, 1, 1);
    m_whiteBoardLayout->addWidget(m_widthButton, 9, 1, 1, 1);
    m_whiteBoardLayout->addWidget(m_readyButton, 10, 0, 1, 2);

    QObject::connect(m_colorButton, SIGNAL(clicked()), this, SLOT(penColor()));
    QObject::connect(m_widthButton, SIGNAL(clicked()), this, SLOT(penWidth()));

    QObject::connect(m_scribbleArea, SIGNAL(imageChanged()), this, SLOT(imageHasChanged()));
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
    int newWidth = QInputDialog::getInt(this, tr("Size of the pen"), tr("Please select the pen width : "),10, 1, 50, 1, &ok);
    if (ok)
    {
        m_scribbleArea->setPenWidth(newWidth);
    }
}

ScribbleArea* WhiteBoardWindow::getScribbleArea() const
{
    return m_scribbleArea;
}

void WhiteBoardWindow::imageHasChanged()
{
    emit(newImageAvailable());
}
