#include "uefilogfile.h"

#include <uefi/uefiblockioprotocol.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



#if NGOS_BUILD_LOG_TO_UEFI_FILE == OPTION_YES



bool              UefiLogFile::sIsAborted;
UefiFileProtocol *UefiLogFile::sLogFile;



NgosStatus UefiLogFile::init()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    UEFI_TEST_ASSERT(!sIsAborted, NgosStatus::ASSERTION);

    if (!sLogFile)
    {
        sIsAborted = true; // To avoid infinite loop



        Guid         blockIoProtocol = UEFI_BLOCK_IO_PROTOCOL_GUID;
        u64          blockIoSize     = 0;
        uefi_handle *blockIoHandles  = 0;



        if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, &blockIoProtocol, 0, &blockIoSize, blockIoHandles) == UefiStatus::BUFFER_TOO_SMALL)
        {
            UEFI_LVV(("Found size(%u) of buffer for handles for UEFI_BLOCK_IO_PROTOCOL", blockIoSize));

            if (initBlockIoProtocol(&blockIoProtocol, blockIoSize) != NgosStatus::OK)
            {
                UEFI_LF(("Failed to setup UEFI_BLOCK_IO_PROTOCOL"));

                return NgosStatus::FAILED;
            }

            UEFI_LV(("Setup UEFI_BLOCK_IO_PROTOCOL completed"));
        }
        else
        {
            UEFI_LW(("Handle for UEFI_BLOCK_IO_PROTOCOL not found"));
        }
    }



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::print(char8 ch)
{
    // UEFI_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(write((u8 *)&ch, sizeof(ch)), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::print(const char8 *str)
{
    // UEFI_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    UEFI_ASSERT(str, "str is null", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(write((u8 *)str, strlen(str)), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::println()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(print('\n'), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::println(char8 ch)
{
    // UEFI_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(print(ch),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(print('\n'), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::println(const char8 *str)
{
    // UEFI_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    UEFI_ASSERT(str, "str is null", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(print(str),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(print('\n'), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::noMorePrint()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    if (!sIsAborted)
    {
        sIsAborted = true;

        if (sLogFile)
        {
            if (sLogFile->close(sLogFile) == UefiStatus::SUCCESS)
            {
                UEFI_LV(("Closed " NGOS_BUILD_UEFI_LOG_FILE " log file"));
            }
            else
            {
                UEFI_LW(("Failed to close " NGOS_BUILD_UEFI_LOG_FILE " log file"));
            }
        }
    }
    else
    {
        UEFI_TEST_ASSERT(sLogFile == nullptr, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

bool UefiLogFile::canPrint()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    return !sIsAborted;
}

NgosStatus UefiLogFile::initBlockIoProtocol(Guid *protocol, u64 size)
{
    UEFI_LT((" | protocol = 0x%p, size = %u", protocol, size));

    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is zero",     NgosStatus::ASSERTION);



    uefi_handle *blockIoHandles = 0;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&blockIoHandles) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for handles for UEFI_BLOCK_IO_PROTOCOL", size));

        return NgosStatus::OUT_OF_MEMORY;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for handles for UEFI_BLOCK_IO_PROTOCOL", blockIoHandles, size));



    NgosStatus status = NgosStatus::FAILED;

    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, protocol, 0, &size, blockIoHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Located handles(0x%p) for UEFI_BLOCK_IO_PROTOCOL", blockIoHandles));

        status = initBlockIoProtocol(protocol, size, blockIoHandles);
    }
    else
    {
        UEFI_LF(("Failed to locate handles(0x%p) for UEFI_BLOCK_IO_PROTOCOL", blockIoHandles));
    }



    if (UEFI::freePool(blockIoHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for handles for UEFI_BLOCK_IO_PROTOCOL", blockIoHandles));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for handles for UEFI_BLOCK_IO_PROTOCOL", blockIoHandles));
    }



    return status;
}

NgosStatus UefiLogFile::initBlockIoProtocol(Guid *protocol, u64 size, uefi_handle *blockIoHandles)
{
    UEFI_LT((" | protocol = 0x%p, size = %u, blockIoHandles = 0x%p", protocol, size, blockIoHandles));

    UEFI_ASSERT(protocol,       "protocol is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0,       "size is zero",           NgosStatus::ASSERTION);
    UEFI_ASSERT(blockIoHandles, "blockIoHandles is null", NgosStatus::ASSERTION);



    u64 numberOfVolumes = size / sizeof(uefi_handle);
    UEFI_LVVV(("numberOfVolumes = %u", numberOfVolumes));

    for (i64 i = 0; i < (i64)numberOfVolumes; ++i)
    {

    }



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::write(u8 *data, u64 size)
{
    // UEFI_LT((" | data = 0x%p, size = %u", data, size)); // Commented to avoid bad looking logs

    UEFI_ASSERT(data,     "data is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is zero", NgosStatus::ASSERTION);



    if (sLogFile)
    {
        sLogFile->write(sLogFile, &size, data);
    }



    return NgosStatus::OK;
}



#endif
