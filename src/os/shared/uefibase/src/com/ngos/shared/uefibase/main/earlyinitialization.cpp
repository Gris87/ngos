#include "earlyinitialization.h"

#include <common/src/com/ngos/shared/common/bootparams/bootparams.h>
#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/assets/assets.h>
#include <common/src/com/ngos/shared/common/cpu/cpu.h>
#include <common/src/com/ngos/shared/common/fpu/fpu.h>
#include <common/src/com/ngos/shared/common/serial/serial.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/uefi/uefisystemtable.h>
#include <uefibase/src/com/ngos/shared/uefibase/main/setupcr4.h>
#include <uefibase/src/com/ngos/shared/uefibase/main/setupdynamicrelocation.h>
#include <uefibase/src/com/ngos/shared/uefibase/main/setupglobalobjects.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>



// DO NOT DELETE IT!!!
// We are putting this variable to .noinit section in order to convert .noinit section type from NOBITS to PROGBITS
u8 __reserved_for_bss __attribute__ ((section (".noinit")));



#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
NgosStatus waitForGdbDebug()
{ // Ignore CppNgosTraceVerifier
    UEFI_LT((""));



    UEFI_LD(("Waiting for gdb debug..."));
    UEFI_ASSERT_EXECUTION(UEFI::stall(5 * UEFI_STALL_SECOND), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
#endif

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE
NgosStatus printCpuFlags()
{ // Ignore CppNgosTraceVerifier
    UEFI_LT((""));



    char8 buffer[1024];

    UEFI_ASSERT_EXECUTION(CPU::flagsToString(buffer, sizeof(buffer)), NgosStatus::ASSERTION);

    UEFI_LV(("CPU flags:"));
    UEFI_LV(("%s", buffer));



    return NgosStatus::OK;
}
#endif

NgosStatus earlyInitialization(u64 kernelLocation)
{
    UEFI_LT((" | kernelLocation = 0x%p", kernelLocation));

    UEFI_ASSERT(kernelLocation, "kernelLocation is null", NgosStatus::ASSERTION);



    UEFI_LI(("UEFI v%u.%02u by %ls", UEFI::getSystemTable()->header.revision >> 16, UEFI::getSystemTable()->header.revision & 0xFFFF, UEFI::getSystemTable()->firmwareVendor));



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



#ifdef BUILD_TARGET_CONFIGURE // Defined in Makefile
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



        if (wantedCpuFlag != nullptr && wantedCpuFlag[0] != 0)
        {
            UEFI_LF(("CPU flag \"%s\" is not supported\n", wantedCpuFlag));
        }



        UEFI_LF(("Your CPU is already outdated. Please upgrade it"));
        UEFI_LF(("We recommend Intel Core i9-10980XE Extreme Edition or newer or AMD Ryzen Threadripper 3990X or newer"));



        return NgosStatus::FAILED;
    }
#endif



    UEFI_ASSERT_EXECUTION(setupDynamicRelocation(kernelLocation), NgosStatus::ASSERTION);
    UEFI_LI(("Setup dynamic relocation completed"));



    UEFI_ASSERT_EXECUTION(setupGlobalObjects(), NgosStatus::ASSERTION);
    UEFI_LI(("Setup global objects completed"));



    UEFI_ASSERT_EXECUTION(setupCr4(), NgosStatus::ASSERTION);
    UEFI_LI(("Setup CR4 completed"));



    UEFI_ASSERT_EXECUTION(FPU::initForBootStrapProcessor(), NgosStatus::ASSERTION);
    UEFI_LI(("FPU initialized"));



    UEFI_ASSERT_EXECUTION(Assets::init(), NgosStatus::ASSERTION);
    UEFI_LI(("Assets initialized"));



    return NgosStatus::OK;
}
