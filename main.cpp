#include "QApplication"
#include "mainwindow.h"
#include "createprojectdialog.h"
int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MainWindow window;

    window.show();
    return a.exec();
}
