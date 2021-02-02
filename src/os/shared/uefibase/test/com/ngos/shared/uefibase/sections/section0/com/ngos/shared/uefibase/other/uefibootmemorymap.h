#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H



#include <buildconfig.h>
#include <com/ngos/shared/uefibase/other/uefibootmemorymap.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_uefibase_other_uefibootmemorymap);
{
    TEST_CASE("MEMORY_MAP_DESCRIPTOR()");
    {
        UefiMemoryDescriptor  descriptors[5];
        bad_uint64                   descriptorSize = sizeof(UefiMemoryDescriptor);
        UefiMemoryDescriptor *memoryMap      = &descriptors[0];



        UefiBootMemoryMap bootMemoryMap;

        bootMemoryMap.memoryMap      = &memoryMap;
        bootMemoryMap.descriptorSize = &descriptorSize;



        TEST_ASSERT_EQUALS(MEMORY_MAP_DESCRIPTOR(&bootMemoryMap, 0), &descriptors[0]);
        TEST_ASSERT_EQUALS(MEMORY_MAP_DESCRIPTOR(&bootMemoryMap, 1), &descriptors[1]);
        TEST_ASSERT_EQUALS(MEMORY_MAP_DESCRIPTOR(&bootMemoryMap, 2), &descriptors[2]);
        TEST_ASSERT_EQUALS(MEMORY_MAP_DESCRIPTOR(&bootMemoryMap, 3), &descriptors[3]);
        TEST_ASSERT_EQUALS(MEMORY_MAP_DESCRIPTOR(&bootMemoryMap, 4), &descriptors[4]);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H
