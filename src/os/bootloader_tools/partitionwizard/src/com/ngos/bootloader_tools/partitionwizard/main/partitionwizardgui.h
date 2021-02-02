#ifndef COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_MAIN_PARTITIONWIZARDGUI_H
#define COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_MAIN_PARTITIONWIZARDGUI_H



#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/containers/arraylist.h>
#include <com/ngos/shared/common/gui/widgets/controls/button.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerprotocol.h>
#include <com/ngos/shared/common/uefi/uefisimplepointerprotocol.h>



class PartitionWizardGUI
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

    static NgosStatus onRebootButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShutdownButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO

    static Button     *sRebootButton;
    static Button     *sShutdownButton;
    static bad_uint16         sWaitEventsCount;
    static uefi_event *sWaitEvents;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_MAIN_PARTITIONWIZARDGUI_H
