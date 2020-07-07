#include <com/ngos/kernel/a_early/main/disableirq.h>
#include <com/ngos/kernel/a_early/main/reservepciromimages.h>
#include <com/ngos/kernel/a_early/main/setupbootparams.h>
#include <com/ngos/kernel/a_early/main/setupbrk.h>
#include <com/ngos/kernel/a_early/main/setupcr4shadow.h>
#include <com/ngos/kernel/a_early/main/setupdmi.h>
#include <com/ngos/kernel/a_early/main/setupe820tables.h>
#include <com/ngos/kernel/a_early/main/setupfirstcpu.h>
#include <com/ngos/kernel/a_early/main/setuphypervisor.h>
#include <com/ngos/kernel/a_early/main/setupidthandlers.h>
#include <com/ngos/kernel/a_early/main/setupinittask.h>
#include <com/ngos/kernel/a_early/main/setupioremap.h>
#include <com/ngos/kernel/a_early/main/setupmemorymanager.h>
#include <com/ngos/kernel/a_early/main/setupstackcanary.h>
#include <com/ngos/kernel/a_early/main/setupuefimemorymap.h>
#include <com/ngos/kernel/a_early/main/setupuefisystemtable.h>
#include <com/ngos/kernel/a_early/sections/section2/testcase.h>
#include <com/ngos/kernel/other/bootparams/bootparams.h>
#include <com/ngos/shared/common/assets/assets.h>
#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/pagetable/utils.h>
#include <com/ngos/shared/common/serial/serial.h>



extern PGD early_pagetable[PTRS_PER_PGD]; // early_pagetable declared in main.S file
extern PGD init_pagetable[PTRS_PER_PGD];  // init_pagetable declared in main.S file



CPP_EXTERN_C
void kernelMain(BootParams *params)
{ // Ignore CppNgosTraceVerifier
    // We can't output at the moment
    // EARLY_LT((" | params = 0x%p", params));



    EARLY_ASSERT_EXECUTION(setupBootParams(params));
    EARLY_LI(("Setup boot parameters completed"));



    EARLY_ASSERT_EXECUTION(Assets::init());
    EARLY_LI(("Assets initialized"));



    EARLY_ASSERT_EXECUTION(Console::init());
    EARLY_LI(("Console initialized"));



    EARLY_LT((" | params = 0x%p", params));

    EARLY_ASSERT(params, "params is null");



    EARLY_LI(("NGOS kernel started"));



    EARLY_ASSERT_EXECUTION(CPU::init());
    EARLY_LI(("CPU information initialized"));

    EARLY_ASSERT_EXECUTION(FPU::initForBootStrapProcessor());
    EARLY_LI(("FPU initialized"));



#if NGOS_BUILD_TEST_MODE == OPTION_YES
    if (startTestSection2() != NgosStatus::OK)
    {
        EARLY_LF(("Test failure"));

        return;
    }
#endif



    EARLY_ASSERT_EXECUTION(setupCr4Shadow());
    EARLY_LI(("Setup CR4 shadow completed"));

    EARLY_ASSERT_EXECUTION(setupIdtHandlers());
    EARLY_LI(("Setup IDT handlers completed"));

    EARLY_ASSERT_EXECUTION(setupBrk());
    EARLY_LI(("Setup BRK completed"));

    EARLY_ASSERT_EXECUTION(setupInitTask());
    EARLY_LI(("Setup init task completed"));

    EARLY_ASSERT_EXECUTION(setupStackCanary());
    EARLY_LI(("Setup stack canary completed"));

    EARLY_ASSERT_EXECUTION(disableIrq());
    EARLY_LI(("IRQ disabled"));

    EARLY_ASSERT_EXECUTION(setupFirstCpu());
    EARLY_LI(("Setup first CPU completed"));

    EARLY_ASSERT_EXECUTION(setupMemoryManager());
    EARLY_LI(("Setup memory manager completed"));

    EARLY_ASSERT_EXECUTION(setupIoRemap());
    EARLY_LI(("Setup IO remap completed"));

    EARLY_ASSERT_EXECUTION(setupE820Tables());
    EARLY_LI(("Setup E820 tables completed"));

    EARLY_ASSERT_EXECUTION(setupUefiMemoryMap());
    EARLY_LI(("Setup UEFI memory map completed"));

    EARLY_ASSERT_EXECUTION(reservePciRomImages());
    EARLY_LI(("Memory reserved for PCI ROM images"));

    EARLY_ASSERT_EXECUTION(setupUefiSystemTable());
    EARLY_LI(("Setup UEFI system table completed"));

    EARLY_ASSERT_EXECUTION(setupDmi());
    EARLY_LI(("Setup DMI completed"));

    EARLY_ASSERT_EXECUTION(setupHypervisor());
    EARLY_LI(("Setup hypervisor completed"));



    init_pagetable[511] = early_pagetable[511];
}
