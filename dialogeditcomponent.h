#ifndef DIALOGEDITCOMPONENT_H
#define DIALOGEDITCOMPONENT_H

#include <QDialog>
#include "component.h"

namespace Ui {
    class DialogEditComponent;
}

class DialogEditComponent : public QDialog
{
    Q_OBJECT
    Component *component;

public:
    explicit DialogEditComponent(QWidget *parent = 0);
    ~DialogEditComponent();

    void setComponent(Component *component);
private:
    Ui::DialogEditComponent *ui;
};

#endif // DIALOGEDITCOMPONENT_H
