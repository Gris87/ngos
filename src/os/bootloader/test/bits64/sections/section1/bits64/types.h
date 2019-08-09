#ifndef BOOTLOADER_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
#define BOOTLOADER_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/bits64/main/bootloader.h"
#include "src/bits64/main/bootloadergui.h"
#include "src/bits64/other/volumeinfo.h"
#include "src/bits64/other/volumetype.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(Bootloader),    1);
        TEST_ASSERT_EQUALS(sizeof(BootloaderGUI), 1);
        TEST_ASSERT_EQUALS(sizeof(VolumeInfo),    64);
        TEST_ASSERT_EQUALS(sizeof(VolumeType),    1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // BOOTLOADER_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
