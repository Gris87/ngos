TARGET = configure

ARCH = $(shell grep "define NGOS_BUILD_ARCH" ../../../include/buildconfig.h | cut -c 37- | tr "[:upper:]" "[:lower:]")

ASSETS_DIR     = assets
SHARED_DIR     = ../shared
COMMON_DIR     = $(SHARED_DIR)/common
UEFIBASE_DIR   = $(SHARED_DIR)/uefibase
SOURCE_ASM_DIR = asm
SOURCE_CPP_DIR = src
TEST_CPP_DIR   = test
OUTPUT_DIR     = build

MKDIR = mkdir -p
RMDIR = rm -rf
CAT   = cat



CROSS_COMPILE = $(ARCH)-elf-

CC  = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
LD  = $(CROSS_COMPILE)ld



VECTORIZATION_FLAGS = -mno-mmx -mno-sse

FMA_FLAGS = -mno-fma



RELEASE = $(shell grep "define NGOS_BUILD_RELEASE" ../../../include/buildconfig.h | cut -c 35- | tr "[:upper:]" "[:lower:]")



DEBUG_FLAGS =

ifeq ($(RELEASE), no)
	DEBUG_FLAGS = -g
endif



DEFINES = \
	-DBUILD_TARGET_$(shell echo $(TARGET) | tr "[:lower:]" "[:upper:]")



INCLUDE_PATH = \
	-I . \
	-I $(SHARED_DIR)/ \
	-I ../include/ \
	-I ../../../include/ \
	-I ../../../include/stdinc/



ASMFLAGS = -c $(INCLUDE_PATH)
CXXFLAGS = -c -m64 -O3 -W -Wall -Werror -nostdinc -mno-red-zone -fPIE -ffreestanding -fno-strict-aliasing -fno-stack-protector -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables -std=c++17 $(VECTORIZATION_FLAGS) $(FMA_FLAGS) $(DEBUG_FLAGS) $(DEFINES) $(INCLUDE_PATH)



# Getting list of source files
ASSETS_FILES         = $(shell find $(ASSETS_DIR)/ -type f | grep -ve .gitignore -ve generated/assets.S                            2> /dev/null)
COMMON_ASM_SOURCES   = $(shell find $(COMMON_DIR)/$(SOURCE_ASM_DIR)/arch/$(ARCH)/                                    -name "*.S"   2> /dev/null)
COMMON_CPP_SOURCES   = $(shell find $(COMMON_DIR)/$(SOURCE_CPP_DIR)/                                                 -name "*.cpp" 2> /dev/null)
UEFIBASE_ASM_SOURCES = $(shell find $(UEFIBASE_DIR)/$(SOURCE_ASM_DIR)/arch/$(ARCH)/                                  -name "*.S"   2> /dev/null)
UEFIBASE_CPP_SOURCES = $(shell find $(UEFIBASE_DIR)/$(SOURCE_CPP_DIR)/ $(UEFIBASE_DIR)/$(TEST_CPP_DIR)/              -name "*.cpp" 2> /dev/null)
ASM_SOURCES          = $(shell find $(SOURCE_ASM_DIR)/arch/$(ARCH)/                                                  -name "*.S"   2> /dev/null)
CPP_SOURCES          = $(shell find $(SOURCE_CPP_DIR)/ $(TEST_CPP_DIR)/                                              -name "*.cpp" 2> /dev/null)
CPP_HEADERS          = $(shell find $(SOURCE_CPP_DIR)/ $(TEST_CPP_DIR)/ $(SHARED_DIR)/ ../include/ ../../../include/ -name "*.h"   2> /dev/null)

# Getting list of object files
ASSETS_OBJ       = $(OUTPUT_DIR)/$(ASSETS_DIR)/generated/assets.o
COMMON_ASM_OBJ   = $(addprefix $(OUTPUT_DIR)/,$(COMMON_ASM_SOURCES:../shared/common/%.S=shared/common/%.o))
COMMON_CPP_OBJ   = $(addprefix $(OUTPUT_DIR)/,$(COMMON_CPP_SOURCES:../shared/common/%.cpp=shared/common/%.o))
UEFIBASE_ASM_OBJ = $(addprefix $(OUTPUT_DIR)/,$(UEFIBASE_ASM_SOURCES:../shared/uefibase/%.S=shared/uefibase/%.o))
UEFIBASE_CPP_OBJ = $(addprefix $(OUTPUT_DIR)/,$(UEFIBASE_CPP_SOURCES:../shared/uefibase/%.cpp=shared/uefibase/%.o))
ASM_OBJ          = $(addprefix $(OUTPUT_DIR)/,$(ASM_SOURCES:%.S=%.o))
CPP_OBJ          = $(addprefix $(OUTPUT_DIR)/,$(CPP_SOURCES:%.cpp=%.o))

OBJECTS = $(ASSETS_OBJ) $(COMMON_ASM_OBJ) $(COMMON_CPP_OBJ) $(UEFIBASE_ASM_OBJ) $(UEFIBASE_CPP_OBJ) $(ASM_OBJ) $(CPP_OBJ)



all: $(OUTPUT_DIR)/$(TARGET).elf

$(OUTPUT_DIR)/$(TARGET).elf: $(OBJECTS) linker.ld
	$(LD) -T linker.ld $(OBJECTS) -o $(OUTPUT_DIR)/$(TARGET).elf

$(ASSETS_OBJ): $(ASSETS_FILES)
	sh -c "cd $(ASSETS_DIR)/ && ./generate_assets.sh"
	$(MKDIR) $(@D)
	$(CC) $(ASMFLAGS) $(ASSETS_DIR)/generated/assets.S -o $@

$(OUTPUT_DIR)/shared/%.o: $(SHARED_DIR)/%.S $(CPP_HEADERS)
	$(MKDIR) $(@D)
	$(CC) $(ASMFLAGS) $< -o $@

$(OUTPUT_DIR)/shared/%.o: $(SHARED_DIR)/%.cpp $(CPP_HEADERS)
	$(MKDIR) $(@D)
	$(CXX) $(CXXFLAGS) -E $< -o $@.cpp
	$(CXX) $(CXXFLAGS) -S $< -o $@.S
	$(CXX) $(CXXFLAGS) $< -o $@

$(OUTPUT_DIR)/%.o: %.S $(CPP_HEADERS)
	$(MKDIR) $(@D)
	$(CC) $(ASMFLAGS) $< -o $@

$(OUTPUT_DIR)/%.o: %.cpp $(CPP_HEADERS)
	$(MKDIR) $(@D)
	$(CXX) $(CXXFLAGS) -E $< -o $@.cpp
	$(CXX) $(CXXFLAGS) -S $< -o $@.S
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RMDIR) $(OUTPUT_DIR)
