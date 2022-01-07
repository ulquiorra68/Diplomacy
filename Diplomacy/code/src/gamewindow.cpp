#include "code/include/gamewindow.h"
#include "ui_gamewindow.h"
#include "code/include/game.h"
#include <stdlib.h>
#include <string>

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
    connect(ui->clearButton, &QPushButton::clicked, this, &GameWindow::onClear);
    connect(ui->helpAttackButton, &QPushButton::clicked, this, &GameWindow::onHelpAttack);

    QPixmap bkgnd(":/images/map.jpg");
    bkgnd = bkgnd.scaled(QSize(1920, 1080), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    
    for (int i = 0; i < 57; i++)
    {
        QPushButton* pb = new QPushButton("1", this);
        pb->setObjectName("ime" + QString::fromStdString(std::to_string(i)));
        pb->setFixedSize(10, 10);
        connect(pb, &QPushButton::clicked, this, std::bind(&GameWindow::onTerritoryButton, this, pb));
        territoryButtons.push_back(pb);
    }

    game = new Game();
    QVector<Player*> qplrs = mw->players();
    game->setPlayers(qplrs);
    game->start(territoryButtons);

    ui->nameLabel->setAlignment(Qt::AlignCenter);
    ui->nameLabel->setText("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    ui->nameLabel->setText(ui->nameLabel->text() + QString::fromStdString(mw->players()[0]->name()) + "[" + QString::fromStdString(mw->players()[0]->GetNationalBelongingText()) + "][" + QString::fromStdString(mw->players()[0]->GetColorText()) + "]");
    ui->nameLabel->setText(ui->nameLabel->text() + "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    ui->logLabel->setText("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~log~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    ui->logLabel->setAlignment(Qt::AlignTop);
}

void GameWindow::onTerritoryButton(QPushButton* btn)
{
    if (ui->logLabel->text().size() > 1200)
    {
        ui->logLabel->clear();
        ui->logLabel->setText("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~log~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
    if (currentMove != 0)
    {
        std::unordered_set<Territory*> territories = game->getTerritories();
        Territory* clickedTerritory;

        for (Territory* terr : territories)
        {
            if (QString::fromStdString(terr->GetName()) == btn->objectName())
            {
                clickedTerritory = terr;
                break;
            }
        }

        if (!startingTerritory)
        {
            if (clickedTerritory->GetPlayerBelonging() == game->currPlayer() && clickedTerritory->numOfTanks() > 0 && !game->currPlayer()->isArmyMoveAlreadyMade(clickedTerritory))
            {
                startingTerritory = clickedTerritory;
                endingTerritory = nullptr;

                if (currentMove == 1)
                    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da NAPADNE iz: " + btn->objectName());
                if (currentMove == 2)
                    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da POMOGNE iz: " + btn->objectName());
                if (currentMove == 3)
                    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da SE POVUCE iz: " + btn->objectName());
                if (currentMove == 4)
                    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da NAPADNE (pomocni napad) iz: " + btn->objectName());

                ui->logLabel->setText(ui->logLabel->text() + "\nOdaberite finalnu destinaciju.");
            }
            else
            {
                ui->logLabel->setText(ui->logLabel->text() + "\nNa odabranoj teritoriji igrac nema svoju vojsku. Odaberite teritoriju na kojoj imate vojsku.");
            }
        }
        else if (!endingTerritory)
        {
            if (!startingTerritory->isBoarder(clickedTerritory))
            {
                ui->logLabel->setText(ui->logLabel->text() + "\nOdabrana teritorija se ne granici sa pocetnom. Izaberite teritoriju koja se granici sa " + btn->objectName());
            }
            else
            {
                if (clickedTerritory->GetPlayerBelonging() == game->currPlayer() && currentMove == 1)
                {
                    ui->logLabel->setText(ui->logLabel->text() + "\nNe mozete napasti svoju teritoriju! Izaberite protivnicku teritoriju ili promenite potez.");
                }
                else if (clickedTerritory->GetPlayerBelonging() == game->currPlayer() && currentMove == 2)
                {
                    ui->logLabel->setText(ui->logLabel->text() + "\nNe mozete POMOCI svojoj teritoriji! Izaberite tudju teritoriju ili promenite potez.");
                }
                else if (clickedTerritory->GetPlayerBelonging() != game->currPlayer() && currentMove == 3)
                {
                    ui->logLabel->setText(ui->logLabel->text() + "\nNe mozete se POVUCI na protivnicku teritoriju! Izaberite svoju teritoriju ili promenite potez.");
                }
                if (clickedTerritory->GetPlayerBelonging() == game->currPlayer() && currentMove == 4)
                {
                    ui->logLabel->setText(ui->logLabel->text() + "\nNe mozete napasti(pomocni napad) svoju teritoriju! Izaberite protivnicku teritoriju ili promenite potez.");
                }
                else if (clickedTerritory->GetPlayerBelonging() == game->currPlayer() && currentMove == 3 && clickedTerritory->numOfTanks() > 0)
                {
                    ui->logLabel->setText(ui->logLabel->text() + "\nNa odabranoj teritoriji vec imate vojsku! Izaberite drugu teritoriju ili promenite potez.");
                }
                else
                {
                    endingTerritory = clickedTerritory;

                    game->currPlayer()->addMove(startingTerritory, endingTerritory, currentMove);

                    if (currentMove == 1)
                        ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) +
                            " NAPADA iz: " + QString::fromStdString(startingTerritory->GetName()) + " u: " + btn->objectName());
                    if (currentMove == 2)
                        ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) +
                            " POMAZE iz: " + QString::fromStdString(startingTerritory->GetName()) + " u: " + btn->objectName());
                    if (currentMove == 3)
                        ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) +
                            " SE POVLACI iz: " + QString::fromStdString(startingTerritory->GetName()) + " u: " + btn->objectName());
                    if (currentMove == 4)
                        ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) +
                            " NAPADA(pomocni napad) iz: " + QString::fromStdString(startingTerritory->GetName()) + " u: " + btn->objectName());

                    startingTerritory = nullptr;
                    endingTerritory = nullptr;
                }
            }
        }
        else
        {
            startingTerritory = clickedTerritory;
            endingTerritory = nullptr;

            if (currentMove == 1)
                ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da NAPADNE iz:" + btn->objectName());
            if (currentMove == 2)
                ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da POMOGNE iz:" + btn->objectName());
            if (currentMove == 3)
                ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da SE POVUCE iz:" + btn->objectName());

            ui->logLabel->setText(ui->logLabel->text() + "\nOdaberite finalnu destinaciju.");
        }
        
    }
    else
    {
        ui->logLabel->setText(ui->logLabel->text() + "\nOdaberite zeljenu akciju klikom na dugme za napad, pomoc ili povlacenje.");
    }
    
}

void GameWindow::onAttack()
{
    if (ui->logLabel->text().size() > 1200)
    {
        ui->logLabel->clear();
        ui->logLabel->setText("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~log~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da napadne.");
    currentMove = 1;
    startingTerritory = nullptr;
    endingTerritory = nullptr;
}

void GameWindow::onHelp()
{
    if (ui->logLabel->text().size() > 1200)
    {
        ui->logLabel->clear();
        ui->logLabel->setText("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~log~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da pomogne.");
    currentMove = 2;
    startingTerritory = nullptr;
    endingTerritory = nullptr;
}

void GameWindow::onChangePosition()
{
    if (ui->logLabel->text().size() > 1200)
    {
        ui->logLabel->clear();
        ui->logLabel->setText("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~log~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da pomeri vojsku.");
    currentMove = 3;
    startingTerritory = nullptr;
    endingTerritory = nullptr;
}

void GameWindow::onFinish()
{
   // if (ui->logLabel->text().size() > 700)
    ui->logLabel->clear();
    ui->logLabel->setText("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~log~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    
    int index;
    while (true)
    {
        game->setCounter((game->getCounter() + 1) % (mw->getNumSpinBox()));
        index = game->getCounter();
        game->setCurrPlayer(mw->players()[index]);
        if (!mw->players()[index]->territories().empty())
            break;
    }
    
    if (index == 0)
    {
        ui->logLabel->setText(ui->logLabel->text() + "\nSvi igraci su zavrsili potez! \n");
        ui->nameLabel->setText("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        ui->nameLabel->setText(ui->nameLabel->text() + QString::fromStdString(mw->players()[0]->name()) + "[" + QString::fromStdString(mw->players()[0]->GetNationalBelongingText()) + "][" + QString::fromStdString(mw->players()[0]->GetColorText()) + "]");
        ui->nameLabel->setText(ui->nameLabel->text() + "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        std::string WarLogs = game->resolveWars();
        ui->logLabel->setText(ui->logLabel->text() + QString::fromStdString(WarLogs));

        int remainingPlayers = 0;
        Player* possibleWinner;
        for (Player* pl : game->players())
        {
            if (!pl->territories().empty())
            {
                if (pl->getNumOfAllTanks() == 0)
                {
                    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(pl->name()) + " je izgubio!");
                    pl->performLosing();
                    game->setTerritoriesColor();
                    pl = nullptr;
                    mw->setPlayers(game->players());
                }
                else
                {
                    remainingPlayers++;
                    possibleWinner = pl;
                }
            }
        }
        if (remainingPlayers == 1)
        {
            game->performWin(possibleWinner);
            ui->logLabel->clear();
            ui->logLabel->setText("~~~~~~~~~~~~~~~~~~~~~~~~~~~~log~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            ui->logLabel->setText(ui->logLabel->text() + "\nCESTITKE!!!\nIgrac " + QString::fromStdString(possibleWinner->name()) + " je POBEDNIK!!!");

            ui->attackButton->setDisabled(true);
            ui->helpButton->setDisabled(true);
            ui->helpAttackButton->setDisabled(true);
            ui->positionButton->setDisabled(true);
            ui->finishButton->setDisabled(true);
            ui->clearButton->setDisabled(true);

            for (QPushButton* btn : territoryButtons)
            {
                btn->setDisabled(true);
            }


        }
    }
    else
    {
        ui->nameLabel->setText("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        ui->nameLabel->setText(ui->nameLabel->text() + QString::fromStdString(game->currPlayer()->name()) + "[" + QString::fromStdString(game->currPlayer()->GetNationalBelongingText()) + "][" + QString::fromStdString(game->currPlayer()->GetColorText()) + "]");
        ui->nameLabel->setText(ui->nameLabel->text() + "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " je sad na potezu");
    }
    currentMove = 0;
    startingTerritory = nullptr;
    endingTerritory = nullptr;

}

void GameWindow::onExit()
{
    close();
}

void GameWindow::onClear()
{
    game->currPlayer()->removeAllMoves();
    ui->logLabel->clear();
    ui->logLabel->setText("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~log~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " je izbrisao sve poteze!");
}

void GameWindow::onHelpAttack()
{

    if (ui->logLabel->text().size() > 1200)
    {
        ui->logLabel->clear();
        ui->logLabel->setText("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~log~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
    ui->logLabel->setText(ui->logLabel->text() + "\nIgrac " + QString::fromStdString(game->currPlayer()->name()) + " zeli da napadne (pomocni napad).");
    currentMove = 4;
    startingTerritory = nullptr;
    endingTerritory = nullptr;

}
