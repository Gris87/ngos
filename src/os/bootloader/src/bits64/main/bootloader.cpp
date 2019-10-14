#include "bootloader.h"

#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/string/string.h>
#include <gpt/utils.h>
#include <guid/utils.h>
#include <ngos/utils.h>
#include <uefi/uefiblockioprotocol.h>
#include <uefi/uefifileinfo.h>
#include <uefi/uefifilesysteminfo.h>
#include <uefi/uefiharddrivedevicepath.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



#define OPTICAL_BLOCK_SIZE 2048



UefiLoadedImageProtocol *Bootloader::sImage;
char16                  *Bootloader::sApplicationDirPath;
VolumeInfo              *Bootloader::sMainVolume;
List<VolumeInfo>         Bootloader::sVolumes;
ArrayList<OsInfo>        Bootloader::sOSes;



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
    UEFI_LT((" | path = %ls", path));

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
    UEFI_LT((" | parentPath = %ls, path = %ls, res = 0x%p", parentPath, path, res));

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

NgosStatus Bootloader::buildPath(const char16 *parentPath, const char8 *path, char16 **res)
{
    UEFI_LT((" | parentPath = %ls, path = %s, res = 0x%p", parentPath, path, res));

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

        for (i64 i = 0; i <= size2; ++i)
        {
            str[size1 + 1 + i] = path[i];
        }
    }
    else
    {
        for (i64 i = 0; i <= size2; ++i)
        {
            str[i] = path[i];
        }
    }



    *res = str;



    return NgosStatus::OK;
}

NgosStatus Bootloader::loadImageFromDiskOrAssets(const char8 *path, Image **image)
{
    UEFI_LT((" | path = %s, image = 0x%p", path, image));

    UEFI_ASSERT(path,  "path is null",  NgosStatus::ASSERTION);
    UEFI_ASSERT(image, "image is null", NgosStatus::ASSERTION);



    UefiFileProtocol *imageFile   = 0;
    u8               *content     = 0;
    u64               contentSize = 0;
    NgosStatus        status      = NgosStatus::NO_EFFECT;



    char16 *absolutePath;

    UEFI_ASSERT_EXECUTION(buildPath(sApplicationDirPath, path, &absolutePath), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cleanUpPath(absolutePath),                           NgosStatus::ASSERTION);



    if (sMainVolume->rootDirectory->open(sMainVolume->rootDirectory, &imageFile, absolutePath, FLAGS(UefiFileModeFlag::READ), FLAG(UefiFileAttributeFlag::NONE)) == UefiStatus::SUCCESS)
    {
        UEFI_LV(("%ls image file openned", absolutePath));



        Guid          fileInfoGuid = UEFI_FILE_INFO_GUID;
        u64           fileInfoSize = 0;
        UefiFileInfo *fileInfo;



        if (imageFile->getInfo(imageFile, &fileInfoGuid, &fileInfoSize, &fileInfo) == UefiStatus::BUFFER_TOO_SMALL)
        {
            if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, fileInfoSize, (void **)&fileInfo) != UefiStatus::SUCCESS)
            {
                UEFI_LF(("Failed to allocate pool(%u) for image file info", fileInfoSize));

                return NgosStatus::OUT_OF_MEMORY;
            }

            UEFI_LVV(("Allocated pool(0x%p, %u) for image file info", fileInfo, fileInfoSize));



            if (imageFile->getInfo(imageFile, &fileInfoGuid, &fileInfoSize, fileInfo) == UefiStatus::SUCCESS)
            {
                contentSize = fileInfo->fileSize;

                UEFI_LVV(("%ls image file size is %u", absolutePath, contentSize));



                if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, contentSize, (void **)&content) != UefiStatus::SUCCESS)
                {
                    UEFI_LF(("Failed to allocate pool(%u) for image file content", contentSize));

                    return NgosStatus::OUT_OF_MEMORY;
                }

                UEFI_LVV(("Allocated pool(0x%p, %u) for image file content", content, contentSize));



                if (imageFile->read(imageFile, &contentSize, content) == UefiStatus::SUCCESS)
                {
                    UEFI_LVV(("%ls image file loaded", absolutePath));

                    status = NgosStatus::OK;
                }
                else
                {
                    UEFI_LW(("Failed to read %ls image file content", absolutePath));
                }
            }
            else
            {
                UEFI_LW(("Failed to get size of %ls image file", absolutePath));
            }



            if (UEFI::freePool(fileInfo) == UefiStatus::SUCCESS)
            {
                UEFI_LVV(("Released pool(0x%p) for image file info", fileInfo));
            }
            else
            {
                UEFI_LE(("Failed to release pool(0x%p) for image file info", fileInfo));
            }
        }
        else
        {
            UEFI_LW(("Failed to get size of %ls image file", absolutePath));
        }

        if (imageFile->close(imageFile) == UefiStatus::SUCCESS)
        {
            UEFI_LV(("%ls image file closed", absolutePath));
        }
        else
        {
            UEFI_LW(("Failed to close %ls image file", absolutePath));

            status = NgosStatus::FAILED;
        }
    }
    else
    {
        UEFI_LVV(("%ls image file not found. Loading from assets", absolutePath));
    }



    bool withNinePatch = strend(path, ".9.png");



    if (status == NgosStatus::OK)
    {
        status = Graphics::loadImage(content, contentSize, withNinePatch, image);

        if (status != NgosStatus::OK)
        {
            UEFI_LE(("Failed to load image in file %ls", absolutePath));
        }
    }



    if (status != NgosStatus::OK)
    {
        AssetEntry *asset = Assets::getAssetEntry(path);
        UEFI_TEST_ASSERT(asset, NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(Graphics::loadImage(asset->content, asset->contentSize, withNinePatch, image), NgosStatus::ASSERTION);
    }



    if (UEFI::freePool(absolutePath) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for string", absolutePath));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for string", absolutePath));
    }



    if (content)
    {
        if (UEFI::freePool(content) == UefiStatus::SUCCESS)
        {
            UEFI_LVV(("Released pool(0x%p) for image file content", content));
        }
        else
        {
            UEFI_LE(("Failed to release pool(0x%p) for image file content", content));
        }
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::startTool(const char8 *path)
{
    UEFI_LT((" | path = 0x%p", path));

    UEFI_ASSERT(path, "path is null", NgosStatus::ASSERTION);



    char16 *absolutePath;

    UEFI_ASSERT_EXECUTION(buildPath(sApplicationDirPath, path, &absolutePath), NgosStatus::ASSERTION);



    return startApplication(sMainVolume, absolutePath);
}

NgosStatus Bootloader::startOs(u64 index)
{
    UEFI_LT((" | index = %u", index));

    UEFI_ASSERT(index < sOSes.getSize(), "index is invalid", NgosStatus::ASSERTION);



    const OsInfo &os = sOSes.at(index);

    return startApplication(os.volume, os.path);
}

const ArrayList<OsInfo>& Bootloader::getOSes()
{
    UEFI_LT((""));



    return sOSes;
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



    UEFI_LVVV(("*applicationPath = %ls", *applicationPath));

    UEFI_TEST_ASSERT(strcmpi(*applicationPath, u"\\EFI\\BOOT\\BOOTX64.EFI") == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initApplicationDirPath(char16 *applicationPath)
{
    UEFI_LT((" | applicationPath = %ls", applicationPath));

    UEFI_ASSERT(applicationPath, "applicationPath is null", NgosStatus::ASSERTION);



    sApplicationDirPath = UEFI::parentDirectory(applicationPath);
    UEFI_ASSERT_EXECUTION(cleanUpPath(sApplicationDirPath), NgosStatus::ASSERTION);

    UEFI_LVVV(("sApplicationDirPath = %ls", sApplicationDirPath));

    UEFI_TEST_ASSERT(strcmpi(sApplicationDirPath, u"EFI\\BOOT") == 0, NgosStatus::ASSERTION);



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



    UEFI_LVVV(("sMainVolume = 0x%p", sMainVolume));

    UEFI_TEST_ASSERT(sMainVolume,                NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(sMainVolume->rootDirectory, NgosStatus::ASSERTION);



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
            UEFI_LVVV(("volume.devicePath      = 0x%p", volume.devicePath));



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
            UEFI_LVVV(("volume.name                  = %ls",     volume.name));
            UEFI_LVVV(("volume.partitionUniqueGuid   = 0x%p",    volume.partitionUniqueGuid));
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

            if (volume.deviceHandle == sImage->deviceHandle)
            {
                UEFI_TEST_ASSERT(!sMainVolume, NgosStatus::ASSERTION);

                sMainVolume = (VolumeInfo *)&sVolumes.getTail()->getData();
            }
        }
        else
        {
            UEFI_TEST_ASSERT(volume.deviceHandle != sImage->deviceHandle, NgosStatus::ASSERTION);

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
    UEFI_ASSERT_EXECUTION(initVolumeRootDirectory(volume),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeType(volume),                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initVolumeNameAndGuid(volume),                       NgosStatus::ASSERTION);



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
                UEFI_LF(("Failed to allocate pool(%u) for device path", size));

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
        u64 size = ROUND_UP(sizeof(Mbr), volume->blockIoProtocol->media->blockSize);

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



        size = ROUND_UP(sizeof(GptHeader), volume->blockIoProtocol->media->blockSize);

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

NgosStatus Bootloader::initVolumeNameAndGuid(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    volume->name                = u"UNKNOWN";
    volume->partitionUniqueGuid = nullptr;



    UefiDevicePath *currentDevicePath = volume->devicePath;

    while (!UEFI::isDevicePathEndType(currentDevicePath))
    {
        if (
            currentDevicePath->type == UefiDevicePathType::MEDIA_DEVICE_PATH
            &&
            currentDevicePath->subType == UefiDevicePathSubType::MEDIA_HARDDRIVE_DP
           )
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

                            if (isGuidEquals(gptEntry->partitionUniqueGuid, hardDrivePath->signatureGuid))
                            {
                                volume->name                = gptEntry->name;
                                volume->partitionUniqueGuid = &gptEntry->partitionUniqueGuid;

                                return NgosStatus::OK;
                            }
                        }
                    }



                    element = element->getNext();
                }
            }
        }



        currentDevicePath = UEFI::nextDevicePathNode(currentDevicePath);
    }



    if (!volume->partitionUniqueGuid)
    {
        Guid *partitionUniqueGuid;
        u64   size = sizeof(*partitionUniqueGuid);

        UEFI_TEST_ASSERT(size == 16, NgosStatus::ASSERTION);

        if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&partitionUniqueGuid) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to allocate pool(%u) for GUID", size));

            return NgosStatus::OUT_OF_MEMORY;
        }

        UEFI_LVV(("Allocated pool(0x%p, %u) for GUID", partitionUniqueGuid, size));



        memzero(partitionUniqueGuid, size);



        u64 *guid         = (u64 *)partitionUniqueGuid;
        u8   guidIndex    = 0;
        currentDevicePath = volume->devicePath;

        do
        {
            guid[guidIndex] ^= Crc::crc64((u8 *)currentDevicePath, currentDevicePath->length);

            if (UEFI::isDevicePathEndType(currentDevicePath))
            {
                break;
            }

            guidIndex ^= 0x01;



            currentDevicePath = UEFI::nextDevicePathNode(currentDevicePath);
        } while(true);



        volume->partitionUniqueGuid = partitionUniqueGuid;
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

        for (i64 i = 0; i < (i64)sOSes.getSize(); ++i)
        {
            const OsInfo &os = sOSes.at(i);

            UEFI_LVVV(("os.type   = %u (%s)", os.type, osTypeToString(os.type)));
            UEFI_LVVV(("os.volume = 0x%p",    os.volume));
            UEFI_LVVV(("os.path   = %ls",     os.path));

            UEFI_TEST_ASSERT(os.type < OsType::MAXIMUM, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(os.volume,                 NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(os.path,                   NgosStatus::ASSERTION);



            if (i < (i64)(sOSes.getSize() - 1))
            {
                UEFI_LVVV(("+++++++++++++++++++++++++++++++++++++"));
            }
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
        UEFI_ASSERT_EXECUTION(addNgosKernel(volume),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(addNgosInstaller(volume), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(addWindows10(volume),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(addUbuntu19(volume),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(addCentOS8(volume),       NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::addNgosKernel(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    const char16 *path = u"EFI\\NGOS\\kernel.efi";

    if (UEFI::fileExists(volume->rootDirectory, path))
    {
        OsInfo os;

        os.type   = OsType::NGOS;
        os.volume = volume;
        os.path   = (char16 *)path;

        UEFI_ASSERT_EXECUTION(sOSes.append(os), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::addNgosInstaller(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    const char16 *path = u"EFI\\NGOS\\installer.efi";

    if (UEFI::fileExists(volume->rootDirectory, path))
    {
        OsInfo os;

        os.type   = OsType::NGOS;
        os.volume = volume;
        os.path   = (char16 *)path;

        UEFI_ASSERT_EXECUTION(sOSes.append(os), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::addWindows10(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    const char16 *path = u"EFI\\Microsoft\\Boot\\bootmgfw.efi";

    if (UEFI::fileExists(volume->rootDirectory, path))
    {
        OsInfo os;

        os.type   = OsType::WINDOWS_10;
        os.volume = volume;
        os.path   = (char16 *)path;

        UEFI_ASSERT_EXECUTION(sOSes.append(os), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::addUbuntu19(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    const char16 *path = u"EFI\\ubuntu\\grubx64.efi";

    if (UEFI::fileExists(volume->rootDirectory, path))
    {
        OsInfo os;

        os.type   = OsType::UBUNTU_19;
        os.volume = volume;
        os.path   = (char16 *)path;

        UEFI_ASSERT_EXECUTION(sOSes.append(os), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::addCentOS8(VolumeInfo *volume)
{
    UEFI_LT((" | volume = 0x%p", volume));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);



    const char16 *path = u"EFI\\centos\\grubx64.efi";

    if (UEFI::fileExists(volume->rootDirectory, path))
    {
        OsInfo os;

        os.type   = OsType::CENTOS_8;
        os.volume = volume;
        os.path   = (char16 *)path;

        UEFI_ASSERT_EXECUTION(sOSes.append(os), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Bootloader::startApplication(VolumeInfo *volume, const char16 *path)
{
    UEFI_LT((" | volume = 0x%p, path = 0x%p", volume, path));

    UEFI_ASSERT(volume, "volume is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(path,   "path is null",   NgosStatus::ASSERTION);



    UefiDevicePath *devicePath = UEFI::fileDevicePath(volume->deviceHandle, path);

    if (!devicePath)
    {
        UEFI_LE(("Failed to get device path for %ls", path));

        return NgosStatus::FAILED;
    }



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        UEFI_LVVV(("devicePath:"));
        UEFI_LVVV(("-------------------------------------"));

        UefiDevicePath *currentDevicePath = devicePath;

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



    uefi_handle childImageHandle;

    if (UEFI::loadImage(false, UEFI::getImageHandle(), devicePath, nullptr, 0, &childImageHandle) != UefiStatus::SUCCESS)
    {
        UEFI_LE(("Failed to load %ls", path));

        return NgosStatus::FAILED;
    }

    UEFI_LV(("Loaded %ls with image handle 0x%p", path, childImageHandle));



    Guid                     protocol = UEFI_LOADED_IMAGE_PROTOCOL_GUID;
    UefiLoadedImageProtocol *childImage;



    if (UEFI::handleProtocol(childImageHandle, &protocol, (void **)&childImage) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to handle(0x%p) protocol for UEFI_LOADED_IMAGE_PROTOCOL", childImageHandle));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_LOADED_IMAGE_PROTOCOL", childImageHandle, childImage));



    UEFI_LVVV(("Loaded image:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("childImage->imageBase = 0x%p", childImage->imageBase));
    UEFI_LVVV(("childImage->imageSize = %u",   childImage->imageSize));

    UEFI_LVVV(("-------------------------------------"));



    u64     optionsSize = (1 + strlen(path) + 2) * sizeof(char16);
    char16 *options;

    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, optionsSize, (void **)&options) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for string", optionsSize));

        return NgosStatus::OUT_OF_MEMORY;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for string", str, optionsSize));



    options[0] = '\\';
    strapp(strapp(&options[1], path), u" ");



    childImage->loadOptionsSize = optionsSize;
    childImage->loadOptions     = options;

    UEFI_LVVV(("childImage->loadOptionsSize = %u",  childImage->loadOptionsSize));
    UEFI_LVVV(("childImage->loadOptions     = %ls", childImage->loadOptions));




    UEFI_LI(("Starting %ls", path));

    UEFI_ASSERT_EXECUTION(GraphicalConsole::noMorePrint(), NgosStatus::ASSERTION);



    RgbaPixel blackPixel;
    memzero(&blackPixel, sizeof(blackPixel));



    ListElement<ScreenWidget *> *screen = GUI::getRootWidget()->getScreens().getHead();

    while (screen)
    {
        UefiGraphicsOutputProtocol *screenGop = screen->getData()->getScreenGop();

        UEFI_ASSERT_EXECUTION(screenGop->blt(screenGop,
                                                (UefiGraphicsOutputBltPixel *)&blackPixel,
                                                UefiGraphicsOutputBltOperation::VIDEO_FILL,
                                                0, 0,
                                                0, 0,
                                                screenGop->mode->info->horizontalResolution,
                                                screenGop->mode->info->verticalResolution,
                                                0),
                                UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

        screen = screen->getNext();
    }



    UEFI_ASSERT_EXECUTION(UEFI::switchToTextMode(),                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(UEFI::startImage(childImageHandle, nullptr, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    // Reboot if we exits from application
    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::COLD, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
