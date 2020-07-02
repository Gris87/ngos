QT += core gui widgets network

CONFIG += c++17

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



INCLUDEPATH += \
    ../../../include \          # /include
    ../../../src/os/shared      # /src/os/shared



# Include libraries - BEGIN
win32 {
    LIBS += -lSetupAPI -lOle32
}

unix {
    LIBS += -ludev
}
# Include libraries - END



# Increase permissions - BEGIN
win32 {
    QMAKE_LFLAGS += /MANIFESTUAC:"level='requireAdministrator'"
}
# Increase permissions - END



# Copy files to build folder - BEGIN
win32 {
    copydata.commands = \
        $(COPY_FILE) \"$$shell_path($$PWD/distrib/*)\" \"$$shell_path($$OUT_PWD/$$DESTDIR)\"

    first.depends = $(first) copydata

    export(first.depends)
    export(copydata.commands)

    QMAKE_EXTRA_TARGETS += first copydata
}
# Copy files to build folder - END



SOURCES += \
    src/com/ngos/devtools/usb_boot_maker/main.cpp \
    src/com/ngos/devtools/usb_boot_maker/main/aboutdialog.cpp \
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow.cpp \
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow_linux.cpp \
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow_win.cpp \
    src/com/ngos/devtools/usb_boot_maker/threads/burnthread.cpp \
    src/com/ngos/devtools/usb_boot_maker/threads/burnthread_linux.cpp \
    src/com/ngos/devtools/usb_boot_maker/threads/burnthread_win.cpp \
    src/com/ngos/devtools/usb_boot_maker/threads/usbmonitorthread_linux.cpp

HEADERS += \
    src/com/ngos/devtools/usb_boot_maker/main/aboutdialog.h \
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow.h \
    src/com/ngos/devtools/usb_boot_maker/other/defines.h \
    src/com/ngos/devtools/usb_boot_maker/other/fileinfo.h \
    src/com/ngos/devtools/usb_boot_maker/other/usbbootmakerstate.h \
    src/com/ngos/devtools/usb_boot_maker/other/usbdeviceinfo.h \
    src/com/ngos/devtools/usb_boot_maker/other/usbproperties.h \
    src/com/ngos/devtools/usb_boot_maker/other/usbspeed.h \
    src/com/ngos/devtools/usb_boot_maker/other/versioninfo.h \
    src/com/ngos/devtools/usb_boot_maker/threads/burnthread.h \
    src/com/ngos/devtools/usb_boot_maker/threads/usbmonitorthread.h

FORMS += \
    src/com/ngos/devtools/usb_boot_maker/main/aboutdialog.ui \
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow.ui

TRANSLATIONS += \
    assets/translations/language_en.ts \
    assets/translations/language_ru.ts
