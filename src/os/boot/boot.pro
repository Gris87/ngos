QT -= gui

CONFIG += c++17

TARGET = boot.elf
TEMPLATE = app



VECTORIZATION_FLAGS = -mno-mmx -mno-sse
FMA_FLAGS           = -mno-fma



QMAKE_LFLAGS += \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/main.S
