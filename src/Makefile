SUBDIRS = \
	os \
	libs \
	apps



all: $(SUBDIRS)

clean: $(SUBDIRS)

$(SUBDIRS):
	sh -c "cd $@ && qmake $@.pro && make $(MAKECMDGOALS)"



.PHONY: $(SUBDIRS)
