ARCH = $(shell grep "define NGOS_BUILD_ARCH" ../include/buildconfig.h | sed -r "s/  */ /g" | cut -d " " -f 3 | sed -r "s/OPTION_ARCH_//g" | tr "[:upper:]" "[:lower:]")

MKDIR = mkdir -p
RMDIR = rm -rf



EDK2_ARCH = X64

ifeq ($(ARCH), x86_64)
	EDK2_ARCH = X64
endif



LIBRARIES_DIR = libs
FREETYPE_DIR  = $(LIBRARIES_DIR)/freetype
EDK2_DIR      = $(LIBRARIES_DIR)/edk2



TARGET_FREETYPE = $(FREETYPE_DIR)/objs/.libs/libfreetype.a
TARGET_EDK2     = $(EDK2_DIR)/Build/Shell/RELEASE_GCC5/$(EDK2_ARCH)/ShellPkg/Application/Shell/Shell/OUTPUT/Shell.efi



ALL_TARGETS = \
	$(TARGET_FREETYPE) \
	$(TARGET_EDK2)



all: $(ALL_TARGETS)



clean:
	$(RMDIR) $(LIBRARIES_DIR)



$(TARGET_FREETYPE): $(FREETYPE_DIR)
	sh -c "cd $(FREETYPE_DIR) && ./configure && make -j`nproc`"



$(TARGET_EDK2): $(EDK2_DIR)
	sh -c "cd $(EDK2_DIR) && source edksetup.sh BaseTools && make -C BaseTools/ && build -a $(EDK2_ARCH) -t GCC5 -b RELEASE -n `nproc` -p ShellPkg/ShellPkg.dsc && cp Build/Shell/RELEASE_GCC5/$(EDK2_ARCH)/ShellPkg/Application/Shell/Shell/OUTPUT/Shell.efi Build/shell.efi"



$(FREETYPE_DIR):
	./fetch_freetype.sh



$(EDK2_DIR):
	./fetch_edk2.sh
