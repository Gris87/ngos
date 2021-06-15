QT -= gui

CONFIG += c++20

TARGET   = kernel
TEMPLATE = kernel

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_KERNEL



INCLUDEPATH += \
    src \                       # src/os/kernel/src
    test \                      # src/os/kernel/test
    ../shared/common/src \      # src/os/shared/common/src
    ../shared/uefibase/src \    # src/os/shared/uefibase/src
    ../shared/uefibase/test \   # src/os/shared/uefibase/test
    ../../../include \          # include
    ../../../include/stdinc     # include/stdinc



include(../shared/common/common.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    --emit-relocs \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/com/ngos/kernel/a_early/main/setupidthandlers.S \
    asm/arch/x86_64/com/ngos/kernel/main.S \
    src/com/ngos/kernel/a_early/main/disableirq.cpp \
    src/com/ngos/kernel/a_early/main/reservepciromimages.cpp \
    src/com/ngos/kernel/a_early/main/setupbootparams.cpp \
    src/com/ngos/kernel/a_early/main/setupbrk.cpp \
    src/com/ngos/kernel/a_early/main/setupcr4shadow.cpp \
    src/com/ngos/kernel/a_early/main/setupdmi.cpp \
    src/com/ngos/kernel/a_early/main/setupe820tables.cpp \
    src/com/ngos/kernel/a_early/main/setupfirstcpu.cpp \
    src/com/ngos/kernel/a_early/main/setuphypervisor.cpp \
    src/com/ngos/kernel/a_early/main/setupidthandlers.cpp \
    src/com/ngos/kernel/a_early/main/setupinittask.cpp \
    src/com/ngos/kernel/a_early/main/setupioremap.cpp \
    src/com/ngos/kernel/a_early/main/setupmemorymanager.cpp \
    src/com/ngos/kernel/a_early/main/setupstackcanary.cpp \
    src/com/ngos/kernel/a_early/main/setupuefimemorymap.cpp \
    src/com/ngos/kernel/a_early/main/setupuefisystemtable.cpp \
    src/com/ngos/kernel/a_early/other/adaptpagetable.cpp \
    src/com/ngos/kernel/main.cpp \
    src/com/ngos/kernel/other/bootparams/bootparams.cpp \
    src/com/ngos/kernel/other/brk/brk.cpp \
    src/com/ngos/kernel/other/cpu/cpumask.cpp \
    src/com/ngos/kernel/other/cpu/hotplug/cpuhotplug.cpp \
    src/com/ngos/kernel/other/cpu/percpu.cpp \
    src/com/ngos/kernel/other/e820/e820.cpp \
    src/com/ngos/kernel/other/hypervisor/hypervisor.cpp \
    src/com/ngos/kernel/other/hypervisor/kvm/clock/kvmclock.cpp \
    src/com/ngos/kernel/other/hypervisor/kvm/kvm.cpp \
    src/com/ngos/kernel/other/ioremap/ioremap.cpp \
    src/com/ngos/kernel/other/irq/irqstack.cpp \
    src/com/ngos/kernel/other/memorymanager/memorymanager.cpp \
    src/com/ngos/kernel/other/pagetable/addressconversion.cpp \
    src/com/ngos/kernel/other/pagetable/dynamicpagetable.cpp \
    src/com/ngos/kernel/other/task/task.cpp \
    src/com/ngos/kernel/other/task/utils.cpp \
    src/com/ngos/kernel/other/uefi/uefi.cpp \
    test/com/ngos/kernel/a_early/testresults.cpp

HEADERS += \
    src/com/ngos/kernel/a_early/main/asm_setupidthandlers.h \
    src/com/ngos/kernel/a_early/main/disableirq.h \
    src/com/ngos/kernel/a_early/main/reservepciromimages.h \
    src/com/ngos/kernel/a_early/main/setupbootparams.h \
    src/com/ngos/kernel/a_early/main/setupbrk.h \
    src/com/ngos/kernel/a_early/main/setupcr4shadow.h \
    src/com/ngos/kernel/a_early/main/setupdmi.h \
    src/com/ngos/kernel/a_early/main/setupe820tables.h \
    src/com/ngos/kernel/a_early/main/setupfirstcpu.h \
    src/com/ngos/kernel/a_early/main/setuphypervisor.h \
    src/com/ngos/kernel/a_early/main/setupidthandlers.h \
    src/com/ngos/kernel/a_early/main/setupinittask.h \
    src/com/ngos/kernel/a_early/main/setupioremap.h \
    src/com/ngos/kernel/a_early/main/setupmemorymanager.h \
    src/com/ngos/kernel/a_early/main/setupstackcanary.h \
    src/com/ngos/kernel/a_early/main/setupuefimemorymap.h \
    src/com/ngos/kernel/a_early/main/setupuefisystemtable.h \
    src/com/ngos/kernel/other/bootparams/bootparams.h \
    src/com/ngos/kernel/other/brk/brk.h \
    src/com/ngos/kernel/other/cpu/cpumask.h \
    src/com/ngos/kernel/other/cpu/hotplug/cpuhotplug.h \
    src/com/ngos/kernel/other/cpu/hotplug/cpuhotplugstate.h \
    src/com/ngos/kernel/other/cpu/hotplug/cpuhotplugstep.h \
    src/com/ngos/kernel/other/cpu/percpu.h \
    src/com/ngos/kernel/other/e820/e820.h \
    src/com/ngos/kernel/other/e820/e820table.h \
    src/com/ngos/kernel/other/hypervisor/hypervisor.h \
    src/com/ngos/kernel/other/hypervisor/hypervisortype.h \
    src/com/ngos/kernel/other/hypervisor/kvm/clock/kvmclock.h \
    src/com/ngos/kernel/other/hypervisor/kvm/kvm.h \
    src/com/ngos/kernel/other/hypervisor/kvm/kvmfeature.h \
    src/com/ngos/kernel/other/hypervisor/kvm/kvmfeaturetypeflags.h \
    src/com/ngos/kernel/other/ioremap/fixmap.h \
    src/com/ngos/kernel/other/ioremap/ioremap.h \
    src/com/ngos/kernel/other/ioremap/macros.h \
    src/com/ngos/kernel/other/ioremap/utils.h \
    src/com/ngos/kernel/other/irq/irqstack.h \
    src/com/ngos/kernel/other/kerneldefines.h \
    src/com/ngos/kernel/other/memorymanager/memoryblock.h \
    src/com/ngos/kernel/other/memorymanager/memoryblockregion.h \
    src/com/ngos/kernel/other/memorymanager/memoryblockregionflags.h \
    src/com/ngos/kernel/other/memorymanager/memoryblockregionnodeid.h \
    src/com/ngos/kernel/other/memorymanager/memoryblocktype.h \
    src/com/ngos/kernel/other/memorymanager/memorymanager.h \
    src/com/ngos/kernel/other/pagetable/addressconversion.h \
    src/com/ngos/kernel/other/pagetable/dynamicpagetable.h \
    src/com/ngos/kernel/other/task/task.h \
    src/com/ngos/kernel/other/task/taskstate.h \
    src/com/ngos/kernel/other/task/threadinfo.h \
    src/com/ngos/kernel/other/task/threadinfoflags.h \
    src/com/ngos/kernel/other/task/utils.h \
    src/com/ngos/kernel/other/uefi/uefi.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/brk/brk.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/cpu/cpumask.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/e820/e820.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/hypervisor/kvm/kvm.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/ioremap/ioremap.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/ioremap/utils.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/memorymanager/memoryblockregion.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/memorymanager/memorymanager.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/pagetable/addressconversion.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/pagetable/dynamicpagetable.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/task/utils.h \
    test/com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/types.h \
    test/com/ngos/kernel/a_early/sections/section2/testcase.h \
    test/com/ngos/kernel/a_early/testengine.h \
    test/com/ngos/kernel/a_early/testresults.h
