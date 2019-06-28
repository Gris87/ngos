#include "malloc.h"

#if defined(UEFI_APPLICATION)                       // Defined in Makefile
#include <uefibase/src/bits64/uefi/uefi.h>
#endif

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



void* malloc(u64 size)
{
    COMMON_LT((" | size = %u", count));

    COMMON_ASSERT(size > 0, "size is zero", 0);



    void *res = 0;

#if defined(UEFI_APPLICATION)
    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, &res) != UefiStatus::SUCCESS)
    {
        COMMON_LF(("Failed to allocate pool(%u)", size));
    }

    COMMON_LVV(("Allocated pool(0x%p, %u)", res, size));
#endif



    return res;
}

NgosStatus free(void *address)
{
    COMMON_LT((" | address = 0x%p", address));

    COMMON_ASSERT(address, "address is null", NgosStatus::ASSERTION);



#if defined(UEFI_APPLICATION)
    if (UEFI::freePool(address) == UefiStatus::SUCCESS)
    {
        COMMON_LVV(("Released pool(0x%p)", address));
    }
    else
    {
        COMMON_LE(("Failed to free pool(0x%p)", address));

        return NgosStatus::FAILED;
    }
#endif



    return NgosStatus::OK;
}
