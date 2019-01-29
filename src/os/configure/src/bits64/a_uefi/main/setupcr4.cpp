#include "setupcr4.h"

#include <asm/instructions.h>
#include <src/bits64/cpu/flags.h>

#include "src/bits64/a_uefi/uefi/uefiassert.h"
#include "src/bits64/a_uefi/uefi/uefilog.h"



NgosStatus setupCr4()
{
    UEFI_LT((""));



    u64 cr4 = readCr4();

    UEFI_LVVV(("cr4 = 0x%016lX", cr4));



    cr4 |= X86_CR4_PAE;
    cr4 |= X86_CR4_PGE;
    cr4 |= X86_CR4_OSFXSR;      // Requires X86Feature::FXSR
    cr4 |= X86_CR4_OSXMMEXCPT;  // Requires X86Feature::XMM

    UEFI_LVVV(("cr4 = 0x%016lX", cr4));



    UEFI_ASSERT_EXECUTION(writeCr4(cr4), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
