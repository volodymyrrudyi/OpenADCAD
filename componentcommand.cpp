#include "componentcommand.h"

ComponentCommand::ComponentCommand(Component *component,
                                   const QString &propertyName,
                                   const QVariant &newValue)
{
    this->component = component;
    this->oldValue = component->getProperty(propertyName);
    this->newValue = newValue;
    this->propertyName = propertyName;
}


void ComponentCommand::undo()
{
    component->setProperty(this->propertyName, this->oldValue);
}

void ComponentCommand::redo()
{
    component->setProperty(this->propertyName, this->newValue);
}
