#include "code/include/userswindow.h"
#include "ui_userswindow.h"

void UsersWindow::onOk()
{

}


void UsersWindow::onCancel()
{
    delete this;
}

UsersWindow::UsersWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::UsersWindow),
    mw(parent)
{
    ui->setupUi(this);

    connect(ui->cancel_button, &QPushButton::clicked, this, &UsersWindow::onCancel);
    connect(ui->ok_button, &QPushButton::clicked, this, &UsersWindow::onOk);
}

UsersWindow::~UsersWindow()
{
    delete ui;
}
