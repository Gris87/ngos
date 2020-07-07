#ifndef BOOTLOADER_TEST_COM_NGOS_BOOTLOADER_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TYPES_H
#define BOOTLOADER_TEST_COM_NGOS_BOOTLOADER_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TYPES_H



#include <buildconfig.h>
#include <com/ngos/bootloader/main/bootloader.h>
#include <com/ngos/bootloader/main/bootloadergui.h>
#include <com/ngos/bootloader/other/osinfo.h>
#include <com/ngos/bootloader/other/ostype.h>
#include <com/ngos/bootloader/other/volumeinfo.h>
#include <com/ngos/bootloader/other/volumetype.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, com_ngos_bootloader_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(Bootloader),    1);
        TEST_ASSERT_EQUALS(sizeof(BootloaderGUI), 1);
        TEST_ASSERT_EQUALS(sizeof(OsInfo),        24);
        TEST_ASSERT_EQUALS(sizeof(OsType),        1);
        TEST_ASSERT_EQUALS(sizeof(VolumeInfo),    104);
        TEST_ASSERT_EQUALS(sizeof(VolumeType),    1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // BOOTLOADER_TEST_COM_NGOS_BOOTLOADER_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TYPES_H
