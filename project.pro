TARGET = main
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++14 -O2 -Wall -Wextra

win32 {
QMAKE_LFLAGS += -static -static-libgcc -static-libstdc++
}

SOURCES += \
    main.cpp