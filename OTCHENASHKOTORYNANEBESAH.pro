QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admins.cpp \
    avtorizat.cpp \
    dobclient.cpp \
    dobinfo.cpp \
    dobotv.cpp \
    dobpolzovat.cpp \
    dobsotrudn.cpp \
    dobvoprOTV.cpp \
    inform.cpp \
    main.cpp \
    nachokno.cpp \
    polzovat.cpp \
    support.cpp \
    vohod.cpp

HEADERS += \
    admins.h \
    avtorizat.h \
    dobclient.h \
    dobinfo.h \
    dobotv.h \
    dobpolzovat.h \
    dobsotrudn.h \
    dobvoprOTV.h \
    inform.h \
    nachokno.h \
    polzovat.h \
    support.h \
    vohod.h

FORMS += \
    admins.ui \
    avtorizat.ui \
    dobclient.ui \
    dobinfo.ui \
    dobotv.ui \
    dobpolzovat.ui \
    dobsotrudn.ui \
    dobvoprOTV.ui \
    inform.ui \
    nachokno.ui \
    polzovat.ui \
    support.ui \
    vohod.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

DISTFILES += \
    LP.txt
