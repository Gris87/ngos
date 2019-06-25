#ifndef UEFI_UEFIDEVICEPATHTOTEXTPROTOCOL_H
#define UEFI_UEFIDEVICEPATHTOTEXTPROTOCOL_H



#include <uefi/macros.h>
#include <uefi/types.h>
#include <uefi/uefidevicepath.h>



#define UEFI_DEVICE_PATH_TO_TEXT_PROTOCOL_GUID \
    { 0x8B843E20, 0x8132, 0x4852, {0x90, 0xCC, 0x55, 0x1A, 0x4E, 0x4A, 0x7F, 0x1C} }



struct UefiDevicePathToTextProtocol
{
    char16* (UEFI_API *convertDeviceNodeToText)(const UefiDevicePath *deviceNode, bool displayOnly, bool allowShortcuts); // TEST: NO
    char16* (UEFI_API *convertDevicePathToText)(const UefiDevicePath *devicePath, bool displayOnly, bool allowShortcuts); // TEST: NO
};



#endif // UEFI_UEFIDEVICEPATHTOTEXTPROTOCOL_H
