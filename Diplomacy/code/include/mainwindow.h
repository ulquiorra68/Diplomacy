#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QPainter>
#include <QKeyEvent>
#include <QtGui>
#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>

#include "code/include/player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *event) override;

public slots:
    void onQuit();
    void onPlay();
    void onOptions();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void playBackgroundMusic();
    void setVolume(int volume);
    int getVolume() const;
    void setBackGroundMusic(QString str);
    void stopBackGroundMusic();
    void openGameWindow();
    bool isSoundOn() const;
    void setSoundOn(bool flag);
    int getNumSpinBox();
    void setNumSpinBox(int value);

    int width, height;

    const QVector<Player*> &players() const;
    void setPlayers(const QVector<Player *> &newPlayers);

private:
    void setConnects();
    void setMusic();

public:
    QMediaPlayer* backGroundMusic;
    QAudioOutput *audioOutput;

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

private:
    Ui::MainWindow *ui;
    int volume;
    bool sound;
    int numSpinBox;

    QVector<Player*> p_players;
};
#endif // MAINWINDOW_H
