#ifndef BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADERGUI_H
#define BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADERGUI_H



#include <bootparams/bootparams.h>
#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <ngos/status.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefisimplepointerprotocol.h>

#include "src/bits64/other/ostype.h"
#include "src/bits64/other/volumetype.h"



class BootloaderGUI
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO
    static NgosStatus exec(); // TEST: NO
    static NgosStatus cleanUp(); // TEST: NO

private:
    static NgosStatus focusOsButton(); // TEST: NO
    static NgosStatus focusFirstOsButton(); // TEST: NO
    static NgosStatus focusOsButtonLeft(); // TEST: NO
    static NgosStatus focusOsButtonRight(); // TEST: NO
    static NgosStatus focusPreviousOsButton(); // TEST: NO
    static NgosStatus focusNextOsButton(); // TEST: NO
    static NgosStatus focusNextOsButtonOrGoDown(); // TEST: NO

    static NgosStatus generateWaitEventList(); // TEST: NO
    static NgosStatus waitForEvent(); // TEST: NO
    static NgosStatus processKeyboardEvent(); // TEST: NO
    static NgosStatus processSimplePointerEvent(UefiSimplePointerProtocol *pointer); // TEST: NO
    static NgosStatus processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer); // TEST: NO
    static NgosStatus processTimerEvent(); // TEST: NO
    static NgosStatus disableTimerEvent(); // TEST: NO

    static NgosStatus onRebootButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShutdownButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onOsButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onLeftButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onRightButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onCpuTestButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onMemoryTestButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onNetworkTestButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onHddTestButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onPartitionWizardButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShellButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO
    static NgosStatus onOsButtonPressed(); // TEST: NO
    static NgosStatus onLeftButtonPressed(); // TEST: NO
    static NgosStatus onRightButtonPressed(); // TEST: NO
    static NgosStatus onCpuTestButtonPressed(); // TEST: NO
    static NgosStatus onMemoryTestButtonPressed(); // TEST: NO
    static NgosStatus onNetworkTestButtonPressed(); // TEST: NO
    static NgosStatus onHddTestButtonPressed(); // TEST: NO
    static NgosStatus onPartitionWizardButtonPressed(); // TEST: NO
    static NgosStatus onShellButtonPressed(); // TEST: NO

    static Image               *sBackgroundImage;
    static Image               *sButtonNormalImage;
    static Image               *sButtonHoverImage;
    static Image               *sButtonPressedImage;
    static Image               *sButtonFocusedImage;
    static Image               *sButtonFocusedHoverImage;
    static Image               *sCpuTestImage;
    static Image               *sMemoryTestImage;
    static Image               *sNetworkTestImage;
    static Image               *sHddTestImage;
    static Image               *sPartitionWizardImage;
    static Image               *sShellImage;
    static Image               *sRebootImage;
    static Image               *sShutdownImage;
    static Image               *sCursorImage;
    static Image*               sOsImages[(u64)OsType::MAXIMUM];
    static Image*               sVolumeImages[(u64)VolumeType::MAXIMUM];
    static Button              *sRebootButton;
    static Button              *sShutdownButton;
    static ArrayList<Button *>  sOsButtons;
    static u64                  sOsButtonLeft;
    static u64                  sOsButtonRight;
    static u64                  sOsButtonSelected;
    static Button              *sLeftButton;
    static Button              *sRightButton;
    static LabelWidget         *sTimeoutLabelWidget;
    static u8                   sTimeoutTick;
    static Button              *sCpuTestButton;
    static Button              *sMemoryTestButton;
    static Button              *sNetworkTestButton;
    static Button              *sHddTestButton;
    static Button              *sPartitionWizardButton;
    static Button              *sShellButton;
    static u16                  sWaitEventsCount;
    static uefi_event          *sWaitEvents;
    static uefi_event           sTimerEvent;
};



#endif // BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADERGUI_H
