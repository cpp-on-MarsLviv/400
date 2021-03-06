QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Models/blankmodel.cpp \
    Models/cell.cpp \
    Models/cellarea.cpp \
    Models/modelparams.cpp \
    Utils/applocation.cpp \
    Utils/logger.cpp \
    Widgets/mainwindow.cpp \
    Models/lifemodel.cpp \
    main.cpp \

HEADERS += \
    Helpers/constants.h \
    Helpers/functions.h \
    Helpers/generators.h \
    Models/blankmodel.h \
    Models/cell.h \
    Models/cellarea.h \
    Models/cellobserver.h \
    Models/lifemodel.h \
    Models/modelparams.h \
    Utils/applocation.h \
    Utils/logger.h \
    Widgets/mainwindow.h \
    Models/lifemodel.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
