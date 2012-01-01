#ifndef TEXTCOMPONENT_H
#define TEXTCOMPONENT_H

#include "graphicscomponent.h"
#include <QString>
#include <QGraphicsTextItem>

//! Text label component
/**
  * Let`s user to add text labels to the schemes
  */
class TextComponent : public  virtual GraphicsComponent
{
    /**
      * Pointer to QGraphicsTextItem that holds text
      */
    QGraphicsTextItem *textItem;

protected:
    /**
      * Constructs TextComponent with specified parent
      * @param parent parent scheme
      */
    TextComponent(AbstractScheme* parent);
    /**
      * Constructs TextComponent with specified parent and text
      * @param parent scheme
      * @param text text
      */
    TextComponent(AbstractScheme* parent, QString value);
    /**
      * Sets property of the component
      * @param property property name
      * @param value property value
      */
public:

    virtual void setProperty(const QString &property, const QVariant &value);
};

#endif // TEXTCOMPONENT_H
