#include "componentinfo.h"

ComponentInfo::ComponentInfo()
{

}


ComponentInfo::ComponentInfo(QString typeId, ComponentType type,
                             const QMap<QString, QVariant> &properties)
{
    this->properties = properties;
    this->type = type;
    this->typeId = typeId;
}

QMap<QString, QVariant> &ComponentInfo::getProperties()
{
    return this->properties;
}

QString ComponentInfo::getTypeId() const
{
    return this->typeId;
}

