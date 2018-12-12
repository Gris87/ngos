SUBDIRS = \
	build_config_gui \
	build_config_maker \
	code_generator \
	code_verifier \
	docs_verifier \
	gdb_debug \
	image_builder \
	test_verifier



all: $(SUBDIRS)

clean: $(SUBDIRS)

$(SUBDIRS):
	sh -c "cd $@ && qmake $@.pro && make -j8 $(MAKECMDGOALS)"



.PHONY: $(SUBDIRS)
