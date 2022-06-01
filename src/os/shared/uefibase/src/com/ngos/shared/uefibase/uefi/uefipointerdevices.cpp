#include "uefipointerdevices.h"

#include <com/ngos/shared/common/string/utils.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



u8                            UefiPointerDevices::sAbsolutePointersCount;
UefiAbsolutePointerProtocol **UefiPointerDevices::sAbsolutePointers;
u8                            UefiPointerDevices::sSimplePointersCount;
UefiSimplePointerProtocol   **UefiPointerDevices::sSimplePointers;



NgosStatus UefiPointerDevices::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initAbsolutePointerDevices(), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initSimplePointerDevices(),   NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiPointerDevices::cleanUp()
{
    UEFI_LT((""));



    if (sAbsolutePointers)
    {
        if (UEFI::freePool(sAbsolutePointers) == UefiStatus::SUCCESS)
        {
            UEFI_LVV(("Released pool(0x%p) for absolute pointer devices", sAbsolutePointers));
        }
        else
        {
            UEFI_LE(("Failed to release pool(0x%p) for absolute pointer devices", sAbsolutePointers));
        }
    }

    if (sSimplePointers)
    {
        if (UEFI::freePool(sSimplePointers) == UefiStatus::SUCCESS)
        {
            UEFI_LVV(("Released pool(0x%p) for simple pointer devices", sSimplePointers));
        }
        else
        {
            UEFI_LE(("Failed to release pool(0x%p) for simple pointer devices", sSimplePointers));
        }
    }



    return NgosStatus::OK;
}

u8 UefiPointerDevices::getAbsolutePointersCount()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return sAbsolutePointersCount;
}

UefiAbsolutePointerProtocol* UefiPointerDevices::getAbsolutePointer(u8 index)
{
    // UEFI_LT((" | index = %u", index)); // Commented to avoid too frequent logs

    UEFI_ASSERT(index < sAbsolutePointersCount, "index is invalid", nullptr);



    return sAbsolutePointers[index];
}

u8 UefiPointerDevices::getSimplePointersCount()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return sSimplePointersCount;
}

UefiSimplePointerProtocol* UefiPointerDevices::getSimplePointer(u8 index)
{
    // UEFI_LT((" | index = %u", index)); // Commented to avoid too frequent logs

    UEFI_ASSERT(index < sSimplePointersCount, "index is invalid", nullptr);



    return sSimplePointers[index];
}

NgosStatus UefiPointerDevices::initAbsolutePointerDevices()
{
    UEFI_LT((""));



    Guid pointersProtocol = UEFI_ABSOLUTE_POINTER_PROTOCOL_GUID;
    u64  pointersSize     = 0;



    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, &pointersProtocol, nullptr, &pointersSize, nullptr) == UefiStatus::BUFFER_TOO_SMALL)
    {
        UEFI_LVV(("Found size(%u) of buffer for handles for UEFI_ABSOLUTE_POINTER_PROTOCOL", pointersSize));

        if (initAbsolutePointerDevices(&pointersProtocol, pointersSize) != NgosStatus::OK)
        {
            UEFI_LF(("Failed to setup UEFI_ABSOLUTE_POINTER_PROTOCOL"));

            return NgosStatus::FAILED;
        }

        UEFI_LV(("Setup UEFI_ABSOLUTE_POINTER_PROTOCOL completed"));
    }
    else
    {
        UEFI_LV(("Handle for UEFI_ABSOLUTE_POINTER_PROTOCOL not found"));
    }



    // Validation
    {
        UEFI_LVVV(("sAbsolutePointersCount = %u", sAbsolutePointersCount));

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            UEFI_LVVV(("sAbsolutePointers:"));
            UEFI_LVVV(("-------------------------------------"));

            for (good_I64 i = 0; i < (i64)sAbsolutePointersCount; ++i)
            {
                UEFI_LVVV(("sAbsolutePointers[%d]->waitForInput       = 0x%p", i, sAbsolutePointers[i]->waitForInput));
                UEFI_LVVV(("sAbsolutePointers[%d]->mode->absoluteMinX = %u",   i, sAbsolutePointers[i]->mode->absoluteMinX));
                UEFI_LVVV(("sAbsolutePointers[%d]->mode->absoluteMinY = %u",   i, sAbsolutePointers[i]->mode->absoluteMinY));
                UEFI_LVVV(("sAbsolutePointers[%d]->mode->absoluteMinZ = %u",   i, sAbsolutePointers[i]->mode->absoluteMinZ));
                UEFI_LVVV(("sAbsolutePointers[%d]->mode->absoluteMaxX = %u",   i, sAbsolutePointers[i]->mode->absoluteMaxX));
                UEFI_LVVV(("sAbsolutePointers[%d]->mode->absoluteMaxY = %u",   i, sAbsolutePointers[i]->mode->absoluteMaxY));
                UEFI_LVVV(("sAbsolutePointers[%d]->mode->absoluteMaxZ = %u",   i, sAbsolutePointers[i]->mode->absoluteMaxZ));
                UEFI_LVVV(("sAbsolutePointers[%d]->mode->attributes   = %s",   i, flagsToFullString(sAbsolutePointers[i]->mode->attributes)));
            }

            UEFI_LVVV(("-------------------------------------"));
        }
#endif



        // UEFI_TEST_ASSERT(sAbsolutePointersCount                   == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sAbsolutePointers[0]->waitForInput       != nullptr,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sAbsolutePointers[0]->mode->absoluteMinX == 0,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sAbsolutePointers[0]->mode->absoluteMinY == 0,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sAbsolutePointers[0]->mode->absoluteMinZ == 0,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sAbsolutePointers[0]->mode->absoluteMaxX == 65536,                                             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sAbsolutePointers[0]->mode->absoluteMaxY == 65536,                                             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sAbsolutePointers[0]->mode->absoluteMaxZ == 65536,                                             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sAbsolutePointers[0]->mode->attributes   == FLAGS(UefiAbsolutePointerModeAttributeFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation
    }



    return NgosStatus::OK;
}

NgosStatus UefiPointerDevices::initAbsolutePointerDevices(Guid *protocol, u64 size)
{
    UEFI_LT((" | protocol = 0x%p, size = %u", protocol, size));

    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is invalid",  NgosStatus::ASSERTION);



    uefi_handle *pointersHandles = nullptr;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&pointersHandles) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for handles for UEFI_ABSOLUTE_POINTER_PROTOCOL", size));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for handles for UEFI_ABSOLUTE_POINTER_PROTOCOL", pointersHandles, size));



    NgosStatus status = NgosStatus::FAILED;

    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, protocol, nullptr, &size, pointersHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Located handles(0x%p) for UEFI_ABSOLUTE_POINTER_PROTOCOL", pointersHandles));

        status = initAbsolutePointerDevices(protocol, size, pointersHandles);
    }
    else
    {
        UEFI_LF(("Failed to locate handles(0x%p) for UEFI_ABSOLUTE_POINTER_PROTOCOL", pointersHandles));
    }



    if (UEFI::freePool(pointersHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for handles for UEFI_ABSOLUTE_POINTER_PROTOCOL", pointersHandles));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for handles for UEFI_ABSOLUTE_POINTER_PROTOCOL", pointersHandles));
    }



    return status;
}

NgosStatus UefiPointerDevices::initAbsolutePointerDevices(Guid *protocol, u64 size, uefi_handle *pointersHandles)
{
    UEFI_LT((" | protocol = 0x%p, size = %u, pointersHandles = 0x%p", protocol, size, pointersHandles));

    UEFI_ASSERT(protocol,        "protocol is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0,        "size is invalid",         NgosStatus::ASSERTION);
    UEFI_ASSERT(pointersHandles, "pointersHandles is null", NgosStatus::ASSERTION);



    i64 count = size / sizeof(uefi_handle);
    UEFI_LVVV(("count = %d", count));



    u64 pointersSize = count * sizeof(UefiAbsolutePointerProtocol *);

    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, pointersSize, (void **)&sAbsolutePointers) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for absolute pointer devices", pointersSize));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for absolute pointer devices", sAbsolutePointers, pointersSize));



    sAbsolutePointersCount = 0;

    for (good_I64 i = 0; i < count; ++i)
    {
        uefi_handle                  handle = pointersHandles[i];
        UefiAbsolutePointerProtocol *pointer;



        if (UEFI::handleProtocol(handle, protocol, (void **)&pointer) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to handle(0x%p) protocol for UEFI_ABSOLUTE_POINTER_PROTOCOL", handle));

            continue;
        }

        UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_ABSOLUTE_POINTER_PROTOCOL", handle, pointer));



        UEFI_LVVV(("pointer->waitForInput       = 0x%p", pointer->waitForInput));
        UEFI_LVVV(("pointer->mode->absoluteMinX = %u",   pointer->mode->absoluteMinX));
        UEFI_LVVV(("pointer->mode->absoluteMinY = %u",   pointer->mode->absoluteMinY));
        UEFI_LVVV(("pointer->mode->absoluteMinZ = %u",   pointer->mode->absoluteMinZ));
        UEFI_LVVV(("pointer->mode->absoluteMaxX = %u",   pointer->mode->absoluteMaxX));
        UEFI_LVVV(("pointer->mode->absoluteMaxY = %u",   pointer->mode->absoluteMaxY));
        UEFI_LVVV(("pointer->mode->absoluteMaxZ = %u",   pointer->mode->absoluteMaxZ));
        UEFI_LVVV(("pointer->mode->attributes   = %s",   flagsToFullString(pointer->mode->attributes)));



        if (pointer->reset(pointer, true) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to reset pointer 0x%p", pointer));

            continue;
        }

        UEFI_LVV(("Pointer 0x%p successfully resetted", pointer));



        sAbsolutePointers[sAbsolutePointersCount] = pointer;
        ++sAbsolutePointersCount;
    }



    return NgosStatus::OK;
}

NgosStatus UefiPointerDevices::initSimplePointerDevices()
{
    UEFI_LT((""));



    Guid pointersProtocol = UEFI_SIMPLE_POINTER_PROTOCOL_GUID;
    u64  pointersSize     = 0;



    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, &pointersProtocol, nullptr, &pointersSize, nullptr) == UefiStatus::BUFFER_TOO_SMALL)
    {
        UEFI_LVV(("Found size(%u) of buffer for handles for UEFI_SIMPLE_POINTER_PROTOCOL", pointersSize));

        if (initSimplePointerDevices(&pointersProtocol, pointersSize) != NgosStatus::OK)
        {
            UEFI_LF(("Failed to setup UEFI_SIMPLE_POINTER_PROTOCOL"));

            return NgosStatus::FAILED;
        }

        UEFI_LV(("Setup UEFI_SIMPLE_POINTER_PROTOCOL completed"));
    }
    else
    {
        UEFI_LW(("Handle for UEFI_SIMPLE_POINTER_PROTOCOL not found"));
    }



    // Validation
    {
        UEFI_LVVV(("sSimplePointersCount = %u", sSimplePointersCount));

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            UEFI_LVVV(("sSimplePointers:"));
            UEFI_LVVV(("-------------------------------------"));

            for (good_I64 i = 0; i < (i64)sSimplePointersCount; ++i)
            {
                UEFI_LVVV(("sSimplePointers[%d]->waitForInput      = 0x%p", i, sSimplePointers[i]->waitForInput));
                UEFI_LVVV(("sSimplePointers[%d]->mode->resolutionX = %u",   i, sSimplePointers[i]->mode->resolutionX));
                UEFI_LVVV(("sSimplePointers[%d]->mode->resolutionY = %u",   i, sSimplePointers[i]->mode->resolutionY));
                UEFI_LVVV(("sSimplePointers[%d]->mode->resolutionZ = %u",   i, sSimplePointers[i]->mode->resolutionZ));
                UEFI_LVVV(("sSimplePointers[%d]->mode->leftButton  = %s",   i, boolToString(sSimplePointers[i]->mode->leftButton)));
                UEFI_LVVV(("sSimplePointers[%d]->mode->rightButton = %s",   i, boolToString(sSimplePointers[i]->mode->rightButton)));
            }

            UEFI_LVVV(("-------------------------------------"));
        }
#endif



        // UEFI_TEST_ASSERT(sSimplePointersCount                  == 1,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sSimplePointers[0]->waitForInput      != nullptr, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sSimplePointers[0]->mode->resolutionX == 65536,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sSimplePointers[0]->mode->resolutionY == 65536,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sSimplePointers[0]->mode->resolutionZ == 65536,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sSimplePointers[0]->mode->leftButton  == true,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(sSimplePointers[0]->mode->rightButton == true,    NgosStatus::ASSERTION); // Commented due to value variation
    }



    return NgosStatus::OK;
}

NgosStatus UefiPointerDevices::initSimplePointerDevices(Guid *protocol, u64 size)
{
    UEFI_LT((" | protocol = 0x%p, size = %u", protocol, size));

    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is invalid",  NgosStatus::ASSERTION);



    uefi_handle *pointersHandles = nullptr;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&pointersHandles) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for handles for UEFI_SIMPLE_POINTER_PROTOCOL", size));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for handles for UEFI_SIMPLE_POINTER_PROTOCOL", pointersHandles, size));



    NgosStatus status = NgosStatus::FAILED;

    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, protocol, nullptr, &size, pointersHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Located handles(0x%p) for UEFI_SIMPLE_POINTER_PROTOCOL", pointersHandles));

        status = initSimplePointerDevices(protocol, size, pointersHandles);
    }
    else
    {
        UEFI_LF(("Failed to locate handles(0x%p) for UEFI_SIMPLE_POINTER_PROTOCOL", pointersHandles));
    }



    if (UEFI::freePool(pointersHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for handles for UEFI_SIMPLE_POINTER_PROTOCOL", pointersHandles));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for handles for UEFI_SIMPLE_POINTER_PROTOCOL", pointersHandles));
    }



    return status;
}

NgosStatus UefiPointerDevices::initSimplePointerDevices(Guid *protocol, u64 size, uefi_handle *pointersHandles)
{
    UEFI_LT((" | protocol = 0x%p, size = %u, pointersHandles = 0x%p", protocol, size, pointersHandles));

    UEFI_ASSERT(protocol,        "protocol is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0,        "size is invalid",         NgosStatus::ASSERTION);
    UEFI_ASSERT(pointersHandles, "pointersHandles is null", NgosStatus::ASSERTION);



    i64 count = size / sizeof(uefi_handle);
    UEFI_LVVV(("count = %d", count));



    u64 pointersSize = count * sizeof(UefiSimplePointerProtocol *);

    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, pointersSize, (void **)&sSimplePointers) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for simple pointer devices", pointersSize));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for simple pointer devices", sSimplePointers, pointersSize));



    sSimplePointersCount = 0;

    for (good_I64 i = 0; i < count; ++i)
    {
        uefi_handle                handle = pointersHandles[i];
        UefiSimplePointerProtocol *pointer;



        if (UEFI::handleProtocol(handle, protocol, (void **)&pointer) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to handle(0x%p) protocol for UEFI_SIMPLE_POINTER_PROTOCOL", handle));

            continue;
        }

        UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_SIMPLE_POINTER_PROTOCOL", handle, pointer));



        UEFI_LVVV(("pointer->waitForInput      = 0x%p", pointer->waitForInput));
        UEFI_LVVV(("pointer->mode->resolutionX = %u",   pointer->mode->resolutionX));
        UEFI_LVVV(("pointer->mode->resolutionY = %u",   pointer->mode->resolutionY));
        UEFI_LVVV(("pointer->mode->resolutionZ = %u",   pointer->mode->resolutionZ));
        UEFI_LVVV(("pointer->mode->leftButton  = %s",   boolToString(pointer->mode->leftButton)));
        UEFI_LVVV(("pointer->mode->rightButton = %s",   boolToString(pointer->mode->rightButton)));



        if (pointer->reset(pointer, true) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to reset pointer 0x%p", pointer));

            continue;
        }

        UEFI_LVV(("Pointer 0x%p successfully resetted", pointer));



        sSimplePointers[sSimplePointersCount] = pointer;
        ++sSimplePointersCount;
    }



    return NgosStatus::OK;
}
