#include "malloc.h"

#if defined(UEFI_APPLICATION)                       // Defined in Makefile
#include <uefibase/src/bits64/uefi/uefi.h>
#endif

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/linkage.h>



void* malloc(u64 size)
{
    COMMON_LT((" | size = %u", size));

    COMMON_ASSERT(size > 0, "size is zero", 0);



    void *res = 0;

#if defined(UEFI_APPLICATION)
    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, &res) != UefiStatus::SUCCESS)
    {
        COMMON_LF(("Failed to allocate pool(%u)", size));
    }

    COMMON_LVV(("Allocated pool(0x%p, %u)", res, size));
#else
    AVOID_UNUSED(size); // TODO: Remove it when implemented
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
        COMMON_LC(("Failed to free pool(0x%p)", address));

        return NgosStatus::FAILED;
    }
#else
    AVOID_UNUSED(address); // TODO: Remove it when implemented
#endif



    return NgosStatus::OK;
}

void* operator new(size_t size)
{
    COMMON_LT((" | size = %u", size));



    return malloc(size);
}

void operator delete(void *address)
{
    COMMON_LT((" | address = 0x%p", address));

    COMMON_ASSERT(address, "address is null");



    free(address);
}

void operator delete(void *address, size_t size)
{
    COMMON_LT((" | address = 0x%p, size = %u", address, size));

    COMMON_ASSERT(address,  "address is null");
    COMMON_ASSERT(size > 0, "size is zero");



    AVOID_UNUSED(size);



    free(address);
}
