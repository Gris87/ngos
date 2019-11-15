#include <bootparams/bootparams.h>
#include <buildconfig.h>
#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/serial/serial.h>
#include <ngos/linkage.h>
#include <uefi/uefisystemtable.h>
#include <uefibase/src/bits64/main/earlyinitialization.h>
#include <uefibase/src/bits64/main/setupdynamicrelocation.h>
#include <uefibase/src/bits64/main/setupgraphics.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/sections/section0/testcase.h>

#include "src/bits64/a_uefi/main/exitbootservices.h"
#include "src/bits64/a_uefi/main/setupbootparams.h"
#include "src/bits64/a_uefi/main/setupkernellocation.h"
#include "src/bits64/a_uefi/main/setuppciio.h"
#include "test/bits64/a_uefi/sections/section1/testcase.h"



CPP_EXTERN_C
BootParams* uefiMain(uefi_handle imageHandle, UefiSystemTable *systemTable, u64 kernelLocation)
{ // Ignore CppNgosTraceVerifier
    // We can't output at the moment
    // UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p, kernelLocation = 0x%p", imageHandle, systemTable, kernelLocation)); // Commented to avoid error because UEFI is uninitialized



    UEFI_ASSERT_EXECUTION(Serial::initConsole(), 0);



    // Check that we are booting via UEFI
    if (systemTable->header.signature != UEFI_SYSTEM_TABLE_SIGNATURE)
    {
        UEFI_LF(("Unexpected UEFI System Table signature"));

        return 0;
    }



    UEFI_ASSERT_EXECUTION(UEFI::init(imageHandle, systemTable), 0);



    UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p, kernelLocation = 0x%p", imageHandle, systemTable, kernelLocation)); // We can output now

    UEFI_ASSERT(imageHandle,    "imageHandle is null",    0);
    UEFI_ASSERT(systemTable,    "systemTable is null",    0);
    UEFI_ASSERT(kernelLocation, "kernelLocation is null", 0);



    UEFI_LI(("NGOS starting up"));



    if (earlyInitialization(kernelLocation) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to perform early initialization"));

        return 0;
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

        return 0;
    }
#endif



    BootParams *params = 0;

    if (setupBootParams(&params, kernelLocation) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup boot parameters"));

        return 0;
    }

    UEFI_LI(("Setup boot parameters completed"));



    if (setupGraphics(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup graphics"));

        return 0;
    }

    UEFI_LI(("Setup graphics completed"));



    if (setupPciIo(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup PCI IO"));

        return 0;
    }

    UEFI_LI(("Setup PCI IO completed"));



    if (setupKernelLocation(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup kernel location"));

        return 0;
    }

    UEFI_LI(("Setup kernel location completed"));



    if (exitBootServices(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to exit boot services"));

        return 0;
    }

    UEFI_LI(("Exit boot services completed"));



    return params;
}
