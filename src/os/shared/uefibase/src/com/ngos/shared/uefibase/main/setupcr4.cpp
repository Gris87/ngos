#include "setupcr4.h"

#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



NgosStatus setupCr4()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    X86Cr4Flags cr4 = AsmUtils::readCr4();

    // UEFI_LVVV(("cr4 = %s", flagsToFullString(cr4))); // Commented to avoid bad looking logs



    cr4 |= FLAGS(X86Cr4Flag::PHYSICAL_ADDRESS_EXTENSION, X86Cr4Flag::PAGE_GLOBAL_ENABLE);

    if (CPU::hasFeature(X86Feature::FXSR))
    {
        cr4 |= FLAGS(X86Cr4Flag::SUPPORT_FXSAVE);
    }

    if (CPU::hasFeature(X86Feature::SSE))
    {
        cr4 |= FLAGS(X86Cr4Flag::SUPPORT_UNMASKED_SSE_EXCEPTIONS);
    }

    if (CPU::hasFeature(X86Feature::XSAVE))
    {
        cr4 |= FLAGS(X86Cr4Flag::SUPPORT_XSAVE);
    }

    // UEFI_LVVV(("cr4 = %s", flagsToFullString(cr4))); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(AsmUtils::writeCr4(cr4), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
