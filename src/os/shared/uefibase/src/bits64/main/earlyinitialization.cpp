#include "earlyinitialization.h"

#include <bootparams/bootparams.h>
#include <buildconfig.h>
#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/fpu/fpu.h>
#include <common/src/bits64/serial/serial.h>
#include <ngos/linkage.h>
#include <uefi/uefisystemtable.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/main/setupglobalobjects.h>
#include <uefibase/src/bits64/main/setupgraphics.h>
#include <uefibase/src/bits64/main/setupdynamicrelocation.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



// DO NOT DELETE IT!!!
// We are putting this variable to .noinit section in order to convert .noinit section type from NOBITS to PROGBITS
u8 __reserved_for_bss __attribute__ ((section (".noinit")));



#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
NgosStatus waitForGdbDebug()
{ // Ignore CppNgosTraceVerifier
    UEFI_LT((""));



    UEFI_LD(("Waiting for gdb debug..."));



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

NgosStatus earlyInitialization(u64 kernelLocation)
{
    UEFI_LT((""));



#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
    UEFI_LD(("Application started at address 0x%p", kernelLocation));
    UEFI_LD(("gdb debug is ready to go"));

    UEFI_ASSERT_EXECUTION(waitForGdbDebug(), NgosStatus::ASSERTION);
#else
    UEFI_LV(("Application started at address 0x%p", kernelLocation));
#endif



    UEFI_ASSERT_EXECUTION(CPU::init(), NgosStatus::ASSERTION);
    UEFI_LI(("CPU information initialized"));

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE
    UEFI_ASSERT_EXECUTION(printCpuFlags(), NgosStatus::ASSERTION);
#endif



#ifdef BUILD_TARGET_CONFIGURE
    const char8 *wantedCpuFlag = 0;

    if (CPU::check(&wantedCpuFlag) != NgosStatus::OK)
    {
        char8 buffer[1024];

        UEFI_ASSERT_EXECUTION(UEFI::clearScreen(), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(CPU::toString(buffer, 1024), NgosStatus::ASSERTION);

        UEFI_LF(("%s\n", buffer));

        UEFI_ASSERT_EXECUTION(CPU::flagsToString(buffer, 1024), NgosStatus::ASSERTION);

        UEFI_LF(("CPU flags:             %s\n", buffer));

        UEFI_ASSERT_EXECUTION(CPU::bugsToString(buffer, 1024), NgosStatus::ASSERTION);

        UEFI_LF(("CPU bugs:              %s\n", buffer));



        if (wantedCpuFlag && *wantedCpuFlag)
        {
            UEFI_LF(("CPU flag \"%s\" is not supported\n", wantedCpuFlag));
        }



        UEFI_LF(("Your CPU is already outdated. Please upgrade your hardware."));
        UEFI_LF(("It is expected Intel Core i9-9980XE Extreme Edition or newer or AMD Ryzen Threadripper 2990WX or newer."));



        return NgosStatus::FAILED;
    }
#endif



    UEFI_ASSERT_EXECUTION(setupDynamicRelocation(kernelLocation), NgosStatus::ASSERTION);
    UEFI_LI(("Setup dynamic relocation completed"));



    UEFI_ASSERT_EXECUTION(setupGlobalObjects(), NgosStatus::ASSERTION);
    UEFI_LI(("Setup global objects completed"));



    UEFI_ASSERT_EXECUTION(setupCr4(), NgosStatus::ASSERTION);
    UEFI_LI(("Setup CR4 completed"));



    UEFI_ASSERT_EXECUTION(FPU::init(), NgosStatus::ASSERTION);
    UEFI_LI(("FPU initialized"));



    UEFI_ASSERT_EXECUTION(Assets::init(), NgosStatus::ASSERTION);
    UEFI_LI(("Assets initialized"));



    return NgosStatus::OK;
}
