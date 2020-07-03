#ifndef KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYMANAGER_H
#define KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYMANAGER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/memory/memory.h>

#include <com/ngos/kernel/other/memorymanager/memorymanager.h>
#include <com/ngos/kernel/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, com_ngos_kernel_other_memorymanager_memorymanager);
{
    TEST_CASE("init()");
    {
        TEST_ASSERT_EQUALS(memempty(&MemoryManager::sMemoryBlock,     sizeof(MemoryManager::sMemoryBlock)),     true);
        TEST_ASSERT_EQUALS(memempty(&MemoryManager::sMemoryRegions,   sizeof(MemoryManager::sMemoryRegions)),   true);
        TEST_ASSERT_EQUALS(memempty(&MemoryManager::sReservedRegions, sizeof(MemoryManager::sReservedRegions)), true);

        TEST_ASSERT_EQUALS(MemoryManager::init(), NgosStatus::OK);

        TEST_ASSERT_EQUALS(memempty(&MemoryManager::sMemoryBlock,     sizeof(MemoryManager::sMemoryBlock)),     false);
        TEST_ASSERT_EQUALS(memempty(&MemoryManager::sMemoryRegions,   sizeof(MemoryManager::sMemoryRegions)),   true);
        TEST_ASSERT_EQUALS(memempty(&MemoryManager::sReservedRegions, sizeof(MemoryManager::sReservedRegions)), true);
    }
    TEST_CASE_END();



    TEST_CASE("add()");
    {
        TEST_ASSERT_EQUALS(MemoryManager::add(50000, 2000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.count,     1);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.totalSize, 2000);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::add(90000, 5000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.count,     2);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.totalSize, 7000);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::add(10000, 3000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.count,     3);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.totalSize, 10000);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::add(30000, 1000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.count,     4);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.totalSize, 11000);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::add(70000, 4000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.count,     5);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.totalSize, 15000);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].start,  70000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].size,   4000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::add(45000, 6000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.count,     5);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.totalSize, 20000);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].start,  45000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].size,   7000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].start,  70000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].size,   4000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::add(51000, 4000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.count,     5);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.totalSize, 23000);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].start,  45000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].size,   10000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].start,  70000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].size,   4000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::add(47000, 2000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.count,     5);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.totalSize, 23000);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].start,  45000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].size,   10000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].start,  70000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].size,   4000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[3].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[4].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::add(500, 100000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.count,     1);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.memory.totalSize, 100000);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].start,  500);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].size,   100000);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryRegions[0].nodeId, 0x0400);
    }
    TEST_CASE_END();



    TEST_CASE("reserve()");
    {
        TEST_ASSERT_EQUALS(MemoryManager::reserve(50000, 2000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.count,     1);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.totalSize, 2000);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::reserve(90000, 5000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.count,     2);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.totalSize, 7000);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::reserve(10000, 3000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.count,     3);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.totalSize, 10000);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::reserve(30000, 1000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.count,     4);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.totalSize, 11000);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::reserve(70000, 4000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.count,     5);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.totalSize, 15000);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].start,  50000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].start,  70000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].size,   4000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::reserve(45000, 6000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.count,     5);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.totalSize, 20000);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].start,  45000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].size,   7000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].start,  70000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].size,   4000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::reserve(51000, 4000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.count,     5);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.totalSize, 23000);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].start,  45000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].size,   10000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].start,  70000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].size,   4000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::reserve(47000, 2000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.count,     5);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.totalSize, 23000);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[1].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].start,  45000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].size,   10000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[2].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].start,  70000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].size,   4000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[3].nodeId, 0x0400);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].start,  90000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[4].nodeId, 0x0400);



        TEST_ASSERT_EQUALS(MemoryManager::reserve(500, 100000), NgosStatus::OK);

        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.count,     1);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.max,       128);
        TEST_ASSERT_EQUALS(MemoryManager::sMemoryBlock.reserved.totalSize, 100000);

        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].start,  500);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].size,   100000);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].flags,  0);
        TEST_ASSERT_EQUALS(MemoryManager::sReservedRegions[0].nodeId, 0x0400);
    }
    TEST_CASE_END();



    TEST_CASE("insertRegion()");
    {
        MemoryBlockType   blockType;
        MemoryBlockRegion blockRegions[10];

        blockType.count     = 0;
        blockType.max       = 10;
        blockType.totalSize = 0;
        blockType.regions   = blockRegions;



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 1000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     1);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 2000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 5000, 3000, 9, 555), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     2);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 5000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 1, 3000, 4000, 7, 321), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     3);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 9000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 2, 2000, 1000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     4);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 10000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 1000, 3000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     5);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 13000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);
    }
    TEST_CASE_END();



    TEST_CASE("removeRegion()");
    {
        MemoryBlockType   blockType;
        MemoryBlockRegion blockRegions[10];

        blockType.count     = 0;
        blockType.max       = 10;
        blockType.totalSize = 0;
        blockType.regions   = blockRegions;



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 1000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     1);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 2000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 5000, 3000, 9, 555), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     2);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 5000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 1, 3000, 4000, 7, 321), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     3);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 9000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 2, 2000, 1000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     4);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 10000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 1000, 3000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     5);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 13000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::removeRegion(&blockType, 1), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     4);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 10000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::removeRegion(&blockType, 0), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     3);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 7000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::removeRegion(&blockType, 1), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     2);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 6000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::removeRegion(&blockType, 1), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     1);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 4000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 321);



        TEST_ASSERT_EQUALS(MemoryManager::removeRegion(&blockType, 0), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     0);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 0);
    }
    TEST_CASE_END();



    TEST_CASE("removeRegions()");
    {
        MemoryBlockType   blockType;
        MemoryBlockRegion blockRegions[10];

        blockType.count     = 0;
        blockType.max       = 10;
        blockType.totalSize = 0;
        blockType.regions   = blockRegions;



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 1000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     1);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 2000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 5000, 3000, 9, 555), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     2);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 5000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 1, 3000, 4000, 7, 321), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     3);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 9000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 2, 2000, 1000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     4);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 10000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 1000, 3000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     5);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 13000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  5000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  9);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 555);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  7);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 321);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::removeRegions(&blockType, 1, 2), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     3);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 6000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::removeRegions(&blockType, 0, 1), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     2);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 3000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  2000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::removeRegions(&blockType, 0, 2), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     0);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 0);
    }
    TEST_CASE_END();



    TEST_CASE("mergeRegions()");
    {
        MemoryBlockType   blockType;
        MemoryBlockRegion blockRegions[10];

        blockType.count     = 0;
        blockType.max       = 10;
        blockType.totalSize = 0;
        blockType.regions   = blockRegions;



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 0, 1000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     1);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 2000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 1, 3000, 3000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     2);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 5000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::insertRegion(&blockType, 2, 6000, 4000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     3);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 9000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  3000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  6000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::mergeRegions(&blockType), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     1);
        TEST_ASSERT_EQUALS(blockType.max,       10);
        TEST_ASSERT_EQUALS(blockType.totalSize, 9000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  1000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);
    }
    TEST_CASE_END();



    TEST_CASE("addRange()");
    {
        MemoryBlockType   blockType;
        MemoryBlockRegion blockRegions[20];

        blockType.count     = 0;
        blockType.max       = 20;
        blockType.totalSize = 0;
        blockType.regions   = blockRegions;



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 50000, 5000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     1);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 5000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 70000, 1000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     2);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 6000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 90000, 3000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     3);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 9000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 30000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     4);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 11000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 10000, 4000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     5);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 15000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 20000, 1000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     6);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 16000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 40000, 7000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     7);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 23000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 60000, 6000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     8);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 29000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 80000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     9);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 31000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 85000, 1000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     10);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 32000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 15000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     11);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 34000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 25000, 3000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     12);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 37000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 75000, 3000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     13);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 40000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 67000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     14);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 42000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 35000, 3000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     15);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 45000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 48000, 1000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     16);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 46000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 57000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     17);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 48000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 93000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     17);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 50000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  90000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 88000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     17);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 52000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  88000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 87000, 9000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     17);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 54000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 14000, 500, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     17);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 54500);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  10000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   4500);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 8000, 2000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     17);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 56500);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  8000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   6500);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 86000, 1000, 4, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     18);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 57500);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  8000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   6500);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  86000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[17].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[17].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[17].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[17].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 96000, 1000, 4, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     19);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 58500);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  8000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   6500);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  86000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[17].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[17].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[17].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[17].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[18].start,  96000);
        TEST_ASSERT_EQUALS(blockRegions[18].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[18].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[18].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 7000, 1000, 4, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     20);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 59500);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  7000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  8000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   6500);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  20000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[17].start,  86000);
        TEST_ASSERT_EQUALS(blockRegions[17].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[17].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[17].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[18].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[18].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[18].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[18].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[19].start,  96000);
        TEST_ASSERT_EQUALS(blockRegions[19].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[19].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[19].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 18000, 2500, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     20);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 61500);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  7000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  8000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   6500);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  18000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[17].start,  86000);
        TEST_ASSERT_EQUALS(blockRegions[17].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[17].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[17].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[18].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[18].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[18].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[18].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[19].start,  96000);
        TEST_ASSERT_EQUALS(blockRegions[19].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[19].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[19].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 31000, 3000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     20);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 63500);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  7000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  8000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   6500);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  18000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[17].start,  86000);
        TEST_ASSERT_EQUALS(blockRegions[17].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[17].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[17].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[18].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[18].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[18].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[18].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[19].start,  96000);
        TEST_ASSERT_EQUALS(blockRegions[19].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[19].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[19].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 36000, 1000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     20);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 63500);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  7000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  8000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   6500);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  18000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  75000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[17].start,  86000);
        TEST_ASSERT_EQUALS(blockRegions[17].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[17].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[17].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[18].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[18].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[18].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[18].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[19].start,  96000);
        TEST_ASSERT_EQUALS(blockRegions[19].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[19].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[19].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 73000, 6000, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     20);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 66500);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  7000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  8000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   6500);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  15000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  18000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  25000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[5].start,  30000);
        TEST_ASSERT_EQUALS(blockRegions[5].size,   4000);
        TEST_ASSERT_EQUALS(blockRegions[5].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[5].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[6].start,  35000);
        TEST_ASSERT_EQUALS(blockRegions[6].size,   3000);
        TEST_ASSERT_EQUALS(blockRegions[6].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[6].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[7].start,  40000);
        TEST_ASSERT_EQUALS(blockRegions[7].size,   7000);
        TEST_ASSERT_EQUALS(blockRegions[7].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[7].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[8].start,  48000);
        TEST_ASSERT_EQUALS(blockRegions[8].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[8].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[8].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[9].start,  50000);
        TEST_ASSERT_EQUALS(blockRegions[9].size,   5000);
        TEST_ASSERT_EQUALS(blockRegions[9].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[9].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[10].start,  57000);
        TEST_ASSERT_EQUALS(blockRegions[10].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[10].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[10].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[11].start,  60000);
        TEST_ASSERT_EQUALS(blockRegions[11].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[11].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[11].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[12].start,  67000);
        TEST_ASSERT_EQUALS(blockRegions[12].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[12].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[12].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[13].start,  70000);
        TEST_ASSERT_EQUALS(blockRegions[13].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[13].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[13].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[14].start,  73000);
        TEST_ASSERT_EQUALS(blockRegions[14].size,   6000);
        TEST_ASSERT_EQUALS(blockRegions[14].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[14].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[15].start,  80000);
        TEST_ASSERT_EQUALS(blockRegions[15].size,   2000);
        TEST_ASSERT_EQUALS(blockRegions[15].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[15].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[16].start,  85000);
        TEST_ASSERT_EQUALS(blockRegions[16].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[16].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[16].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[17].start,  86000);
        TEST_ASSERT_EQUALS(blockRegions[17].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[17].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[17].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[18].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[18].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[18].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[18].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[19].start,  96000);
        TEST_ASSERT_EQUALS(blockRegions[19].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[19].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[19].nodeId, 123);



        TEST_ASSERT_EQUALS(MemoryManager::addRange(&blockType, 9000, 76500, 5, 123), NgosStatus::OK);

        TEST_ASSERT_EQUALS(blockType.count,     5);
        TEST_ASSERT_EQUALS(blockType.max,       20);
        TEST_ASSERT_EQUALS(blockType.totalSize, 90000);

        TEST_ASSERT_EQUALS(blockRegions[0].start,  7000);
        TEST_ASSERT_EQUALS(blockRegions[0].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[0].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[0].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[1].start,  8000);
        TEST_ASSERT_EQUALS(blockRegions[1].size,   78000);
        TEST_ASSERT_EQUALS(blockRegions[1].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[1].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[2].start,  86000);
        TEST_ASSERT_EQUALS(blockRegions[2].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[2].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[2].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[3].start,  87000);
        TEST_ASSERT_EQUALS(blockRegions[3].size,   9000);
        TEST_ASSERT_EQUALS(blockRegions[3].flags,  5);
        TEST_ASSERT_EQUALS(blockRegions[3].nodeId, 123);

        TEST_ASSERT_EQUALS(blockRegions[4].start,  96000);
        TEST_ASSERT_EQUALS(blockRegions[4].size,   1000);
        TEST_ASSERT_EQUALS(blockRegions[4].flags,  4);
        TEST_ASSERT_EQUALS(blockRegions[4].nodeId, 123);
    }
    TEST_CASE_END();



    TEST_CASE("Clean up");
    {
        TEST_ASSERT_EQUALS(memempty(&MemoryManager::sMemoryBlock,     sizeof(MemoryManager::sMemoryBlock)),     false);
        TEST_ASSERT_EQUALS(memempty(&MemoryManager::sMemoryRegions,   sizeof(MemoryManager::sMemoryRegions)),   false);
        TEST_ASSERT_EQUALS(memempty(&MemoryManager::sReservedRegions, sizeof(MemoryManager::sReservedRegions)), false);

        TEST_ASSERT_EQUALS(memzero(&MemoryManager::sMemoryBlock,     sizeof(MemoryManager::sMemoryBlock)),     &MemoryManager::sMemoryBlock);
        TEST_ASSERT_EQUALS(memzero(&MemoryManager::sMemoryRegions,   sizeof(MemoryManager::sMemoryRegions)),   &MemoryManager::sMemoryRegions);
        TEST_ASSERT_EQUALS(memzero(&MemoryManager::sReservedRegions, sizeof(MemoryManager::sReservedRegions)), &MemoryManager::sReservedRegions);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYMANAGER_H
