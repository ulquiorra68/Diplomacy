#include "code/include/userswindow.h"
#include "ui_userswindow.h"

void UsersWindow::onOk()
{

}


void UsersWindow::onBack()
{
    this->close();
}

UsersWindow::UsersWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::UsersWindow),
    mw(parent)
{
    ui->setupUi(this);

//    connect(ui->back_button_3, &QPushButton::clicked, this, &UsersWindow::onBack);
//    connect(ui->ok_button_3, &QPushButton::clicked, this, &UsersWindow::onOk);
}

UsersWindow::~UsersWindow()
{
    delete ui;
}
