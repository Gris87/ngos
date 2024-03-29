#include "setuppciio.h"

#include <com/ngos/shared/common/bootparams/lib/pciromimagewithinfo.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>
#include <com/ngos/shared/common/pci/pciregister.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocol.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



NgosStatus processPciRomImage(UefiPciIoProtocol *pci, PciRomImageWithInfo **result)
{
    UEFI_LT((" | pci = 0x%p, result = 0x%p", pci, result));

    UEFI_ASSERT(pci,    "pci is null",    NgosStatus::ASSERTION);
    UEFI_ASSERT(result, "result is null", NgosStatus::ASSERTION);



    u64                  size = sizeof(PciRomImageWithInfo) + pci->romSize;
    PciRomImageWithInfo *rom  = nullptr;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&rom) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for ROM image for protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", size, pci));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for ROM image for protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", rom, size, pci));



    *result = rom;

    rom->next    = nullptr;
    rom->romSize = pci->romSize;



    if (pci->pci.read(pci, UefiPciIoProtocolWidth::UINT16, (u64)PciRegister::VENDOR_ID, 1, &rom->vendorId) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Successfully read PCI register Vendor ID(0x%04X) from protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", rom->vendorId, pci));

        if (pci->pci.read(pci, UefiPciIoProtocolWidth::UINT16, (u64)PciRegister::DEVICE_ID, 1, &rom->deviceId) == UefiStatus::SUCCESS)
        {
            UEFI_LVV(("Successfully read PCI register Device ID(0x%04X) from protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", rom->deviceId, pci));

            if (pci->getLocation(pci, &rom->segmentNumber, &rom->busNumber, &rom->deviceNumber, &rom->functionNumber) == UefiStatus::SUCCESS)
            {
                UEFI_LVV(("Found PCI location(%u, %u, %u, %u) from protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", rom->segmentNumber, rom->busNumber, rom->deviceNumber, rom->functionNumber, pci));



                memcpy(rom->romImage, pci->romImage, pci->romSize);



                return NgosStatus::OK;
            }
            else
            {
                UEFI_LE(("Failed to get PCI location from protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", pci));
            }
        }
        else
        {
            UEFI_LE(("Failed to read PCI register Device ID from protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", pci));
        }
    }
    else
    {
        UEFI_LE(("Failed to read PCI register Vendor ID from protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", pci));
    }



    // ----------------------------------------
    // Failed => We need to free allocated pool
    // ----------------------------------------



    if (UEFI::freePool(rom) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for ROM image for protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", rom, pci));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for ROM image for protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", rom, pci));
    }



    return NgosStatus::FAILED;
}

NgosStatus setupPciIoProtocol(BootParams *params, Guid *protocol, u64 size, uefi_handle *pciIoHandles)
{
    UEFI_LT((" | params = 0x%p, protocol = 0x%p, size = %u, pciIoHandles = 0x%p", params, protocol, size, pciIoHandles));

    UEFI_ASSERT(params,       "params is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol,     "protocol is null",     NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0,     "size is invalid",      NgosStatus::ASSERTION);
    UEFI_ASSERT(pciIoHandles, "pciIoHandles is null", NgosStatus::ASSERTION);



    PciRomImageWithInfo *curNode = nullptr;



    i64 count = size / sizeof(uefi_handle);
    UEFI_LVVV(("count = %d", count));

    for (good_I64 i = 0; i < count; ++i)
    {
        uefi_handle        handle = pciIoHandles[i];
        UefiPciIoProtocol *pci    = nullptr;



        if (UEFI::handleProtocol(handle, protocol, (void **)&pci) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to handle(0x%p) protocol for UEFI_PCI_IO_PROTOCOL", handle));

            continue;
        }

        UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", handle, pci));



        if (pci->romImage == nullptr || pci->romSize == 0)
        {
            UEFI_LVV(("Skipped protocol(0x%p) without ROM Image for UEFI_PCI_IO_PROTOCOL", pci));

            continue;
        }



        PciRomImageWithInfo *rom = nullptr;

        if (processPciRomImage(pci, &rom) != NgosStatus::OK)
        {
            UEFI_LE(("Failed to process protocol(0x%p) for UEFI_PCI_IO_PROTOCOL", pci));

            continue;
        }

        UEFI_LVV(("Processed protocol(0x%p) with ROM Image(0x%p) for UEFI_PCI_IO_PROTOCOL", pci, rom));



        if (curNode)
        {
            curNode->next = rom;
        }
        else
        {
            params->pciRomImages = rom;
        }

        curNode = rom;
    }



    if (params->pciRomImages)
    {
        UEFI_LVV(("Found valid protocol with ROM Image(0x%p) for UEFI_PCI_IO_PROTOCOL", params->pciRomImages));
    }
    else
    {
        UEFI_LVV(("Protocol with ROM Image for UEFI_PCI_IO_PROTOCOL not found"));
    }



    // Validation
    {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            UEFI_LVVV(("ROM Images:"));
            UEFI_LVVV(("-------------------------------------"));

            curNode = params->pciRomImages;

            while (curNode)
            {
                UEFI_LVVV(("ROM Image with info: 0x%p", curNode));
                UEFI_LVVV((""));

                UEFI_LVVV(("next           = 0x%p",        curNode->next));
                UEFI_LVVV(("vendorId       = 0x%04X (%s)", curNode->vendorId, enumToHumanString((PciVendor)curNode->vendorId)));
                UEFI_LVVV(("deviceId       = 0x%04X (%s)", curNode->deviceId, enumToHumanString((PciVendor)curNode->vendorId, curNode->deviceId)));
                UEFI_LVVV(("segmentNumber  = %u",          curNode->segmentNumber));
                UEFI_LVVV(("busNumber      = %u",          curNode->busNumber));
                UEFI_LVVV(("deviceNumber   = %u",          curNode->deviceNumber));
                UEFI_LVVV(("functionNumber = %u",          curNode->functionNumber));
                UEFI_LVVV(("romSize        = %u",          curNode->romSize));

                UEFI_LVVV((""));



                curNode = curNode->next;
            }

            UEFI_LVVV(("-------------------------------------"));
        }
#endif



        // UEFI_TEST_ASSERT(params->pciRomImages                       != nullptr, NgosStatus::ASSERTION); // Commented due to value variation

        // UEFI_TEST_ASSERT(params->pciRomImages->next                 != nullptr, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->vendorId             == 0x15AD,  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->deviceId             == 0x0405,  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->segmentNumber        == 0,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->busNumber            == 0,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->deviceNumber         == 2,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->functionNumber       == 0,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->romSize              == 38400,   NgosStatus::ASSERTION); // Commented due to value variation

        // UEFI_TEST_ASSERT(params->pciRomImages->next->next           == nullptr, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->next->vendorId       == 0x10EC,  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->next->deviceId       == 0x8139,  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->next->segmentNumber  == 0,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->next->busNumber      == 0,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->next->deviceNumber   == 3,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->next->functionNumber == 0,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->pciRomImages->next->romSize        == 247808,  NgosStatus::ASSERTION); // Commented due to value variation
    }



    return NgosStatus::OK;
}

NgosStatus setupPciIoProtocol(BootParams *params, Guid *protocol, u64 size)
{
    UEFI_LT((" | params = 0x%p, protocol = 0x%p, size = %u", params, protocol, size));

    UEFI_ASSERT(params,   "params is null",   NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is invalid",  NgosStatus::ASSERTION);



    uefi_handle *pciIoHandles = nullptr;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&pciIoHandles) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for handles for UEFI_PCI_IO_PROTOCOL", size));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for handles for UEFI_PCI_IO_PROTOCOL", pciIoHandles, size));



    NgosStatus status = NgosStatus::FAILED;

    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, protocol, nullptr, &size, pciIoHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Located handles(0x%p) for UEFI_PCI_IO_PROTOCOL", pciIoHandles));

        status = setupPciIoProtocol(params, protocol, size, pciIoHandles);
    }
    else
    {
        UEFI_LF(("Failed to locate handles(0x%p) for UEFI_PCI_IO_PROTOCOL", pciIoHandles));
    }



    if (UEFI::freePool(pciIoHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for handles for UEFI_PCI_IO_PROTOCOL", pciIoHandles));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for handles for UEFI_PCI_IO_PROTOCOL", pciIoHandles));
    }



    return status;
}

NgosStatus setupPciIo(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    Guid pciIoProtocol = UEFI_PCI_IO_PROTOCOL_GUID;
    u64  pciIoSize     = 0;



    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, &pciIoProtocol, nullptr, &pciIoSize, nullptr) == UefiStatus::BUFFER_TOO_SMALL)
    {
        UEFI_LVV(("Found size(%u) of buffer for handles for UEFI_PCI_IO_PROTOCOL", pciIoSize));

        if (setupPciIoProtocol(params, &pciIoProtocol, pciIoSize) != NgosStatus::OK)
        {
            UEFI_LF(("Failed to setup UEFI_PCI_IO_PROTOCOL"));

            return NgosStatus::FAILED;
        }

        UEFI_LV(("Setup UEFI_PCI_IO_PROTOCOL completed"));
    }
    else
    {
        UEFI_LV(("Handle for UEFI_PCI_IO_PROTOCOL not found"));
    }



    return NgosStatus::OK;
}
