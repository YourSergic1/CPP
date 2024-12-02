QT       += core gui widgets opengl openglwidgets

LIBS += -lcheck -lm

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/affine_transform.cpp \
    sources/myopenglwidget.cpp \
    sources/opengl_data_calc.cpp \
    sources/opengl_settings.cpp \
    sources/parser.cpp

HEADERS += \
    headers/mainwindow.h \
    headers/gif.h \
    headers/myopenglwidget.h \
    headers/parser.h \
    headers/affine_transform.h

FORMS += \
    forms/mainwindow.ui

DEFINES += _GNU_SOURCE

# Добавляем директорию headers в INCLUDEPATH
INCLUDEPATH += headers

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target