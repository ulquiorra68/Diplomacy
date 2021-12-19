QT       += core gui sql \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    code/src/main.cpp \
    code/src/mainwindow.cpp \
    code/src/player.cpp \
    code/src/userswindow.cpp

HEADERS += \
    code/include/mainwindow.h \
    code/include/player.h \
    code/include/userswindow.h

FORMS += \
    forms/mainwindow.ui \
    forms/userswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    sounds.qrc
