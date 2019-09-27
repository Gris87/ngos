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
        char16 path1[32];
        char16 path2[32];
        char16 path3[32];
        char16 path4[32];
        char16 path5[32];
        char16 path6[32];
        char16 path7[32];
        char16 path8[32];
        char16 path9[32];

        TEST_ASSERT_EQUALS(strcpy(path1, u"/EFI/BOOT/BOOTX64.EFI"),    path1);
        TEST_ASSERT_EQUALS(strcpy(path2, u"\\EFI\\BOOT\\BOOTX64.EFI"), path2);
        TEST_ASSERT_EQUALS(strcpy(path3, u"/EFI//BOOT///BOOTX64.EFI"), path3);
        TEST_ASSERT_EQUALS(strcpy(path4, u"/EFI/BOOT\\/BOOTX64.EFI"),  path4);
        TEST_ASSERT_EQUALS(strcpy(path5, u"/EFI\\\\BOOT/"),            path5);
        TEST_ASSERT_EQUALS(strcpy(path6, u"EFI////BOOT\\"),            path6);
        TEST_ASSERT_EQUALS(strcpy(path7, u"/"),                        path7); // Ignore CppSingleCharVerifier
        TEST_ASSERT_EQUALS(strcpy(path8, u"\\"),                       path8); // Ignore CppSingleCharVerifier
        TEST_ASSERT_EQUALS(strcpy(path9, u""),                         path9);

        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path4), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path6), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path7), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path8), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::cleanUpPath(path9), NgosStatus::OK);

        TEST_ASSERT_EQUALS(strcmp(path1, u"EFI\\BOOT\\BOOTX64.EFI"), 0);
        TEST_ASSERT_EQUALS(strcmp(path2, u"EFI\\BOOT\\BOOTX64.EFI"), 0);
        TEST_ASSERT_EQUALS(strcmp(path3, u"EFI\\BOOT\\BOOTX64.EFI"), 0);
        TEST_ASSERT_EQUALS(strcmp(path4, u"EFI\\BOOT\\BOOTX64.EFI"), 0);
        TEST_ASSERT_EQUALS(strcmp(path5, u"EFI\\BOOT"),              0);
        TEST_ASSERT_EQUALS(strcmp(path6, u"EFI\\BOOT"),              0);
        TEST_ASSERT_EQUALS(strcmp(path7, u"\\"),                     0); // Ignore CppSingleCharVerifier
        TEST_ASSERT_EQUALS(strcmp(path8, u"\\"),                     0); // Ignore CppSingleCharVerifier
        TEST_ASSERT_EQUALS(strcmp(path9, u"\\"),                     0); // Ignore CppSingleCharVerifier
    }
    TEST_CASE_END();



    TEST_CASE("buildPath()");
    {
        char16 *path1;
        char16 *path2;
        char16 *path3;
        char16 *path4;
        char16 *path5;
        char16 *path6;
        char16 *path7;

        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"",                  u"EFI",            &path1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI",               u"BOOT",           &path2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI",               u"NGOS",           &path3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI\\BOOT",         u"bootx64.efi",    &path4), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI\\NGOS",         u"kernel.efi",     &path5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI\\BOOT",         u"images",         &path6), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI\\BOOT\\images", u"background.jpg", &path7), NgosStatus::OK);

        TEST_ASSERT_EQUALS(strcmp(path1, u"EFI"),                               0);
        TEST_ASSERT_EQUALS(strcmp(path2, u"EFI\\BOOT"),                         0);
        TEST_ASSERT_EQUALS(strcmp(path3, u"EFI\\NGOS"),                         0);
        TEST_ASSERT_EQUALS(strcmp(path4, u"EFI\\BOOT\\bootx64.efi"),            0);
        TEST_ASSERT_EQUALS(strcmp(path5, u"EFI\\NGOS\\kernel.efi"),             0);
        TEST_ASSERT_EQUALS(strcmp(path6, u"EFI\\BOOT\\images"),                 0);
        TEST_ASSERT_EQUALS(strcmp(path7, u"EFI\\BOOT\\images\\background.jpg"), 0);

        TEST_ASSERT_EQUALS(UEFI::freePool(path1), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path2), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path3), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path4), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path5), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path6), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path7), UefiStatus::SUCCESS);
    }
    TEST_CASE_END();



    TEST_CASE("buildPath()");
    {
        char16 *path1;
        char16 *path2;
        char16 *path3;
        char16 *path4;
        char16 *path5;
        char16 *path6;
        char16 *path7;

        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"",                  "EFI",            &path1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI",               "BOOT",           &path2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI",               "NGOS",           &path3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI\\BOOT",         "bootx64.efi",    &path4), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI\\NGOS",         "kernel.efi",     &path5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI\\BOOT",         "images",         &path6), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Bootloader::buildPath(u"EFI\\BOOT\\images", "background.jpg", &path7), NgosStatus::OK);

        TEST_ASSERT_EQUALS(strcmp(path1, u"EFI"),                               0);
        TEST_ASSERT_EQUALS(strcmp(path2, u"EFI\\BOOT"),                         0);
        TEST_ASSERT_EQUALS(strcmp(path3, u"EFI\\NGOS"),                         0);
        TEST_ASSERT_EQUALS(strcmp(path4, u"EFI\\BOOT\\bootx64.efi"),            0);
        TEST_ASSERT_EQUALS(strcmp(path5, u"EFI\\NGOS\\kernel.efi"),             0);
        TEST_ASSERT_EQUALS(strcmp(path6, u"EFI\\BOOT\\images"),                 0);
        TEST_ASSERT_EQUALS(strcmp(path7, u"EFI\\BOOT\\images\\background.jpg"), 0);

        TEST_ASSERT_EQUALS(UEFI::freePool(path1), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path2), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path3), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path4), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path5), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path6), UefiStatus::SUCCESS);
        TEST_ASSERT_EQUALS(UEFI::freePool(path7), UefiStatus::SUCCESS);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // BOOTLOADER_TEST_BITS64_SECTIONS_SECTION1_BITS64_MAIN_BOOTLOADER_H
