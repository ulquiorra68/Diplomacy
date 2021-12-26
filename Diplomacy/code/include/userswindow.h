#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QDialog>
#include "code/include/mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UsersWindow; }
QT_END_NAMESPACE

class UsersWindow : public QDialog
{
    Q_OBJECT

public slots:
    void onOk();
    void onCancel();

public:
    UsersWindow(MainWindow *parent = nullptr);
    ~UsersWindow();


private:
    Ui::UsersWindow *ui;
    MainWindow* mw;
};
#endif // USERSWINDOW_H
