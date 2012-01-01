#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->project = NULL;
    this->createdComponent = NULL;
    this->undoStack = new QUndoStack(this);

    this->ui->tabWidget->setTabText(1,"Principal Scheme");
    this->principalScheme = new AbstractScheme(this->ui->principalSchemeView);
    this->ui->principalSchemeView->setScene(this->principalScheme);

    this->first = NULL;
    this->second = NULL;

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionCreateProject_triggered()
{
    CreateProjectDialog createProject;
    createProject.exec();

}


void MainWindow::on_actionPrincipal_Scheme_Component_Library_triggered()
{
    DlgPrincipalComponentLibrary principalLib;
    principalLib.exec();

}

void MainWindow::on_actionNo_Grid_triggered()
{
   this->principalScheme->showGrid(false);
}

void MainWindow::on_action10x10_Grid_triggered()
{
    this->principalScheme->setGridStep(10);
    this->principalScheme->showGrid(true);
    this->principalScheme->setSnapToGrid(true);
}

void MainWindow::on_action20x20_Grid_triggered()
{
    this->principalScheme->setGridStep(20);
    this->principalScheme->showGrid(true);
    this->principalScheme->setSnapToGrid(true);
}

void MainWindow::on_actionText_triggered()
{
    if (createdComponent != NULL){
        delete createdComponent;
        createdComponent = NULL;
    }
  //  this->createdComponent = new TextComponent(this->principalScheme, "some_text");
}

void MainWindow::on_principalSchemeView_schemeClicked(QPointF pos)
{
    if (createdComponent != NULL)
    {
       this->principalScheme->addItem(createdComponent);
       createdComponent->setPos(createdComponent->mapFromScene(pos));
       cmp = createdComponent;
       createdComponent = NULL;
    }
}

void MainWindow::on_actionRotate_ItemsLeft_triggered()
{
    this->principalScheme->rotateSelected(RotateLeft);
}

void MainWindow::on_actionUndo_Command_triggered()
{
    ApplicationUtils::getUndoStack().undo();
}

void MainWindow::on_actionRedo_Command_triggered()
{
    ApplicationUtils::getUndoStack().redo();
}

void MainWindow::on_toolButton_clicked()
{
    ComponentCommand *command = new
                                ComponentCommand(cmp,
                                                 "text",
                                                 QString("new_value"));

    ApplicationUtils::getUndoStack().push(command);
}

void MainWindow::on_principalSchemeView_componentSelected(GraphicsComponent* selectedComponent)
{
    if (first == NULL){
        statusBar()->showMessage("Selected first");
        first = selectedComponent;
    } else if ((second == NULL) && (first != selectedComponent))
    {
        statusBar()->showMessage("Selected second");
        second = selectedComponent;
    } else
    {
        first = NULL;
        second = NULL;
    }
}

void MainWindow::on_toolButton_2_clicked()
{
//    if ((first != NULL) & (second != NULL))
//    {
//        this->principalScheme->addItem(new WireConnection(this->principalScheme,
//                                                          first, second));
//    } else {
//        statusBar()->showMessage("Select two components!");
//    }
}

void MainWindow::on_actionAlign_Left_triggered()
{
    this->principalScheme->alignSelected(Left);
}

void MainWindow::on_actionAlign_Right_triggered()
{
    this->principalScheme->alignSelected(Right);
}

void MainWindow::on_actionAlign_Top_triggered()
{
    this->principalScheme->alignSelected(Top);
}

void MainWindow::on_actionAlign_Bottom_triggered()
{
    this->principalScheme->alignSelected(Bottom);
}
