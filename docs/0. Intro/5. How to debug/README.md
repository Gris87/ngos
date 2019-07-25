NGOS
====

0.5. How to debug
-----------------

GDB, the GNU Project debugger, allows you to see what is going on inside another program while it executes -- or what another program was doing at the moment it crashed.

GDB can do four main kinds of things (plus other things in support of these) to help you catch bugs in the act:
* Start your program, specifying anything that might affect its behavior.
* Make your program stop on specified conditions.
* Examine what has happened, when your program has stopped.
* Change things in your program, so you can experiment with correcting the effects of one bug and go on to learn about another.

You should start QEMU virtual machine before start debugging with one of the following commands:

```
make run-test-debug
```

or

```
cd tools/vm/ && ./start_vm.sh qemu vnc ngos
```

It is also possible to start another kernels with commands:

```
cd tools/vm/ && ./start_vm.sh qemu vnc ngos_installer
cd tools/vm/ && ./start_vm.sh qemu vnc linux
cd tools/vm/ && ./start_vm.sh qemu vnc win7
cd tools/vm/ && ./start_vm.sh qemu vnc win10
```

If you are running NGOS kernel built in Debug mode you will have 5 seconds delay in order to establish GDB remote connection with the commands:

```
gdb
(gdb) set architecture i386:x86-64:intel
(gdb) target remote :1234
```

After that you can load symbols with the commands:

```
(gdb) add-symbol-file-all src/os/configure/build/configure.elf 0x3E40F220
(gdb) add-symbol-file-all src/os/configure/build/configure.elf 0x02000000
(gdb) add-symbol-file-all src/os/kernel/build/kernel.elf -0xFFFFFFFF80000000+0x10000000
(gdb) add-symbol-file-all src/os/kernel/build/kernel.elf -0xFFFFFFFF80000000+0xFFFFFFFF80000000
```

Where:
* 0x3E40F220 - Address of first kernel instruction when UEFI loads image in memory
* 0x02000000 - Address of relocated kernel in low address space
* 0x10000000 - Random address of kernel in Physical address space
* 0xFFFFFFFF80000000 - Random address of kernel in Virtual address space

`add-symbol-file-all` is user defined GDB command. You should install it first with:

```
cd tools/gdb
./install.sh
```

You may do the debugging as you wish from this moment.

### Additional GDB commands

Here is the list of useful GDB commands:

* `symbol-file` - call this command to remove all symbols that you may load again with `add-symbol-file-all`
* `dump binary memory result.bin 0x0000000000000000 0x000000003FFFFFFF` - this command dumps memory range to the external file on your hard disk
* `x/10xg 0x01000000` - dumps ten 64 bit integers in HEX format. Please check `help x` for more output options
* `x/60i 0x01000000` - prints 60 instructions starting from specified address
* `x/60i $pc` - prints 60 instructions starting from current instruction
* `br *0x01000000` - puts breakpoint at specified address
* `c` - continue execution until breakpoint reached or Ctrl+C pressed
* `ni` - execute current instruction. Jump over function call
* `si` - execute current instruction. Step into function call
* `i r` - prints register values
* `i th` - prints information about currently running threads
* `t 2` - switch to thread specified by thread ID
