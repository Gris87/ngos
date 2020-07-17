#include "devicemanagerpci.h"

#include <com/ngos/shared/common/pci/macros.h>
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



    Guid         protocol = UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GUID;
    u64          size     = 0;
    uefi_handle *handles  = nullptr;



    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, &protocol, 0, &size, handles) == UefiStatus::BUFFER_TOO_SMALL)
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



    // Validation
    {
        UEFI_LVVV(("pci->parentHandle  = 0x%p", pci->parentHandle));
        UEFI_LVVV(("pci->segmentNumber = %u",   pci->segmentNumber));

        UEFI_TEST_ASSERT(pci->parentHandle  != nullptr, NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(pci->segmentNumber == 0,       NgosStatus::ASSERTION);
    }



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



        ++descriptor;
    } while(true);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPcisInBusRange(UefiPciRootBridgeIoProtocol *pci, i64 minimumBus, i64 maximumBus)
{
    UEFI_LT((" | pci = 0x%p, minimumBus = %d, maximumBus = %d", pci, minimumBus, maximumBus));

    UEFI_ASSERT(pci, "pci is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(minimumBus);
    AVOID_UNUSED(maximumBus);



    return NgosStatus::OK;
}
