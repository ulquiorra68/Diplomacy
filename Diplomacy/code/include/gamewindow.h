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
    void onClear();
    void onHelpAttack();

public:
    GameWindow(MainWindow *parent = nullptr);
    void onTerritoryButton(QPushButton* btn);
    
    ~GameWindow() {};

    MainWindow *mw;
    Game *game;

private:
    Ui::GameWindow *ui;
    int currentMove = 0; // 1 - attack, 2 - help, 3 - move
    Territory* startingTerritory = nullptr;
    Territory* endingTerritory = nullptr;
};

#endif // GAMEWINDOW_H
