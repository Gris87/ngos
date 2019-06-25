#include "bootloader.h"

#include <common/src/bits64/string/string.h>
#include <uefi/uefiblockioprotocol.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



UefiLoadedImageProtocol *Bootloader::sImage;
UefiDevicePath          *Bootloader::sDevicePath;
char                    *Bootloader::sApplicationDirPath;
u64                      Bootloader::sNumberOfVolumes;
VolumeInfo              *Bootloader::sVolumes;



NgosStatus Bootloader::init()
{
    UEFI_LT((""));



    char *applicationPath;

    UEFI_ASSERT_EXECUTION(initImage(),                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initApplicationPath(&applicationPath),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initDevicePath(applicationPath),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initApplicationDirPath(applicationPath), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumes(),                           NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::cleanUpPath(char *path)
{
    UEFI_LT((" | path = %s", path));

    UEFI_ASSERT(path, "path is null", NgosStatus::ASSERTION);



    u64 source = 0;
    u64 dest   = 0;

    while (path[source])
    {
        if (
            path[source] == '/'
            ||
            path[source] == '\\'
           )
        {
            if (!dest) // dest == 0
            {
                ++source;
            }
            else
            {
                path[dest] = '\\';
                ++dest;

                do
                {
                    ++source;
                } while ((path[source] == '/') || (path[source] == '\\'));
            }
        }
        else
        {
            path[dest] = path[source];
            ++source;
            ++dest;
        }
    }



    if (dest > 0 && path[dest - 1] == '\\')
    {
        --dest;
    }

    path[dest] = 0;



    if (!path[0]) // path[0] == 0
    {
        path[0] = '\\';
        path[1] = '\0';
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initImage()
{
    UEFI_LT((""));



    UefiGuid    protocol = UEFI_LOADED_IMAGE_PROTOCOL_GUID;
    uefi_handle handle   = UEFI::getImageHandle();



    if (UEFI::handleProtocol(handle, &protocol, (void **)&sImage) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to handle(0x%p) protocol for UEFI_LOADED_IMAGE_PROTOCOL", handle));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_LOADED_IMAGE_PROTOCOL", handle, sImage));



    UEFI_LVVV(("Loaded image:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("sImage->imageBase = 0x%p", sImage->imageBase));
    UEFI_LVVV(("sImage->imageSize = %u",   sImage->imageSize));

    UEFI_LVVV(("-------------------------------------"));



    return NgosStatus::OK;
}

NgosStatus Bootloader::initApplicationPath(char **applicationPath)
{
    UEFI_LT((" | applicationPath = 0x%p", applicationPath));

    UEFI_ASSERT(applicationPath, "applicationPath is null", NgosStatus::ASSERTION);



    *applicationPath = UEFI::devicePathToString(sImage->filePath);

    if (!(*applicationPath))
    {
        UEFI_LF(("Failed to get application path"));

        return NgosStatus::FAILED;
    }



    UEFI_LVVV(("sApplicationPath = %s", *applicationPath));

    UEFI_TEST_ASSERT(strcmp(*applicationPath, "\\EFI\\BOOT\\BOOTX64.EFI") == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initDevicePath(char *applicationPath)
{
    UEFI_LT((" | applicationPath = %s", applicationPath));

    UEFI_ASSERT(applicationPath, "applicationPath is null", NgosStatus::ASSERTION);



    sDevicePath = UEFI::fileDevicePath(sImage->deviceHandle, applicationPath);

    if (!sDevicePath)
    {
        UEFI_LF(("Failed to get device path"));

        return NgosStatus::FAILED;
    }



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        UEFI_LVVV(("sDevicePath:"));
        UEFI_LVVV(("-------------------------------------"));

        UefiDevicePath *currentDevicePath = sDevicePath;

        do
        {
            UEFI_LVVV(("currentDevicePath->type    = 0x%02X (%s)", currentDevicePath->type, uefiDevicePathTypeToString(currentDevicePath->type)));
            UEFI_LVVV(("currentDevicePath->subtype = 0x%02X (%s)", currentDevicePath->subType, uefiDevicePathSubTypeToString(currentDevicePath->type, currentDevicePath->subType)));
            UEFI_LVVV(("currentDevicePath->length  = %u",          currentDevicePath->length));

            if (UEFI::isDevicePathEndType(currentDevicePath))
            {
                break;
            }

            currentDevicePath = UEFI::nextDevicePathNode(currentDevicePath);
        } while (true);

        UEFI_LVVV(("-------------------------------------"));
    }
#endif



    return NgosStatus::OK;
}

NgosStatus Bootloader::initApplicationDirPath(char *applicationPath)
{
    UEFI_LT((" | applicationPath = %s", applicationPath));

    UEFI_ASSERT(applicationPath, "applicationPath is null", NgosStatus::ASSERTION);



    char *sApplicationDirPath = UEFI::parentDirectory(applicationPath);
    UEFI_ASSERT_EXECUTION(cleanUpPath(sApplicationDirPath), NgosStatus::ASSERTION);

    UEFI_LVVV(("sApplicationDirPath = %s", sApplicationDirPath));

    UEFI_TEST_ASSERT(strcmp(sApplicationDirPath, "EFI\\BOOT") == 0, NgosStatus::ASSERTION);



    if (UEFI::freePool(applicationPath) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for string", applicationPath));
    }
    else
    {
        UEFI_LE(("Failed to free pool(0x%p) for string", applicationPath));

        return NgosStatus::FAILED;
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumes()
{
    UEFI_LT((""));



    UefiGuid     blockIoProtocol = UEFI_BLOCK_IO_PROTOCOL_GUID;
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



    UEFI_LVVV(("sNumberOfVolumes = %u", sNumberOfVolumes));

    // UEFI_TEST_ASSERT(sNumberOfVolumes == 3, NgosStatus::ASSERTION); // Commented due to value variation



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        UEFI_LVVV(("sVolumes:"));
        UEFI_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)sNumberOfVolumes; ++i)
        {
            UEFI_LVVV(("sVolumes[%d].deviceHandle    = 0x%p", i, sVolumes[i].deviceHandle));
            UEFI_LVVV(("sVolumes[%d].blockIoProtocol = 0x%p", i, sVolumes[i].blockIoProtocol));



            UEFI_LVVV(("sVolumes[%d].devicePath:", i));
            UEFI_LVVV(("....................................."));

            UefiDevicePath *currentDevicePath = sVolumes[i].devicePath;

            do
            {
                UEFI_LVVV(("currentDevicePath->type    = 0x%02X (%s)", currentDevicePath->type, uefiDevicePathTypeToString(currentDevicePath->type)));
                UEFI_LVVV(("currentDevicePath->subtype = 0x%02X (%s)", currentDevicePath->subType, uefiDevicePathSubTypeToString(currentDevicePath->type, currentDevicePath->subType)));
                UEFI_LVVV(("currentDevicePath->length  = %u",          currentDevicePath->length));

                if (UEFI::isDevicePathEndType(currentDevicePath))
                {
                    break;
                }

                currentDevicePath = UEFI::nextDevicePathNode(currentDevicePath);
            } while (true);

            UEFI_LVVV(("....................................."));



            UEFI_LVVV(("sVolumes[%d].gptData.protectiveMbr = 0x%p", i, sVolumes[i].gptData.protectiveMbr));
            UEFI_LVVV(("sVolumes[%d].gptData.header        = 0x%p", i, sVolumes[i].gptData.header));
            UEFI_LVVV(("sVolumes[%d].gptData.entries       = 0x%p", i, sVolumes[i].gptData.entries));
            UEFI_LVVV(("sVolumes[%d].type                  = %u (%s)", i, sVolumes[i].type, volumeTypeToString(sVolumes[i].type)));
        }

        UEFI_LVVV(("-------------------------------------"));
    }
#endif



    return NgosStatus::OK;
}

NgosStatus Bootloader::initBlockIoProtocol(UefiGuid *protocol, u64 size)
{
    UEFI_LT((" | protocol = 0x%p, size = %u", protocol, size));

    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is zero",     NgosStatus::ASSERTION);



    uefi_handle *blockIoHandles = 0;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&blockIoHandles) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for handles for UEFI_BLOCK_IO_PROTOCOL", size));

        return NgosStatus::FAILED;
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

NgosStatus Bootloader::initBlockIoProtocol(UefiGuid *protocol, u64 size, uefi_handle *blockIoHandles)
{
    UEFI_LT((" | protocol = 0x%p, size = %u, graphicsHandles = 0x%p", protocol, size, graphicsHandles));

    UEFI_ASSERT(protocol,       "protocol is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0,       "size is zero",           NgosStatus::ASSERTION);
    UEFI_ASSERT(blockIoHandles, "blockIoHandles is null", NgosStatus::ASSERTION);



    sNumberOfVolumes = size / sizeof(uefi_handle);
    UEFI_LVVV(("sNumberOfVolumes = %u", sNumberOfVolumes));



    u64 volumesSize = sNumberOfVolumes * sizeof(VolumeInfo);

    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, volumesSize, (void **)&sVolumes) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for volumes", volumesSize));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for volumes", sVolumes, volumesSize));



    for (i64 i = 0; i < (i64)sNumberOfVolumes; ++i)
    {
        UEFI_ASSERT_EXECUTION(initVolume(&sVolumes[i], protocol, blockIoHandles[i]), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolume(VolumeInfo *volume, UefiGuid *protocol, uefi_handle handle)
{
    UEFI_LT((" | volume = 0x%p, protocol = 0x%p, handle = 0x%p", volume, protocol, handle));

    UEFI_ASSERT(volume,   "volume is null",   NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(handle,   "handle is null",   NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(initVolumeDeviceHandle(volume, handle),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeBlockIoProtocol(volume, protocol, handle), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeDevicePath(volume, handle),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeGptData(volume),                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeType(volume),                              NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeDeviceHandle(VolumeInfo *volume, uefi_handle handle)
{
    UEFI_LT((" | volume = 0x%p, handle = 0x%p", volume, handle));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(handle, "handle is null", NgosStatus::ASSERTION);



    volume->deviceHandle = handle;



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeBlockIoProtocol(VolumeInfo *volume, UefiGuid *protocol, uefi_handle handle)
{
    UEFI_LT((" | volume = 0x%p, protocol = 0x%p, handle = 0x%p", volume, protocol, handle));

    UEFI_ASSERT(volume,   "volume is null",   NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(handle,   "handle is null",   NgosStatus::ASSERTION);



    if (UEFI::handleProtocol(handle, protocol, (void **)&volume->blockIoProtocol) != UefiStatus::SUCCESS)
    {
        UEFI_LE(("Failed to handle(0x%p) protocol for UEFI_BLOCK_IO_PROTOCOL", handle));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_BLOCK_IO_PROTOCOL", handle, volume->blockIoProtocol));



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeDevicePath(VolumeInfo *volume, uefi_handle handle)
{
    UEFI_LT((" | volume = 0x%p, handle = 0x%p", volume, handle));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(handle, "handle is null", NgosStatus::ASSERTION);



    volume->devicePath = UEFI::devicePathFromHandle(handle);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeGptData(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    volume->gptData.protectiveMbr = 0;
    volume->gptData.header        = 0;
    volume->gptData.entries       = 0;



    if (
        volume->blockIoProtocol->media->mediaPresent
        ||
        volume->blockIoProtocol->media->logicalPartition
       )
    {
        u64 size = sizeof(Mbr);

        if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&volume->gptData.protectiveMbr) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to allocate pool(%u) for GPT protective MBR", size));

            return NgosStatus::FAILED;
        }

        UEFI_LVV(("Allocated pool(0x%p, %u) for GPT protective MBR", volume->gptData.protectiveMbr, size));



        if (volume->blockIoProtocol->readBlocks(volume->blockIoProtocol, volume->blockIoProtocol->media->mediaId, 0, size, (void *)volume->gptData.protectiveMbr) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to read GPT protective MBR"));

            return NgosStatus::FAILED;
        }

        UEFI_LVV(("Successfully read GPT protective MBR"));



        size = sizeof(GptHeader);

        if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&volume->gptData.header) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to allocate pool(%u) for GPT header", size));

            return NgosStatus::FAILED;
        }

        UEFI_LVV(("Allocated pool(0x%p, %u) for GPT header", volume->gptData.header, size));



        if (volume->blockIoProtocol->readBlocks(volume->blockIoProtocol, volume->blockIoProtocol->media->mediaId, 1, size, (void *)volume->gptData.header) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to read GPT header"));

            return NgosStatus::FAILED;
        }

        UEFI_LVV(("Successfully read GPT header"));
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeType(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    volume->type = VolumeType::INTERNAL;

    if (volume->blockIoProtocol->media->blockSize == 2048)
    {
        volume->type = VolumeType::OPTICAL;
    }



    UefiDevicePath *currentDevicePath = volume->devicePath;

    while (!UEFI::isDevicePathEndType(currentDevicePath))
    {
        if (currentDevicePath->type == UefiDevicePathType::MEDIA_DEVICE_PATH)
        {
            if (currentDevicePath->subType == UefiDevicePathSubType::MEDIA_CDROM_DP)
            {
                volume->type = VolumeType::OPTICAL;
            }
        }
        else
        if (currentDevicePath->type == UefiDevicePathType::MESSAGING_DEVICE_PATH)
        {
            if (
                currentDevicePath->subType == UefiDevicePathSubType::MSG_USB_DP
                ||
                currentDevicePath->subType == UefiDevicePathSubType::MSG_USB_CLASS_DP
                ||
                currentDevicePath->subType == UefiDevicePathSubType::MSG_1394_DP
                ||
                currentDevicePath->subType == UefiDevicePathSubType::MSG_FIBRECHANNEL_DP
               )
            {
                volume->type = VolumeType::EXTERNAL;
            }
        }



        currentDevicePath = UEFI::nextDevicePathNode(currentDevicePath);
    }



    return NgosStatus::OK;
}
