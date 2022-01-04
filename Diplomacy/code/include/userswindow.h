#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QDialog>
#include "code/include/numberwindow.h"
#include "code/include/player.h"

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
    UsersWindow(NumberWindow *parent = nullptr);
    ~UsersWindow();

    const QVector<Player*> &players() const;
    void setPlayers(const QVector<Player *> &newPlayers);

private:
    Ui::UsersWindow *ui;
    NumberWindow* nw;

    QVector<Player*> p_players;
};
#endif // USERSWINDOW_H
