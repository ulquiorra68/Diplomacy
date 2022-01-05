#include "code/include/gamewindow.h"
#include "ui_gamewindow.h"
#include "code/include/game.h"

class Game;

GameWindow::GameWindow(MainWindow *parent) :
    QMainWindow(parent),
    mw(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/images/map.jpg");
    bkgnd = bkgnd.scaled(QSize(1920, 1080), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    vector<QPushButton*> territoryButtons;
    for (int i = 0; i < 57; i++)
    {
        QPushButton* pb = new QPushButton();
        pb->show();
        pb->setVisible(true);
        pb->setObjectName("ime");
        pb->setFixedSize(100, 100);
        territoryButtons.push_back(pb);
    }

    Game* game = new Game();
    game->start(territoryButtons);


}
