MKDIR = mkdir -p
RMDIR = rm -rf
COPY  = cp



LIBRARIES_DIR = libs
FREETYPE_DIR  = $(LIBRARIES_DIR)/freetype



TARGET_FREETYPE = $(FREETYPE_DIR)/objs/.libs/libfreetype.so



ALL_TARGETS = \
	$(TARGET_FREETYPE)



all: $(ALL_TARGETS)



clean:
	$(RMDIR) $(LIBRARIES_DIR)



$(TARGET_FREETYPE): $(FREETYPE_DIR)
	bash -c "cd $(FREETYPE_DIR) && ./configure && make -j`nproc`"



$(FREETYPE_DIR):
	./fetch_freetype.sh
