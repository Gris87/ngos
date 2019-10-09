MKDIR = mkdir -p
RMDIR = rm -rf
COPY  = cp



LIBRARIES_DIR   = libs
FREETYPE_DIR    = $(LIBRARIES_DIR)/freetype
SHELLBINPKG_DIR = $(LIBRARIES_DIR)/ShellBinPkg



TARGET_FREETYPE    = $(FREETYPE_DIR)/objs/.libs/libfreetype.a
TARGET_SHELLBINPKG = $(SHELLBINPKG_DIR)/UefiShell



ALL_TARGETS = \
	$(TARGET_FREETYPE) \
	$(TARGET_SHELLBINPKG)



all: $(ALL_TARGETS)



clean:
	$(RMDIR) $(LIBRARIES_DIR)



$(TARGET_FREETYPE): $(FREETYPE_DIR)
	bash -c "cd $(FREETYPE_DIR) && ./configure && make -j`nproc`"



$(TARGET_SHELLBINPKG): $(SHELLBINPKG_DIR)



$(FREETYPE_DIR):
	./fetch_freetype.sh



$(SHELLBINPKG_DIR):
	./fetch_shellbinpkg.sh
