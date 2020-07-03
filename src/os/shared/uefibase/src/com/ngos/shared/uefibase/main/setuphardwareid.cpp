#include "setuphardwareid.h"

#include <common/src/com/ngos/shared/common/dmi/dmi.h>
#include <common/src/com/ngos/shared/common/random/random.h>
#include <common/src/com/ngos/shared/common/string/utils.h>
#include <common/src/com/ngos/shared/common/uefi/uefiloadedimageprotocol.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>
#include <common/src/com/ngos/shared/common/uuid/utils.h>



#define HARDWARE_ID_PATH u"EFI\\hardwareId.txt"



Guid generalGUID = { 0x00112233, 0x4455, 0x6677, { 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF } };



NgosStatus generateHardwareId(BootParams *params, i64 *length)
{
    UEFI_LT((" | params = 0x%p, length = 0x%p", params, length));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(length, "length is null", NgosStatus::ASSERTION);



    const char8 *manufacturer = DMI::getIdentity(DmiIdentity::BASEBOARD_MANUFACTURER);
    const char8 *product      = DMI::getIdentity(DmiIdentity::BASEBOARD_PRODUCT);
    const char8 *systemUuid   = uuidToString(DMI::getUuid(DmiStoredUuid::SYSTEM_UUID));

    if (!manufacturer)
    {
        manufacturer = DMI::getIdentity(DmiIdentity::SYSTEM_MANUFACTURER);
    }

    if (!product)
    {
        product = DMI::getIdentity(DmiIdentity::SYSTEM_PRODUCT_NAME);
    }



    i64 len = sprintf(params->hardwareId, "%s %s %s - ", stringToString(manufacturer), stringToString(product), systemUuid);

    UEFI_LVVV(("len = %u", len));

    UEFI_TEST_ASSERT(len < (i64)sizeof(params->hardwareId), NgosStatus::ASSERTION);



    u64 rand = 0;

    for (i64 i = len; i < (i64)sizeof(params->hardwareId) - 1; ++i)
    {
        if (!rand)
        {
            rand = simpleRandom();
        }

        const char8 *digits = "0123456789ABCDEF";



        params->hardwareId[i] =   digits[rand & 0x0F];
        rand                  >>= 4;
    }

    params->hardwareId[sizeof(params->hardwareId) - 1] = 0;



    *length = len;



    return NgosStatus::OK;
}

NgosStatus saveHardwareIdToNvram(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    if (UEFI::setVariable(u"HardwareID", &generalGUID, sizeof(params->hardwareId), (u8 *)params->hardwareId) == UefiStatus::SUCCESS)
    {
        UEFI_LV(("Stored HardwareID NVRAM variable: %s", params->hardwareId));
    }
    else
    {
        UEFI_LE(("Failed to store HardwareID NVRAM variable"));
    }



    return NgosStatus::OK;
}

NgosStatus loadHardwareIdFromNvram(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    u64    variableSize;
    char8 *nvramHardwareId;

    if (UEFI::getVariable(u"HardwareID", &generalGUID, &variableSize, (u8 **)&nvramHardwareId) == UefiStatus::SUCCESS)
    {
        UEFI_LV(("Loaded HardwareID NVRAM variable: %s", nvramHardwareId));

        UEFI_TEST_ASSERT(variableSize == (strlen(nvramHardwareId) + 1) * sizeof(char8), NgosStatus::ASSERTION);



        strcpy(params->hardwareId, nvramHardwareId);



        if (UEFI::freePool(nvramHardwareId) == UefiStatus::SUCCESS)
        {
            UEFI_LVV(("Released pool(0x%p) for NVRAM variable", nvramHardwareId));
        }
        else
        {
            UEFI_LE(("Failed to release pool(0x%p) for NVRAM variable", nvramHardwareId));
        }
    }
    else
    {
        params->hardwareId[0] = 0;
    }



    return NgosStatus::OK;
}

NgosStatus saveHardwareIdToFile(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    Guid        protocol = UEFI_LOADED_IMAGE_PROTOCOL_GUID;
    uefi_handle handle   = UEFI::getImageHandle();



    UefiLoadedImageProtocol *image;

    if (UEFI::handleProtocol(handle, &protocol, (void **)&image) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to handle(0x%p) protocol for UEFI_LOADED_IMAGE_PROTOCOL", handle));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_LOADED_IMAGE_PROTOCOL", handle, image));



    UefiFileProtocol *rootDirectory = UEFI::openVolume(image->deviceHandle);

    if (rootDirectory)
    {
        UefiFileProtocol *hardwareIdFile;

        if (rootDirectory->open(rootDirectory, &hardwareIdFile, HARDWARE_ID_PATH, FLAGS(UefiFileModeFlag::CREATE, UefiFileModeFlag::READ, UefiFileModeFlag::WRITE), FLAGS(UefiFileAttributeFlag::NONE)) == UefiStatus::SUCCESS)
        {
            UEFI_LV(("Created hardware ID file: %ls", HARDWARE_ID_PATH));

            u64 size = sizeof(params->hardwareId) - 1;

            if (hardwareIdFile->write(hardwareIdFile, &size, params->hardwareId) == UefiStatus::SUCCESS)
            {
                char8 ch = '\n';
                size     = sizeof(ch);

                if (hardwareIdFile->write(hardwareIdFile, &size, &ch) == UefiStatus::SUCCESS)
                {
                    UEFI_LV(("Stored HardwareID to file: %s", params->hardwareId));
                }
                else
                {
                    UEFI_LW(("Failed to write hardware ID file: %ls", HARDWARE_ID_PATH));
                }
            }
            else
            {
                UEFI_LW(("Failed to write hardware ID file: %ls", HARDWARE_ID_PATH));
            }



            if (hardwareIdFile->close(hardwareIdFile) == UefiStatus::SUCCESS)
            {
                UEFI_LV(("Closed hardware ID file: %ls", HARDWARE_ID_PATH));
            }
            else
            {
                UEFI_LW(("Failed to close hardware ID file: %ls", HARDWARE_ID_PATH));
            }
        }
        else
        {
            UEFI_LV(("Failed to create hardware ID file: %ls", HARDWARE_ID_PATH));
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
    else
    {
        UEFI_LW(("Failed to open volume root directory"));
    }



    return NgosStatus::OK;
}

NgosStatus loadHardwareIdFromFile(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    Guid        protocol = UEFI_LOADED_IMAGE_PROTOCOL_GUID;
    uefi_handle handle   = UEFI::getImageHandle();



    UefiLoadedImageProtocol *image;

    if (UEFI::handleProtocol(handle, &protocol, (void **)&image) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to handle(0x%p) protocol for UEFI_LOADED_IMAGE_PROTOCOL", handle));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_LOADED_IMAGE_PROTOCOL", handle, image));



    char8 hardwareId[HARDWARE_ID_LENGTH];
    u64   size = sizeof(hardwareId);



    UefiFileProtocol *rootDirectory = UEFI::openVolume(image->deviceHandle);

    if (rootDirectory)
    {
        UefiFileProtocol *hardwareIdFile;

        if (rootDirectory->open(rootDirectory, &hardwareIdFile, HARDWARE_ID_PATH, FLAGS(UefiFileModeFlag::READ), FLAGS(UefiFileAttributeFlag::NONE)) == UefiStatus::SUCCESS)
        {
            UEFI_LV(("Openned hardware ID file: %ls", HARDWARE_ID_PATH));

            if (hardwareIdFile->read(hardwareIdFile, &size, hardwareId) == UefiStatus::SUCCESS)
            {
                if (size < sizeof(hardwareId))
                {
                    hardwareId[size] = 0;
                }
                else
                {
                    hardwareId[sizeof(hardwareId) - 1] = 0;
                }



                UEFI_LV(("Loaded HardwareID: %s", hardwareId));
            }
            else
            {
                UEFI_LW(("Failed to read hardware ID file: %ls", HARDWARE_ID_PATH));

                hardwareId[0] = 0;
            }



            if (hardwareIdFile->close(hardwareIdFile) == UefiStatus::SUCCESS)
            {
                UEFI_LV(("Closed hardware ID file: %ls", HARDWARE_ID_PATH));
            }
            else
            {
                UEFI_LW(("Failed to close hardware ID file: %ls", HARDWARE_ID_PATH));
            }
        }
        else
        {
            UEFI_LV(("Failed to open hardware ID file: %ls", HARDWARE_ID_PATH));

            hardwareId[0] = 0;
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
    else
    {
        UEFI_LW(("Failed to open volume root directory"));

        hardwareId[0] = 0;
    }



    if (!strequal(params->hardwareId, ""))
    {
        if (!strequal(params->hardwareId, hardwareId))
        {
            UEFI_ASSERT_EXECUTION(saveHardwareIdToFile(params),  NgosStatus::ASSERTION);
        }
    }
    else
    {
        i64 length;

        UEFI_ASSERT_EXECUTION(generateHardwareId(params, &length), NgosStatus::ASSERTION);

        if (!strequal(hardwareId, ""))
        {
            if (!strnequal(params->hardwareId, hardwareId, length))
            {
                UEFI_ASSERT_EXECUTION(saveHardwareIdToNvram(params), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(saveHardwareIdToFile(params),  NgosStatus::ASSERTION);
            }
            else
            {
                strcpy(params->hardwareId, hardwareId);

                UEFI_ASSERT_EXECUTION(saveHardwareIdToNvram(params), NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_ASSERT_EXECUTION(saveHardwareIdToNvram(params), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(saveHardwareIdToFile(params),  NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus setupHardwareId(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(DMI::init(), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(loadHardwareIdFromNvram(params), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(loadHardwareIdFromFile(params),  NgosStatus::ASSERTION);

    UEFI_LVVV(("params->hardwareId = %s", params->hardwareId));



    return NgosStatus::OK;
}
