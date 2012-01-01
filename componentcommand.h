#ifndef COMPONENTCOMMAND_H
#define COMPONENTCOMMAND_H

#include <QUndoCommand>
#include <QString>
#include <QVariant>
#include "component.h"

//! Implements command for particular Component
/**
  * Implements command for particular Component
  */
class ComponentCommand : public QUndoCommand
{
    /**
      * Old value of the component`s property value
      */
    QVariant oldValue;
    /**
      * New value of the component`s property value
      */
    QVariant newValue;
    /**
      * Name of the property being changed
      */
    QString propertyName;
    /**
      * Pointer to the component being changed
      */
    Component *component;
public:
    explicit ComponentCommand(Component* component,
                              const QString &propertyName,
                              const QVariant &newValue);
    /**
      * Implementation of the undo method
      */
    void undo();
    /**
      * Implementation of the redo method
      */
    void redo();

signals:

public slots:

};

#endif // COMPONENTCOMMAND_H
