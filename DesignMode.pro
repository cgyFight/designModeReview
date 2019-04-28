TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    factorAndBuilder.cpp \
    sigle.cpp \
    behaviourMode/strategy.cpp \

HEADERS += \
    behaviourMode/strategy.h \
    StructualType/adapter.h \
    behaviourMode/template.h \
    StructualType/faced.h \
    decorate.h \
    StructualType/proxy.h \
    StructualType/flyweight.h \
    behaviourMode/observer.h
