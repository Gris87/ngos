#include "bootloader.h"

#include <common/src/bits64/string/string.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



UefiLoadedImageProtocol *Bootloader::sImage;
UefiDevicePath          *Bootloader::sDevicePath;
char                    *Bootloader::sApplicationDirPath;



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



    return NgosStatus::OK;
}
