#include "setupcr4.h"

#include <common/src/com/ngos/shared/common/asm/instructions.h>
#include <common/src/com/ngos/shared/common/cpu/cpu.h>
#include <common/src/com/ngos/shared/common/cpu/flags.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



NgosStatus setupCr4()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    u64 cr4 = readCr4();

    // UEFI_LVVV(("cr4 = 0x%016lX", cr4)); // Commented to avoid bad looking logs



    cr4 |= X86_CR4_PAE
        |  X86_CR4_PGE;

    if (CPU::hasFlag(X86Feature::FXSR))
    {
        cr4 |= X86_CR4_OSFXSR;
    }

    if (CPU::hasFlag(X86Feature::XMM))
    {
        cr4 |= X86_CR4_OSXMMEXCPT;
    }

    if (CPU::hasFlag(X86Feature::XSAVE))
    {
        cr4 |= X86_CR4_OSXSAVE;
    }

    // UEFI_LVVV(("cr4 = 0x%016lX", cr4)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(writeCr4(cr4), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
