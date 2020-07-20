MKDIR = mkdir -p
RMDIR = rm -rf
COPY  = cp



LIBRARIES_DIR = libs
FREETYPE_DIR  = $(LIBRARIES_DIR)/freetype
POPPLER_DIR   = $(LIBRARIES_DIR)/poppler



TARGET_FREETYPE = $(FREETYPE_DIR)/objs/.libs/libfreetype.a
TARGET_POPPLER  = $(POPPLER_DIR)/build/abc



ALL_TARGETS = \
	$(TARGET_FREETYPE) \
	$(TARGET_POPPLER)



all: $(ALL_TARGETS)



clean:
	$(RMDIR) $(LIBRARIES_DIR)



$(TARGET_FREETYPE): $(FREETYPE_DIR)
	bash -c "cd $(FREETYPE_DIR) && ./configure && make -j`nproc`"



$(TARGET_POPPLER): $(POPPLER_DIR)
	bash -c "cd $(POPPLER_DIR) && mkdir build && cd build && cmake .. && make -j`nproc`"



$(FREETYPE_DIR):
	./fetch_freetype.sh



$(POPPLER_DIR):
	./fetch_poppler.sh
