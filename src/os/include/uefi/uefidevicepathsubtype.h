#ifndef UEFI_UEFIDEVICEPATHSUBTYPE_H
#define UEFI_UEFIDEVICEPATHSUBTYPE_H



#include <ngos/types.h>



enum class UefiDevicePathSubType : u8
{
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
    MSG_IPv4_DP                = 0x0C,
    MSG_IPv6_DP                = 0x0D,
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

    BBS_BBS_DP = 0x01
};



#endif // UEFI_UEFIDEVICEPATHSUBTYPE_H
