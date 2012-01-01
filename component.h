#ifndef COMPONENT_H
#define COMPONENT_H


#include <QMap>
#include <QList>
#include <QString>
#include <QVariant>
#include "componentinfo.h"
using namespace std;


//! Component class
/**
  * Component is a base class for all scheme components
  */
class Component
{
protected:
    /**
      * Name of the component
      */
    QString name;
    /**
      * Associative container with properties
      */
    QMap<QString, QVariant> properties;
    /**
      * Link to the ComponentInfo for this object
      */
    ComponentInfo *info;
    /**
      * List of the component that are connected with this component
      */
    QList<Component*> connectedComponents;
public:
    /**
      * Takes pointer to ComponentInfo and assigns it with current component
      */
    Component(ComponentInfo *info);
    /**
      * Default constructor
      */
    Component();
    /**
      * Destructor of the Component class
      */
    virtual ~Component();
    /**
      * Returns QMap with properties and values
      * @return Map with properties and values
      */
    QMap<QString, QVariant> getProperties();
    /**
      * Returns property value
      * @paragraph property property name
      * @return value of the specified property
      */
    virtual QVariant getProperty(const QString &property) ;
    /**
      * Sets property value
      * @param property name of the property
      * @param value value of the property
      */
    virtual void setProperty(const QString &property,const QVariant &value);
    /**
      * Returns ComponentInfo associated with current Component
      * @return ComponentInfo associated with current Component
      */
    ComponentInfo *getInfo();
    /**
      * Returns list of the components that are connected to this component
      * @return list of the components that are connected to this component
      */
    QList<Component*> &getConnectedComponents();
    /**
      * Connect current component with specified component
      * @param connectTo component to connect with
      */
    void connect(Component *connectTo);
    /**
      * Disconnect current component with specified component
      * @param connected component from which disconnect
      */
    void disconnect(Component *connected);
};

#endif // COMPONENT_H
