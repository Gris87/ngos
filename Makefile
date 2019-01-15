OUTPUT_DIR = build
BUILD_CONFIG = include/buildconfig.h

MKDIR = mkdir -p
RMDIR = rm -rf



SUBDIRS = \
	3rd_party \
	src \
	tools



all: $(SUBDIRS) $(OUTPUT_DIR)/NGOS_kernel.bin $(OUTPUT_DIR)/NGOS_installer.bin

$(OUTPUT_DIR)/NGOS_kernel.bin: src/os/boot/build/boot.elf src/os/configure/build/configure.elf src/os/kernel/build/kernel.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -c src/os/configure/build/configure.elf -k src/os/kernel/build/kernel.elf -o $@

$(OUTPUT_DIR)/NGOS_installer.bin: src/os/boot/build/boot.elf src/os/configure/build/configure.elf src/os/installer/build/installer.elf tools/qt/image_builder/build/image_builder
	$(MKDIR) $(@D)
	tools/qt/image_builder/build/image_builder -b src/os/boot/build/boot.elf -c src/os/configure/build/configure.elf -i src/os/installer/build/installer.elf -o $@

clean: $(SUBDIRS)
	$(RMDIR) $(OUTPUT_DIR)



$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)



help:
	@echo "Available targets:"
	@echo "    all              - Build all the source code"
	@echo "    clean            - Delete all files that appears during the build process"
	@echo "    config           - Build and run build_config_gui tool in order to update build configuration"
	@echo "    generate         - Build and run code_generator tool in order to update generated files"
	@echo "    verify           - Build and run code_verifier tool in order to verify the source code"
	@echo "    verify-tests     - Build and run test_verifier tool in order to verify test filling"
	@echo "    verify-docs      - Build and run docs_verifier tool in order to verify documents"
	@echo "    test             - Perform kernel testing"
	@echo "    run-gdb-debug    - Build the source code in debug mode and run gdb_debug tool"
	@echo "    debug            - Build the source code in debug mode"
	@echo "    release          - Build the source code in release mode"
	@echo "    test-debug       - Build the source code in debug mode with the tests included"
	@echo "    test-release     - Build the source code in release mode with the tests included"
	@echo "    run-debug        - Build the source code in debug mode and run kernel on the VM"
	@echo "    run-release      - Build the source code in release mode and run kernel on the VM"
	@echo "    run-test-debug   - Build the source code in debug mode with the tests included and run kernel on the VM. Preferable target for development"
	@echo "    run-test-release - Build the source code in release mode with the tests included and run kernel on the VM"
	@echo "    run-vm           - Run kernel on the VM (QEMU by default)"
	@echo "    run-qemu-kvm     - Run kernel on the QEMU-KVM VM"
	@echo "    run-qemu         - Run kernel on the QEMU VM"
	@echo "    run-vbox         - Run kernel on the VirtualBox VM"



config:
	sh -c "cd tools/qt/build_config_gui/ && qmake build_config_gui.pro && make -j8"
	tools/qt/build_config_gui/build/build_config_gui



generate:
	sh -c "cd 3rd_party/ && make"
	sh -c "cd tools/qt/code_generator/ && qmake code_generator.pro && make -j8"
	tools/qt/code_generator/build/code_generator .



verify:
	sh -c "cd tools/qt/code_verifier/ && qmake code_verifier.pro && make -j8"
	tools/qt/code_verifier/build/code_verifier .



verify-tests:
	sh -c "cd tools/qt/test_verifier/ && qmake test_verifier.pro && make -j8"
	tools/qt/test_verifier/build/test_verifier .



verify-docs:
	sh -c "cd tools/qt/docs_verifier/ && qmake docs_verifier.pro && make -j8"
	tools/qt/docs_verifier/build/docs_verifier .



test:
	sh -c "cd test/ && ./start.sh"



run-gdb-debug: test-debug
	tools/qt/gdb_debug/build/gdb_debug --auto



debug:
	sh -c "cd tools/qt/build_config_maker/ && qmake build_config_maker.pro && make -j8"
	tools/qt/build_config_maker/build/build_config_maker $(BUILD_CONFIG) NGOS_BUILD_RELEASE=OPTION_NO NGOS_BUILD_TEST_MODE=OPTION_NO
	$(MAKE) all



release:
	sh -c "cd tools/qt/build_config_maker/ && qmake build_config_maker.pro && make -j8"
	tools/qt/build_config_maker/build/build_config_maker $(BUILD_CONFIG) NGOS_BUILD_RELEASE=OPTION_YES NGOS_BUILD_TEST_MODE=OPTION_NO
	$(MAKE) all



test-debug:
	sh -c "cd tools/qt/build_config_maker/ && qmake build_config_maker.pro && make -j8"
	tools/qt/build_config_maker/build/build_config_maker $(BUILD_CONFIG) NGOS_BUILD_RELEASE=OPTION_NO NGOS_BUILD_TEST_MODE=OPTION_YES
	$(MAKE) all



test-release:
	sh -c "cd tools/qt/build_config_maker/ && qmake build_config_maker.pro && make -j8"
	tools/qt/build_config_maker/build/build_config_maker $(BUILD_CONFIG) NGOS_BUILD_RELEASE=OPTION_YES NGOS_BUILD_TEST_MODE=OPTION_YES
	$(MAKE) all



run-debug: debug run-vm

run-release: release run-vm

run-test-debug: test-debug run-vm

run-test-release: test-release run-vm



run-vm: run-qemu

run-qemu-kvm:
	sh -c "cd tools/vm/ && ./start_vm.sh qemu-kvm"

run-qemu:
	sh -c "cd tools/vm/ && ./start_vm.sh qemu"

run-vbox:
	sh -c "cd tools/vm/ && ./start_vm.sh vbox"



.PHONY: $(SUBDIRS) test
