#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIDEVICEPATHSUBTYPE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIDEVICEPATHSUBTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/uefi/uefidevicepathtype.h>



enum class UefiDevicePathSubType: bad_uint8 // Ignore CppEnumVerifier
{
    NONE = 0,

    // UefiDevicePathType::HARDWARE_DEVICE_PATH

    HW_PCI_DP        = 0x01,
    HW_PCCARD_DP     = 0x02,
    HW_MEMMAP_DP     = 0x03,
    HW_VENDOR_DP     = 0x04,
    HW_CONTROLLER_DP = 0x05,
    HW_BMC_DP        = 0x06,

    // UefiDevicePathType::ACPI_DEVICE_PATH

    ACPI_DP          = 0x01,
    ACPI_EXTENDED_DP = 0x02,
    ACPI_ADR_DP      = 0x03,

    // UefiDevicePathType::MESSAGING_DEVICE_PATH

    MSG_ATAPI_DP               = 0x01,
    MSG_SCSI_DP                = 0x02,
    MSG_FIBRECHANNEL_DP        = 0x03,
    MSG_1394_DP                = 0x04,
    MSG_USB_DP                 = 0x05,
    MSG_I2O_DP                 = 0x06,
    MSG_INFINIBAND_DP          = 0x09,
    MSG_VENDOR_DP              = 0x0A,
    MSG_MAC_ADDR_DP            = 0x0B,
    MSG_IPV4_DP                = 0x0C,
    MSG_IPV6_DP                = 0x0D,
    MSG_UART_DP                = 0x0E,
    MSG_USB_CLASS_DP           = 0x0F,
    MSG_USB_WWID_DP            = 0x10,
    MSG_DEVICE_LOGICAL_UNIT_DP = 0x11,
    MSG_SATA_DP                = 0x12,
    MSG_ISCSI_DP               = 0x13,
    MSG_VLAN_DP                = 0x14,
    MSG_FIBRECHANNELEX_DP      = 0x15,
    MSG_SASEX_DP               = 0x16,
    MSG_NVME_NAMESPACE_DP      = 0x17,
    MSG_URI_DP                 = 0x18,
    MSG_UFS_DP                 = 0x19,
    MSG_SD_DP                  = 0x1A,
    MSG_BLUETOOTH_DP           = 0x1B,
    MSG_WIFI_DP                = 0x1C,
    MSG_EMMC_DP                = 0x1D,
    MSG_BLUETOOTH_LE_DP        = 0x1E,
    MSG_DNS_DP                 = 0x1F,

    // UefiDevicePathType::MEDIA_DEVICE_PATH

    MEDIA_HARDDRIVE_DP             = 0x01,
    MEDIA_CDROM_DP                 = 0x02,
    MEDIA_VENDOR_DP                = 0x03,
    MEDIA_FILEPATH_DP              = 0x04,
    MEDIA_PROTOCOL_DP              = 0x05,
    MEDIA_PIWG_FW_FILE_DP          = 0x06,
    MEDIA_PIWG_FW_VOL_DP           = 0x07,
    MEDIA_RELATIVE_OFFSET_RANGE_DP = 0x08,
    MEDIA_RAM_DISK_DP              = 0x09,

    // UefiDevicePathType::BBS_DEVICE_PATH

    BBS_BBS_DP = 0x01,

    // UefiDevicePathType::END_DEVICE_PATH_TYPE

    END_ENTIRE_DEVICE_PATH_SUBTYPE = 0xFF
};



inline const char8* enumToString(UefiDevicePathType type, UefiDevicePathSubType subtype) // TEST: NO
{
    // COMMON_LT((" | type = %u, subtype = %u", type, subtype)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiDevicePathType::HARDWARE_DEVICE_PATH:
        {
            switch (subtype)
            {
                case UefiDevicePathSubType::HW_PCI_DP:        return "HW_PCI_DP";
                case UefiDevicePathSubType::HW_PCCARD_DP:     return "HW_PCCARD_DP";
                case UefiDevicePathSubType::HW_MEMMAP_DP:     return "HW_MEMMAP_DP";
                case UefiDevicePathSubType::HW_VENDOR_DP:     return "HW_VENDOR_DP";
                case UefiDevicePathSubType::HW_CONTROLLER_DP: return "HW_CONTROLLER_DP";
                case UefiDevicePathSubType::HW_BMC_DP:        return "HW_BMC_DP";

                default: return "UNKNOWN";
            }
        }
        break;

        case UefiDevicePathType::ACPI_DEVICE_PATH:
        {
            switch (subtype)
            {
                case UefiDevicePathSubType::ACPI_DP:          return "ACPI_DP";
                case UefiDevicePathSubType::ACPI_EXTENDED_DP: return "ACPI_EXTENDED_DP";
                case UefiDevicePathSubType::ACPI_ADR_DP:      return "ACPI_ADR_DP";

                default: return "UNKNOWN";
            }
        }
        break;

        case UefiDevicePathType::MESSAGING_DEVICE_PATH:
        {
            switch (subtype)
            {
                case UefiDevicePathSubType::MSG_ATAPI_DP:               return "MSG_ATAPI_DP";
                case UefiDevicePathSubType::MSG_SCSI_DP:                return "MSG_SCSI_DP";
                case UefiDevicePathSubType::MSG_FIBRECHANNEL_DP:        return "MSG_FIBRECHANNEL_DP";
                case UefiDevicePathSubType::MSG_1394_DP:                return "MSG_1394_DP";
                case UefiDevicePathSubType::MSG_USB_DP:                 return "MSG_USB_DP";
                case UefiDevicePathSubType::MSG_I2O_DP:                 return "MSG_I2O_DP";
                case UefiDevicePathSubType::MSG_INFINIBAND_DP:          return "MSG_INFINIBAND_DP";
                case UefiDevicePathSubType::MSG_VENDOR_DP:              return "MSG_VENDOR_DP";
                case UefiDevicePathSubType::MSG_MAC_ADDR_DP:            return "MSG_MAC_ADDR_DP";
                case UefiDevicePathSubType::MSG_IPV4_DP:                return "MSG_IPV4_DP";
                case UefiDevicePathSubType::MSG_IPV6_DP:                return "MSG_IPV6_DP";
                case UefiDevicePathSubType::MSG_UART_DP:                return "MSG_UART_DP";
                case UefiDevicePathSubType::MSG_USB_CLASS_DP:           return "MSG_USB_CLASS_DP";
                case UefiDevicePathSubType::MSG_USB_WWID_DP:            return "MSG_USB_WWID_DP";
                case UefiDevicePathSubType::MSG_DEVICE_LOGICAL_UNIT_DP: return "MSG_DEVICE_LOGICAL_UNIT_DP";
                case UefiDevicePathSubType::MSG_SATA_DP:                return "MSG_SATA_DP";
                case UefiDevicePathSubType::MSG_ISCSI_DP:               return "MSG_ISCSI_DP";
                case UefiDevicePathSubType::MSG_VLAN_DP:                return "MSG_VLAN_DP";
                case UefiDevicePathSubType::MSG_FIBRECHANNELEX_DP:      return "MSG_FIBRECHANNELEX_DP";
                case UefiDevicePathSubType::MSG_SASEX_DP:               return "MSG_SASEX_DP";
                case UefiDevicePathSubType::MSG_NVME_NAMESPACE_DP:      return "MSG_NVME_NAMESPACE_DP";
                case UefiDevicePathSubType::MSG_URI_DP:                 return "MSG_URI_DP";
                case UefiDevicePathSubType::MSG_UFS_DP:                 return "MSG_UFS_DP";
                case UefiDevicePathSubType::MSG_SD_DP:                  return "MSG_SD_DP";
                case UefiDevicePathSubType::MSG_BLUETOOTH_DP:           return "MSG_BLUETOOTH_DP";
                case UefiDevicePathSubType::MSG_WIFI_DP:                return "MSG_WIFI_DP";
                case UefiDevicePathSubType::MSG_EMMC_DP:                return "MSG_EMMC_DP";
                case UefiDevicePathSubType::MSG_BLUETOOTH_LE_DP:        return "MSG_BLUETOOTH_LE_DP";
                case UefiDevicePathSubType::MSG_DNS_DP:                 return "MSG_DNS_DP";

                default: return "UNKNOWN";
            }
        }
        break;

        case UefiDevicePathType::MEDIA_DEVICE_PATH:
        {
            switch (subtype)
            {
                case UefiDevicePathSubType::MEDIA_HARDDRIVE_DP:             return "MEDIA_HARDDRIVE_DP";
                case UefiDevicePathSubType::MEDIA_CDROM_DP:                 return "MEDIA_CDROM_DP";
                case UefiDevicePathSubType::MEDIA_VENDOR_DP:                return "MEDIA_VENDOR_DP";
                case UefiDevicePathSubType::MEDIA_FILEPATH_DP:              return "MEDIA_FILEPATH_DP";
                case UefiDevicePathSubType::MEDIA_PROTOCOL_DP:              return "MEDIA_PROTOCOL_DP";
                case UefiDevicePathSubType::MEDIA_PIWG_FW_FILE_DP:          return "MEDIA_PIWG_FW_FILE_DP";
                case UefiDevicePathSubType::MEDIA_PIWG_FW_VOL_DP:           return "MEDIA_PIWG_FW_VOL_DP";
                case UefiDevicePathSubType::MEDIA_RELATIVE_OFFSET_RANGE_DP: return "MEDIA_RELATIVE_OFFSET_RANGE_DP";
                case UefiDevicePathSubType::MEDIA_RAM_DISK_DP:              return "MEDIA_RAM_DISK_DP";

                default: return "UNKNOWN";
            }
        }
        break;

        case UefiDevicePathType::BBS_DEVICE_PATH:
        {
            switch (subtype)
            {
                case UefiDevicePathSubType::BBS_BBS_DP: return "BBS_BBS_DP";

                default: return "UNKNOWN";
            }
        }
        break;

        case UefiDevicePathType::END_DEVICE_PATH_TYPE:
        {
            switch (subtype)
            {
                case UefiDevicePathSubType::END_ENTIRE_DEVICE_PATH_SUBTYPE: return "END_ENTIRE_DEVICE_PATH_SUBTYPE";

                default: return "UNKNOWN";
            }
        }
        break;

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiDevicePathType type, UefiDevicePathSubType subtype) // TEST: NO
{
    // COMMON_LT((" | type = %u, subtype = %u", type, subtype)); // Commented to avoid bad looking logs



    static char8 res[38];

    sprintf(res, "0x%02X (%s)", (bad_uint8)subtype, enumToString(type, subtype));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIDEVICEPATHSUBTYPE_H
