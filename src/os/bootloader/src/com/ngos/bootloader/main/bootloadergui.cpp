#include "bootloadergui.h"

#include <common/src/com/ngos/shared/common/graphics/graphics.h>
#include <common/src/com/ngos/shared/common/gui/gui.h>
#include <common/src/com/ngos/shared/common/gui/widgets/misc/labelwidget.h>
#include <common/src/com/ngos/shared/common/gui/widgets/special/rootwidget.h>
#include <common/src/com/ngos/shared/common/gui/widgets/special/screenwidget.h>
#include <common/src/com/ngos/shared/common/memory/memory.h>
#include <common/src/com/ngos/shared/common/string/utils.h>
#include <common/src/com/ngos/shared/common/guid/utils.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/utils.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefi.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefipointerdevices.h>

#include "src/com/ngos/bootloader/main/bootloader.h"



#define INFO_TEXT_POSITION_X_PERCENT 10
#define INFO_TEXT_POSITION_Y_PERCENT 0
#define INFO_TEXT_WIDTH_PERCENT      80
#define INFO_TEXT_HEIGHT_PERCENT     2

#define OS_REGION_LEFT_PERCENT            10
#define OS_REGION_RIGHT_PERCENT           90
#define OS_REGION_VERTICAL_CENTER_PERCENT 25
#define OS_VISIBLE_COUNT                  4
#define OS_BUTTON_SIZE_PERCENT            20

#define LEFT_BUTTON_POSITION_X_PERCENT  2
#define RIGHT_BUTTON_POSITION_X_PERCENT 92
#define ARROW_BUTTON_SIZE_PERCENT       6

#define TIMEOUT_PANEL_POSITION_X_PERCENT 36
#define TIMEOUT_PANEL_POSITION_Y_PERCENT 43
#define TIMEOUT_PANEL_WIDTH_PERCENT      28
#define TIMEOUT_PANEL_HEIGHT_PERCENT     4

#define TIMEOUT_TEXT_POSITION_X_PERCENT 5
#define TIMEOUT_TEXT_POSITION_Y_PERCENT 20
#define TIMEOUT_TEXT_WIDTH_PERCENT      90
#define TIMEOUT_TEXT_HEIGHT_PERCENT     60

#define DEVICE_MANAGER_BUTTON_POSITION_X_PERCENT 10
#define DEVICE_MANAGER_BUTTON_POSITION_Y_PERCENT 48

#define CPU_TEST_BUTTON_POSITION_X_PERCENT 37
#define CPU_TEST_BUTTON_POSITION_Y_PERCENT 48

#define MEMORY_TEST_BUTTON_POSITION_X_PERCENT 64
#define MEMORY_TEST_BUTTON_POSITION_Y_PERCENT 48

#define NETWORK_TEST_BUTTON_POSITION_X_PERCENT 10
#define NETWORK_TEST_BUTTON_POSITION_Y_PERCENT 59

#define HDD_TEST_BUTTON_POSITION_X_PERCENT 37
#define HDD_TEST_BUTTON_POSITION_Y_PERCENT 59

#define PARTITION_WIZARD_BUTTON_POSITION_X_PERCENT 64
#define PARTITION_WIZARD_BUTTON_POSITION_Y_PERCENT 59

#define TOOL_BUTTON_WIDTH_PERCENT         26
#define TOOL_BUTTON_HEIGHT_PERCENT        10
#define SYSTEM_BUTTON_RESERVED_PROPORTION 0.7
#define CURSOR_SIZE                       20

#define TIMEOUT_TIME 9

#define TIMEOUT_TEXT_LENGTH 28



Image               *BootloaderGUI::sBackgroundImage;
Image               *BootloaderGUI::sButtonNormalImage;
Image               *BootloaderGUI::sButtonHoverImage;
Image               *BootloaderGUI::sButtonPressedImage;
Image               *BootloaderGUI::sButtonFocusedImage;
Image               *BootloaderGUI::sButtonFocusedHoverImage;
Image               *BootloaderGUI::sInfoPanelImage;
Image               *BootloaderGUI::sDeviceManagerImage;
Image               *BootloaderGUI::sCpuTestImage;
Image               *BootloaderGUI::sMemoryTestImage;
Image               *BootloaderGUI::sNetworkTestImage;
Image               *BootloaderGUI::sHddTestImage;
Image               *BootloaderGUI::sPartitionWizardImage;
Image               *BootloaderGUI::sRebootImage;
Image               *BootloaderGUI::sShutdownImage;
Image               *BootloaderGUI::sCursorImage;
Image*               BootloaderGUI::sOsImages[(u64)OsType::MAXIMUM];
Image*               BootloaderGUI::sVolumeImages[(u64)VolumeType::MAXIMUM];
Button              *BootloaderGUI::sRebootButton;
Button              *BootloaderGUI::sShutdownButton;
ArrayList<Button *>  BootloaderGUI::sOsButtons;
u64                  BootloaderGUI::sOsButtonLeft;
u64                  BootloaderGUI::sOsButtonRight;
u64                  BootloaderGUI::sOsButtonSelected;
Button              *BootloaderGUI::sLeftButton;
Button              *BootloaderGUI::sRightButton;
PanelWidget         *BootloaderGUI::sTimeoutPanelWidget;
LabelWidget         *BootloaderGUI::sTimeoutLabelWidget;
u8                   BootloaderGUI::sTimeoutTick;
Button              *BootloaderGUI::sDeviceManagerButton;
Button              *BootloaderGUI::sCpuTestButton;
Button              *BootloaderGUI::sMemoryTestButton;
Button              *BootloaderGUI::sNetworkTestButton;
Button              *BootloaderGUI::sHddTestButton;
Button              *BootloaderGUI::sPartitionWizardButton;
u16                  BootloaderGUI::sWaitEventsCount;
uefi_event          *BootloaderGUI::sWaitEvents;
uefi_event           BootloaderGUI::sTimerEvent;

Guid bootloaderGUID = { 0xACC36FA9, 0x3834, 0x49C2, { 0xA6, 0xC7, 0x29, 0x68, 0x2B, 0x2A, 0xD3, 0x3E } };



NgosStatus BootloaderGUI::init(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    Image *buttonNormalResizedImage;
    Image *buttonHoverResizedImage;
    Image *buttonPressedResizedImage;
    Image *buttonFocusedResizedImage;
    Image *buttonFocusedHoverResizedImage;



    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/background.jpg",             &sBackgroundImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_normal.9.png",        &sButtonNormalImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_hover.9.png",         &sButtonHoverImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_pressed.9.png",       &sButtonPressedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_focused.9.png",       &sButtonFocusedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_focused_hover.9.png", &sButtonFocusedHoverImage), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/info_panel.9.png",           &sInfoPanelImage),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/device_manager.png",         &sDeviceManagerImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/cpu_test.png",               &sCpuTestImage),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/memory_test.png",            &sMemoryTestImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/network_test.png",           &sNetworkTestImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/hdd_test.png",               &sHddTestImage),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/partition_wizard.png",       &sPartitionWizardImage),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/reboot.png",                 &sRebootImage),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/shutdown.png",               &sShutdownImage),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/cursor.png",                 &sCursorImage),             NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(params->screensCount > 0, NgosStatus::ASSERTION);

    u64 screenWidth  = params->screens[0]->mode->info->horizontalResolution;
    u64 screenHeight = params->screens[0]->mode->info->verticalResolution;



    RootWidget *rootWidget = new RootWidget();

    UEFI_ASSERT_EXECUTION(rootWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rootWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    ScreenWidget *screenWidget = new ScreenWidget(sBackgroundImage, params->screens[0], rootWidget);

    UEFI_ASSERT_EXECUTION(screenWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(screenWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    if (UEFI::freePool(params->screens) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for screen infos", params->screens));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for screen infos", params->screens));
    }



    LabelWidget *infoLabel = new LabelWidget("Use arrow keys and Tab to select, Enter to boot", rootWidget);

    UEFI_ASSERT_EXECUTION(infoLabel->setPosition(screenWidth * INFO_TEXT_POSITION_X_PERCENT / 100, screenHeight * INFO_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(infoLabel->setSize(screenWidth     * INFO_TEXT_WIDTH_PERCENT      / 100, screenHeight * INFO_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    u64 allowedWidthForSystemButtons   = screenWidth  * (100 - (GRAPHICAL_CONSOLE_POSITION_X_PERCENT + GRAPHICAL_CONSOLE_WIDTH_PERCENT)) / 100;
    u64 allowedHeighthForSystemButtons = screenHeight * GRAPHICAL_CONSOLE_HEIGHT_PERCENT                                                 / 100 - allowedWidthForSystemButtons * SYSTEM_BUTTON_RESERVED_PROPORTION;

    u64 systemButtonSize = allowedHeighthForSystemButtons / 2;

    if (systemButtonSize > allowedWidthForSystemButtons)
    {
        systemButtonSize = allowedWidthForSystemButtons;
    }



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonNormalImage,       systemButtonSize, systemButtonSize, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonHoverImage,        systemButtonSize, systemButtonSize, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonPressedImage,      systemButtonSize, systemButtonSize, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonFocusedImage,      systemButtonSize, systemButtonSize, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonFocusedHoverImage, systemButtonSize, systemButtonSize, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



    sRebootButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, sRebootImage, nullptr, "", rootWidget);

    UEFI_ASSERT_EXECUTION(sRebootButton->setPosition(screenWidth - systemButtonSize, screenHeight - systemButtonSize * 2), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setSize(systemButtonSize, systemButtonSize),                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setKeyboardEventHandler(onRebootButtonKeyboardEvent),                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setPressEventHandler(onRebootButtonPressed),                                      NgosStatus::ASSERTION);



    sShutdownButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, sShutdownImage, nullptr, "", rootWidget);

    UEFI_ASSERT_EXECUTION(sShutdownButton->setPosition(screenWidth - systemButtonSize, screenHeight - systemButtonSize), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setSize(systemButtonSize, systemButtonSize),                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setKeyboardEventHandler(onShutdownButtonKeyboardEvent),                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setPressEventHandler(onShutdownButtonPressed),                                NgosStatus::ASSERTION);



    const ArrayList<OsInfo>& oses    = Bootloader::getOSes();
    u64                      osCount = oses.getSize();

    if (osCount > 0)
    {
        u64 osButtonSize = screenWidth * OS_BUTTON_SIZE_PERCENT / 100;



        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonNormalImage,       osButtonSize, osButtonSize, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonHoverImage,        osButtonSize, osButtonSize, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonPressedImage,      osButtonSize, osButtonSize, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonFocusedImage,      osButtonSize, osButtonSize, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonFocusedHoverImage, osButtonSize, osButtonSize, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



        for (i64 i = 0; i < (i64)osCount; ++i)
        {
            const OsInfo &os = oses.at(i);



            UEFI_TEST_ASSERT(os.type < OsType::MAXIMUM, NgosStatus::ASSERTION);
            Image *osImage = sOsImages[(u64)os.type];

            if (!osImage)
            {
                const char8 *pathToImage;

                switch (os.type)
                {
                    case OsType::NGOS:       pathToImage = "images/os_ngos.png";    break;
                    case OsType::WINDOWS_10: pathToImage = "images/os_windows.png"; break;
                    case OsType::UBUNTU_19:  pathToImage = "images/os_ubuntu.png";  break;
                    case OsType::CENTOS_8:   pathToImage = "images/os_centos.png";  break;

                    case OsType::MAXIMUM:
                    {
                        UEFI_LF(("Unexpected OS type: %s, %s:%u", enumToFullString(os.type), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        UEFI_LF(("Unknown OS type: %s, %s:%u", enumToFullString(os.type), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }

                UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets(pathToImage, &osImage), NgosStatus::ASSERTION);
                sOsImages[(u64)os.type] = osImage;
            }



            UEFI_TEST_ASSERT(os.volume->type < VolumeType::MAXIMUM, NgosStatus::ASSERTION);
            Image *volumeImage = sVolumeImages[(u64)os.volume->type];

            if (!volumeImage)
            {
                const char8 *pathToImage;

                switch (os.volume->type)
                {
                    case VolumeType::INTERNAL: pathToImage = "images/volume_internal.png"; break;
                    case VolumeType::EXTERNAL: pathToImage = "images/volume_external.png"; break;
                    case VolumeType::OPTICAL:  pathToImage = "images/volume_optical.png";  break;
                    case VolumeType::NETWORK:  pathToImage = "images/volume_network.png";  break;

                    case VolumeType::MAXIMUM:
                    {
                        UEFI_LF(("Unexpected volume type: %s, %s:%u", enumToFullString(os.volume->type), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        UEFI_LF(("Unknown volume type: %s, %s:%u", enumToFullString(os.volume->type), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }

                UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets(pathToImage, &volumeImage), NgosStatus::ASSERTION);
                sVolumeImages[(u64)os.volume->type] = volumeImage;
            }



            Button *osButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, osImage, volumeImage, "", rootWidget);

            UEFI_ASSERT_EXECUTION(osButton->setKeyboardEventHandler(onOsButtonKeyboardEvent), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(osButton->setPressEventHandler(onOsButtonPressed),          NgosStatus::ASSERTION);

            sOsButtons.append(osButton);
        }



        if (osCount > OS_VISIBLE_COUNT)
        {
            osCount = OS_VISIBLE_COUNT;

            Image *arrowLeftImage;
            Image *arrowRightImage;

            UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/arrow_left.png",  &arrowLeftImage),  NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/arrow_right.png", &arrowRightImage), NgosStatus::ASSERTION);



            u64 arrowButtonSize = screenWidth * ARROW_BUTTON_SIZE_PERCENT / 100;



            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonNormalImage,       arrowButtonSize, arrowButtonSize, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonHoverImage,        arrowButtonSize, arrowButtonSize, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonPressedImage,      arrowButtonSize, arrowButtonSize, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonFocusedImage,      arrowButtonSize, arrowButtonSize, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonFocusedHoverImage, arrowButtonSize, arrowButtonSize, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



            sLeftButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, arrowLeftImage, nullptr, "", rootWidget);

            UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(false),                                                                                                                             NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sLeftButton->setPosition(screenWidth * LEFT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * OS_REGION_VERTICAL_CENTER_PERCENT / 100 - arrowButtonSize / 2), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sLeftButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sLeftButton->setKeyboardEventHandler(onLeftButtonKeyboardEvent),                                                                                            NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sLeftButton->setPressEventHandler(onLeftButtonPressed),                                                                                                     NgosStatus::ASSERTION);



            sRightButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, arrowRightImage, nullptr, "", rootWidget);

            UEFI_ASSERT_EXECUTION(sRightButton->setPosition(screenWidth * RIGHT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * OS_REGION_VERTICAL_CENTER_PERCENT / 100 - arrowButtonSize / 2), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                      NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setKeyboardEventHandler(onRightButtonKeyboardEvent),                                                                                            NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setPressEventHandler(onRightButtonPressed),                                                                                                     NgosStatus::ASSERTION);
        }



        i64 osButtonPositionX;
        i64 osButtonStep;

        if (osCount == 1)
        {
            osButtonPositionX = screenWidth * (OS_REGION_LEFT_PERCENT + OS_REGION_RIGHT_PERCENT - OS_BUTTON_SIZE_PERCENT) / 200;
            osButtonStep      = 0;
        }
        else
        if (osCount == 2)
        {
            osButtonPositionX = screenWidth * (OS_REGION_LEFT_PERCENT + OS_REGION_RIGHT_PERCENT - OS_BUTTON_SIZE_PERCENT) / 200 - osButtonSize;
            osButtonStep      = osButtonSize * 2;
        }
        else
        {
            osButtonPositionX = screenWidth * OS_REGION_LEFT_PERCENT / 100;
            osButtonStep      = screenWidth * (OS_REGION_RIGHT_PERCENT - OS_REGION_LEFT_PERCENT - OS_BUTTON_SIZE_PERCENT) / 100 / (osCount - 1);
        }

        i64 osButtonPositionY = screenHeight * OS_REGION_VERTICAL_CENTER_PERCENT / 100 - (osButtonSize >> 1);



        for (i64 i = 0; i < (i64)osCount; ++i)
        {
            Button *button = sOsButtons.at(i);

            UEFI_ASSERT_EXECUTION(button->setPosition(osButtonPositionX, osButtonPositionY), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(button->setSize(osButtonSize, osButtonSize),               NgosStatus::ASSERTION);

            osButtonPositionX += osButtonStep;
        }

        for (i64 i = osCount; i < (i64)sOsButtons.getSize(); ++i)
        {
            Button *button = sOsButtons.at(i);

            UEFI_ASSERT_EXECUTION(button->setVisible(false),                   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(button->setSize(osButtonSize, osButtonSize), NgosStatus::ASSERTION);
        }

        sOsButtonLeft     = 0;
        sOsButtonRight    = osCount;
        sOsButtonSelected = 0;



        u64   variableSize;
        Guid *lastOsVolumeGuid;

        if (UEFI::getVariable(u"LastOsVolumeGuid", &bootloaderGUID, &variableSize, (u8 **)&lastOsVolumeGuid) == UefiStatus::SUCCESS)
        {
            UEFI_LV(("Loaded LastOsVolumeGuid NVRAM variable: %s", guidToString(lastOsVolumeGuid)));

            UEFI_TEST_ASSERT(variableSize == sizeof(*lastOsVolumeGuid), NgosStatus::ASSERTION);



            char16 *lastOsPath;

            if (UEFI::getVariable(u"LastOsPath", &bootloaderGUID, &variableSize, (u8 **)&lastOsPath) == UefiStatus::SUCCESS)
            {
                UEFI_LV(("Loaded LastOsPath NVRAM variable: %ls", lastOsPath));

                UEFI_TEST_ASSERT(variableSize == (strlen(lastOsPath) + 1) * sizeof(char16), NgosStatus::ASSERTION);



                osCount = oses.getSize();

                for (i64 i = 0; i < (i64)osCount; ++i)
                {
                    const OsInfo &os = oses.at(i);

                    if (
                        isGuidEquals(*os.volume->partitionUniqueGuid, *lastOsVolumeGuid)
                        &&
                        !strcmpi(os.path, lastOsPath) // os.path == lastOsPath
                       )
                    {
                        while ((i64)sOsButtonRight <= i)
                        {
                            UEFI_ASSERT_EXECUTION(onRightButtonPressed(), NgosStatus::ASSERTION);
                        }

                        sOsButtonSelected = i;

                        break;
                    }
                }



                if (UEFI::freePool(lastOsPath) == UefiStatus::SUCCESS)
                {
                    UEFI_LVV(("Released pool(0x%p) for NVRAM variable", lastOsPath));
                }
                else
                {
                    UEFI_LE(("Failed to release pool(0x%p) for NVRAM variable", lastOsPath));
                }
            }



            if (UEFI::freePool(lastOsVolumeGuid) == UefiStatus::SUCCESS)
            {
                UEFI_LVV(("Released pool(0x%p) for NVRAM variable", lastOsVolumeGuid));
            }
            else
            {
                UEFI_LE(("Failed to release pool(0x%p) for NVRAM variable", lastOsVolumeGuid));
            }
        }



        sTimeoutTick = TIMEOUT_TIME;

        char8 *timeoutText = (char8 *)malloc(TIMEOUT_TEXT_LENGTH);
        UEFI_TEST_ASSERT(timeoutText != nullptr, NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sprintf(timeoutText, "Automatic boot in %u seconds", sTimeoutTick), i64, TIMEOUT_TEXT_LENGTH - 1, NgosStatus::ASSERTION);



        u64 timeoutPanelWidth  = screenWidth  * TIMEOUT_PANEL_WIDTH_PERCENT  / 100;
        u64 timeoutPanelHeight = screenHeight * TIMEOUT_PANEL_HEIGHT_PERCENT / 100;



        sTimeoutPanelWidget = new PanelWidget(sInfoPanelImage, rootWidget);

        UEFI_ASSERT_EXECUTION(sTimeoutPanelWidget->setPosition(screenWidth * TIMEOUT_PANEL_POSITION_X_PERCENT / 100, screenHeight * TIMEOUT_PANEL_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTimeoutPanelWidget->setSize(timeoutPanelWidth, timeoutPanelHeight),                                                                           NgosStatus::ASSERTION);



        sTimeoutLabelWidget = new LabelWidget(timeoutText, sTimeoutPanelWidget);

        UEFI_ASSERT_EXECUTION(sTimeoutLabelWidget->setPosition(timeoutPanelWidth * TIMEOUT_TEXT_POSITION_X_PERCENT / 100, timeoutPanelHeight * TIMEOUT_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTimeoutLabelWidget->setSize(timeoutPanelWidth     * TIMEOUT_TEXT_WIDTH_PERCENT      / 100, timeoutPanelHeight * TIMEOUT_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    }



    u64 toolButtonWidth  = screenWidth  * TOOL_BUTTON_WIDTH_PERCENT  / 100;
    u64 toolButtonHeight = screenHeight * TOOL_BUTTON_HEIGHT_PERCENT / 100;



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonNormalImage,       toolButtonWidth, toolButtonHeight, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonHoverImage,        toolButtonWidth, toolButtonHeight, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonPressedImage,      toolButtonWidth, toolButtonHeight, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonFocusedImage,      toolButtonWidth, toolButtonHeight, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(sButtonFocusedHoverImage, toolButtonWidth, toolButtonHeight, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



    sDeviceManagerButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, sDeviceManagerImage, nullptr, "Device Manager", rootWidget);

    UEFI_ASSERT_EXECUTION(sDeviceManagerButton->setPosition(screenWidth * DEVICE_MANAGER_BUTTON_POSITION_X_PERCENT / 100, screenHeight * DEVICE_MANAGER_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDeviceManagerButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDeviceManagerButton->setKeyboardEventHandler(onDeviceManagerButtonKeyboardEvent),                                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sDeviceManagerButton->setPressEventHandler(onDeviceManagerButtonPressed),                                                                                       NgosStatus::ASSERTION);



    sCpuTestButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, sCpuTestImage, nullptr, "CPU Test      ", rootWidget);

    UEFI_ASSERT_EXECUTION(sCpuTestButton->setPosition(screenWidth * CPU_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * CPU_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sCpuTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sCpuTestButton->setKeyboardEventHandler(onCpuTestButtonKeyboardEvent),                                                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sCpuTestButton->setPressEventHandler(onCpuTestButtonPressed),                                                                                 NgosStatus::ASSERTION);



    sMemoryTestButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, sMemoryTestImage, nullptr, "Memory Test   ", rootWidget);

    UEFI_ASSERT_EXECUTION(sMemoryTestButton->setPosition(screenWidth * MEMORY_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * MEMORY_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sMemoryTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sMemoryTestButton->setKeyboardEventHandler(onMemoryTestButtonKeyboardEvent),                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sMemoryTestButton->setPressEventHandler(onMemoryTestButtonPressed),                                                                                    NgosStatus::ASSERTION);



    sNetworkTestButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, sNetworkTestImage, nullptr, "Network Test  ", rootWidget);

    UEFI_ASSERT_EXECUTION(sNetworkTestButton->setPosition(screenWidth * NETWORK_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * NETWORK_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sNetworkTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sNetworkTestButton->setKeyboardEventHandler(onNetworkTestButtonKeyboardEvent),                                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sNetworkTestButton->setPressEventHandler(onNetworkTestButtonPressed),                                                                                     NgosStatus::ASSERTION);



    sHddTestButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, sHddTestImage, nullptr, "HDD Test      ", rootWidget);

    UEFI_ASSERT_EXECUTION(sHddTestButton->setPosition(screenWidth * HDD_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * HDD_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sHddTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sHddTestButton->setKeyboardEventHandler(onHddTestButtonKeyboardEvent),                                                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sHddTestButton->setPressEventHandler(onHddTestButtonPressed),                                                                                 NgosStatus::ASSERTION);



    sPartitionWizardButton = new Button(sButtonNormalImage, sButtonHoverImage, sButtonPressedImage, sButtonFocusedImage, sButtonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, sPartitionWizardImage, nullptr, "Partition     \nWizard        ", rootWidget);

    UEFI_ASSERT_EXECUTION(sPartitionWizardButton->setPosition(screenWidth * PARTITION_WIZARD_BUTTON_POSITION_X_PERCENT / 100, screenHeight * PARTITION_WIZARD_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sPartitionWizardButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sPartitionWizardButton->setKeyboardEventHandler(onPartitionWizardButtonKeyboardEvent),                                                                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sPartitionWizardButton->setPressEventHandler(onPartitionWizardButtonPressed),                                                                                         NgosStatus::ASSERTION);



    if (osCount > 0)
    {
        UEFI_ASSERT_EXECUTION(focusOsButton(), NgosStatus::ASSERTION);
    }
    else
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sDeviceManagerButton), NgosStatus::ASSERTION);
    }



    CursorWidget *cursorWidget = new CursorWidget(sCursorImage, rootWidget);

    UEFI_ASSERT_EXECUTION(cursorWidget->setPosition(GUI::getFocusedWidget()->getGlobalPositionX() + (GUI::getFocusedWidget()->getWidth() / 2), GUI::getFocusedWidget()->getGlobalPositionY() + (GUI::getFocusedWidget()->getHeight() / 2)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cursorWidget->setSize(CURSOR_SIZE, CURSOR_SIZE),                                                                                                                                                                  NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, screenWidget, cursorWidget), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(),                              NgosStatus::ASSERTION);

    UEFI_TEST_ASSERT(GUI::isUpdatesEnabled(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::exec()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(generateWaitEventList(), NgosStatus::ASSERTION);

    do
    {
        UEFI_ASSERT_EXECUTION(waitForEvent(), NgosStatus::ASSERTION);
    } while(true);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::cleanUp()
{
    UEFI_LT((""));



    if (sTimeoutLabelWidget)
    {
        UEFI_ASSERT_EXECUTION(free((char8 *)sTimeoutLabelWidget->getText()), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sRebootButton->setPredefined(false),  NgosStatus::ASSERTION); // It will force to release release for resized images

    if (sOsButtons.getSize() > 0)
    {
        UEFI_ASSERT_EXECUTION(sOsButtons.first()->setPredefined(false), NgosStatus::ASSERTION); // It will force to release memory for resized images
        UEFI_ASSERT_EXECUTION(sOsButtons.clear(),                       NgosStatus::ASSERTION);
    }

    if (sLeftButton)
    {
        UEFI_ASSERT_EXECUTION(sLeftButton->setPredefined(false), NgosStatus::ASSERTION); // It will force to release release for resized images
    }

    UEFI_ASSERT_EXECUTION(sCpuTestButton->setPredefined(false), NgosStatus::ASSERTION); // It will force to release release for resized images



    delete GUI::getRootWidget();



    delete sBackgroundImage;
    delete sButtonNormalImage;
    delete sButtonHoverImage;
    delete sButtonPressedImage;
    delete sButtonFocusedImage;
    delete sButtonFocusedHoverImage;
    delete sInfoPanelImage;
    delete sDeviceManagerImage;
    delete sCpuTestImage;
    delete sMemoryTestImage;
    delete sNetworkTestImage;
    delete sHddTestImage;
    delete sPartitionWizardImage;
    delete sRebootImage;
    delete sShutdownImage;
    delete sCursorImage;



    for (i64 i = 0; i < (i64)OsType::MAXIMUM; ++i)
    {
        if (sOsImages[i])
        {
            delete sOsImages[i];
        }
    }

    for (i64 i = 0; i < (i64)VolumeType::MAXIMUM; ++i)
    {
        if (sVolumeImages[i])
        {
            delete sVolumeImages[i];
        }
    }



    UEFI_ASSERT_EXECUTION(UefiPointerDevices::cleanUp(), NgosStatus::ASSERTION);

    if (UEFI::freePool(sWaitEvents) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for wait events", sWaitEvents));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for wait events", sWaitEvents));
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::focusOsButton()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sOsButtonRight > 0, NgosStatus::ASSERTION);



    return GUI::setFocusedWidget(sOsButtons.at(sOsButtonSelected));
}

NgosStatus BootloaderGUI::focusFirstOsButton()
{
    UEFI_LT((""));



    bool locked = false;

    if (sOsButtonLeft > 0)
    {
        locked = true;

        UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

        for (i64 i = 0; i < OS_VISIBLE_COUNT; ++i)
        {
            Button *button        = sOsButtons.at(i);
            Button *visibleButton = sOsButtons.at(sOsButtonLeft + i);

            button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
            button->setVisible(true);
        }

        for (i64 i = OS_VISIBLE_COUNT; i < (i64)sOsButtons.getSize(); ++i)
        {
            sOsButtons.at(i)->setVisible(false);
        }

        sOsButtonLeft  = 0;
        sOsButtonRight = OS_VISIBLE_COUNT;

        UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(false), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sRightButton->setVisible(true), NgosStatus::ASSERTION);
    }

    sOsButtonSelected = 0;



    UEFI_ASSERT_EXECUTION(focusOsButton(), NgosStatus::ASSERTION);



    if (locked)
    {
        UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::focusOsButtonLeft()
{
    UEFI_LT((""));



    sOsButtonSelected = sOsButtonLeft;



    return focusOsButton();
}

NgosStatus BootloaderGUI::focusOsButtonRight()
{
    UEFI_LT((""));



    sOsButtonSelected = sOsButtonRight - 1;



    return focusOsButton();
}

NgosStatus BootloaderGUI::focusPreviousOsButton()
{
    UEFI_LT((""));



    bool locked = false;

    if (sOsButtonSelected <= sOsButtonLeft)
    {
        if (sOsButtonLeft > 0)
        {
            locked = true;

            UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            for (i64 i = sOsButtonLeft; i < (i64)sOsButtonRight; ++i)
            {
                Button *button        = sOsButtons.at(i - 1);
                Button *visibleButton = sOsButtons.at(i);

                button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
            }

            --sOsButtonLeft;
            --sOsButtonRight;

            UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonLeft)->setVisible(true),   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonRight)->setVisible(false), NgosStatus::ASSERTION);

            UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(sOsButtonLeft > 0), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setVisible(true),             NgosStatus::ASSERTION);
        }
        else
        {
            return NgosStatus::NO_EFFECT;
        }
    }

    --sOsButtonSelected;



    UEFI_ASSERT_EXECUTION(focusOsButton(), NgosStatus::ASSERTION);



    if (locked)
    {
        UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::focusNextOsButton()
{
    UEFI_LT((""));



    bool locked = false;

    if (sOsButtonSelected + 1 >= sOsButtonRight)
    {
        if (sOsButtonRight < sOsButtons.getSize())
        {
            locked = true;

            UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            for (i64 i = sOsButtonRight; i > (i64)sOsButtonLeft; --i)
            {
                Button *button        = sOsButtons.at(i);
                Button *visibleButton = sOsButtons.at(i - 1);

                button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
            }

            UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonLeft)->setVisible(false), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonRight)->setVisible(true), NgosStatus::ASSERTION);

            ++sOsButtonLeft;
            ++sOsButtonRight;

            UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(true),                                   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setVisible(sOsButtonRight < sOsButtons.getSize()), NgosStatus::ASSERTION);
        }
        else
        {
            return NgosStatus::NO_EFFECT;
        }
    }

    ++sOsButtonSelected;



    UEFI_ASSERT_EXECUTION(focusOsButton(), NgosStatus::ASSERTION);



    if (locked)
    {
        UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::focusNextOsButtonOrGoDown()
{
    UEFI_LT((""));



    NgosStatus status = focusNextOsButton();

    if (status == NgosStatus::NO_EFFECT)
    {
        return GUI::setFocusedWidget(sDeviceManagerButton);
    }



    return status;
}

NgosStatus BootloaderGUI::generateWaitEventList()
{
    UEFI_LT((""));



    sWaitEventsCount = UefiPointerDevices::getSimplePointersCount() + UefiPointerDevices::getAbsolutePointersCount() + 1; // "+ 1" = keyboard event

    if (sTimeoutLabelWidget)
    {
        ++sWaitEventsCount;
    }

    u64 size = sWaitEventsCount * sizeof(uefi_event);



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



    if (sTimeoutLabelWidget)
    {
        UEFI_ASSERT_EXECUTION(UEFI::createEvent(UefiEventType::TIMER, UefiTpl::NONE, 0, 0, &sTimerEvent), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
        UEFI_LVV(("Created timer event(0x%p)", sTimerEvent));



        UEFI_ASSERT_EXECUTION(UEFI::setTimer(sTimerEvent, UefiTimerDelay::PERIODIC, UEFI_TIMER_SECOND), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
        UEFI_LVV(("Setup timer(0x%p) completed", sTimerEvent));



        sWaitEvents[eventId] = sTimerEvent;
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::waitForEvent()
{
    UEFI_LT((""));



    u64 eventIndex;

    UEFI_ASSERT_EXECUTION(UEFI::waitForEvent(sWaitEventsCount, sWaitEvents, &eventIndex), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("eventIndex = %u", eventIndex));



    if (eventIndex == 0)
    {
        return processKeyboardEvent();
    }



    if (eventIndex <= UefiPointerDevices::getSimplePointersCount())
    {
        return processSimplePointerEvent(UefiPointerDevices::getSimplePointer(eventIndex - 1));
    }



    if (sWaitEvents[eventIndex] == sTimerEvent)
    {
        return processTimerEvent();
    }



    return processAbsolutePointerEvent(UefiPointerDevices::getAbsolutePointer(eventIndex - UefiPointerDevices::getSimplePointersCount() - 1));
}

NgosStatus BootloaderGUI::processKeyboardEvent()
{
    UEFI_LT((""));



    UefiInputKey key;

    UEFI_ASSERT_EXECUTION(UEFI::getSystemTable()->stdin->readKeyStroke(UEFI::getSystemTable()->stdin, &key), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("key.scanCode    = %s",     enumToFullString(key.scanCode)));
    UEFI_LVVV(("key.unicodeChar = 0x%04X", key.unicodeChar));



    if (sTimerEvent)
    {
        UEFI_ASSERT_EXECUTION(disableTimerEvent(), NgosStatus::ASSERTION);
    }



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

NgosStatus BootloaderGUI::processSimplePointerEvent(UefiSimplePointerProtocol *pointer)
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



        if (
            sTimerEvent
            &&
            (
             state.leftButton
             ||
             state.rightButton
            )
           )
        {
            UEFI_ASSERT_EXECUTION(disableTimerEvent(), NgosStatus::ASSERTION);
        }



        UEFI_ASSERT_EXECUTION(GUI::processSimplePointerState(&state), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer)
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



        if (sTimerEvent)
        {
            UEFI_ASSERT_EXECUTION(disableTimerEvent(), NgosStatus::ASSERTION);
        }



        UEFI_ASSERT_EXECUTION(GUI::processAbsolutePointerState(pointer, &state), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::processTimerEvent()
{
    UEFI_LT((""));



    --sTimeoutTick;

    if (sTimeoutTick > 0)
    {
        char8 *timeoutText = (char8 *)sTimeoutLabelWidget->getText();

        if (sTimeoutTick > 1)
        {
            UEFI_ASSERT_EXECUTION(sprintf(timeoutText, "Automatic boot in %u seconds", sTimeoutTick), i64, TIMEOUT_TEXT_LENGTH - 1, NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_ASSERT_EXECUTION(sprintf(timeoutText, "Automatic boot in 1 second"), i64, TIMEOUT_TEXT_LENGTH - 2, NgosStatus::ASSERTION);
        }

        UEFI_ASSERT_EXECUTION(sTimeoutLabelWidget->setText(timeoutText), NgosStatus::ASSERTION);
    }
    else
    {
        return onOsButtonPressed();
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::disableTimerEvent()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sTimerEvent != nullptr, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(UEFI::closeEvent(sTimerEvent), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_LVV(("Closed timer event(0x%p)", sTimerEvent));

    sTimerEvent = nullptr;
    --sWaitEventsCount;



    sTimeoutPanelWidget->setVisible(false);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onRebootButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sHddTestButton);
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sShutdownButton);

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

NgosStatus BootloaderGUI::onShutdownButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP: return GUI::setFocusedWidget(sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return sOsButtonRight > 0 ? focusFirstOsButton() : GUI::setFocusedWidget(sDeviceManagerButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onOsButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sCpuTestButton);
        case UefiInputKeyScanCode::LEFT:  return focusPreviousOsButton();
        case UefiInputKeyScanCode::RIGHT: return focusNextOsButton();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return focusNextOsButtonOrGoDown();

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onLeftButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sDeviceManagerButton);
        case UefiInputKeyScanCode::RIGHT: return focusOsButtonLeft();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return focusOsButtonLeft();

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onRightButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sMemoryTestButton);
        case UefiInputKeyScanCode::LEFT: return focusOsButtonRight();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sDeviceManagerButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onDeviceManagerButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:    return sOsButtonRight > 0 ? focusOsButton() : NgosStatus::NO_EFFECT;
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sNetworkTestButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sCpuTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sCpuTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onCpuTestButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:    return sOsButtonRight > 0 ? focusOsButton() : NgosStatus::NO_EFFECT;
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sHddTestButton);
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sDeviceManagerButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sMemoryTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sMemoryTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onMemoryTestButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:    return sOsButtonRight > 0 ? focusOsButton() : NgosStatus::NO_EFFECT;
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sPartitionWizardButton);
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sCpuTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sNetworkTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onNetworkTestButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:    return GUI::setFocusedWidget(sDeviceManagerButton);
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sHddTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sHddTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onHddTestButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:    return GUI::setFocusedWidget(sCpuTestButton);
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sNetworkTestButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sPartitionWizardButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sPartitionWizardButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onPartitionWizardButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sMemoryTestButton);
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sHddTestButton);

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

NgosStatus BootloaderGUI::onRebootButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::COLD, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onShutdownButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::SHUTDOWN, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onOsButtonPressed()
{
    UEFI_LT((""));



    const OsInfo &os = Bootloader::getOSes().at(sOsButtonSelected);

    if (UEFI::setVariable(u"LastOsVolumeGuid", &bootloaderGUID, sizeof(*os.volume->partitionUniqueGuid), (u8 *)os.volume->partitionUniqueGuid) == UefiStatus::SUCCESS)
    {
        UEFI_LV(("Stored LastOsVolumeGuid NVRAM variable: %s", guidToString(os.volume->partitionUniqueGuid)));
    }
    else
    {
        UEFI_LE(("Failed to store LastOsVolumeGuid NVRAM variable"));
    }

    if (UEFI::setVariable(u"LastOsPath", &bootloaderGUID, (strlen(os.path) + 1) * sizeof(char16), (u8 *)os.path) == UefiStatus::SUCCESS)
    {
        UEFI_LV(("Stored LastOsPath NVRAM variable: %ls", os.path));
    }
    else
    {
        UEFI_LE(("Failed to store LastOsPath NVRAM variable"));
    }



    UEFI_ASSERT_EXECUTION(Bootloader::startOs(sOsButtonSelected), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onLeftButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(sOsButtonLeft > 0, NgosStatus::ASSERTION);

    for (i64 i = sOsButtonLeft; i < (i64)sOsButtonRight; ++i)
    {
        Button *button        = sOsButtons.at(i - 1);
        Button *visibleButton = sOsButtons.at(i);

        button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
    }

    --sOsButtonLeft;
    --sOsButtonRight;

    UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonLeft)->setVisible(true),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonRight)->setVisible(false), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(sOsButtonLeft > 0), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRightButton->setVisible(true),             NgosStatus::ASSERTION);



    if (sOsButtonLeft == 0)
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sRightButton), NgosStatus::ASSERTION);
    }

    sOsButtonSelected = sOsButtonLeft;



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onRightButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(sOsButtonRight < sOsButtons.getSize(), NgosStatus::ASSERTION);

    for (i64 i = sOsButtonRight; i > (i64)sOsButtonLeft; --i)
    {
        Button *button        = sOsButtons.at(i);
        Button *visibleButton = sOsButtons.at(i - 1);

        button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
    }

    UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonLeft)->setVisible(false), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonRight)->setVisible(true), NgosStatus::ASSERTION);

    ++sOsButtonLeft;
    ++sOsButtonRight;

    UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(true),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRightButton->setVisible(sOsButtonRight < sOsButtons.getSize()), NgosStatus::ASSERTION);



    if (sOsButtonRight >= sOsButtons.getSize())
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sLeftButton), NgosStatus::ASSERTION);
    }

    sOsButtonSelected = sOsButtonRight - 1;



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onDeviceManagerButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\devicemanager.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onCpuTestButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\cputest.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onMemoryTestButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\memorytest.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onNetworkTestButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\networktest.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onHddTestButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\hddtest.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onPartitionWizardButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\partitionwizard.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
