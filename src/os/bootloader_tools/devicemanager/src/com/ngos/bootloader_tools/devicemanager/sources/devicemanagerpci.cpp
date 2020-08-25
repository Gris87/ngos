#include "devicemanagerpci.h"

#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/common/pci/database/generated/pcibaseclass.h>
#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>
#include <com/ngos/shared/common/pci/macros.h>
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



                            UEFI_ASSERT_EXECUTION(initPciWithConfigurationSpace(configurationSpace, deviceManagerEntry), NgosStatus::ASSERTION);



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

NgosStatus DeviceManagerPci::initPciWithConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | configurationSpace = ..., deviceManagerEntry = 0x%p", deviceManagerEntry));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("configurationSpace.header.vendorId                       = 0x%04X (%s)",            configurationSpace.header.vendorId, enumToHumanString(configurationSpace.header.vendorId)));
        UEFI_LVVV(("configurationSpace.header.deviceId                       = 0x%04X (%s)",            configurationSpace.header.deviceId, enumToHumanString(configurationSpace.header.vendorId, configurationSpace.header.deviceId)));
        UEFI_LVVV(("configurationSpace.header.command                        = %s",                     flagsToFullString(configurationSpace.header.command)));
        UEFI_LVVV(("configurationSpace.header.status.reserved                = %u",                     configurationSpace.header.status.reserved));
        UEFI_LVVV(("configurationSpace.header.status.interruptStatus         = %s",                     boolToString(configurationSpace.header.status.interruptStatus)));
        UEFI_LVVV(("configurationSpace.header.status.capabilitiesList        = %s",                     boolToString(configurationSpace.header.status.capabilitiesList)));
        UEFI_LVVV(("configurationSpace.header.status.support64MHz            = %s",                     boolToString(configurationSpace.header.status.support64MHz)));
        UEFI_LVVV(("configurationSpace.header.status.reserved1               = %u",                     configurationSpace.header.status.reserved1));
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
        UEFI_LVVV(("configurationSpace.header.builtInSelfTest.reserved       = %u",                     configurationSpace.header.builtInSelfTest.reserved));
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
        case PciHeaderType::DEVICE:            UEFI_ASSERT_EXECUTION(initPciWithDeviceConfigurationSpace(configurationSpace, deviceManagerEntry),  NgosStatus::ASSERTION); break;
        case PciHeaderType::PCI_TO_PCI_BRIDGE: UEFI_ASSERT_EXECUTION(initPciWithBridgeConfigurationSpace(configurationSpace, deviceManagerEntry),  NgosStatus::ASSERTION); break;
        case PciHeaderType::CARDBUS_BRIDGE:    UEFI_ASSERT_EXECUTION(initPciWithCardBusConfigurationSpace(configurationSpace, deviceManagerEntry), NgosStatus::ASSERTION); break;

        default:
        {
            UEFI_LF(("Unexpected PCI header type %s", enumToFullString((PciHeaderType)configurationSpace.header.headerType.type)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithDeviceConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | configurationSpace = ..., deviceManagerEntry = 0x%p", deviceManagerEntry));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[0]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[0]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[1]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[1]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[2]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[2]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[3]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[3]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[4]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[4]));
        UEFI_LVVV(("configurationSpace.device.baseAddressRegisters[5]         = 0x%08X",      configurationSpace.device.baseAddressRegisters[5]));
        UEFI_LVVV(("configurationSpace.device.cardInformationStructurePointer = 0x%08X",      configurationSpace.device.cardInformationStructurePointer));
        UEFI_LVVV(("configurationSpace.device.subsystemVendorID               = 0x%04X (%s)", configurationSpace.device.subsystemVendorID, enumToHumanString(configurationSpace.device.subsystemVendorID)));
        UEFI_LVVV(("configurationSpace.device.subsystemID                     = 0x%04X",      configurationSpace.device.subsystemID));
        UEFI_LVVV(("configurationSpace.device.expansionRomBaseAddress         = 0x%08X",      configurationSpace.device.expansionRomBaseAddress));
        UEFI_LVVV(("configurationSpace.device.capabilitiesPointer             = 0x%02X",      configurationSpace.device.capabilitiesPointer));
        UEFI_LVVV(("configurationSpace.device.interruptLine                   = %u",          configurationSpace.device.interruptLine));
        UEFI_LVVV(("configurationSpace.device.interruptPin                    = %u",          configurationSpace.device.interruptPin));
        UEFI_LVVV(("configurationSpace.device.minGrant                        = %u",          configurationSpace.device.minGrant));
        UEFI_LVVV(("configurationSpace.device.maxLatency                      = %u",          configurationSpace.device.maxLatency));
    }



    // Fill Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #0",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[0]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #1",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[1]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #2",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[2]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #3",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[3]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #4",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[4]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Base address register #5",           mprintf("0x%08X", configurationSpace.device.baseAddressRegisters[5]),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Card information structure pointer", mprintf("0x%08X", configurationSpace.device.cardInformationStructurePointer), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem vendor ID",                mprintf("0x%04X", configurationSpace.device.subsystemVendorID),               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Subsystem ID",                       mprintf("0x%04X", configurationSpace.device.subsystemID),                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Expansion ROM base address",         mprintf("0x%08X", configurationSpace.device.expansionRomBaseAddress),         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Capabilities pointer",               mprintf("0x%02X", configurationSpace.device.capabilitiesPointer),             DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt line",                     mprintf("%u",     configurationSpace.device.interruptLine),                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interrupt pin",                      mprintf("%u",     configurationSpace.device.interruptPin),                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum grant",                      mprintf("%u",     configurationSpace.device.minGrant),                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum latency",                    mprintf("%u",     configurationSpace.device.maxLatency),                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(initPciWithCapabilitiesPointer(configurationSpace, configurationSpace.device.capabilitiesPointer, deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithBridgeConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | configurationSpace = ..., deviceManagerEntry = 0x%p", deviceManagerEntry));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



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
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.reserved              = %u",     configurationSpace.bridge.secondaryStatus.reserved));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.interruptStatus       = %s",     boolToString(configurationSpace.bridge.secondaryStatus.interruptStatus)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.capabilitiesList      = %s",     boolToString(configurationSpace.bridge.secondaryStatus.capabilitiesList)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.support64MHz          = %s",     boolToString(configurationSpace.bridge.secondaryStatus.support64MHz)));
        UEFI_LVVV(("configurationSpace.bridge.secondaryStatus.reserved1             = %u",     configurationSpace.bridge.secondaryStatus.reserved1));
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
        UEFI_LVVV(("configurationSpace.bridge.bridgeControl                         = %u",     configurationSpace.bridge.bridgeControl));
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bridge control",                              mprintf("%u",     configurationSpace.bridge.bridgeControl),                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    UEFI_ASSERT_EXECUTION(initPciWithCapabilitiesPointer(configurationSpace, configurationSpace.bridge.capabilitiesPointer, deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithCardBusConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | configurationSpace = ..., deviceManagerEntry = 0x%p", deviceManagerEntry));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("configurationSpace.cardBus.cardBusSocket                         = 0x%08X", configurationSpace.cardBus.cardBusSocket));
        UEFI_LVVV(("configurationSpace.cardBus.capabilitiesPointer                   = 0x%02X", configurationSpace.cardBus.capabilitiesPointer));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.reserved              = %u",     configurationSpace.cardBus.secondaryStatus.reserved));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.interruptStatus       = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.interruptStatus)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.capabilitiesList      = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.capabilitiesList)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.support64MHz          = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.support64MHz)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.reserved1             = %u",     configurationSpace.cardBus.secondaryStatus.reserved1));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.fastBackToBackCapable = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.fastBackToBackCapable)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.masterDataParityError = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.masterDataParityError)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.deviceSelectTiming    = %s",     enumToFullString((PciDeviceSelectTiming)configurationSpace.cardBus.secondaryStatus.deviceSelectTiming)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.signaledTargetAbort   = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.signaledTargetAbort)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.receivedTargetAbort   = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.receivedTargetAbort)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.receivedMasterAbort   = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.receivedMasterAbort)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.signaledSystemError   = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.signaledSystemError)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.detectedParityError   = %s",     boolToString(configurationSpace.cardBus.secondaryStatus.detectedParityError)));
        UEFI_LVVV(("configurationSpace.cardBus.secondaryStatus.value16               = 0x%04X", configurationSpace.cardBus.secondaryStatus.value16));
        UEFI_LVVV(("configurationSpace.cardBus.pciBusNumber                          = %u",     configurationSpace.cardBus.pciBusNumber));
        UEFI_LVVV(("configurationSpace.cardBus.cardBusBusNumber                      = %u",     configurationSpace.cardBus.cardBusBusNumber));
        UEFI_LVVV(("configurationSpace.cardBus.subordinateBusNumber                  = %u",     configurationSpace.cardBus.subordinateBusNumber));
        UEFI_LVVV(("configurationSpace.cardBus.cardBusLatencyTimer                   = %u",     configurationSpace.cardBus.cardBusLatencyTimer));
        UEFI_LVVV(("configurationSpace.cardBus.memoryBase0                           = 0x%08X", configurationSpace.cardBus.memoryBase0));
        UEFI_LVVV(("configurationSpace.cardBus.memoryLimit0                          = 0x%08X", configurationSpace.cardBus.memoryLimit0));
        UEFI_LVVV(("configurationSpace.cardBus.memoryBase1                           = 0x%08X", configurationSpace.cardBus.memoryBase1));
        UEFI_LVVV(("configurationSpace.cardBus.memoryLimit1                          = 0x%08X", configurationSpace.cardBus.memoryLimit1));
        UEFI_LVVV(("configurationSpace.cardBus.ioBase0                               = 0x%08X", configurationSpace.cardBus.ioBase0));
        UEFI_LVVV(("configurationSpace.cardBus.ioLimit0                              = 0x%08X", configurationSpace.cardBus.ioLimit0));
        UEFI_LVVV(("configurationSpace.cardBus.ioBase1                               = 0x%08X", configurationSpace.cardBus.ioBase1));
        UEFI_LVVV(("configurationSpace.cardBus.ioLimit1                              = 0x%08X", configurationSpace.cardBus.ioLimit1));
        UEFI_LVVV(("configurationSpace.cardBus.interruptLine                         = %u",     configurationSpace.cardBus.interruptLine));
        UEFI_LVVV(("configurationSpace.cardBus.interruptPin                          = %u",     configurationSpace.cardBus.interruptPin));
        UEFI_LVVV(("configurationSpace.cardBus.bridgeControl                         = %u",     configurationSpace.cardBus.bridgeControl));
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
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bridge control",                              mprintf("%u",     configurationSpace.cardBus.bridgeControl),                                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    UEFI_ASSERT_EXECUTION(initPciWithCapabilitiesPointer(configurationSpace, configurationSpace.cardBus.capabilitiesPointer, deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithCapabilitiesPointer(const PciConfigurationSpace &configurationSpace, u8 capabilityPointer, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | configurationSpace = ..., capabilityPointer = 0x%02X, deviceManagerEntry = 0x%p", capabilityPointer, deviceManagerEntry));

    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



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



        UEFI_ASSERT_EXECUTION(initPciWithCapability(capability, deviceManagerEntry), NgosStatus::ASSERTION);



        if (capability->nextCapabilityPointer == capabilityPointer)
        {
            break;
        }

        capabilityPointer = capability->nextCapabilityPointer;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerPci::initPciWithCapability(PciCapabilityHeader *capability, DeviceManagerEntry *deviceManagerEntry)
{
    UEFI_LT((" | capability = 0x%p, deviceManagerEntry = 0x%p", capability, deviceManagerEntry));

    UEFI_ASSERT(capability         != nullptr, "capability is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(deviceManagerEntry != nullptr, "deviceManagerEntry is null", NgosStatus::ASSERTION);



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
        case PciCapabilityType::POWER_MANAGEMENT_INTERFACE: UEFI_ASSERT_EXECUTION(initPciWithPciPowerManagementInterfaceCapability((PciPowerManagementInterfaceCapability *)capability, deviceManagerEntry), NgosStatus::ASSERTION); break;
        case PciCapabilityType::ACCELERATED_GRAPHICS_PORT:  UEFI_ASSERT_EXECUTION(initPciWithPciAcceleratedGraphicsPortCapability((PciAcceleratedGraphicsPortCapability *)capability,   deviceManagerEntry), NgosStatus::ASSERTION); break;

        default:
        {
            UEFI_LF(("Unexpected PCI capability %s", enumToFullString(capability->capabilityId)));
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
        UEFI_LF(("capability->capabilities.version                      = %u",     capability->capabilities.version));
        UEFI_LF(("capability->capabilities.pmeClock                     = %u",     capability->capabilities.pmeClock));
        UEFI_LF(("capability->capabilities.deviceSpecificInitialization = %u",     capability->capabilities.deviceSpecificInitialization));
        UEFI_LF(("capability->capabilities.auxCurrent                   = %s",     enumToFullString((PciPowerManagementAuxCurrent)capability->capabilities.auxCurrent)));
        UEFI_LF(("capability->capabilities.supportD1                    = %u",     capability->capabilities.supportD1));
        UEFI_LF(("capability->capabilities.supportD2                    = %u",     capability->capabilities.supportD2));
        UEFI_LF(("capability->capabilities.supportPme                   = %s",     flagsToFullString(supportPme)));
        UEFI_LF(("capability->capabilities.value16                      = 0x%04X", capability->capabilities.value16));
        UEFI_LF(("capability->controlStatus.powerState                  = %s",     enumToFullString((PciPowerManagementPowerState)capability->controlStatus.powerState)));
        UEFI_LF(("capability->controlStatus.noSoftReset                 = %u",     capability->controlStatus.noSoftReset));
        UEFI_LF(("capability->controlStatus.enablePme                   = %u",     capability->controlStatus.enablePme));
        UEFI_LF(("capability->controlStatus.dataSelect                  = %u",     capability->controlStatus.dataSelect));
        UEFI_LF(("capability->controlStatus.dataScale                   = %u",     capability->controlStatus.dataScale));
        UEFI_LF(("capability->controlStatus.pmeStatus                   = %u",     capability->controlStatus.pmeStatus));
        UEFI_LF(("capability->controlStatus.value16                     = 0x%04X", capability->controlStatus.value16));
        UEFI_LF(("capability->bridgeExtention.b2B3ForD3Hot              = %u",     capability->bridgeExtention.b2B3ForD3Hot));
        UEFI_LF(("capability->bridgeExtention.busPowerClockControl      = %u",     capability->bridgeExtention.busPowerClockControl));
        UEFI_LF(("capability->bridgeExtention.value8                    = 0x%02X", capability->bridgeExtention.value8));
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
