#include "setupvirtualfunctiontables.h"

#include <elf/rela.h>
#include <elf/relatype.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



extern void *_rela_begin; // _rela_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern void *_rela_end;   // _rela_end declared in linker.ld file   // Ignore CppEqualAlignmentVerifier



NgosStatus setupVirtualFunctionTables(u64 kernelLocation)
{
    UEFI_LT((" | kernelLocation = 0x%p", kernelLocation));

    UEFI_ASSERT(kernelLocation, "kernelLocation is null", NgosStatus::ASSERTION);



    ElfRela *relas = (ElfRela *)&_rela_begin;

    i64 count = ((u64)&_rela_end - (u64)&_rela_begin) / sizeof(ElfRela);
    UEFI_LVVV(("count = %d", count));

    for (i64 i = 0; i < count; ++i)
    {
        ElfRela &rela = relas[i];

        // UEFI_LVVV(("relas[%d].offset = 0x%016lX", i, rela.offset));                               // Commented to avoid too frequent logs
        // UEFI_LVVV(("relas[%d].info   = 0x%016lX", i, rela.info));                                 // Commented to avoid too frequent logs
        // UEFI_LVVV(("relas[%d].addend = 0x%016lX", i, rela.addend));                               // Commented to avoid too frequent logs
        // UEFI_LVVV(("relas[%d].type   = %u (%s)",  i, rela.type, elfRelaTypeToString(rela.type))); // Commented to avoid too frequent logs

        UEFI_TEST_ASSERT(rela.type == ElfRelaType::RELATIVE, NgosStatus::ASSERTION);



        u64 relaAddress = kernelLocation + rela.offset;

        UEFI_LVV(("Handling RELA entry(ElfRelaType::RELATIVE) at 0x%p: 0x%016lX => 0x%016lX", relaAddress, *((u64 *)relaAddress), kernelLocation + rela.addend));

        *(u64 *)relaAddress = kernelLocation + rela.addend;
    }



    return NgosStatus::OK;
}
