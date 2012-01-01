#ifndef COMPONENTLOADER_H
#define COMPONENTLOADER_H

#include "componentinfo.h"
#include <QList>
#include <QString>
using namespace std;

//! Abstract base class for component loading classes
/**
  * Abstract base class for component loading classes
  */
class ComponentLoader{
protected:
    /**
      * Loaded components
      */
    QList<ComponentInfo> components;
public:
    /**
      * Returns list of loaded components
      * @return list of loaded components
      */
    QList<ComponentInfo> getComponents() const;
    /**
      * Loads components
      */
    virtual void loadComponents() = 0;
    /**
      * Free`s previously loaded components
      */
    virtual void freeComponents() = 0;
    /**
      * Returns description of the library
      * @return description of the library
      */
    virtual QString getDescription() const = 0;
    /**
      * Returns library author name
      * @return author name
      */
    virtual QString getAuthor() const = 0 ;
};

#endif // COMPONENTLOADER_H
