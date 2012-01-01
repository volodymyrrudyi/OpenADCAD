#ifndef COMPONENTSTORAGE_H
#define COMPONENTSTORAGE_H

#include <QObject>
#include "graphicscomponent.h"

//! Implements component storage
/**
  */
class ComponentStorage : public QObject
{
    Q_OBJECT
public:
    explicit ComponentStorage(QObject *parent = 0);

    void addComponent(ComponentInfo *component);
    void removeComponent(ComponentInfo *component);
    GraphicsComponent *createComponent(ComponentInfo *component);
signals:
    void componentAdded(ComponentInfo *added);
    void componentRemoved(ComponentInfo *removed);

public slots:

};

#endif // COMPONENTSTORAGE_H
