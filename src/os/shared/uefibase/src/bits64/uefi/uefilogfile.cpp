#include "uefilogfile.h"

#include <uefi/uefiloadedimageprotocol.h>
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



        Guid        protocol = UEFI_LOADED_IMAGE_PROTOCOL_GUID;
        uefi_handle handle   = UEFI::getImageHandle();



        UefiLoadedImageProtocol *image;

        if (UEFI::handleProtocol(handle, &protocol, (void **)&image) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to handle(0x%p) protocol for UEFI_LOADED_IMAGE_PROTOCOL", handle));

            return NgosStatus::FAILED;
        }

        UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_LOADED_IMAGE_PROTOCOL", handle, image));



        UEFI_ASSERT_EXECUTION(initVolume(image->deviceHandle), NgosStatus::ASSERTION);



        if (sLogFile)
        {
            sIsAborted = false; // To avoid infinite loop
        }
        else
        {
            UEFI_LW(("Failed to create " NGOS_BUILD_UEFI_LOG_FILE " log file"));
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

NgosStatus UefiLogFile::initVolume(uefi_handle handle)
{
    UEFI_LT((" | handle = 0x%p", handle));

    UEFI_ASSERT(handle, "handle is null", NgosStatus::ASSERTION);



    UefiFileProtocol *rootDirectory = UEFI::openVolume(handle);

    if (rootDirectory)
    {
        const char8 *logPath8 = NGOS_BUILD_UEFI_LOG_FILE;



        char16 *logPath16;
        u64     size = (strlen(logPath8) + 1) * sizeof(char16);

        if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&logPath16) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to allocate pool(%u) for string", size));

            return NgosStatus::OUT_OF_MEMORY;
        }

        UEFI_LVV(("Allocated pool(0x%p, %u) for string", logPath16, size));



        const char8 *cur8  = logPath8;
        char16      *cur16 = logPath16;

        while (*cur8)
        {
            if (
                *cur8 == '/'
                ||
                *cur8 == '\\'
               )
            {
                if (cur16 != logPath16)
                {
                    *cur16 = 0;



                    UefiFileProtocol *folder;

                    if (rootDirectory->open(rootDirectory, &folder, logPath16, FLAGS(UefiFileModeFlag::CREATE, UefiFileModeFlag::READ, UefiFileModeFlag::WRITE), FLAGS(UefiFileAttributeFlag::DIRECTORY)) == UefiStatus::SUCCESS)
                    {
                        UEFI_LV(("Created folder: %ls", logPath16));

                        if (folder->close(folder) == UefiStatus::SUCCESS)
                        {
                            UEFI_LV(("Closed created folder"));
                        }
                        else
                        {
                            UEFI_LW(("Failed to close created folder"));
                        }
                    }
                    else
                    {
                        UEFI_LW(("Failed to create folder: %ls", logPath16));
                    }



                    *cur16 = '\\';
                    ++cur16;
                }
            }
            else
            {
                *cur16 = *cur8;
                ++cur16;
            }

            ++cur8;
        }

        *cur16 = 0;



        if (rootDirectory->open(rootDirectory, &sLogFile, logPath16, FLAGS(UefiFileModeFlag::CREATE, UefiFileModeFlag::READ, UefiFileModeFlag::WRITE), FLAGS(UefiFileAttributeFlag::NONE)) == UefiStatus::SUCCESS)
        {
            UEFI_LV(("Created log file: %ls", logPath16));
        }



        if (UEFI::freePool(logPath16) == UefiStatus::SUCCESS)
        {
            UEFI_LVV(("Released pool(0x%p) for string", logPath16));
        }
        else
        {
            UEFI_LE(("Failed to release pool(0x%p) for string", logPath16));
        }



        if (rootDirectory->close(rootDirectory) == UefiStatus::SUCCESS)
        {
            UEFI_LV(("Closed volume root directory"));
        }
        else
        {
            UEFI_LW(("Failed to close volume root directory"));
        }
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
        sLogFile->flush(sLogFile);
    }



    return NgosStatus::OK;
}



#endif
