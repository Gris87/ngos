QT -= gui                                                                                                                                                                                                # Colorize: green
QT += network                                                                                                                                                                                            # Colorize: green
                                                                                                                                                                                                         # Colorize: green
CONFIG += c++20 console                                                                                                                                                                                  # Colorize: green
CONFIG -= app_bundle                                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
TARGET   = code_generator                                                                                                                                                                                # Colorize: green
TEMPLATE = app                                                                                                                                                                                           # Colorize: green
                                                                                                                                                                                                         # Colorize: green
RESOURCES += Resources.qrc                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
DEFINES += \                                                                                                                                                                                             # Colorize: green
    DEVTOOLS_APPLICATION \                                                                                                                                                                               # Colorize: green
    _WIN32_WINNT=0x0A00                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# Warnings as errors - BEGIN                                                                                                                                                                             # Colorize: green
win32-msvc* {                                                                                                                                                                                            # Colorize: green
    QMAKE_CXXFLAGS += /WX                                                                                                                                                                                # Colorize: green
} else {                                                                                                                                                                                                 # Colorize: green
    QMAKE_CXXFLAGS += -Wall -Wextra -Werror                                                                                                                                                              # Colorize: green
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
OBJECTS_DIR = build/gen/$$TARGET/objs                                                                                                                                                                    # Colorize: green
MOC_DIR     = build/gen/$$TARGET/moc                                                                                                                                                                     # Colorize: green
RCC_DIR     = build/gen/$$TARGET/rcc                                                                                                                                                                     # Colorize: green
UI_DIR      = build/gen/$$TARGET/ui                                                                                                                                                                      # Colorize: green
# Target dirs - END                                                                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
INCLUDEPATH += \                                                                                                                                                                                         # Colorize: green
    src \                                       # tools/qt/code_generator/src                                                                                                                            # Colorize: green
    build/gen \                                 # tools/qt/code_generator/build/gen                                                                                                                      # Colorize: green
    ../../../3rd_party/libs/freetype/include \  # 3rd_party/libs/freetype/include                                                                                                                        # Colorize: green
    ../../../include \                          # include                                                                                                                                                # Colorize: green
    ../../../src/os/configure/src \             # src/os/configure/src                                                                                                                                   # Colorize: green
    ../../../src/os/shared/common/src           # src/os/shared/common/src                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
LIBS += \                                                                                                                                                                                                # Colorize: green
    -L../../../3rd_party/libs/freetype/objs/.libs -lfreetype                                                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
include(../shared/console/console.pri)                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
SOURCES += \                                                                                                                                                                                             # Colorize: green
    src/com/ngos/devtools/code_generator/generators/assets/assetsgenerator.cpp \                                                                                                                         # Colorize: green
    src/com/ngos/devtools/code_generator/generators/assets/zzz_generators/consoleglyphgenerator.cpp \                                                                                                    # Colorize: green
    src/com/ngos/devtools/code_generator/generators/assets/zzz_generators/guiglyphgenerator.cpp \                                                                                                        # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/commongenerator.cpp \                                                                                                                         # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/bitstestgenerator.cpp \                                                                                                        # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/bytesdecimalsgenerator.cpp \                                                                                                   # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/hexcharsgenerator.cpp \                                                                                                        # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/numberdecimalsgenerator.cpp \                                                                                                  # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/pcidatabasegenerator.cpp \                                                                                                     # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/x86bugsnamesgenerator.cpp \                                                                                                    # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/x86featuresnamesgenerator.cpp \                                                                                                # Colorize: green
    src/com/ngos/devtools/code_generator/generators/configure/configuregenerator.cpp \                                                                                                                   # Colorize: green
    src/com/ngos/devtools/code_generator/generators/configure/zzz_generators/asmoffsetsgenerator.cpp \                                                                                                   # Colorize: green
    src/com/ngos/devtools/code_generator/generators/generator.cpp \                                                                                                                                      # Colorize: green
    src/com/ngos/devtools/code_generator/generators/usb_boot_maker/usbbootmakergenerator.cpp \                                                                                                           # Colorize: green
    src/com/ngos/devtools/code_generator/generators/usb_boot_maker/zzz_generators/protectivembrgenerator.cpp \                                                                                           # Colorize: green
    src/com/ngos/devtools/code_generator/main.cpp                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
HEADERS += \                                                                                                                                                                                             # Colorize: green
    src/com/ngos/devtools/code_generator/generators/assets/assetsgenerator.h \                                                                                                                           # Colorize: green
    src/com/ngos/devtools/code_generator/generators/assets/zzz_generators/consoleglyphgenerator.h \                                                                                                      # Colorize: green
    src/com/ngos/devtools/code_generator/generators/assets/zzz_generators/guiglyphgenerator.h \                                                                                                          # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/commongenerator.h \                                                                                                                           # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/bitstestgenerator.h \                                                                                                          # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/bytesdecimalsgenerator.h \                                                                                                     # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/hexcharsgenerator.h \                                                                                                          # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/numberdecimalsgenerator.h \                                                                                                    # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/pcidatabasegenerator.h \                                                                                                       # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/x86bugsnamesgenerator.h \                                                                                                      # Colorize: green
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/x86featuresnamesgenerator.h \                                                                                                  # Colorize: green
    src/com/ngos/devtools/code_generator/generators/configure/configuregenerator.h \                                                                                                                     # Colorize: green
    src/com/ngos/devtools/code_generator/generators/configure/zzz_generators/asmoffsetsgenerator.h \                                                                                                     # Colorize: green
    src/com/ngos/devtools/code_generator/generators/generator.h \                                                                                                                                        # Colorize: green
    src/com/ngos/devtools/code_generator/generators/usb_boot_maker/usbbootmakergenerator.h \                                                                                                             # Colorize: green
    src/com/ngos/devtools/code_generator/generators/usb_boot_maker/zzz_generators/protectivembrgenerator.h \                                                                                             # Colorize: green
    src/com/ngos/devtools/code_generator/other/bitsfield.h \                                                                                                                                             # Colorize: green
    src/com/ngos/devtools/code_generator/other/bitsstructure.h \                                                                                                                                         # Colorize: green
    src/com/ngos/devtools/code_generator/other/pcibaseclass.h \                                                                                                                                          # Colorize: green
    src/com/ngos/devtools/code_generator/other/pcidevice.h \                                                                                                                                             # Colorize: green
    src/com/ngos/devtools/code_generator/other/pciinterface.h \                                                                                                                                          # Colorize: green
    src/com/ngos/devtools/code_generator/other/pcisubclass.h \                                                                                                                                           # Colorize: green
    src/com/ngos/devtools/code_generator/other/pcisubdevice.h \                                                                                                                                          # Colorize: green
    src/com/ngos/devtools/code_generator/other/pcivendor.h                                                                                                                                               # Colorize: green
