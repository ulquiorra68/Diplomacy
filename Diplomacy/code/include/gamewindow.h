#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "code/include/userswindow.h"
#include "code/include/game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void onAttack();
    void onHelp();
    void onChangePosition();
    void onFinish();
    void onExit();

public:
    GameWindow(MainWindow *parent = nullptr);
    ~GameWindow() {};

    MainWindow *mw;
    Game *game;

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
