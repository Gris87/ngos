#include "setupdynamicrelocation.h"

#include <com/ngos/shared/common/elf/rela.h>
#include <com/ngos/shared/common/elf/relocationtype.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



extern void *_rela_begin; // _rela_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern void *_rela_end;   // _rela_end declared in linker.ld file   // Ignore CppEqualAlignmentVerifier



NgosStatus setupDynamicRelocation(address_t kernelLocation)
{
    UEFI_LT((" | kernelLocation = 0x%p", kernelLocation));

    UEFI_ASSERT(kernelLocation, "kernelLocation is null", NgosStatus::ASSERTION);



    ElfRela *relas = (ElfRela *)&_rela_begin;

    i64 count = ((address_t)&_rela_end - (address_t)&_rela_begin) / sizeof(ElfRela);
    UEFI_LVVV(("count = %d", count));

    for (good_i64 i = 0; i < count; ++i)
    {
        ElfRela &rela = relas[i];

        // UEFI_LVVV(("relas[%d].offset = 0x%016llX", i, rela.offset));                 // Commented to avoid too frequent logs
        // UEFI_LVVV(("relas[%d].info   = 0x%016llX", i, rela.info));                   // Commented to avoid too frequent logs
        // UEFI_LVVV(("relas[%d].addend = 0x%016llX", i, rela.addend));                 // Commented to avoid too frequent logs
        // UEFI_LVVV(("relas[%d].type   = %s",        i, enumToFullString(rela.type))); // Commented to avoid too frequent logs

        UEFI_TEST_ASSERT(rela.type == ElfRelocationType::RELATIVE, NgosStatus::ASSERTION);



        address_t relaAddress = kernelLocation + rela.offset;

        UEFI_LVV(("Handling RELA entry(ElfRelocationType::RELATIVE) at 0x%p: 0x%016llX => 0x%016llX", relaAddress, *(address_t *)relaAddress, kernelLocation + rela.addend));

        *(address_t *)relaAddress = kernelLocation + rela.addend;
    }



    return NgosStatus::OK;
}
