SUBDIRS = \
	boot \
	configure \
	kernel \
	installer \
	bootloader



all: $(SUBDIRS)

clean: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ -j8 $(MAKECMDGOALS)



.PHONY: $(SUBDIRS)
