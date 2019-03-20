QT += core gui widgets

CONFIG += c++14

TARGET = usb_boot_maker
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



# Include libraries - BEGIN
win32 {
    LIBS += -lSetupAPI
}
# Include libraries - END



# Increase permissions - BEGIN
win32 {
    QMAKE_LFLAGS += /MANIFESTUAC:"level='requireAdministrator'"
}
# Increase permissions - END



SOURCES += \
    src/main.cpp \
    src/main/aboutdialog.cpp \
    src/main/mainwindow.cpp \
    src/main/mainwindow_win.cpp \
    src/main/mainwindow_linux.cpp \
    src/other/usbspeed.cpp

HEADERS += \
    src/main/aboutdialog.h \
    src/main/mainwindow.h \
    src/other/usbproperties.h \
    src/other/usbspeed.h \
    src/other/usbdeviceinfo.h

FORMS += \
    src/main/aboutdialog.ui \
    src/main/mainwindow.ui

TRANSLATIONS += \
    assets/translations/language_en.ts \
    assets/translations/language_ru.ts
