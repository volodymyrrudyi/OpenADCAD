#include "graphicscomponent.h"
#include <QGraphicsTextItem>

GraphicsComponent::GraphicsComponent(AbstractScheme *parent)
{
    this->setFlag(QGraphicsItem::ItemIsMovable);
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    this->parent = parent;
    this->setProperty("angle", QVariant(0.0f));
}

GraphicsComponent::GraphicsComponent(AbstractScheme *parent,
                                     ComponentInfo *info) : Component(info)
{
    this->parent = parent;
    this->setFlag(QGraphicsItem::ItemIsMovable);
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemSendsGeometryChanges);

    this->setProperty("angle", QVariant(0.0f));
}

GraphicsComponent::~GraphicsComponent()
{

}

int GraphicsComponent::round(int num, int border)
{
    int res = num;
    int odd = num % border;

    if (odd < (border / 2))
    {
        res = res - odd;
    } else {
        res = res + border - odd;
    }

    return res;
}

QPoint GraphicsComponent::calculateSnap(const QPoint &point)
{
    QPoint res(round(point.x(), this->parent->getGridStep()),
               round(point.y(), this->parent->getGridStep()));

    return res;
}

QVariant GraphicsComponent::itemChange(GraphicsItemChange change, const QVariant &value)
{

    switch (change)
    {
    case ItemPositionChange:
        {
            emit itemMoved(this);
            QPoint pos = value.toPoint();
            if (this->parent->getSnapToGrid()){
                pos = this->calculateSnap(pos);
                this->setProperty("x", pos.x());
                this->setProperty("y", pos.y());
                return QGraphicsItem::itemChange(change, QVariant(pos));
            }

            this->setProperty("x", this->x());
            this->setProperty("y", this->y());

        }
        break;
    case ItemSelectedChange:
        break;
    default:
        break;

    }

     return QGraphicsItem::itemChange(change, value);

}



void GraphicsComponent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QStyleOptionGraphicsItem correctedOption = (*option);
    QGraphicsItemGroup ::paint(painter, &correctedOption, widget);
}

void GraphicsComponent::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->pos();

    QGraphicsItem::mouseMoveEvent(event);
}



QGraphicsSvgItem *GraphicsComponent::getBody()
{
    return this->body;
}

void GraphicsComponent::setProperty(const QString &name, const QVariant &value)
{
    if (name == "x")
    {
        this->setX(value.toReal());
    } else if (name == "y")
    {
        this->setY(value.toReal());
    } else if (name == "angle")
    {
        this->setRotation(value.toDouble());
    }
    Component::setProperty(name, value);
}

QVariant GraphicsComponent::getProperty(const QString &property)
{
    return Component::getProperty(property);
}


