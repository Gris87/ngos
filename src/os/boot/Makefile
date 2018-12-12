TARGET = boot

ARCH = $(shell grep "define NGOS_BUILD_ARCH" ../../../include/buildconfig.h | cut -c 37- | tr '[:upper:]' '[:lower:]')

SOURCE_ASM_DIR = asm
OUTPUT_DIR     = build

MKDIR = mkdir -p
RMDIR = rm -rf



CROSS_COMPILE = $(ARCH)-elf-

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld



ASMFLAGS = -c



# Getting list of source files
ASM_SOURCES = $(shell find $(SOURCE_ASM_DIR)/arch/$(ARCH)/ -name '*.S' 2> /dev/null)

# Getting list of object files
ASM_OBJ = $(addprefix $(OUTPUT_DIR)/,$(ASM_SOURCES:%.S=%.o))

OBJECTS = $(ASM_OBJ)



all: $(OUTPUT_DIR)/$(TARGET).elf

$(OUTPUT_DIR)/$(TARGET).elf: $(OBJECTS) linker.ld
	$(LD) -T linker.ld $(OBJECTS) -o $(OUTPUT_DIR)/$(TARGET).elf

$(OUTPUT_DIR)/%.o: %.S
	$(MKDIR) $(@D)
	$(CC) $(ASMFLAGS) $< -o $@

clean:
	$(RMDIR) $(OUTPUT_DIR)
