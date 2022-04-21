QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
//源文件
SOURCES += \
    boom.cpp \
    card.cpp \
    gameover.cpp \
    gamewin.cpp \
    land.cpp \
    landbar.cpp \
    level.cpp \
    main.cpp \
    mainwindow.cpp \
    mypushbutton.cpp \
    paint.cpp \
    pea.cpp \
    peashooter.cpp \
    plant.cpp \
    quanji.cpp \
    skyshooter.cpp \
    spikeweed.cpp \
    sun.cpp \
    sunflower.cpp \
    timecontrol.cpp \
    wallnut.cpp \
    yuanwall.cpp \
    zombie.cpp \
    zombie_0.cpp \
    zombie_1.cpp \
    zombie_2.cpp \
    zombie_3.cpp \
    zombie_7.cpp \
    zombie_8.cpp \
    zombienode.cpp
//头文件
HEADERS += \
    boom.h \
    card.h \
    common.h \
    gameover.h \
    gamewin.h \
    land.h \
    landbar.h \
    level.h \
    mainwindow.h \
    mypushbutton.h \
    paint.h \
    pea.h \
    peashooter.h \
    plant.h \
    quanji.h \
    skyshooter.h \
    spikeweed.h \
    sun.h \
    sunflower.h \
    timecontrol.h \
    wallnut.h \
    yuanwall.h \
    zombie.h \
    zombie_0.h \
    zombie_1.h \
    zombie_2.h \
    zombie_3.h \
    zombie_7.h \
    zombie_8.h \
    zombienode.h

FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
