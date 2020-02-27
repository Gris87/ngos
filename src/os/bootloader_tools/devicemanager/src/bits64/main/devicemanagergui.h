#ifndef DEVICEMANAGER_SRC_BITS64_MAIN_DEVICEMANAGERGUI_H
#define DEVICEMANAGER_SRC_BITS64_MAIN_DEVICEMANAGERGUI_H



#include <bootparams/bootparams.h>
#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/controls/tablewidget.h>
#include <common/src/bits64/gui/widgets/controls/tabwidget.h>
#include <common/src/bits64/gui/widgets/controls/treewidget.h>
#include <ngos/status.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefisimplepointerprotocol.h>



class DeviceManagerGUI
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO
    static NgosStatus exec(); // TEST: NO

private:
    static NgosStatus fillDevicesTree(); // TEST: NO

    static NgosStatus focusTabFirstWidget(); // TEST: NO

    static NgosStatus generateWaitEventList(); // TEST: NO
    static NgosStatus waitForEvent(); // TEST: NO
    static NgosStatus processKeyboardEvent(); // TEST: NO
    static NgosStatus processSimplePointerEvent(UefiSimplePointerProtocol *pointer); // TEST: NO
    static NgosStatus processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer); // TEST: NO

    static NgosStatus onRebootButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShutdownButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSystemInformationTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onIssuesTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onDevicesTreeWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onDeviceInfoTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO
    static NgosStatus onSystemInformationTabButtonPressed(); // TEST: NO
    static NgosStatus onIssuesTabButtonPressed(); // TEST: NO

    static Button      *sRebootButton;
    static Button      *sShutdownButton;
    static TabWidget   *sTabWidget;
    static TabButton   *sSystemInformationTabButton;
    static TabButton   *sIssuesTabButton;
    static TreeWidget  *sDevicesTreeWidget;
    static TableWidget *sDeviceInfoTableWidget;
    static Image       *sSystemInformationImage;
    static Image       *sWarningImage;
    static Image       *sCriticalImage;
    static u16          sWaitEventsCount;
    static uefi_event  *sWaitEvents;
};



#endif // DEVICEMANAGER_SRC_BITS64_MAIN_DEVICEMANAGERGUI_H
