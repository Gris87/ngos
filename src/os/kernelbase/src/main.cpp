#include <bootparams/bootparams.h>
#include <ngos/linkage.h>
#include <pagetable/utils.h>
#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>
#include <src/bits64/a_early/main/disableirq.h>
#include <src/bits64/a_early/main/reservepciromimages.h>
#include <src/bits64/a_early/main/setupbootparams.h>
#include <src/bits64/a_early/main/setupcr4shadow.h>
#include <src/bits64/a_early/main/setupe820tables.h>
#include <src/bits64/a_early/main/setupfirstcpu.h>
#include <src/bits64/a_early/main/setupidthandlers.h>
#include <src/bits64/a_early/main/setupinittask.h>
#include <src/bits64/a_early/main/setupioremap.h>
#include <src/bits64/a_early/main/setupmemorymanager.h>
#include <src/bits64/a_early/main/setupstackcanary.h>
#include <src/bits64/a_early/main/setupuefimemorymap.h>
#include <src/bits64/assets/assets.h>
#include <src/bits64/cpu/cpu.h>
#include <src/bits64/fpu/fpu.h>
#include <src/bits64/serial/serial.h>
#include <test/bits64/a_early/sections/section1/testcase.h>



extern PGD early_pagetable[PTRS_PER_PGD]; // early_pagetable declared in main.S file
extern PGD init_pagetable[PTRS_PER_PGD];  // init_pagetable declared in main.S file



CPP_EXTERN_C
void kernelMain(BootParams *params)
{ // Ignore CppNgosTraceVerifier
    EARLY_LT((" | params = 0x%p", params));

    EARLY_ASSERT(params, "params is null");



    EARLY_ASSERT_EXECUTION(Serial::initConsole());



#ifdef BUILD_TARGET_INSTALLER               // Defined in Makefile
    EARLY_LI(("NGOS installer started"));
#else
    EARLY_LI(("NGOS kernel started"));
#endif



    EARLY_ASSERT_EXECUTION(CPU::init());
    EARLY_LI(("CPU information initialized"));

    EARLY_ASSERT_EXECUTION(FPU::init());
    EARLY_LI(("FPU initialized"));

    EARLY_ASSERT_EXECUTION(Assets::init());
    EARLY_LI(("Assets initialized"));



#if NGOS_BUILD_TEST_MODE == OPTION_YES
    if (startTestSection1() != NgosStatus::OK)
    {
        EARLY_LF(("Test failure"));

        return;
    }
#endif



    EARLY_ASSERT_EXECUTION(setupBootParams(params));
    EARLY_LI(("Setup boot parameters completed"));

    EARLY_ASSERT_EXECUTION(setupCr4Shadow());
    EARLY_LI(("Setup CR4 shadow completed"));

    EARLY_ASSERT_EXECUTION(setupIdtHandlers());
    EARLY_LI(("Setup IDT handlers completed"));

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



    init_pagetable[511] = early_pagetable[511];
}
