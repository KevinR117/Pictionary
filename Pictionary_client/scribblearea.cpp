#include "scribblearea.h"

ScribbleArea::ScribbleArea() : m_modified(false), m_scribbling(false), m_penColor(Qt::black), m_penWidth(3)
{
    QImage loadedImage;
    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    m_drawing = loadedImage;
    m_modified = false;
    update();
}

ScribbleArea::ScribbleArea(QWidget *parent) : QWidget(parent), m_modified(false), m_scribbling(false), m_penColor(Qt::black), m_penWidth(3)
{
    QImage loadedImage;
    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    m_drawing = loadedImage;
    m_modified = false;
    update();
}

bool ScribbleArea::isModified() const
{
    return m_modified;
}

QColor ScribbleArea::getPenColor() const
{
    return m_penColor;
}

int ScribbleArea::getPenWidth() const
{
    return m_penWidth;
}

void ScribbleArea::setPenColor(const QColor &newColor)
{
    m_penColor = newColor;
}

void ScribbleArea::setPenWidth(int newWidth)
{
    m_penWidth = newWidth;
}

void ScribbleArea::clearImage()
{
    m_drawing.fill(Qt::white);
    m_modified = true;
    update();
}

void ScribbleArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_lastPoint = event->pos();
        m_scribbling = true;
    }
}

void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && m_scribbling == true)
    {
        drawLineTo(event->pos());
    }
}

void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_scribbling == true)
    {
        drawLineTo(event->pos());
        m_scribbling = false;
    }
}

void ScribbleArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect Rect = event->rect();
    painter.drawImage(Rect, m_drawing, Rect);
}

void ScribbleArea::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&m_drawing);
    painter.setPen(QPen(m_penColor, m_penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(m_lastPoint, endPoint);
    m_modified = true;
    int rad = (m_penWidth / 2) + 2;
    update(QRect(m_lastPoint, endPoint).normalized().adjusted(-rad, -rad, rad, rad));
    m_lastPoint = endPoint;
}

void ScribbleArea::resizeEvent(QResizeEvent *event)
{
    if (width() > m_drawing.width() || height() > m_drawing.height()) {
        int newWidth = qMax(width() + 128, m_drawing.width());
        int newHeight = qMax(height() + 128, m_drawing.height());
        resizeImage(&m_drawing, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void ScribbleArea::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}
