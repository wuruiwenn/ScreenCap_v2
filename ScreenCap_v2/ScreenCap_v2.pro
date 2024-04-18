QT       += core gui
#QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SystemInfo.cpp \
    main.cpp \
    mainwidget.cpp \
    screenbackwidget.cpp \
    screencanvaswidget.cpp \
    tools.cpp \
    trayiconwidget.cpp

HEADERS += \
    SystemInfo.h \
    defines.h \
    mainwidget.h \
    screenbackwidget.h \
    screencanvaswidget.h \
    tools.h \
    trayiconwidget.h

FORMS += \
    mainwidget.ui \
    screenbackwidget.ui \
    screencanvaswidget.ui \
    trayiconwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RC_ICONS = favicon.ico
#QMAKE_CXXFLAGS += /utf-8  # 设置C++源文件的编码为UTF-8
#这个 当使用MinGW编译器的时候，就不行

RESOURCES += \
    myResource.qrc

# 使得C++ std::cout<<有效
#CONFIG += console

DISTFILES += \
    readme.md


#指定编译生成的文件到temp目录 分门别类存储
MOC_DIR       = temp_file/moc
RCC_DIR       = temp_file/rcc
OBJECTS_DIR   = temp_file/obj
UI_DIR        = temp_file/ui

#指定生成的可执行文件的路径
#本质也是：QGuiApplication::applicationDirPath()的路径
DESTDIR       = bin


