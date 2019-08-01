SUBDIRS = \
	os \
	libs \
	apps



all: $(SUBDIRS)

clean: $(SUBDIRS)

$(SUBDIRS):
	sh -c "cd $@ && ../../tools/qt/qmake/build/qmake $@.pro && make $(MAKECMDGOALS)"



.PHONY: $(SUBDIRS)
