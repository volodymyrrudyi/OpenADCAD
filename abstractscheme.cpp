#include "abstractscheme.h"

AbstractScheme::AbstractScheme()
{

}

AbstractScheme::AbstractScheme(QObject *parent) : QGraphicsScene(parent)
{
    this->setGridStep(32);
    this->setSnapToGrid(false);
    this->setGridColor(qRgb(150,150,150));

    connect(this, SIGNAL(selectionChanged()), parent, SLOT(selectionChanged()));
}

void AbstractScheme::setGridColor(QColor color)
{
    this->gridColor = color;
}

QColor AbstractScheme::getGridColor()
{
    return this->gridColor;
}

void AbstractScheme::setSnapToGrid(bool enabled)
{
    this->snapToGrid = enabled;
}

bool AbstractScheme::getSnapToGrid()
{
    return this->snapToGrid;
}

void AbstractScheme::setGridStep(int value)
{
    this->gridStep = value;

}

int AbstractScheme::getGridStep()
{
    return this->gridStep;

}

void AbstractScheme::drawBackground(QPainter *painter, const QRectF &rect)
{
    if (this->gridVisible)
    {

        int gridInterval = this->getGridStep();
        painter->setWorldMatrixEnabled(true);

        QPen pen;
        pen.setColor(this->getGridColor());
        pen.setStyle(Qt::DotLine);
        painter->setPen(pen);

        qreal left = int(rect.left()) - (int(rect.left()) % gridInterval );
        qreal top = int(rect.top()) - (int(rect.top()) % gridInterval );

        QVarLengthArray<QLineF, 100> linesX;
        for (qreal x = left; x < rect.right(); x += gridInterval )
        linesX.append(QLineF(x, rect.top(), x, rect.bottom()));


        QVarLengthArray<QLineF, 100> linesY;
        for (qreal y = top; y < rect.bottom(); y += gridInterval )
        linesY.append(QLineF(rect.left(), y, rect.right(), y));

        painter->drawLines(linesX.data(), linesX.size());
        painter->drawLines(linesY.data(), linesY.size());


    }
}

void AbstractScheme::showGrid(bool show)
{
    this->gridVisible = show;
    this->invalidate();
}

void AbstractScheme::rotateSelected(RotationDirection direction)
{
    QList<QGraphicsItem*> items = this->selectedItems();
    switch(direction){
    case RotateLeft:
        ApplicationUtils::getUndoStack().beginMacro("rotate_left");
        for(QList<QGraphicsItem*>::iterator i = items.begin(); i != items.end(); i++)
        {
           GraphicsComponent *current = (GraphicsComponent*)*i;
           ComponentCommand *command = new ComponentCommand(
                   current, "angle",
                   QVariant(current->getProperty("angle").toDouble() + 90));

           ApplicationUtils::getUndoStack().push(command);
        }
        ApplicationUtils::getUndoStack().endMacro();
        break;
    }
}

void AbstractScheme::alignSelected(AlignmentType alignment)
{
    if (this->selectedItems().count() == 0)
    {
        return;
    }
    QList<QGraphicsItem*> items = this->selectedItems();
    switch(alignment){
    case Left:{
            qreal minLeft = items.at(0)->x();

            for(QList<QGraphicsItem*>::iterator i = items.begin(); i != items.end(); i++)
            {
                if ((*i)->x() < minLeft)
                {
                    minLeft = (*i)->x();
                }
            }

            ApplicationUtils::getUndoStack().beginMacro("align left");
            for(QList<QGraphicsItem*>::iterator i = items.begin(); i != items.end(); i++)
            {
                GraphicsComponent *current = (GraphicsComponent*)*i;
                ApplicationUtils::getUndoStack()
                        .push(new ComponentCommand(current, "x",
                                                    QVariant(minLeft)));
            }
            ApplicationUtils::getUndoStack().endMacro();

            break;
        }
    case Right:{
            qreal maxLeft = items.at(0)->x();
            for(QList<QGraphicsItem*>::iterator i = items.begin(); i != items.end(); i++)
            {
                if ((*i)->x() > maxLeft)
                {
                    maxLeft = (*i)->x();
                }
            }

            ApplicationUtils::getUndoStack().beginMacro("align right");
            for(QList<QGraphicsItem*>::iterator i = items.begin(); i != items.end(); i++)
            {
                GraphicsComponent *current = (GraphicsComponent*)*i;
                ApplicationUtils::getUndoStack()
                        .push(new ComponentCommand(current, "x",
                                                    QVariant(maxLeft)));
            }
            ApplicationUtils::getUndoStack().endMacro();

            break;
        }
    case Top:{
            qreal minTop = items.at(0)->y();

            for(QList<QGraphicsItem*>::iterator i = items.begin(); i != items.end(); i++)
            {
                if ((*i)->y() < minTop)
                {
                    minTop = (*i)->y();
                }
            }

            ApplicationUtils::getUndoStack().beginMacro("align top");
            for(QList<QGraphicsItem*>::iterator i = items.begin(); i != items.end(); i++)
            {
                GraphicsComponent *current = (GraphicsComponent*)*i;
                ApplicationUtils::getUndoStack()
                       .push(new ComponentCommand(current, "y",
                                                    QVariant(minTop)));
            }
            ApplicationUtils::getUndoStack().endMacro();

            break;
        }
    case Bottom:{
            qreal maxTop = items.at(0)->y();

            for(QList<QGraphicsItem*>::iterator i = items.begin(); i != items.end(); i++)
            {
                if ((*i)->y() > maxTop)
                {
                    maxTop = (*i)->y();
                }
            }

            ApplicationUtils::getUndoStack().beginMacro("alignbottom");
            for(QList<QGraphicsItem*>::iterator i = items.begin(); i != items.end(); i++)
            {
                GraphicsComponent *current = (GraphicsComponent*)*i;
                ApplicationUtils::getUndoStack()
                        .push(new ComponentCommand(current, "y",
                                                   QVariant(maxTop)));
            }
            ApplicationUtils::getUndoStack().endMacro();
            break;
        }
        break;
    default:
        break;
    }
}

