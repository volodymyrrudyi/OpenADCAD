#include "textcomponent.h"

TextComponent::TextComponent(AbstractScheme *parent)
    : GraphicsComponent(parent)
{
    this->textItem = new QGraphicsTextItem(this);

}

TextComponent::TextComponent(AbstractScheme *parent, QString value)
    : GraphicsComponent(parent)
{
    this->properties.insert("text", value);
    this->textItem = new QGraphicsTextItem(value, this);
    this->addToGroup(this->textItem);
}

void TextComponent::setProperty(const QString &property, const QVariant &value)
{
    if (property == "text"){
        this->textItem->setPlainText(value.toString());
    }
    GraphicsComponent::setProperty(property, value);
}

