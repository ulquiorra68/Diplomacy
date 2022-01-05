#include "code/include/optionswindow.h"
#include "ui_optionswindow.h"
#include "code/include/mainwindow.h"
#include <QSlider>

void OptionsWindow::volumeChanged()
{
    mw->setVolume(ui->volumeSlider->value());
}

OptionsWindow::OptionsWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::OptionsWindow),
    mw(parent)
{
    ui->setupUi(this);

    ui->onButton->setChecked(parent->isSoundOn());
    ui->offButton->setChecked(!parent->isSoundOn());
    ui->volumeSlider->setValue(mw->getVolume());

    connect(ui->backButton, &QPushButton::clicked, this, &OptionsWindow::onBack);
    connect(ui->volumeSlider, &QSlider::valueChanged, mw, &MainWindow::setVolume);
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

    delete this;
}
