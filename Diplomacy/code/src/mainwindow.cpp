#include "code/include/mainwindow.h"
#include "ui_mainwindow.h"
#include "code/include/userswindow.h"
#include "code/include/gamewindow.h"
#include "code/include/optionswindow.h"

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

void MainWindow::onPlay()
{
    UsersWindow* uw = new UsersWindow(this);
    uw->setWindowFlags(Qt::CustomizeWindowHint);
    uw->exec();

    if (uw->ready())
    {
        openGameWindow();
        uw->setReady(false);
    }
}

void MainWindow::onOptions()
{
    OptionsWindow *ow = new OptionsWindow(this);
    ow->setWindowFlags(Qt::CustomizeWindowHint);
    ow->exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , volume(10)
    , sound(true)
    , numSpinBox(3)
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

void MainWindow::openGameWindow()
{
    GameWindow* gw = new GameWindow(this);

    gw->setWindowFlags(Qt::Window);
    gw->showFullScreen();
}

int MainWindow::getNumSpinBox()
{
    return numSpinBox;
}

void MainWindow::setNumSpinBox(int value)
{
    numSpinBox = value;
}

bool MainWindow::isSoundOn() const
{
    return sound;
}

void MainWindow::setSoundOn(bool flag)
{
    sound = flag;
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
    connect(ui->play_button, &QPushButton::clicked, this, &MainWindow::onPlay);
    connect(ui->options_button, &QPushButton::clicked, this, &MainWindow::onOptions);
}

void MainWindow::setMusic()
{
    backGroundMusic = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    backGroundMusic->setAudioOutput(audioOutput);

    backGroundMusic->setSource(QUrl("qrc:/sound/Medieval Music - Medieval Travelers.mp3"));
    audioOutput->setVolume(10);

    backGroundMusic->play();
}
