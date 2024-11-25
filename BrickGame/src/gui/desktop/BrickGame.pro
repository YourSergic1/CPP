QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    exit.cpp \
    main.cpp \
    mainwindow.cpp \
    ../../brick_game/tetris/backend_t.c \
    ../../brick_game/snake/backend_s.cpp \
    ../cli/tetris/frontend_t.c \
    ../cli/snake/frontend_s.cpp \
    snake.cpp \
    tetris.cpp

HEADERS += \
    exit.h \
    mainwindow.h \
    snake.h \
    tetris.h \
    ../../brick_game/tetris/backend_t.h \
    ../../brick_game/snake/backend_s.hpp \
    ../cli/tetris/frontend_t.h \
    ../../brick_game/tetris/defines_t.h

FORMS += \
    exit.ui \
    mainwindow.ui \
    snake.ui \
    tetris.ui

# Добавляем флаг для линковки с библиотекой ncurses
LIBS += -lncurses


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target