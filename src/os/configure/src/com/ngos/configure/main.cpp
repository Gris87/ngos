#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <buildconfig.h>
#include <com/ngos/shared/common/assets/assets.h>
#include <com/ngos/shared/common/serial/serial.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/uefi/uefisystemtable.h>
#include <com/ngos/shared/uefibase/main/earlyinitialization.h>
#include <com/ngos/shared/uefibase/main/setupdynamicrelocation.h>
#include <com/ngos/shared/uefibase/main/setupgraphics.h>
#include <com/ngos/shared/uefibase/main/setuphardwareid.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>
#include <com/ngos/shared/uefibase/sections/section0/testcase.h>

#include "com/ngos/configure/a_uefi/main/exitbootservices.h"
#include "com/ngos/configure/a_uefi/main/setupbootparams.h"
#include "com/ngos/configure/a_uefi/main/setupkernellocation.h"
#include "com/ngos/configure/a_uefi/main/setuppciio.h"
#include "com/ngos/configure/sections/section1/testcase.h"



CPP_EXTERN_C
BootParams* uefiMain(uefi_handle imageHandle, UefiSystemTable *systemTable, u64 kernelLocation)
{ // Ignore CppNgosTraceVerifier
    // We can't output at the moment
    // UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p, kernelLocation = 0x%p", imageHandle, systemTable, kernelLocation)); // Commented to avoid error because UEFI is uninitialized



    UEFI_ASSERT_EXECUTION(Serial::initConsole(), nullptr);



    // Check that we are booting via UEFI
    if (systemTable->header.signature != UEFI_SYSTEM_TABLE_SIGNATURE)
    {
        UEFI_LF(("Unexpected UEFI System Table signature"));

        return nullptr;
    }



    UEFI_ASSERT_EXECUTION(UEFI::init(imageHandle, systemTable), nullptr);



    UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p, kernelLocation = 0x%p", imageHandle, systemTable, kernelLocation)); // We can output now

    UEFI_ASSERT(imageHandle,    "imageHandle is null",    nullptr);
    UEFI_ASSERT(systemTable,    "systemTable is null",    nullptr);
    UEFI_ASSERT(kernelLocation, "kernelLocation is null", nullptr);



    UEFI_LI(("NGOS starting up"));



    if (earlyInitialization(kernelLocation) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to perform early initialization"));

        return nullptr;
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

        return nullptr;
    }
#endif



    BootParams *params = nullptr;

    if (setupBootParams(&params, kernelLocation) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup boot parameters"));

        return nullptr;
    }

    UEFI_LI(("Setup boot parameters completed"));



    if (setupGraphics(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup graphics"));

        return nullptr;
    }

    UEFI_LI(("Setup graphics completed"));



    if (setupHardwareId(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup hardware ID"));

        return nullptr;
    }

    UEFI_LI(("Setup hardware ID completed"));



    if (setupPciIo(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup PCI IO"));

        return nullptr;
    }

    UEFI_LI(("Setup PCI IO completed"));



    if (setupKernelLocation(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup kernel location"));

        return nullptr;
    }

    UEFI_LI(("Setup kernel location completed"));



    if (exitBootServices(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to exit boot services"));

        return nullptr;
    }

    UEFI_LI(("Exit boot services completed"));



    return params;
}
