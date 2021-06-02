QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KitsuneTravel
CONFIG += c++11
win32:RC_ICONS += ./icon.ico
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutprogram.cpp \
    client.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    manualbox.cpp

HEADERS += \
    List.h \
    aboutprogram.h \
    client.h \
    form.h \
    mainwindow.h \
    manualbox.h

FORMS += \
    form.ui \
    mainwindow.ui \
    manualbox.ui

TRANSLATIONS += \
    Kursach_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES +=
