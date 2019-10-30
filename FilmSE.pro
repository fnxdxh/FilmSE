TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        mcharstring.cpp \
        mcharstringlink.cpp \
        test.cpp

HEADERS += \
    mcharstring.h \
    mcharstringlink.h \
    mstack.h \
    test.h
