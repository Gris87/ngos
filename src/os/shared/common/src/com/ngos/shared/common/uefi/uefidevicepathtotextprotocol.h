#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIDEVICEPATHTOTEXTPROTOCOL_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIDEVICEPATHTOTEXTPROTOCOL_H



#include <common/src/com/ngos/shared/common/uefi/macros.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefidevicepath.h>



#define UEFI_DEVICE_PATH_TO_TEXT_PROTOCOL_GUID \
    { 0x8B843E20, 0x8132, 0x4852, { 0x90, 0xCC, 0x55, 0x1A, 0x4E, 0x4A, 0x7F, 0x1C } }



struct UefiDevicePathToTextProtocol
{
    char16* (UEFI_API *convertDeviceNodeToText)(const UefiDevicePath *deviceNode, bool displayOnly, bool allowShortcuts); // TEST: NO
    char16* (UEFI_API *convertDevicePathToText)(const UefiDevicePath *devicePath, bool displayOnly, bool allowShortcuts); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIDEVICEPATHTOTEXTPROTOCOL_H
