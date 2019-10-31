TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dic.cpp \
        main.cpp \
        mcharstring.cpp \
        mcharstringlink.cpp \
        parser.cpp \
        test.cpp

HEADERS += \
    dic.h \
    mcharstring.h \
    mcharstringlink.h \
    mstack.h \
    parser.h \
    test.h
