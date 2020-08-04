#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_UEFIBASE_TYPES_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_UEFIBASE_TYPES_H



#include <buildconfig.h>
#include <com/ngos/shared/uefibase/other/uefibootmemorymap.h>
#include <com/ngos/shared/uefibase/testengine.h>
#include <com/ngos/shared/uefibase/uefi/uefi.h>
#include <com/ngos/shared/uefibase/uefi/uefilogfile.h>
#include <com/ngos/shared/uefibase/uefi/uefipointerdevices.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_uefibase_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(UEFI),               1);
        TEST_ASSERT_EQUALS(sizeof(UefiBootMemoryMap),  48);
        TEST_ASSERT_EQUALS(sizeof(UefiPointerDevices), 1);

#if NGOS_BUILD_LOG_TO_UEFI_FILE == OPTION_YES
        TEST_ASSERT_EQUALS(sizeof(UefiLogFile), 1);
#endif
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_UEFIBASE_TYPES_H
