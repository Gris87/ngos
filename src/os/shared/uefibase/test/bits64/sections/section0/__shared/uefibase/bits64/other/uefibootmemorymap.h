#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_OTHER_UEFIBOOTMEMORYMAP_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_OTHER_UEFIBOOTMEMORYMAP_H



#include <buildconfig.h>
#include <uefibase/src/bits64/other/uefibootmemorymap.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_uefibase_bits64_other_uefibootmemorymap);
{
    TEST_CASE("MEMORY_MAP_DESCRIPTOR()");
    {
        UefiMemoryDescriptor  descriptors[5];
        u64                   descriptorSize = sizeof(UefiMemoryDescriptor);
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



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_OTHER_UEFIBOOTMEMORYMAP_H
