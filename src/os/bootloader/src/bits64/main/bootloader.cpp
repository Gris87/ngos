#include "bootloader.h"

#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/string/string.h>
#include <gpt/utils.h>
#include <uefi/uefiblockioprotocol.h>
#include <uefi/uefiharddrivedevicepath.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



#define OPTICAL_BLOCK_SIZE 2048



UefiLoadedImageProtocol *Bootloader::sImage;
UefiDevicePath          *Bootloader::sDevicePath;
char16                  *Bootloader::sApplicationDirPath;
List<VolumeInfo>         Bootloader::sVolumes;
List<OsInfo>             Bootloader::sOSes;



NgosStatus Bootloader::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initImage(),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initPaths(),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumes(), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initOSes(),    NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::cleanUpPath(char16 *path)
{
    UEFI_LT((" | path = %S", path));

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
                } while((path[source] == '/') || (path[source] == '\\'));
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
        path[1] = 0;
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::buildPath(const char16 *parentPath, const char16 *path, char16 **res)
{
    UEFI_LT((" | parentPath = %S, path = %S, res = 0x%p", parentPath, path, res));

    UEFI_ASSERT(parentPath, "parentPath is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(path,       "path is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(res,        "res is null",        NgosStatus::ASSERTION);



    i64 size1 = strlen(parentPath);
    i64 size2 = strlen(path);

    i64 totalSize;

    if (size1)
    {
        totalSize = (size1 + size2 + 2) * sizeof(char16);
    }
    else
    {
        totalSize = (size2 + 1) * sizeof(char16);
    }



    char16 *str;

    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, totalSize, (void **)&str) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for string", totalSize));

        return NgosStatus::OUT_OF_MEMORY;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for string", str, totalSize));



    if (size1)
    {
        memcpy(str, parentPath, size1 * sizeof(char16));
        str[size1] = '\\';
        memcpy(&str[size1 + 1], path, (size2 + 1) * sizeof(char16));
    }
    else
    {
        memcpy(str, path, (size2 + 1) * sizeof(char16));
    }



    *res = str;



    return NgosStatus::OK;
}

NgosStatus Bootloader::loadImageFromDiskOrAssets(const char8 *path, Image **image)
{
    UEFI_LT((" | path = %s, image = 0x%p", path, image));

    UEFI_ASSERT(path,  "path is null",  NgosStatus::ASSERTION);
    UEFI_ASSERT(image, "image is null", NgosStatus::ASSERTION);



    AssetEntry *asset = Assets::getAssetEntry(path);
    UEFI_TEST_ASSERT(asset != 0, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(Graphics::loadImage(asset->content, asset->contentSize, strend(path, ".9.png"), image), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initImage()
{
    UEFI_LT((""));



    Guid        protocol = UEFI_LOADED_IMAGE_PROTOCOL_GUID;
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

NgosStatus Bootloader::initPaths()
{
    UEFI_LT((""));



    char16 *applicationPath;

    UEFI_ASSERT_EXECUTION(initApplicationPath(&applicationPath),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initDevicePath(applicationPath),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initApplicationDirPath(applicationPath), NgosStatus::ASSERTION);



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

NgosStatus Bootloader::initApplicationPath(char16 **applicationPath)
{
    UEFI_LT((" | applicationPath = 0x%p", applicationPath));

    UEFI_ASSERT(applicationPath, "applicationPath is null", NgosStatus::ASSERTION);



    *applicationPath = UEFI::devicePathToString(sImage->filePath);

    if (!(*applicationPath))
    {
        UEFI_LF(("Failed to get application path"));

        return NgosStatus::FAILED;
    }



    UEFI_LVVV(("*applicationPath = %S", *applicationPath));

    UEFI_TEST_ASSERT(strcmp(*applicationPath, u"\\EFI\\BOOT\\BOOTX64.EFI") == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initDevicePath(char16 *applicationPath)
{
    UEFI_LT((" | applicationPath = %S", applicationPath));

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
        } while(true);

        UEFI_LVVV(("-------------------------------------"));
    }
#endif



    return NgosStatus::OK;
}

NgosStatus Bootloader::initApplicationDirPath(char16 *applicationPath)
{
    UEFI_LT((" | applicationPath = %S", applicationPath));

    UEFI_ASSERT(applicationPath, "applicationPath is null", NgosStatus::ASSERTION);



    sApplicationDirPath = UEFI::parentDirectory(applicationPath);
    UEFI_ASSERT_EXECUTION(cleanUpPath(sApplicationDirPath), NgosStatus::ASSERTION);

    UEFI_LVVV(("sApplicationDirPath = %S", sApplicationDirPath));

    UEFI_TEST_ASSERT(strcmp(sApplicationDirPath, u"EFI\\BOOT") == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumes()
{
    UEFI_LT((""));



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



    UEFI_ASSERT_EXECUTION(sVolumes.sort(), NgosStatus::ASSERTION);



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        UEFI_LVVV(("sVolumes:"));
        UEFI_LVVV(("-------------------------------------"));

        ListElement<VolumeInfo> *element = sVolumes.getHead();

        while (element)
        {
            const VolumeInfo &volume = element->getData();



            UEFI_LVVV(("volume.deviceHandle    = 0x%p", volume.deviceHandle));
            UEFI_LVVV(("volume.blockIoProtocol = 0x%p", volume.blockIoProtocol));



            UEFI_LVVV(("volume.devicePath:"));
            UEFI_LVVV(("....................................."));

            UefiDevicePath *currentDevicePath = volume.devicePath;

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
            } while(true);

            UEFI_LVVV(("....................................."));



            UEFI_LVVV(("volume.wholeDiskBlockIoProtocol = 0x%p", volume.wholeDiskBlockIoProtocol));
            UEFI_LVVV(("volume.wholeDiskDevicePath      = 0x%p", volume.wholeDiskDevicePath));



            if (volume.wholeDiskDevicePath)
            {
                UEFI_LVVV(("volume.wholeDiskDevicePath:"));
                UEFI_LVVV(("....................................."));

                UefiDevicePath *currentDevicePath = volume.wholeDiskDevicePath;

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
                } while(true);

                UEFI_LVVV(("....................................."));
            }



            UEFI_LVVV(("volume.gptData.protectiveMbr = 0x%p",    volume.gptData.protectiveMbr));
            UEFI_LVVV(("volume.gptData.header        = 0x%p",    volume.gptData.header));
            UEFI_LVVV(("volume.gptData.entries       = 0x%p",    volume.gptData.entries));
            UEFI_LVVV(("volume.type                  = %u (%s)", volume.type, volumeTypeToString(volume.type)));
            UEFI_LVVV(("volume.name                  = %S",      volume.name));
            UEFI_LVVV(("volume.rootDirectory         = 0x%p",    volume.rootDirectory));



            element = element->getNext();

            if (element)
            {
                UEFI_LVVV(("+++++++++++++++++++++++++++++++++++++"));
            }
        }

        UEFI_LVVV(("-------------------------------------"));
    }
#endif



    return NgosStatus::OK;
}

NgosStatus Bootloader::initBlockIoProtocol(Guid *protocol, u64 size)
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

NgosStatus Bootloader::initBlockIoProtocol(Guid *protocol, u64 size, uefi_handle *blockIoHandles)
{
    UEFI_LT((" | protocol = 0x%p, size = %u, blockIoHandles = 0x%p", protocol, size, blockIoHandles));

    UEFI_ASSERT(protocol,       "protocol is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0,       "size is zero",           NgosStatus::ASSERTION);
    UEFI_ASSERT(blockIoHandles, "blockIoHandles is null", NgosStatus::ASSERTION);



    u64 numberOfVolumes = size / sizeof(uefi_handle);
    UEFI_LVVV(("numberOfVolumes = %u", numberOfVolumes));

    for (i64 i = 0; i < (i64)numberOfVolumes; ++i)
    {
        VolumeInfo volume;

        UEFI_ASSERT_EXECUTION(initVolume(&volume, protocol, blockIoHandles[i]), NgosStatus::ASSERTION);

        if (volume.type != VolumeType::NONE)
        {
            sVolumes.append(volume);
        }
        else
        {
            sVolumes.prepend(volume);
        }
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolume(VolumeInfo *volume, Guid *protocol, uefi_handle handle)
{
    UEFI_LT((" | volume = 0x%p, protocol = 0x%p, handle = 0x%p", volume, protocol, handle));

    UEFI_ASSERT(volume,   "volume is null",   NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(handle,   "handle is null",   NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(initVolumeDeviceHandle(volume, handle),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeBlockIoProtocol(volume, protocol, handle), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeDevicePath(volume, handle),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeWholeDisk(volume, protocol),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeGptData(volume),                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeType(volume),                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeName(volume),                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeRootDirectory(volume),                     NgosStatus::ASSERTION);



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

NgosStatus Bootloader::initVolumeBlockIoProtocol(VolumeInfo *volume, Guid *protocol, uefi_handle handle)
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

NgosStatus Bootloader::initVolumeWholeDisk(VolumeInfo *volume, Guid *protocol)
{
    UEFI_LT((" | volume = 0x%p, protocol = 0x%p", volume, protocol));

    UEFI_ASSERT(volume,   "volume is null",   NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);



    volume->wholeDiskBlockIoProtocol = 0;
    volume->wholeDiskDevicePath      = 0;



    UefiDevicePath *currentDevicePath = volume->devicePath;

    while (!UEFI::isDevicePathEndType(currentDevicePath))
    {
        UefiDevicePath *nextDevicePath = UEFI::nextDevicePathNode(currentDevicePath);



        if (currentDevicePath->type == UefiDevicePathType::MESSAGING_DEVICE_PATH)
        {
            u64 size = (u64)nextDevicePath - (u64)volume->devicePath + sizeof(UefiDevicePath);



            UefiDevicePath *diskDevicePath;

            if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&diskDevicePath) != UefiStatus::SUCCESS)
            {
                UEFI_LE(("Failed to allocate pool(%u) for device path", size));

                return NgosStatus::OUT_OF_MEMORY;
            }

            UEFI_LVV(("Allocated pool(0x%p, %u) for device path", diskDevicePath, size));



            memcpy(diskDevicePath, volume->devicePath, size - sizeof(UefiDevicePath));
            UEFI_ASSERT_EXECUTION(UEFI::setDevicePathEndNode((UefiDevicePath *)((u64)diskDevicePath + size - sizeof(UefiDevicePath))), NgosStatus::ASSERTION);



            UefiDevicePath *devicePath = diskDevicePath;
            uefi_handle     wholeDiskHandle;

            if (UEFI::locateDevicePath(protocol, &devicePath, &wholeDiskHandle) == UefiStatus::SUCCESS)
            {
                UEFI_LVV(("Found whole disk handle (0x%p) for UEFI_BLOCK_IO_PROTOCOL", wholeDiskHandle));

                UEFI_ASSERT_EXECUTION(initVolumeWholeDiskBlockIoProtocol(volume, protocol, wholeDiskHandle), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(initVolumeWholeDiskDevicePath(volume, wholeDiskHandle),                NgosStatus::ASSERTION);
            }
            else
            {
                UEFI_LW(("Whole disk handle for UEFI_BLOCK_IO_PROTOCOL not found"));
            }



            if (UEFI::freePool(diskDevicePath) == UefiStatus::SUCCESS)
            {
                UEFI_LVV(("Released pool(0x%p) for device path", diskDevicePath));
            }
            else
            {
                UEFI_LE(("Failed to free pool(0x%p) for device path", diskDevicePath));

                return NgosStatus::FAILED;
            }
        }



        currentDevicePath = nextDevicePath;
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeWholeDiskBlockIoProtocol(VolumeInfo *volume, Guid *protocol, uefi_handle handle)
{
    UEFI_LT((" | volume = 0x%p, protocol = 0x%p, handle = 0x%p", volume, protocol, handle));

    UEFI_ASSERT(volume,   "volume is null",   NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(handle,   "handle is null",   NgosStatus::ASSERTION);



    if (UEFI::handleProtocol(handle, protocol, (void **)&volume->wholeDiskBlockIoProtocol) != UefiStatus::SUCCESS)
    {
        UEFI_LE(("Failed to handle(0x%p) protocol for UEFI_BLOCK_IO_PROTOCOL", handle));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_BLOCK_IO_PROTOCOL", handle, volume->wholeDiskBlockIoProtocol));



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeWholeDiskDevicePath(VolumeInfo *volume, uefi_handle handle)
{
    UEFI_LT((" | volume = 0x%p, handle = 0x%p", volume, handle));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(handle, "handle is null", NgosStatus::ASSERTION);



    volume->wholeDiskDevicePath = UEFI::devicePathFromHandle(handle);



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
        &&
        !volume->blockIoProtocol->media->logicalPartition
       )
    {
        u64 size = sizeof(Mbr);

        if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&volume->gptData.protectiveMbr) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to allocate pool(%u) for GPT protective MBR", size));

            return NgosStatus::OUT_OF_MEMORY;
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

            return NgosStatus::OUT_OF_MEMORY;
        }

        UEFI_LVV(("Allocated pool(0x%p, %u) for GPT header", volume->gptData.header, size));



        if (volume->blockIoProtocol->readBlocks(volume->blockIoProtocol, volume->blockIoProtocol->media->mediaId, 1, size, (void *)volume->gptData.header) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to read GPT header"));

            return NgosStatus::FAILED;
        }

        UEFI_LVV(("Successfully read GPT header"));



        if (isGptValid(volume->gptData))
        {
            size = volume->gptData.header->entryCount * volume->gptData.header->entrySize;

            if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&volume->gptData.entries) != UefiStatus::SUCCESS)
            {
                UEFI_LF(("Failed to allocate pool(%u) for GPT entries", size));

                return NgosStatus::OUT_OF_MEMORY;
            }

            UEFI_LVV(("Allocated pool(0x%p, %u) for GPT entries", volume->gptData.entries, size));



            if (volume->blockIoProtocol->readBlocks(volume->blockIoProtocol, volume->blockIoProtocol->media->mediaId, volume->gptData.header->entryLba, size, (void *)volume->gptData.entries) != UefiStatus::SUCCESS)
            {
                UEFI_LF(("Failed to read GPT entries"));

                return NgosStatus::FAILED;
            }

            UEFI_LVV(("Successfully read GPT entries"));



            UEFI_TEST_ASSERT(Crc::crc32((u8 *)volume->gptData.entries, size) == volume->gptData.header->entryCrc32, NgosStatus::ASSERTION);



            for (i64 i = 0; i < volume->gptData.header->entryCount; ++i)
            {
                volume->gptData.entries[i].name[ARRAY_COUNT(volume->gptData.entries[i].name) - 1] = 0;
            }
        }
        else
        {
            if (UEFI::freePool(volume->gptData.protectiveMbr) == UefiStatus::SUCCESS)
            {
                UEFI_LVV(("Released pool(0x%p) for GPT protective MBR", volume->gptData.protectiveMbr));
            }
            else
            {
                UEFI_LE(("Failed to free pool(0x%p) for GPT protective MBR", volume->gptData.protectiveMbr));

                return NgosStatus::FAILED;
            }



            if (UEFI::freePool(volume->gptData.header) == UefiStatus::SUCCESS)
            {
                UEFI_LVV(("Released pool(0x%p) for GPT header", volume->gptData.header));
            }
            else
            {
                UEFI_LE(("Failed to free pool(0x%p) for GPT header", volume->gptData.header));

                return NgosStatus::FAILED;
            }



            volume->gptData.protectiveMbr = 0;
            volume->gptData.header        = 0;
        }
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeType(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    if (
        volume->blockIoProtocol->media->blockSize == OPTICAL_BLOCK_SIZE
        ||
        (
         volume->wholeDiskBlockIoProtocol
         &&
         volume->wholeDiskBlockIoProtocol->media->blockSize == OPTICAL_BLOCK_SIZE
        )
       )
    {
        volume->type = VolumeType::OPTICAL;
    }
    else
    {
        volume->type = VolumeType::NONE;



        UefiDevicePath *currentDevicePath = volume->devicePath;

        while (!UEFI::isDevicePathEndType(currentDevicePath))
        {
            if (currentDevicePath->type == UefiDevicePathType::MEDIA_DEVICE_PATH)
            {
                if (currentDevicePath->subType == UefiDevicePathSubType::MEDIA_HARDDRIVE_DP)
                {
                    volume->type = VolumeType::INTERNAL;

                    break;
                }
                else
                if (currentDevicePath->subType == UefiDevicePathSubType::MEDIA_CDROM_DP)
                {
                    volume->type = VolumeType::OPTICAL;

                    break;
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
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeName(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    volume->name = u"UNKNOWN";



    UefiDevicePath *currentDevicePath = volume->devicePath;

    while (!UEFI::isDevicePathEndType(currentDevicePath))
    {
        if (currentDevicePath->type == UefiDevicePathType::MEDIA_DEVICE_PATH)
        {
            if (currentDevicePath->subType == UefiDevicePathSubType::MEDIA_HARDDRIVE_DP)
            {
                UefiHardDriveDevicePath *hardDrivePath = (UefiHardDriveDevicePath *)currentDevicePath;

                if (hardDrivePath->signatureType == UefiHardDriveDevicePathSignatureType::GUID)
                {
                    ListElement<VolumeInfo> *element = sVolumes.getHead();

                    while (element)
                    {
                        const VolumeInfo &previousVolume = element->getData();



                        if (previousVolume.gptData.entries)
                        {
                            for (i64 i = 0; i < previousVolume.gptData.header->entryCount; ++i)
                            {
                                GptEntry *gptEntry = &previousVolume.gptData.entries[i];

                                if (!memcmp(&gptEntry->partitionUniqueGuid, hardDrivePath->signature, sizeof(hardDrivePath->signature))) // memcmp(&gptEntry->partitionUniqueGuid, hardDrivePath->signature, sizeof(hardDrivePath->signature)) == 0
                                {
                                    volume->name = gptEntry->name;

                                    return NgosStatus::OK;
                                }
                            }
                        }



                        element = element->getNext();
                    }
                }
            }
        }



        currentDevicePath = UEFI::nextDevicePathNode(currentDevicePath);
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initVolumeRootDirectory(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    volume->rootDirectory = UEFI::openVolume(volume->deviceHandle);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initOSes()
{
    UEFI_LT((""));



    ListElement<VolumeInfo> *element = sVolumes.getHead();

    while (element)
    {
        UEFI_ASSERT_EXECUTION(initOSesFromVolume((VolumeInfo *)&element->getData()), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    UEFI_ASSERT_EXECUTION(sOSes.sort(), NgosStatus::ASSERTION);



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        UEFI_LVVV(("sOSes:"));
        UEFI_LVVV(("-------------------------------------"));

        ListElement<OsInfo> *element = sOSes.getHead();

        while (element)
        {
            const OsInfo &os = element->getData();

            UEFI_LVVV(("os.type   = %u (%s)", os.type, osTypeToString(os.type)));
            UEFI_LVVV(("os.volume = 0x%p",    os.volume));
            UEFI_LVVV(("os.path   = %S",      os.path));

            UEFI_TEST_ASSERT(os.type != OsType::NONE, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(os.volume,               NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(os.path,                 NgosStatus::ASSERTION);



            element = element->getNext();
        }

        UEFI_LVVV(("-------------------------------------"));
    }
#endif



    return NgosStatus::OK;
}

NgosStatus Bootloader::initOSesFromVolume(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    if (volume->rootDirectory)
    {
        UEFI_ASSERT_EXECUTION(initOSesFromPath(volume, volume->rootDirectory, u"", u"EFI"), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::initOSesFromPath(VolumeInfo *volume, UefiFileProtocol *parentDirectory, const char16 *parentPath, const char16 *path)
{
    UEFI_LT((" | volume = 0x%p, parentDirectory = 0x%p, parentPath = %S, path = %S", volume, parentDirectory, parentPath, path));

    UEFI_ASSERT(volume,          "volume is null",          NgosStatus::ASSERTION);
    UEFI_ASSERT(parentDirectory, "parentDirectory is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(parentPath,      "parentPath is null",      NgosStatus::ASSERTION);
    UEFI_ASSERT(path,            "path is null",            NgosStatus::ASSERTION);



    char16 *absolutePath;

    UEFI_ASSERT_EXECUTION(buildPath(parentPath, path, &absolutePath), NgosStatus::ASSERTION);



    NgosStatus status = NgosStatus::OK;

    // We don't want to scan bootloader directory
    if (strcmpi(absolutePath, sApplicationDirPath)) // absolutePath != sApplicationDirPath
    {
        UefiFileProtocol *directory;

        if (parentDirectory->open(parentDirectory, &directory, path, FLAGS(UefiFileModeFlag::READ), FLAG(UefiFileAttributeFlag::NONE)) == UefiStatus::SUCCESS)
        {
            UEFI_LV(("%S directory openned for OS search", absolutePath));



            status = initOSesFromDirectory(volume, absolutePath, directory);

            if (status != NgosStatus::OK)
            {
                UEFI_LW(("Failed to get OS in %S directory", absolutePath));
            }



            if (directory->close(directory) == UefiStatus::SUCCESS)
            {
                UEFI_LV(("%S directory closed", absolutePath));
            }
            else
            {
                UEFI_LW(("Failed to close %S directory", absolutePath));

                status = NgosStatus::FAILED;
            }
        }
    }
    else
    {
        UEFI_LV(("Ignoring %S directory", absolutePath));
    }



    if (UEFI::freePool(absolutePath) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for string", absolutePath));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for string", absolutePath));
    }



    return status;
}

NgosStatus Bootloader::initOSesFromDirectory(VolumeInfo *volume, char16 *absolutePath, UefiFileProtocol *directory)
{
    UEFI_LT((" | volume = 0x%p, absolutePath = %S, directory = 0x%p", volume, absolutePath, directory));

    UEFI_ASSERT(volume,       "volume is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(absolutePath, "absolutePath is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(directory,    "directory is null",    NgosStatus::ASSERTION);



    do
    {
        u64          size = 0;
        UefiFileInfo fileInfo;

        UefiStatus status = directory->read(directory, &size, &fileInfo);

        if (status == UefiStatus::BUFFER_TOO_SMALL)
        {
            UEFI_LVV(("Found size(%u) of file info", size));



            NgosStatus status = initOSesFromDirectory(volume, absolutePath, directory, size);

            if (status != NgosStatus::OK)
            {
                UEFI_LF(("Failed to search OSes in directory"));

                return status;
            }
        }
        else
        if (status == UefiStatus::SUCCESS)
        {
            break;
        }
        else
        {
            UEFI_LW(("Failed to get size of file info"));

            return NgosStatus::FAILED;
        }
    } while(true);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initOSesFromDirectory(VolumeInfo *volume, char16 *absolutePath, UefiFileProtocol *directory, u64 size)
{
    UEFI_LT((" | volume = 0x%p, absolutePath = %S, directory = 0x%p, size = %u", volume, absolutePath, directory, size));

    UEFI_ASSERT(volume,       "volume is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(absolutePath, "absolutePath is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(directory,    "directory is null",    NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0,     "size is zero",         NgosStatus::ASSERTION);



    UefiFileInfo *fileInfo = 0;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&fileInfo) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for file info", size));

        return NgosStatus::OUT_OF_MEMORY;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for file info", fileInfo, size));



    NgosStatus status = NgosStatus::FAILED;

    u64 bytesRead = size;

    if (directory->read(directory, &bytesRead, fileInfo) == UefiStatus::SUCCESS)
    {
        UEFI_TEST_ASSERT(size == bytesRead,      NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(size == fileInfo->size, NgosStatus::ASSERTION);

        status = initOSesFromDirectory(volume, absolutePath, directory, fileInfo);
    }
    else
    {
        UEFI_LW(("Failed to get file info"));
    }



    if (UEFI::freePool(fileInfo) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for file info", fileInfo));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for file info", fileInfo));
    }



    return status;
}

NgosStatus Bootloader::initOSesFromDirectory(VolumeInfo *volume, char16 *absolutePath, UefiFileProtocol *directory, UefiFileInfo *fileInfo)
{
    UEFI_LT((" | volume = 0x%p, absolutePath = %S, directory = 0x%p, fileInfo = 0x%p", volume, absolutePath, directory, fileInfo));

    UEFI_ASSERT(volume,       "volume is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(absolutePath, "absolutePath is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(directory,    "directory is null",    NgosStatus::ASSERTION);
    UEFI_ASSERT(fileInfo,     "fileInfo is null",     NgosStatus::ASSERTION);



    UEFI_LVVV(("fileInfo->size             = %u",                                          fileInfo->size));
    UEFI_LVVV(("fileInfo->fileSize         = %u",                                          fileInfo->fileSize));
    UEFI_LVVV(("fileInfo->physicalSize     = %u",                                          fileInfo->physicalSize));
    UEFI_LVVV(("fileInfo->createTime       = %04u-%02u-%02u %02u:%02u:%02u.%09u %+d (%u)", fileInfo->createTime.year, fileInfo->createTime.month, fileInfo->createTime.day, fileInfo->createTime.hour, fileInfo->createTime.minute, fileInfo->createTime.second, fileInfo->createTime.nanosecond, fileInfo->createTime.timeZone, fileInfo->createTime.daylight));
    UEFI_LVVV(("fileInfo->lastAccessTime   = %04u-%02u-%02u %02u:%02u:%02u.%09u %+d (%u)", fileInfo->lastAccessTime.year, fileInfo->lastAccessTime.month, fileInfo->lastAccessTime.day, fileInfo->lastAccessTime.hour, fileInfo->lastAccessTime.minute, fileInfo->lastAccessTime.second, fileInfo->lastAccessTime.nanosecond, fileInfo->lastAccessTime.timeZone, fileInfo->lastAccessTime.daylight));
    UEFI_LVVV(("fileInfo->modificationTime = %04u-%02u-%02u %02u:%02u:%02u.%09u %+d (%u)", fileInfo->modificationTime.year, fileInfo->modificationTime.month, fileInfo->modificationTime.day, fileInfo->modificationTime.hour, fileInfo->modificationTime.minute, fileInfo->modificationTime.second, fileInfo->modificationTime.nanosecond, fileInfo->modificationTime.timeZone, fileInfo->modificationTime.daylight));
    UEFI_LVVV(("fileInfo->attributes       = 0x%016lX (%s)",                               fileInfo->attributes, uefiFileAttributeFlagsToString(fileInfo->attributes)));
    UEFI_LVVV(("fileInfo->fileName         = %S",                                          fileInfo->fileName));



    if (
        strcmp(fileInfo->fileName, u".") // fileInfo->fileName != "." // Ignore CppSingleCharVerifier
        &&
        strcmp(fileInfo->fileName, u"..") // fileInfo->fileName != ".."
       )
    {
        if (fileInfo->attributes & FLAG(UefiFileAttributeFlag::DIRECTORY))
        {
            NgosStatus status = initOSesFromPath(volume, directory, absolutePath, fileInfo->fileName);

            if (status != NgosStatus::OK)
            {
                return status;
            }
        }
        else
        {
            if (
                !strcmpi(absolutePath, u"EFI\\NGOS") // absolutePath == "EFI\\NGOS"
                &&
                !strcmpi(fileInfo->fileName, u"ngos.efi") // fileInfo->fileName == "ngos.efi"
               )
            {
                UEFI_ASSERT_EXECUTION(addNgosOS(volume, absolutePath, fileInfo->fileName), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::addNgosOS(VolumeInfo *volume, char16 *directoryPath, char16 *fileName)
{
    UEFI_LT((" | volume = 0x%p, directoryPath = %S, fileName = %S", volume, directoryPath, fileName));

    UEFI_ASSERT(volume,        "volume is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(directoryPath, "directoryPath is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(fileName,      "fileName is null",      NgosStatus::ASSERTION);



    OsInfo os;

    os.type   = OsType::NGOS;
    os.volume = volume;

    UEFI_ASSERT_EXECUTION(buildPath(directoryPath, fileName, &os.path), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sOSes.append(os), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
