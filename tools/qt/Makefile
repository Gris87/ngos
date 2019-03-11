SUBDIRS = \
	build_config_gui \
	build_config_maker \
	code_generator \
	code_verifier \
	docs_verifier \
	gdb_debug \
	image_builder \
	test_verifier \
	usb_boot_maker



all: $(SUBDIRS)

clean: $(SUBDIRS)

$(SUBDIRS):
	sh -c "cd $@ && qmake $@.pro && make -j`nproc` $(MAKECMDGOALS)"



.PHONY: $(SUBDIRS)
