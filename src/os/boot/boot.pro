QT -= gui                                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
CONFIG += c++20                                                                                                                                                                                          # Colorize: green
                                                                                                                                                                                                         # Colorize: green
TARGET   = boot                                                                                                                                                                                          # Colorize: green
TEMPLATE = uefi                                                                                                                                                                                          # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
QMAKE_LFLAGS += \                                                                                                                                                                                        # Colorize: green
    -T linker.ld                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
SOURCES += \                                                                                                                                                                                             # Colorize: green
    asm/arch/x86_64/com/ngos/boot/main.S                                                                                                                                                                 # Colorize: green
