#include "malloc.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/linkage.h>

#ifdef UEFI_APPLICATION                         // Defined in pro file
#include <com/ngos/shared/uefibase/uefi/uefi.h>
#endif



void* malloc(u64 size)
{
    // COMMON_LT((" | size = %u", size)); // Commented to avoid too frequent logs

    COMMON_ASSERT(size > 0, "size is zero", nullptr);



    void *res = nullptr;

#ifdef UEFI_APPLICATION // Defined in pro file
    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, &res) != UefiStatus::SUCCESS)
    {
        COMMON_LF(("Failed to allocate pool(%u)", size));

        return nullptr;
    }

    COMMON_LVV(("Allocated pool(0x%p, %u)", res, size));
#else
    AVOID_UNUSED(size); // TODO: Remove it when implemented
#endif



    return res;
}

NgosStatus free(void *address)
{
    // COMMON_LT((" | address = 0x%p", address)); // Commented to avoid too frequent logs

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);



#ifdef UEFI_APPLICATION // Defined in pro file
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

void* realloc(void* address, u64 oldSize, u64 newSize)
{
    // COMMON_LT((" | address = 0x%p, oldSize = %u, newSize = %u", address, oldSize, newSize)); // Commented to avoid too frequent logs

    COMMON_ASSERT(address != nullptr, "address is null",    nullptr);
    COMMON_ASSERT(oldSize > 0,        "oldSize is zero",    nullptr);
    COMMON_ASSERT(newSize > 0,        "newSize is zero",    nullptr);
    COMMON_ASSERT(newSize > oldSize,  "newSize is invalid", nullptr);



    void *res = malloc(newSize);

    if (res != nullptr)
    {
        memcpy(res, address, oldSize);

        COMMON_ASSERT_EXECUTION(free(address), nullptr);
    }



    return res;
}

void* operator new(size_t size)
{
    // COMMON_LT((" | size = %u", size)); // Commented to avoid too frequent logs



    return malloc(size);
}

void operator delete(void *address)
{
    // COMMON_LT((" | address = 0x%p", address)); // Commented to avoid too frequent logs

    COMMON_ASSERT(address != nullptr, "address is null");



    COMMON_ASSERT_EXECUTION(free(address));
}

void operator delete(void *address, size_t size)
{
    // COMMON_LT((" | address = 0x%p, size = %u", address, size)); // Commented to avoid too frequent logs

    COMMON_ASSERT(address != nullptr, "address is null");
    COMMON_ASSERT(size > 0,           "size is zero");



    AVOID_UNUSED(size);



    COMMON_ASSERT_EXECUTION(free(address));
}

void* operator new[](size_t size)
{
    // COMMON_LT((" | size = %u", size)); // Commented to avoid too frequent logs



    return malloc(size);
}

void operator delete[](void *address)
{
    // COMMON_LT((" | address = 0x%p", address)); // Commented to avoid too frequent logs

    COMMON_ASSERT(address != nullptr, "address is null");



    COMMON_ASSERT_EXECUTION(free(address));
}

void operator delete[](void *address, size_t size)
{
    // COMMON_LT((" | address = 0x%p, size = %u", address, size)); // Commented to avoid too frequent logs

    COMMON_ASSERT(address != nullptr, "address is null");
    COMMON_ASSERT(size > 0,           "size is zero");



    AVOID_UNUSED(size);



    COMMON_ASSERT_EXECUTION(free(address));
}
