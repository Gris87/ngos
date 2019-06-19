#include "setupcr4.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/flags.h>

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



NgosStatus setupCr4()
{
    UEFI_LT((""));



    u64 cr4 = readCr4();

    UEFI_LVVV(("cr4 = 0x%016lX", cr4));



    cr4 |= X86_CR4_PAE
        |  X86_CR4_PGE
        |  X86_CR4_OSFXSR        // Requires X86Feature::FXSR
        |  X86_CR4_OSXMMEXCPT    // Requires X86Feature::XMM
        |  X86_CR4_OSXSAVE;      // Requires X86Feature::XSAVE

    UEFI_LVVV(("cr4 = 0x%016lX", cr4));



    UEFI_ASSERT_EXECUTION(writeCr4(cr4), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
