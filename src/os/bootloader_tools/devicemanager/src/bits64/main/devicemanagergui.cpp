#include "devicemanagergui.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/misc/labelwidget.h>
#include <common/src/bits64/gui/widgets/misc/treenodewidget.h>
#include <common/src/bits64/gui/widgets/special/rootwidget.h>
#include <common/src/bits64/gui/widgets/special/screenwidget.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/string/utils.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>
#include <uefibase/src/bits64/uefi/uefi.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/src/bits64/uefi/uefipointerdevices.h>

#include "src/bits64/sources/dmi/devicemanagerdmi.h"



#define REBOOT_BUTTON_POSITION_X_PERCENT 90
#define REBOOT_BUTTON_POSITION_Y_PERCENT 0

#define SHUTDOWN_BUTTON_POSITION_X_PERCENT 95
#define SHUTDOWN_BUTTON_POSITION_Y_PERCENT 0

#define DEVICES_TREEWIDGET_POSITION_X_PERCENT 1
#define DEVICES_TREEWIDGET_POSITION_Y_PERCENT 1
#define DEVICES_TREEWIDGET_WIDTH_PERCENT      29
#define DEVICES_TREEWIDGET_HEIGHT_PERCENT     68
#define DEVICES_TREEWIDGET_ROW_HEIGHT_PERCENT 2

#define DEVICE_INFO_TABLEWIDGET_POSITION_X_PERCENT 31
#define DEVICE_INFO_TABLEWIDGET_POSITION_Y_PERCENT 1
#define DEVICE_INFO_TABLEWIDGET_WIDTH_PERCENT      58
#define DEVICE_INFO_TABLEWIDGET_HEIGHT_PERCENT     68
#define DEVICE_INFO_TABLEWIDGET_ROW_HEIGHT_PERCENT 3

#define DEVICE_INFO_COLUMN_NAME_WIDTH_PERCENT  80
#define DEVICE_INFO_COLUMN_VALUE_WIDTH_PERCENT 20

#define SYSTEM_BUTTON_SIZE_PERCENT 5
#define CURSOR_SIZE_PERCENT        1

#define COLUMN_NAME  0
#define COLUMN_VALUE 1



Button      *DeviceManagerGUI::sRebootButton;
Button      *DeviceManagerGUI::sShutdownButton;
TreeWidget  *DeviceManagerGUI::sDevicesTreeWidget;
TableWidget *DeviceManagerGUI::sDeviceInfoTableWidget;
u16          DeviceManagerGUI::sWaitEventsCount;
uefi_event  *DeviceManagerGUI::sWaitEvents;
RgbaPixel    DeviceManagerGUI::sBlackColor(0xFF000000);
Image*       DeviceManagerGUI::sImages[(u64)DeviceManagerImage::MAXIMUM];



const char8* DeviceManagerGUI::sImagesPath[(u64)DeviceManagerImage::MAXIMUM] =
{
    "images/additional.png",                        // DeviceManagerImage::ADDITIONAL
    "images/baseboard.png",                         // DeviceManagerImage::BASEBOARD
    "images/bios.png",                              // DeviceManagerImage::BIOS
    "images/bios_language.png",                     // DeviceManagerImage::BIOS_LANGUAGE
    "images/cache.png",                             // DeviceManagerImage::CACHE
    "images/chassis.png",                           // DeviceManagerImage::CHASSIS
    "images/cooling_device.png",                    // DeviceManagerImage::COOLING_DEVICE
    "images/electrical_current_probe.png",          // DeviceManagerImage::ELECTRICAL_CURRENT_PROBE
    "images/group_associations.png",                // DeviceManagerImage::GROUP_ASSOCIATIONS
    "images/management_device.png",                 // DeviceManagerImage::MANAGEMENT_DEVICE
    "images/management_device_component.png",       // DeviceManagerImage::MANAGEMENT_DEVICE_COMPONENT
    "images/management_device_threshold_data.png",  // DeviceManagerImage::MANAGEMENT_DEVICE_THRESHOLD_DATA
    "images/memory_array_mapped_address.png",       // DeviceManagerImage::MEMORY_ARRAY_MAPPED_ADDRESS
    "images/memory_controller.png",                 // DeviceManagerImage::MEMORY_CONTROLLER
    "images/memory_device.png",                     // DeviceManagerImage::MEMORY_DEVICE
    "images/memory_device_mapped_address.png",      // DeviceManagerImage::MEMORY_DEVICE_MAPPED_ADDRESS
    "images/memory_module.png",                     // DeviceManagerImage::MEMORY_MODULE
    "images/onboard_devices.png",                   // DeviceManagerImage::ONBOARD_DEVICES
    "images/onboard_ethernet.png",                  // DeviceManagerImage::ONBOARD_ETHERNET
    "images/onboard_other.png",                     // DeviceManagerImage::ONBOARD_OTHER
    "images/onboard_sata.png",                      // DeviceManagerImage::ONBOARD_SATA
    "images/onboard_sound.png",                     // DeviceManagerImage::ONBOARD_SOUND
    "images/onboard_video.png",                     // DeviceManagerImage::ONBOARD_VIDEO
    "images/other.png",                             // DeviceManagerImage::OTHER
    "images/physical_memory_array.png",             // DeviceManagerImage::PHYSICAL_MEMORY_ARRAY
    "images/port_audio.png",                        // DeviceManagerImage::PORT_AUDIO
    "images/port_connector.png",                    // DeviceManagerImage::PORT_CONNECTOR
    "images/port_fan.png",                          // DeviceManagerImage::PORT_FAN
    "images/port_network.png",                      // DeviceManagerImage::PORT_NETWORK
    "images/port_other.png",                        // DeviceManagerImage::PORT_OTHER
    "images/port_ps2.png",                          // DeviceManagerImage::PORT_PS2
    "images/port_sata.png",                         // DeviceManagerImage::PORT_SATA
    "images/port_usb.png",                          // DeviceManagerImage::PORT_USB
    "images/port_video.png",                        // DeviceManagerImage::PORT_VIDEO
    "images/portable_battery.png",                  // DeviceManagerImage::PORTABLE_BATTERY
    "images/processor.png",                         // DeviceManagerImage::PROCESSOR
    "images/system.png",                            // DeviceManagerImage::SYSTEM
    "images/system_boot.png",                       // DeviceManagerImage::SYSTEM_BOOT
    "images/system_power_supply.png",               // DeviceManagerImage::SYSTEM_POWER_SUPPLY
    "images/system_slot_pci_express.png",           // DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS
    "images/system_slots.png",                      // DeviceManagerImage::SYSTEM_SLOTS
    "images/temperature_probe.png",                 // DeviceManagerImage::TEMPERATURE_PROBE
    "images/voltage_probe.png"                      // DeviceManagerImage::VOLTAGE_PROBE
};



NgosStatus DeviceManagerGUI::init(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    Image *backgroundImage;
    Image *buttonNormalImage;
    Image *buttonHoverImage;
    Image *buttonPressedImage;
    Image *buttonFocusedImage;
    Image *buttonFocusedHoverImage;
    Image *buttonNormalResizedImage;
    Image *buttonHoverResizedImage;
    Image *buttonPressedResizedImage;
    Image *buttonFocusedResizedImage;
    Image *buttonFocusedHoverResizedImage;
    Image *treeBackgroundImage;
    Image *tableBackgroundImage;
    Image *tableHeaderImage;
    Image *rebootImage;
    Image *shutdownImage;
    Image *cursorImage;



    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/background.jpg",             &backgroundImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_normal.9.png",        &buttonNormalImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_hover.9.png",         &buttonHoverImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_pressed.9.png",       &buttonPressedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_focused.9.png",       &buttonFocusedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_focused_hover.9.png", &buttonFocusedHoverImage), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/tree_background.9.png",      &treeBackgroundImage),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/table_background.9.png",     &tableBackgroundImage),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/table_header.9.png",         &tableHeaderImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/reboot.png",                 &rebootImage),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/shutdown.png",               &shutdownImage),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/cursor.png",                 &cursorImage),             NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(params->screensCount > 0, NgosStatus::ASSERTION);

    u64 screenWidth  = params->screens[0]->mode->info->horizontalResolution;
    u64 screenHeight = params->screens[0]->mode->info->verticalResolution;



    u64 systemButtonSize = screenWidth * SYSTEM_BUTTON_SIZE_PERCENT / 100;
    u64 cursorSize       = screenWidth * CURSOR_SIZE_PERCENT        / 100;



    RootWidget *rootWidget = new RootWidget();

    UEFI_ASSERT_EXECUTION(rootWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rootWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    ScreenWidget *screenWidget = new ScreenWidget(backgroundImage, params->screens[0], rootWidget);

    UEFI_ASSERT_EXECUTION(screenWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(screenWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonNormalImage,       systemButtonSize, systemButtonSize, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonHoverImage,        systemButtonSize, systemButtonSize, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonPressedImage,      systemButtonSize, systemButtonSize, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedImage,      systemButtonSize, systemButtonSize, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedHoverImage, systemButtonSize, systemButtonSize, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



    sRebootButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, rebootImage, nullptr, "", rootWidget);

    UEFI_ASSERT_EXECUTION(sRebootButton->setPosition(screenWidth * REBOOT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * REBOOT_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setSize(systemButtonSize, systemButtonSize),                                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setKeyboardEventHandler(onRebootButtonKeyboardEvent),                                                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setPressEventHandler(onRebootButtonPressed),                                                                              NgosStatus::ASSERTION);



    sShutdownButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, shutdownImage, nullptr, "", rootWidget);

    UEFI_ASSERT_EXECUTION(sShutdownButton->setPosition(screenWidth * SHUTDOWN_BUTTON_POSITION_X_PERCENT / 100, screenHeight * SHUTDOWN_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setSize(systemButtonSize, systemButtonSize),                                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setKeyboardEventHandler(onShutdownButtonKeyboardEvent),                                                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setPressEventHandler(onShutdownButtonPressed),                                                                                NgosStatus::ASSERTION);



    u64 devicesTreeWidth      = screenWidth  * DEVICES_TREEWIDGET_WIDTH_PERCENT       / 100;
    u64 devicesTreeHeight     = screenHeight * DEVICES_TREEWIDGET_HEIGHT_PERCENT      / 100;
    u64 deviceInfoTableWidth  = screenWidth  * DEVICE_INFO_TABLEWIDGET_WIDTH_PERCENT  / 100;
    u64 deviceInfoTableHeight = screenHeight * DEVICE_INFO_TABLEWIDGET_HEIGHT_PERCENT / 100;



    sDevicesTreeWidget = new TreeWidget(treeBackgroundImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sDevicesTreeWidget->setPosition(screenWidth * DEVICES_TREEWIDGET_POSITION_X_PERCENT / 100, screenHeight * DEVICES_TREEWIDGET_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDevicesTreeWidget->setSize(devicesTreeWidth, devicesTreeHeight),                                                                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDevicesTreeWidget->setKeyboardEventHandler(onDevicesTreeWidgetKeyboardEvent),                                                                          NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sDevicesTreeWidget->setRowHeight(screenHeight * DEVICES_TREEWIDGET_ROW_HEIGHT_PERCENT / 100), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(fillDevicesTree(), NgosStatus::ASSERTION);



    sDeviceInfoTableWidget = new TableWidget(tableBackgroundImage, tableHeaderImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setPosition(screenWidth * DEVICE_INFO_TABLEWIDGET_POSITION_X_PERCENT / 100, screenHeight * DEVICE_INFO_TABLEWIDGET_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setSize(deviceInfoTableWidth, deviceInfoTableHeight),                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setKeyboardEventHandler(onDeviceInfoTableWidgetKeyboardEvent),                                                                                NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setRowHeight(screenHeight * DEVICE_INFO_TABLEWIDGET_ROW_HEIGHT_PERCENT / 100), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setColumnCount(2), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setColumnWidth(COLUMN_NAME,  deviceInfoTableWidth * DEVICE_INFO_COLUMN_NAME_WIDTH_PERCENT  / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setColumnWidth(COLUMN_VALUE, deviceInfoTableWidth * DEVICE_INFO_COLUMN_VALUE_WIDTH_PERCENT / 100), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setHeaderText(COLUMN_NAME,  "Name"),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setHeaderText(COLUMN_VALUE, "Value"), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(addDeviceInfoEntry("", ""), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sDevicesTreeWidget), NgosStatus::ASSERTION);



    CursorWidget *cursorWidget = new CursorWidget(cursorImage, rootWidget);

    UEFI_ASSERT_EXECUTION(cursorWidget->setPosition(screenWidth >> 1, screenHeight >> 1), NgosStatus::ASSERTION); // ">> 1" == "/ 2"
    UEFI_ASSERT_EXECUTION(cursorWidget->setSize(cursorSize, cursorSize),                  NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, screenWidget, cursorWidget), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(),                              NgosStatus::ASSERTION);

    UEFI_TEST_ASSERT(GUI::isUpdatesEnabled(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::exec()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(generateWaitEventList(), NgosStatus::ASSERTION);

    do
    {
        UEFI_ASSERT_EXECUTION(waitForEvent(), NgosStatus::ASSERTION);
    } while(true);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::fillDevicesTree()
{
    UEFI_LT((""));



    Image *toolButtonNormalImage;
    Image *toolButtonHoverImage;
    Image *toolButtonPressedImage;
    Image *toolButtonNormalResizedImage;
    Image *toolButtonHoverResizedImage;
    Image *toolButtonPressedResizedImage;
    Image *collapsedImage;
    Image *expandedImage;



    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/toolbutton_normal.9.png",  &toolButtonNormalImage),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/toolbutton_hover.9.png",   &toolButtonHoverImage),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/toolbutton_pressed.9.png", &toolButtonPressedImage), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/collapsed.png",            &collapsedImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/expanded.png",             &expandedImage),          NgosStatus::ASSERTION);



    u64 expandButtonSize = sDevicesTreeWidget->getRowHeight();



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(toolButtonNormalImage,  expandButtonSize, expandButtonSize, &toolButtonNormalResizedImage),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(toolButtonHoverImage,   expandButtonSize, expandButtonSize, &toolButtonHoverResizedImage),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(toolButtonPressedImage, expandButtonSize, expandButtonSize, &toolButtonPressedResizedImage), NgosStatus::ASSERTION);



    TreeNodeWidget *rootNodeWidget = new TreeNodeWidget(toolButtonNormalImage, toolButtonHoverImage, toolButtonPressedImage, toolButtonNormalResizedImage, toolButtonHoverResizedImage, toolButtonPressedResizedImage, collapsedImage, expandedImage, getImage(DeviceManagerImage::SYSTEM), "System", sDevicesTreeWidget);

    UEFI_ASSERT_EXECUTION(rootNodeWidget->getLabelWidget()->setColor(sBlackColor), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDevicesTreeWidget->setRootNodeWidget(rootNodeWidget),   NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(fillDevicesTreeForDmi(toolButtonNormalImage, toolButtonHoverImage, toolButtonPressedImage, toolButtonNormalResizedImage, toolButtonHoverResizedImage, toolButtonPressedResizedImage, collapsedImage, expandedImage), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(rootNodeWidget->setExpanded(true), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::fillDevicesTreeForDmi(Image *toolButtonNormalImage, Image *toolButtonHoverImage, Image *toolButtonPressedImage, Image *toolButtonNormalResizedImage, Image *toolButtonHoverResizedImage, Image *toolButtonPressedResizedImage, Image *collapsedImage, Image *expandedImage)
{
    UEFI_LT((" | toolButtonNormalImage = 0x%p, toolButtonHoverImage = 0x%p, toolButtonPressedImage = 0x%p, toolButtonNormalResizedImage = 0x%p, toolButtonHoverResizedImage = 0x%p, toolButtonPressedResizedImage = 0x%p, collapsedImage = 0x%p, expandedImage = 0x%p", toolButtonNormalImage, toolButtonHoverImage, toolButtonPressedImage, toolButtonNormalResizedImage, toolButtonHoverResizedImage, toolButtonPressedResizedImage, collapsedImage, expandedImage));



    TreeNodeWidget *dmiNodeWidget = new TreeNodeWidget(toolButtonNormalImage, toolButtonHoverImage, toolButtonPressedImage, toolButtonNormalResizedImage, toolButtonHoverResizedImage, toolButtonPressedResizedImage, collapsedImage, expandedImage, getImage(DeviceManagerImage::SYSTEM), "DMI", sDevicesTreeWidget);

    UEFI_ASSERT_EXECUTION(dmiNodeWidget->getLabelWidget()->setColor(sBlackColor),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDevicesTreeWidget->getRootNodeWidget()->addChildNode(dmiNodeWidget), NgosStatus::ASSERTION);



    const ArrayList<DeviceManagerEntryDMI *>& entries = DeviceManagerDMI::getEntries();

    for (i64 i = 0; i < (i64)entries.getSize(); ++i)
    {
        DeviceManagerEntryDMI *entry = entries.at(i);



        TreeNodeWidget *entryNodeWidget = new TreeNodeWidget(toolButtonNormalImage, toolButtonHoverImage, toolButtonPressedImage, toolButtonNormalResizedImage, toolButtonHoverResizedImage, toolButtonPressedResizedImage, collapsedImage, expandedImage, getImage(entry->getImage()), strdup(enumToString(entry->getType())), sDevicesTreeWidget);

        UEFI_ASSERT_EXECUTION(entryNodeWidget->getLabelWidget()->setColor(sBlackColor), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(dmiNodeWidget->addChildNode(entryNodeWidget),             NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(dmiNodeWidget->setExpanded(true),  NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::addDeviceInfoEntry(const char8 *name, const char8 *value)
{
    UEFI_LT((" | name = 0x%p, value = 0x%p", name, value));

    UEFI_ASSERT(name,  "name is null",  NgosStatus::ASSERTION);
    UEFI_ASSERT(value, "value is null", NgosStatus::ASSERTION);



    u64 row = sDeviceInfoTableWidget->getRowCount();

    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setRowCount(row + 1), NgosStatus::ASSERTION);



    LabelWidget *nameLabelWidget = new LabelWidget(name, sDeviceInfoTableWidget);
    UEFI_ASSERT_EXECUTION(nameLabelWidget->setColor(sBlackColor),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setCellWidget(row, COLUMN_NAME, nameLabelWidget), NgosStatus::ASSERTION);

    LabelWidget *valueLabelWidget = new LabelWidget(value, sDeviceInfoTableWidget);
    UEFI_ASSERT_EXECUTION(valueLabelWidget->setColor(sBlackColor),                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDeviceInfoTableWidget->setCellWidget(row, COLUMN_VALUE, valueLabelWidget), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::generateWaitEventList()
{
    UEFI_LT((""));



    sWaitEventsCount = UefiPointerDevices::getSimplePointersCount() + UefiPointerDevices::getAbsolutePointersCount() + 1; // "+ 1" = keyboard event
    u64 size         = sWaitEventsCount * sizeof(uefi_event);



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&sWaitEvents) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for wait events", size));

        return NgosStatus::OUT_OF_MEMORY;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for wait events", sWaitEvents, size));



    sWaitEvents[0] = UEFI::getSystemTable()->stdin->waitForKey;
    u16 eventId    = 1;



    for (i64 i = 0; i < UefiPointerDevices::getSimplePointersCount(); ++i)
    {
        sWaitEvents[eventId] = UefiPointerDevices::getSimplePointer(i)->waitForInput;

        ++eventId;
    }



    for (i64 i = 0; i < UefiPointerDevices::getAbsolutePointersCount(); ++i)
    {
        sWaitEvents[eventId] = UefiPointerDevices::getAbsolutePointer(i)->waitForInput;

        ++eventId;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::waitForEvent()
{
    UEFI_LT((""));



    u64 eventIndex;

    UEFI_ASSERT_EXECUTION(UEFI::waitForEvent(sWaitEventsCount, sWaitEvents, &eventIndex), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("eventIndex = %u", eventIndex));



    if (!eventIndex) // eventIndex == 0
    {
        return processKeyboardEvent();
    }



    if (eventIndex <= UefiPointerDevices::getSimplePointersCount())
    {
        return processSimplePointerEvent(UefiPointerDevices::getSimplePointer(eventIndex - 1));
    }



    return processAbsolutePointerEvent(UefiPointerDevices::getAbsolutePointer(eventIndex - UefiPointerDevices::getSimplePointersCount() - 1));
}

NgosStatus DeviceManagerGUI::processKeyboardEvent()
{
    UEFI_LT((""));



    UefiInputKey key;

    UEFI_ASSERT_EXECUTION(UEFI::getSystemTable()->stdin->readKeyStroke(UEFI::getSystemTable()->stdin, &key), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("key.scanCode    = %s",     enumToFullString(key.scanCode)));
    UEFI_LVVV(("key.unicodeChar = 0x%04X", key.unicodeChar));



    UEFI_TEST_ASSERT(GUI::getFocusedWidget(),                            NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(GUI::getFocusedWidget()->getKeyboardEventHandler(), NgosStatus::ASSERTION);



    NgosStatus status = GUI::getFocusedWidget()->getKeyboardEventHandler()(key);

    if (status == NgosStatus::NO_EFFECT)
    {
        status = GUI::getFocusedWidget()->onKeyboardEvent(key);

        if (status == NgosStatus::NO_EFFECT)
        {
            status = GUI::processKeyboardEvent(key);
        }
    }

    UEFI_TEST_ASSERT(status == NgosStatus::OK
                    ||
                    status == NgosStatus::NO_EFFECT, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::processSimplePointerEvent(UefiSimplePointerProtocol *pointer)
{
    UEFI_LT((" | pointer = 0x%p", pointer));

    UEFI_ASSERT(pointer, "pointer is null", NgosStatus::ASSERTION);



    UefiSimplePointerState state;

    if (pointer->getState(pointer, &state) == UefiStatus::SUCCESS)
    {
        UEFI_LVVV(("state.relativeMovementX = %d", state.relativeMovementX));
        UEFI_LVVV(("state.relativeMovementY = %d", state.relativeMovementY));
        UEFI_LVVV(("state.relativeMovementZ = %d", state.relativeMovementZ));
        UEFI_LVVV(("state.leftButton        = %s", boolToString(state.leftButton)));
        UEFI_LVVV(("state.rightButton       = %s", boolToString(state.rightButton)));



        UEFI_ASSERT_EXECUTION(GUI::processSimplePointerState(&state), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer)
{
    UEFI_LT((" | pointer = 0x%p", pointer));

    UEFI_ASSERT(pointer, "pointer is null", NgosStatus::ASSERTION);



    UefiAbsolutePointerState state;

    if (pointer->getState(pointer, &state) == UefiStatus::SUCCESS)
    {
        UEFI_LVVV(("state.currentX      = %u", state.currentX));
        UEFI_LVVV(("state.currentY      = %u", state.currentY));
        UEFI_LVVV(("state.currentZ      = %u", state.currentZ));
        UEFI_LVVV(("state.activeButtons = %s", flagsToFullString(state.activeButtons)));



        UEFI_ASSERT_EXECUTION(GUI::processAbsolutePointerState(pointer, &state), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::onRebootButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sDeviceInfoTableWidget);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sShutdownButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sShutdownButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus DeviceManagerGUI::onShutdownButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sDevicesTreeWidget);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus DeviceManagerGUI::onDevicesTreeWidgetKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sDeviceInfoTableWidget);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus DeviceManagerGUI::onDeviceInfoTableWidgetKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sDevicesTreeWidget);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus DeviceManagerGUI::onRebootButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::COLD, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerGUI::onShutdownButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::SHUTDOWN, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

Image* DeviceManagerGUI::getImage(DeviceManagerImage image)
{
    // UEFI_LT((" | image = %u", image)); // Commented to avoid too frequent logs

    UEFI_ASSERT(image < DeviceManagerImage::MAXIMUM, "image is invalid", nullptr);



    Image *res = sImages[(u64)image];

    if (!res)
    {
        UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets(sImagesPath[(u64)image], &res), nullptr);

        sImages[(u64)image] = res;
    }



    return res;
}
