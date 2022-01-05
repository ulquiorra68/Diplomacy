#include "code/include/userswindow.h"
#include "ui_userswindow.h"
#include "code/include/gamewindow.h"
#include "code/include/player.h"

class Player;

void UsersWindow::onOk()
{
    QVector<Player *> players;

    Player* p1;// = new Player();
    Player* p2;// = new Player();
    Player* p3;// = new Player();

    if (ui->lineEdit->text() != "")
    {
        p1 = new Player((ui->lineEdit->text()).toStdString(), Red, false);
    }
    else
    {
        p1 = new Player("Player1", Red, false);
    }


    if (ui->lineEdit_2->text() != "")
    {
        p2 = new Player((ui->lineEdit_2->text()).toStdString(), Green, false);
    }
    else
    {
        p2 = new Player("Player2", Green, false);
    }


    if (ui->lineEdit_3->text() != "")
    {
        p3 = new Player((ui->lineEdit_3->text()).toStdString(), Blue, false);
    }
    else
    {
        p3 = new Player("Player3", Blue, false);
    }

    players.insert(0, p1);
    players.insert(1, p2);
    players.insert(2, p3);

    if (ui->lineEdit_4->isEnabled())
    {
        Player *p4 = new Player();
        if (ui->lineEdit_4->text() != "")
        {
            p4 = new Player((ui->lineEdit_4->text()).toStdString(), Yellow, false);
        }
        else
        {
            p4 = new Player("Player4", Yellow, false);
        }
        players.insert(3, p4);
    }

    if (ui->lineEdit_5->isEnabled())
    {
        Player *p5 = new Player();
        if (ui->lineEdit_5->text() != "")
        {
            p5 = new Player((ui->lineEdit_5->text()).toStdString(), Cyan, false);
        }
        else
        {
            p5 = new Player("Player5", Cyan, false);
        }
        players.insert(4, p5);
    }

    if (ui->lineEdit_6->isEnabled())
    {
        Player *p6 = new Player();
        if (ui->lineEdit_6->text() != "")
        {
            p6 = new Player((ui->lineEdit_6->text()).toStdString(), Black, false);
        }
        else
        {
            p6 = new Player("Player6", Black, false);
        }
        players.insert(5, p6);
    }

    if (ui->lineEdit_7->isEnabled())
    {
        Player *p7 = new Player();
        if (ui->lineEdit_7->text() != "")
        {
            p7 = new Player((ui->lineEdit_7->text()).toStdString(), White, false);
        }
        else
        {
            p7 = new Player("Player7", White, false);
        }
        players.insert(6, p7);
    }
    setPlayers(players);

    p_ready = true;
    delete this;
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

    p_ready = false;

    connect(ui->cancel_button, &QPushButton::clicked, this, &UsersWindow::onCancel);
    connect(ui->ok_button, &QPushButton::clicked, this, &UsersWindow::onOk);

    int numOfPlayers = parent->getNumSpinBox();
    if (numOfPlayers == 3)
    {
        ui->lineEdit_4->setDisabled(true);
        ui->lineEdit_5->setDisabled(true);
        ui->lineEdit_6->setDisabled(true);
        ui->lineEdit_7->setDisabled(true);
    }
    else if (numOfPlayers == 4)
    {
        ui->lineEdit_5->setDisabled(true);
        ui->lineEdit_6->setDisabled(true);
        ui->lineEdit_7->setDisabled(true);
    }
    else if (numOfPlayers == 5)
    {
        ui->lineEdit_6->setDisabled(true);
        ui->lineEdit_7->setDisabled(true);
    }
    else if (numOfPlayers == 6)
    {
        ui->lineEdit_7->setDisabled(true);
    }
}

UsersWindow::~UsersWindow()
{
    delete ui;
}

const QVector<Player*> &UsersWindow::players() const
{
    return p_players;
}

void UsersWindow::setPlayers(const QVector<Player *> &newPlayers)
{
    p_players = newPlayers;
}
