#-------------------------------------------------
#
# Project created by QtCreator 2013-09-24T17:03:18
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qfi_example
TEMPLATE = app

#-------------------------------------------------

win32: DEFINES += WIN32 _WINDOWS _USE_MATH_DEFINES

win32:CONFIG(release, debug|release):    DEFINES += NDEBUG
else:win32:CONFIG(debug, debug|release): DEFINES += _DEBUG

#-------------------------------------------------

INCLUDEPATH += ./ ./example

#-------------------------------------------------

HEADERS += \
    example/LayoutSquare.h \
    example/MainWindow.h \
    example/WidgetPFD.h \
    qfi_PFD.h
SOURCES += \
    example/LayoutSquare.cpp \
    example/main.cpp \
    example/MainWindow.cpp \
    example/WidgetPFD.cpp \
    qfi_PFD.cpp

FORMS += \
    example/MainWindow.ui \
    example/WidgetPFD.ui

RESOURCES += \
    qfi.qrc
