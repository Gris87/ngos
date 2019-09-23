#ifndef BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADERGUI_H
#define BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADERGUI_H



#include <bootparams/bootparams.h>
#include <ngos/status.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefisimplepointerprotocol.h>



class BootloaderGUI
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO
    static NgosStatus exec(); // TEST: NO

private:
    static NgosStatus generateWaitEventList(); // TEST: NO
    static NgosStatus waitForEvent(); // TEST: NO
    static NgosStatus processKeyboardEvent(); // TEST: NO
    static NgosStatus processSimplePointerEvent(UefiSimplePointerProtocol *pointer); // TEST: NO
    static NgosStatus processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer); // TEST: NO
    static NgosStatus processTimerEvent(); // TEST: NO
    static NgosStatus disableTimerEvent(); // TEST: NO

    static u16         sWaitEventsCount;
    static uefi_event *sWaitEvents;
    static uefi_event  sTimerEvent;
};



#endif // BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADERGUI_H
