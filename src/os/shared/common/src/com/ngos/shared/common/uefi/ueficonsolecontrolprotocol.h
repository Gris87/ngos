#ifndef UEFI_UEFICONSOLECONTROLPROTOCOL_H
#define UEFI_UEFICONSOLECONTROLPROTOCOL_H



#include <common/src/com/ngos/shared/common/uefi/macros.h>
#include <common/src/com/ngos/shared/common/uefi/ueficonsolecontrolscreenmode.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_CONSOLE_CONTROL_PROTOCOL_GUID \
    { 0xF42F7782, 0x012E, 0x4C12, { 0x99, 0x56, 0x49, 0xF9, 0x43, 0x04, 0xF7, 0x21 } }



struct UefiConsoleControlProtocol
{
    UefiStatus (UEFI_API *getMode)(UefiConsoleControlProtocol *obj, UefiConsoleControlScreenMode *mode, bool *ugaExists, bool *stdInLocked); // TEST: NO
    UefiStatus (UEFI_API *setMode)(UefiConsoleControlProtocol *obj, UefiConsoleControlScreenMode mode); // TEST: NO
    UefiStatus (UEFI_API *lockStdIn)(UefiConsoleControlProtocol *obj, char16 *password); // TEST: NO
};



#endif // UEFI_UEFICONSOLECONTROLPROTOCOL_H
