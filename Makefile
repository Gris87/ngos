ARCH = $(shell grep "define NGOS_BUILD_ARCH" include/buildconfig.h | sed -r "s/  */ /g" | cut -d " " -f 3 | sed -r "s/OPTION_ARCH_//g" | tr "[:upper:]" "[:lower:]")

OUTPUT_DIR   = build
BUILD_CONFIG = include/buildconfig.h

MKDIR = mkdir -p
RMDIR = rm -rf
COPY  = cp



SUBDIRS = \
	3rd_party \
	tools \
	src



TARGET_APPS = \
	$(OUTPUT_DIR)/deployment/com.ngos.bootloader/bootx64.efi \
	$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/devicemanager.efi \
	$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/cputest.efi \
	$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/memorytest.efi \
	$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/networktest.efi \
	$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/hddtest.efi \
	$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/partitionwizard.efi \
	$(OUTPUT_DIR)/deployment/com.ngos.kernel/kernel.efi \
	$(OUTPUT_DIR)/deployment/com.ngos.installer/installer.efi



.NOTPARALLEL:



all: $(SUBDIRS) $(TARGET_APPS)

$(OUTPUT_DIR)/deployment/com.ngos.bootloader/bootx64.efi: src/os/boot/build/boot.elf src/os/bootloader/build/bootloader.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -t src/os/bootloader/build/bootloader.elf -o $@
	./scripts/sign_uefi_application.sh $@

$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/devicemanager.efi: src/os/boot/build/boot.elf src/os/bootloader_tools/devicemanager/build/devicemanager.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -t src/os/bootloader_tools/devicemanager/build/devicemanager.elf -o $@
	./scripts/sign_uefi_application.sh $@

$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/cputest.efi: src/os/boot/build/boot.elf src/os/bootloader_tools/cputest/build/cputest.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -t src/os/bootloader_tools/cputest/build/cputest.elf -o $@
	./scripts/sign_uefi_application.sh $@

$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/memorytest.efi: src/os/boot/build/boot.elf src/os/bootloader_tools/memorytest/build/memorytest.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -t src/os/bootloader_tools/memorytest/build/memorytest.elf -o $@
	./scripts/sign_uefi_application.sh $@

$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/networktest.efi: src/os/boot/build/boot.elf src/os/bootloader_tools/networktest/build/networktest.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -t src/os/bootloader_tools/networktest/build/networktest.elf -o $@
	./scripts/sign_uefi_application.sh $@

$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/hddtest.efi: src/os/boot/build/boot.elf src/os/bootloader_tools/hddtest/build/hddtest.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -t src/os/bootloader_tools/hddtest/build/hddtest.elf -o $@
	./scripts/sign_uefi_application.sh $@

$(OUTPUT_DIR)/deployment/com.ngos.bootloader/tools/partitionwizard.efi: src/os/boot/build/boot.elf src/os/bootloader_tools/partitionwizard/build/partitionwizard.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -t src/os/bootloader_tools/partitionwizard/build/partitionwizard.elf -o $@
	./scripts/sign_uefi_application.sh $@

$(OUTPUT_DIR)/deployment/com.ngos.kernel/kernel.efi: src/os/boot/build/boot.elf src/os/configure/build/configure.elf src/os/kernel/build/kernel.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -c src/os/configure/build/configure.elf -k src/os/kernel/build/kernel.elf -o $@
	./scripts/sign_uefi_application.sh $@

$(OUTPUT_DIR)/deployment/com.ngos.installer/installer.efi: src/os/boot/build/boot.elf src/os/configure/build/configure.elf src/os/installer/build/installer.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -c src/os/configure/build/configure.elf -i src/os/installer/build/installer.elf -o $@
	./scripts/sign_uefi_application.sh $@



clean: $(SUBDIRS)
	$(RMDIR) $(OUTPUT_DIR)



3rd_party:
	$(MAKE) -C $@ $(MAKECMDGOALS)

tools:
	cd $@ && \
	lupdate -noobsolete $@.pro && \
	lrelease $@.pro && \
	qmake $@.pro || \
	exit 1 ; \
	\
	for line in `find -type d -maxdepth 1 2> /dev/null | cut -c 3-` ; \
	do \
		if [ -f "$${line}/$${line}.pro" ]; then \
			cd $${line} && \
			lupdate -noobsolete $${line}.pro && \
			lrelease $${line}.pro && \
			qmake $${line}.pro || \
			exit 1 ; \
			\
			for line2 in `find -type d -maxdepth 1 2> /dev/null | cut -c 3-` ; \
			do \
				if [ -f "$${line2}/$${line2}.pro" ]; then \
					cd $${line2} && \
					lupdate -noobsolete $${line2}.pro && \
					lrelease $${line2}.pro && \
					qmake $${line2}.pro || \
					exit 1 ; \
					cd .. ; \
				fi \
			done ; \
			\
			sed -i "s/\$$(MAKE) -f Makefile/\$$(MAKE) -f Makefile -j\`nproc\`/g" Makefile || \
			exit 1 ; \
			\
			cd .. ; \
		fi \
	done ; \
	\
	make $(MAKECMDGOALS) || \
	exit 1

src:
	bash -c "cd $@ && lupdate -noobsolete $@.pro && lrelease $@.pro && ../tools/qt/qmake/build/qmake $@.pro && make -j`nproc` $(MAKECMDGOALS)"



help:
	@echo "Available targets:"
	@echo "    all              - Build all the source code"
	@echo "    clean            - Delete all files that appears during the build process"
	@echo "    deployment       - Prepare binaries for deployment"
	@echo "    config           - Build and run build_config_gui tool in order to update build configuration"
	@echo "    generate         - Build and run code_generator tool in order to update generated files"
	@echo "    verify           - Build and run code_verifier tool in order to verify the source code"
	@echo "    verify-tests     - Build and run test_verifier tool in order to verify test coverage"
	@echo "    verify-docs      - Build and run docs_verifier tool in order to verify documents"
	@echo "    test             - Perform kernel testing"
	@echo "    debug            - Build the source code in debug mode"
	@echo "    release          - Build the source code in release mode"
	@echo "    test-debug       - Build the source code in debug mode with the tests included"
	@echo "    test-release     - Build the source code in release mode with the tests included"
	@echo "    run-debug        - Build the source code in debug mode and run kernel on the VM"
	@echo "    run-release      - Build the source code in release mode and run kernel on the VM"
	@echo "    run-test-debug   - Build the source code in debug mode with the tests included and run kernel on the VM. Preferable target for development"
	@echo "    run-test-release - Build the source code in release mode with the tests included and run kernel on the VM"
	@echo "    run-vm           - Run kernel on the VM (QEMU-KVM by default)"
	@echo "    run-qemu-kvm     - Run kernel on the QEMU-KVM VM"
	@echo "    run-qemu         - Run kernel on the QEMU VM"
	@echo "    run-vbox         - Run kernel on the VirtualBox VM"



deployment: generate
	bash -c "cd tools/qt/build_config_maker/ && lupdate -noobsolete build_config_maker.pro && lrelease build_config_maker.pro && qmake build_config_maker.pro && make -j`nproc`"
	tools/qt/build_config_maker/build/build_config_maker $(BUILD_CONFIG) --reset
	$(MAKE) all



config:
	bash -c "cd tools/qt/build_config_gui/ && lupdate -noobsolete build_config_gui.pro && lrelease build_config_gui.pro && qmake build_config_gui.pro && make -j`nproc`"
	tools/qt/build_config_gui/build/build_config_gui



generate:
	bash -c "cd 3rd_party/ && make"
	bash -c "cd tools/qt/code_generator/ && lupdate -noobsolete code_generator.pro && lrelease code_generator.pro && qmake code_generator.pro && make -j`nproc`"
	tools/qt/code_generator/build/code_generator .



verify:
	bash -c "cd tools/qt/code_verifier/ && lupdate -noobsolete code_verifier.pro && lrelease code_verifier.pro && qmake code_verifier.pro && make -j`nproc`"
	tools/qt/code_verifier/build/code_verifier .



verify-tests:
	bash -c "cd tools/qt/test_verifier/ && lupdate -noobsolete test_verifier.pro && lrelease test_verifier.pro && qmake test_verifier.pro && make -j`nproc`"
	tools/qt/test_verifier/build/test_verifier .



verify-docs:
	bash -c "cd tools/qt/docs_verifier/ && lupdate -noobsolete docs_verifier.pro && lrelease docs_verifier.pro && qmake docs_verifier.pro && make -j`nproc`"
	tools/qt/docs_verifier/build/docs_verifier .



test:
	bash -c "cd test/ && ./start.sh"



debug:
	bash -c "cd tools/qt/build_config_maker/ && lupdate -noobsolete build_config_maker.pro && lrelease build_config_maker.pro && qmake build_config_maker.pro && make -j`nproc`"
	tools/qt/build_config_maker/build/build_config_maker $(BUILD_CONFIG) NGOS_BUILD_RELEASE=OPTION_NO NGOS_BUILD_TEST_MODE=OPTION_NO
	$(MAKE) all



release:
	bash -c "cd tools/qt/build_config_maker/ && lupdate -noobsolete build_config_maker.pro && lrelease build_config_maker.pro && qmake build_config_maker.pro && make -j`nproc`"
	tools/qt/build_config_maker/build/build_config_maker $(BUILD_CONFIG) NGOS_BUILD_RELEASE=OPTION_YES NGOS_BUILD_TEST_MODE=OPTION_NO
	$(MAKE) all



test-debug:
	bash -c "cd tools/qt/build_config_maker/ && lupdate -noobsolete build_config_maker.pro && lrelease build_config_maker.pro && qmake build_config_maker.pro && make -j`nproc`"
	tools/qt/build_config_maker/build/build_config_maker $(BUILD_CONFIG) NGOS_BUILD_RELEASE=OPTION_NO NGOS_BUILD_TEST_MODE=OPTION_YES
	$(MAKE) all



test-release:
	bash -c "cd tools/qt/build_config_maker/ && lupdate -noobsolete build_config_maker.pro && lrelease build_config_maker.pro && qmake build_config_maker.pro && make -j`nproc`"
	tools/qt/build_config_maker/build/build_config_maker $(BUILD_CONFIG) NGOS_BUILD_RELEASE=OPTION_YES NGOS_BUILD_TEST_MODE=OPTION_YES
	$(MAKE) all



run-debug: debug run-vm

run-release: release run-vm

run-test-debug: test-debug run-vm

run-test-release: test-release run-vm



run-vm: run-qemu-kvm

run-qemu-kvm:
	bash -c "cd tools/vm/ && ./start_vm.sh qemu-kvm"

run-qemu:
	bash -c "cd tools/vm/ && ./start_vm.sh qemu"

run-vbox:
	bash -c "cd tools/vm/ && ./start_vm.sh vbox"



.PHONY: $(SUBDIRS) test
