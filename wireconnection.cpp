#include "wireconnection.h"

WireConnection::WireConnection(AbstractScheme *parent,
    GraphicsComponent *first, GraphicsComponent *second)
        :GraphicsComponent(parent)
{
    this->setFlags(this->flags() ^ QGraphicsItem::ItemIsMovable);
    this->setFlags(this->flags() ^ QGraphicsItem::ItemIsSelectable);
    this->first = first;
    this->second = second;

    QObject::connect(first, SIGNAL(itemMoved(GraphicsComponent*)), this, SLOT(componentMoved(GraphicsComponent*)));
    QObject::connect(second, SIGNAL(itemMoved(GraphicsComponent*)), this, SLOT(componentMoved(GraphicsComponent*)));

    rebuildPath();
}

void WireConnection::rebuildPath()
{
    QPointF firstPos = first->pos();
    QPointF secondPos = second->pos();
    QPointF intermediate;

    intermediate.setX(first->x());
    intermediate.setY(second->y());

    for(QList<QGraphicsLineItem*>::iterator i = path.begin(); i != path.end();i++)
    {
        this->removeFromGroup(*i);
    }

    qDeleteAll(this->path);
    this->path.clear();

    this->path.append(new QGraphicsLineItem(QLineF(firstPos, intermediate)));
    this->path.append(new QGraphicsLineItem(QLineF(intermediate, secondPos)));

    for(QList<QGraphicsLineItem*>::iterator i = path.begin(); i != path.end();i++)
    {
        this->addToGroup(*i);
    }

}

void WireConnection::componentMoved(GraphicsComponent *moved)
{
    rebuildPath();
}
