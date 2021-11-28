#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    a.setWindowIcon(QIcon(":/images/diplomacy.jpg"));

    w.show();
    w.setWindowState(Qt::WindowFullScreen);
    return a.exec();
}
