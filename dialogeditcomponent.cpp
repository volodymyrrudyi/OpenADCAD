#include "dialogeditcomponent.h"
#include "ui_dialogeditcomponent.h"

DialogEditComponent::DialogEditComponent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditComponent)
{
    ui->setupUi(this);
}

DialogEditComponent::~DialogEditComponent()
{
    delete ui;
}

void DialogEditComponent::setComponent(Component *component)
{
    this->component = component;
    this->ui->leName->setText(component->getProperty("name").toString());
    this->ui->twProperties->setColumnCount(2);
    QStringList labelList;
    labelList.append("Property");
    labelList.append("Value");
    this->ui->twProperties->setHorizontalHeaderLabels(labelList);

    for(QMap<QString, QVariant>::iterator i = component->getInfo()->getProperties().begin();
    i != component->getInfo()->getProperties().end(); i++)
    {
        QTableWidgetItem *propItem = new QTableWidgetItem();
        propItem->setText(i.key());
        QTableWidgetItem *valItem = new QTableWidgetItem();
        valItem->setText(component->getProperty(i.key()).toString());
        this->ui->twProperties->insertRow(this->ui->twProperties->rowCount());
        this->ui->twProperties->setItem(this->ui->twProperties->rowCount() -1, 0, propItem);
        this->ui->twProperties->setItem(this->ui->twProperties->rowCount() -1, 1, valItem);
    }


}
