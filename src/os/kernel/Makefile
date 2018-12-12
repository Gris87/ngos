TARGET = kernel

ARCH = $(shell grep "define NGOS_BUILD_ARCH" ../../../include/buildconfig.h | cut -c 37- | tr '[:upper:]' '[:lower:]')

ASSETS_DIR     = assets
COMMON_DIR     = ../common
KERNELBASE_DIR = ../kernelbase
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



ZIP         = $(shell grep "define NGOS_BUILD_KERNEL_COMPRESSION" ../../../include/buildconfig.h | cut -c 65- | tr '[:upper:]' '[:lower:]')
ZIP_EXT     =
ZIP_FLAGS   =
ZIP_COMMAND =

ifeq ($(ZIP), gzip)
	ZIP_EXT   = .gz
	ZIP_FLAGS = -n -f -9

	ZIP_COMMAND = $(CAT) $(OUTPUT_DIR)/$(TARGET).elf | $(ZIP) $(ZIP_FLAGS) > $(OUTPUT_DIR)/$(TARGET).elf$(ZIP_EXT)
else ifeq ($(ZIP), xz)
	ZIP_EXT = .xz

	ifeq ($(ARCH), x86_64)
		ZIP_FLAGS = --x86 --lzma2=dict=128MiB
	else
		ZIP_FLAGS = --lzma2=dict=128MiB
	endif

	ZIP_COMMAND = $(CAT) $(OUTPUT_DIR)/$(TARGET).elf | $(ZIP) $(ZIP_FLAGS) > $(OUTPUT_DIR)/$(TARGET).elf$(ZIP_EXT)
endif



VECTORIZATION_MODE = $(shell grep "define NGOS_BUILD_X86_64_VECTORIZATION_MODE" ../../../include/buildconfig.h | cut -c 79- | tr '[:upper:]' '[:lower:]')



VECTORIZATION_FLAGS = -mno-mmx -mno-sse

ifeq ($(ARCH), x86_64)
	ifeq ($(VECTORIZATION_MODE), sse)
		VECTORIZATION_FLAGS = -msse
	else ifeq ($(VECTORIZATION_MODE), sse2)
		VECTORIZATION_FLAGS = -msse2
	else ifeq ($(VECTORIZATION_MODE), sse3)
		VECTORIZATION_FLAGS = -msse3
	else ifeq ($(VECTORIZATION_MODE), sse4)
		VECTORIZATION_FLAGS = -msse4
	else ifeq ($(VECTORIZATION_MODE), sse4_1)
		VECTORIZATION_FLAGS = -msse4.1
	else ifeq ($(VECTORIZATION_MODE), sse4_2)
		VECTORIZATION_FLAGS = -msse4.2
	else ifeq ($(VECTORIZATION_MODE), avx)
		VECTORIZATION_FLAGS = -mavx
	else ifeq ($(VECTORIZATION_MODE), avx2)
		VECTORIZATION_FLAGS = -mavx2
	else ifeq ($(VECTORIZATION_MODE), avx_512)
		VECTORIZATION_FLAGS = -mavx512f -mavx512pf -mavx512er -mavx512cd -mavx512vl -mavx512bw -mavx512dq -mavx512ifma -mavx512vbmi
	endif
endif



FUSED_MULTIPLY_ADD = $(shell grep "define NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD" ../../../include/buildconfig.h | cut -c 79- | tr '[:upper:]' '[:lower:]')



FMA_FLAGS = -mno-fma

ifeq ($(ARCH), x86_64)
	ifeq ($(FUSED_MULTIPLY_ADD), fma4)
		FMA_FLAGS = -mfma4
	else ifeq ($(FUSED_MULTIPLY_ADD), fma3)
		FMA_FLAGS = -mfma
	endif
endif



RELEASE = $(shell grep "define NGOS_BUILD_RELEASE" ../../../include/buildconfig.h | cut -c 35- | tr '[:upper:]' '[:lower:]')



DEBUG_FLAGS =

ifeq ($(RELEASE), no)
	DEBUG_FLAGS = -g
endif



DEFINES = \
	-DBUILD_TARGET_$(shell echo $(TARGET) | tr '[:lower:]' '[:upper:]')



INCLUDE_PATH = \
	-I . \
	-I $(COMMON_DIR)/ \
	-I $(KERNELBASE_DIR)/ \
	-I ../../../include/ \
	-I ../../../include/stdinc/ \
	-I ../include/



ASMFLAGS = -c $(INCLUDE_PATH)
CXXFLAGS = -c -m64 -O3 -W -Wall -Werror -nostdinc -mno-red-zone -fPIE -ffreestanding -fno-strict-aliasing -fno-stack-protector -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables -std=c++17 $(VECTORIZATION_FLAGS) $(FMA_FLAGS) $(DEBUG_FLAGS) $(DEFINES) $(INCLUDE_PATH)



# Getting list of source files
ASSETS_FILES           = $(shell find $(ASSETS_DIR)/ -type f | grep -ve .gitignore -ve generated/assets.S                                               2> /dev/null)
COMMON_ASM_SOURCES     = $(shell find $(COMMON_DIR)/$(SOURCE_ASM_DIR)/arch/$(ARCH)/                                                       -name '*.S'   2> /dev/null)
COMMON_CPP_SOURCES     = $(shell find $(COMMON_DIR)/$(SOURCE_CPP_DIR)/                                                                    -name '*.cpp' 2> /dev/null)
KERNELBASE_ASM_SOURCES = $(shell find $(KERNELBASE_DIR)/$(SOURCE_ASM_DIR)/arch/$(ARCH)/                                                   -name '*.S'   2> /dev/null)
KERNELBASE_CPP_SOURCES = $(shell find $(KERNELBASE_DIR)/$(SOURCE_CPP_DIR)/ $(KERNELBASE_DIR)/$(TEST_CPP_DIR)/                             -name '*.cpp' 2> /dev/null)
ASM_SOURCES            = $(shell find $(SOURCE_ASM_DIR)/arch/$(ARCH)/                                                                     -name '*.S'   2> /dev/null)
CPP_SOURCES            = $(shell find $(SOURCE_CPP_DIR)/ $(TEST_CPP_DIR)/                                                                 -name '*.cpp' 2> /dev/null)
CPP_HEADERS            = $(shell find $(SOURCE_CPP_DIR)/ $(TEST_CPP_DIR)/ $(COMMON_DIR)/ $(KERNELBASE_DIR)/ ../../../include/ ../include/ -name '*.h'   2> /dev/null)

# Getting list of object files
ASSETS_OBJ         = $(OUTPUT_DIR)/$(ASSETS_DIR)/generated/assets.o
COMMON_ASM_OBJ     = $(addprefix $(OUTPUT_DIR)/,$(COMMON_ASM_SOURCES:../common/%.S=common/%.o))
COMMON_CPP_OBJ     = $(addprefix $(OUTPUT_DIR)/,$(COMMON_CPP_SOURCES:../common/%.cpp=common/%.o))
KERNELBASE_ASM_OBJ = $(addprefix $(OUTPUT_DIR)/,$(KERNELBASE_ASM_SOURCES:../kernelbase/%.S=kernelbase/%.o))
KERNELBASE_CPP_OBJ = $(addprefix $(OUTPUT_DIR)/,$(KERNELBASE_CPP_SOURCES:../kernelbase/%.cpp=kernelbase/%.o))
ASM_OBJ            = $(addprefix $(OUTPUT_DIR)/,$(ASM_SOURCES:%.S=%.o))
CPP_OBJ            = $(addprefix $(OUTPUT_DIR)/,$(CPP_SOURCES:%.cpp=%.o))

OBJECTS = $(ASSETS_OBJ) $(COMMON_ASM_OBJ) $(COMMON_CPP_OBJ) $(KERNELBASE_ASM_OBJ) $(KERNELBASE_CPP_OBJ) $(ASM_OBJ) $(CPP_OBJ)



all: $(OUTPUT_DIR)/$(TARGET).elf$(ZIP_EXT)

$(OUTPUT_DIR)/$(TARGET).elf$(ZIP_EXT): $(OBJECTS) linker.ld
	$(LD) -T linker.ld --emit-relocs $(OBJECTS) -o $(OUTPUT_DIR)/$(TARGET).elf
	$(ZIP_COMMAND)

$(ASSETS_OBJ): $(ASSETS_FILES)
	sh -c "cd $(ASSETS_DIR)/ && ./generate_assets.sh"
	$(MKDIR) $(@D)
	$(CC) $(ASMFLAGS) $(ASSETS_DIR)/generated/assets.S -o $@

$(OUTPUT_DIR)/common/%.o: $(COMMON_DIR)/%.S $(CPP_HEADERS)
	$(MKDIR) $(@D)
	$(CC) $(ASMFLAGS) $< -o $@

$(OUTPUT_DIR)/common/%.o: $(COMMON_DIR)/%.cpp $(CPP_HEADERS)
	$(MKDIR) $(@D)
	$(CXX) $(CXXFLAGS) -E $< -o $@.cpp
	$(CXX) $(CXXFLAGS) -S $< -o $@.S
	$(CXX) $(CXXFLAGS) $< -o $@

$(OUTPUT_DIR)/kernelbase/%.o: $(KERNELBASE_DIR)/%.S $(CPP_HEADERS)
	$(MKDIR) $(@D)
	$(CC) $(ASMFLAGS) $< -o $@

$(OUTPUT_DIR)/kernelbase/%.o: $(KERNELBASE_DIR)/%.cpp $(CPP_HEADERS)
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
