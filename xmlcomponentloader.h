#ifndef XMLCOMPONENTLOADER_H
#define XMLCOMPONENTLOADER_H

#include "componentloader.h"
#include <list>
using namespace std;
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QFile>
#include <QString>

//! Class for loading components from the XML libraries
/**
  * Loads components from XML libraries
  */
class XmlComponentLoader: public ComponentLoader
{
    /**
      * DOM object of the library
      */
    QDomDocument library;
    /**
      * Library author name
      */
    QString author;
    /**
      * Library descritption
      */
    QString description;
    /**
      * Mask of component types in a library
      */
    ComponentType componentTypes;
    /**
      * Default constructor
      */
    XmlComponentLoader();
    /** Returns component type by a string
      * @param typeId string with type name
      */
    static ComponentType GetType(QString typeId);

public:
    /**
      * Constructs XmlComponentLoader to load specified library
      * @param filename library file name
      */
    XmlComponentLoader(QString filename);
    /**
      * Loads components
      *
      */
    void loadComponents();
    /**
      * Frees components
      */
    void freeComponents();
    /** Returns library description
      * @return library description
      */
    QString getDescription() const;
    /** Returns library author
      * @return library author
      */
    QString getAuthor() const;
    /** Returns library components type
      * @return library components type
      */
    ComponentType getComponentsType() const;

};

#endif // XMLCOMPONENTLOADER_H
