#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QList>
#include <QVariant>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
using namespace std;

#include "abstractscheme.h"
#include "component.h"
class AbstractScheme;

#include <QStyle>
#include <QStyleOptionGraphicsItem>

//! Base class for graphical component
/**
  * Base class for graphical components. Provides all necessary
  * methods to create graphic components
  */
class GraphicsComponent : public QObject, public QGraphicsItemGroup, public virtual Component
{
    Q_OBJECT

protected:
    /**
      * Pointer to the parent scheme
      */
    AbstractScheme *parent;
private:

    /**
      * Calculate item position based on a snapping parameters
      * and given coordinates
      * @return item coordinates calculated with account of
      * snapping mode
      */
    QPoint calculateSnap(const QPoint &point);

    /**
      * Rounds numbers specificaly for _calculateSnap methods
      */
    int  round(int num, int border);
    /**
      * Pointer to body of the component
      */
    QGraphicsSvgItem *body;


public:
    using Component::setProperty;
    using Component::getProperty;
    /**
      * Returns body of the component
      * @return pointer to the body of the component
      */
    QGraphicsSvgItem *getBody();
    /**
      * Destructor of the component
      */
    virtual ~GraphicsComponent();
    /**
      * Sets specified property
      * @param name property name
      * @param value value of the property
      */
    virtual void setProperty(const QString &name, const QVariant &value);
    /**
      * Returns value of the property
      * @param property name
      * @return value of the property
      */
    virtual QVariant getProperty(const QString &property);
protected:
    /**
      * Constructs GraphicsComponent with specified parent and info
      * @param parent parent scheme
      * @param info pointer to ComponentInfo
      */
    GraphicsComponent(AbstractScheme *parent, ComponentInfo* info);
    /**
      * Constructs GraphicsComponent with specified info
      * @param info ComponentInfo
      */
     GraphicsComponent(AbstractScheme *parent);
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);



signals:
    void itemMoved(GraphicsComponent*);


};

#endif // GRAPHICSCOMPONENT_H
