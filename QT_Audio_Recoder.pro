#-------------------------------------------------
#
# Project created by QtCreator 2024-04-20T21:26:36
#
#-------------------------------------------------

QT       += core gui multimedia
#这一行指定了项目需要链接的Qt模块。core和gui是最基本的Qt模块，分别提供核心非图形功能和图形用户界面功能。
#multimedia模块提供了处理多媒体内容的功能，比如音视频。
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#这一行是一个条件语句，用来判断Qt的主版本号是否大于4。如果是，那么就添加widgets模块。
#这个模块在Qt 5及之后的版本中才被引入，提供了一套丰富的界面组件。

TARGET = QT_Audio_Recoder
#这行设置了项目的目标名称，即生成的执行文件名将是QT_Audio_Recoder。
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui
