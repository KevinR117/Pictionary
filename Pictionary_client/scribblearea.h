#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

class ScribbleArea : public QWidget
{

    Q_OBJECT

public:
    ScribbleArea();

    ScribbleArea(QWidget *parent);

    void resizeImage(QImage *image, const QSize &newSize);

    QImage getImage() const;

    void setPenColor(const QColor &newColor);

    void setPenWidth(int newWidth);

    void setImage(QImage &image);

    bool isModified() const;

    QColor getPenColor() const;

    int getPenWidth() const;

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);

    void drawLineTo(const QPoint &endPoint);

signals:
    void imageChanged();

private slots:
    void clearImage();

private:
    bool m_modified;
    bool m_scribbling;
    QColor m_penColor;
    int m_penWidth;
    QImage m_drawing;
    QPoint m_lastPoint;
};

#endif // SCRIBBLEAREA_H
