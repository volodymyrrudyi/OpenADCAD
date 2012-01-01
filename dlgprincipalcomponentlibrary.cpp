#include "dlgprincipalcomponentlibrary.h"
#include "ui_dlgprincipalcomponentlibrary.h"

DlgPrincipalComponentLibrary::DlgPrincipalComponentLibrary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgPrincipalComponentLibrary)
{
    ui->setupUi(this);
}

DlgPrincipalComponentLibrary::~DlgPrincipalComponentLibrary()
{
    delete ui;
}

void DlgPrincipalComponentLibrary::on_btnChoose_clicked()
{
    XmlComponentLoader loader("/home/volodymyr/work/university/openadcad/lib/library.principal.std.xml");
    QList<ComponentInfo> info;
    loader.loadComponents();
    info = loader.getComponents();

    this->ui->treeWidget->clear();
    for(QList<ComponentInfo>::iterator i = info.begin(); i != info.end(); i++)
    {
        this->ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(
                QStringList((*i).getTypeId())));
    }
}
