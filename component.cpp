#include "component.h"

Component::Component()
{
    this->info = NULL;
}

Component::Component(ComponentInfo *info)
{
    this->info = info;

}


Component::~Component()
{


}

QMap<QString, QVariant> Component::getProperties()
{
    return this->properties;
}

void Component::setProperty(const QString& property, const QVariant& value)
{
    this->properties[property] = value;
}

QVariant Component::getProperty(const QString& property)
{
    if (this->properties.find(property) != this->properties.end()){
        return this->properties[property];
    } else {
        QMap<QString, QVariant> &infoProperties = this->info->getProperties();

        if (infoProperties.find(property) != infoProperties.end()){
            return QVariant::fromValue(infoProperties[property]);
        } else {
            return "";
        }
    }
}

ComponentInfo *Component::getInfo()
{
    return this->info;
}

QList<Component*> &Component::getConnectedComponents()
{
    return this->connectedComponents;
}

void Component::connect(Component *connectTo)
{
    this->connectedComponents.push_back(connectTo);
}

void Component::disconnect(Component *connected)
{
    this->connectedComponents.removeOne(connected);
}

