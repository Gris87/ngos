#include "bootloader.h"

#include <common/src/bits64/string/string.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



UefiLoadedImageProtocol *Bootloader::sImage;
char                    *Bootloader::sApplicationPath;
UefiDevicePath          *Bootloader::sDevicePath;



NgosStatus Bootloader::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initImage(),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initApplicationPath(), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(initDevicePath(),      NgosStatus::ASSERTION);



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

NgosStatus Bootloader::initApplicationPath()
{
    UEFI_LT((""));



    sApplicationPath = UEFI::devicePathToString(sImage->filePath);

    if (!sApplicationPath)
    {
        UEFI_LF(("Failed to get application path"));

        return NgosStatus::FAILED;
    }



    UEFI_LVVV(("sApplicationPath = %s", sApplicationPath));

    UEFI_TEST_ASSERT(strcmp(sApplicationPath, "\\EFI\\BOOT\\BOOTX64.EFI") == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initDevicePath()
{
    UEFI_LT((""));



    sDevicePath = UEFI::fileDevicePath(sImage->deviceHandle, sApplicationPath);

    if (!sDevicePath)
    {
        UEFI_LF(("Failed to get device path"));

        return NgosStatus::FAILED;
    }



    return NgosStatus::OK;
}
