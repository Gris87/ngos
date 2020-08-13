QT += core gui widgets

CONFIG += c++17

TARGET = build_config_gui
TEMPLATE = app

RC_FILE    = Resources.rc
RESOURCES += Resources.qrc



DEFINES += \
    DEVTOOLS_APPLICATION



# Warnings as errors - BEGIN
win32-msvc* {
    QMAKE_CXXFLAGS += /WX
} else {
    QMAKE_CXXFLAGS += -Werror -Wno-address-of-packed-member -Wno-trigraphs
}
# Warnings as errors - END

# Release optimization - BEGIN
QMAKE_CFLAGS_RELEASE -= -O1
QMAKE_CFLAGS_RELEASE -= -O2
QMAKE_CFLAGS_RELEASE += -O3

QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
# Release optimization - END

# Target dirs - BEGIN
DESTDIR     = build/
OBJECTS_DIR = build/gen
MOC_DIR     = build/gen
RCC_DIR     = build/gen
UI_DIR      = build/gen
# Target dirs - END



INCLUDEPATH += \
    src     # /tools/qt/build_config_gui/src



SOURCES += \
    src/com/ngos/devtools/build_config_gui/main.cpp \
    src/com/ngos/devtools/build_config_gui/main/aboutdialog.cpp \
    src/com/ngos/devtools/build_config_gui/main/mainwindow.cpp \
    src/com/ngos/devtools/build_config_gui/other/global.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/categorytreewidgetitem.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/common/trackingcheckbox.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/common/trackingcombobox.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/common/trackinggroupbox.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/common/trackinglineedit.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/booleanparameterwidget.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/comboboxparameterwidget.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/integerpowerof2parameterwidget.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/parameterwidget.cpp \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/textparameterwidget.cpp

HEADERS += \
    src/com/ngos/devtools/build_config_gui/main/aboutdialog.h \
    src/com/ngos/devtools/build_config_gui/main/mainwindow.h \
    src/com/ngos/devtools/build_config_gui/other/global.h \
    src/com/ngos/devtools/build_config_gui/other/optioninfo.h \
    src/com/ngos/devtools/build_config_gui/widgets/categorytreewidgetitem.h \
    src/com/ngos/devtools/build_config_gui/widgets/common/trackingcheckbox.h \
    src/com/ngos/devtools/build_config_gui/widgets/common/trackingcombobox.h \
    src/com/ngos/devtools/build_config_gui/widgets/common/trackinggroupbox.h \
    src/com/ngos/devtools/build_config_gui/widgets/common/trackinglineedit.h \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/booleanparameterwidget.h \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/comboboxparameterwidget.h \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/integerpowerof2parameterwidget.h \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/parameterwidget.h \
    src/com/ngos/devtools/build_config_gui/widgets/parameters/textparameterwidget.h

FORMS += \
    src/com/ngos/devtools/build_config_gui/main/aboutdialog.ui \
    src/com/ngos/devtools/build_config_gui/main/mainwindow.ui
