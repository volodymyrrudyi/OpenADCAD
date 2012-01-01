#ifndef ABSTRACTSCHEME_H
#define ABSTRACTSCHEME_H

#include <QGraphicsScene>
#include "component.h"
#include <QVarLengthArray>
#include <QMouseEvent>
#include <QPainter>
#include "graphicscomponent.h"
#include "applicationutils.h"
#include "componentcommand.h"

#include <QStyle>

class GraphicsComponent;

enum AlignmentType{
    Left, Right, Top, Bottom
};

enum RotationDirection{
    RotateLeft, RotateRight
};

//! Abstract class that implements common features for all schemes
/**
  Abstract class that implements common features for all schemes - grid drawing,
  snapping and so on.
  */
class AbstractScheme: public QGraphicsScene
{

    Q_OBJECT
private:
   /**
     * Indicates that snapping is enabled
     */
   bool snapToGrid;
   /**
     * Controls visibility of a grid
     */
   bool gridVisible;
   /**
     * Step of the grid
     */
   int gridStep;
   /**
     * Color of the grid
     */
   QColor gridColor;
   public:
   /**
     * Default constructor
     */
    AbstractScheme();
    /**
      * Constructs scheme with specified parent
      * @param parent parent component
      */
    AbstractScheme(QObject *parent);
    /**
      * Enables or disables grid snapping
      * @param enabled state of the grid snapping
      */
    void setSnapToGrid(bool enabled);
    /**
      * Returns state of snapping mode
      * @return state of the snapping mode
      */
    bool getSnapToGrid();
    /**
      * Sets step of the grid
      * @param value value of the step
      */
    void setGridStep(int vaue);
    /**
      * Returns size of the grid step
      * @return grid step size
      */
    int getGridStep();
    /**
      * Sets color of the grid
      * color color of the grid
      */
    void setGridColor(QColor color);
    /**
      * Returns color of the grid
      * @return grid color
      */
    QColor getGridColor();
    /**
      * Enables or disables grid
      * @param show grid visibility
      */
    void showGrid(bool show);
    /**
      * Rotates selected components
      * @param direction RotationDirection
      */
    void rotateSelected(RotationDirection direction);
    /**
      * @param alignment alignment type
      */
    void alignSelected(AlignmentType alignment);


    virtual void drawBackground( QPainter * painter, const QRectF & rect );
public slots:


signals:





};

#endif // ABSTRACTSCHEME_H
