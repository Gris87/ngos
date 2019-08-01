NGOS
====

0.7.09. GDB debug
-----------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/tools/qt/gdb_debug/Screenshot.png?raw=true" alt="Screenshot"/>
</p>

GDB debug tool let you debug kernel source code with simplifying interaction with gdb.

### Usage

```sh
gdb_debug [--auto]
```

### How to ...

If you call GDB debug tool with `--auto` option it will automatically start QEMU VM with the built kernel.

Press restart button ![Restart button](../../../../tools/qt/gdb_debug/assets/images/restart.png) to restart QEMU VM and restart debugging.<br/>
It takes some time to start VM and to get memory content.

Use start/stop button ![Start button](../../../../tools/qt/gdb_debug/assets/images/start.png)/![Stop button](../../../../tools/qt/gdb_debug/assets/images/stop.png) to continue/terminate kernel.

If you press next step button ![Next step button](../../../../tools/qt/gdb_debug/assets/images/next.png) it will execute current assembler instruction and will update memory snapshot.

Use Tools -> Show memory map to display memory with the minimal size and to perform fast jump to some place in memory.

You also can jump to some address if you double click this address on Assembler view.

Press back button ![Back button](../../../../tools/qt/gdb_debug/assets/images/back.png) to return back to currently executing Assembler instruction.

You can use Data inspector view to look up data value in some place in memory.
