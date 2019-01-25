NGOS
====

0.4. How to build
-----------------

You have to install prerequisites before building the source code.

* [Install prerequisites on Ubuntu 18.10](../2.%20Getting%20started/1.%20Install%20prerequisites%20on%20Ubuntu%2018.10/README.md)
* [Install prerequisites on Ubuntu 18.04](../2.%20Getting%20started/2.%20Install%20prerequisites%20on%20Ubuntu%2018.04/README.md)
* [Install prerequisites on Ubuntu 16.04](../2.%20Getting%20started/3.%20Install%20prerequisites%20on%20Ubuntu%2016.04/README.md)
* [Install prerequisites on CentOS 7.6](../2.%20Getting%20started/4.%20Install%20prerequisites%20on%20CentOS%207.6/README.md)

You can also change the build configuration if needed. Please read [for more details](../3.%20Configuration/README.md).

Build targets
-------------

The list of available targets can be found with the following command started at the project root:

```sh
$ make help
```

Here is the output example:

```
Available targets:
    all              - Build all the source code
    clean            - Delete all files that appears during the build process
    config           - Build and run build_config_gui tool in order to update build configuration
    generate         - Build and run code_generator tool in order to update generated files
    verify           - Build and run code_verifier tool in order to verify the source code
    verify-tests     - Build and run test_verifier tool in order to verify test filling
    verify-docs      - Build and run docs_verifier tool in order to verify documents
    test             - Perform kernel testing
    run-gdb-debug    - Build the source code in debug mode and run gdb_debug tool
    debug            - Build the source code in debug mode
    release          - Build the source code in release mode
    test-debug       - Build the source code in debug mode with the tests included
    test-release     - Build the source code in release mode with the tests included
    run-debug        - Build the source code in debug mode and run kernel on the VM
    run-release      - Build the source code in release mode and run kernel on the VM
    run-test-debug   - Build the source code in debug mode with the tests included and run kernel on the VM. Preferable target for development
    run-test-release - Build the source code in release mode with the tests included and run kernel on the VM
    run-vm           - Run kernel on the VM (QEMU by default)
    run-qemu-kvm     - Run kernel on the QEMU-KVM VM
    run-qemu         - Run kernel on the QEMU VM
    run-vbox         - Run kernel on the VirtualBox VM
```

Please use `make` command to obtain binaries that you can apply to your machine.
