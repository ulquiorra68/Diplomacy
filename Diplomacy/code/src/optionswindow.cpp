#include "code/include/optionswindow.h"
#include "ui_optionswindow.h"
#include "code/include/mainwindow.h"
#include <QSlider>

OptionsWindow::OptionsWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::OptionsWindow),
    mw(parent)
{
    ui->setupUi(this);

    ui->onButton->setChecked(parent->isSoundOn());
    ui->offButton->setChecked(!parent->isSoundOn());

    connect(ui->backButton, &QPushButton::clicked, this, &OptionsWindow::onBack);
}

OptionsWindow::~OptionsWindow()
{
    delete ui;
}

void OptionsWindow::onBack()
{
    if (ui->onButton->isChecked())
        mw->setSoundOn(true);
    else
    {
        mw->setSoundOn(false);
        mw->setVolume(0);
    }

    mw->setNumSpinBox((ui->numberSpinBox)->value());

    delete this;
}
