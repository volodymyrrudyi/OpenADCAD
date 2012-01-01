#ifndef DLGPRINCIPALCOMPONENTLIBRARY_H
#define DLGPRINCIPALCOMPONENTLIBRARY_H

#include <QDialog>
#include "xmlcomponentloader.h"
#include "componentinfo.h"

namespace Ui {
    class DlgPrincipalComponentLibrary;
}

class DlgPrincipalComponentLibrary : public QDialog
{
    Q_OBJECT

public:
    explicit DlgPrincipalComponentLibrary(QWidget *parent = 0);
    ~DlgPrincipalComponentLibrary();

private:
    Ui::DlgPrincipalComponentLibrary *ui;

private slots:
    void on_btnChoose_clicked();
};

#endif // DLGPRINCIPALCOMPONENTLIBRARY_H
