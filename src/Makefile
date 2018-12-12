SUBDIRS = \
	os \
	libs \
	apps



all: $(SUBDIRS)

clean: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)



.PHONY: $(SUBDIRS)
