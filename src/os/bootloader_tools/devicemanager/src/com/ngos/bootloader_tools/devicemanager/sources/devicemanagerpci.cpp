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
        for (i64 i = 0; i < (i64)(sizeof(flagsVar) * 8); ++i) \
        { \
            u64 flag = (1ULL << i); \
            \
            if (flagsVar.flags & flag) \
            { \
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf(name ": %s", flagToString((flagType)flag)), "Yes", mode), NgosStatus::ASSERTION); \
            } \
        } \
    }



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



                            DeviceManagerEntry *deviceManagerEntry;

                            // Add Device Manager entry
                            {
                                deviceManagerEntry = new DeviceManagerEntry(DeviceManagerImage::PCI, mprintf("PCI(%d/%d/%d)", i, j, k));

                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment",  mprintf("%u", pci->segmentNumber), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bus",      mprintf("%u", i),                  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device",   mprintf("%u", j),                  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Function", mprintf("%u", k),                  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



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

NgosStatus DeviceManagerPci::initPciWithConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base class",  baseClass,                                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subclass",    subClass,                                                                                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interface",   interface,                                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor",      enumToHumanString(configurationSpace.header.vendorId),                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device name", enumToHumanString(configurationSpace.header.vendorId, configurationSpace.header.deviceId), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor ID",   mprintf("0x%04X", configurationSpace.header.vendorId),                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device ID",   mprintf("0x%04X", configurationSpace.header.deviceId),                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Command", configurationSpace.header.command, "0x%04X", PciCommandFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                            mprintf("0x%04X", configurationSpace.header.status.value16),                                                                                               DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Interrupt status",          configurationSpace.header.status.interruptStatus       ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Capabilities list",         configurationSpace.header.status.capabilitiesList      ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: 66 MHz capable",            configurationSpace.header.status.support64MHz          ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Fast back-to-back capable", configurationSpace.header.status.fastBackToBackCapable ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Master data parity error",  configurationSpace.header.status.masterDataParityError ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Device select timing",      strdup(enumToFullString((PciDeviceSelectTiming)configurationSpace.header.status.deviceSelectTiming)),                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Signaled target abort",     configurationSpace.header.status.signaledTargetAbort   ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Received target abort",     configurationSpace.header.status.receivedTargetAbort   ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Received master abort",     configurationSpace.header.status.receivedMasterAbort   ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Signaled system error",     configurationSpace.header.status.signaledSystemError   ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status: Detected parity error",     configurationSpace.header.status.detectedParityError   ? "Yes" : "No",                                                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Revision ID",                       mprintf("%u",                     configurationSpace.header.revisionId),                                                                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Class codes",                       mprintf("0x%02X, 0x%02X, 0x%02X", configurationSpace.header.classCode[2], configurationSpace.header.classCode[1], configurationSpace.header.classCode[0]), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cache line size",                   mprintf("%u",                     configurationSpace.header.cacheLineSize),                                                                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Latency timer",                     mprintf("%u",                     configurationSpace.header.latencyTimer),                                                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Header type",                       strdup(enumToFullString((PciHeaderType)configurationSpace.header.headerType.type)),                                                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Built-in self test",                mprintf("0x%02X", configurationSpace.header.builtInSelfTest.value8),                                                                                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Built-in self test capable",        configurationSpace.header.builtInSelfTest.capable ? "Yes" : "No",                                                                                          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Built-in self test result",         mprintf("%u", configurationSpace.header.builtInSelfTest.completionCode),                                                                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
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

NgosStatus DeviceManagerPci::initPciWithDeviceConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #0",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[0]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #1",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[1]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #2",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[2]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #3",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[3]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #4",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[4]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #5",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[5]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Card information structure pointer", mprintf("0x%08X", configurationSpace.device.cardInformationStructurePointer), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem vendor ID",                subsystemVendorID,                                                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem ID",                       subsystemID,                                                                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Expansion ROM base address",         mprintf("0x%08X", configurationSpace.device.expansionRomBaseAddress),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities pointer",               mprintf("0x%02X", configurationSpace.device.capabilitiesPointer),             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt line",                     mprintf("%u",     configurationSpace.device.interruptLine),                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt pin",                      mprintf("%u",     configurationSpace.device.interruptPin),                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum grant",                      mprintf("%u",     configurationSpace.device.minGrant),                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum latency",                    mprintf("%u",     configurationSpace.device.maxLatency),                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    UEFI_ASSERT_EXECUTION(initPciWithCapabilitiesPointer(configurationSpace, configurationSpace.device.capabilitiesPointer, deviceManagerEntry, PciHeaderType::DEVICE, pci, bus, device, function), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithBridgeConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #0",                    mprintf("0x%08X", configurationSpace.bridge.baseAddressRegisters[0]),                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #1",                    mprintf("0x%08X", configurationSpace.bridge.baseAddressRegisters[1]),                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Primary bus",                                 mprintf("%u",     configurationSpace.bridge.primaryBus),                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary bus",                               mprintf("%u",     configurationSpace.bridge.secondaryBus),                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subordinate bus",                             mprintf("%u",     configurationSpace.bridge.subordinateBus),                                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Secondary latency timer",                     mprintf("%u",     configurationSpace.bridge.secondaryLatencyTimer),                                            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO base",                                     mprintf("0x%02X", configurationSpace.bridge.ioBase),                                                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO limit",                                    mprintf("0x%02X", configurationSpace.bridge.ioLimit),                                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory base",                                 mprintf("0x%04X", configurationSpace.bridge.memoryBase),                                                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory limit",                                mprintf("0x%04X", configurationSpace.bridge.memoryLimit),                                                      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Prefetchable memory base",                    mprintf("0x%04X", configurationSpace.bridge.prefetchableMemoryBase),                                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Prefetchable memory limit",                   mprintf("0x%04X", configurationSpace.bridge.prefetchableMemoryLimit),                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Prefetchable base upper 32",                  mprintf("0x%08X", configurationSpace.bridge.prefetchableBaseUpper32),                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Prefetchable limit upper 32",                 mprintf("0x%08X", configurationSpace.bridge.prefetchableLimitUpper32),                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO base upper 16",                            mprintf("0x%04X", configurationSpace.bridge.ioBaseUpper16),                                                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO limit upper 16",                           mprintf("0x%04X", configurationSpace.bridge.ioLimitUpper16),                                                   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities pointer",                        mprintf("0x%02X", configurationSpace.bridge.capabilitiesPointer),                                              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Expansion ROM base address",                  mprintf("0x%08X", configurationSpace.bridge.expansionRomBaseAddress),                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt line",                              mprintf("%u",     configurationSpace.bridge.interruptLine),                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt pin",                               mprintf("%u",     configurationSpace.bridge.interruptPin),                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Bridge control", configurationSpace.bridge.bridgeControl, "0x%04X", PciBridgeControlFlag, DeviceManagerMode::EXPERT);
        // Ignore CppAlignmentVerifier [END]
    }



    UEFI_ASSERT_EXECUTION(initPciWithCapabilitiesPointer(configurationSpace, configurationSpace.bridge.capabilitiesPointer, deviceManagerEntry, PciHeaderType::PCI_TO_PCI_BRIDGE, pci, bus, device, function), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithCardBusConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Card bus socket",                             mprintf("0x%08X", configurationSpace.cardBus.cardBusSocket),                                                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities pointer",                        mprintf("0x%02X", configurationSpace.cardBus.capabilitiesPointer),                                              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI bus number",                              mprintf("%u",     configurationSpace.cardBus.pciBusNumber),                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Card bus number",                             mprintf("%u",     configurationSpace.cardBus.cardBusBusNumber),                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subordinate bus number",                      mprintf("%u",     configurationSpace.cardBus.subordinateBusNumber),                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Card bus latency timer",                      mprintf("%u",     configurationSpace.cardBus.cardBusLatencyTimer),                                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory base0",                                mprintf("0x%08X", configurationSpace.cardBus.memoryBase0),                                                      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory limit0",                               mprintf("0x%08X", configurationSpace.cardBus.memoryLimit0),                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory base1",                                mprintf("0x%08X", configurationSpace.cardBus.memoryBase1),                                                      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory limit1",                               mprintf("0x%08X", configurationSpace.cardBus.memoryLimit1),                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO base0",                                    mprintf("0x%08X", configurationSpace.cardBus.ioBase0),                                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO limit0",                                   mprintf("0x%08X", configurationSpace.cardBus.ioLimit0),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO base1",                                    mprintf("0x%08X", configurationSpace.cardBus.ioBase1),                                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("IO limit1",                                   mprintf("0x%08X", configurationSpace.cardBus.ioLimit1),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt line",                              mprintf("%u",     configurationSpace.cardBus.interruptLine),                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt pin",                               mprintf("%u",     configurationSpace.cardBus.interruptPin),                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Bridge control", configurationSpace.cardBus.bridgeControl, "0x%04X", PciCardBusControlFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem vendor ID", subsystemVendorID,                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem ID",        subsystemID,                                DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Legacy base",         mprintf("0x%08X", cardBusData->legacyBase), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    UEFI_ASSERT_EXECUTION(initPciWithCapabilitiesPointer(configurationSpace, configurationSpace.cardBus.capabilitiesPointer, deviceManagerEntry, PciHeaderType::CARDBUS_BRIDGE, pci, bus, device, function), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithCapabilitiesPointer(const PciConfigurationSpace &configurationSpace, u8 capabilityPointer, DeviceManagerEntry *deviceManagerEntry, PciHeaderType headerType, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
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

NgosStatus DeviceManagerPci::initPciWithCapability(PciCapabilityHeader *capability, DeviceManagerEntry *deviceManagerEntry, PciHeaderType headerType, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
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
        case PciCapabilityType::POWER_MANAGEMENT_INTERFACE:    UEFI_ASSERT_EXECUTION(initPciWithPciPowerManagementInterfaceCapability((PciPowerManagementInterfaceCapability *)capability,            deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::ACCELERATED_GRAPHICS_PORT:     UEFI_ASSERT_EXECUTION(initPciWithPciAcceleratedGraphicsPortCapability((PciAcceleratedGraphicsPortCapability *)capability,              deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::VITAL_PRODUCT_DATA:            UEFI_ASSERT_EXECUTION(initPciWithPciVitalProductDataCapability((PciVitalProductDataCapability *)capability,                            deviceManagerEntry),                             NgosStatus::ASSERTION); break;
        case PciCapabilityType::SLOT_IDENTIFICATION:           UEFI_ASSERT_EXECUTION(initPciWithPciSlotNumberingCapability((PciSlotNumberingCapability *)capability,                                  deviceManagerEntry),                             NgosStatus::ASSERTION); break;
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

NgosStatus DeviceManagerPci::initPciWithPciPowerManagementInterfaceCapability(PciPowerManagementInterfaceCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_LVVV(("capability->controlStatus.dataSelect                  = %u",     capability->controlStatus.dataSelect));
        UEFI_LVVV(("capability->controlStatus.dataScale                   = %u",     capability->controlStatus.dataScale));
        UEFI_LVVV(("capability->controlStatus.pmeStatus                   = %u",     capability->controlStatus.pmeStatus));
        UEFI_LVVV(("capability->controlStatus.value16                     = 0x%04X", capability->controlStatus.value16));
        UEFI_LVVV(("capability->bridgeExtention.b2B3ForD3Hot              = %u",     capability->bridgeExtention.b2B3ForD3Hot));
        UEFI_LVVV(("capability->bridgeExtention.busPowerClockControl      = %u",     capability->bridgeExtention.busPowerClockControl));
        UEFI_LVVV(("capability->bridgeExtention.value8                    = 0x%02X", capability->bridgeExtention.value8));
    }



    // Fill Device Manager entry
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Capabilities",                                 mprintf("0x%04X", capability->capabilities.value16),                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Capabilities: Version",                        mprintf("%u",     capability->capabilities.version),                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Capabilities: PME clock",                      capability->capabilities.pmeClock                     ? "Yes" : "No",                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Capabilities: Device specific initialization", capability->capabilities.deviceSpecificInitialization ? "Yes" : "No",                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Capabilities: AUX current",                    strdup(enumToFullString((PciPowerManagementAuxCurrent)capability->capabilities.auxCurrent)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Capabilities: Support D1",                     capability->capabilities.supportD1                    ? "Yes" : "No",                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Capabilities: Support D2",                     capability->capabilities.supportD2                    ? "Yes" : "No",                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "PMI - Capabilities: PME support", supportPme, "0x%02X", PciPowerManagementSupportPmeFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Control/Status",                mprintf("0x%04X", capability->controlStatus.value16),                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Control/Status: Power state",   strdup(enumToFullString((PciPowerManagementPowerState)capability->controlStatus.powerState)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Control/Status: No soft reset", capability->controlStatus.noSoftReset ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Control/Status: Enable PME",    capability->controlStatus.enablePme   ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Control/Status: Data select",   mprintf("%u", capability->controlStatus.dataSelect),                                          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Control/Status: Data scale",    mprintf("%u", capability->controlStatus.dataScale),                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Control/Status: PME status",    capability->controlStatus.pmeStatus   ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Bridge extention",                                             mprintf("0x%02X", capability->bridgeExtention.value8),           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Bridge extention: Switch secondary bus power state on D3 HOT", capability->bridgeExtention.b2B3ForD3Hot         ? "B2"  : "B3", DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PMI - Bridge extention: Enable bus power/clock control",             capability->bridgeExtention.busPowerClockControl ? "Yes" : "No", DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithPciAcceleratedGraphicsPortCapability(PciAcceleratedGraphicsPortCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("AGP - Revision", mprintf("0x%02X", capability->revision),       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("AGP - Status",   mprintf("0x%08X", capability->status.value32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "AGP - Status: Rate", statusRate, "0x%02X", PciAcceleratedGraphicsPortRateFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("AGP - Status: Support side band addressing",       capability->status.supportSideBandAddressing ? "Yes" : "No",          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("AGP - Status: Maximum number of command requests", mprintf("%u",     capability->status.maximumNumberOfCommandRequests), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("AGP - Command",                                    mprintf("0x%08X", capability->command.value32),                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "AGP - Command: Rate", commandRate, "0x%02X", PciAcceleratedGraphicsPortRateFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("AGP - Command: Enable accelerated graphics port",   capability->command.enableAcceleratedGraphicsPort ? "Yes" : "No",  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("AGP - Command: Enable side band addressing",        capability->command.enableSideBandAddressing      ? "Yes" : "No",  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("AGP - Command: Maximum number of command requests", mprintf("%u", capability->command.maximumNumberOfCommandRequests), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithPciVitalProductDataCapability(PciVitalProductDataCapability *capability, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->address.value    = 0x%04X", capability->address.value));
        UEFI_LVVV(("capability->address.finished = %u",     capability->address.finished));
        UEFI_LVVV(("capability->address.value16  = 0x%04X", capability->address.value16));
        UEFI_LVVV(("capability->data             = 0x%08X", capability->data));
    }



    // Fill Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("VPD - Address union", mprintf("0x%04X", capability->address.value16), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("VPD - Address",       mprintf("0x%04X", capability->address.value),   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("VPD - Finished",      capability->address.finished ? "Yes" : "No",    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("VPD - Data",          mprintf("0x%08X", capability->data),            DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithPciSlotNumberingCapability(PciSlotNumberingCapability *capability, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("capability->expansionSlot.expansionSlotsProvided = 0x%02X", capability->expansionSlot.expansionSlotsProvided));
        UEFI_LVVV(("capability->expansionSlot.firstInChassis         = %u",     capability->expansionSlot.firstInChassis));
        UEFI_LVVV(("capability->expansionSlot.value8                 = 0x%02X", capability->expansionSlot.value8));
        UEFI_LVVV(("capability->chassisNumber                        = 0x%02X", capability->chassisNumber));
    }



    // Fill Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SLOT ID - Expansion slot",           mprintf("0x%02X", capability->expansionSlot.value8),                 DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SLOT ID - Expansion slots provided", mprintf("0x%02X", capability->expansionSlot.expansionSlotsProvided), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SLOT ID - First in chassis",         capability->expansionSlot.firstInChassis ? "Yes" : "No",             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SLOT ID - Chassis number",           mprintf("0x%02X", capability->chassisNumber),                        DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciMessageSignaledInterruptsCapability(PciMessageSignaledInterruptsCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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

NgosStatus DeviceManagerPci::initPciMessageSignaledInterrupts32Capability(PciMessageSignaledInterruptsCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control",                             mprintf("0x%04X", capability->messageControl.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Enable MSI",                 capability->messageControl.enableMSI ? "Yes" : "No",                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Support multiple message",   mprintf("%u", capability->messageControl.supportMultipleMessageReal()), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Enable multiple message",    mprintf("%u", capability->messageControl.enableMultipleMessageReal()),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Support 64 bit address",     capability->messageControl.support64BitAddress ? "Yes" : "No",          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Support per vector masking", capability->messageControl.supportPerVectorMasking ? "Yes" : "No",      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message address",                             mprintf("0x%08X", capability->messageAddress.value),                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message data",                                mprintf("0x%04X", capability->messageData),                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciMessageSignaledInterrupts64Capability(PciMessageSignaledInterrupts64Capability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control",                             mprintf("0x%04X", capability->messageControl.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Enable MSI",                 capability->messageControl.enableMSI ? "Yes" : "No",                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Support multiple message",   mprintf("%u", capability->messageControl.supportMultipleMessageReal()), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Enable multiple message",    mprintf("%u", capability->messageControl.enableMultipleMessageReal()),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Support 64 bit address",     capability->messageControl.support64BitAddress ? "Yes" : "No",          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Support per vector masking", capability->messageControl.supportPerVectorMasking ? "Yes" : "No",      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message address",                             mprintf("0x%08X", capability->messageAddress.value),                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message address upper",                       mprintf("0x%08X", capability->messageAddressUpper),                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message data",                                mprintf("0x%04X", capability->messageData),                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciMessageSignaledInterrupts64PerVectorMaskingCapability(PciMessageSignaledInterrupts64PerVectorMaskingCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control",                             mprintf("0x%04X", capability->messageControl.value16),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Enable MSI",                 capability->messageControl.enableMSI ? "Yes" : "No",                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Support multiple message",   mprintf("%u", capability->messageControl.supportMultipleMessageReal()), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Enable multiple message",    mprintf("%u", capability->messageControl.enableMultipleMessageReal()),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Support 64 bit address",     capability->messageControl.support64BitAddress ? "Yes" : "No",          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message control: Support per vector masking", capability->messageControl.supportPerVectorMasking ? "Yes" : "No",      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message address",                             mprintf("0x%08X", capability->messageAddress.value),                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message address upper",                       mprintf("0x%08X", capability->messageAddressUpper),                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Message data",                                mprintf("0x%04X", capability->messageData),                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Mask bits",                                   mprintf("0x%08X", capability->maskBits),                                DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI - Pending bits",                                mprintf("0x%08X", capability->pendingBits),                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciHotSwapCapability(PciHotSwapCapability *capability, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExtendedCapability(PciCapabilityHeader *capability, DeviceManagerEntry *deviceManagerEntry, PciHeaderType headerType)
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

NgosStatus DeviceManagerPci::initPciExtendedDeviceCapability(PciExtendedDeviceCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Command",                                                 mprintf("0x%04X", capability->command.value16),                                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Command: Enable data parity error recovery",              capability->command.enableDataParityErrorRecovery      ? "Yes" : "No",                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Command: Enable relaxed ordering",                        capability->command.enableRelaxedOrdering              ? "Yes" : "No",                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Command: Maximum memory read byte count",                 mprintf("%u",     capability->command.maximumMemoryReadByteCountReal()),                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Command: Maximum outstanding split transactions",         mprintf("%u",     capability->command.maximumOutstandingSplitTransactionsReal()),           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status",                                                  mprintf("0x%08X", capability->status.value32),                                              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Function number",                                 mprintf("%u",     capability->status.functionNumber),                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Device number",                                   mprintf("%u",     capability->status.deviceNumber),                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Bus number",                                      mprintf("%u",     capability->status.busNumber),                                            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: 64 bit device",                                   capability->status.is64BitDevice                       ? "Yes" : "No",                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: 133 MHz capable",                                 capability->status.support133MHz                       ? "Yes" : "No",                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Split completion discarded",                      capability->status.splitCompletionDiscarded            ? "Yes" : "No",                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Unexpected split completion",                     capability->status.unexpectedSplitCompletion           ? "Yes" : "No",                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Device complexity",                               strdup(enumToFullString((PciExtendedDeviceComplexity)capability->status.deviceComplexity)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Designed maximum memory read byte count",         mprintf("%u",     capability->status.designedMaximumMemoryReadByteCountReal()),             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Designed maximum outstanding split transactions", mprintf("%u",     capability->status.designedMaximumOutstandingSplitTransactionsReal()),    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Designed maximum cumulative read size",           mprintf("%u",     capability->status.designedMaximumCumulativeReadSizeReal()),              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Received split completion error message",         capability->status.receivedSplitCompletionErrorMessage ? "Yes" : "No",                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExtendedBridgeCapability(PciExtendedBridgeCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Secondary status",                               mprintf("0x%04X", capability->secondaryStatus.value16),                                                                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Secondary status: 64 bit device",                capability->secondaryStatus.is64BitDevice             ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Secondary status: 133 MHz capable",              capability->secondaryStatus.support133MHz             ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Secondary status: Split completion discarded",   capability->secondaryStatus.splitCompletionDiscarded  ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Secondary status: Unexpected split completion",  capability->secondaryStatus.unexpectedSplitCompletion ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Secondary status: Split completion overrun",     capability->secondaryStatus.splitCompletionOverrun    ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Secondary status: Split request delayed",        capability->secondaryStatus.splitRequestDelayed       ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Secondary status: Secondary clock frequency",    strdup(enumToFullString((PciExtendedBridgeSecondaryClockFrequency)capability->secondaryStatus.secondaryClockFrequency)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status",                                         mprintf("0x%08X", capability->status.value32),                                                                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Function number",                        mprintf("%u",     capability->status.functionNumber),                                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Device number",                          mprintf("%u",     capability->status.deviceNumber),                                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Bus number",                             mprintf("%u",     capability->status.busNumber),                                                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: 64 bit device",                          capability->status.is64BitDevice                      ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: 133 MHz capable",                        capability->status.support133MHz                      ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Split completion discarded",             capability->status.splitCompletionDiscarded           ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Unexpected split completion",            capability->status.unexpectedSplitCompletion          ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Split completion overrun",               capability->status.splitCompletionOverrun             ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Status: Split request delayed",                  capability->status.splitRequestDelayed                ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Upstream: Split transaction commitment limit",   mprintf("%u",     capability->upstream.splitTransactionCommitmentLimit),                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Upstream: Split transaction capacity",           mprintf("%u",     capability->upstream.splitTransactionCapacity),                                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Downstream: Split transaction commitment limit", mprintf("%u",     capability->downstream.splitTransactionCommitmentLimit),                                               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-X - Downstream: Split transaction capacity",         mprintf("%u",     capability->downstream.splitTransactionCapacity),                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciHyperTransportCapability(PciHyperTransportCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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

NgosStatus DeviceManagerPci::initPciHyperTransportSlavePrimaryInterfaceBlockCapability(PciHyperTransportSlavePrimaryInterfaceBlockCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command",                                           mprintf("0x%04X", capability->command.value16),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Base unit ID",                             mprintf("%u",     capability->command.baseUnitId),                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Unit count",                               mprintf("%u",     capability->command.unitCount),                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Master host",                              capability->command.masterHost ? "Yes" : "No",                                                          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Default direction",                        capability->command.defaultDirection ? "To master host" : "From master host",                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Drop on uninit",                           capability->command.dropOnUninit ? "Yes" : "No",                                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Capability type",                          strdup(enumToFullString((PciHyperTransportCapabilityType)capability->command.capabilityType)),          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0",                                    mprintf("0x%04X", capability->linkControl0.value16),                                                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: Enable source ID",                  capability->linkControl0.enableSourceId               ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: Enable CRC flood",                  capability->linkControl0.enableCrcFlood               ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: CRC start test",                    capability->linkControl0.crcStartTest                 ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: CRC force error",                   capability->linkControl0.crcForceError                ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: Link failure",                      capability->linkControl0.linkFailure                  ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: Initialization complete",           capability->linkControl0.initializationComplete       ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: End of chain",                      capability->linkControl0.endOfChain                   ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: Transmitter off",                   capability->linkControl0.transmitterOff               ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: CRC error",                         mprintf("%u", capability->linkControl0.crcError),                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: Enable isochronous flow control",   capability->linkControl0.enableIsochronousFlowControl ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: Enable LDTSTOP tristate",           capability->linkControl0.enableLdtStopTristate        ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: Extended CTL time",                 capability->linkControl0.extendedCtlTime              ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 0: Enable 64 bit addressing",          capability->linkControl0.enable64BitAddressing        ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 0",                                     mprintf("0x%04X", capability->linkConfig0.value16),                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 0: Maximum link width in",              strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.maximumLinkWidthIn)),       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 0: Doubleword flow control in",         capability->linkConfig0.doublewordFlowControlIn ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 0: Maximum link width out",             strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.maximumLinkWidthOut)),      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 0: Doubleword flow control out",        capability->linkConfig0.doublewordFlowControlOut ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 0: Link width in",                      strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.linkWidthIn)),              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 0: Enable doubleword flow control in",  capability->linkConfig0.enableDoublewordFlowControlIn ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 0: Link width out",                     strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig0.linkWidthOut)),             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 0: Enable doubleword flow control out", capability->linkConfig0.enableDoublewordFlowControlOut ? "Yes" : "No",                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1",                                    mprintf("0x%04X", capability->linkControl1.value16),                                                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: Enable source ID",                  capability->linkControl1.enableSourceId               ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: Enable CRC flood",                  capability->linkControl1.enableCrcFlood               ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: CRC start test",                    capability->linkControl1.crcStartTest                 ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: CRC force error",                   capability->linkControl1.crcForceError                ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: Link failure",                      capability->linkControl1.linkFailure                  ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: Initialization complete",           capability->linkControl1.initializationComplete       ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: End of chain",                      capability->linkControl1.endOfChain                   ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: Transmitter off",                   capability->linkControl1.transmitterOff               ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: CRC error",                         mprintf("%u", capability->linkControl1.crcError),                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: Enable isochronous flow control",   capability->linkControl1.enableIsochronousFlowControl ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: Enable LDTSTOP tristate",           capability->linkControl1.enableLdtStopTristate        ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: Extended CTL time",                 capability->linkControl1.extendedCtlTime              ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control 1: Enable 64 bit addressing",          capability->linkControl1.enable64BitAddressing        ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 1",                                     mprintf("0x%04X", capability->linkConfig1.value16),                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 1: Maximum link width in",              strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.maximumLinkWidthIn)),       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 1: Doubleword flow control in",         capability->linkConfig1.doublewordFlowControlIn ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 1: Maximum link width out",             strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.maximumLinkWidthOut)),      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 1: Doubleword flow control out",        capability->linkConfig1.doublewordFlowControlOut ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 1: Link width in",                      strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.linkWidthIn)),              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 1: Enable doubleword flow control in",  capability->linkConfig1.enableDoublewordFlowControlIn ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 1: Link width out",                     strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig1.linkWidthOut)),             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config 1: Enable doubleword flow control out", capability->linkConfig1.enableDoublewordFlowControlOut ? "Yes" : "No",                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Revision ID",                                       strdup(enumToFullString(capability->revisionId)),                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link frequency 0",                                  strdup(enumToFullString((PciHyperTransportLinkFrequency)capability->linkErrorAndFrequency0.frequency)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Link error 0",                linkError0,                           "0x%02X", PciHyperTransportLinkErrorFlag,                    DeviceManagerMode::EXPERT);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Link frequency capability 0", capability->linkFrequencyCapability0, "0x%04X", PciHyperTransportLinkFrequencyCapabilityFlag,      DeviceManagerMode::EXPERT);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Feature",                     capability->feature,                  "0x%02X", PciHyperTransportSlavePrimaryInterfaceFeatureFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link frequency 1", strdup(enumToFullString((PciHyperTransportLinkFrequency)capability->linkErrorAndFrequency1.frequency)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Link error 1",                linkError1,                           "0x%02X", PciHyperTransportLinkErrorFlag,               DeviceManagerMode::EXPERT);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Link frequency capability 1", capability->linkFrequencyCapability1, "0x%04X", PciHyperTransportLinkFrequencyCapabilityFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Enumeration scratchpad", mprintf("%u", capability->enumerationScratchpad), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Error handling", capability->errorHandling, "0x%04X", PciHyperTransportErrorHandlingFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Memory base upper",  mprintf("0x%02X", capability->memoryBaseUpper),  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Memory limit upper", mprintf("0x%02X", capability->memoryLimitUpper), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Bus number",         mprintf("%u",     capability->busNumber),        DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciHyperTransportHostSecondaryInterfaceBlockCapability(PciHyperTransportHostSecondaryInterfaceBlockCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command",                                         mprintf("0x%04X", capability->command.value16),                                                        DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Warm reset",                             capability->command.warmReset                  ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Double ended",                           capability->command.doubleEnded                ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Device number",                          mprintf("%u", capability->command.deviceNumber),                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Chain side",                             capability->command.chainSide                  ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Host hide",                              capability->command.hostHide                   ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Act as slave",                           capability->command.actAsSlave                 ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Host inbound end of chain error",        capability->command.hostInboundEndOfChainError ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Drop on uninit",                         capability->command.dropOnUninit               ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Command: Capability type",                        strdup(enumToFullString((PciHyperTransportCapabilityType)capability->command.capabilityType)),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control",                                    mprintf("0x%04X", capability->linkControl.value16),                                                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: Enable source ID",                  capability->linkControl.enableSourceId               ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: Enable CRC flood",                  capability->linkControl.enableCrcFlood               ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: CRC start test",                    capability->linkControl.crcStartTest                 ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: CRC force error",                   capability->linkControl.crcForceError                ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: Link failure",                      capability->linkControl.linkFailure                  ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: Initialization complete",           capability->linkControl.initializationComplete       ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: End of chain",                      capability->linkControl.endOfChain                   ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: Transmitter off",                   capability->linkControl.transmitterOff               ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: CRC error",                         mprintf("%u", capability->linkControl.crcError),                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: Enable isochronous flow control",   capability->linkControl.enableIsochronousFlowControl ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: Enable LDTSTOP tristate",           capability->linkControl.enableLdtStopTristate        ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: Extended CTL time",                 capability->linkControl.extendedCtlTime              ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link control: Enable 64 bit addressing",          capability->linkControl.enable64BitAddressing        ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config",                                     mprintf("0x%04X", capability->linkConfig.value16),                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config: Maximum link width in",              strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.maximumLinkWidthIn)),       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config: Doubleword flow control in",         capability->linkConfig.doublewordFlowControlIn ? "Yes" : "No",                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config: Maximum link width out",             strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.maximumLinkWidthOut)),      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config: Doubleword flow control out",        capability->linkConfig.doublewordFlowControlOut ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config: Link width in",                      strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.linkWidthIn)),              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config: Enable doubleword flow control in",  capability->linkConfig.enableDoublewordFlowControlIn ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config: Link width out",                     strdup(enumToFullString((PciHyperTransportLinkWidth)capability->linkConfig.linkWidthOut)),             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link config: Enable doubleword flow control out", capability->linkConfig.enableDoublewordFlowControlOut ? "Yes" : "No",                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Revision ID",                                     strdup(enumToFullString(capability->revisionId)),                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Link frequency",                                  strdup(enumToFullString((PciHyperTransportLinkFrequency)capability->linkErrorAndFrequency.frequency)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Link error",                linkError,                           "0x%02X", PciHyperTransportLinkErrorFlag,                     DeviceManagerMode::EXPERT);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Link frequency capability", capability->linkFrequencyCapability, "0x%04X", PciHyperTransportLinkFrequencyCapabilityFlag,       DeviceManagerMode::EXPERT);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Feature",                   capability->feature,                 "0x%04X", PciHyperTransportHostSecondaryInterfaceFeatureFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Enumeration scratchpad", mprintf("%u", capability->enumerationScratchpad), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "HT - Error handling", capability->errorHandling, "0x%04X", PciHyperTransportErrorHandlingFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Memory base upper",  mprintf("0x%02X", capability->memoryBaseUpper),  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("HT - Memory limit upper", mprintf("0x%02X", capability->memoryLimitUpper), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciVendorCapability(PciVendorCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor - Length", mprintf("%u", capability->length), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciDebugPortCapability(PciDebugPortCapability *capability, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciCentralResourceControlCapability(PciCentralResourceControlCapability *capability, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciHotPlugCapability(PciHotPlugCapability *capability, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciAcceleratedGraphicsPort8xCapability(PciAcceleratedGraphicsPort8xCapability *capability, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciSecureDeviceCapability(PciSecureDeviceCapability *capability, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(capability);
    AVOID_UNUSED(deviceManagerEntry);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciExpressCapability(PciExpressCapability *capability, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function)
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
        UEFI_LVVV(("capability->deviceCapability.capturedSlotPowerLimitScale                             = %s",     enumToFullString((PciExpressSlotPowerLimitScale)capability->deviceCapability.capturedSlotPowerLimitScale)));
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
        UEFI_LVVV(("capability->slotCapability.slotPowerLimitScale                                       = %s",     enumToFullString((PciExpressSlotPowerLimitScale)capability->slotCapability.slotPowerLimitScale)));
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Capability",                                                                         mprintf("0x%04X", capability->capability.value16),                                                                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Capability: Version",                                                                mprintf("%u",     capability->capability.capabilityVersion),                                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Capability: Device port type",                                                       strdup(enumToFullString((PciExpressDevicePortType)capability->capability.devicePortType)),                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Capability: Slot implemented",                                                       capability->capability.slotImplemented ? "Yes" : "No",                                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Capability: Interrupt message number",                                               mprintf("%u",     capability->capability.interruptMessageNumber),                                                            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability",                                                                  mprintf("0x%08X", capability->deviceCapability.value32),                                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability: Maximum payload size supported",                                  strdup(enumToFullString((PciExpressPayloadSize)capability->deviceCapability.maximumPayloadSizeSupported)),                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability: Phantom functions supported",                                     mprintf("%u",     capability->deviceCapability.phantomFunctionsSupported),                                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability: Extended tag field supported",                                    strdup(enumToFullString((PciExpressExtendedTagField)capability->deviceCapability.extendedTagFieldSupported)),                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability: Endpoint L0s acceptable latency",                                 strdup(enumToFullString((PciExpressEndpointL0sAcceptableLatency)capability->deviceCapability.endpointL0sAcceptableLatency)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability: Endpoint L1 acceptable latency",                                  strdup(enumToFullString((PciExpressEndpointL1AcceptableLatency)capability->deviceCapability.endpointL1AcceptableLatency)),   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability: Role based error reporting",                                      capability->deviceCapability.roleBasedErrorReporting ? "Yes" : "No",                                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability: Captured slot power limit value",                                 mprintf("%u",     capability->deviceCapability.capturedSlotPowerLimitValue),                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability: Captured slot power limit scale",                                 strdup(enumToFullString((PciExpressSlotPowerLimitScale)capability->deviceCapability.capturedSlotPowerLimitScale)),           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability: Function level reset capability",                                 capability->deviceCapability.functionLevelResetCapability ? "Yes" : "No",                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control",                                                                     mprintf("0x%04X", capability->deviceControl.value16),                                                                        DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Correctable error reporting enable",                                 capability->deviceControl.correctableErrorReportingEnable   ? "Yes" : "No",                                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Non-fatal error reporting enable",                                   capability->deviceControl.nonFatalErrorReportingEnable      ? "Yes" : "No",                                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Fatal error reporting enable",                                       capability->deviceControl.fatalErrorReportingEnable         ? "Yes" : "No",                                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Unsupported request reporting enable",                               capability->deviceControl.unsupportedRequestReportingEnable ? "Yes" : "No",                                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Enable relaxed ordering",                                            capability->deviceControl.enableRelaxedOrdering             ? "Yes" : "No",                                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Maximum payload size",                                               strdup(enumToFullString((PciExpressPayloadSize)capability->deviceControl.maximumPayloadSize)),                               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Extended tag field enable",                                          strdup(enumToFullString((PciExpressExtendedTagField)capability->deviceControl.extendedTagFieldEnable)),                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Phantom functions enable",                                           capability->deviceControl.phantomFunctionsEnable ? "Yes" : "No",                                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Auxiliary power PM enable",                                          capability->deviceControl.auxPowerPmEnable       ? "Yes" : "No",                                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Enable no snoop",                                                    capability->deviceControl.enableNoSnoop          ? "Yes" : "No",                                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Maximum read request size",                                          strdup(enumToFullString((PciExpressRequestSize)capability->deviceControl.maximumReadRequestSize)),                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control: Bridge configuration retry enable or initiate function level reset", capability->deviceControl.bridgeConfigurationRetryEnableOrInitiateFunctionLevelReset ? "Yes" : "No",                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "PCI-E - Device status", capability->deviceStatus, "0x%04X", PciExpressDeviceStatusFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability",                                                mprintf("0x%08X", capability->linkCapability.value32),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: Supported link speeds",                         strdup(enumToFullString((PciExpressLinkSpeed)capability->linkCapability.supportedLinkSpeeds)),                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: Maximum link width",                            strdup(enumToFullString((PciExpressLinkWidth)capability->linkCapability.maximumLinkWidth)),                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: ASPM support",                                  strdup(enumToFullString((PciExpressActiveStatePowerManagementSupport)capability->linkCapability.aspmSupport)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: L0s exit latency",                              strdup(enumToFullString((PciExpressL0sExitLatency)capability->linkCapability.l0sExitLatency)),                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: L1 exit latency",                               strdup(enumToFullString((PciExpressL1ExitLatency)capability->linkCapability.l1ExitLatency)),                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: Clock power management",                        capability->linkCapability.clockPowerManagement                    ? "Yes" : "No",                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: Surprise down error reporting capable",         capability->linkCapability.surpriseDownErrorReportingCapable       ? "Yes" : "No",                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: Data link layer link active reporting capable", capability->linkCapability.dataLinkLayerLinkActiveReportingCapable ? "Yes" : "No",                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: Link bandwidth notification capability",        capability->linkCapability.linkBandwidthNotificationCapability     ? "Yes" : "No",                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: ASPM optionality compliance",                   capability->linkCapability.aspmOptionalityCompliance               ? "Yes" : "No",                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability: Port number",                                   mprintf("%u",     capability->linkCapability.portNumber),                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control",                                                   mprintf("0x%04X", capability->linkControl.value16),                                                            DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: ASPM control",                                     strdup(enumToFullString((PciExpressActiveStatePowerManagementControl)capability->linkControl.aspmControl)),    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: Read completion boundary",                         strdup(enumToFullString((PciExpressReadCompletionBoundary)capability->linkControl.readCompletionBoundary)),    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: Link disable",                                     capability->linkControl.linkDisable                            ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: Retrain link",                                     capability->linkControl.retrainLink                            ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: Common clock configuration",                       capability->linkControl.commonClockConfiguration               ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: Extended synch",                                   capability->linkControl.extendedSynch                          ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: Enable clock power management",                    capability->linkControl.enableClockPowerManagement             ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: Hardware autonomous width disable",                capability->linkControl.hardwareAutonomousWidthDisable         ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: Link bandwidth management interrupt enable",       capability->linkControl.linkBandwidthManagementInterruptEnable ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control: Link autonomous bandwidth interrupt enable",       capability->linkControl.linkAutonomousBandwidthInterruptEnable ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status",                                                    mprintf("0x%04X", capability->linkStatus.value16),                                                             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status: Current link speed",                                strdup(enumToFullString((PciExpressLinkSpeed)capability->linkStatus.currentLinkSpeed)),                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status: Negotiated link width",                             strdup(enumToFullString((PciExpressLinkWidth)capability->linkStatus.negotiatedLinkWidth)),                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status: Link training",                                     capability->linkStatus.linkTraining                  ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status: Slot clock configuration",                          capability->linkStatus.slotClockConfiguration        ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status: Data link layer link active",                       capability->linkStatus.dataLinkLayerLinkActive       ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status: Link bandwidth management status",                  capability->linkStatus.linkBandwidthManagementStatus ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status: Link autonomous bandwidth status",                  capability->linkStatus.linkAutonomousBandwidthStatus ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability",                                                mprintf("0x%08X", capability->slotCapability.value32),                                                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Attention button present",                      capability->slotCapability.attentionButtonPresent    ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Power controller present",                      capability->slotCapability.powerControllerPresent    ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: MRL sensor present",                            capability->slotCapability.mrlSensorPresent          ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Attention indicator present",                   capability->slotCapability.attentionIndicatorPresent ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Power indicator present",                       capability->slotCapability.powerIndicatorPresent     ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Hot-plug surprise",                             capability->slotCapability.hotPlugSurprise           ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Hot-plug capable",                              capability->slotCapability.hotPlugCapable            ? "Yes" : "No",                                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Slot power limit value",                        mprintf("%u",     capability->slotCapability.slotPowerLimitValue),                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Slot power limit scale",                        strdup(enumToFullString((PciExpressSlotPowerLimitScale)capability->slotCapability.slotPowerLimitScale)),       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Electromechanical interlock present",           capability->slotCapability.electromechanicalInterlockPresent ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: No command completed support",                  capability->slotCapability.noCommandCompletedSupport         ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability: Physical slot number",                          mprintf("%u",     capability->slotCapability.physicalSlotNumber),                                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control",                                                   mprintf("0x%04X", capability->slotControl.value16),                                                            DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Attention button pressed enable",                  capability->slotControl.attentionButtonPressedEnable    ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Power fault detected enable",                      capability->slotControl.powerFaultDetectedEnable        ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: MRL sensor changed enable",                        capability->slotControl.mrlSensorChangedEnable          ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Presence detect changed enable",                   capability->slotControl.presenceDetectChangedEnable     ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Command completed interrupt enable",               capability->slotControl.commandCompletedInterruptEnable ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Hot-plug interrupt enable",                        capability->slotControl.hotPlugInterruptEnable          ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Attention indicator control",                      strdup(enumToFullString((PciExpressIndicatorControl)capability->slotControl.attentionIndicatorControl)),       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Power indicator control",                          strdup(enumToFullString((PciExpressIndicatorControl)capability->slotControl.powerIndicatorControl)),           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Power controller control",                         strdup(enumToFullString((PciExpressPowerControllerControl)capability->slotControl.powerControllerControl)),    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Electromechanical interlock control",              capability->slotControl.electromechanicalInterlockControl ? "Yes" : "No",                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control: Data link layer state changed enable",             capability->slotControl.dataLinkLayerStateChangedEnable   ? "Yes" : "No",                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "PCI-E - Slot status",     capability->slotStatus,     "0x%04X", PciExpressSlotStatusFlag,     DeviceManagerMode::EXPERT);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "PCI-E - Root control",    capability->rootControl,    "0x%04X", PciExpressRootControlFlag,    DeviceManagerMode::EXPERT);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "PCI-E - Root capability", capability->rootCapability, "0x%04X", PciExpressRootCapabilityFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Root status",                   mprintf("0x%08X", capability->rootStatus.value32),        DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Root status: PME requester ID", mprintf("%u",     capability->rootStatus.pmeRequesterId), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Root status: PME status",       capability->rootStatus.pmeStatus  ? "Yes" : "No",         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Root status: PME pending",      capability->rootStatus.pmePending ? "Yes" : "No",         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2",           mprintf("0x%08X", capability->deviceCapability2.value32), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "PCI-E - Device capability 2: Completion timeout ranges supported", completionTimeoutRangesSupported, "0x%02X", PciExpressCompletionTimeoutRangeFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Completion timeout disable supported", capability->deviceCapability2.completionTimeoutDisableSupported ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: ARI forwarding supported",             capability->deviceCapability2.ariForwardingSupported            ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: AtomicOp routing supported",           capability->deviceCapability2.atomicOpRoutingSupported          ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: AtomicOp 32-bit completer supported",  capability->deviceCapability2.atomicOp32CompleterSupported      ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: AtomicOp 64-bit completer supported",  capability->deviceCapability2.atomicOp64CompleterSupported      ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: CAS 128-bit completer supported",      capability->deviceCapability2.cas128CompleterSupported          ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: No RO-enabled PR-PR passing",          capability->deviceCapability2.noRoEnabledPrPrPassing            ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: LTR mechanism supported",              capability->deviceCapability2.ltrMechanismSupported             ? "Yes" : "No", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "PCI-E - Device capability 2: TPH completer supported", tphCompleterSupported, "0x%02X", PciExpressTphCompleterFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Ln system cls",                                     mprintf("%u",     capability->deviceCapability2.lnSystemCls),                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Ten bit tag completer supported",                   capability->deviceCapability2.tenBitTagCompleterSupported ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Ten bit tag requester supported",                   capability->deviceCapability2.tenBitTagRequesterSupported ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Obff",                                              mprintf("%u",     capability->deviceCapability2.obff),                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Extended fmt field supported",                      capability->deviceCapability2.extendedFmtFieldSupported ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: End-end TLP prefix supported",                      capability->deviceCapability2.endEndTlpPrefixSupported  ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Max end-end TLP prefixes",                          mprintf("%u",     capability->deviceCapability2.maxEndEndTlpPrefixes),                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Emergency power reduction supported",               mprintf("%u",     capability->deviceCapability2.emergencyPowerReductionSupported),                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Emergency power reduction initialization required", capability->deviceCapability2.emergencyPowerReductionInitializationRequired ? "Yes" : "No",               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device capability 2: Frs supported",                                     capability->deviceCapability2.frsSupported                                  ? "Yes" : "No",               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2",                                                       mprintf("0x%04X", capability->deviceControl2.value16),                                                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: Completion timeout value",                             strdup(enumToFullString((PciExpressCompletionTimeout)capability->deviceControl2.completionTimeoutValue)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: Completion timeout disable",                           capability->deviceControl2.completionTimeoutDisable       ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: ARI forwarding enable",                                capability->deviceControl2.ariForwardingEnable            ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: AtomicOp requester enable",                            capability->deviceControl2.atomicOpRequesterEnable        ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: AtomicOp egress blocking",                             capability->deviceControl2.atomicOpEgressBlocking         ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: IDO request enable",                                   capability->deviceControl2.idoRequestEnable               ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: IDO completion enable",                                capability->deviceControl2.idoCompletionEnable            ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: LTR mechanism enable",                                 capability->deviceControl2.ltrMechanismEnable             ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: Emergency power reduction request",                    capability->deviceControl2.emergencyPowerReductionRequest ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: Ten bit tag requester enable",                         capability->deviceControl2.tenBitTagRequesterEnable       ? "Yes" : "No",                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: Obff",                                                 mprintf("%u",     capability->deviceControl2.obff),                                                       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device control 2: End-End TLP prefix blocking",                          capability->deviceControl2.endEndTlpPrefixBlocking ? "Yes" : "No",                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Device status 2",                                                        mprintf("0x%04X", capability->deviceStatus2.value16),                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability 2",                                                      mprintf("0x%08X", capability->linkCapability2.value32),                                                   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability 2: Link speeds vector",                                  mprintf("%u",     capability->linkCapability2.linkSpeedsVector),                                          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link capability 2: Crosslink",                                           capability->linkCapability2.crosslink ? "Yes" : "No",                                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control 2",                                                         mprintf("0x%04X", capability->linkControl2.value16),                                                      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control 2: Target link speed",                                      strdup(enumToFullString((PciExpressLinkSpeed)capability->linkControl2.targetLinkSpeed)),                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control 2: Enter compliance",                                       capability->linkControl2.enterCompliance                ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control 2: Hardware autonomous speed disable",                      capability->linkControl2.hardwareAutonomousSpeedDisable ? "Yes" : "No",                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control 2: Selectable de-emphasis",                                 strdup(enumToFullString((PciExpressDeemphasis)capability->linkControl2.selectableDeemphasis)),            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control 2: Transmit margin",                                        mprintf("%u",     capability->linkControl2.transmitMargin),                                               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control 2: Enter modified compliance",                              capability->linkControl2.enterModifiedCompliance ? "Yes" : "No",                                          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control 2: Compliance SOS",                                         capability->linkControl2.complianceSos           ? "Yes" : "No",                                          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link control 2: Compliance de-emphasis",                                 strdup(enumToFullString((PciExpressDeemphasis)capability->linkControl2.complianceDeemphasis)),            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status 2",                                                          mprintf("0x%04X", capability->linkStatus2.value16),                                                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status 2: Current de-emphasis level",                               strdup(enumToFullString((PciExpressDeemphasis)capability->linkStatus2.currentDeemphasisLevel)),           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status 2: Equalization complete",                                   capability->linkStatus2.equalizationComplete         ? "Yes" : "No",                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status 2: Equalization phase 1 successful",                         capability->linkStatus2.equalizationPhase1Successful ? "Yes" : "No",                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status 2: Equalization phase 2 successful",                         capability->linkStatus2.equalizationPhase2Successful ? "Yes" : "No",                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status 2: Equalization phase 3 successful",                         capability->linkStatus2.equalizationPhase3Successful ? "Yes" : "No",                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Link status 2: Link equalization request",                               capability->linkStatus2.linkEqualizationRequest      ? "Yes" : "No",                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot capability 2",                                                      mprintf("0x%08X", capability->slotCapability2.value32),                                                   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot control 2",                                                         mprintf("0x%04X", capability->slotControl2.value16),                                                      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("PCI-E - Slot status 2",                                                          mprintf("0x%04X", capability->slotStatus2.value16),                                                       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
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

NgosStatus DeviceManagerPci::initPciMessageSignaledInterruptsExtendedCapability(PciMessageSignaledInterruptsExtendedCapability *capability, DeviceManagerEntry *deviceManagerEntry)
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI-X - Message control",               mprintf("0x%04X", capability->messageControl.value16),             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI-X - Message control: Enable MSI-X", capability->messageControl.enableMSIX ? "Yes" : "No",              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI-X - Message control: Table size",   mprintf("%u", capability->messageControl.tableSizeReal()),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI-X - Message address upper",         mprintf("0x%08X", capability->messageAddressUpper),                DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI-X - Base address indicator",        mprintf("%u", capability->tableOffsetAndBir.baseAddressIndicator), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("MSI-X - Table offset",                  mprintf("%u", capability->tableOffsetAndBir.tableOffset),          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithExtendedConfigurationSpace(const PciExtendedConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry)
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



        if (capability->nextCapabilityOffset == 0)
        {
            break;
        }

        capability = (PciExtendedCapabilityHeader *)((u64)&configurationSpace + capability->nextCapabilityOffset - sizeof(PciConfigurationSpace));
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithExtendedCapability(PciExtendedCapabilityHeader *capability, DeviceManagerEntry *deviceManagerEntry)
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



    return NgosStatus::OK;
}
