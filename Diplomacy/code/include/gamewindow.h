#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "code/include/userswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(MainWindow *parent = nullptr);
    ~GameWindow() {};

    MainWindow *mw;

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
