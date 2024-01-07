QT       += core network sql
include($$PWD/QtTelegramBot/QtTelegramBot.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    completion.cpp \
    image.cpp \
    main.cpp \
    msql.cpp


HEADERS += \
    completion.h \
    image.h \
    msql.h

    msql.h
QMAKE_CXXFLAGS += -lcurl
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
LIBS +=/usr/include/x86_64-linux-gnu/curl/curl.h -lcurl
INCLUDEPATH += /usr/include/x86_64-linux-gnu/curl.curl.h
DEPENDPATH += /usr/include/x86_64-linux-gnu/curl.curl.h
