QT += core gui widgets network                                                                                                                                                                           # Colorize: green
                                                                                                                                                                                                         # Colorize: green
CONFIG += c++17                                                                                                                                                                                          # Colorize: green
                                                                                                                                                                                                         # Colorize: green
TARGET   = usb_boot_maker                                                                                                                                                                                # Colorize: green
TEMPLATE = app                                                                                                                                                                                           # Colorize: green
                                                                                                                                                                                                         # Colorize: green
RC_FILE    = Resources.rc                                                                                                                                                                                # Colorize: green
RESOURCES += Resources.qrc                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
DEFINES += \                                                                                                                                                                                             # Colorize: green
    DEVTOOLS_APPLICATION                                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# Warnings as errors - BEGIN                                                                                                                                                                             # Colorize: green
win32-msvc* {                                                                                                                                                                                            # Colorize: green
    QMAKE_CXXFLAGS += /WX                                                                                                                                                                                # Colorize: green
} else {                                                                                                                                                                                                 # Colorize: green
    QMAKE_CXXFLAGS += -Werror -Wno-address-of-packed-member -Wno-trigraphs                                                                                                                               # Colorize: green
}                                                                                                                                                                                                        # Colorize: green
# Warnings as errors - END                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# Release optimization - BEGIN                                                                                                                                                                           # Colorize: green
QMAKE_CFLAGS_RELEASE -= -O1                                                                                                                                                                              # Colorize: green
QMAKE_CFLAGS_RELEASE -= -O2                                                                                                                                                                              # Colorize: green
QMAKE_CFLAGS_RELEASE += -O3                                                                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
QMAKE_CXXFLAGS_RELEASE -= -O1                                                                                                                                                                            # Colorize: green
QMAKE_CXXFLAGS_RELEASE -= -O2                                                                                                                                                                            # Colorize: green
QMAKE_CXXFLAGS_RELEASE += -O3                                                                                                                                                                            # Colorize: green
# Release optimization - END                                                                                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# Target dirs - BEGIN                                                                                                                                                                                    # Colorize: green
DESTDIR     = build/                                                                                                                                                                                     # Colorize: green
OBJECTS_DIR = build/gen                                                                                                                                                                                  # Colorize: green
MOC_DIR     = build/gen                                                                                                                                                                                  # Colorize: green
RCC_DIR     = build/gen                                                                                                                                                                                  # Colorize: green
UI_DIR      = build/gen                                                                                                                                                                                  # Colorize: green
# Target dirs - END                                                                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
INCLUDEPATH += \                                                                                                                                                                                         # Colorize: green
    src \                               # /tools/qt/usb_boot_maker/src                                                                                                                                   # Colorize: green
    ../../../include \                  # /include                                                                                                                                                       # Colorize: green
    ../../../src/os/shared/common/src   # /src/os/shared/common/src                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# Include libraries - BEGIN                                                                                                                                                                              # Colorize: green
win32 {                                                                                                                                                                                                  # Colorize: green
    LIBS += -lSetupAPI -lOle32                                                                                                                                                                           # Colorize: green
}                                                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
unix {                                                                                                                                                                                                   # Colorize: green
    LIBS += -ludev                                                                                                                                                                                       # Colorize: green
}                                                                                                                                                                                                        # Colorize: green
# Include libraries - END                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# Increase permissions - BEGIN                                                                                                                                                                           # Colorize: green
win32 {                                                                                                                                                                                                  # Colorize: green
    QMAKE_LFLAGS += /MANIFESTUAC:"level='requireAdministrator'"                                                                                                                                          # Colorize: green
}                                                                                                                                                                                                        # Colorize: green
# Increase permissions - END                                                                                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# Copy files to build folder - BEGIN                                                                                                                                                                     # Colorize: green
win32 {                                                                                                                                                                                                  # Colorize: green
    copydata.commands = \                                                                                                                                                                                # Colorize: green
        $(COPY_FILE) \"$$shell_path($$PWD/distrib/*)\" \"$$shell_path($$OUT_PWD/$$DESTDIR)\"                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    first.depends = $(first) copydata                                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    export(first.depends)                                                                                                                                                                                # Colorize: green
    export(copydata.commands)                                                                                                                                                                            # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    QMAKE_EXTRA_TARGETS += first copydata                                                                                                                                                                # Colorize: green
}                                                                                                                                                                                                        # Colorize: green
# Copy files to build folder - END                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
SOURCES += \                                                                                                                                                                                             # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/main.cpp \                                                                                                                                                      # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/main/aboutdialog.cpp \                                                                                                                                          # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow.cpp \                                                                                                                                           # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow_linux.cpp \                                                                                                                                     # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow_win.cpp \                                                                                                                                       # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/threads/burnthread.cpp \                                                                                                                                        # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/threads/burnthread_linux.cpp \                                                                                                                                  # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/threads/burnthread_win.cpp \                                                                                                                                    # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/threads/usbmonitorthread_linux.cpp                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
HEADERS += \                                                                                                                                                                                             # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/main/aboutdialog.h \                                                                                                                                            # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow.h \                                                                                                                                             # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/other/defines.h \                                                                                                                                               # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/other/fileinfo.h \                                                                                                                                              # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/other/usbbootmakerstate.h \                                                                                                                                     # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/other/usbdeviceinfo.h \                                                                                                                                         # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/other/usbproperties.h \                                                                                                                                         # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/other/usbspeed.h \                                                                                                                                              # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/other/versioninfo.h \                                                                                                                                           # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/threads/burnthread.h \                                                                                                                                          # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/threads/usbmonitorthread.h                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
FORMS += \                                                                                                                                                                                               # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/main/aboutdialog.ui \                                                                                                                                           # Colorize: green
    src/com/ngos/devtools/usb_boot_maker/main/mainwindow.ui                                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
TRANSLATIONS += \                                                                                                                                                                                        # Colorize: green
    assets/translations/language_en.ts \                                                                                                                                                                 # Colorize: green
    assets/translations/language_ru.ts                                                                                                                                                                   # Colorize: green
