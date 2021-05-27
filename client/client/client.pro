QT       += quick \
    widgets \
    quickwidgets \
    gui \
    core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    source/appcontroller.cpp \
    source/appdata.cpp \
    source/fieldmodel.cpp \
    source/fightersmodel.cpp \
    source/fillcontroller.cpp \
    source/main.cpp \
    source/tile.cpp

HEADERS += \
    headers/appcontroller.h \
    headers/appdata.h \
    headers/fieldmodel.h \
    headers/fightersmodel.h \
    headers/fillcontroller.h \
    headers/tile.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc

INCLUDEPATH += \
    D:\kursovaya\clientnew\client\headers\
    D:\kursovaya\clientnew\client\source\
    D:\kursovaya\clientnew\client\qml


