QT += widgets

CONFIG += c++11

DESTDIR = $$PWD/build

SOURCES += \
    main.cpp \
    mainwindows.cpp \
    evaluationwindows.cpp \
    updatewindows.cpp \
    configwindows.cpp

HEADERS += \
    mainwindows.h \
    evaluationwindows.h \
    EUpdateResult.h \
    updatewindows.h \
    configwindows.h \
    WestgardInterface.h

LIBS += -L$$PWD/build libWESTGARD-SSM.so

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Desktop/Westguard-SSM/src/ -llibWESTGARD-SSM.dll
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Desktop/Westguard-SSM/src/ -llibWESTGARD-SSM.dll
#else:unix: LIBS += -L$$PWD/../../Desktop/Westguard-SSM/src/ -llibWESTGARD-SSM.dll

INCLUDEPATH += $$PWD/../../Desktop/Westguard-SSM/src
DEPENDPATH += $$PWD/../../Desktop/Westguard-SSM/src
