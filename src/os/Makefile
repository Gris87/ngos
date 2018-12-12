SUBDIRS = \
	boot \
	configure \
	kernel \
	installer



all: $(SUBDIRS)

clean: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ -j8 $(MAKECMDGOALS)



.PHONY: $(SUBDIRS)
