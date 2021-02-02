#ifndef COM_NGOS_BOOTLOADER_TOOLS_HDDTEST_MAIN_HDDTESTGUI_H
#define COM_NGOS_BOOTLOADER_TOOLS_HDDTEST_MAIN_HDDTESTGUI_H



#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/containers/arraylist.h>
#include <com/ngos/shared/common/gui/widgets/controls/button.h>
#include <com/ngos/shared/common/gui/widgets/controls/tablewidget.h>
#include <com/ngos/shared/common/gui/widgets/controls/tabwidget.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerprotocol.h>
#include <com/ngos/shared/common/uefi/uefisimplepointerprotocol.h>



class HddTestGUI
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO
    static NgosStatus exec(); // TEST: NO

private:
    static NgosStatus focusTabFirstWidget(); // TEST: NO
    static NgosStatus focusTabLastWidget(); // TEST: NO

    static NgosStatus generateWaitEventList(); // TEST: NO
    static NgosStatus waitForEvent(); // TEST: NO
    static NgosStatus processKeyboardEvent(); // TEST: NO
    static NgosStatus processSimplePointerEvent(UefiSimplePointerProtocol *pointer); // TEST: NO
    static NgosStatus processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer); // TEST: NO

    static NgosStatus onRebootButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShutdownButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSystemInformationTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onIssuesTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSummaryTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO
    static NgosStatus onSystemInformationTabButtonPressed(); // TEST: NO
    static NgosStatus onIssuesTabButtonPressed(); // TEST: NO
    static NgosStatus onTestTabButtonPressed(); // TEST: NO
    static NgosStatus onSummaryTabButtonPressed(); // TEST: NO

    static Button     *sRebootButton;
    static Button     *sShutdownButton;
    static TabWidget  *sTabWidget;
    static TabButton  *sSystemInformationTabButton;
    static TabButton  *sIssuesTabButton;
    static TabButton  *sTestTabButton;
    static TabButton  *sSummaryTabButton;
    static Image      *sWarningImage;
    static Image      *sCriticalImage;
    static Image      *sStartImage;
    static Image      *sStopImage;
    static bad_uint16         sWaitEventsCount;
    static uefi_event *sWaitEvents;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_HDDTEST_MAIN_HDDTESTGUI_H
