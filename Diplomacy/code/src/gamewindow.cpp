#include "code/include/gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(MainWindow *parent) :
    QMainWindow(parent),
    mw(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/images/map.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}
