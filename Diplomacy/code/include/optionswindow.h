#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QDialog>
#include "code/include/mainwindow.h"
#include <QSlider>

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QDialog
{
    Q_OBJECT

public slots:
    void volumeChanged();

public:
    explicit OptionsWindow(MainWindow *parent = nullptr);
    ~OptionsWindow();

    void onBack();

private:
    Ui::OptionsWindow *ui;
    MainWindow* mw;
};

#endif // OPTIONSWINDOW_H
