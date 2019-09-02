#ifndef BOOTLOADER_TEST_BITS64_SECTIONS_SECTION1_BITS64_MAIN_BOOTLOADER_H
#define BOOTLOADER_TEST_BITS64_SECTIONS_SECTION1_BITS64_MAIN_BOOTLOADER_H



#include <buildconfig.h>
#include <common/src/bits64/string/string.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/bits64/main/bootloader.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_main_bootloader);
{
    TEST_CASE("cleanUpPath()");
    {
        char8 path1[32];
        char8 path2[32];
        char8 path3[32];
        char8 path4[32];
        char8 path5[32];
        char8 path6[32];
        char8 path7[32];
        char8 path8[32];
        char8 path9[32];

        TEST_ASSERT_EQUALS(strcpy(path1, "/EFI/BOOT/BOOTX64.EFI"),    path1);
        TEST_ASSERT_EQUALS(strcpy(path2, "\\EFI\\BOOT\\BOOTX64.EFI"), path2);
        TEST_ASSERT_EQUALS(strcpy(path3, "/EFI//BOOT///BOOTX64.EFI"), path3);
        TEST_ASSERT_EQUALS(strcpy(path4, "/EFI/BOOT\\/BOOTX64.EFI"),  path4);
        TEST_ASSERT_EQUALS(strcpy(path5, "/EFI\\\\BOOT/"),            path5);
        TEST_ASSERT_EQUALS(strcpy(path6, "EFI////BOOT\\"),            path6);
        TEST_ASSERT_EQUALS(strcpy(path7, "/"),                        path7);
        TEST_ASSERT_EQUALS(strcpy(path8, "\\"),                       path8);
        TEST_ASSERT_EQUALS(strcpy(path9, ""),                         path9);

        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path4), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path6), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path7), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path8), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path9), NgosStatus::OK);

        TEST_ASSERT_EQUALS(strcmp(path1, "EFI\\BOOT\\BOOTX64.EFI"), 0);
        TEST_ASSERT_EQUALS(strcmp(path2, "EFI\\BOOT\\BOOTX64.EFI"), 0);
        TEST_ASSERT_EQUALS(strcmp(path3, "EFI\\BOOT\\BOOTX64.EFI"), 0);
        TEST_ASSERT_EQUALS(strcmp(path4, "EFI\\BOOT\\BOOTX64.EFI"), 0);
        TEST_ASSERT_EQUALS(strcmp(path5, "EFI\\BOOT"),              0);
        TEST_ASSERT_EQUALS(strcmp(path6, "EFI\\BOOT"),              0);
        TEST_ASSERT_EQUALS(strcmp(path7, "\\"),                     0);
        TEST_ASSERT_EQUALS(strcmp(path8, "\\"),                     0);
        TEST_ASSERT_EQUALS(strcmp(path9, "\\"),                     0);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // BOOTLOADER_TEST_BITS64_SECTIONS_SECTION1_BITS64_MAIN_BOOTLOADER_H
