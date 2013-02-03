TEMPLATE = app
TARGET = teaservice
CONFIG += qt warn_on qt3d

#CONFIG += qt3d_deploy_pkg
#include(/home/t0/Downloads/qt3d-1.0-src/pkg.pri)

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

