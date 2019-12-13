QT += core gui widgets

CONFIG += c++17

TARGET = build_config_gui
TEMPLATE = app

RC_FILE    = Resources.rc
RESOURCES += Resources.qrc



# Warnings as errors - BEGIN
win32-msvc* {
    QMAKE_CXXFLAGS += /WX
} else {
    QMAKE_CXXFLAGS += -Werror
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



SOURCES += \
    src/main.cpp \
    src/main/aboutdialog.cpp \
    src/main/mainwindow.cpp \
    src/other/global.cpp \
    src/widgets/categorytreewidgetitem.cpp \
    src/widgets/common/trackingcheckbox.cpp \
    src/widgets/common/trackingcombobox.cpp \
    src/widgets/common/trackinggroupbox.cpp \
    src/widgets/common/trackinglineedit.cpp \
    src/widgets/parameters/booleanparameterwidget.cpp \
    src/widgets/parameters/comboboxparameterwidget.cpp \
    src/widgets/parameters/integerpowerof2parameterwidget.cpp \
    src/widgets/parameters/parameterwidget.cpp \
    src/widgets/parameters/textparameterwidget.cpp

HEADERS += \
    src/main/aboutdialog.h \
    src/main/mainwindow.h \
    src/other/global.h \
    src/other/optioninfo.h \
    src/widgets/categorytreewidgetitem.h \
    src/widgets/common/trackingcheckbox.h \
    src/widgets/common/trackingcombobox.h \
    src/widgets/common/trackinggroupbox.h \
    src/widgets/common/trackinglineedit.h \
    src/widgets/parameters/booleanparameterwidget.h \
    src/widgets/parameters/comboboxparameterwidget.h \
    src/widgets/parameters/integerpowerof2parameterwidget.h \
    src/widgets/parameters/parameterwidget.h \
    src/widgets/parameters/textparameterwidget.h

FORMS += \
    src/main/aboutdialog.ui \
    src/main/mainwindow.ui
