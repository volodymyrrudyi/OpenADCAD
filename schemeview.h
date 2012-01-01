#ifndef SCHEMEVIEW_H
#define SCHEMEVIEW_H

#include "component.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include "graphicscomponent.h"
class SchemeView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SchemeView(QWidget *parent = 0);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

signals:
    void componentSelected(GraphicsComponent *selected);
    void schemeClicked(QPointF point);
public slots:
    void selectionChanged();



};

#endif // SCHEMEVIEW_H
