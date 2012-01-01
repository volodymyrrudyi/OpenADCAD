#ifndef COMPONENTINFO_H
#define COMPONENTINFO_H



#include <QMap>
#include <QString>
#include <QGraphicsSvgItem>
#include <QVariant>
using namespace std;

enum ComponentType{
    BlockSchemeComponent = 1,
    PrincipalSchemeComponent = 2,
    BoardSchemeComponent = 4
};

//! Holds information about component
/**
  * Holds information about component. Used by component classes to
  * hold default values of properties.
  */
class ComponentInfo
{
    /**
      * Map with properties and their default values
      */
    QMap<QString, QVariant>  properties;
    /**
      * Type of the component
      */
    ComponentType type;
    /**
      * String with type name of the component
      */
    QString typeId;
public:
    /**
      * Default constructor
      */
    ComponentInfo();
    /**
      * Creates ComponentInfo with specified parameters
      * @param typeId string with type name
      * @param type component type
      * @param properties properties of component
      */
    ComponentInfo(QString typeId, ComponentType type,
                  const QMap<QString,QVariant> &properties);
    /**
      * Returns properties of the component
      * @return Map with properties
      */
    QMap<QString, QVariant> &getProperties();
    /**
      * Returns string with type name
      * @return string with type name
      */
    QString getTypeId() const;
};

#endif // COMPONENTINFO_H
