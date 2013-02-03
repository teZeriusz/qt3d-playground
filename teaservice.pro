TEMPLATE = app
TARGET = teaservice
CONFIG += qt warn_on
QT += 3d

CONFIG += qt3d_deploy_pkg
#include(/home/t0/qtpro/ose/qt3d-build-Desktop_Qt_5_0_0_GCC_64bit_SDK-Release/mkspecs/modules/qt_lib_3d.pri)
include(/home/t0/qtpro/ose/qt3d/pkg.pri)

INSTALLS = ""
DESTDIR = ""

SOURCES = meshobject.cpp sceneobject.cpp perpixeleffect.cpp \
    TeaServiceView.cpp \
    main.cpp \
    TeaService.cpp \
    Teaspoon.cpp \
    Teacup.cpp \
    Teapot.cpp \
    common.cpp
HEADERS = meshobject.h sceneobject.h perpixeleffect.h \
    TeaServiceView.h \
    TeaService.h \
    Teaspoon.h \
    Teacup.h \
    Teapot.h \
    common.h
RESOURCES = teaservice.qrc

OTHER_FILES += \
    teaservice.rc \
    teaservice.desktop

RC_FILE = teaservice.rc

