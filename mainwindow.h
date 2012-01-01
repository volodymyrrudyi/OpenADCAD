#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>
#include <QBrush>
#include "project.h"
#include "createprojectdialog.h"
#include "graphicscomponent.h"
#include "dlgprincipalcomponentlibrary.h"
#include "dialogeditcomponent.h"
#include "textcomponent.h"
#include "componentcommand.h"
#include "applicationutils.h"
#include "wireconnection.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    TextComponent *text;
    Ui::MainWindow *ui;
    Project* project;

    GraphicsComponent *createdComponent;
    GraphicsComponent *cmp;
    AbstractScheme *principalScheme;
    QUndoStack *undoStack;

    GraphicsComponent *first;
    GraphicsComponent *second;
private slots:


private slots:

    void on_actionAlign_Bottom_triggered();
    void on_actionAlign_Top_triggered();
    void on_actionAlign_Right_triggered();
    void on_actionAlign_Left_triggered();
    void on_toolButton_2_clicked();
    void on_principalSchemeView_componentSelected(GraphicsComponent*selectedComponent);
    void on_toolButton_clicked();
    void on_actionRedo_Command_triggered();
    void on_actionUndo_Command_triggered();
    void on_actionRotate_ItemsLeft_triggered();
    void on_principalSchemeView_schemeClicked(QPointF pos);
    void on_actionText_triggered();
    void on_action20x20_Grid_triggered();
    void on_action10x10_Grid_triggered();
    void on_actionNo_Grid_triggered();
    void on_actionPrincipal_Scheme_Component_Library_triggered();
    void on_actionCreateProject_triggered();
};

#endif // MAINWINDOW_H
