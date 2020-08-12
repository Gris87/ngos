#include "devicemanagerpci.h"

#include <com/ngos/shared/common/pci/database/generated/pcibaseclass.h>
#include <com/ngos/shared/common/pci/macros.h>
#include <com/ngos/shared/common/pci/pcideviceindependentregion.h>
#include <com/ngos/shared/common/pci/pciregister.h>
#include <com/ngos/shared/common/string/utils.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



ArrayList<DeviceManagerEntry *> DeviceManagerPci::sEntries;



NgosStatus DeviceManagerPci::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initPciRootBridgeIoProtocols(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

const ArrayList<DeviceManagerEntry *>& DeviceManagerPci::getEntries()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return sEntries;
}

NgosStatus DeviceManagerPci::initPciRootBridgeIoProtocols()
{
    UEFI_LT((""));



    Guid protocol = UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GUID;
    u64  size     = 0;



    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, &protocol, 0, &size, nullptr) == UefiStatus::BUFFER_TOO_SMALL)
    {
        UEFI_LVV(("Found size(%u) of buffer for handles for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL", size));

        if (initPciRootBridgeIoProtocols(&protocol, size) != NgosStatus::OK)
        {
            UEFI_LF(("Failed to setup UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL"));

            return NgosStatus::FAILED;
        }

        UEFI_LV(("Setup UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL completed"));
    }
    else
    {
        UEFI_LW(("Handle for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL not found"));
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciRootBridgeIoProtocols(Guid *protocol, u64 size)
{
    UEFI_LT((" | protocol = 0x%p, size = %u", protocol, size));

    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is zero",     NgosStatus::ASSERTION);



    uefi_handle *handles = nullptr;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&handles) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for handles for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL", size));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for handles for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL", handles, size));



    NgosStatus status = NgosStatus::FAILED;

    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, protocol, 0, &size, handles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Located handles(0x%p) for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL", handles));

        status = initPciRootBridgeIoProtocols(protocol, size, handles);
    }
    else
    {
        UEFI_LF(("Failed to locate handles(0x%p) for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL", handles));
    }



    if (UEFI::freePool(handles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for handles for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL", handles));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for handles for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL", handles));
    }



    return status;
}

NgosStatus DeviceManagerPci::initPciRootBridgeIoProtocols(Guid *protocol, u64 size, uefi_handle *handles)
{
    UEFI_LT((" | protocol = 0x%p, size = %u, handles = 0x%p", protocol, size, handles));

    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is zero",     NgosStatus::ASSERTION);
    UEFI_ASSERT(handles,  "handles is null",  NgosStatus::ASSERTION);



    i64 count = size / sizeof(uefi_handle);
    UEFI_LVVV(("count = %d", count));



    for (i64 i = 0; i < count; ++i)
    {
        uefi_handle                  handle = handles[i];
        UefiPciRootBridgeIoProtocol *pci;



        if (UEFI::handleProtocol(handle, protocol, (void **)&pci) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to handle(0x%p) protocol for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL", handle));

            continue;
        }

        UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL", handle, pci));



        // Validation
        {
            UEFI_LVVV(("pci->parentHandle  = 0x%p", pci->parentHandle));
            UEFI_LVVV(("pci->segmentNumber = %u",   pci->segmentNumber));

            UEFI_TEST_ASSERT(pci->parentHandle  != nullptr, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(pci->segmentNumber == 0,       NgosStatus::ASSERTION);
        }



        UefiAcpiAddressSpaceDescriptor *resources;

        if (pci->configuration(pci, &resources) == UefiStatus::SUCCESS)
        {
            UEFI_ASSERT_EXECUTION(initPciRootBridgeIoProtocol(pci, resources), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_LW(("Failed to get ACPI address space configuration for pci 0x%p", pci));

            UEFI_ASSERT_EXECUTION(initPcisInBusRange(pci, 0, PCI_MAXIMUM_BUS), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciRootBridgeIoProtocol(UefiPciRootBridgeIoProtocol *pci, UefiAcpiAddressSpaceDescriptor *resources)
{
    UEFI_LT((" | pci = 0x%p, resources = 0x%p", pci, resources));

    UEFI_ASSERT(pci,       "pci is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(resources, "resources is null", NgosStatus::ASSERTION);



    UefiAcpiAddressSpaceDescriptor *descriptor = resources;

    do
    {
        do
        {
            // Validation
            {
                UEFI_LVVV(("descriptor->descriptor               = %s", enumToFullString(descriptor->descriptor)));
                UEFI_LVVV(("descriptor->length                   = %u", descriptor->length));
                UEFI_LVVV(("descriptor->resourceType             = %s", enumToFullString(descriptor->resourceType)));
                UEFI_LVVV(("descriptor->genFlag                  = %u", descriptor->genFlag));
                UEFI_LVVV(("descriptor->specificFlag             = %u", descriptor->specificFlag));
                UEFI_LVVV(("descriptor->addressSpaceGranularity  = %u", descriptor->addressSpaceGranularity));
                UEFI_LVVV(("descriptor->addressRangeMinimum      = %u", descriptor->addressRangeMinimum));
                UEFI_LVVV(("descriptor->addressRangeMaximum      = %u", descriptor->addressRangeMaximum));
                UEFI_LVVV(("descriptor->addressTranslationOffset = %u", descriptor->addressTranslationOffset));
                UEFI_LVVV(("descriptor->addressLength            = %u", descriptor->addressLength));
            }



            if (descriptor->descriptor == UefiAcpiDescriptor::END_TAG)
            {
                break;
            }



            UEFI_LVVV(("+++++++++++++++++++++++++++++++++++++"));



            if (descriptor->resourceType == UefiAcpiResourceType::BUS)
            {
                break;
            }



            ++descriptor;
        } while(true);



        if (descriptor->descriptor == UefiAcpiDescriptor::END_TAG)
        {
            break;
        }

        UEFI_TEST_ASSERT(descriptor->resourceType == UefiAcpiResourceType::BUS, NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(initPcisInBusRange(pci, descriptor->addressRangeMinimum, descriptor->addressRangeMaximum), NgosStatus::ASSERTION);



        UEFI_LVVV(("+++++++++++++++++++++++++++++++++++++"));



        ++descriptor;
    } while(true);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPcisInBusRange(UefiPciRootBridgeIoProtocol *pci, i64 minimumBus, i64 maximumBus)
{
    UEFI_LT((" | pci = 0x%p, minimumBus = %d, maximumBus = %d", pci, minimumBus, maximumBus));

    UEFI_ASSERT(pci,                                  "pci is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(minimumBus >= 0 && minimumBus <= 255, "minimumBus is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(maximumBus >= 0 && maximumBus <= 255, "maximumBus is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(minimumBus <= maximumBus,             "minimumBus is invalid", NgosStatus::ASSERTION);



    for (i64 i = minimumBus; i <= maximumBus; ++i)
    {
        for (i64 j = 0; j <= PCI_MAXIMUM_DEVICE; ++j)
        {
            for (i64 k = 0; k <= PCI_MAXIMUM_FUNCTION; ++k)
            {
                u16 vendorId;
                u64 address = UEFI_PCI_ADDRESS(i, j, k, (u64)PciRegister::VENDOR_ID);

                if (pci->pci.read(pci, UefiPciRootBridgeIoProtocolWidth::UINT16, address, 1, &vendorId) == UefiStatus::SUCCESS)
                {
                    if (vendorId != 0xFFFF)
                    {
                        UEFI_LVV(("Successfully read PCI register Vendor ID(0x%04X) from protocol(0x%p) for PCI(%d/%d/%d)", vendorId, pci, i, j, k));



                        PciDeviceIndependentRegion pciHeader;

                        if (pci->pci.read(pci, UefiPciRootBridgeIoProtocolWidth::UINT32, address, sizeof(pciHeader) / sizeof(u32), &pciHeader) == UefiStatus::SUCCESS)
                        {
                            UEFI_LVV(("Successfully read PCI header from protocol(0x%p) for PCI(%d/%d/%d)", pci, i, j, k));

                            UEFI_LVVV(("pciHeader.vendorId                     = 0x%04X",                 pciHeader.vendorId));
                            UEFI_LVVV(("pciHeader.deviceId                     = 0x%04X",                 pciHeader.deviceId));
                            UEFI_LVVV(("pciHeader.command                      = 0x%04X",                 pciHeader.command));
                            UEFI_LVVV(("pciHeader.status                       = 0x%04X",                 pciHeader.status));
                            UEFI_LVVV(("pciHeader.revisionId                   = %u",                     pciHeader.revisionId));
                            UEFI_LVVV(("pciHeader.classCode                    = 0x%02X, 0x%02X, 0x%02X", pciHeader.classCode[2], pciHeader.classCode[1], pciHeader.classCode[0]));
                            UEFI_LVVV(("pciHeader.cacheLineSize                = %u",                     pciHeader.cacheLineSize));
                            UEFI_LVVV(("pciHeader.latencyTimer                 = %u",                     pciHeader.latencyTimer));
                            UEFI_LVVV(("pciHeader.headerType                   = %s",                     enumToFullString((PciHeaderType)pciHeader.headerType)));
                            UEFI_LVVV(("pciHeader.isMultiFunction              = %s",                     boolToString(pciHeader.isMultiFunction)));
                            UEFI_LVVV(("pciHeader.headerTypeAndIsMultiFunction = 0x%02X",                 pciHeader.headerTypeAndIsMultiFunction));
                            UEFI_LVVV(("pciHeader.builtInSelfTest              = %u",                     pciHeader.builtInSelfTest));



                            const char8 *baseClass = "N/A";
                            const char8 *subClass  = "N/A";
                            const char8 *interface = "N/A";

                            // Get other strings
                            {
                                char8 *classStr = strdup(enumToHumanString((PciBaseClass)pciHeader.classCode[2], pciHeader.classCode[1], pciHeader.classCode[0]));



                                // Get string for Base class
                                {
                                    baseClass = classStr;
                                }



                                // Get string for Subclass
                                {
                                    if (
                                        classStr[0] != 0
                                        &&
                                        classStr[1] != 0
                                        &&
                                        classStr[2] != 0
                                       )
                                    {
                                        classStr += 3; // We will check previous 3 chars for " - "

                                        while (classStr[0] != 0)
                                        {
                                            if (
                                                classStr[-1] == ' '
                                                &&
                                                classStr[-2] == '-'
                                                &&
                                                classStr[-3] == ' '
                                               )
                                            {
                                                classStr[-3] = 0;

                                                subClass = classStr;

                                                break;
                                            }

                                            ++classStr;
                                        }
                                    }
                                }



                                // Get string for Interface
                                {
                                    if (
                                        classStr[0] != 0
                                        &&
                                        classStr[1] != 0
                                        &&
                                        classStr[2] != 0
                                       )
                                    {
                                        classStr += 3; // We will check previous 3 chars for " - "

                                        while (classStr[0] != 0)
                                        {
                                            if (
                                                classStr[-1] == ' '
                                                &&
                                                classStr[-2] == '-'
                                                &&
                                                classStr[-3] == ' '
                                               )
                                            {
                                                classStr[-3] = 0;

                                                interface = classStr;

                                                break;
                                            }

                                            ++classStr;
                                        }
                                    }
                                }
                            }



                            // Add Device Manager entry
                            {
                                DeviceManagerEntry *deviceManagerEntry = new DeviceManagerEntry(DeviceManagerImage::PCI, mprintf("PCI(%d/%d/%d)", i, j, k));

                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base class",         baseClass,                                                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subclass",           subClass,                                                                                                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interface",          interface,                                                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment",            mprintf("%u",                     pci->segmentNumber),                                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bus",                mprintf("%u",                     i),                                                                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device",             mprintf("%u",                     j),                                                                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Function",           mprintf("%u",                     k),                                                                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor ID",          mprintf("0x%04X",                 pciHeader.vendorId),                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device ID",          mprintf("0x%04X",                 pciHeader.deviceId),                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command",            mprintf("0x%04X",                 pciHeader.command),                                                      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",             mprintf("0x%04X",                 pciHeader.status),                                                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Revision ID",        mprintf("%u",                     pciHeader.revisionId),                                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Class codes",        mprintf("0x%02X, 0x%02X, 0x%02X", pciHeader.classCode[2], pciHeader.classCode[1], pciHeader.classCode[0]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cache line size",    mprintf("%u",                     pciHeader.cacheLineSize),                                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Latency timer",      mprintf("%u",                     pciHeader.latencyTimer),                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header type",        strdup(enumToFullString((PciHeaderType)pciHeader.headerType)),                                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Built-In self test", mprintf("%u",                     pciHeader.builtInSelfTest),                                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);

                                UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
                            }



                            // If device is not multi-function then there is no need to check for remaining functions
                            if (
                                k == 0
                                &&
                                !pciHeader.isMultiFunction
                               )
                            {
                                break;
                            }
                        }
                        else
                        {
                            UEFI_LE(("Failed to read PCI header from protocol(0x%p) for PCI(%d/%d/%d)", pci, i, j, k));
                        }
                    }
                    else
                    {
                        // If we fail to get valid vendorId for function 0 then there is no need to check for remaining functions
                        if (k == 0)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    UEFI_LE(("Failed to read PCI register Vendor ID from protocol(0x%p) for PCI(%d/%d/%d)", pci, i, j, k));
                }
            }
        }
    }



    return NgosStatus::OK;
}
