#include "code/include/numberwindow.h"
#include "ui_numberwindow.h"
#include "code/include/userswindow.h"

void NumberWindow::onOk()
{
    numSpinBox = (ui->numberSpinBox)->value();

    UsersWindow* uw = new UsersWindow(this);
    uw->setWindowFlags(Qt::CustomizeWindowHint);
    uw->exec();
}


void NumberWindow::onBack()
{
    delete this;
}

NumberWindow::NumberWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::NumberWindow),
    mw(parent)
{
    ui->setupUi(this);

    connect(ui->back_button, &QPushButton::clicked, this, &NumberWindow::onBack);
    connect(ui->ok_button, &QPushButton::clicked, this, &NumberWindow::onOk);

    p_ready = false;
}

NumberWindow::~NumberWindow()
{
    delete ui;
}

int NumberWindow::getNumSpinBox()
{
    return numSpinBox;
}

bool NumberWindow::ready() const
{
    return p_ready;
}

void NumberWindow::setReady(bool flag)
{
    p_ready = flag;
}
