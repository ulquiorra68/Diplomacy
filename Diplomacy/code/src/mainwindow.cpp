#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::resizeEvent(QResizeEvent *event) {
    QPixmap bkgnd(":/images/diplomacy.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QMainWindow::resizeEvent(event);
}

void MainWindow::onQuit()
{
    close();
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , volume(20)
{
    ui->setupUi(this);
    setMusic();
    setConnects();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    this->height = screenGeometry.height();
    this->width = screenGeometry.width();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getHeight() const
{
    return height;
}

void MainWindow::setHeight(int value)
{
    height = value;
}

int MainWindow::getWidth() const
{
    return width;
}

void MainWindow::setWidth(int value)
{
    width = value;
}

void MainWindow::playBackgroundMusic()
{
    backGroundMusic->play();
}

void MainWindow::setVolume(int volume)
{
    this->volume = volume;
    audioOutput->setVolume(volume);
}

int MainWindow::getVolume() const
{
    return volume;
}

void MainWindow::setBackGroundMusic(QString str)
{
    backGroundMusic->setSource(QUrl(str));
}

void MainWindow::stopBackGroundMusic()
{
    backGroundMusic->stop();
}

void MainWindow::setConnects()
{
    connect(ui->quit_button, &QPushButton::clicked, this, &MainWindow::onQuit);
   //onnect(ui->play_button, &QPushButton::clicked, this, &MainWindow::onPlay);
  //connect(ui->options_button, &QPushButton::clicked, this, &MainWindow::onOptions);
}

void MainWindow::setMusic()
{
    backGroundMusic = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    backGroundMusic->setAudioOutput(audioOutput);

    backGroundMusic->setSource(QUrl("qrc:/sound/Medieval Music - Medieval Travelers.mp3"));
    audioOutput->setVolume(20);

    backGroundMusic->play();
}
