#include "code/include/gamewindow.h"
#include "ui_gamewindow.h"
#include "code/include/game.h"

//class Game;

GameWindow::GameWindow(MainWindow *parent) :
    QMainWindow(parent),
    mw(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    connect(ui->attackButton, &QPushButton::clicked, this, &GameWindow::onAttack);
    connect(ui->helpButton, &QPushButton::clicked, this, &GameWindow::onHelp);
    connect(ui->positionButton, &QPushButton::clicked, this, &GameWindow::onChangePosition);
    connect(ui->finishButton, &QPushButton::clicked, this, &GameWindow::onFinish);
    connect(ui->exitButton, &QPushButton::clicked, this, &GameWindow::onExit);

    QPixmap bkgnd(":/images/map.jpg");
    bkgnd = bkgnd.scaled(QSize(1407, 1080), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    std::vector<QPushButton*> territoryButtons;
    for (int i = 0; i < 57; i++)
    {
        QPushButton* pb = new QPushButton("1", this);
        pb->setObjectName("ime");
        pb->setFixedSize(10, 10);
        territoryButtons.push_back(pb);
    }

    game = new Game();
    game->start(territoryButtons);

    ui->nameLabel->setText(QString::fromStdString(game->currPlayer()->name()));
}

void GameWindow::onAttack()
{

}

void GameWindow::onHelp()
{

}

void GameWindow::onChangePosition()
{

}

void GameWindow::onFinish()
{
    game->setCounter((game->getCounter()+1)%(mw->getNumSpinBox()));
    int index = game->getCounter();
    game->setCurrPlayer(game->players()[index]);
    ui->nameLabel->setText(QString::fromStdString(game->currPlayer()->name()));
    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " je sad na potezu");
}

void GameWindow::onExit()
{
    close();
}
