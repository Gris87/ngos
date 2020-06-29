#include <bootparams/bootparams.h>
#include <buildconfig.h>
#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/serial/serial.h>
#include <ngos/linkage.h>
#include <uefi/uefisystemtable.h>
#include <uefibase/src/bits64/main/earlyinitialization.h>
#include <uefibase/src/bits64/main/setupbootparams.h>
#include <uefibase/src/bits64/main/setupdynamicrelocation.h>
#include <uefibase/src/bits64/main/setupgraphics.h>
#include <uefibase/src/bits64/main/setuphardwareid.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/src/bits64/uefi/uefipointerdevices.h>
#include <uefibase/test/bits64/sections/section0/testcase.h>

#include "src/com/ngos/bootloader_tools/devicemanager/main/devicemanager.h"
#include "src/com/ngos/bootloader_tools/devicemanager/main/devicemanagergui.h"
#include "test/com/ngos/bootloader_tools/devicemanager/sections/section1/testcase.h"



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



    UEFI_LI(("NGOS Bootloader Tool - Device Manager starting up"));



    if (earlyInitialization(kernelLocation) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to perform early initialization"));

        return UefiStatus::ABORTED;
    }

    UEFI_LI(("Early initialization completed"));



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



    if (setupHardwareId(&params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup hardware ID"));

        return UefiStatus::ABORTED;
    }

    UEFI_LI(("Setup hardware ID completed"));



    UEFI_ASSERT_EXECUTION(UefiPointerDevices::init(), UefiStatus::ABORTED);
    UEFI_LI(("Pointer devices initialized"));



    UEFI_ASSERT_EXECUTION(DeviceManager::init(), UefiStatus::ABORTED);
    UEFI_LI(("Device Manager initialized"));



    UEFI_ASSERT_EXECUTION(DeviceManagerGUI::init(&params), UefiStatus::ABORTED);
    UEFI_LI(("Device Manager GUI initialized"));



    UEFI_ASSERT_EXECUTION(DeviceManagerGUI::exec(), UefiStatus::ABORTED); // Loop forever



    return UefiStatus::SUCCESS;
}
