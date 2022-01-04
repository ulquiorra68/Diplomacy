#ifndef NUMBERWINDOW_H
#define NUMBERWINDOW_H

#include <QDialog>
#include <QSpinBox>
#include "code/include/mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NumberWindow; }
QT_END_NAMESPACE

class NumberWindow : public QDialog
{
    Q_OBJECT

public slots:
    void onOk();
    void onBack();

public:
    NumberWindow(MainWindow *parent = nullptr);
    ~NumberWindow();

    bool ready() const;
    void setReady(bool flag);

    int getNumSpinBox();

private:
    Ui::NumberWindow *ui;
    MainWindow* mw;

    bool p_ready;

    int numSpinBox;
};

#endif // NUMBERWINDOW_H
