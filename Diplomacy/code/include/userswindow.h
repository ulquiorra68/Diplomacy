#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QDialog>
#include "code/include/player.h"
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

    const QVector<Player*> &players() const;
    void setPlayers(const QVector<Player *> &newPlayers);

    bool ready() { return p_ready; };
    void setReady(bool flag) { p_ready = flag; };

    int getNumSpinBox();

private:
    Ui::UsersWindow *ui;
    MainWindow* mw;

    QVector<Player*> p_players;

    bool p_ready;

    int numSpinBox;
};
#endif // USERSWINDOW_H
