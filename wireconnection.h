#ifndef WIRECONNECTION_H
#define WIRECONNECTION_H

#include "graphicscomponent.h"
#include <QGraphicsPathItem>
#include <QPointF>
#include <QList>

//! Class that implements wire connection between two components
/**
  * Class that implements wire connection between two components
  */
class WireConnection : public GraphicsComponent
{

    Q_OBJECT
    /**
      * First component to connect with
      */
    GraphicsComponent *first;
    /**
      * Second component to connect with
      */
    GraphicsComponent *second;
    /**
      * List of the lines - parts of the path between components
      */
    QList<QGraphicsLineItem*> path;
protected:
    /**
      * Constructs wire connection with specified parent
      * between specified component
      * @param parent parent scheme
      * @param first first component
      * @param second second component
      */
    WireConnection(AbstractScheme *parent,
                   GraphicsComponent *first, GraphicsComponent *second);
public:

    /**
      * Causes path between components being rebuilt
      */
    void rebuildPath();

public slots:
    void componentMoved(GraphicsComponent *moved);
};

#endif // WIRECONNECTION_H
