#include "schemeview.h"


SchemeView::SchemeView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setDragMode(QGraphicsView::RubberBandDrag);
}

void SchemeView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);

}

void SchemeView::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    QPointF scenePos = this->mapToScene(pos);
    emit schemeClicked(scenePos);
    QGraphicsView::mousePressEvent(event);
}

void SchemeView::selectionChanged()
{
    if (this->scene()->selectedItems().count() != 0)
    {
        emit componentSelected((GraphicsComponent*)this->scene()->selectedItems().at(0));
    }
}
