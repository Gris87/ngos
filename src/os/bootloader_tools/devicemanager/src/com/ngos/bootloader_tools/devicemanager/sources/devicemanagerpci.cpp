#include "devicemanagerpci.h"

#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/common/pci/database/generated/pcibaseclass.h>
#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>
#include <com/ngos/shared/common/pci/macros.h>
#include <com/ngos/shared/common/pci/pcicardbusdata.h>
#include <com/ngos/shared/common/pci/pcideviceindependentregion.h>
#include <com/ngos/shared/common/pci/pciregister.h>
#include <com/ngos/shared/common/string/utils.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, name, flagsVar, format, flagType, mode) \
    { \
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(name, mprintf(format, flagsVar.flags), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION); \
        \
        for (i64 _ = 0; _ < (i64)(sizeof(flagsVar) * 8); ++_) \
        { \
            u64 flag = (1ULL << _); \
            \
            if (flagsVar.flags & flag) \
            { \
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf(name ": %s", flagToString((flagType)flag)), "Yes", mode), NgosStatus::ASSERTION); \
            } \
        } \
    }



#define ADD_RECORDS_FOR_FLAGS_CYCLE(deviceManagerEntry, name, i, flagsVar, format, flagType, mode) \
    { \
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf(name, i), mprintf(format, flagsVar.flags), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION); \
        \
        for (i64 _ = 0; _ < (i64)(sizeof(flagsVar) * 8); ++_) \
        { \
            u64 flag = (1ULL << _); \
            \
            if (flagsVar.flags & flag) \
            { \
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf(name ": %s", i, flagToString((flagType)flag)), "Yes", mode), NgosStatus::ASSERTION); \
            } \
        } \
    }



ArrayList<DeviceManagerEntryPCI *> DeviceManagerPci::sEntries;



NgosStatus DeviceManagerPci::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initPciRootBridgeIoProtocols(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

const ArrayList<DeviceManagerEntryPCI *>& DeviceManagerPci::getEntries()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return sEntries;
}

NgosStatus DeviceManagerPci::initPciRootBridgeIoProtocols()
{
    UEFI_LT((""));



    Guid protocol = UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GUID;
    u64  size     = 0;



    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, &protocol, nullptr, &size, nullptr) == UefiStatus::BUFFER_TOO_SMALL)
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

    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, protocol, nullptr, &size, handles) == UefiStatus::SUCCESS)
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
                PciVendor vendorId;
                u64       address = UEFI_PCI_ADDRESS(i, j, k, (u64)PciRegister::VENDOR_ID);

                if (pci->pci.read(pci, UefiPciRootBridgeIoProtocolWidth::UINT16, address, 1, &vendorId) == UefiStatus::SUCCESS)
                {
                    if (vendorId != PciVendor::VENDOR_FFFF)
                    {
                        UEFI_LVV(("Successfully read PCI register Vendor ID(0x%04X) from protocol(0x%p) for PCI(%d/%d/%d)", vendorId, pci, i, j, k));



                        PciConfigurationSpace configurationSpace;

                        if (pci->pci.read(pci, UefiPciRootBridgeIoProtocolWidth::UINT32, address, sizeof(configurationSpace) / sizeof(u32), &configurationSpace) == UefiStatus::SUCCESS)
                        {
                            UEFI_LVV(("Successfully read PCI configuration space from protocol(0x%p) for PCI(%d/%d/%d)", pci, i, j, k));



                            DeviceManagerEntryPCI *deviceManagerEntry;

                            // Add Device Manager entry
                            {
                                deviceManagerEntry = new DeviceManagerEntryPCI(nullptr, DeviceManagerImage::PCI, mprintf("PCI(%d/%d/%d)", i, j, k));



                                // Segment / Bus / Device / Function
                                {
                                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment",  mprintf("%u", pci->segmentNumber), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bus",      mprintf("%u", i),                  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device",   mprintf("%u", j),                  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Function", mprintf("%u", k),                  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                                }



                                UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
                            }



                            UEFI_ASSERT_EXECUTION(initPciWithConfigurationSpace(configurationSpace, deviceManagerEntry, pci, i, j, k), NgosStatus::ASSERTION);



                            // If device is not multi-function then there is no need to check for remaining functions
                            if (
                                k == 0
                                &&
                                !configurationSpace.header.headerType.isMultiFunction
                               )
                            {
                                break;
                            }
                        }
                        else
                        {
                            UEFI_LE(("Failed to read PCI configuration space from protocol(0x%p) for PCI(%d/%d/%d)", pci, i, j, k));
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

NgosStatus DeviceManagerPci::initPciWithConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
{
    UEFI_LT((" | configurationSpace = ..., deviceManagerEntry = 0x%p, pci = 0x%p, bus = %d, device = %d, function = %d", deviceManagerEntry, pci, bus, device, function));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(pci                != nullptr, "pci is null",                NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("configurationSpace.header.vendorId                       = 0x%04X (%s)",            configurationSpace.header.vendorId, enumToHumanString(configurationSpace.header.vendorId)));
        UEFI_LVVV(("configurationSpace.header.deviceId                       = 0x%04X (%s)",            configurationSpace.header.deviceId, enumToHumanString(configurationSpace.header.vendorId, configurationSpace.header.deviceId)));
        UEFI_LVVV(("configurationSpace.header.command                        = %s",                     flagsToFullString(configurationSpace.header.command)));
        UEFI_LVVV(("configurationSpace.header.status.interruptStatus         = %s",                     boolToString(configurationSpace.header.status.interruptStatus)));
        UEFI_LVVV(("configurationSpace.header.status.capabilitiesList        = %s",                     boolToString(configurationSpace.header.status.capabilitiesList)));
        UEFI_LVVV(("configurationSpace.header.status.support64MHz            = %s",                     boolToString(configurationSpace.header.status.support64MHz)));
        UEFI_LVVV(("configurationSpace.header.status.fastBackToBackCapable   = %s",                     boolToString(configurationSpace.header.status.fastBackToBackCapable)));
        UEFI_LVVV(("configurationSpace.header.status.masterDataParityError   = %s",                     boolToString(configurationSpace.header.status.masterDataParityError)));
        UEFI_LVVV(("configurationSpace.header.status.deviceSelectTiming      = %s",                     enumToFullString((PciDeviceSelectTiming)configurationSpace.header.status.deviceSelectTiming)));
        UEFI_LVVV(("configurationSpace.header.status.signaledTargetAbort     = %s",                     boolToString(configurationSpace.header.status.signaledTargetAbort)));
        UEFI_LVVV(("configurationSpace.header.status.receivedTargetAbort     = %s",                     boolToString(configurationSpace.header.status.receivedTargetAbort)));
        UEFI_LVVV(("configurationSpace.header.status.receivedMasterAbort     = %s",                     boolToString(configurationSpace.header.status.receivedMasterAbort)));
        UEFI_LVVV(("configurationSpace.header.status.signaledSystemError     = %s",                     boolToString(configurationSpace.header.status.signaledSystemError)));
        UEFI_LVVV(("configurationSpace.header.status.detectedParityError     = %s",                     boolToString(configurationSpace.header.status.detectedParityError)));
        UEFI_LVVV(("configurationSpace.header.status.value16                 = 0x%04X",                 configurationSpace.header.status.value16));
        UEFI_LVVV(("configurationSpace.header.revisionId                     = %u",                     configurationSpace.header.revisionId));
        UEFI_LVVV(("configurationSpace.header.classCode                      = 0x%02X, 0x%02X, 0x%02X", configurationSpace.header.classCode[2], configurationSpace.header.classCode[1], configurationSpace.header.classCode[0]));
        UEFI_LVVV(("configurationSpace.header.cacheLineSize                  = %u",                     configurationSpace.header.cacheLineSize));
        UEFI_LVVV(("configurationSpace.header.latencyTimer                   = %u",                     configurationSpace.header.latencyTimer));
        UEFI_LVVV(("configurationSpace.header.headerType.type                = %s",                     enumToFullString((PciHeaderType)configurationSpace.header.headerType.type)));
        UEFI_LVVV(("configurationSpace.header.headerType.isMultiFunction     = %s",                     boolToString(configurationSpace.header.headerType.isMultiFunction)));
        UEFI_LVVV(("configurationSpace.header.headerType.value8              = 0x%02X",                 configurationSpace.header.headerType.value8));
        UEFI_LVVV(("configurationSpace.header.builtInSelfTest.completionCode = %u",                     configurationSpace.header.builtInSelfTest.completionCode));
        UEFI_LVVV(("configurationSpace.header.builtInSelfTest.startBist      = %u",                     configurationSpace.header.builtInSelfTest.startBist));
        UEFI_LVVV(("configurationSpace.header.builtInSelfTest.capable        = %u",                     configurationSpace.header.builtInSelfTest.capable));
        UEFI_LVVV(("configurationSpace.header.builtInSelfTest.value8         = 0x%02X",                 configurationSpace.header.builtInSelfTest.value8));
    }



    const char8 *baseClass = "N/A";
    const char8 *subClass  = "N/A";
    const char8 *interface = "N/A";

    // Get other strings
    {
        char8 *classStr = strdup(enumToHumanString((PciBaseClass)configurationSpace.header.classCode[2], configurationSpace.header.classCode[1], configurationSpace.header.classCode[0]));



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



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        // Classes, interface, vendor and device name
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base class",  baseClass,                                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subclass",    subClass,                                                                                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interface",   interface,                                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor",      enumToHumanString(configurationSpace.header.vendorId),                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device name", enumToHumanString(configurationSpace.header.vendorId, configurationSpace.header.deviceId), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor ID",   mprintf("0x%04X", configurationSpace.header.vendorId),                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device ID",   mprintf("0x%04X", configurationSpace.header.deviceId),                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Command", configurationSpace.header.command, "0x%04X", PciCommandFlag, DeviceManagerMode::EXPERT);



        // Status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                            mprintf("0x%04X", configurationSpace.header.status.value16),                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Interrupt status",          configurationSpace.header.status.interruptStatus       ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Capabilities list",         configurationSpace.header.status.capabilitiesList      ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: 66 MHz capable",            configurationSpace.header.status.support64MHz          ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Fast back-to-back capable", configurationSpace.header.status.fastBackToBackCapable ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Master data parity error",  configurationSpace.header.status.masterDataParityError ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Device select timing",      strdup(enumToFullString((PciDeviceSelectTiming)configurationSpace.header.status.deviceSelectTiming)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Signaled target abort",     configurationSpace.header.status.signaledTargetAbort   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Received target abort",     configurationSpace.header.status.receivedTargetAbort   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Received master abort",     configurationSpace.header.status.receivedMasterAbort   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Signaled system error",     configurationSpace.header.status.signaledSystemError   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Detected parity error",     configurationSpace.header.status.detectedParityError   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Revision ID",     mprintf("%u",                     configurationSpace.header.revisionId),                                                                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Class codes",     mprintf("0x%02X, 0x%02X, 0x%02X", configurationSpace.header.classCode[2], configurationSpace.header.classCode[1], configurationSpace.header.classCode[0]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cache line size", mprintf("%u",                     configurationSpace.header.cacheLineSize),                                                                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Latency timer",   mprintf("%u",                     configurationSpace.header.latencyTimer),                                                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header type",     strdup(enumToFullString((PciHeaderType)configurationSpace.header.headerType.type)),                                                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Built-in self test
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Built-in self test",         mprintf("0x%02X", configurationSpace.header.builtInSelfTest.value8),     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Built-in self test capable", configurationSpace.header.builtInSelfTest.capable ? "Yes" : "No",        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Built-in self test result",  mprintf("%u", configurationSpace.header.builtInSelfTest.completionCode), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    switch ((PciHeaderType)configurationSpace.header.headerType.type)
    {
        case PciHeaderType::DEVICE:            UEFI_ASSERT_EXECUTION(initPciWithDeviceConfigurationSpace(configurationSpace, deviceManagerEntry, pci, bus, device, function),  NgosStatus::ASSERTION); break;
        case PciHeaderType::PCI_TO_PCI_BRIDGE: UEFI_ASSERT_EXECUTION(initPciWithBridgeConfigurationSpace(configurationSpace, deviceManagerEntry, pci, bus, device, function),  NgosStatus::ASSERTION); break;
        case PciHeaderType::CARDBUS_BRIDGE:    UEFI_ASSERT_EXECUTION(initPciWithCardBusConfigurationSpace(configurationSpace, deviceManagerEntry, pci, bus, device, function), NgosStatus::ASSERTION); break;

        default:
        {
            UEFI_LF(("Unknown PCI header type %s", enumToFullString((PciHeaderType)configurationSpace.header.headerType.type)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithDeviceConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
{
    UEFI_LT((" | configurationSpace = ..., deviceManagerEntry = 0x%p, pci = 0x%p, bus = %d, device = %d, function = %d", deviceManagerEntry, pci, bus, device, function));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(pci                != nullptr, "pci is null",                NgosStatus::ASSERTION);



    const char8 *subsystemVendorID = enumToHumanString(configurationSpace.device.subsystemVendorID);
    const char8 *subsystemID       = enumToHumanString(configurationSpace.header.vendorId, configurationSpace.header.deviceId, configurationSpace.device.subsystemVendorID, configurationSpace.device.subsystemID);



    // Validation
    {
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[0]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[0]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[1]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[1]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[2]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[2]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[3]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[3]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[4]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[4]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[5]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[5]));
        UEFI_LVVV(("configurationSpace.device.cardInformationStructurePointer = 0x%08X",      configurationSpace.device.cardInformationStructurePointer));
        UEFI_LVVV(("configurationSpace.device.subsystemVendorID               = 0x%04X (%s)", configurationSpace.device.subsystemVendorID, subsystemVendorID));
        UEFI_LVVV(("configurationSpace.device.subsystemID                     = 0x%04X (%s)", configurationSpace.device.subsystemID, subsystemID));
        UEFI_LVVV(("configurationSpace.device.expansionRomBaseAddress         = 0x%08X",      configurationSpace.device.expansionRomBaseAddress));
        UEFI_LVVV(("configurationSpace.device.capabilitiesPointer             = 0x%02X",      configurationSpace.device.capabilitiesPointer));
        UEFI_LVVV(("configurationSpace.device.interruptLine                   = %u",          configurationSpace.device.interruptLine));
        UEFI_LVVV(("configurationSpace.device.interruptPin                    = %u",          configurationSpace.device.interruptPin));
        UEFI_LVVV(("configurationSpace.device.minGrant                        = %u",          configurationSpace.device.minGrant));
        UEFI_LVVV(("configurationSpace.device.maxLatency                      = %u",          configurationSpace.device.maxLatency));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        // Base address register
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #0", mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[0]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #1", mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[1]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #2", mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[2]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #3", mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[3]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #4", mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[4]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #5", mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[5]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Card information structure pointer", mprintf("0x%08X", configurationSpace.device.cardInformationStructurePointer), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem vendor ID",                subsystemVendorID,                                                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem ID",                       subsystemID,                                                                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Expansion ROM base address",         mprintf("0x%08X", configurationSpace.device.expansionRomBaseAddress),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities pointer",               mprintf("0x%02X", configurationSpace.device.capabilitiesPointer),             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt line",                     mprintf("%u",     configurationSpace.device.interruptLine),                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt pin",                      mprintf("%u",     configurationSpace.device.interruptPin),                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum grant",                      mprintf("%u",     configurationSpace.device.minGrant),                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum latency",                    mprintf("%u",     configurationSpace.device.maxLatency),                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    UEFI_ASSERT_EXECUTION(initPciWithCapabilitiesPointer(configurationSpace, configurationSpace.device.capabilitiesPointer, deviceManagerEntry, PciHeaderType::DEVICE, pci, bus, device, function), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithBridgeConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
{
    UEFI_LT((" | configurationSpace = ..., deviceManagerEntry = 0x%p, pci = 0x%p, bus = %d, device = %d, function = %d", deviceManagerEntry, pci, bus, device, function));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(pci                != nullptr, "pci is null",                NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("configurationSpace.bridge.baseAddressRegisters[0]               = 0x%08X", configurationSpace.bridge.baseAddressRegisters[0]));
        UEFI_LVVV(("configurationSpace.bridge.baseAddressRegisters[1]               = 0x%08X", configurationSpace.bridge.baseAddressRegisters[1]));
        UEFI_LVVV(("configurationSpace.bridge.primaryBus                            = %u",     configurationSpace.bridge.primaryBus));
        UEFI_LVVV(("configurationSpace.bridge.secondaryBus                          = %u",     configurationSpace.bridge.secondaryBus));
        UEFI_LVVV(("configurationSpace.bridge.subordinateBus                        = %u",     configurationSpace.bridge.subordinateBus));
        UEFI_LVVV(("configurationSpace.bridge.secondaryLatencyTimer                 = %u",     configurationSpace.bridge.secondaryLatencyTimer));
        UEFI_LVVV(("configurationSpace.bridge.ioBase                                = 0x%02X", configurationSpace.bridge.ioBase));
        UEFI_LVVV(("configurationSpace.bridge.ioLimit                               = 0x%02X", configurationSpace.bridge.ioLimit));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.interruptStatus       = %s",     boolToString(configurationSpace.bridge.secondaryStatus.interruptStatus)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.capabilitiesList      = %s",     boolToString(configurationSpace.bridge.secondaryStatus.capabilitiesList)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.support64MHz          = %s",     boolToString(configurationSpace.bridge.secondaryStatus.support64MHz)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.fastBackToBackCapable = %s",     boolToString(configurationSpace.bridge.secondaryStatus.fastBackToBackCapable)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.masterDataParityError = %s",     boolToString(configurationSpace.bridge.secondaryStatus.masterDataParityError)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.deviceSelectTiming    = %s",     enumToFullString((PciDeviceSelectTiming)configurationSpace.bridge.secondaryStatus.deviceSelectTiming)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.signaledTargetAbort   = %s",     boolToString(configurationSpace.bridge.secondaryStatus.signaledTargetAbort)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.receivedTargetAbort   = %s",     boolToString(configurationSpace.bridge.secondaryStatus.receivedTargetAbort)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.receivedMasterAbort   = %s",     boolToString(configurationSpace.bridge.secondaryStatus.receivedMasterAbort)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.signaledSystemError   = %s",     boolToString(configurationSpace.bridge.secondaryStatus.signaledSystemError)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.detectedParityError   = %s",     boolToString(configurationSpace.bridge.secondaryStatus.detectedParityError)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.value16               = 0x%04X", configurationSpace.bridge.secondaryStatus.value16));
        UEFI_LVVV(("configurationSpace.bridge.memoryBase                            = 0x%04X", configurationSpace.bridge.memoryBase));
        UEFI_LVVV(("configurationSpace.bridge.memoryLimit                           = 0x%04X", configurationSpace.bridge.memoryLimit));
        UEFI_LVVV(("configurationSpace.bridge.prefetchableMemoryBase                = 0x%04X", configurationSpace.bridge.prefetchableMemoryBase));
        UEFI_LVVV(("configurationSpace.bridge.prefetchableMemoryLimit               = 0x%04X", configurationSpace.bridge.prefetchableMemoryLimit));
        UEFI_LVVV(("configurationSpace.bridge.prefetchableBaseUpper32               = 0x%08X", configurationSpace.bridge.prefetchableBaseUpper32));
        UEFI_LVVV(("configurationSpace.bridge.prefetchableLimitUpper32              = 0x%08X", configurationSpace.bridge.prefetchableLimitUpper32));
        UEFI_LVVV(("configurationSpace.bridge.ioBaseUpper16                         = 0x%04X", configurationSpace.bridge.ioBaseUpper16));
        UEFI_LVVV(("configurationSpace.bridge.ioLimitUpper16                        = 0x%04X", configurationSpace.bridge.ioLimitUpper16));
        UEFI_LVVV(("configurationSpace.bridge.capabilitiesPointer                   = 0x%02X", configurationSpace.bridge.capabilitiesPointer));
        UEFI_LVVV(("configurationSpace.bridge.expansionRomBaseAddress               = 0x%08X", configurationSpace.bridge.expansionRomBaseAddress));
        UEFI_LVVV(("configurationSpace.bridge.interruptLine                         = %u",     configurationSpace.bridge.interruptLine));
        UEFI_LVVV(("configurationSpace.bridge.interruptPin                          = %u",     configurationSpace.bridge.interruptPin));
        UEFI_LVVV(("configurationSpace.bridge.bridgeControl                         = %s",     flagsToFullString(configurationSpace.bridge.bridgeControl)));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        // Base address register
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #0", mprintf("0x%08X", configurationSpace.bridge.baseAddressRegisters[0]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #1", mprintf("0x%08X", configurationSpace.bridge.baseAddressRegisters[1]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Primary bus",             mprintf("%u",     configurationSpace.bridge.primaryBus),            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary bus",           mprintf("%u",     configurationSpace.bridge.secondaryBus),          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subordinate bus",         mprintf("%u",     configurationSpace.bridge.subordinateBus),        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary latency timer", mprintf("%u",     configurationSpace.bridge.secondaryLatencyTimer), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO base",                 mprintf("0x%02X", configurationSpace.bridge.ioBase),                DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO limit",                mprintf("0x%02X", configurationSpace.bridge.ioLimit),               DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }



        // Secondary status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status",                            mprintf("0x%04X", configurationSpace.bridge.secondaryStatus.value16),                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Interrupt status",          configurationSpace.bridge.secondaryStatus.interruptStatus       ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Capabilities list",         configurationSpace.bridge.secondaryStatus.capabilitiesList      ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: 66 MHz capable",            configurationSpace.bridge.secondaryStatus.support64MHz          ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Fast back-to-back capable", configurationSpace.bridge.secondaryStatus.fastBackToBackCapable ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Master data parity error",  configurationSpace.bridge.secondaryStatus.masterDataParityError ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Device select timing",      strdup(enumToFullString((PciDeviceSelectTiming)configurationSpace.bridge.secondaryStatus.deviceSelectTiming)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Signaled target abort",     configurationSpace.bridge.secondaryStatus.signaledTargetAbort   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Received target abort",     configurationSpace.bridge.secondaryStatus.receivedTargetAbort   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Received master abort",     configurationSpace.bridge.secondaryStatus.receivedMasterAbort   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Signaled system error",     configurationSpace.bridge.secondaryStatus.signaledSystemError   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Detected parity error",     configurationSpace.bridge.secondaryStatus.detectedParityError   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory base",                 mprintf("0x%04X", configurationSpace.bridge.memoryBase),               DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory limit",                mprintf("0x%04X", configurationSpace.bridge.memoryLimit),              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Prefetchable memory base",    mprintf("0x%04X", configurationSpace.bridge.prefetchableMemoryBase),   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Prefetchable memory limit",   mprintf("0x%04X", configurationSpace.bridge.prefetchableMemoryLimit),  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Prefetchable base upper 32",  mprintf("0x%08X", configurationSpace.bridge.prefetchableBaseUpper32),  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Prefetchable limit upper 32", mprintf("0x%08X", configurationSpace.bridge.prefetchableLimitUpper32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO base upper 16",            mprintf("0x%04X", configurationSpace.bridge.ioBaseUpper16),            DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO limit upper 16",           mprintf("0x%04X", configurationSpace.bridge.ioLimitUpper16),           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities pointer",        mprintf("0x%02X", configurationSpace.bridge.capabilitiesPointer),      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Expansion ROM base address",  mprintf("0x%08X", configurationSpace.bridge.expansionRomBaseAddress),  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt line",              mprintf("%u",     configurationSpace.bridge.interruptLine),            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt pin",               mprintf("%u",     configurationSpace.bridge.interruptPin),             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Bridge control", configurationSpace.bridge.bridgeControl, "0x%04X", PciBridgeControlFlag, DeviceManagerMode::EXPERT);
        // Ignore CppAlignmentVerifier [END]
    }



    UEFI_ASSERT_EXECUTION(initPciWithCapabilitiesPointer(configurationSpace, configurationSpace.bridge.capabilitiesPointer, deviceManagerEntry, PciHeaderType::PCI_TO_PCI_BRIDGE, pci, bus, device, function), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithCardBusConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
{
    UEFI_LT((" | configurationSpace = ..., deviceManagerEntry = 0x%p, pci = 0x%p, bus = %d, device = %d, function = %d", deviceManagerEntry, pci, bus, device, function));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(pci                != nullptr, "pci is null",                NgosStatus::ASSERTION);



    PciCardBusData *cardBusData = (PciCardBusData *)&configurationSpace.data;



    const char8 *subsystemVendorID = enumToHumanString(cardBusData->subsystemVendorID);
    const char8 *subsystemID       = enumToHumanString(configurationSpace.header.vendorId, configurationSpace.header.deviceId, cardBusData->subsystemVendorID, cardBusData->subsystemID);



    // Validation
    {
        UEFI_LVVV(("configurationSpace.cardBus.cardBusSocket                         = 0x%08X",      configurationSpace.cardBus.cardBusSocket));
        UEFI_LVVV(("configurationSpace.cardBus.capabilitiesPointer                   = 0x%02X",      configurationSpace.cardBus.capabilitiesPointer));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.interruptStatus       = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.interruptStatus)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.capabilitiesList      = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.capabilitiesList)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.support64MHz          = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.support64MHz)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.fastBackToBackCapable = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.fastBackToBackCapable)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.masterDataParityError = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.masterDataParityError)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.deviceSelectTiming    = %s",          enumToFullString((PciDeviceSelectTiming)configurationSpace.cardBus.secondaryStatus.deviceSelectTiming)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.signaledTargetAbort   = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.signaledTargetAbort)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.receivedTargetAbort   = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.receivedTargetAbort)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.receivedMasterAbort   = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.receivedMasterAbort)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.signaledSystemError   = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.signaledSystemError)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.detectedParityError   = %s",          boolToString(configurationSpace.cardBus.secondaryStatus.detectedParityError)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.value16               = 0x%04X",      configurationSpace.cardBus.secondaryStatus.value16));
        UEFI_LVVV(("configurationSpace.cardBus.pciBusNumber                          = %u",          configurationSpace.cardBus.pciBusNumber));
        UEFI_LVVV(("configurationSpace.cardBus.cardBusBusNumber                      = %u",          configurationSpace.cardBus.cardBusBusNumber));
        UEFI_LVVV(("configurationSpace.cardBus.subordinateBusNumber                  = %u",          configurationSpace.cardBus.subordinateBusNumber));
        UEFI_LVVV(("configurationSpace.cardBus.cardBusLatencyTimer                   = %u",          configurationSpace.cardBus.cardBusLatencyTimer));
        UEFI_LVVV(("configurationSpace.cardBus.memoryBase0                           = 0x%08X",      configurationSpace.cardBus.memoryBase0));
        UEFI_LVVV(("configurationSpace.cardBus.memoryLimit0                          = 0x%08X",      configurationSpace.cardBus.memoryLimit0));
        UEFI_LVVV(("configurationSpace.cardBus.memoryBase1                           = 0x%08X",      configurationSpace.cardBus.memoryBase1));
        UEFI_LVVV(("configurationSpace.cardBus.memoryLimit1                          = 0x%08X",      configurationSpace.cardBus.memoryLimit1));
        UEFI_LVVV(("configurationSpace.cardBus.ioBase0                               = 0x%08X",      configurationSpace.cardBus.ioBase0));
        UEFI_LVVV(("configurationSpace.cardBus.ioLimit0                              = 0x%08X",      configurationSpace.cardBus.ioLimit0));
        UEFI_LVVV(("configurationSpace.cardBus.ioBase1                               = 0x%08X",      configurationSpace.cardBus.ioBase1));
        UEFI_LVVV(("configurationSpace.cardBus.ioLimit1                              = 0x%08X",      configurationSpace.cardBus.ioLimit1));
        UEFI_LVVV(("configurationSpace.cardBus.interruptLine                         = %u",          configurationSpace.cardBus.interruptLine));
        UEFI_LVVV(("configurationSpace.cardBus.interruptPin                          = %u",          configurationSpace.cardBus.interruptPin));
        UEFI_LVVV(("configurationSpace.cardBus.bridgeControl                         = %s",          flagsToFullString(configurationSpace.cardBus.bridgeControl)));
        UEFI_LVVV(("cardBusData->subsystemVendorID                                   = 0x%04X (%s)", cardBusData->subsystemVendorID, subsystemVendorID));
        UEFI_LVVV(("cardBusData->subsystemID                                         = 0x%04X (%s)", cardBusData->subsystemID, subsystemID));
        UEFI_LVVV(("cardBusData->legacyBase                                          = 0x%08X",      cardBusData->legacyBase));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Card bus socket",      mprintf("0x%08X", configurationSpace.cardBus.cardBusSocket),       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities pointer", mprintf("0x%02X", configurationSpace.cardBus.capabilitiesPointer), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }



        // Secondary status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status",                            mprintf("0x%04X", configurationSpace.cardBus.secondaryStatus.value16),                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Interrupt status",          configurationSpace.cardBus.secondaryStatus.interruptStatus       ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Capabilities list",         configurationSpace.cardBus.secondaryStatus.capabilitiesList      ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: 66 MHz capable",            configurationSpace.cardBus.secondaryStatus.support64MHz          ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Fast back-to-back capable", configurationSpace.cardBus.secondaryStatus.fastBackToBackCapable ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Master data parity error",  configurationSpace.cardBus.secondaryStatus.masterDataParityError ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Device select timing",      strdup(enumToFullString((PciDeviceSelectTiming)configurationSpace.cardBus.secondaryStatus.deviceSelectTiming)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Signaled target abort",     configurationSpace.cardBus.secondaryStatus.signaledTargetAbort   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Received target abort",     configurationSpace.cardBus.secondaryStatus.receivedTargetAbort   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Received master abort",     configurationSpace.cardBus.secondaryStatus.receivedMasterAbort   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Signaled system error",     configurationSpace.cardBus.secondaryStatus.signaledSystemError   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Detected parity error",     configurationSpace.cardBus.secondaryStatus.detectedParityError   ? "Yes" : "No",                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI bus number",         mprintf("%u",     configurationSpace.cardBus.pciBusNumber),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Card bus number",        mprintf("%u",     configurationSpace.cardBus.cardBusBusNumber),     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subordinate bus number", mprintf("%u",     configurationSpace.cardBus.subordinateBusNumber), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Card bus latency timer", mprintf("%u",     configurationSpace.cardBus.cardBusLatencyTimer),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory base0",           mprintf("0x%08X", configurationSpace.cardBus.memoryBase0),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory limit0",          mprintf("0x%08X", configurationSpace.cardBus.memoryLimit0),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory base1",           mprintf("0x%08X", configurationSpace.cardBus.memoryBase1),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory limit1",          mprintf("0x%08X", configurationSpace.cardBus.memoryLimit1),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO base0",               mprintf("0x%08X", configurationSpace.cardBus.ioBase0),              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO limit0",              mprintf("0x%08X", configurationSpace.cardBus.ioLimit0),             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO base1",               mprintf("0x%08X", configurationSpace.cardBus.ioBase1),              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO limit1",              mprintf("0x%08X", configurationSpace.cardBus.ioLimit1),             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt line",         mprintf("%u",     configurationSpace.cardBus.interruptLine),        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt pin",          mprintf("%u",     configurationSpace.cardBus.interruptPin),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Bridge control", configurationSpace.cardBus.bridgeControl, "0x%04X", PciCardBusControlFlag, DeviceManagerMode::EXPERT);



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem vendor ID", subsystemVendorID,                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem ID",        subsystemID,                                DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Legacy base",         mprintf("0x%08X", cardBusData->legacyBase), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    UEFI_ASSERT_EXECUTION(initPciWithCapabilitiesPointer(configurationSpace, configurationSpace.cardBus.capabilitiesPointer, deviceManagerEntry, PciHeaderType::CARDBUS_BRIDGE, pci, bus, device, function), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithCapabilitiesPointer(const PciConfigurationSpace &configurationSpace, u8 capabilityPointer, DeviceManagerEntryPCI *deviceManagerEntry, PciHeaderType headerType, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
{
    UEFI_LT((" | configurationSpace = ..., capabilityPointer = 0x%02X, deviceManagerEntry = 0x%p, headerType = %u, pci = 0x%p, bus = %d, device = %d, function = %d", capabilityPointer, deviceManagerEntry, headerType, pci, bus, device, function));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(pci                != nullptr, "pci is null",                NgosStatus::ASSERTION);



    if (
        !configurationSpace.header.status.capabilitiesList
        ||
        capabilityPointer == 0
       )
    {
        return NgosStatus::OK;
    }



    while (
           capabilityPointer >= OFFSET_OF(PciConfigurationSpace, data)
           &&
           IS_ALIGNED(capabilityPointer, 4)
          )
    {
        PciCapabilityHeader *capability = (PciCapabilityHeader *)((u64)&configurationSpace + capabilityPointer);



        UEFI_ASSERT_EXECUTION(initPciWithCapability(capability, deviceManagerEntry, headerType, pci, bus, device, function), NgosStatus::ASSERTION);



        if (capability->nextCapabilityPointer == capabilityPointer)
        {
            break;
        }

        capabilityPointer = capability->nextCapabilityPointer;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithCapability(PciCapabilityHeader *capability, DeviceManagerEntryPCI *deviceManagerEntry, PciHeaderType headerType, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p, headerType = %u, pci = 0x%p, bus = %d, device = %d, function = %d", capability, deviceManagerEntry, headerType, pci, bus, device, function));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(pci                != nullptr, "pci is null",                NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->capabilityId          = %s",     enumToFullString(capability->capabilityId)));
        UEFI_LVVV(("capability->nextCapabilityPointer = 0x%02X", capability->nextCapabilityPointer));
    }



    // Fill Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability", strdup(enumToFullString(capability->capabilityId)), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
    }



    switch (capability->capabilityId)
    {
        case PciCapabilityType::POWER_MANAGEMENT_INTERFACE:    UEFI_ASSERT_EXECUTION(initPciPowerManagementInterfaceCapability((PciPowerManagementInterfaceCapability *)capability,                   deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::ACCELERATED_GRAPHICS_PORT:     UEFI_ASSERT_EXECUTION(initPciAcceleratedGraphicsPortCapability((PciAcceleratedGraphicsPortCapability *)capability,                     deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::VITAL_PRODUCT_DATA:            UEFI_ASSERT_EXECUTION(initPciVitalProductDataCapability((PciVitalProductDataCapability *)capability,                                   deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::SLOT_IDENTIFICATION:           UEFI_ASSERT_EXECUTION(initPciSlotNumberingCapability((PciSlotNumberingCapability *)capability,                                         deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::MESSAGE_SIGNALED_INTERRUPTS:   UEFI_ASSERT_EXECUTION(initPciMessageSignaledInterruptsCapability((PciMessageSignaledInterruptsCapability *)capability,                 deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::HOT_SWAP:                      UEFI_ASSERT_EXECUTION(initPciHotSwapCapability((PciHotSwapCapability *)capability,                                                     deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::PCI_X:                         UEFI_ASSERT_EXECUTION(initPciExtendedCapability(capability,                                                                            deviceManagerEntry, headerType),                 NgosStatus::ASSERTION); break;
        case PciCapabilityType::HYPER_TRANSPORT:               UEFI_ASSERT_EXECUTION(initPciHyperTransportCapability((PciHyperTransportCapability *)capability,                                       deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::VENDOR:                        UEFI_ASSERT_EXECUTION(initPciVendorCapability((PciVendorCapability *)capability,                                                       deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::DEBUG_PORT:                    UEFI_ASSERT_EXECUTION(initPciDebugPortCapability((PciDebugPortCapability *)capability,                                                 deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::CENTRAL_RESOURCE_CONTROL:      UEFI_ASSERT_EXECUTION(initPciCentralResourceControlCapability((PciCentralResourceControlCapability *)capability,                       deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::HOT_PLUG:                      UEFI_ASSERT_EXECUTION(initPciHotPlugCapability((PciHotPlugCapability *)capability,                                                     deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::ACCELERATED_GRAPHICS_PORT_8X:  UEFI_ASSERT_EXECUTION(initPciAcceleratedGraphicsPort8xCapability((PciAcceleratedGraphicsPort8xCapability *)capability,                 deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::SECURE_DEVICE:                 UEFI_ASSERT_EXECUTION(initPciSecureDeviceCapability((PciSecureDeviceCapability *)capability,                                           deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::PCI_EXPRESS:                   UEFI_ASSERT_EXECUTION(initPciExpressCapability((PciExpressCapability *)capability,                                                     deviceManagerEntry, pci, bus, device, function), NgosStatus::ASSERTION); break;
        case PciCapabilityType::MESSAGE_SIGNALED_INTERRUPTS_X: UEFI_ASSERT_EXECUTION(initPciMessageSignaledInterruptsExtendedCapability((PciMessageSignaledInterruptsExtendedCapability *)capability, deviceManagerEntry),                             NgosStatus::ASSERTION); break;

        default:
        {
            UEFI_LF(("Unknown PCI capability %s", enumToFullString(capability->capabilityId)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciPowerManagementInterfaceCapability(PciPowerManagementInterfaceCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    PciPowerManagementSupportPmeFlags supportPme(capability->capabilities.supportPme);



    // Validation
    {
        UEFI_LVVV(("capability->capabilities.version                      = %u",     capability->capabilities.version));
        UEFI_LVVV(("capability->capabilities.pmeClock                     = %u",     capability->capabilities.pmeClock));
        UEFI_LVVV(("capability->capabilities.deviceSpecificInitialization = %u",     capability->capabilities.deviceSpecificInitialization));
        UEFI_LVVV(("capability->capabilities.auxCurrent                   = %s",     enumToFullString((PciPowerManagementAuxCurrent)capability->capabilities.auxCurrent)));
        UEFI_LVVV(("capability->capabilities.supportD1                    = %u",     capability->capabilities.supportD1));
        UEFI_LVVV(("capability->capabilities.supportD2                    = %u",     capability->capabilities.supportD2));
        UEFI_LVVV(("capability->capabilities.supportPme                   = %s",     flagsToFullString(supportPme)));
        UEFI_LVVV(("capability->capabilities.value16                      = 0x%04X", capability->capabilities.value16));
        UEFI_LVVV(("capability->controlStatus.powerState                  = %s",     enumToFullString((PciPowerManagementPowerState)capability->controlStatus.powerState)));
        UEFI_LVVV(("capability->controlStatus.noSoftReset                 = %u",     capability->controlStatus.noSoftReset));
        UEFI_LVVV(("capability->controlStatus.enablePme                   = %u",     capability->controlStatus.enablePme));
        UEFI_LVVV(("capability->controlStatus.dataSelect                  = %s",     enumToFullString((PciPowerManagementDataSelect)capability->controlStatus.dataSelect)));
        UEFI_LVVV(("capability->controlStatus.dataScale                   = %s",     enumToFullString((PciPowerManagementDataScale)capability->controlStatus.dataScale)));
        UEFI_LVVV(("capability->controlStatus.pmeStatus                   = %u",     capability->controlStatus.pmeStatus));
        UEFI_LVVV(("capability->controlStatus.value16                     = 0x%04X", capability->controlStatus.value16));
        UEFI_LVVV(("capability->bridgeExtention.b2B3ForD3Hot              = %u",     capability->bridgeExtention.b2B3ForD3Hot));
        UEFI_LVVV(("capability->bridgeExtention.busPowerClockControl      = %u",     capability->bridgeExtention.busPowerClockControl));
        UEFI_LVVV(("capability->bridgeExtention.value8                    = 0x%02X", capability->bridgeExtention.value8));
        UEFI_LVVV(("capability->data                                      = %u",     capability->data));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Power management interface");



        // Capabilities
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities",                                 mprintf("0x%04X", capability->capabilities.value16),                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities: Version",                        mprintf("%u",     capability->capabilities.version),                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities: PME clock",                      capability->capabilities.pmeClock                     ? "Yes" : "No",                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities: Device specific initialization", capability->capabilities.deviceSpecificInitialization ? "Yes" : "No",                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities: AUX current",                    strdup(enumToFullString((PciPowerManagementAuxCurrent)capability->capabilities.auxCurrent)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities: Support D1",                     capability->capabilities.supportD1                    ? "Yes" : "No",                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities: Support D2",                     capability->capabilities.supportD2                    ? "Yes" : "No",                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);

            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Capabilities: PME support", supportPme, "0x%02X", PciPowerManagementSupportPmeFlag, DeviceManagerMode::EXPERT);
        }



        // Control/Status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control/Status",                mprintf("0x%04X", capability->controlStatus.value16),                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control/Status: Power state",   strdup(enumToFullString((PciPowerManagementPowerState)capability->controlStatus.powerState)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control/Status: No soft reset", capability->controlStatus.noSoftReset ? "Yes" : "No",                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control/Status: Enable PME",    capability->controlStatus.enablePme   ? "Yes" : "No",                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control/Status: Data select",   strdup(enumToFullString((PciPowerManagementDataSelect)capability->controlStatus.dataSelect)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control/Status: Data scale",    strdup(enumToFullString((PciPowerManagementDataScale)capability->controlStatus.dataScale)),   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control/Status: PME status",    capability->controlStatus.pmeStatus   ? "Yes" : "No",                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Bridge extention
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bridge extention",                                             mprintf("0x%02X", capability->bridgeExtention.value8),           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bridge extention: Switch secondary bus power state on D3 HOT", capability->bridgeExtention.b2B3ForD3Hot         ? "B2"  : "B3", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bridge extention: Enable bus power/clock control",             capability->bridgeExtention.busPowerClockControl ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data", mprintf("%u", capability->data), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciAcceleratedGraphicsPortCapability(PciAcceleratedGraphicsPortCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    PciAcceleratedGraphicsPortRateFlags statusRate(capability->status.rate);
    PciAcceleratedGraphicsPortRateFlags commandRate(capability->command.rate);



    // Validation
    {
        UEFI_LVVV(("capability->revision                               = 0x%02X", capability->revision));
        UEFI_LVVV(("capability->status.rate                            = %s",     flagsToFullString(statusRate)));
        UEFI_LVVV(("capability->status.supportSideBandAddressing       = %u",     capability->status.supportSideBandAddressing));
        UEFI_LVVV(("capability->status.maximumNumberOfCommandRequests  = %u",     capability->status.maximumNumberOfCommandRequests));
        UEFI_LVVV(("capability->status.value32                         = 0x%08X", capability->status.value32));
        UEFI_LVVV(("capability->command.rate                           = %s",     flagsToFullString(commandRate)));
        UEFI_LVVV(("capability->command.enableAcceleratedGraphicsPort  = %u",     capability->command.enableAcceleratedGraphicsPort));
        UEFI_LVVV(("capability->command.enableSideBandAddressing       = %u",     capability->command.enableSideBandAddressing));
        UEFI_LVVV(("capability->command.maximumNumberOfCommandRequests = %u",     capability->command.maximumNumberOfCommandRequests));
        UEFI_LVVV(("capability->command.value32                        = 0x%08X", capability->command.value32));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Accelerated graphics port");



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Revision", mprintf("0x%02X", capability->revision), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        // Status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status", mprintf("0x%08X", capability->status.value32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Status: Rate", statusRate, "0x%02X", PciAcceleratedGraphicsPortRateFlag, DeviceManagerMode::BASIC);

            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Support side band addressing",       capability->status.supportSideBandAddressing ? "Yes" : "No",      DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Maximum number of command requests", mprintf("%u", capability->status.maximumNumberOfCommandRequests), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }



        // Command
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command", mprintf("0x%08X", capability->command.value32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Command: Rate", commandRate, "0x%02X", PciAcceleratedGraphicsPortRateFlag, DeviceManagerMode::BASIC);

            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Enable accelerated graphics port",   capability->command.enableAcceleratedGraphicsPort ? "Yes" : "No",  DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Enable side band addressing",        capability->command.enableSideBandAddressing      ? "Yes" : "No",  DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Maximum number of command requests", mprintf("%u", capability->command.maximumNumberOfCommandRequests), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciVitalProductDataCapability(PciVitalProductDataCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // TODO: Need to decode VPD data



    // Validation
    {
        UEFI_LVVV(("capability->address.value    = 0x%04X", capability->address.value));
        UEFI_LVVV(("capability->address.finished = %u",     capability->address.finished));
        UEFI_LVVV(("capability->address.value16  = 0x%04X", capability->address.value16));
        UEFI_LVVV(("capability->data             = 0x%08X", capability->data));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Vital product data");



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Address union", mprintf("0x%04X", capability->address.value16), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Address",       mprintf("0x%04X", capability->address.value),   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Finished",      capability->address.finished ? "Yes" : "No",    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data",          mprintf("0x%08X", capability->data),            DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciSlotNumberingCapability(PciSlotNumberingCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->expansionSlot.expansionSlotsProvided = 0x%02X", capability->expansionSlot.expansionSlotsProvided));
        UEFI_LVVV(("capability->expansionSlot.firstInChassis         = %u",     capability->expansionSlot.firstInChassis));
        UEFI_LVVV(("capability->expansionSlot.value8                 = 0x%02X", capability->expansionSlot.value8));
        UEFI_LVVV(("capability->chassisNumber                        = %u",     capability->chassisNumber));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Slot ID");



        // Expansion slot
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Expansion slot",           mprintf("0x%02X", capability->expansionSlot.value8),                 DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Expansion slots provided", mprintf("0x%02X", capability->expansionSlot.expansionSlotsProvided), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("First in chassis",         capability->expansionSlot.firstInChassis ? "Yes" : "No",             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Chassis number", mprintf("%u", capability->chassisNumber), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciMessageSignaledInterruptsCapability(PciMessageSignaledInterruptsCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->messageControl.enableMSI               = %u",     capability->messageControl.enableMSI));
        UEFI_LVVV(("capability->messageControl.supportMultipleMessage  = %u",     capability->messageControl.supportMultipleMessage));
        UEFI_LVVV(("capability->messageControl.enableMultipleMessage   = %u",     capability->messageControl.enableMultipleMessage));
        UEFI_LVVV(("capability->messageControl.support64BitAddress     = %u",     capability->messageControl.support64BitAddress));
        UEFI_LVVV(("capability->messageControl.supportPerVectorMasking = %u",     capability->messageControl.supportPerVectorMasking));
        UEFI_LVVV(("capability->messageControl.value16                 = 0x%04X", capability->messageControl.value16));
        UEFI_LVVV(("capability->messageAddress.value                   = 0x%08X", capability->messageAddress.value));
        UEFI_LVVV(("capability->messageAddress.value32                 = 0x%08X", capability->messageAddress.value32));
        UEFI_LVVV(("capability->messageData                            = 0x%04X", capability->messageData));
    }



    if (capability->messageControl.support64BitAddress)
    {
        if (capability->messageControl.supportPerVectorMasking)
        {
            UEFI_ASSERT_EXECUTION(initPciMessageSignaledInterrupts64PerVectorMaskingCapability((PciMessageSignaledInterrupts64PerVectorMaskingCapability *)capability, deviceManagerEntry), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_ASSERT_EXECUTION(initPciMessageSignaledInterrupts64Capability((PciMessageSignaledInterrupts64Capability *)capability, deviceManagerEntry), NgosStatus::ASSERTION);
        }
    }
    else
    {
        UEFI_ASSERT_EXECUTION(initPciMessageSignaledInterrupts32Capability(capability, deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciMessageSignaledInterrupts32Capability(PciMessageSignaledInterruptsCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->messageControl.enableMSI               = %u",     capability->messageControl.enableMSI));
        UEFI_LVVV(("capability->messageControl.supportMultipleMessage  = %u",     capability->messageControl.supportMultipleMessage));
        UEFI_LVVV(("capability->messageControl.enableMultipleMessage   = %u",     capability->messageControl.enableMultipleMessage));
        UEFI_LVVV(("capability->messageControl.support64BitAddress     = %u",     capability->messageControl.support64BitAddress));
        UEFI_LVVV(("capability->messageControl.supportPerVectorMasking = %u",     capability->messageControl.supportPerVectorMasking));
        UEFI_LVVV(("capability->messageControl.value16                 = 0x%04X", capability->messageControl.value16));
        UEFI_LVVV(("capability->messageAddress.value                   = 0x%08X", capability->messageAddress.value));
        UEFI_LVVV(("capability->messageAddress.value32                 = 0x%08X", capability->messageAddress.value32));
        UEFI_LVVV(("capability->messageData                            = 0x%04X", capability->messageData));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Message signaled interrupts");



        // Message control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control",                             mprintf("0x%04X", capability->messageControl.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Enable MSI",                 capability->messageControl.enableMSI ? "Yes" : "No",                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Support multiple message",   mprintf("%u", capability->messageControl.supportMultipleMessageReal()), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Enable multiple message",    mprintf("%u", capability->messageControl.enableMultipleMessageReal()),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Support 64 bit address",     capability->messageControl.support64BitAddress ? "Yes" : "No",          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Support per vector masking", capability->messageControl.supportPerVectorMasking ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message address", mprintf("0x%08X", capability->messageAddress.value), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message data",    mprintf("0x%04X", capability->messageData),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciMessageSignaledInterrupts64Capability(PciMessageSignaledInterrupts64Capability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->messageControl.enableMSI               = %u",     capability->messageControl.enableMSI));
        UEFI_LVVV(("capability->messageControl.supportMultipleMessage  = %u",     capability->messageControl.supportMultipleMessage));
        UEFI_LVVV(("capability->messageControl.enableMultipleMessage   = %u",     capability->messageControl.enableMultipleMessage));
        UEFI_LVVV(("capability->messageControl.support64BitAddress     = %u",     capability->messageControl.support64BitAddress));
        UEFI_LVVV(("capability->messageControl.supportPerVectorMasking = %u",     capability->messageControl.supportPerVectorMasking));
        UEFI_LVVV(("capability->messageControl.value16                 = 0x%04X", capability->messageControl.value16));
        UEFI_LVVV(("capability->messageAddress.value                   = 0x%08X", capability->messageAddress.value));
        UEFI_LVVV(("capability->messageAddress.value32                 = 0x%08X", capability->messageAddress.value32));
        UEFI_LVVV(("capability->messageAddressUpper                    = 0x%08X", capability->messageAddressUpper));
        UEFI_LVVV(("capability->messageData                            = 0x%04X", capability->messageData));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Message signaled interrupts");



        // Message control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control",                             mprintf("0x%04X", capability->messageControl.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Enable MSI",                 capability->messageControl.enableMSI ? "Yes" : "No",                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Support multiple message",   mprintf("%u", capability->messageControl.supportMultipleMessageReal()), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Enable multiple message",    mprintf("%u", capability->messageControl.enableMultipleMessageReal()),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Support 64 bit address",     capability->messageControl.support64BitAddress ? "Yes" : "No",          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Support per vector masking", capability->messageControl.supportPerVectorMasking ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message address",       mprintf("0x%08X", capability->messageAddress.value), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message address upper", mprintf("0x%08X", capability->messageAddressUpper),  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message data",          mprintf("0x%04X", capability->messageData),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciMessageSignaledInterrupts64PerVectorMaskingCapability(PciMessageSignaledInterrupts64PerVectorMaskingCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->messageControl.enableMSI               = %u",     capability->messageControl.enableMSI));
        UEFI_LVVV(("capability->messageControl.supportMultipleMessage  = %u",     capability->messageControl.supportMultipleMessage));
        UEFI_LVVV(("capability->messageControl.enableMultipleMessage   = %u",     capability->messageControl.enableMultipleMessage));
        UEFI_LVVV(("capability->messageControl.support64BitAddress     = %u",     capability->messageControl.support64BitAddress));
        UEFI_LVVV(("capability->messageControl.supportPerVectorMasking = %u",     capability->messageControl.supportPerVectorMasking));
        UEFI_LVVV(("capability->messageControl.value16                 = 0x%04X", capability->messageControl.value16));
        UEFI_LVVV(("capability->messageAddress.value                   = 0x%08X", capability->messageAddress.value));
        UEFI_LVVV(("capability->messageAddress.value32                 = 0x%08X", capability->messageAddress.value32));
        UEFI_LVVV(("capability->messageAddressUpper                    = 0x%08X", capability->messageAddressUpper));
        UEFI_LVVV(("capability->messageData                            = 0x%04X", capability->messageData));
        UEFI_LVVV(("capability->maskBits                               = 0x%08X", capability->maskBits));
        UEFI_LVVV(("capability->pendingBits                            = 0x%08X", capability->pendingBits));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Message signaled interrupts");



        // Message control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control",                             mprintf("0x%04X", capability->messageControl.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Enable MSI",                 capability->messageControl.enableMSI ? "Yes" : "No",                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Support multiple message",   mprintf("%u", capability->messageControl.supportMultipleMessageReal()), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Enable multiple message",    mprintf("%u", capability->messageControl.enableMultipleMessageReal()),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Support 64 bit address",     capability->messageControl.support64BitAddress ? "Yes" : "No",          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Support per vector masking", capability->messageControl.supportPerVectorMasking ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message address",       mprintf("0x%08X", capability->messageAddress.value), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message address upper", mprintf("0x%08X", capability->messageAddressUpper),  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message data",          mprintf("0x%04X", capability->messageData),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Mask bits",             mprintf("0x%08X", capability->maskBits),             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Pending bits",          mprintf("0x%08X", capability->pendingBits),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciHotSwapCapability(PciHotSwapCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExtendedCapability(PciCapabilityHeader *capability, DeviceManagerEntryPCI *deviceManagerEntry, PciHeaderType headerType)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p, headerType = %u", capability, deviceManagerEntry, headerType));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    switch (headerType)
    {
        case PciHeaderType::DEVICE:            UEFI_ASSERT_EXECUTION(initPciExtendedDeviceCapability((PciExtendedDeviceCapability *)capability, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciHeaderType::PCI_TO_PCI_BRIDGE: UEFI_ASSERT_EXECUTION(initPciExtendedBridgeCapability((PciExtendedBridgeCapability *)capability, deviceManagerEntry), NgosStatus::ASSERTION); break;

        case PciHeaderType::CARDBUS_BRIDGE:
        {
            UEFI_LF(("Unexpected PCI header type %s", enumToFullString(headerType)));
        }
        break;

        default:
        {
            UEFI_LF(("Unknown PCI header type %s", enumToFullString(headerType)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExtendedDeviceCapability(PciExtendedDeviceCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->command.enableDataParityErrorRecovery              = %u",     capability->command.enableDataParityErrorRecovery));
        UEFI_LVVV(("capability->command.enableRelaxedOrdering                      = %u",     capability->command.enableRelaxedOrdering));
        UEFI_LVVV(("capability->command.maximumMemoryReadByteCount                 = %u",     capability->command.maximumMemoryReadByteCount));
        UEFI_LVVV(("capability->command.maximumOutstandingSplitTransactions        = %u",     capability->command.maximumOutstandingSplitTransactions));
        UEFI_LVVV(("capability->command.value16                                    = 0x%04X", capability->command.value16));
        UEFI_LVVV(("capability->status.functionNumber                              = %u",     capability->status.functionNumber));
        UEFI_LVVV(("capability->status.deviceNumber                                = %u",     capability->status.deviceNumber));
        UEFI_LVVV(("capability->status.busNumber                                   = %u",     capability->status.busNumber));
        UEFI_LVVV(("capability->status.is64BitDevice                               = %u",     capability->status.is64BitDevice));
        UEFI_LVVV(("capability->status.support133MHz                               = %u",     capability->status.support133MHz));
        UEFI_LVVV(("capability->status.splitCompletionDiscarded                    = %u",     capability->status.splitCompletionDiscarded));
        UEFI_LVVV(("capability->status.unexpectedSplitCompletion                   = %u",     capability->status.unexpectedSplitCompletion));
        UEFI_LVVV(("capability->status.deviceComplexity                            = %s",     enumToFullString((PciExtendedDeviceComplexity)capability->status.deviceComplexity)));
        UEFI_LVVV(("capability->status.designedMaximumMemoryReadByteCount          = %u",     capability->status.designedMaximumMemoryReadByteCount));
        UEFI_LVVV(("capability->status.designedMaximumOutstandingSplitTransactions = %u",     capability->status.designedMaximumOutstandingSplitTransactions));
        UEFI_LVVV(("capability->status.designedMaximumCumulativeReadSize           = %u",     capability->status.designedMaximumCumulativeReadSize));
        UEFI_LVVV(("capability->status.receivedSplitCompletionErrorMessage         = %u",     capability->status.receivedSplitCompletionErrorMessage));
        UEFI_LVVV(("capability->status.value32                                     = 0x%08X", capability->status.value32));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "PCI extended");



        // Command
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command",                                         mprintf("0x%04X", capability->command.value16),                                   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Enable data parity error recovery",      capability->command.enableDataParityErrorRecovery ? "Yes" : "No",                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Enable relaxed ordering",                capability->command.enableRelaxedOrdering         ? "Yes" : "No",                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Maximum memory read byte count",         strdup(bytesToString(capability->command.maximumMemoryReadByteCountReal())),      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Maximum outstanding split transactions", mprintf("%u",     capability->command.maximumOutstandingSplitTransactionsReal()), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                                                  mprintf("0x%08X", capability->status.value32),                                              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Function number",                                 mprintf("%u",     capability->status.functionNumber),                                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Device number",                                   mprintf("%u",     capability->status.deviceNumber),                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Bus number",                                      mprintf("%u",     capability->status.busNumber),                                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: 64 bit device",                                   capability->status.is64BitDevice                       ? "Yes" : "No",                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: 133 MHz capable",                                 capability->status.support133MHz                       ? "Yes" : "No",                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Split completion discarded",                      capability->status.splitCompletionDiscarded            ? "Yes" : "No",                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Unexpected split completion",                     capability->status.unexpectedSplitCompletion           ? "Yes" : "No",                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Device complexity",                               strdup(enumToFullString((PciExtendedDeviceComplexity)capability->status.deviceComplexity)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Designed maximum memory read byte count",         strdup(bytesToString(capability->status.designedMaximumMemoryReadByteCountReal())),         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Designed maximum outstanding split transactions", mprintf("%u",     capability->status.designedMaximumOutstandingSplitTransactionsReal()),    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Designed maximum cumulative read size",           strdup(bytesToString(capability->status.designedMaximumCumulativeReadSizeReal())),          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Received split completion error message",         capability->status.receivedSplitCompletionErrorMessage ? "Yes" : "No",                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExtendedBridgeCapability(PciExtendedBridgeCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->secondaryStatus.is64BitDevice              = %u",     capability->secondaryStatus.is64BitDevice));
        UEFI_LVVV(("capability->secondaryStatus.support133MHz              = %u",     capability->secondaryStatus.support133MHz));
        UEFI_LVVV(("capability->secondaryStatus.splitCompletionDiscarded   = %u",     capability->secondaryStatus.splitCompletionDiscarded));
        UEFI_LVVV(("capability->secondaryStatus.unexpectedSplitCompletion  = %u",     capability->secondaryStatus.unexpectedSplitCompletion));
        UEFI_LVVV(("capability->secondaryStatus.splitCompletionOverrun     = %u",     capability->secondaryStatus.splitCompletionOverrun));
        UEFI_LVVV(("capability->secondaryStatus.splitRequestDelayed        = %u",     capability->secondaryStatus.splitRequestDelayed));
        UEFI_LVVV(("capability->secondaryStatus.secondaryClockFrequency    = %s",     enumToFullString((PciExtendedBridgeSecondaryClockFrequency)capability->secondaryStatus.secondaryClockFrequency)));
        UEFI_LVVV(("capability->secondaryStatus.value16                    = 0x%04X", capability->secondaryStatus.value16));
        UEFI_LVVV(("capability->status.functionNumber                      = %u",     capability->status.functionNumber));
        UEFI_LVVV(("capability->status.deviceNumber                        = %u",     capability->status.deviceNumber));
        UEFI_LVVV(("capability->status.busNumber                           = %u",     capability->status.busNumber));
        UEFI_LVVV(("capability->status.is64BitDevice                       = %u",     capability->status.is64BitDevice));
        UEFI_LVVV(("capability->status.support133MHz                       = %u",     capability->status.support133MHz));
        UEFI_LVVV(("capability->status.splitCompletionDiscarded            = %u",     capability->status.splitCompletionDiscarded));
        UEFI_LVVV(("capability->status.unexpectedSplitCompletion           = %u",     capability->status.unexpectedSplitCompletion));
        UEFI_LVVV(("capability->status.splitCompletionOverrun              = %u",     capability->status.splitCompletionOverrun));
        UEFI_LVVV(("capability->status.splitRequestDelayed                 = %u",     capability->status.splitRequestDelayed));
        UEFI_LVVV(("capability->status.value32                             = 0x%08X", capability->status.value32));
        UEFI_LVVV(("capability->upstream.splitTransactionCommitmentLimit   = %u",     capability->upstream.splitTransactionCommitmentLimit));
        UEFI_LVVV(("capability->upstream.splitTransactionCapacity          = %u",     capability->upstream.splitTransactionCapacity));
        UEFI_LVVV(("capability->downstream.splitTransactionCommitmentLimit = %u",     capability->downstream.splitTransactionCommitmentLimit));
        UEFI_LVVV(("capability->downstream.splitTransactionCapacity        = %u",     capability->downstream.splitTransactionCapacity));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "PCI extended");



        // Secondary status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status",                              mprintf("0x%04X", capability->secondaryStatus.value16),                                                                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: 64 bit device",               capability->secondaryStatus.is64BitDevice             ? "Yes" : "No",                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: 133 MHz capable",             capability->secondaryStatus.support133MHz             ? "Yes" : "No",                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Split completion discarded",  capability->secondaryStatus.splitCompletionDiscarded  ? "Yes" : "No",                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Unexpected split completion", capability->secondaryStatus.unexpectedSplitCompletion ? "Yes" : "No",                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Split completion overrun",    capability->secondaryStatus.splitCompletionOverrun    ? "Yes" : "No",                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Split request delayed",       capability->secondaryStatus.splitRequestDelayed       ? "Yes" : "No",                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary status: Secondary clock frequency",   strdup(enumToFullString((PciExtendedBridgeSecondaryClockFrequency)capability->secondaryStatus.secondaryClockFrequency)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                              mprintf("0x%08X", capability->status.value32),               DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Function number",             mprintf("%u",     capability->status.functionNumber),        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Device number",               mprintf("%u",     capability->status.deviceNumber),          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Bus number",                  mprintf("%u",     capability->status.busNumber),             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: 64 bit device",               capability->status.is64BitDevice             ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: 133 MHz capable",             capability->status.support133MHz             ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Split completion discarded",  capability->status.splitCompletionDiscarded  ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Unexpected split completion", capability->status.unexpectedSplitCompletion ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Split completion overrun",    capability->status.splitCompletionOverrun    ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Split request delayed",       capability->status.splitRequestDelayed       ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Upstream
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upstream: Split transaction commitment limit", mprintf("%u", capability->upstream.splitTransactionCommitmentLimit), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upstream: Split transaction capacity",         mprintf("%u", capability->upstream.splitTransactionCapacity),        DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }



        // Downstream
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Downstream: Split transaction commitment limit", mprintf("%u", capability->downstream.splitTransactionCommitmentLimit), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Downstream: Split transaction capacity",         mprintf("%u", capability->downstream.splitTransactionCapacity),        DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciHyperTransportCapability(PciHyperTransportCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    switch ((PciHyperTransportCapabilityType)capability->command.capabilityType)
    {
        case PciHyperTransportCapabilityType::SLAVE_OR_PRIMARY_INTERFACE:  UEFI_ASSERT_EXECUTION(initPciHyperTransportSlavePrimaryInterfaceBlockCapability((PciHyperTransportSlavePrimaryInterfaceBlockCapability *)capability,   deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciHyperTransportCapabilityType::HOST_OR_SECONDARY_INTERFACE: UEFI_ASSERT_EXECUTION(initPciHyperTransportHostSecondaryInterfaceBlockCapability((PciHyperTransportHostSecondaryInterfaceBlockCapability *)capability, deviceManagerEntry), NgosStatus::ASSERTION); break;

        default:
        {
            UEFI_LF(("Unknown PCI HyperTransport capability type %s", enumToFullString((PciHyperTransportCapabilityType)capability->command.capabilityType)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciHyperTransportSlavePrimaryInterfaceBlockCapability(PciHyperTransportSlavePrimaryInterfaceBlockCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    PciHyperTransportLinkErrorFlags linkError0(capability->linkErrorAndFrequency0.error);
    PciHyperTransportLinkErrorFlags linkError1(capability->linkErrorAndFrequency1.error);



    // Validation
    {
        UEFI_LVVV(("capability->command.baseUnitId                         = %u",     capability->command.baseUnitId));
        UEFI_LVVV(("capability->command.unitCount                          = %u",     capability->command.unitCount));
        UEFI_LVVV(("capability->command.masterHost                         = %u",     capability->command.masterHost));
        UEFI_LVVV(("capability->command.defaultDirection                   = %u",     capability->command.defaultDirection));
        UEFI_LVVV(("capability->command.dropOnUninit                       = %u",     capability->command.dropOnUninit));
        UEFI_LVVV(("capability->command.capabilityType                     = %s",     enumToFullString((PciHyperTransportCapabilityType)capability->command.capabilityType)));
        UEFI_LVVV(("capability->command.value16                            = 0x%04X", capability->command.value16));
        UEFI_LVVV(("capability->linkControl0.enableSourceId                = %u",     capability->linkControl0.enableSourceId));
        UEFI_LVVV(("capability->linkControl0.enableCrcFlood                = %u",     capability->linkControl0.enableCrcFlood));
        UEFI_LVVV(("capability->linkControl0.crcStartTest                  = %u",     capability->linkControl0.crcStartTest));
        UEFI_LVVV(("capability->linkControl0.crcForceError                 = %u",     capability->linkControl0.crcForceError));
        UEFI_LVVV(("capability->linkControl0.linkFailure                   = %u",     capability->linkControl0.linkFailure));
        UEFI_LVVV(("capability->linkControl0.initializationComplete        = %u",     capability->linkControl0.initializationComplete));
        UEFI_LVVV(("capability->linkControl0.endOfChain                    = %u",     capability->linkControl0.endOfChain));
        UEFI_LVVV(("capability->linkControl0.transmitterOff                = %u",     capability->linkControl0.transmitterOff));
        UEFI_LVVV(("capability->linkControl0.crcError                      = %u",     capability->linkControl0.crcError));
        UEFI_LVVV(("capability->linkControl0.enableIsochronousFlowControl  = %u",     capability->linkControl0.enableIsochronousFlowControl));
        UEFI_LVVV(("capability->linkControl0.enableLdtStopTristate         = %u",     capability->linkControl0.enableLdtStopTristate));
        UEFI_LVVV(("capability->linkControl0.extendedCtlTime               = %u",     capability->linkControl0.extendedCtlTime));
        UEFI_LVVV(("capability->linkControl0.enable64BitAddressing         = %u",     capability->linkControl0.enable64BitAddressing));
        UEFI_LVVV(("capability->linkControl0.value16                       = 0x%04X", capability->linkControl0.value16));
        UEFI_LVVV(("capability->linkConfig0.maximumLinkWidthIn             = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.maximumLinkWidthIn)));
        UEFI_LVVV(("capability->linkConfig0.doublewordFlowControlIn        = %u",     capability->linkConfig0.doublewordFlowControlIn));
        UEFI_LVVV(("capability->linkConfig0.maximumLinkWidthOut            = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.maximumLinkWidthOut)));
        UEFI_LVVV(("capability->linkConfig0.doublewordFlowControlOut       = %u",     capability->linkConfig0.doublewordFlowControlOut));
        UEFI_LVVV(("capability->linkConfig0.linkWidthIn                    = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.linkWidthIn)));
        UEFI_LVVV(("capability->linkConfig0.enableDoublewordFlowControlIn  = %u",     capability->linkConfig0.enableDoublewordFlowControlIn));
        UEFI_LVVV(("capability->linkConfig0.linkWidthOut                   = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.linkWidthOut)));
        UEFI_LVVV(("capability->linkConfig0.enableDoublewordFlowControlOut = %u",     capability->linkConfig0.enableDoublewordFlowControlOut));
        UEFI_LVVV(("capability->linkConfig0.value16                        = 0x%04X", capability->linkConfig0.value16));
        UEFI_LVVV(("capability->linkControl1.enableSourceId                = %u",     capability->linkControl1.enableSourceId));
        UEFI_LVVV(("capability->linkControl1.enableCrcFlood                = %u",     capability->linkControl1.enableCrcFlood));
        UEFI_LVVV(("capability->linkControl1.crcStartTest                  = %u",     capability->linkControl1.crcStartTest));
        UEFI_LVVV(("capability->linkControl1.crcForceError                 = %u",     capability->linkControl1.crcForceError));
        UEFI_LVVV(("capability->linkControl1.linkFailure                   = %u",     capability->linkControl1.linkFailure));
        UEFI_LVVV(("capability->linkControl1.initializationComplete        = %u",     capability->linkControl1.initializationComplete));
        UEFI_LVVV(("capability->linkControl1.endOfChain                    = %u",     capability->linkControl1.endOfChain));
        UEFI_LVVV(("capability->linkControl1.transmitterOff                = %u",     capability->linkControl1.transmitterOff));
        UEFI_LVVV(("capability->linkControl1.crcError                      = %u",     capability->linkControl1.crcError));
        UEFI_LVVV(("capability->linkControl1.enableIsochronousFlowControl  = %u",     capability->linkControl1.enableIsochronousFlowControl));
        UEFI_LVVV(("capability->linkControl1.enableLdtStopTristate         = %u",     capability->linkControl1.enableLdtStopTristate));
        UEFI_LVVV(("capability->linkControl1.extendedCtlTime               = %u",     capability->linkControl1.extendedCtlTime));
        UEFI_LVVV(("capability->linkControl1.enable64BitAddressing         = %u",     capability->linkControl1.enable64BitAddressing));
        UEFI_LVVV(("capability->linkControl1.value16                       = 0x%04X", capability->linkControl1.value16));
        UEFI_LVVV(("capability->linkConfig1.maximumLinkWidthIn             = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.maximumLinkWidthIn)));
        UEFI_LVVV(("capability->linkConfig1.doublewordFlowControlIn        = %u",     capability->linkConfig1.doublewordFlowControlIn));
        UEFI_LVVV(("capability->linkConfig1.maximumLinkWidthOut            = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.maximumLinkWidthOut)));
        UEFI_LVVV(("capability->linkConfig1.doublewordFlowControlOut       = %u",     capability->linkConfig1.doublewordFlowControlOut));
        UEFI_LVVV(("capability->linkConfig1.linkWidthIn                    = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.linkWidthIn)));
        UEFI_LVVV(("capability->linkConfig1.enableDoublewordFlowControlIn  = %u",     capability->linkConfig1.enableDoublewordFlowControlIn));
        UEFI_LVVV(("capability->linkConfig1.linkWidthOut                   = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.linkWidthOut)));
        UEFI_LVVV(("capability->linkConfig1.enableDoublewordFlowControlOut = %u",     capability->linkConfig1.enableDoublewordFlowControlOut));
        UEFI_LVVV(("capability->linkConfig1.value16                        = 0x%04X", capability->linkConfig1.value16));
        UEFI_LVVV(("capability->revisionId                                 = %s",     enumToFullString(capability->revisionId)));
        UEFI_LVVV(("capability->linkErrorAndFrequency0.frequency           = %s",     enumToFullString((PciHyperTransportLinkFrequency)capability->linkErrorAndFrequency0.frequency)));
        UEFI_LVVV(("capability->linkErrorAndFrequency0.error               = %s",     flagsToFullString(linkError0)));
        UEFI_LVVV(("capability->linkErrorAndFrequency0.value8              = 0x%02X", capability->linkErrorAndFrequency0.value8));
        UEFI_LVVV(("capability->linkFrequencyCapability0                   = %s",     flagsToFullString(capability->linkFrequencyCapability0)));
        UEFI_LVVV(("capability->feature                                    = %s",     flagsToFullString(capability->feature)));
        UEFI_LVVV(("capability->linkErrorAndFrequency1.frequency           = %s",     enumToFullString((PciHyperTransportLinkFrequency)capability->linkErrorAndFrequency1.frequency)));
        UEFI_LVVV(("capability->linkErrorAndFrequency1.error               = %s",     flagsToFullString(linkError1)));
        UEFI_LVVV(("capability->linkErrorAndFrequency1.value8              = 0x%02X", capability->linkErrorAndFrequency1.value8));
        UEFI_LVVV(("capability->linkFrequencyCapability1                   = %s",     flagsToFullString(capability->linkFrequencyCapability1)));
        UEFI_LVVV(("capability->enumerationScratchpad                      = %u",     capability->enumerationScratchpad));
        UEFI_LVVV(("capability->errorHandling                              = %s",     flagsToFullString(capability->errorHandling)));
        UEFI_LVVV(("capability->memoryBaseUpper                            = 0x%02X", capability->memoryBaseUpper));
        UEFI_LVVV(("capability->memoryLimitUpper                           = 0x%02X", capability->memoryLimitUpper));
        UEFI_LVVV(("capability->busNumber                                  = %u",     capability->busNumber));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Hyper transport");



        // Command
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command",                    mprintf("0x%04X", capability->command.value16),                                                DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Base unit ID",      mprintf("%u",     capability->command.baseUnitId),                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Unit count",        mprintf("%u",     capability->command.unitCount),                                              DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Master host",       capability->command.masterHost ? "Yes" : "No",                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Default direction", capability->command.defaultDirection ? "To master host" : "From master host",                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Drop on uninit",    capability->command.dropOnUninit ? "Yes" : "No",                                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Capability type",   strdup(enumToFullString((PciHyperTransportCapabilityType)capability->command.capabilityType)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Link control 0
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0",                                  mprintf("0x%04X", capability->linkControl0.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: Enable source ID",                capability->linkControl0.enableSourceId               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: Enable CRC flood",                capability->linkControl0.enableCrcFlood               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: CRC start test",                  capability->linkControl0.crcStartTest                 ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: CRC force error",                 capability->linkControl0.crcForceError                ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: Link failure",                    capability->linkControl0.linkFailure                  ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: Initialization complete",         capability->linkControl0.initializationComplete       ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: End of chain",                    capability->linkControl0.endOfChain                   ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: Transmitter off",                 capability->linkControl0.transmitterOff               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: CRC error",                       mprintf("%u", capability->linkControl0.crcError),                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: Enable isochronous flow control", capability->linkControl0.enableIsochronousFlowControl ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: Enable LDTSTOP tristate",         capability->linkControl0.enableLdtStopTristate        ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: Extended CTL time",               capability->linkControl0.extendedCtlTime              ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 0: Enable 64 bit addressing",        capability->linkControl0.enable64BitAddressing        ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Link config 0
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 0",                                     mprintf("0x%04X", capability->linkConfig0.value16),                                                DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 0: Maximum link width in",              strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.maximumLinkWidthIn)),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 0: Doubleword flow control in",         capability->linkConfig0.doublewordFlowControlIn ? "Yes" : "No",                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 0: Maximum link width out",             strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.maximumLinkWidthOut)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 0: Doubleword flow control out",        capability->linkConfig0.doublewordFlowControlOut ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 0: Link width in",                      strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.linkWidthIn)),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 0: Enable doubleword flow control in",  capability->linkConfig0.enableDoublewordFlowControlIn ? "Yes" : "No",                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 0: Link width out",                     strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.linkWidthOut)),        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 0: Enable doubleword flow control out", capability->linkConfig0.enableDoublewordFlowControlOut ? "Yes" : "No",                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Link control 1
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1",                                  mprintf("0x%04X", capability->linkControl1.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: Enable source ID",                capability->linkControl1.enableSourceId               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: Enable CRC flood",                capability->linkControl1.enableCrcFlood               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: CRC start test",                  capability->linkControl1.crcStartTest                 ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: CRC force error",                 capability->linkControl1.crcForceError                ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: Link failure",                    capability->linkControl1.linkFailure                  ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: Initialization complete",         capability->linkControl1.initializationComplete       ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: End of chain",                    capability->linkControl1.endOfChain                   ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: Transmitter off",                 capability->linkControl1.transmitterOff               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: CRC error",                       mprintf("%u", capability->linkControl1.crcError),                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: Enable isochronous flow control", capability->linkControl1.enableIsochronousFlowControl ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: Enable LDTSTOP tristate",         capability->linkControl1.enableLdtStopTristate        ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: Extended CTL time",               capability->linkControl1.extendedCtlTime              ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 1: Enable 64 bit addressing",        capability->linkControl1.enable64BitAddressing        ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Link config 1
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 1",                                     mprintf("0x%04X", capability->linkConfig1.value16),                                                DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 1: Maximum link width in",              strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.maximumLinkWidthIn)),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 1: Doubleword flow control in",         capability->linkConfig1.doublewordFlowControlIn ? "Yes" : "No",                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 1: Maximum link width out",             strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.maximumLinkWidthOut)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 1: Doubleword flow control out",        capability->linkConfig1.doublewordFlowControlOut ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 1: Link width in",                      strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.linkWidthIn)),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 1: Enable doubleword flow control in",  capability->linkConfig1.enableDoublewordFlowControlIn ? "Yes" : "No",                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 1: Link width out",                     strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.linkWidthOut)),        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config 1: Enable doubleword flow control out", capability->linkConfig1.enableDoublewordFlowControlOut ? "Yes" : "No",                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Revision ID",      strdup(enumToFullString(capability->revisionId)),                                                       DeviceManagerMode::BASIC),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link frequency 0", strdup(enumToFullString((PciHyperTransportLinkFrequency)capability->linkErrorAndFrequency0.frequency)), DeviceManagerMode::BASIC),    NgosStatus::ASSERTION);



            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Link error 0",                linkError0,                           "0x%02X", PciHyperTransportLinkErrorFlag,                    DeviceManagerMode::EXPERT);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Link frequency capability 0", capability->linkFrequencyCapability0, "0x%04X", PciHyperTransportLinkFrequencyCapabilityFlag,      DeviceManagerMode::EXPERT);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Feature",                     capability->feature,                  "0x%02X", PciHyperTransportSlavePrimaryInterfaceFeatureFlag, DeviceManagerMode::EXPERT);



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link frequency 1", strdup(enumToFullString((PciHyperTransportLinkFrequency)capability->linkErrorAndFrequency1.frequency)), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);



            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Link error 1",                linkError1,                           "0x%02X", PciHyperTransportLinkErrorFlag,               DeviceManagerMode::EXPERT);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Link frequency capability 1", capability->linkFrequencyCapability1, "0x%04X", PciHyperTransportLinkFrequencyCapabilityFlag, DeviceManagerMode::EXPERT);



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enumeration scratchpad", mprintf("%u", capability->enumerationScratchpad), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Error handling", capability->errorHandling, "0x%04X", PciHyperTransportErrorHandlingFlag, DeviceManagerMode::EXPERT);



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory base upper",  mprintf("0x%02X", capability->memoryBaseUpper),  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory limit upper", mprintf("0x%02X", capability->memoryLimitUpper), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bus number",         mprintf("%u",     capability->busNumber),        DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciHyperTransportHostSecondaryInterfaceBlockCapability(PciHyperTransportHostSecondaryInterfaceBlockCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    PciHyperTransportLinkErrorFlags linkError(capability->linkErrorAndFrequency.error);



    // Validation
    {
        UEFI_LVVV(("capability->command.warmReset                         = %u",     capability->command.warmReset));
        UEFI_LVVV(("capability->command.doubleEnded                       = %u",     capability->command.doubleEnded));
        UEFI_LVVV(("capability->command.deviceNumber                      = %u",     capability->command.deviceNumber));
        UEFI_LVVV(("capability->command.chainSide                         = %u",     capability->command.chainSide));
        UEFI_LVVV(("capability->command.hostHide                          = %u",     capability->command.hostHide));
        UEFI_LVVV(("capability->command.actAsSlave                        = %u",     capability->command.actAsSlave));
        UEFI_LVVV(("capability->command.hostInboundEndOfChainError        = %u",     capability->command.hostInboundEndOfChainError));
        UEFI_LVVV(("capability->command.dropOnUninit                      = %u",     capability->command.dropOnUninit));
        UEFI_LVVV(("capability->command.capabilityType                    = %s",     enumToFullString((PciHyperTransportCapabilityType)capability->command.capabilityType)));
        UEFI_LVVV(("capability->command.value16                           = 0x%04X", capability->command.value16));
        UEFI_LVVV(("capability->linkControl.enableSourceId                = %u",     capability->linkControl.enableSourceId));
        UEFI_LVVV(("capability->linkControl.enableCrcFlood                = %u",     capability->linkControl.enableCrcFlood));
        UEFI_LVVV(("capability->linkControl.crcStartTest                  = %u",     capability->linkControl.crcStartTest));
        UEFI_LVVV(("capability->linkControl.crcForceError                 = %u",     capability->linkControl.crcForceError));
        UEFI_LVVV(("capability->linkControl.linkFailure                   = %u",     capability->linkControl.linkFailure));
        UEFI_LVVV(("capability->linkControl.initializationComplete        = %u",     capability->linkControl.initializationComplete));
        UEFI_LVVV(("capability->linkControl.endOfChain                    = %u",     capability->linkControl.endOfChain));
        UEFI_LVVV(("capability->linkControl.transmitterOff                = %u",     capability->linkControl.transmitterOff));
        UEFI_LVVV(("capability->linkControl.crcError                      = %u",     capability->linkControl.crcError));
        UEFI_LVVV(("capability->linkControl.enableIsochronousFlowControl  = %u",     capability->linkControl.enableIsochronousFlowControl));
        UEFI_LVVV(("capability->linkControl.enableLdtStopTristate         = %u",     capability->linkControl.enableLdtStopTristate));
        UEFI_LVVV(("capability->linkControl.extendedCtlTime               = %u",     capability->linkControl.extendedCtlTime));
        UEFI_LVVV(("capability->linkControl.enable64BitAddressing         = %u",     capability->linkControl.enable64BitAddressing));
        UEFI_LVVV(("capability->linkControl.value16                       = 0x%04X", capability->linkControl.value16));
        UEFI_LVVV(("capability->linkConfig.maximumLinkWidthIn             = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.maximumLinkWidthIn)));
        UEFI_LVVV(("capability->linkConfig.doublewordFlowControlIn        = %u",     capability->linkConfig.doublewordFlowControlIn));
        UEFI_LVVV(("capability->linkConfig.maximumLinkWidthOut            = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.maximumLinkWidthOut)));
        UEFI_LVVV(("capability->linkConfig.doublewordFlowControlOut       = %u",     capability->linkConfig.doublewordFlowControlOut));
        UEFI_LVVV(("capability->linkConfig.linkWidthIn                    = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.linkWidthIn)));
        UEFI_LVVV(("capability->linkConfig.enableDoublewordFlowControlIn  = %u",     capability->linkConfig.enableDoublewordFlowControlIn));
        UEFI_LVVV(("capability->linkConfig.linkWidthOut                   = %s",     enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.linkWidthOut)));
        UEFI_LVVV(("capability->linkConfig.enableDoublewordFlowControlOut = %u",     capability->linkConfig.enableDoublewordFlowControlOut));
        UEFI_LVVV(("capability->linkConfig.value16                        = 0x%04X", capability->linkConfig.value16));
        UEFI_LVVV(("capability->revisionId                                = %s",     enumToFullString(capability->revisionId)));
        UEFI_LVVV(("capability->linkErrorAndFrequency.frequency           = %s",     enumToFullString((PciHyperTransportLinkFrequency)capability->linkErrorAndFrequency.frequency)));
        UEFI_LVVV(("capability->linkErrorAndFrequency.error               = %s",     flagsToFullString(linkError)));
        UEFI_LVVV(("capability->linkErrorAndFrequency.value8              = 0x%02X", capability->linkErrorAndFrequency.value8));
        UEFI_LVVV(("capability->linkFrequencyCapability                   = %s",     flagsToFullString(capability->linkFrequencyCapability)));
        UEFI_LVVV(("capability->feature                                   = %s",     flagsToFullString(capability->feature)));
        UEFI_LVVV(("capability->enumerationScratchpad                     = %u",     capability->enumerationScratchpad));
        UEFI_LVVV(("capability->errorHandling                             = %s",     flagsToFullString(capability->errorHandling)));
        UEFI_LVVV(("capability->memoryBaseUpper                           = 0x%02X", capability->memoryBaseUpper));
        UEFI_LVVV(("capability->memoryLimitUpper                          = 0x%02X", capability->memoryLimitUpper));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Hyper transport");



        // Command
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command",                                  mprintf("0x%04X", capability->command.value16),                                                DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Warm reset",                      capability->command.warmReset                  ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Double ended",                    capability->command.doubleEnded                ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Device number",                   mprintf("%u", capability->command.deviceNumber),                                               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Chain side",                      capability->command.chainSide                  ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Host hide",                       capability->command.hostHide                   ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Act as slave",                    capability->command.actAsSlave                 ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Host inbound end of chain error", capability->command.hostInboundEndOfChainError ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Drop on uninit",                  capability->command.dropOnUninit               ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Command: Capability type",                 strdup(enumToFullString((PciHyperTransportCapabilityType)capability->command.capabilityType)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Link control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control",                                  mprintf("0x%04X", capability->linkControl.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Enable source ID",                capability->linkControl.enableSourceId               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Enable CRC flood",                capability->linkControl.enableCrcFlood               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: CRC start test",                  capability->linkControl.crcStartTest                 ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: CRC force error",                 capability->linkControl.crcForceError                ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Link failure",                    capability->linkControl.linkFailure                  ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Initialization complete",         capability->linkControl.initializationComplete       ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: End of chain",                    capability->linkControl.endOfChain                   ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Transmitter off",                 capability->linkControl.transmitterOff               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: CRC error",                       mprintf("%u", capability->linkControl.crcError),                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Enable isochronous flow control", capability->linkControl.enableIsochronousFlowControl ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Enable LDTSTOP tristate",         capability->linkControl.enableLdtStopTristate        ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Extended CTL time",               capability->linkControl.extendedCtlTime              ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Enable 64 bit addressing",        capability->linkControl.enable64BitAddressing        ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Link config
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config",                                     mprintf("0x%04X", capability->linkConfig.value16),                                                DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config: Maximum link width in",              strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.maximumLinkWidthIn)),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config: Doubleword flow control in",         capability->linkConfig.doublewordFlowControlIn ? "Yes" : "No",                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config: Maximum link width out",             strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.maximumLinkWidthOut)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config: Doubleword flow control out",        capability->linkConfig.doublewordFlowControlOut ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config: Link width in",                      strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.linkWidthIn)),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config: Enable doubleword flow control in",  capability->linkConfig.enableDoublewordFlowControlIn ? "Yes" : "No",                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config: Link width out",                     strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.linkWidthOut)),        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link config: Enable doubleword flow control out", capability->linkConfig.enableDoublewordFlowControlOut ? "Yes" : "No",                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Revision ID",    strdup(enumToFullString(capability->revisionId)),                                                      DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link frequency", strdup(enumToFullString((PciHyperTransportLinkFrequency)capability->linkErrorAndFrequency.frequency)), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);



            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Link error",                linkError,                           "0x%02X", PciHyperTransportLinkErrorFlag,                     DeviceManagerMode::EXPERT);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Link frequency capability", capability->linkFrequencyCapability, "0x%04X", PciHyperTransportLinkFrequencyCapabilityFlag,       DeviceManagerMode::EXPERT);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Feature",                   capability->feature,                 "0x%04X", PciHyperTransportHostSecondaryInterfaceFeatureFlag, DeviceManagerMode::EXPERT);



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enumeration scratchpad", mprintf("%u", capability->enumerationScratchpad), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Error handling", capability->errorHandling, "0x%04X", PciHyperTransportErrorHandlingFlag, DeviceManagerMode::EXPERT);



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory base upper",  mprintf("0x%02X", capability->memoryBaseUpper),  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory limit upper", mprintf("0x%02X", capability->memoryLimitUpper), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciVendorCapability(PciVendorCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->length = %u", capability->length));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Vendor specific");



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Length", mprintf("%u", capability->length), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciDebugPortCapability(PciDebugPortCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciCentralResourceControlCapability(PciCentralResourceControlCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciHotPlugCapability(PciHotPlugCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciAcceleratedGraphicsPort8xCapability(PciAcceleratedGraphicsPort8xCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciSecureDeviceCapability(PciSecureDeviceCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressCapability(PciExpressCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p, pci = 0x%p, bus = %d, device = %d, function = %d", capability, deviceManagerEntry, pci, bus, device, function));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(pci                != nullptr, "pci is null",                NgosStatus::ASSERTION);



    PciExpressCompletionTimeoutRangeFlags completionTimeoutRangesSupported(capability->deviceCapability2.completionTimeoutRangesSupported);
    PciExpressTphCompleterFlags           tphCompleterSupported(capability->deviceCapability2.tphCompleterSupported);



    // Validation
    {
        UEFI_LVVV(("capability->capability.capabilityVersion                                             = %u",     capability->capability.capabilityVersion));
        UEFI_LVVV(("capability->capability.devicePortType                                                = %s",     enumToFullString((PciExpressDevicePortType)capability->capability.devicePortType)));
        UEFI_LVVV(("capability->capability.slotImplemented                                               = %u",     capability->capability.slotImplemented));
        UEFI_LVVV(("capability->capability.interruptMessageNumber                                        = %u",     capability->capability.interruptMessageNumber));
        UEFI_LVVV(("capability->capability.value16                                                       = 0x%04X", capability->capability.value16));
        UEFI_LVVV(("capability->deviceCapability.maximumPayloadSizeSupported                             = %s",     enumToFullString((PciExpressPayloadSize)capability->deviceCapability.maximumPayloadSizeSupported)));
        UEFI_LVVV(("capability->deviceCapability.phantomFunctionsSupported                               = %u",     capability->deviceCapability.phantomFunctionsSupported));
        UEFI_LVVV(("capability->deviceCapability.extendedTagFieldSupported                               = %s",     enumToFullString((PciExpressExtendedTagField)capability->deviceCapability.extendedTagFieldSupported)));
        UEFI_LVVV(("capability->deviceCapability.endpointL0sAcceptableLatency                            = %s",     enumToFullString((PciExpressEndpointL0sAcceptableLatency)capability->deviceCapability.endpointL0sAcceptableLatency)));
        UEFI_LVVV(("capability->deviceCapability.endpointL1AcceptableLatency                             = %s",     enumToFullString((PciExpressEndpointL1AcceptableLatency)capability->deviceCapability.endpointL1AcceptableLatency)));
        UEFI_LVVV(("capability->deviceCapability.roleBasedErrorReporting                                 = %u",     capability->deviceCapability.roleBasedErrorReporting));
        UEFI_LVVV(("capability->deviceCapability.capturedSlotPowerLimitValue                             = %u",     capability->deviceCapability.capturedSlotPowerLimitValue));
        UEFI_LVVV(("capability->deviceCapability.capturedSlotPowerLimitScale                             = %s",     enumToFullString((PciExpressPowerScale)capability->deviceCapability.capturedSlotPowerLimitScale)));
        UEFI_LVVV(("capability->deviceCapability.functionLevelResetCapability                            = %u",     capability->deviceCapability.functionLevelResetCapability));
        UEFI_LVVV(("capability->deviceCapability.value32                                                 = 0x%08X", capability->deviceCapability.value32));
        UEFI_LVVV(("capability->deviceControl.correctableErrorReportingEnable                            = %u",     capability->deviceControl.correctableErrorReportingEnable));
        UEFI_LVVV(("capability->deviceControl.nonFatalErrorReportingEnable                               = %u",     capability->deviceControl.nonFatalErrorReportingEnable));
        UEFI_LVVV(("capability->deviceControl.fatalErrorReportingEnable                                  = %u",     capability->deviceControl.fatalErrorReportingEnable));
        UEFI_LVVV(("capability->deviceControl.unsupportedRequestReportingEnable                          = %u",     capability->deviceControl.unsupportedRequestReportingEnable));
        UEFI_LVVV(("capability->deviceControl.enableRelaxedOrdering                                      = %u",     capability->deviceControl.enableRelaxedOrdering));
        UEFI_LVVV(("capability->deviceControl.maximumPayloadSize                                         = %s",     enumToFullString((PciExpressPayloadSize)capability->deviceControl.maximumPayloadSize)));
        UEFI_LVVV(("capability->deviceControl.extendedTagFieldEnable                                     = %s",     enumToFullString((PciExpressExtendedTagField)capability->deviceControl.extendedTagFieldEnable)));
        UEFI_LVVV(("capability->deviceControl.phantomFunctionsEnable                                     = %u",     capability->deviceControl.phantomFunctionsEnable));
        UEFI_LVVV(("capability->deviceControl.auxPowerPmEnable                                           = %u",     capability->deviceControl.auxPowerPmEnable));
        UEFI_LVVV(("capability->deviceControl.enableNoSnoop                                              = %u",     capability->deviceControl.enableNoSnoop));
        UEFI_LVVV(("capability->deviceControl.maximumReadRequestSize                                     = %s",     enumToFullString((PciExpressRequestSize)capability->deviceControl.maximumReadRequestSize)));
        UEFI_LVVV(("capability->deviceControl.bridgeConfigurationRetryEnableOrInitiateFunctionLevelReset = %u",     capability->deviceControl.bridgeConfigurationRetryEnableOrInitiateFunctionLevelReset));
        UEFI_LVVV(("capability->deviceControl.value16                                                    = 0x%04X", capability->deviceControl.value16));
        UEFI_LVVV(("capability->deviceStatus                                                             = %s",     flagsToFullString(capability->deviceStatus)));
        UEFI_LVVV(("capability->linkCapability.supportedLinkSpeeds                                       = %s",     enumToFullString((PciExpressLinkSpeed)capability->linkCapability.supportedLinkSpeeds)));
        UEFI_LVVV(("capability->linkCapability.maximumLinkWidth                                          = %s",     enumToFullString((PciExpressLinkWidth)capability->linkCapability.maximumLinkWidth)));
        UEFI_LVVV(("capability->linkCapability.aspmSupport                                               = %s",     enumToFullString((PciExpressActiveStatePowerManagementSupport)capability->linkCapability.aspmSupport)));
        UEFI_LVVV(("capability->linkCapability.l0sExitLatency                                            = %s",     enumToFullString((PciExpressL0sExitLatency)capability->linkCapability.l0sExitLatency)));
        UEFI_LVVV(("capability->linkCapability.l1ExitLatency                                             = %s",     enumToFullString((PciExpressL1ExitLatency)capability->linkCapability.l1ExitLatency)));
        UEFI_LVVV(("capability->linkCapability.clockPowerManagement                                      = %u",     capability->linkCapability.clockPowerManagement));
        UEFI_LVVV(("capability->linkCapability.surpriseDownErrorReportingCapable                         = %u",     capability->linkCapability.surpriseDownErrorReportingCapable));
        UEFI_LVVV(("capability->linkCapability.dataLinkLayerLinkActiveReportingCapable                   = %u",     capability->linkCapability.dataLinkLayerLinkActiveReportingCapable));
        UEFI_LVVV(("capability->linkCapability.linkBandwidthNotificationCapability                       = %u",     capability->linkCapability.linkBandwidthNotificationCapability));
        UEFI_LVVV(("capability->linkCapability.aspmOptionalityCompliance                                 = %u",     capability->linkCapability.aspmOptionalityCompliance));
        UEFI_LVVV(("capability->linkCapability.portNumber                                                = %u",     capability->linkCapability.portNumber));
        UEFI_LVVV(("capability->linkCapability.value32                                                   = 0x%08X", capability->linkCapability.value32));
        UEFI_LVVV(("capability->linkControl.aspmControl                                                  = %s",     enumToFullString((PciExpressActiveStatePowerManagementControl)capability->linkControl.aspmControl)));
        UEFI_LVVV(("capability->linkControl.readCompletionBoundary                                       = %s",     enumToFullString((PciExpressReadCompletionBoundary)capability->linkControl.readCompletionBoundary)));
        UEFI_LVVV(("capability->linkControl.linkDisable                                                  = %u",     capability->linkControl.linkDisable));
        UEFI_LVVV(("capability->linkControl.retrainLink                                                  = %u",     capability->linkControl.retrainLink));
        UEFI_LVVV(("capability->linkControl.commonClockConfiguration                                     = %u",     capability->linkControl.commonClockConfiguration));
        UEFI_LVVV(("capability->linkControl.extendedSynch                                                = %u",     capability->linkControl.extendedSynch));
        UEFI_LVVV(("capability->linkControl.enableClockPowerManagement                                   = %u",     capability->linkControl.enableClockPowerManagement));
        UEFI_LVVV(("capability->linkControl.hardwareAutonomousWidthDisable                               = %u",     capability->linkControl.hardwareAutonomousWidthDisable));
        UEFI_LVVV(("capability->linkControl.linkBandwidthManagementInterruptEnable                       = %u",     capability->linkControl.linkBandwidthManagementInterruptEnable));
        UEFI_LVVV(("capability->linkControl.linkAutonomousBandwidthInterruptEnable                       = %u",     capability->linkControl.linkAutonomousBandwidthInterruptEnable));
        UEFI_LVVV(("capability->linkControl.value16                                                      = 0x%04X", capability->linkControl.value16));
        UEFI_LVVV(("capability->linkStatus.currentLinkSpeed                                              = %s",     enumToFullString((PciExpressLinkSpeed)capability->linkStatus.currentLinkSpeed)));
        UEFI_LVVV(("capability->linkStatus.negotiatedLinkWidth                                           = %s",     enumToFullString((PciExpressLinkWidth)capability->linkStatus.negotiatedLinkWidth)));
        UEFI_LVVV(("capability->linkStatus.linkTraining                                                  = %u",     capability->linkStatus.linkTraining));
        UEFI_LVVV(("capability->linkStatus.slotClockConfiguration                                        = %u",     capability->linkStatus.slotClockConfiguration));
        UEFI_LVVV(("capability->linkStatus.dataLinkLayerLinkActive                                       = %u",     capability->linkStatus.dataLinkLayerLinkActive));
        UEFI_LVVV(("capability->linkStatus.linkBandwidthManagementStatus                                 = %u",     capability->linkStatus.linkBandwidthManagementStatus));
        UEFI_LVVV(("capability->linkStatus.linkAutonomousBandwidthStatus                                 = %u",     capability->linkStatus.linkAutonomousBandwidthStatus));
        UEFI_LVVV(("capability->linkStatus.value16                                                       = 0x%04X", capability->linkStatus.value16));
        UEFI_LVVV(("capability->slotCapability.attentionButtonPresent                                    = %u",     capability->slotCapability.attentionButtonPresent));
        UEFI_LVVV(("capability->slotCapability.powerControllerPresent                                    = %u",     capability->slotCapability.powerControllerPresent));
        UEFI_LVVV(("capability->slotCapability.mrlSensorPresent                                          = %u",     capability->slotCapability.mrlSensorPresent));
        UEFI_LVVV(("capability->slotCapability.attentionIndicatorPresent                                 = %u",     capability->slotCapability.attentionIndicatorPresent));
        UEFI_LVVV(("capability->slotCapability.powerIndicatorPresent                                     = %u",     capability->slotCapability.powerIndicatorPresent));
        UEFI_LVVV(("capability->slotCapability.hotPlugSurprise                                           = %u",     capability->slotCapability.hotPlugSurprise));
        UEFI_LVVV(("capability->slotCapability.hotPlugCapable                                            = %u",     capability->slotCapability.hotPlugCapable));
        UEFI_LVVV(("capability->slotCapability.slotPowerLimitValue                                       = %u",     capability->slotCapability.slotPowerLimitValue));
        UEFI_LVVV(("capability->slotCapability.slotPowerLimitScale                                       = %s",     enumToFullString((PciExpressPowerScale)capability->slotCapability.slotPowerLimitScale)));
        UEFI_LVVV(("capability->slotCapability.electromechanicalInterlockPresent                         = %u",     capability->slotCapability.electromechanicalInterlockPresent));
        UEFI_LVVV(("capability->slotCapability.noCommandCompletedSupport                                 = %u",     capability->slotCapability.noCommandCompletedSupport));
        UEFI_LVVV(("capability->slotCapability.physicalSlotNumber                                        = %u",     capability->slotCapability.physicalSlotNumber));
        UEFI_LVVV(("capability->slotCapability.value32                                                   = 0x%08X", capability->slotCapability.value32));
        UEFI_LVVV(("capability->slotControl.attentionButtonPressedEnable                                 = %u",     capability->slotControl.attentionButtonPressedEnable));
        UEFI_LVVV(("capability->slotControl.powerFaultDetectedEnable                                     = %u",     capability->slotControl.powerFaultDetectedEnable));
        UEFI_LVVV(("capability->slotControl.mrlSensorChangedEnable                                       = %u",     capability->slotControl.mrlSensorChangedEnable));
        UEFI_LVVV(("capability->slotControl.presenceDetectChangedEnable                                  = %u",     capability->slotControl.presenceDetectChangedEnable));
        UEFI_LVVV(("capability->slotControl.commandCompletedInterruptEnable                              = %u",     capability->slotControl.commandCompletedInterruptEnable));
        UEFI_LVVV(("capability->slotControl.hotPlugInterruptEnable                                       = %u",     capability->slotControl.hotPlugInterruptEnable));
        UEFI_LVVV(("capability->slotControl.attentionIndicatorControl                                    = %s",     enumToFullString((PciExpressIndicatorControl)capability->slotControl.attentionIndicatorControl)));
        UEFI_LVVV(("capability->slotControl.powerIndicatorControl                                        = %s",     enumToFullString((PciExpressIndicatorControl)capability->slotControl.powerIndicatorControl)));
        UEFI_LVVV(("capability->slotControl.powerControllerControl                                       = %s",     enumToFullString((PciExpressPowerControllerControl)capability->slotControl.powerControllerControl)));
        UEFI_LVVV(("capability->slotControl.electromechanicalInterlockControl                            = %u",     capability->slotControl.electromechanicalInterlockControl));
        UEFI_LVVV(("capability->slotControl.dataLinkLayerStateChangedEnable                              = %u",     capability->slotControl.dataLinkLayerStateChangedEnable));
        UEFI_LVVV(("capability->slotControl.value16                                                      = 0x%04X", capability->slotControl.value16));
        UEFI_LVVV(("capability->slotStatus                                                               = %s",     flagsToFullString(capability->slotStatus)));
        UEFI_LVVV(("capability->rootControl                                                              = %s",     flagsToFullString(capability->rootControl)));
        UEFI_LVVV(("capability->rootCapability                                                           = %s",     flagsToFullString(capability->rootCapability)));
        UEFI_LVVV(("capability->rootStatus.pmeRequesterId                                                = %u",     capability->rootStatus.pmeRequesterId));
        UEFI_LVVV(("capability->rootStatus.pmeStatus                                                     = %u",     capability->rootStatus.pmeStatus));
        UEFI_LVVV(("capability->rootStatus.pmePending                                                    = %u",     capability->rootStatus.pmePending));
        UEFI_LVVV(("capability->rootStatus.value32                                                       = 0x%08X", capability->rootStatus.value32));
        UEFI_LVVV(("capability->deviceCapability2.completionTimeoutRangesSupported                       = %s",     flagsToFullString(completionTimeoutRangesSupported)));
        UEFI_LVVV(("capability->deviceCapability2.completionTimeoutDisableSupported                      = %u",     capability->deviceCapability2.completionTimeoutDisableSupported));
        UEFI_LVVV(("capability->deviceCapability2.ariForwardingSupported                                 = %u",     capability->deviceCapability2.ariForwardingSupported));
        UEFI_LVVV(("capability->deviceCapability2.atomicOpRoutingSupported                               = %u",     capability->deviceCapability2.atomicOpRoutingSupported));
        UEFI_LVVV(("capability->deviceCapability2.atomicOp32CompleterSupported                           = %u",     capability->deviceCapability2.atomicOp32CompleterSupported));
        UEFI_LVVV(("capability->deviceCapability2.atomicOp64CompleterSupported                           = %u",     capability->deviceCapability2.atomicOp64CompleterSupported));
        UEFI_LVVV(("capability->deviceCapability2.cas128CompleterSupported                               = %u",     capability->deviceCapability2.cas128CompleterSupported));
        UEFI_LVVV(("capability->deviceCapability2.noRoEnabledPrPrPassing                                 = %u",     capability->deviceCapability2.noRoEnabledPrPrPassing));
        UEFI_LVVV(("capability->deviceCapability2.ltrMechanismSupported                                  = %u",     capability->deviceCapability2.ltrMechanismSupported));
        UEFI_LVVV(("capability->deviceCapability2.tphCompleterSupported                                  = %s",     flagsToFullString(tphCompleterSupported)));
        UEFI_LVVV(("capability->deviceCapability2.lnSystemCls                                            = %u",     capability->deviceCapability2.lnSystemCls));
        UEFI_LVVV(("capability->deviceCapability2.tenBitTagCompleterSupported                            = %u",     capability->deviceCapability2.tenBitTagCompleterSupported));
        UEFI_LVVV(("capability->deviceCapability2.tenBitTagRequesterSupported                            = %u",     capability->deviceCapability2.tenBitTagRequesterSupported));
        UEFI_LVVV(("capability->deviceCapability2.obff                                                   = %u",     capability->deviceCapability2.obff));
        UEFI_LVVV(("capability->deviceCapability2.extendedFmtFieldSupported                              = %u",     capability->deviceCapability2.extendedFmtFieldSupported));
        UEFI_LVVV(("capability->deviceCapability2.endEndTlpPrefixSupported                               = %u",     capability->deviceCapability2.endEndTlpPrefixSupported));
        UEFI_LVVV(("capability->deviceCapability2.maxEndEndTlpPrefixes                                   = %u",     capability->deviceCapability2.maxEndEndTlpPrefixes));
        UEFI_LVVV(("capability->deviceCapability2.emergencyPowerReductionSupported                       = %u",     capability->deviceCapability2.emergencyPowerReductionSupported));
        UEFI_LVVV(("capability->deviceCapability2.emergencyPowerReductionInitializationRequired          = %u",     capability->deviceCapability2.emergencyPowerReductionInitializationRequired));
        UEFI_LVVV(("capability->deviceCapability2.frsSupported                                           = %u",     capability->deviceCapability2.frsSupported));
        UEFI_LVVV(("capability->deviceCapability2.value32                                                = 0x%08X", capability->deviceCapability2.value32));
        UEFI_LVVV(("capability->deviceControl2.completionTimeoutValue                                    = %s",     enumToFullString((PciExpressCompletionTimeout)capability->deviceControl2.completionTimeoutValue)));
        UEFI_LVVV(("capability->deviceControl2.completionTimeoutDisable                                  = %u",     capability->deviceControl2.completionTimeoutDisable));
        UEFI_LVVV(("capability->deviceControl2.ariForwardingEnable                                       = %u",     capability->deviceControl2.ariForwardingEnable));
        UEFI_LVVV(("capability->deviceControl2.atomicOpRequesterEnable                                   = %u",     capability->deviceControl2.atomicOpRequesterEnable));
        UEFI_LVVV(("capability->deviceControl2.atomicOpEgressBlocking                                    = %u",     capability->deviceControl2.atomicOpEgressBlocking));
        UEFI_LVVV(("capability->deviceControl2.idoRequestEnable                                          = %u",     capability->deviceControl2.idoRequestEnable));
        UEFI_LVVV(("capability->deviceControl2.idoCompletionEnable                                       = %u",     capability->deviceControl2.idoCompletionEnable));
        UEFI_LVVV(("capability->deviceControl2.ltrMechanismEnable                                        = %u",     capability->deviceControl2.ltrMechanismEnable));
        UEFI_LVVV(("capability->deviceControl2.emergencyPowerReductionRequest                            = %u",     capability->deviceControl2.emergencyPowerReductionRequest));
        UEFI_LVVV(("capability->deviceControl2.tenBitTagRequesterEnable                                  = %u",     capability->deviceControl2.tenBitTagRequesterEnable));
        UEFI_LVVV(("capability->deviceControl2.obff                                                      = %u",     capability->deviceControl2.obff));
        UEFI_LVVV(("capability->deviceControl2.endEndTlpPrefixBlocking                                   = %u",     capability->deviceControl2.endEndTlpPrefixBlocking));
        UEFI_LVVV(("capability->deviceControl2.value16                                                   = 0x%04X", capability->deviceControl2.value16));
        UEFI_LVVV(("capability->deviceStatus2.value16                                                    = 0x%04X", capability->deviceStatus2.value16));
        UEFI_LVVV(("capability->linkCapability2.linkSpeedsVector                                         = %u",     capability->linkCapability2.linkSpeedsVector));
        UEFI_LVVV(("capability->linkCapability2.crosslink                                                = %u",     capability->linkCapability2.crosslink));
        UEFI_LVVV(("capability->linkCapability2.value32                                                  = 0x%08X", capability->linkCapability2.value32));
        UEFI_LVVV(("capability->linkControl2.targetLinkSpeed                                             = %s",     enumToFullString((PciExpressLinkSpeed)capability->linkControl2.targetLinkSpeed)));
        UEFI_LVVV(("capability->linkControl2.enterCompliance                                             = %u",     capability->linkControl2.enterCompliance));
        UEFI_LVVV(("capability->linkControl2.hardwareAutonomousSpeedDisable                              = %u",     capability->linkControl2.hardwareAutonomousSpeedDisable));
        UEFI_LVVV(("capability->linkControl2.selectableDeemphasis                                        = %s",     enumToFullString((PciExpressDeemphasis)capability->linkControl2.selectableDeemphasis)));
        UEFI_LVVV(("capability->linkControl2.transmitMargin                                              = %u",     capability->linkControl2.transmitMargin));
        UEFI_LVVV(("capability->linkControl2.enterModifiedCompliance                                     = %u",     capability->linkControl2.enterModifiedCompliance));
        UEFI_LVVV(("capability->linkControl2.complianceSos                                               = %u",     capability->linkControl2.complianceSos));
        UEFI_LVVV(("capability->linkControl2.complianceDeemphasis                                        = %s",     enumToFullString((PciExpressDeemphasis)capability->linkControl2.complianceDeemphasis)));
        UEFI_LVVV(("capability->linkControl2.value16                                                     = 0x%04X", capability->linkControl2.value16));
        UEFI_LVVV(("capability->linkStatus2.currentDeemphasisLevel                                       = %s",     enumToFullString((PciExpressDeemphasis)capability->linkStatus2.currentDeemphasisLevel)));
        UEFI_LVVV(("capability->linkStatus2.equalizationComplete                                         = %u",     capability->linkStatus2.equalizationComplete));
        UEFI_LVVV(("capability->linkStatus2.equalizationPhase1Successful                                 = %u",     capability->linkStatus2.equalizationPhase1Successful));
        UEFI_LVVV(("capability->linkStatus2.equalizationPhase2Successful                                 = %u",     capability->linkStatus2.equalizationPhase2Successful));
        UEFI_LVVV(("capability->linkStatus2.equalizationPhase3Successful                                 = %u",     capability->linkStatus2.equalizationPhase3Successful));
        UEFI_LVVV(("capability->linkStatus2.linkEqualizationRequest                                      = %u",     capability->linkStatus2.linkEqualizationRequest));
        UEFI_LVVV(("capability->linkStatus2.value16                                                      = 0x%04X", capability->linkStatus2.value16));
        UEFI_LVVV(("capability->slotCapability2.value32                                                  = 0x%08X", capability->slotCapability2.value32));
        UEFI_LVVV(("capability->slotControl2.value16                                                     = 0x%04X", capability->slotControl2.value16));
        UEFI_LVVV(("capability->slotStatus2.value16                                                      = 0x%04X", capability->slotStatus2.value16));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "PCI Express");



        // Capability
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability",                   mprintf("0x%04X", capability->capability.value16),                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Version",          mprintf("%u",     capability->capability.capabilityVersion),                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Device port type", strdup(enumToFullString((PciExpressDevicePortType)capability->capability.devicePortType)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);



            if (
                (PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::ROOT_PORT_OF_PCI_EXPRESS_ROOT_COMPLEX
                ||
                (PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::DOWNSTREAM_PORT_OF_PCI_EXPRESS_SWITCH
               )
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Slot implemented", capability->capability.slotImplemented ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            }



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Interrupt message number", mprintf("%u", capability->capability.interruptMessageNumber), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }



        // Device capability
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability",                                 mprintf("0x%08X", capability->deviceCapability.value32),                                                      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability: Maximum payload size supported", strdup(enumToFullString((PciExpressPayloadSize)capability->deviceCapability.maximumPayloadSizeSupported)),    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability: Phantom functions supported",    mprintf("%u",     capability->deviceCapability.phantomFunctionsSupported),                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability: Extended tag field supported",   strdup(enumToFullString((PciExpressExtendedTagField)capability->deviceCapability.extendedTagFieldSupported)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);



            if (
                (PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::PCI_EXPRESS_ENDPOINT
                ||
                (PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::LEGACY_PCI_EXPRESS_ENDPOINT
                ||
                (PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::ROOT_COMPLEX_INTEGRATED_ENDPOINT
               )
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability: Endpoint L0s acceptable latency", strdup(enumToFullString((PciExpressEndpointL0sAcceptableLatency)capability->deviceCapability.endpointL0sAcceptableLatency)), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability: Endpoint L1 acceptable latency",  strdup(enumToFullString((PciExpressEndpointL1AcceptableLatency)capability->deviceCapability.endpointL1AcceptableLatency)),   DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            }



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability: Role based error reporting", capability->deviceCapability.roleBasedErrorReporting ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);



            if ((PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::UPSTREAM_PORT_OF_PCI_EXPRESS_SWITCH)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability: Captured slot power limit value", mprintf("%u",     capability->deviceCapability.capturedSlotPowerLimitValue),                              DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability: Captured slot power limit scale", strdup(enumToFullString((PciExpressPowerScale)capability->deviceCapability.capturedSlotPowerLimitScale)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            }



            if (
                (PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::PCI_EXPRESS_ENDPOINT
                ||
                (PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::LEGACY_PCI_EXPRESS_ENDPOINT
                ||
                (PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::ROOT_COMPLEX_INTEGRATED_ENDPOINT
               )
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability: Function level reset capability", capability->deviceCapability.functionLevelResetCapability ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            }
        }



        // Device control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control",                                       mprintf("0x%04X", capability->deviceControl.value16),                                                   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Correctable error reporting enable",   capability->deviceControl.correctableErrorReportingEnable   ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Non-fatal error reporting enable",     capability->deviceControl.nonFatalErrorReportingEnable      ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Fatal error reporting enable",         capability->deviceControl.fatalErrorReportingEnable         ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Unsupported request reporting enable", capability->deviceControl.unsupportedRequestReportingEnable ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Enable relaxed ordering",              capability->deviceControl.enableRelaxedOrdering             ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Maximum payload size",                 strdup(enumToFullString((PciExpressPayloadSize)capability->deviceControl.maximumPayloadSize)),          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Extended tag field enable",            strdup(enumToFullString((PciExpressExtendedTagField)capability->deviceControl.extendedTagFieldEnable)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Phantom functions enable",             capability->deviceControl.phantomFunctionsEnable ? "Yes" : "No",                                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Auxiliary power PM enable",            capability->deviceControl.auxPowerPmEnable       ? "Yes" : "No",                                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Enable no snoop",                      capability->deviceControl.enableNoSnoop          ? "Yes" : "No",                                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Maximum read request size",            strdup(enumToFullString((PciExpressRequestSize)capability->deviceControl.maximumReadRequestSize)),      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);



            if ((PciExpressDevicePortType)capability->capability.devicePortType == PciExpressDevicePortType::PCI_EXPRESS_TO_PCI_BRIDGE)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control: Bridge configuration retry enable", capability->deviceControl.bridgeConfigurationRetryEnableOrInitiateFunctionLevelReset ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            }
        }



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Device status", capability->deviceStatus, "0x%04X", PciExpressDeviceStatusFlag, DeviceManagerMode::BASIC);



        // Link capability
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability",                                                mprintf("0x%08X", capability->linkCapability.value32),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: Supported link speeds",                         strdup(enumToFullString((PciExpressLinkSpeed)capability->linkCapability.supportedLinkSpeeds)),                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: Maximum link width",                            strdup(enumToFullString((PciExpressLinkWidth)capability->linkCapability.maximumLinkWidth)),                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: ASPM support",                                  strdup(enumToFullString((PciExpressActiveStatePowerManagementSupport)capability->linkCapability.aspmSupport)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: L0s exit latency",                              strdup(enumToFullString((PciExpressL0sExitLatency)capability->linkCapability.l0sExitLatency)),                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: L1 exit latency",                               strdup(enumToFullString((PciExpressL1ExitLatency)capability->linkCapability.l1ExitLatency)),                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: Clock power management",                        capability->linkCapability.clockPowerManagement                    ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: Surprise down error reporting capable",         capability->linkCapability.surpriseDownErrorReportingCapable       ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: Data link layer link active reporting capable", capability->linkCapability.dataLinkLayerLinkActiveReportingCapable ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: Link bandwidth notification capability",        capability->linkCapability.linkBandwidthNotificationCapability     ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: ASPM optionality compliance",                   capability->linkCapability.aspmOptionalityCompliance               ? "Yes" : "No",                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability: Port number",                                   mprintf("%u",     capability->linkCapability.portNumber),                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Link control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control",               mprintf("0x%04X", capability->linkControl.value16),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: ASPM control", strdup(enumToFullString((PciExpressActiveStatePowerManagementControl)capability->linkControl.aspmControl)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);



            if (
                (PciExpressDevicePortType)capability->capability.devicePortType != PciExpressDevicePortType::UPSTREAM_PORT_OF_PCI_EXPRESS_SWITCH
                &&
                (PciExpressDevicePortType)capability->capability.devicePortType != PciExpressDevicePortType::DOWNSTREAM_PORT_OF_PCI_EXPRESS_SWITCH
               )
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Read completion boundary", strdup(enumToFullString((PciExpressReadCompletionBoundary)capability->linkControl.readCompletionBoundary)), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            }



            if (
                (PciExpressDevicePortType)capability->capability.devicePortType != PciExpressDevicePortType::PCI_EXPRESS_ENDPOINT
                &&
                (PciExpressDevicePortType)capability->capability.devicePortType != PciExpressDevicePortType::LEGACY_PCI_EXPRESS_ENDPOINT
                &&
                (PciExpressDevicePortType)capability->capability.devicePortType != PciExpressDevicePortType::ROOT_COMPLEX_INTEGRATED_ENDPOINT
                &&
                (PciExpressDevicePortType)capability->capability.devicePortType != PciExpressDevicePortType::UPSTREAM_PORT_OF_PCI_EXPRESS_SWITCH
                &&
                (PciExpressDevicePortType)capability->capability.devicePortType != PciExpressDevicePortType::PCI_EXPRESS_TO_PCI_BRIDGE
               )
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Link disable", capability->linkControl.linkDisable ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            }



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Retrain link",                               capability->linkControl.retrainLink                            ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Common clock configuration",                 capability->linkControl.commonClockConfiguration               ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Extended synch",                             capability->linkControl.extendedSynch                          ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Enable clock power management",              capability->linkControl.enableClockPowerManagement             ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Hardware autonomous width disable",          capability->linkControl.hardwareAutonomousWidthDisable         ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Link bandwidth management interrupt enable", capability->linkControl.linkBandwidthManagementInterruptEnable ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control: Link autonomous bandwidth interrupt enable", capability->linkControl.linkAutonomousBandwidthInterruptEnable ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
        }



        // Link status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status",                                   mprintf("0x%04X", capability->linkStatus.value16),                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status: Current link speed",               strdup(enumToFullString((PciExpressLinkSpeed)capability->linkStatus.currentLinkSpeed)),    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status: Negotiated link width",            strdup(enumToFullString((PciExpressLinkWidth)capability->linkStatus.negotiatedLinkWidth)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status: Link training",                    capability->linkStatus.linkTraining                  ? "Yes" : "No",                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status: Slot clock configuration",         capability->linkStatus.slotClockConfiguration        ? "Yes" : "No",                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status: Data link layer link active",      capability->linkStatus.dataLinkLayerLinkActive       ? "Yes" : "No",                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status: Link bandwidth management status", capability->linkStatus.linkBandwidthManagementStatus ? "Yes" : "No",                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status: Link autonomous bandwidth status", capability->linkStatus.linkAutonomousBandwidthStatus ? "Yes" : "No",                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Slot capability
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability",                                      mprintf("0x%08X", capability->slotCapability.value32),                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Attention button present",            capability->slotCapability.attentionButtonPresent    ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Power controller present",            capability->slotCapability.powerControllerPresent    ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: MRL sensor present",                  capability->slotCapability.mrlSensorPresent          ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Attention indicator present",         capability->slotCapability.attentionIndicatorPresent ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Power indicator present",             capability->slotCapability.powerIndicatorPresent     ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Hot-plug surprise",                   capability->slotCapability.hotPlugSurprise           ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Hot-plug capable",                    capability->slotCapability.hotPlugCapable            ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Slot power limit value",              mprintf("%u",     capability->slotCapability.slotPowerLimitValue),                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Slot power limit scale",              strdup(enumToFullString((PciExpressPowerScale)capability->slotCapability.slotPowerLimitScale)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Electromechanical interlock present", capability->slotCapability.electromechanicalInterlockPresent ? "Yes" : "No",                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: No command completed support",        capability->slotCapability.noCommandCompletedSupport         ? "Yes" : "No",                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability: Physical slot number",                mprintf("%u",     capability->slotCapability.physicalSlotNumber),                               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Slot control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control",                                       mprintf("0x%04X", capability->slotControl.value16),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Attention button pressed enable",      capability->slotControl.attentionButtonPressedEnable    ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Power fault detected enable",          capability->slotControl.powerFaultDetectedEnable        ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: MRL sensor changed enable",            capability->slotControl.mrlSensorChangedEnable          ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Presence detect changed enable",       capability->slotControl.presenceDetectChangedEnable     ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Command completed interrupt enable",   capability->slotControl.commandCompletedInterruptEnable ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Hot-plug interrupt enable",            capability->slotControl.hotPlugInterruptEnable          ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Attention indicator control",          strdup(enumToFullString((PciExpressIndicatorControl)capability->slotControl.attentionIndicatorControl)),    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Power indicator control",              strdup(enumToFullString((PciExpressIndicatorControl)capability->slotControl.powerIndicatorControl)),        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Power controller control",             strdup(enumToFullString((PciExpressPowerControllerControl)capability->slotControl.powerControllerControl)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Electromechanical interlock control",  capability->slotControl.electromechanicalInterlockControl ? "Yes" : "No",                                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control: Data link layer state changed enable", capability->slotControl.dataLinkLayerStateChangedEnable   ? "Yes" : "No",                                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Slot status",     capability->slotStatus,     "0x%04X", PciExpressSlotStatusFlag,     DeviceManagerMode::BASIC);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Root control",    capability->rootControl,    "0x%04X", PciExpressRootControlFlag,    DeviceManagerMode::EXPERT);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Root capability", capability->rootCapability, "0x%04X", PciExpressRootCapabilityFlag, DeviceManagerMode::EXPERT);



        // Root status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root status",                   mprintf("0x%08X", capability->rootStatus.value32),        DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root status: PME requester ID", mprintf("%u",     capability->rootStatus.pmeRequesterId), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root status: PME status",       capability->rootStatus.pmeStatus  ? "Yes" : "No",         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root status: PME pending",      capability->rootStatus.pmePending ? "Yes" : "No",         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Device capability 2
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2", mprintf("0x%08X", capability->deviceCapability2.value32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Device capability 2: Completion timeout ranges supported", completionTimeoutRangesSupported, "0x%02X", PciExpressCompletionTimeoutRangeFlag, DeviceManagerMode::EXPERT);



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Completion timeout disable supported", capability->deviceCapability2.completionTimeoutDisableSupported ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: ARI forwarding supported",             capability->deviceCapability2.ariForwardingSupported            ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: AtomicOp routing supported",           capability->deviceCapability2.atomicOpRoutingSupported          ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: AtomicOp 32-bit completer supported",  capability->deviceCapability2.atomicOp32CompleterSupported      ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: AtomicOp 64-bit completer supported",  capability->deviceCapability2.atomicOp64CompleterSupported      ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: CAS 128-bit completer supported",      capability->deviceCapability2.cas128CompleterSupported          ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: No RO-enabled PR-PR passing",          capability->deviceCapability2.noRoEnabledPrPrPassing            ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: LTR mechanism supported",              capability->deviceCapability2.ltrMechanismSupported             ? "Yes" : "No", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);



            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Device capability 2: TPH completer supported", tphCompleterSupported, "0x%02X", PciExpressTphCompleterFlag, DeviceManagerMode::EXPERT);



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Ln system cls",                                     mprintf("%u",     capability->deviceCapability2.lnSystemCls),                               DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Ten bit tag completer supported",                   capability->deviceCapability2.tenBitTagCompleterSupported ? "Yes" : "No",                   DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Ten bit tag requester supported",                   capability->deviceCapability2.tenBitTagRequesterSupported ? "Yes" : "No",                   DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Obff",                                              mprintf("%u",     capability->deviceCapability2.obff),                                      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Extended fmt field supported",                      capability->deviceCapability2.extendedFmtFieldSupported ? "Yes" : "No",                     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: End-end TLP prefix supported",                      capability->deviceCapability2.endEndTlpPrefixSupported  ? "Yes" : "No",                     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Max end-end TLP prefixes",                          mprintf("%u",     capability->deviceCapability2.maxEndEndTlpPrefixes),                      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Emergency power reduction supported",               mprintf("%u",     capability->deviceCapability2.emergencyPowerReductionSupported),          DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Emergency power reduction initialization required", capability->deviceCapability2.emergencyPowerReductionInitializationRequired ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capability 2: Frs supported",                                     capability->deviceCapability2.frsSupported                                  ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }



        // Device control 2
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2",                                    mprintf("0x%04X", capability->deviceControl2.value16),                                                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: Completion timeout value",          strdup(enumToFullString((PciExpressCompletionTimeout)capability->deviceControl2.completionTimeoutValue)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: Completion timeout disable",        capability->deviceControl2.completionTimeoutDisable       ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: ARI forwarding enable",             capability->deviceControl2.ariForwardingEnable            ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: AtomicOp requester enable",         capability->deviceControl2.atomicOpRequesterEnable        ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: AtomicOp egress blocking",          capability->deviceControl2.atomicOpEgressBlocking         ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: IDO request enable",                capability->deviceControl2.idoRequestEnable               ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: IDO completion enable",             capability->deviceControl2.idoCompletionEnable            ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: LTR mechanism enable",              capability->deviceControl2.ltrMechanismEnable             ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: Emergency power reduction request", capability->deviceControl2.emergencyPowerReductionRequest ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: Ten bit tag requester enable",      capability->deviceControl2.tenBitTagRequesterEnable       ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: Obff",                              mprintf("%u",     capability->deviceControl2.obff),                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device control 2: End-End TLP prefix blocking",       capability->deviceControl2.endEndTlpPrefixBlocking        ? "Yes" : "No",                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device status 2", mprintf("0x%04X", capability->deviceStatus2.value16), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



        // Link capability 2
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability 2",                     mprintf("0x%08X", capability->linkCapability2.value32),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability 2: Link speeds vector", mprintf("%u",     capability->linkCapability2.linkSpeedsVector), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link capability 2: Crosslink",          capability->linkCapability2.crosslink ? "Yes" : "No",            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Link control 2
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 2",                                    mprintf("0x%04X", capability->linkControl2.value16),                                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 2: Target link speed",                 strdup(enumToFullString((PciExpressLinkSpeed)capability->linkControl2.targetLinkSpeed)),       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 2: Enter compliance",                  capability->linkControl2.enterCompliance                ? "Yes" : "No",                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 2: Hardware autonomous speed disable", capability->linkControl2.hardwareAutonomousSpeedDisable ? "Yes" : "No",                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 2: Selectable de-emphasis",            strdup(enumToFullString((PciExpressDeemphasis)capability->linkControl2.selectableDeemphasis)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 2: Transmit margin",                   mprintf("%u",     capability->linkControl2.transmitMargin),                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 2: Enter modified compliance",         capability->linkControl2.enterModifiedCompliance ? "Yes" : "No",                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 2: Compliance SOS",                    capability->linkControl2.complianceSos           ? "Yes" : "No",                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link control 2: Compliance de-emphasis",            strdup(enumToFullString((PciExpressDeemphasis)capability->linkControl2.complianceDeemphasis)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Link status 2
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status 2",                                  mprintf("0x%04X", capability->linkStatus2.value16),                                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status 2: Current de-emphasis level",       strdup(enumToFullString((PciExpressDeemphasis)capability->linkStatus2.currentDeemphasisLevel)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status 2: Equalization complete",           capability->linkStatus2.equalizationComplete         ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status 2: Equalization phase 1 successful", capability->linkStatus2.equalizationPhase1Successful ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status 2: Equalization phase 2 successful", capability->linkStatus2.equalizationPhase2Successful ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status 2: Equalization phase 3 successful", capability->linkStatus2.equalizationPhase3Successful ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Link status 2: Link equalization request",       capability->linkStatus2.linkEqualizationRequest      ? "Yes" : "No",                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot capability 2", mprintf("0x%08X", capability->slotCapability2.value32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot control 2",    mprintf("0x%04X", capability->slotControl2.value16),    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Slot status 2",     mprintf("0x%04X", capability->slotStatus2.value16),     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    // Read and parse PCI extended configuration space
    {
        u64 address = UEFI_PCI_ADDRESS(bus, device, function, sizeof(PciConfigurationSpace));



        PciExtendedConfigurationSpace configurationSpace;

        if (pci->pci.read(pci, UefiPciRootBridgeIoProtocolWidth::UINT32, address, sizeof(configurationSpace) / sizeof(u32), &configurationSpace) == UefiStatus::SUCCESS)
        {
            UEFI_LVV(("Successfully read PCI extended configuration space from protocol(0x%p) for PCI(%d/%d/%d)", pci, bus, device, function));



            UEFI_ASSERT_EXECUTION(initPciWithExtendedConfigurationSpace(configurationSpace, deviceManagerEntry), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_LE(("Failed to read PCI configuration space from protocol(0x%p) for PCI(%d/%d/%d)", pci, bus, device, function));
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciMessageSignaledInterruptsExtendedCapability(PciMessageSignaledInterruptsExtendedCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->messageControl.tableSize               = %u",     capability->messageControl.tableSize));
        UEFI_LVVV(("capability->messageControl.enableMSIX              = %u",     capability->messageControl.enableMSIX));
        UEFI_LVVV(("capability->messageControl.value16                 = 0x%04X", capability->messageControl.value16));
        UEFI_LVVV(("capability->messageAddressUpper                    = 0x%08X", capability->messageAddressUpper));
        UEFI_LVVV(("capability->tableOffsetAndBir.baseAddressIndicator = %u",     capability->tableOffsetAndBir.baseAddressIndicator));
        UEFI_LVVV(("capability->tableOffsetAndBir.tableOffset          = 0x%08X", capability->tableOffsetAndBir.tableOffset));
        UEFI_LVVV(("capability->tableOffsetAndBir.value32              = 0x%08X", capability->tableOffsetAndBir.value32));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Message signaled interrupts extended");



        // Message control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control",               mprintf("0x%04X", capability->messageControl.value16),     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Enable MSI-X", capability->messageControl.enableMSIX ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message control: Table size",   mprintf("%u", capability->messageControl.tableSizeReal()), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Message address upper",  mprintf("0x%08X", capability->messageAddressUpper),                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address indicator", mprintf("%u",     capability->tableOffsetAndBir.baseAddressIndicator), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Table offset",           mprintf("%u",     capability->tableOffsetAndBir.tableOffset),          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithExtendedConfigurationSpace(const PciExtendedConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | configurationSpace = ..., deviceManagerEntry = 0x%p", deviceManagerEntry));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    PciExtendedCapabilityHeader *capability = (PciExtendedCapabilityHeader *)&configurationSpace.capability;

    while (
           capability->capabilityId != 0
           &&
           capability->capabilityVersion != 0
          )
    {
        UEFI_ASSERT_EXECUTION(initPciWithExtendedCapability(capability, deviceManagerEntry), NgosStatus::ASSERTION);



        if (capability->nextCapabilityOffset < sizeof(PciConfigurationSpace))
        {
            break;
        }

        capability = (PciExtendedCapabilityHeader *)((u64)&configurationSpace + capability->nextCapabilityOffset - sizeof(PciConfigurationSpace));
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithExtendedCapability(PciExtendedCapabilityHeader *capability, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->capabilityId         = %s",     enumToFullString((PciExtendedCapabilityType)capability->capabilityId)));
        UEFI_LVVV(("capability->capabilityVersion    = 0x%04X", capability->capabilityVersion));
        UEFI_LVVV(("capability->nextCapabilityOffset = 0x%04X", capability->nextCapabilityOffset));
    }



    // Fill Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended capability", strdup(enumToFullString((PciExtendedCapabilityType)capability->capabilityId)), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
    }



    switch ((PciExtendedCapabilityType)capability->capabilityId)
    {
        case PciExtendedCapabilityType::ADVANCED_ERROR_REPORTING:                          UEFI_ASSERT_EXECUTION(initPciExpressAdvancedErrorReportingCapability((PciExpressAdvancedErrorReportingCapability *)capability,                                             capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::VIRTUAL_CHANNEL:                                   UEFI_ASSERT_EXECUTION(initPciExpressVirtualChannelCapability((PciExpressVirtualChannelCapability *)capability,                                                             capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::VIRTUAL_CHANNEL_MFVC:                              UEFI_ASSERT_EXECUTION(initPciExpressVirtualChannelCapability((PciExpressVirtualChannelCapability *)capability,                                                             capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::MULTI_FUNCTION_VIRTUAL_CHANNEL:                    UEFI_ASSERT_EXECUTION(initPciExpressVirtualChannelCapability((PciExpressVirtualChannelCapability *)capability,                                                             capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::DEVICE_SERIAL_NUMBER:                              UEFI_ASSERT_EXECUTION(initPciExpressDeviceSerialNumberCapability((PciExpressDeviceSerialNumberCapability *)capability,                                                     capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::POWER_BUDGETING:                                   UEFI_ASSERT_EXECUTION(initPciExpressPowerBudgetingCapability((PciExpressPowerBudgetingCapability *)capability,                                                             capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::ROOT_COMPLEX_LINK_DECLARATION:                     UEFI_ASSERT_EXECUTION(initPciExpressRootComplexLinkDeclarationCapability((PciExpressRootComplexLinkDeclarationCapability *)capability,                                     capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::ROOT_COMPLEX_INTERNAL_LINK_CONTROL:                UEFI_ASSERT_EXECUTION(initPciExpressRootComplexInternalLinkControlCapability((PciExpressRootComplexInternalLinkControlCapability *)capability,                             capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::ROOT_COMPLEX_EVENT_COLLECTOR_ENDPOINT_ASSOCIATION: UEFI_ASSERT_EXECUTION(initPciExpressRootComplexEventCollectorEndpointAssociationCapability((PciExpressRootComplexEventCollectorEndpointAssociationCapability *)capability, capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::RCRB_HEADER:                                       UEFI_ASSERT_EXECUTION(initPciExpressRcrbHeaderCapability((PciExpressRcrbHeaderCapability *)capability,                                                                     capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::VENDOR_SPECIFIC:                                   UEFI_ASSERT_EXECUTION(initPciExpressVendorSpecificCapability((PciExpressVendorSpecificCapability *)capability,                                                             capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::ACCESS_CONTROL_SERVICES:                           UEFI_ASSERT_EXECUTION(initPciExpressAccessControlServicesCapability((PciExpressAccessControlServicesCapability *)capability,                                               capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::ARI_CAPABILITY:                                    UEFI_ASSERT_EXECUTION(initPciExpressAriCapability((PciExpressAriCapability *)capability,                                                                                   capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::MULTICAST:                                         UEFI_ASSERT_EXECUTION(initPciExpressMulticastCapability((PciExpressMulticastCapability *)capability,                                                                       capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::RESIZABLE_BAR:                                     UEFI_ASSERT_EXECUTION(initPciExpressResizableBaseAddressCapability((PciExpressResizableBaseAddressCapability *)capability,                                                 capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::DYNAMIC_POWER_ALLOCATION:                          UEFI_ASSERT_EXECUTION(initPciExpressDynamicPowerAllocationCapability((PciExpressDynamicPowerAllocationCapability *)capability,                                             capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::TPH_REQUESTER:                                     UEFI_ASSERT_EXECUTION(initPciExpressTphRequesterCapability((PciExpressTphRequesterCapability *)capability,                                                                 capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciExtendedCapabilityType::LATENCY_TOLERANCE_REPORTING:                       UEFI_ASSERT_EXECUTION(initPciExpressLatencyToleranceReportingCapability((PciExpressLatencyToleranceReportingCapability *)capability,                                       capability->capabilityVersion, deviceManagerEntry), NgosStatus::ASSERTION); break;

        default:
        {
            UEFI_LF(("Unknown PCI extended capability %s", enumToFullString((PciExtendedCapabilityType)capability->capabilityId)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressAdvancedErrorReportingCapability(PciExpressAdvancedErrorReportingCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability != nullptr,                            "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion >= 1 && capabilityVersion <= 2, "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr,                    "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->uncorrectableErrorStatus                                           = %s",     flagsToFullString(capability->uncorrectableErrorStatus)));
        UEFI_LVVV(("capability->uncorrectableErrorMask                                             = %s",     flagsToFullString(capability->uncorrectableErrorMask)));
        UEFI_LVVV(("capability->uncorrectableErrorSeverity                                         = %s",     flagsToFullString(capability->uncorrectableErrorSeverity)));
        UEFI_LVVV(("capability->correctableErrorStatus                                             = %s",     flagsToFullString(capability->correctableErrorStatus)));
        UEFI_LVVV(("capability->correctableErrorMask                                               = %s",     flagsToFullString(capability->correctableErrorMask)));
        UEFI_LVVV(("capability->advancedErrorCapabilitiesAndControl.firstErrorPointer              = %u",     capability->advancedErrorCapabilitiesAndControl.firstErrorPointer));
        UEFI_LVVV(("capability->advancedErrorCapabilitiesAndControl.ecrcGenerationCapable          = %u",     capability->advancedErrorCapabilitiesAndControl.ecrcGenerationCapable));
        UEFI_LVVV(("capability->advancedErrorCapabilitiesAndControl.ecrcGenerationEnable           = %u",     capability->advancedErrorCapabilitiesAndControl.ecrcGenerationEnable));
        UEFI_LVVV(("capability->advancedErrorCapabilitiesAndControl.ecrcCheckCapable               = %u",     capability->advancedErrorCapabilitiesAndControl.ecrcCheckCapable));
        UEFI_LVVV(("capability->advancedErrorCapabilitiesAndControl.ecrcCheckEnable                = %u",     capability->advancedErrorCapabilitiesAndControl.ecrcCheckEnable));
        UEFI_LVVV(("capability->advancedErrorCapabilitiesAndControl.multipleHeaderRecordingCapable = %u",     capability->advancedErrorCapabilitiesAndControl.multipleHeaderRecordingCapable));
        UEFI_LVVV(("capability->advancedErrorCapabilitiesAndControl.multipleHeaderRecordingEnable  = %u",     capability->advancedErrorCapabilitiesAndControl.multipleHeaderRecordingEnable));
        UEFI_LVVV(("capability->advancedErrorCapabilitiesAndControl.tlpPrefixLogPresent            = %u",     capability->advancedErrorCapabilitiesAndControl.tlpPrefixLogPresent));
        UEFI_LVVV(("capability->advancedErrorCapabilitiesAndControl.value32                        = 0x%08X", capability->advancedErrorCapabilitiesAndControl.value32));
        UEFI_LVVV(("capability->headerLog[0]                                                       = 0x%08X", capability->headerLog[0]));
        UEFI_LVVV(("capability->headerLog[1]                                                       = 0x%08X", capability->headerLog[1]));
        UEFI_LVVV(("capability->headerLog[2]                                                       = 0x%08X", capability->headerLog[2]));
        UEFI_LVVV(("capability->headerLog[3]                                                       = 0x%08X", capability->headerLog[3]));
        UEFI_LVVV(("capability->rootErrorCommand                                                   = %s",     flagsToFullString(capability->rootErrorCommand)));
        UEFI_LVVV(("capability->rootErrorStatus.errCorReceived                                     = %u",     capability->rootErrorStatus.errCorReceived));
        UEFI_LVVV(("capability->rootErrorStatus.multipleErrCorReceived                             = %u",     capability->rootErrorStatus.multipleErrCorReceived));
        UEFI_LVVV(("capability->rootErrorStatus.errFatalOrNonFatalReceived                         = %u",     capability->rootErrorStatus.errFatalOrNonFatalReceived));
        UEFI_LVVV(("capability->rootErrorStatus.multipleErrFatalOrNonFatalReceived                 = %u",     capability->rootErrorStatus.multipleErrFatalOrNonFatalReceived));
        UEFI_LVVV(("capability->rootErrorStatus.firstUncorrectableFatal                            = %u",     capability->rootErrorStatus.firstUncorrectableFatal));
        UEFI_LVVV(("capability->rootErrorStatus.nonFatalErrorMessagesReceived                      = %u",     capability->rootErrorStatus.nonFatalErrorMessagesReceived));
        UEFI_LVVV(("capability->rootErrorStatus.fatalErrorMessagesReceived                         = %u",     capability->rootErrorStatus.fatalErrorMessagesReceived));
        UEFI_LVVV(("capability->rootErrorStatus.advancedErrorInterruptMessageNumber                = %u",     capability->rootErrorStatus.advancedErrorInterruptMessageNumber));
        UEFI_LVVV(("capability->rootErrorStatus.value32                                            = 0x%08X", capability->rootErrorStatus.value32));
        UEFI_LVVV(("capability->errorSourceIdentification                                          = 0x%04X", capability->errorSourceIdentification));
        UEFI_LVVV(("capability->correctableErrorSourceIdentification                               = 0x%04X", capability->correctableErrorSourceIdentification));



        if (capabilityVersion >= 2)
        {
            UEFI_LVVV(("capability->tlpPrefixLog[0] = 0x%08X", capability->tlpPrefixLog[0]));
            UEFI_LVVV(("capability->tlpPrefixLog[1] = 0x%08X", capability->tlpPrefixLog[1]));
            UEFI_LVVV(("capability->tlpPrefixLog[2] = 0x%08X", capability->tlpPrefixLog[2]));
            UEFI_LVVV(("capability->tlpPrefixLog[3] = 0x%08X", capability->tlpPrefixLog[3]));
        }
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Advanced error reporting");



        // Uncorrectable / Correctable error
        {
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Uncorrectable error status",   capability->uncorrectableErrorStatus,   "0x%04X", PciExpressUncorrectableErrorFlag, DeviceManagerMode::EXPERT);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Uncorrectable error mask",     capability->uncorrectableErrorMask,     "0x%04X", PciExpressUncorrectableErrorFlag, DeviceManagerMode::EXPERT);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Uncorrectable error severity", capability->uncorrectableErrorSeverity, "0x%04X", PciExpressUncorrectableErrorFlag, DeviceManagerMode::EXPERT);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Correctable error status",     capability->correctableErrorStatus,     "0x%04X", PciExpressCorrectableErrorFlag,   DeviceManagerMode::EXPERT);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Correctable error mask",       capability->correctableErrorMask,       "0x%04X", PciExpressCorrectableErrorFlag,   DeviceManagerMode::EXPERT);
        }



        // Advanced error capabilities and control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Advanced error capabilities and control",                                    mprintf("0x%08X", capability->advancedErrorCapabilitiesAndControl.value32),                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Advanced error capabilities and control: First error pointer",               mprintf("%u",     capability->advancedErrorCapabilitiesAndControl.firstErrorPointer),          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Advanced error capabilities and control: ECRC generation capable",           capability->advancedErrorCapabilitiesAndControl.ecrcGenerationCapable          ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Advanced error capabilities and control: ECRC generation enable",            capability->advancedErrorCapabilitiesAndControl.ecrcGenerationEnable           ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Advanced error capabilities and control: ECRC check capable",                capability->advancedErrorCapabilitiesAndControl.ecrcCheckCapable               ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Advanced error capabilities and control: ECRC check enable",                 capability->advancedErrorCapabilitiesAndControl.ecrcCheckEnable                ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Advanced error capabilities and control: Multiple header recording capable", capability->advancedErrorCapabilitiesAndControl.multipleHeaderRecordingCapable ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Advanced error capabilities and control: Multiple header recording enable",  capability->advancedErrorCapabilitiesAndControl.multipleHeaderRecordingEnable  ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Advanced error capabilities and control: TLP prefix log present",            capability->advancedErrorCapabilitiesAndControl.tlpPrefixLogPresent            ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Header log
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header log #0", mprintf("0x%08X", capability->headerLog[0]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header log #1", mprintf("0x%08X", capability->headerLog[1]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header log #2", mprintf("0x%08X", capability->headerLog[2]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header log #3", mprintf("0x%08X", capability->headerLog[3]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Root error command", capability->rootErrorCommand, "0x%04X", PciExpressRootErrorCommandFlag, DeviceManagerMode::EXPERT);



        // Root error status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root error status",                                          mprintf("0x%08X", capability->rootErrorStatus.value32),                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root error status: ERR_COR received",                        capability->rootErrorStatus.errCorReceived                     ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root error status: Multiple ERR_COR received",               capability->rootErrorStatus.multipleErrCorReceived             ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root error status: ERR_FATAL/NONFATAL received",             capability->rootErrorStatus.errFatalOrNonFatalReceived         ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root error status: Multiple ERR_FATAL/NONFATAL received",    capability->rootErrorStatus.multipleErrFatalOrNonFatalReceived ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root error status: First uncorrectable fatal",               capability->rootErrorStatus.firstUncorrectableFatal            ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root error status: Non-Fatal error messages received",       capability->rootErrorStatus.nonFatalErrorMessagesReceived      ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root error status: Fatal error messages received",           capability->rootErrorStatus.fatalErrorMessagesReceived         ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root error status: Advanced error interrupt message number", mprintf("%u",     capability->rootErrorStatus.advancedErrorInterruptMessageNumber), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error source identification",             mprintf("0x%04X", capability->errorSourceIdentification),            DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Correctable error source identification", mprintf("0x%04X", capability->correctableErrorSourceIdentification), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }



        // TLP prefix log
        {
            if (capabilityVersion >= 2)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("TLP prefix log #0", mprintf("0x%08X", capability->tlpPrefixLog[0]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("TLP prefix log #1", mprintf("0x%08X", capability->tlpPrefixLog[1]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("TLP prefix log #2", mprintf("0x%08X", capability->tlpPrefixLog[2]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("TLP prefix log #3", mprintf("0x%08X", capability->tlpPrefixLog[3]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            }
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressVirtualChannelCapability(PciExpressVirtualChannelCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    PciExpressVirtualChannelArbitrationCapabilityFlags virtualChannelArbitrationCapability(capability->portVirtualChannelCapability2.virtualChannelArbitrationCapability);



    // Validation
    {
        UEFI_LVVV(("capability->portVirtualChannelCapability1.extendedVirtualChannelCount            = %u",     capability->portVirtualChannelCapability1.extendedVirtualChannelCount));
        UEFI_LVVV(("capability->portVirtualChannelCapability1.lowPriorityExtendedVirtualChannelCount = %u",     capability->portVirtualChannelCapability1.lowPriorityExtendedVirtualChannelCount));
        UEFI_LVVV(("capability->portVirtualChannelCapability1.referenceClock                         = %s",     enumToFullString((PciExpressVirtualChannelReferenceClock)capability->portVirtualChannelCapability1.referenceClock)));
        UEFI_LVVV(("capability->portVirtualChannelCapability1.portArbitrationTableEntrySize          = %s",     enumToFullString((PciExpressVirtualChannelPortArbitrationTableEntrySize)capability->portVirtualChannelCapability1.portArbitrationTableEntrySize)));
        UEFI_LVVV(("capability->portVirtualChannelCapability1.value32                                = 0x%08X", capability->portVirtualChannelCapability1.value32));
        UEFI_LVVV(("capability->portVirtualChannelCapability2.virtualChannelArbitrationCapability    = %s",     flagsToFullString(virtualChannelArbitrationCapability)));
        UEFI_LVVV(("capability->portVirtualChannelCapability2.virtualChannelArbitrationTableOffset   = %u",     capability->portVirtualChannelCapability2.virtualChannelArbitrationTableOffset));
        UEFI_LVVV(("capability->portVirtualChannelCapability2.value32                                = 0x%08X", capability->portVirtualChannelCapability2.value32));
        UEFI_LVVV(("capability->portVirtualChannelControl.loadVirtualChannelArbitrationTable         = %u",     capability->portVirtualChannelControl.loadVirtualChannelArbitrationTable));
        UEFI_LVVV(("capability->portVirtualChannelControl.virtualChannelArbitrationSelect            = %s",     enumToFullString((PciExpressVirtualChannelArbitrationSelect)capability->portVirtualChannelControl.virtualChannelArbitrationSelect)));
        UEFI_LVVV(("capability->portVirtualChannelControl.value16                                    = 0x%04X", capability->portVirtualChannelControl.value16));
        UEFI_LVVV(("capability->portVirtualChannelStatus                                             = %s",     flagsToFullString(capability->portVirtualChannelStatus)));



        for (i64 i = 0; i < capability->portVirtualChannelCapability1.extendedVirtualChannelCount; ++i)
        {
            PciExpressVirtualChannelPortArbitrationCapabilityFlags portArbitrationCapability(capability->capability[i].virtualChannelResourceCapability.portArbitrationCapability);

            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceCapability.portArbitrationCapability  = %s",     i, flagsToFullString(portArbitrationCapability)));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceCapability.rejectSnoopTransactions    = %u",     i, capability->capability[i].virtualChannelResourceCapability.rejectSnoopTransactions));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceCapability.maximumTimeSlots           = %u",     i, capability->capability[i].virtualChannelResourceCapability.maximumTimeSlots));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceCapability.portArbitrationTableOffset = %u",     i, capability->capability[i].virtualChannelResourceCapability.portArbitrationTableOffset));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceCapability.value32                    = 0x%08X", i, capability->capability[i].virtualChannelResourceCapability.value32));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceControl.tcVcMap                       = 0x%02X", i, capability->capability[i].virtualChannelResourceControl.tcVcMap));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceControl.loadPortArbitrationTable      = %u",     i, capability->capability[i].virtualChannelResourceControl.loadPortArbitrationTable));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceControl.portArbitrationSelect         = %s",     i, enumToFullString((PciExpressVirtualChannelPortArbitrationSelect)capability->capability[i].virtualChannelResourceControl.portArbitrationSelect)));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceControl.virtualChannelId              = %u",     i, capability->capability[i].virtualChannelResourceControl.virtualChannelId));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceControl.virtualChannelEnable          = %u",     i, capability->capability[i].virtualChannelResourceControl.virtualChannelEnable));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceControl.value32                       = 0x%08X", i, capability->capability[i].virtualChannelResourceControl.value32));
            UEFI_LVVV(("capability->capability[%d].virtualChannelResourceStatus                                = %s",     i, flagsToFullString(capability->capability[i].virtualChannelResourceStatus)));
        }
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Virtual channel");



        // Port virtual channel capability 1
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel capability 1",                                              mprintf("0x%08X", capability->portVirtualChannelCapability1.value32),                                                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel capability 1: Extended virtual channel count",              mprintf("%u",     capability->portVirtualChannelCapability1.extendedVirtualChannelCount),                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel capability 1: Low priority extended virtual channel count", mprintf("%u",     capability->portVirtualChannelCapability1.lowPriorityExtendedVirtualChannelCount),                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel capability 1: Reference clock",                             strdup(enumToFullString((PciExpressVirtualChannelReferenceClock)capability->portVirtualChannelCapability1.referenceClock)),                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel capability 1: Port arbitration table entry size",           strdup(enumToFullString((PciExpressVirtualChannelPortArbitrationTableEntrySize)capability->portVirtualChannelCapability1.portArbitrationTableEntrySize)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Port virtual channel capability 2
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel capability 2", mprintf("0x%08X", capability->portVirtualChannelCapability2.value32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Port virtual channel capability 2: Virtual channel arbitration capability", virtualChannelArbitrationCapability, "0x%02X", PciExpressVirtualChannelArbitrationCapabilityFlag, DeviceManagerMode::EXPERT);

            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel capability 2: Virtual channel arbitration table offset", mprintf("%u", capability->portVirtualChannelCapability2.virtualChannelArbitrationTableOffset), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        }



        // Port virtual channel control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel control",                                         mprintf("0x%04X", capability->portVirtualChannelControl.value16),                                                                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel control: Load virtual channel arbitration table", capability->portVirtualChannelControl.loadVirtualChannelArbitrationTable ? "Yes" : "No",                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port virtual channel control: Virtual channel arbitration select",     strdup(enumToFullString((PciExpressVirtualChannelArbitrationSelect)capability->portVirtualChannelControl.virtualChannelArbitrationSelect)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Port virtual channel status", capability->portVirtualChannelStatus, "0x%04X", PciExpressVirtualChannelPortVirtualChannelStatusFlag, DeviceManagerMode::BASIC);



        for (i64 i = 0; i < capability->portVirtualChannelCapability1.extendedVirtualChannelCount; ++i)
        {
            PciExpressVirtualChannelPortArbitrationCapabilityFlags portArbitrationCapability(capability->capability[i].virtualChannelResourceCapability.portArbitrationCapability);



            // Capability virtual channel resource capability
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource capability", i), mprintf("0x%08X", capability->capability[i].virtualChannelResourceCapability.value32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

                ADD_RECORDS_FOR_FLAGS_CYCLE(deviceManagerEntry, "Capability #%d virtual channel resource capability: Port arbitration capability", i, portArbitrationCapability, "0x%02X", PciExpressVirtualChannelPortArbitrationCapabilityFlag, DeviceManagerMode::EXPERT);

                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource capability: Reject snoop transactions",     i), capability->capability[i].virtualChannelResourceCapability.rejectSnoopTransactions ? "Yes" : "No",    DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource capability: Maximum time slots",            i), mprintf("%u", capability->capability[i].virtualChannelResourceCapability.maximumTimeSlotsReal()),     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource capability: Port arbitration table offset", i), mprintf("%u", capability->capability[i].virtualChannelResourceCapability.portArbitrationTableOffset), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            }



            // Capability virtual channel resource control
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource control",                              i), mprintf("0x%08X", capability->capability[i].virtualChannelResourceControl.value32),                                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource control: TC/VC map",                   i), mprintf("0x%02X", capability->capability[i].virtualChannelResourceControl.tcVcMap),                                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource control: load port arbitration table", i), capability->capability[i].virtualChannelResourceControl.loadPortArbitrationTable ? "Yes" : "No",                                                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource control: Port arbitration select",     i), strdup(enumToFullString((PciExpressVirtualChannelPortArbitrationSelect)capability->capability[i].virtualChannelResourceControl.portArbitrationSelect)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource control: Virtual channel ID",          i), mprintf("%u",     capability->capability[i].virtualChannelResourceControl.virtualChannelId),                                                            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Capability #%d virtual channel resource control: Virtual channel enable",      i), capability->capability[i].virtualChannelResourceControl.virtualChannelEnable ? "Yes" : "No",                                                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            }



            ADD_RECORDS_FOR_FLAGS_CYCLE(deviceManagerEntry, "Capability #%d virtual channel resource status", i, capability->capability[i].virtualChannelResourceStatus, "0x%04X", PciExpressVirtualChannelVirtualChannelResourceStatusFlag, DeviceManagerMode::BASIC);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressDeviceSerialNumberCapability(PciExpressDeviceSerialNumberCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->serialNumber = 0x%016llX", capability->serialNumber));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Device serial number");



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number", mprintf("%016llX", capability->serialNumber), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressPowerBudgetingCapability(PciExpressPowerBudgetingCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->dataSelect            = %u",     capability->dataSelect));
        UEFI_LVVV(("capability->data.basePower        = %u",     capability->data.basePower));
        UEFI_LVVV(("capability->data.dataScale        = %s",     enumToFullString((PciExpressPowerScale)capability->data.dataScale)));
        UEFI_LVVV(("capability->data.pmSubState       = %s",     enumToFullString((PciExpressPowerBudgetingPowerManagementSubState)capability->data.pmSubState)));
        UEFI_LVVV(("capability->data.pmState          = %s",     enumToFullString((PciExpressPowerBudgetingPowerManagementState)capability->data.pmState)));
        UEFI_LVVV(("capability->data.type             = %s",     enumToFullString((PciExpressPowerBudgetingType)capability->data.type)));
        UEFI_LVVV(("capability->data.powerRail        = %s",     enumToFullString((PciExpressPowerBudgetingPowerRail)capability->data.powerRail)));
        UEFI_LVVV(("capability->data.value32          = 0x%08X", capability->data.value32));
        UEFI_LVVV(("capability->powerBudgetCapability = %s",     flagsToFullString(capability->powerBudgetCapability)));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Power budgeting");



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data select", mprintf("%u", capability->dataSelect), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        // Data
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data",               mprintf("0x%08X", capability->data.value32),                                                            DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data: Base power",   mprintf("%u",     capability->data.basePower),                                                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data: Data scale",   strdup(enumToFullString((PciExpressPowerScale)capability->data.dataScale)),                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data: PM sub state", strdup(enumToFullString((PciExpressPowerBudgetingPowerManagementSubState)capability->data.pmSubState)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data: PM state",     strdup(enumToFullString((PciExpressPowerBudgetingPowerManagementState)capability->data.pmState)),       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data: Type",         strdup(enumToFullString((PciExpressPowerBudgetingType)capability->data.type)),                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data: Power rail",   strdup(enumToFullString((PciExpressPowerBudgetingPowerRail)capability->data.powerRail)),                DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Power budget capability", capability->powerBudgetCapability, "0x%02X", PciExpressPowerBudgetingCapabilityFlag, DeviceManagerMode::EXPERT);
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressRootComplexLinkDeclarationCapability(PciExpressRootComplexLinkDeclarationCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->elementSelfDescription.elementType         = %s",     enumToFullString((PciExpressRootComplexLinkDeclarationElementType)capability->elementSelfDescription.elementType)));
        UEFI_LVVV(("capability->elementSelfDescription.numberOfLinkEntries = %u",     capability->elementSelfDescription.numberOfLinkEntries));
        UEFI_LVVV(("capability->elementSelfDescription.componentId         = %u",     capability->elementSelfDescription.componentId));
        UEFI_LVVV(("capability->elementSelfDescription.portNumber          = %u",     capability->elementSelfDescription.portNumber));
        UEFI_LVVV(("capability->elementSelfDescription.value32             = 0x%08X", capability->elementSelfDescription.value32));



        for (i64 i = 0; i < capability->elementSelfDescription.numberOfLinkEntries; ++i)
        {
            UEFI_LVVV(("capability->linkEntry[%d].linkDescription.linkValid           = %u",     i, capability->linkEntry[i].linkDescription.linkValid));
            UEFI_LVVV(("capability->linkEntry[%d].linkDescription.linkType            = %s",     i, enumToFullString((PciExpressRootComplexLinkDeclarationLinkType)capability->linkEntry[i].linkDescription.linkType)));
            UEFI_LVVV(("capability->linkEntry[%d].linkDescription.associateRcrbHeader = %u",     i, capability->linkEntry[i].linkDescription.associateRcrbHeader));
            UEFI_LVVV(("capability->linkEntry[%d].linkDescription.targetComponentId   = %u",     i, capability->linkEntry[i].linkDescription.targetComponentId));
            UEFI_LVVV(("capability->linkEntry[%d].linkDescription.targetPortNumber    = %u",     i, capability->linkEntry[i].linkDescription.targetPortNumber));
            UEFI_LVVV(("capability->linkEntry[%d].linkDescription.value32             = 0x%08X", i, capability->linkEntry[i].linkDescription.value32));



            switch ((PciExpressRootComplexLinkDeclarationLinkType)capability->linkEntry[i].linkDescription.linkType)
            {
                case PciExpressRootComplexLinkDeclarationLinkType::LINK_TO_MEMORY_MAPPED_SPACE:
                {
                    UEFI_LVVV(("capability->linkEntry[%d].linkAddress.memoryMappedSpace.lower32 = 0x%08X", i, capability->linkEntry[i].linkAddress.memoryMappedSpace.lower32));
                    UEFI_LVVV(("capability->linkEntry[%d].linkAddress.memoryMappedSpace.upper32 = 0x%08X", i, capability->linkEntry[i].linkAddress.memoryMappedSpace.upper32));
                }
                break;

                case PciExpressRootComplexLinkDeclarationLinkType::LINK_TO_CONFIGURATION_SPACE:
                {
                    UEFI_LVVV(("capability->linkEntry[%d].linkAddress.configurationSpace.encodedNumberOfBusNumberBits  = %u",        i, capability->linkEntry[i].linkAddress.configurationSpace.encodedNumberOfBusNumberBitsReal()));
                    UEFI_LVVV(("capability->linkEntry[%d].linkAddress.configurationSpace.functionNumber                = %u",        i, capability->linkEntry[i].linkAddress.configurationSpace.functionNumber));
                    UEFI_LVVV(("capability->linkEntry[%d].linkAddress.configurationSpace.deviceNumber                  = %u",        i, capability->linkEntry[i].linkAddress.configurationSpace.deviceNumber));
                    UEFI_LVVV(("capability->linkEntry[%d].linkAddress.configurationSpace.busNumber                     = %u",        i, capability->linkEntry[i].linkAddress.configurationSpace.busNumberReal()));
                    UEFI_LVVV(("capability->linkEntry[%d].linkAddress.configurationSpace.configurationSpaceBaseAddress = 0x%016llX", i, capability->linkEntry[i].linkAddress.configurationSpace.configurationSpaceBaseAddressReal()));
                    UEFI_LVVV(("capability->linkEntry[%d].linkAddress.configurationSpace.value64                       = 0x%016llX", i, capability->linkEntry[i].linkAddress.configurationSpace.value64));
                }
                break;

                default:
                {
                    UEFI_LF(("Unknown Pci Express root complex link declaration link type %s", enumToFullString((PciExpressRootComplexLinkDeclarationLinkType)capability->linkEntry[i].linkDescription.linkType)));
                }
                break;
            }
        }
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Root complex link declaration");



        // Element self description
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Element self description",                         mprintf("0x%08X", capability->elementSelfDescription.value32),                                                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Element self description: Element type",           strdup(enumToFullString((PciExpressRootComplexLinkDeclarationElementType)capability->elementSelfDescription.elementType)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Element self description: Number of link entries", mprintf("%u",     capability->elementSelfDescription.numberOfLinkEntries),                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Element self description: Component ID",           mprintf("%u",     capability->elementSelfDescription.componentId),                                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Element self description: Port number",            mprintf("%u",     capability->elementSelfDescription.portNumber),                                                          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        for (i64 i = 0; i < capability->elementSelfDescription.numberOfLinkEntries; ++i)
        {
            // Link entry link description
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link description",                        i), mprintf("0x%08X", capability->linkEntry[i].linkDescription.value32),                                                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link description: Link valid",            i), capability->linkEntry[i].linkDescription.linkValid ? "Yes" : "No",                                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link description: Link type",             i), strdup(enumToFullString((PciExpressRootComplexLinkDeclarationLinkType)capability->linkEntry[i].linkDescription.linkType)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link description: Associate RCRB header", i), capability->linkEntry[i].linkDescription.associateRcrbHeader ? "Yes" : "No",                                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link description: Target component ID",   i), mprintf("%u",     capability->linkEntry[i].linkDescription.targetComponentId),                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link description: Target port number",    i), mprintf("%u",     capability->linkEntry[i].linkDescription.targetPortNumber),                                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            }



            // Link entry link address
            {
                switch ((PciExpressRootComplexLinkDeclarationLinkType)capability->linkEntry[i].linkDescription.linkType)
                {
                    case PciExpressRootComplexLinkDeclarationLinkType::LINK_TO_MEMORY_MAPPED_SPACE:
                    {
                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link address: Lower 32 bits", i), mprintf("0x%08X", capability->linkEntry[i].linkAddress.memoryMappedSpace.lower32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link address: Upper 32 bits", i), mprintf("0x%08X", capability->linkEntry[i].linkAddress.memoryMappedSpace.upper32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                    }
                    break;

                    case PciExpressRootComplexLinkDeclarationLinkType::LINK_TO_CONFIGURATION_SPACE:
                    {
                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link address",                                    i), mprintf("0x%016llX", capability->linkEntry[i].linkAddress.configurationSpace.value64),                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link address: Encoded number of bus number bits", i), mprintf("%u",        capability->linkEntry[i].linkAddress.configurationSpace.encodedNumberOfBusNumberBitsReal()),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link address: Function number",                   i), mprintf("%u",        capability->linkEntry[i].linkAddress.configurationSpace.functionNumber),                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link address: Device number",                     i), mprintf("%u",        capability->linkEntry[i].linkAddress.configurationSpace.deviceNumber),                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link address: Bus number",                        i), mprintf("%u",        capability->linkEntry[i].linkAddress.configurationSpace.busNumberReal()),                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Link entry #%d link address: Configuration space base address",  i), mprintf("0x%016llX", capability->linkEntry[i].linkAddress.configurationSpace.configurationSpaceBaseAddressReal()), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                    }
                    break;

                    default:
                    {
                        UEFI_LF(("Unknown Pci Express root complex link declaration link type %s", enumToFullString((PciExpressRootComplexLinkDeclarationLinkType)capability->linkEntry[i].linkDescription.linkType)));
                    }
                    break;
                }
            }
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressRootComplexInternalLinkControlCapability(PciExpressRootComplexInternalLinkControlCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->rootComplexLinkCapabilities.supportedLinkSpeeds = %s",     enumToFullString((PciExpressLinkSpeed)capability->rootComplexLinkCapabilities.supportedLinkSpeeds)));
        UEFI_LVVV(("capability->rootComplexLinkCapabilities.maximumLinkWidth    = %s",     enumToFullString((PciExpressLinkWidth)capability->rootComplexLinkCapabilities.maximumLinkWidth)));
        UEFI_LVVV(("capability->rootComplexLinkCapabilities.aspmSupport         = %s",     enumToFullString((PciExpressActiveStatePowerManagementSupport)capability->rootComplexLinkCapabilities.aspmSupport)));
        UEFI_LVVV(("capability->rootComplexLinkCapabilities.l0sExitLatency      = %s",     enumToFullString((PciExpressL0sExitLatency)capability->rootComplexLinkCapabilities.l0sExitLatency)));
        UEFI_LVVV(("capability->rootComplexLinkCapabilities.l1ExitLatency       = %s",     enumToFullString((PciExpressL1ExitLatency)capability->rootComplexLinkCapabilities.l1ExitLatency)));
        UEFI_LVVV(("capability->rootComplexLinkCapabilities.value32             = 0x%08X", capability->rootComplexLinkCapabilities.value32));
        UEFI_LVVV(("capability->rootComplexLinkControl.aspmControl              = %s",     enumToFullString((PciExpressActiveStatePowerManagementControl)capability->rootComplexLinkControl.aspmControl)));
        UEFI_LVVV(("capability->rootComplexLinkControl.extendedSynch            = %u",     capability->rootComplexLinkControl.extendedSynch));
        UEFI_LVVV(("capability->rootComplexLinkControl.value16                  = 0x%04X", capability->rootComplexLinkControl.value16));
        UEFI_LVVV(("capability->rootComplexLinkStatus.currentLinkSpeed          = %s",     enumToFullString((PciExpressLinkSpeed)capability->rootComplexLinkStatus.currentLinkSpeed)));
        UEFI_LVVV(("capability->rootComplexLinkStatus.negotiatedLinkWidth       = %s",     enumToFullString((PciExpressLinkWidth)capability->rootComplexLinkStatus.negotiatedLinkWidth)));
        UEFI_LVVV(("capability->rootComplexLinkStatus.value16                   = 0x%04X", capability->rootComplexLinkStatus.value16));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Root complex internal link control");



        // Root complex link capabilities
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link capabilities",                        mprintf("0x%08X", capability->rootComplexLinkCapabilities.value32),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link capabilities: Supported link speeds", strdup(enumToFullString((PciExpressLinkSpeed)capability->rootComplexLinkCapabilities.supportedLinkSpeeds)),                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link capabilities: Maximum link width",    strdup(enumToFullString((PciExpressLinkWidth)capability->rootComplexLinkCapabilities.maximumLinkWidth)),                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link capabilities: ASPM support",          strdup(enumToFullString((PciExpressActiveStatePowerManagementSupport)capability->rootComplexLinkCapabilities.aspmSupport)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link capabilities: L0s exit latency",      strdup(enumToFullString((PciExpressL0sExitLatency)capability->rootComplexLinkCapabilities.l0sExitLatency)),                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link capabilities: L1 exit latency",       strdup(enumToFullString((PciExpressL1ExitLatency)capability->rootComplexLinkCapabilities.l1ExitLatency)),                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Root complex link control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link control",                 mprintf("0x%04X", capability->rootComplexLinkControl.value16),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link control: ASPM control",   strdup(enumToFullString((PciExpressActiveStatePowerManagementControl)capability->rootComplexLinkControl.aspmControl)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link control: Extended synch", capability->rootComplexLinkControl.extendedSynch ? "Yes" : "No",                                                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Root complex link status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link status",                        mprintf("0x%04X", capability->rootComplexLinkStatus.value16),                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link status: Current link speed",    strdup(enumToFullString((PciExpressLinkSpeed)capability->rootComplexLinkStatus.currentLinkSpeed)),    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Root complex link status: Negotiated link width", strdup(enumToFullString((PciExpressLinkWidth)capability->rootComplexLinkStatus.negotiatedLinkWidth)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressRootComplexEventCollectorEndpointAssociationCapability(PciExpressRootComplexEventCollectorEndpointAssociationCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->associationBitmapForRootComplexIntegratedDevices = 0x%08X", capability->associationBitmapForRootComplexIntegratedDevices));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Root complex event collector endpoint association");



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Association bitmap for root complex integrated devices", mprintf("0x%08X", capability->associationBitmapForRootComplexIntegratedDevices), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressRcrbHeaderCapability(PciExpressRcrbHeaderCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->vendorId     = 0x%04X (%s)", capability->vendorId, enumToHumanString(capability->vendorId)));
        UEFI_LVVV(("capability->deviceId     = 0x%04X (%s)", capability->deviceId, enumToHumanString(capability->vendorId, capability->deviceId)));
        UEFI_LVVV(("capability->capabilities = %s",          flagsToFullString(capability->capabilities)));
        UEFI_LVVV(("capability->control      = %s",          flagsToFullString(capability->control)));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "RCRB");



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor",      enumToHumanString(capability->vendorId),                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device name", enumToHumanString(capability->vendorId, capability->deviceId), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor ID",   mprintf("0x%04X", capability->vendorId),                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device ID",   mprintf("0x%04X", capability->deviceId),                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Capabilities", capability->capabilities, "0x%08X", PciExpressRcrbHeaderCapabilitiesFlag, DeviceManagerMode::BASIC);
            ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Control",      capability->control,      "0x%08X", PciExpressRcrbHeaderControlFlag,      DeviceManagerMode::BASIC);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressVendorSpecificCapability(PciExpressVendorSpecificCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->vendorSpecificHeader.id       = %u",     capability->vendorSpecificHeader.id));
        UEFI_LVVV(("capability->vendorSpecificHeader.revision = %u",     capability->vendorSpecificHeader.revision));
        UEFI_LVVV(("capability->vendorSpecificHeader.length   = %u",     capability->vendorSpecificHeader.length));
        UEFI_LVVV(("capability->vendorSpecificHeader.value32  = 0x%08X", capability->vendorSpecificHeader.value32));
    }



    // Fill Device Manager entry
    {
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Vendor specific");



        // Header
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header",           mprintf("0x%08X", capability->vendorSpecificHeader.value32),  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header: ID",       mprintf("%u",     capability->vendorSpecificHeader.id),       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header: Revision", mprintf("%u",     capability->vendorSpecificHeader.revision), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header: Length",   mprintf("%u",     capability->vendorSpecificHeader.length),   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressAccessControlServicesCapability(PciExpressAccessControlServicesCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    u8 numberOfWords = capability->capability.egressControlVectorSizeNumberOfWords();



    // Validation
    {
        UEFI_LVVV(("capability->capability.acsSourceValidation      = %u",     capability->capability.acsSourceValidation));
        UEFI_LVVV(("capability->capability.acsTranslationBlocking   = %u",     capability->capability.acsTranslationBlocking));
        UEFI_LVVV(("capability->capability.acsP2pRequestRedirect    = %u",     capability->capability.acsP2pRequestRedirect));
        UEFI_LVVV(("capability->capability.acsP2pCompletionRedirect = %u",     capability->capability.acsP2pCompletionRedirect));
        UEFI_LVVV(("capability->capability.acsUpstreamForwarding    = %u",     capability->capability.acsUpstreamForwarding));
        UEFI_LVVV(("capability->capability.acsP2pEgressControl      = %u",     capability->capability.acsP2pEgressControl));
        UEFI_LVVV(("capability->capability.acsDirectTranslatedP2p   = %u",     capability->capability.acsDirectTranslatedP2p));
        UEFI_LVVV(("capability->capability.egressControlVectorSize  = %u",     capability->capability.egressControlVectorSizeReal()));
        UEFI_LVVV(("capability->capability.value16                  = 0x%04X", capability->capability.value16));
        UEFI_LVVV(("capability->control                             = %s",     flagsToFullString(capability->control)));
        UEFI_LVVV(("numberOfWords                                   = %u",     numberOfWords));



        if (capability->capability.acsP2pEgressControl)
        {
            for (i64 i = 0; i < numberOfWords; ++i)
            {
                UEFI_LVVV(("capability->egressControlVector[%d] = 0x%08X", i, capability->egressControlVector[i]));
            }
        }
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Access control services");



        // Capability
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability",                              mprintf("0x%04X", capability->capability.value16),                   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ACS source validation",       capability->capability.acsSourceValidation      ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ACS translation blocking",    capability->capability.acsTranslationBlocking   ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ACS P2P request redirect",    capability->capability.acsP2pRequestRedirect    ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ACS P2P completion redirect", capability->capability.acsP2pCompletionRedirect ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ACS upstream forwarding",     capability->capability.acsUpstreamForwarding    ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ACS P2P egress control",      capability->capability.acsP2pEgressControl      ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ACS direct translated P2P",   capability->capability.acsDirectTranslatedP2p   ? "Yes" : "No",      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Egress control vector size ", mprintf("%u", capability->capability.egressControlVectorSizeReal()), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Control", capability->control, "0x%04X", PciExpressAccessControlServicesAcsControlFlag, DeviceManagerMode::EXPERT);



        // Egress control vector
        {
            if (capability->capability.acsP2pEgressControl)
            {
                for (i64 i = 0; i < numberOfWords; ++i)
                {
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Egress control vector #%d", i), mprintf("0x%08X", capability->egressControlVector[i]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                }
            }
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressAriCapability(PciExpressAriCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->capability.mfvcFunctionGroupsCapability = %u",     capability->capability.mfvcFunctionGroupsCapability));
        UEFI_LVVV(("capability->capability.acsFunctionGroupsCapability  = %u",     capability->capability.acsFunctionGroupsCapability));
        UEFI_LVVV(("capability->capability.nextFunctionNumber           = %u",     capability->capability.nextFunctionNumber));
        UEFI_LVVV(("capability->capability.value16                      = 0x%04X", capability->capability.value16));
        UEFI_LVVV(("capability->control.mfvcFunctionGroupsEnable        = %u",     capability->control.mfvcFunctionGroupsEnable));
        UEFI_LVVV(("capability->control.acsFunctionGroupsEnable         = %u",     capability->control.acsFunctionGroupsEnable));
        UEFI_LVVV(("capability->control.functionGroup                   = %u",     capability->control.functionGroup));
        UEFI_LVVV(("capability->control.value16                         = 0x%04X", capability->control.value16));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "ARI");



        // Capability
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability",                                  mprintf("0x%04X", capability->capability.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: MFVC function groups capability", capability->capability.mfvcFunctionGroupsCapability ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ACS function groups capability",  capability->capability.acsFunctionGroupsCapability  ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Next function number",            mprintf("%u",     capability->capability.nextFunctionNumber),       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        // Control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control",                              mprintf("0x%04X", capability->control.value16),              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control: MFVC function groups enable", capability->control.mfvcFunctionGroupsEnable ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control: ACS function groups enable",  capability->control.acsFunctionGroupsEnable  ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control: Function group",              mprintf("%u",     capability->control.functionGroup),        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressMulticastCapability(PciExpressMulticastCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->capability.mcMaxGroup                     = %u",        capability->capability.mcMaxGroupReal()));
        UEFI_LVVV(("capability->capability.mcWindowSizeRequested          = %u",        capability->capability.mcWindowSizeRequested));
        UEFI_LVVV(("capability->capability.mcEcrcRegenerationSupported    = %u",        capability->capability.mcEcrcRegenerationSupported));
        UEFI_LVVV(("capability->capability.value16                        = 0x%04X",    capability->capability.value16));
        UEFI_LVVV(("capability->control.mcNumGroup                        = %u",        capability->control.mcNumGroupReal()));
        UEFI_LVVV(("capability->control.mcEnable                          = %u",        capability->control.mcEnable));
        UEFI_LVVV(("capability->control.value16                           = 0x%04X",    capability->control.value16));
        UEFI_LVVV(("capability->mcBaseAddress.mcIndexPosition             = %u",        capability->mcBaseAddress.mcIndexPosition));
        UEFI_LVVV(("capability->mcBaseAddress.mcBaseAddress               = 0x%016llX", capability->mcBaseAddress.mcBaseAddress));
        UEFI_LVVV(("capability->mcBaseAddress.value64                     = 0x%016llX", capability->mcBaseAddress.value64));
        UEFI_LVVV(("capability->mcReceive                                 = 0x%016llX", capability->mcReceive));
        UEFI_LVVV(("capability->mcBlockAll                                = 0x%016llX", capability->mcBlockAll));
        UEFI_LVVV(("capability->mcBlockUntranslated                       = 0x%016llX", capability->mcBlockUntranslated));
        UEFI_LVVV(("capability->mcOverlayBaseAddress.mcOverlaySize        = %u",        capability->mcOverlayBaseAddress.mcOverlaySize));
        UEFI_LVVV(("capability->mcOverlayBaseAddress.mcOverlayBaseAddress = 0x%016llX", capability->mcOverlayBaseAddress.mcOverlayBaseAddress));
        UEFI_LVVV(("capability->mcOverlayBaseAddress.value64              = 0x%016llX", capability->mcOverlayBaseAddress.value64));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Multicast");



        // Capability
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability",                              mprintf("0x%04X", capability->capability.value16),                 DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Maximum number of groups",    mprintf("%u",     capability->capability.mcMaxGroupReal()),        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Window size requested",       mprintf("%u",     capability->capability.mcWindowSizeRequested),   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ECRC regeneration supported", capability->capability.mcEcrcRegenerationSupported ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control",                   mprintf("0x%04X", capability->control.value16),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control: Number of groups", mprintf("%u",     capability->control.mcNumGroupReal()), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control: Enable",           capability->control.mcEnable ? "Yes" : "No",             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Base address
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address",                 mprintf("0x%016llX", capability->mcBaseAddress.value64),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address: Index position", mprintf("%u",        capability->mcBaseAddress.mcIndexPosition), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address: Address",        mprintf("0x%016llX", capability->mcBaseAddress.mcBaseAddress),   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }



        // Common info
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Receive",            mprintf("0x%016llX", capability->mcReceive),           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Block all",          mprintf("0x%016llX", capability->mcBlockAll),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Block untranslated", mprintf("0x%016llX", capability->mcBlockUntranslated), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }



        // Overlay base address
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Overlay base address",          mprintf("0x%016llX", capability->mcOverlayBaseAddress.value64),              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Overlay base address: Size",    mprintf("%u",        capability->mcOverlayBaseAddress.mcOverlaySize),        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Overlay base address: Address", mprintf("0x%016llX", capability->mcOverlayBaseAddress.mcOverlayBaseAddress), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressResizableBaseAddressCapability(PciExpressResizableBaseAddressCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        for (i64 i = 0; i < capability->capabilityAndControl[0].control.numberOfResizableBars; ++i)
        {
            UEFI_LVVV(("capability->capabilityAndControl[%d].capability                    = %s",     i, flagsToFullString(capability->capabilityAndControl[i].capability)));
            UEFI_LVVV(("capability->capabilityAndControl[%d].control.barIndex              = %u",     i, capability->capabilityAndControl[i].control.barIndex));
            UEFI_LVVV(("capability->capabilityAndControl[%d].control.numberOfResizableBars = %u",     i, capability->capabilityAndControl[i].control.numberOfResizableBars));
            UEFI_LVVV(("capability->capabilityAndControl[%d].control.barSize               = %s",     i, enumToFullString((PciExpressResizableBaseAddressBarSize)capability->capabilityAndControl[i].control.barSize)));
            UEFI_LVVV(("capability->capabilityAndControl[%d].control.value32               = 0x%08X", i, capability->capabilityAndControl[i].control.value32));
        }
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Resizable base address");



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of resizable BARs", mprintf("%u", capability->capabilityAndControl[0].control.numberOfResizableBars), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);

        for (i64 i = 0; i < capability->capabilityAndControl[0].control.numberOfResizableBars; ++i)
        {
            ADD_RECORDS_FOR_FLAGS_CYCLE(deviceManagerEntry, "Capability #%d", i, capability->capabilityAndControl[i].capability, "0x%08X", PciExpressResizableBaseAddressCapabilityFlag, DeviceManagerMode::EXPERT);



            // Control
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Control #%d",            i), mprintf("0x%08X", capability->capabilityAndControl[i].control.value32),                                               DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Control #%d: BAR index", i), mprintf("%u",     capability->capabilityAndControl[i].control.barIndex),                                              DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Control #%d: BAR size",  i), strdup(enumToFullString((PciExpressResizableBaseAddressBarSize)capability->capabilityAndControl[i].control.barSize)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            }
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressDynamicPowerAllocationCapability(PciExpressDynamicPowerAllocationCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->capability.substateMaximum         = %u",     capability->capability.substateMaximumReal()));
        UEFI_LVVV(("capability->capability.transitionLatencyUnit   = %s",     enumToFullString((PciExpressDynamicPowerAllocationTransitionLatencyUnit)capability->capability.transitionLatencyUnit)));
        UEFI_LVVV(("capability->capability.powerAllocationScale    = %s",     enumToFullString((PciExpressDynamicPowerAllocationPowerAllocationScale)capability->capability.transitionLatencyUnit)));
        UEFI_LVVV(("capability->capability.transitionLatencyValue0 = %u",     capability->capability.transitionLatencyValue0));
        UEFI_LVVV(("capability->capability.transitionLatencyValue1 = %u",     capability->capability.transitionLatencyValue1));
        UEFI_LVVV(("capability->capability.value32                 = 0x%08X", capability->capability.value32));
        UEFI_LVVV(("capability->latencyIndicator                   = 0x%08X", capability->latencyIndicator));
        UEFI_LVVV(("capability->status.substateStatus              = 0x%02X", capability->status.substateStatus));
        UEFI_LVVV(("capability->status.substateControlEnabled      = %u",     capability->status.substateControlEnabled));
        UEFI_LVVV(("capability->status.value16                     = 0x%04X", capability->status.value16));
        UEFI_LVVV(("capability->control.substateControl            = 0x%02X", capability->control.substateControl));
        UEFI_LVVV(("capability->control.value16                    = 0x%04X", capability->control.value16));

        for (i64 i = 0; i < capability->capability.substateMaximumReal(); ++i)
        {
            UEFI_LVVV(("capability->substatePowerAllocation[%d] = %u", i, capability->substatePowerAllocation[i]));
        }
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Dynamic power allocation");



        // Capability
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability",                              mprintf("0x%08X", capability->capability.value32),                                                                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Substate maximum",            mprintf("%u",     capability->capability.substateMaximumReal()),                                                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Transition latency unit",     strdup(enumToFullString((PciExpressDynamicPowerAllocationTransitionLatencyUnit)capability->capability.transitionLatencyUnit)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Power allocation scale",      strdup(enumToFullString((PciExpressDynamicPowerAllocationPowerAllocationScale)capability->capability.transitionLatencyUnit)),  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Transition latency value #0", mprintf("%u",     capability->capability.transitionLatencyValue0),                                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Transition latency value #1", mprintf("%u",     capability->capability.transitionLatencyValue1),                                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Latency indicator", mprintf("0x%08X", capability->latencyIndicator), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



        // Status
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                           mprintf("0x%04X", capability->status.value16),            DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Substate status",          mprintf("0x%02X", capability->status.substateStatus),     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Substate control enabled", capability->status.substateControlEnabled ? "Yes" : "No", DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control",                   mprintf("0x%04X", capability->control.value16),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control: Substate control", mprintf("0x%02X", capability->control.substateControl), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        }



        // Substate power allocation
        {
            for (i64 i = 0; i < capability->capability.substateMaximumReal(); ++i)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Substate power allocation #%d", i), mprintf("%u", capability->substatePowerAllocation[i]), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            }
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressTphRequesterCapability(PciExpressTphRequesterCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->capability.noStModeSupported             = %u",     capability->capability.noStModeSupported));
        UEFI_LVVV(("capability->capability.interruptVectorModeSupported  = %u",     capability->capability.interruptVectorModeSupported));
        UEFI_LVVV(("capability->capability.deviceSpecificModeSupported   = %u",     capability->capability.deviceSpecificModeSupported));
        UEFI_LVVV(("capability->capability.extendedTphRequesterSupported = %u",     capability->capability.extendedTphRequesterSupported));
        UEFI_LVVV(("capability->capability.stTableLocation               = %s",     enumToFullString((PciExpressTphRequesterStTableLocation)capability->capability.stTableLocation)));
        UEFI_LVVV(("capability->capability.stTableSize                   = %u",     capability->capability.stTableSizeReal()));
        UEFI_LVVV(("capability->capability.value32                       = 0x%08X", capability->capability.value32));
        UEFI_LVVV(("capability->control.stModeSelect                     = %s",     enumToFullString((PciExpressTphRequesterStModeSelect)capability->control.stModeSelect)));
        UEFI_LVVV(("capability->control.tphRequesterEnable               = %s",     enumToFullString((PciExpressTphRequesterTphRequesterEnable)capability->control.tphRequesterEnable)));
        UEFI_LVVV(("capability->control.value32                          = 0x%08X", capability->control.value32));

        if ((PciExpressTphRequesterStTableLocation)capability->capability.stTableLocation == PciExpressTphRequesterStTableLocation::TPH_REQUESTER_CAPABILITY)
        {
            for (i64 i = 0; i < capability->capability.stTableSizeReal(); ++i)
            {
                UEFI_LVVV(("capability->stTableEntries[%d].stLowerEntry = 0x%04X", i, capability->stTableEntries[i].stLowerEntry));
                UEFI_LVVV(("capability->stTableEntries[%d].stUpperEntry = 0x%04X", i, capability->stTableEntries[i].stUpperEntry));
            }
        }
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "TPH requester");



        // Capability
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability",                                   mprintf("0x%08X", capability->capability.value32),                                                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: No ST mode supported",             capability->capability.noStModeSupported             ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Interrupt vector mode supported",  capability->capability.interruptVectorModeSupported  ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Device specific mode supported",   capability->capability.deviceSpecificModeSupported   ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: Extended TPH requester supported", capability->capability.extendedTphRequesterSupported ? "Yes" : "No",                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ST table location",                strdup(enumToFullString((PciExpressTphRequesterStTableLocation)capability->capability.stTableLocation)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capability: ST table size",                    mprintf("%u",     capability->capability.stTableSizeReal()),                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Control
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control",                       mprintf("0x%08X", capability->control.value32),                                                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control: ST mode select",       strdup(enumToFullString((PciExpressTphRequesterStModeSelect)capability->control.stModeSelect)),             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Control: TPH requester enable", strdup(enumToFullString((PciExpressTphRequesterTphRequesterEnable)capability->control.tphRequesterEnable)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // ST table entry
        {
            if ((PciExpressTphRequesterStTableLocation)capability->capability.stTableLocation == PciExpressTphRequesterStTableLocation::TPH_REQUESTER_CAPABILITY)
            {
                for (i64 i = 0; i < capability->capability.stTableSizeReal(); ++i)
                {
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("ST table entry #%d: ST lower entry", i), mprintf("0x%04X", capability->stTableEntries[i].stLowerEntry), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("ST table entry #%d: ST upper entry", i), mprintf("0x%04X", capability->stTableEntries[i].stUpperEntry), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                }
            }
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressLatencyToleranceReportingCapability(PciExpressLatencyToleranceReportingCapability *capability, u8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, capabilityVersion = %u, deviceManagerEntry = 0x%p", capability, capabilityVersion, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(capabilityVersion  == 1,       "capabilityVersion is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null",   NgosStatus::ASSERTION);



    AVOID_UNUSED(capabilityVersion);



    // Validation
    {
        UEFI_LVVV(("capability->maxSnoopLatency.latencyValue   = %u",     capability->maxSnoopLatency.latencyValue));
        UEFI_LVVV(("capability->maxSnoopLatency.latencyScale   = %s",     enumToFullString((PciExpressLatencyToleranceReportingLatencyScale)capability->maxSnoopLatency.latencyScale)));
        UEFI_LVVV(("capability->maxSnoopLatency.value16        = 0x%04X", capability->maxSnoopLatency.value16));
        UEFI_LVVV(("capability->maxNoSnoopLatency.latencyValue = %u",     capability->maxNoSnoopLatency.latencyValue));
        UEFI_LVVV(("capability->maxNoSnoopLatency.latencyScale = %s",     enumToFullString((PciExpressLatencyToleranceReportingLatencyScale)capability->maxNoSnoopLatency.latencyScale)));
        UEFI_LVVV(("capability->maxNoSnoopLatency.value16      = 0x%04X", capability->maxNoSnoopLatency.value16));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        deviceManagerEntry = new DeviceManagerEntryPCI(deviceManagerEntry, DeviceManagerImage::PCI, "Latency tolerance reporting");



        // Max snoop latency
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Max snoop latency",                mprintf("0x%04X", capability->maxSnoopLatency.value16),                                                              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Max snoop latency: Latency value", mprintf("%u",     capability->maxSnoopLatency.latencyValue),                                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Max snoop latency: Latency scale", strdup(enumToFullString((PciExpressLatencyToleranceReportingLatencyScale)capability->maxSnoopLatency.latencyScale)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }



        // Max no-snoop latency
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Max no-snoop latency",                mprintf("0x%04X", capability->maxNoSnoopLatency.value16),                                                              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Max no-snoop latency: Latency value", mprintf("%u",     capability->maxNoSnoopLatency.latencyValue),                                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Max no-snoop latency: Latency scale", strdup(enumToFullString((PciExpressLatencyToleranceReportingLatencyScale)capability->maxNoSnoopLatency.latencyScale)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        }
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}
