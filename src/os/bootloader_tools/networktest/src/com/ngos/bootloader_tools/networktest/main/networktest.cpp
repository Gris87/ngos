#include "networktest.h"

#include <com/ngos/shared/common/uefi/uefisimplenetworkprotocol.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



NgosStatus NetworkTest::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initSimpleNetworkProtocols(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus NetworkTest::initSimpleNetworkProtocols()
{
    UEFI_LT((""));



    Guid protocol = UEFI_SIMPLE_NETWORK_PROTOCOL_GUID;
    u64  size     = 0;



    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, &protocol, nullptr, &size, nullptr) == UefiStatus::BUFFER_TOO_SMALL)
    {
        UEFI_LVV(("Found size(%u) of buffer for handles for UEFI_SIMPLE_NETWORK_PROTOCOL", size));

        if (initSimpleNetworkProtocols(&protocol, size) != NgosStatus::OK)
        {
            UEFI_LF(("Failed to setup UEFI_SIMPLE_NETWORK_PROTOCOL"));

            return NgosStatus::FAILED;
        }

        UEFI_LV(("Setup UEFI_SIMPLE_NETWORK_PROTOCOL completed"));
    }
    else
    {
        UEFI_LW(("Handle for UEFI_SIMPLE_NETWORK_PROTOCOL not found"));
    }



    return NgosStatus::OK;
}

NgosStatus NetworkTest::initSimpleNetworkProtocols(Guid *protocol, u64 size)
{
    UEFI_LT((" | protocol = 0x%p, size = %u", protocol, size));

    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is zero",     NgosStatus::ASSERTION);



    uefi_handle *handles = nullptr;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&handles) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for handles for UEFI_SIMPLE_NETWORK_PROTOCOL", size));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for handles for UEFI_SIMPLE_NETWORK_PROTOCOL", handles, size));



    NgosStatus status = NgosStatus::FAILED;

    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, protocol, nullptr, &size, handles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Located handles(0x%p) for UEFI_SIMPLE_NETWORK_PROTOCOL", handles));

        status = initSimpleNetworkProtocols(protocol, size, handles);
    }
    else
    {
        UEFI_LF(("Failed to locate handles(0x%p) for UEFI_SIMPLE_NETWORK_PROTOCOL", handles));
    }



    if (UEFI::freePool(handles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for handles for UEFI_SIMPLE_NETWORK_PROTOCOL", handles));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for handles for UEFI_SIMPLE_NETWORK_PROTOCOL", handles));
    }



    return status;
}

NgosStatus NetworkTest::initSimpleNetworkProtocols(Guid *protocol, u64 size, uefi_handle *handles)
{
    UEFI_LT((" | protocol = 0x%p, size = %u, handles = 0x%p", protocol, size, handles));

    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is zero",     NgosStatus::ASSERTION);
    UEFI_ASSERT(handles,  "handles is null",  NgosStatus::ASSERTION);



    i64 count = size / sizeof(uefi_handle);
    UEFI_LVVV(("count = %d", count));



    for (good_i64 i = 0; i < count; ++i)
    {
        uefi_handle                handle = handles[i];
        UefiSimpleNetworkProtocol *network;



        if (UEFI::handleProtocol(handle, protocol, (void **)&network) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to handle(0x%p) protocol for UEFI_SIMPLE_NETWORK_PROTOCOL", handle));

            continue;
        }

        UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_SIMPLE_NETWORK_PROTOCOL", handle, network));
    }



    return NgosStatus::OK;
}
