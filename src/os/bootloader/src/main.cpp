#include <bootparams/bootparams.h>
#include <buildconfig.h>
#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/fpu/fpu.h>
#include <common/src/bits64/serial/serial.h>
#include <ngos/linkage.h>
#include <uefi/uefisystemtable.h>
#include <uefibase/src/bits64/main/setupbootparams.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/main/setupgraphics.h>
#include <uefibase/src/bits64/main/setupvirtualfunctiontables.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/sections/section0/testcase.h>

#include "src/bits64/main/bootloader.h"
#include "src/bits64/main/bootloadergui.h"
#include "test/bits64/sections/section1/testcase.h"



// DO NOT DELETE IT!!!
// We are putting this variable to .noinit section in order to convert .noinit section type from NOBITS to PROGBITS
u8 __reserved_for_bss __attribute__ ((section (".noinit")));



#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
NgosStatus waitForGdbDebug()
{ // Ignore CppNgosTraceVerifier
    UEFI_LT((""));



    UEFI_LD(("Waiting for gdb_debug..."));



    uefi_event timerEvent = 0;

    UEFI_ASSERT_EXECUTION(UEFI::createEvent(UefiEventType::TIMER, 0, 0, 0, &timerEvent), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_LVV(("Created timer event(0x%p)", timerEvent));



    UEFI_ASSERT_EXECUTION(UEFI::setTimer(timerEvent, UefiTimerDelay::RELATIVE, 50000000), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION); // 5 * 1000 * 1000 * 10 "* 100ns"
    UEFI_LVV(("Setup timer(0x%p) completed", timerEvent));



    uefi_event waitEvents[1] = { timerEvent };
    u64        eventIndex    = 0;

    UEFI_ASSERT_EXECUTION(UEFI::waitForEvent(1, waitEvents, &eventIndex), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_LVV(("Timer(0x%p) triggered", timerEvent));

    UEFI_TEST_ASSERT(eventIndex == 0, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(UEFI::closeEvent(timerEvent), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_LVV(("Closed timer event(0x%p)", timerEvent));



    return NgosStatus::OK;
}

CPP_EXTERN_C
CPP_NO_OPTIMIZATION
NgosStatus gdbDebugBreakpointFunction()
{ // Ignore CppNgosTraceVerifier
    UEFI_LT((""));



    static u8 a;
    ++a;



    return NgosStatus::OK;
}
#endif

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE
NgosStatus printCpuFlags()
{ // Ignore CppNgosTraceVerifier
    UEFI_LT((""));



    char8 buffer[1024];

    UEFI_ASSERT_EXECUTION(CPU::flagsToString(buffer, 1024), NgosStatus::ASSERTION);

    UEFI_LV(("CPU flags:"));
    UEFI_LV(("%s", buffer));



    return NgosStatus::OK;
}
#endif

CPP_EXTERN_C
UefiStatus uefiMain(uefi_handle imageHandle, UefiSystemTable *systemTable, u64 kernelLocation)
{ // Ignore CppNgosTraceVerifier
    // We can't output at the moment
    // UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p, kernelLocation = 0x%p", imageHandle, systemTable, kernelLocation)); // Commented to avoid error because UEFI is uninitialized



    UEFI_ASSERT_EXECUTION(Serial::initConsole(), UefiStatus::ABORTED);



    // Check that we are booting via UEFI
    if (systemTable->header.signature != UEFI_SYSTEM_TABLE_SIGNATURE)
    {
        UEFI_LF(("Unexpected UEFI System Table signature"));

        return UefiStatus::ABORTED;
    }



    UEFI_ASSERT_EXECUTION(UEFI::init(imageHandle, systemTable), UefiStatus::ABORTED);



    UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p, kernelLocation = 0x%p", imageHandle, systemTable, kernelLocation)); // We can output now

    UEFI_ASSERT(imageHandle,    "imageHandle is null",    UefiStatus::ABORTED);
    UEFI_ASSERT(systemTable,    "systemTable is null",    UefiStatus::ABORTED);
    UEFI_ASSERT(kernelLocation, "kernelLocation is null", UefiStatus::ABORTED);



    UEFI_LI(("NGOS Bootloader starting up"));



#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
    UEFI_LD(("Executing code for gdb_debug"));
    UEFI_LD(("Bootloader started at address 0x%p", kernelLocation));
    UEFI_LD(("gdb_debug is ready to go"));

    UEFI_ASSERT_EXECUTION(waitForGdbDebug(),            UefiStatus::ABORTED);
    UEFI_ASSERT_EXECUTION(gdbDebugBreakpointFunction(), UefiStatus::ABORTED);
#else
    UEFI_LV(("Bootloader started at address 0x%p", kernelLocation));
#endif



    UEFI_ASSERT_EXECUTION(CPU::init(), UefiStatus::ABORTED);
    UEFI_LI(("CPU information initialized"));

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE
    UEFI_ASSERT_EXECUTION(printCpuFlags(), UefiStatus::ABORTED);
#endif



    UEFI_ASSERT_EXECUTION(setupVirtualFunctionTables(kernelLocation), UefiStatus::ABORTED);
    UEFI_LI(("Setup virtual function tables completed"));



    UEFI_ASSERT_EXECUTION(setupCr4(), UefiStatus::ABORTED);
    UEFI_LI(("Setup CR4 completed"));



    UEFI_ASSERT_EXECUTION(FPU::init(), UefiStatus::ABORTED);



    UEFI_ASSERT_EXECUTION(Assets::init(), UefiStatus::ABORTED);
    UEFI_LI(("Assets initialized"));



#if NGOS_BUILD_TEST_MODE == OPTION_YES
    if (
        startTestSection0() != NgosStatus::OK
        ||
        startTestSection1() != NgosStatus::OK
       )
    {
        UEFI_LF(("Test failure"));

        return UefiStatus::ABORTED;
    }
#endif



    BootParams params;

    if (setupBootParams(&params, kernelLocation) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup boot parameters"));

        return UefiStatus::ABORTED;
    }

    UEFI_LI(("Setup boot parameters completed"));



    if (setupGraphics(&params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup graphics"));

        return UefiStatus::ABORTED;
    }

    UEFI_LI(("Setup graphics completed"));



    UEFI_ASSERT_EXECUTION(Bootloader::init(), UefiStatus::ABORTED);
    UEFI_LI(("Bootloader initialized"));



    // UEFI_ASSERT_EXECUTION(BootloaderGUI::init(&params), UefiStatus::ABORTED); // TODO: Uncomment it later
    UEFI_LI(("Bootloader GUI initialized"));



    return UefiStatus::SUCCESS;
}
