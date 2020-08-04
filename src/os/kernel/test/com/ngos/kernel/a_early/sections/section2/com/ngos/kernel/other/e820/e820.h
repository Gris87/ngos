#ifndef COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_E820_E820_H
#define COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_E820_E820_H



#include <buildconfig.h>
#include <com/ngos/kernel/a_early/testengine.h>
#include <com/ngos/kernel/other/e820/e820.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, com_ngos_kernel_other_e820_e820);
{
    TEST_CASE("insertRangeInTable()");
    {
        E820Table table;

        table.count = 0;



        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 0, 0x2000, 0x1000, MemoryMapEntryType::RAM), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                  1);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                       0x2000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                        0x1000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                        MemoryMapEntryType::RAM);

        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 0, 0x5000, 0x4000, MemoryMapEntryType::NVS), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                  2);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                       0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                        0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                        MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,                                                       0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].size,                                                        0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,                                                        MemoryMapEntryType::RAM);

        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 1, 0xA000, 0x2000, MemoryMapEntryType::RESERVED), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                       3);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                            0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                             0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                             MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,                                                            0xA000);
        TEST_ASSERT_EQUALS(table.entries[1].size,                                                             0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].type,                                                             MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[2].start,                                                            0x2000);
        TEST_ASSERT_EQUALS(table.entries[2].size,                                                             0x1000);
        TEST_ASSERT_EQUALS(table.entries[2].type,                                                             MemoryMapEntryType::RAM);

        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 3, 0xD000, 0x5000, MemoryMapEntryType::UNUSABLE), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                       4);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                            0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                             0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                             MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,                                                            0xA000);
        TEST_ASSERT_EQUALS(table.entries[1].size,                                                             0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].type,                                                             MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[2].start,                                                            0x2000);
        TEST_ASSERT_EQUALS(table.entries[2].size,                                                             0x1000);
        TEST_ASSERT_EQUALS(table.entries[2].type,                                                             MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start,                                                            0xD000);
        TEST_ASSERT_EQUALS(table.entries[3].size,                                                             0x5000);
        TEST_ASSERT_EQUALS(table.entries[3].type,                                                             MemoryMapEntryType::UNUSABLE);

        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 2, 0x9000, 0x1000, MemoryMapEntryType::ACPI), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                   5);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                        0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                         0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                         MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,                                                        0xA000);
        TEST_ASSERT_EQUALS(table.entries[1].size,                                                         0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].type,                                                         MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[2].start,                                                        0x9000);
        TEST_ASSERT_EQUALS(table.entries[2].size,                                                         0x1000);
        TEST_ASSERT_EQUALS(table.entries[2].type,                                                         MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[3].start,                                                        0x2000);
        TEST_ASSERT_EQUALS(table.entries[3].size,                                                         0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,                                                         MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[4].start,                                                        0xD000);
        TEST_ASSERT_EQUALS(table.entries[4].size,                                                         0x5000);
        TEST_ASSERT_EQUALS(table.entries[4].type,                                                         MemoryMapEntryType::UNUSABLE);
    }
    TEST_CASE_END();



    TEST_CASE("removeRangeInTable()");
    {
        E820Table table;

        table.count            = 10;
        table.entries[0].start = 0x5000;
        table.entries[0].size  = 0x4000;
        table.entries[0].type  = MemoryMapEntryType::NVS;
        table.entries[1].start = 0xA000;
        table.entries[1].size  = 0x2000;
        table.entries[1].type  = MemoryMapEntryType::RESERVED;
        table.entries[2].start = 0x9000;
        table.entries[2].size  = 0x1000;
        table.entries[2].type  = MemoryMapEntryType::ACPI;
        table.entries[3].start = 0x2000;
        table.entries[3].size  = 0x1000;
        table.entries[3].type  = MemoryMapEntryType::RAM;
        table.entries[4].start = 0xD000;
        table.entries[4].size  = 0x5000;
        table.entries[4].type  = MemoryMapEntryType::UNUSABLE;
        table.entries[5].start = 0x1000;
        table.entries[5].size  = 0x1000;
        table.entries[5].type  = MemoryMapEntryType::RAM;
        table.entries[6].start = 0x2000;
        table.entries[6].size  = 0x2000;
        table.entries[6].type  = MemoryMapEntryType::PERSISTENT_MEMORY;
        table.entries[7].start = 0x3000;
        table.entries[7].size  = 0x3000;
        table.entries[7].type  = MemoryMapEntryType::RESERVED_BY_KERNEL;
        table.entries[8].start = 0x4000;
        table.entries[8].size  = 0x4000;
        table.entries[8].type  = MemoryMapEntryType::NVS;
        table.entries[9].start = 0x5000;
        table.entries[9].size  = 0x5000;
        table.entries[9].type  = MemoryMapEntryType::ACPI;



        TEST_ASSERT_EQUALS(E820::removeRangeInTable(&table, 3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                         9);
        TEST_ASSERT_EQUALS(table.entries[0].start,              0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,               0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,               MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,              0xA000);
        TEST_ASSERT_EQUALS(table.entries[1].size,               0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].type,               MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[2].start,              0x9000);
        TEST_ASSERT_EQUALS(table.entries[2].size,               0x1000);
        TEST_ASSERT_EQUALS(table.entries[2].type,               MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[3].start,              0xD000);
        TEST_ASSERT_EQUALS(table.entries[3].size,               0x5000);
        TEST_ASSERT_EQUALS(table.entries[3].type,               MemoryMapEntryType::UNUSABLE);
        TEST_ASSERT_EQUALS(table.entries[4].start,              0x1000);
        TEST_ASSERT_EQUALS(table.entries[4].size,               0x1000);
        TEST_ASSERT_EQUALS(table.entries[4].type,               MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start,              0x2000);
        TEST_ASSERT_EQUALS(table.entries[5].size,               0x2000);
        TEST_ASSERT_EQUALS(table.entries[5].type,               MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[6].start,              0x3000);
        TEST_ASSERT_EQUALS(table.entries[6].size,               0x3000);
        TEST_ASSERT_EQUALS(table.entries[6].type,               MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[7].start,              0x4000);
        TEST_ASSERT_EQUALS(table.entries[7].size,               0x4000);
        TEST_ASSERT_EQUALS(table.entries[7].type,               MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[8].start,              0x5000);
        TEST_ASSERT_EQUALS(table.entries[8].size,               0x5000);
        TEST_ASSERT_EQUALS(table.entries[8].type,               MemoryMapEntryType::ACPI);

        TEST_ASSERT_EQUALS(E820::removeRangeInTable(&table, 7), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                         8);
        TEST_ASSERT_EQUALS(table.entries[0].start,              0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,               0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,               MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,              0xA000);
        TEST_ASSERT_EQUALS(table.entries[1].size,               0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].type,               MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[2].start,              0x9000);
        TEST_ASSERT_EQUALS(table.entries[2].size,               0x1000);
        TEST_ASSERT_EQUALS(table.entries[2].type,               MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[3].start,              0xD000);
        TEST_ASSERT_EQUALS(table.entries[3].size,               0x5000);
        TEST_ASSERT_EQUALS(table.entries[3].type,               MemoryMapEntryType::UNUSABLE);
        TEST_ASSERT_EQUALS(table.entries[4].start,              0x1000);
        TEST_ASSERT_EQUALS(table.entries[4].size,               0x1000);
        TEST_ASSERT_EQUALS(table.entries[4].type,               MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start,              0x2000);
        TEST_ASSERT_EQUALS(table.entries[5].size,               0x2000);
        TEST_ASSERT_EQUALS(table.entries[5].type,               MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[6].start,              0x3000);
        TEST_ASSERT_EQUALS(table.entries[6].size,               0x3000);
        TEST_ASSERT_EQUALS(table.entries[6].type,               MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[7].start,              0x5000);
        TEST_ASSERT_EQUALS(table.entries[7].size,               0x5000);
        TEST_ASSERT_EQUALS(table.entries[7].type,               MemoryMapEntryType::ACPI);

        TEST_ASSERT_EQUALS(E820::removeRangeInTable(&table, 0), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                         7);
        TEST_ASSERT_EQUALS(table.entries[0].start,              0xA000);
        TEST_ASSERT_EQUALS(table.entries[0].size,               0x2000);
        TEST_ASSERT_EQUALS(table.entries[0].type,               MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[1].start,              0x9000);
        TEST_ASSERT_EQUALS(table.entries[1].size,               0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,               MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[2].start,              0xD000);
        TEST_ASSERT_EQUALS(table.entries[2].size,               0x5000);
        TEST_ASSERT_EQUALS(table.entries[2].type,               MemoryMapEntryType::UNUSABLE);
        TEST_ASSERT_EQUALS(table.entries[3].start,              0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].size,               0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,               MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[4].start,              0x2000);
        TEST_ASSERT_EQUALS(table.entries[4].size,               0x2000);
        TEST_ASSERT_EQUALS(table.entries[4].type,               MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[5].start,              0x3000);
        TEST_ASSERT_EQUALS(table.entries[5].size,               0x3000);
        TEST_ASSERT_EQUALS(table.entries[5].type,               MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[6].start,              0x5000);
        TEST_ASSERT_EQUALS(table.entries[6].size,               0x5000);
        TEST_ASSERT_EQUALS(table.entries[6].type,               MemoryMapEntryType::ACPI);
    }
    TEST_CASE_END();



    TEST_CASE("updateRangeInTable()");
    {
        E820Table table;

        table.count            = 2;
        table.entries[0].start = 0x01000000;
        table.entries[0].size  = 0x00500000;
        table.entries[0].type  = MemoryMapEntryType::RAM;
        table.entries[1].start = 0x02000000;
        table.entries[1].size  = 0x00500000;
        table.entries[1].type  = MemoryMapEntryType::PERSISTENT_MEMORY;



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01010000, 0x1000, MemoryMapEntryType::RAM, MemoryMapEntryType::RESERVED_BY_KERNEL), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            4);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x004EF000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::PERSISTENT_MEMORY);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01020000, 0x1000, MemoryMapEntryType::RAM, MemoryMapEntryType::RESERVED_BY_KERNEL), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            6);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::PERSISTENT_MEMORY);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x0101F000, 0xA000, MemoryMapEntryType::RESERVED_BY_KERNEL, MemoryMapEntryType::ACPI), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            6);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::PERSISTENT_MEMORY);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x00000000, 0x1000, MemoryMapEntryType::RAM, MemoryMapEntryType::UNUSABLE), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            6);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::PERSISTENT_MEMORY);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01500000, 0x1000, MemoryMapEntryType::RAM, MemoryMapEntryType::UNUSABLE), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            6);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::PERSISTENT_MEMORY);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01FFF000, 0x1000, MemoryMapEntryType::PERSISTENT_MEMORY, MemoryMapEntryType::UNUSABLE), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            6);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::PERSISTENT_MEMORY);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x02500000, 0x1000, MemoryMapEntryType::PERSISTENT_MEMORY, MemoryMapEntryType::UNUSABLE), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            6);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::PERSISTENT_MEMORY);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0, 0x02000000, MemoryMapEntryType::NVS, MemoryMapEntryType::UNUSABLE), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            6);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::PERSISTENT_MEMORY);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01FFF000, 0x2000, MemoryMapEntryType::PERSISTENT_MEMORY, MemoryMapEntryType::ACPI), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            7);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00001000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[6].start, 0x02001000);
        TEST_ASSERT_EQUALS(table.entries[6].size,  0x004FF000);
        TEST_ASSERT_EQUALS(table.entries[6].type,  MemoryMapEntryType::PERSISTENT_MEMORY);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x024FF000, 0x2000, MemoryMapEntryType::PERSISTENT_MEMORY, MemoryMapEntryType::ACPI), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            8);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00001000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[6].start, 0x02001000);
        TEST_ASSERT_EQUALS(table.entries[6].size,  0x004FE000);
        TEST_ASSERT_EQUALS(table.entries[6].type,  MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[7].start, 0x024FF000);
        TEST_ASSERT_EQUALS(table.entries[7].size,  0x00001000);
        TEST_ASSERT_EQUALS(table.entries[7].type,  MemoryMapEntryType::ACPI);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x02010000, 0x2000, MemoryMapEntryType::PERSISTENT_MEMORY, MemoryMapEntryType::ACPI), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            10);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00001000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[6].start, 0x02001000);
        TEST_ASSERT_EQUALS(table.entries[6].size,  0xF000);
        TEST_ASSERT_EQUALS(table.entries[6].type,  MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[7].start, 0x02010000);
        TEST_ASSERT_EQUALS(table.entries[7].size,  0x2000);
        TEST_ASSERT_EQUALS(table.entries[7].type,  MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[8].start, 0x02012000);
        TEST_ASSERT_EQUALS(table.entries[8].size,  0x004ED000);
        TEST_ASSERT_EQUALS(table.entries[8].type,  MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[9].start, 0x024FF000);
        TEST_ASSERT_EQUALS(table.entries[9].size,  0x00001000);
        TEST_ASSERT_EQUALS(table.entries[9].type,  MemoryMapEntryType::ACPI);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01010500, 0x03000000, MemoryMapEntryType::ACPI, MemoryMapEntryType::RESERVED), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            10);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x0000F000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x01020000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x01021000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0x004DF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x00001000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[6].start, 0x02001000);
        TEST_ASSERT_EQUALS(table.entries[6].size,  0xF000);
        TEST_ASSERT_EQUALS(table.entries[6].type,  MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[7].start, 0x02010000);
        TEST_ASSERT_EQUALS(table.entries[7].size,  0x2000);
        TEST_ASSERT_EQUALS(table.entries[7].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[8].start, 0x02012000);
        TEST_ASSERT_EQUALS(table.entries[8].size,  0x004ED000);
        TEST_ASSERT_EQUALS(table.entries[8].type,  MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[9].start, 0x024FF000);
        TEST_ASSERT_EQUALS(table.entries[9].size,  0x00001000);
        TEST_ASSERT_EQUALS(table.entries[9].type,  MemoryMapEntryType::RESERVED);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01000000, 0x03000000, MemoryMapEntryType::RAM, MemoryMapEntryType::RESERVED), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            8);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x004EF000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x00001000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[4].start, 0x02001000);
        TEST_ASSERT_EQUALS(table.entries[4].size,  0xF000);
        TEST_ASSERT_EQUALS(table.entries[4].type,  MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[5].start, 0x02010000);
        TEST_ASSERT_EQUALS(table.entries[5].size,  0x2000);
        TEST_ASSERT_EQUALS(table.entries[5].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[6].start, 0x02012000);
        TEST_ASSERT_EQUALS(table.entries[6].size,  0x004ED000);
        TEST_ASSERT_EQUALS(table.entries[6].type,  MemoryMapEntryType::PERSISTENT_MEMORY);
        TEST_ASSERT_EQUALS(table.entries[7].start, 0x024FF000);
        TEST_ASSERT_EQUALS(table.entries[7].size,  0x00001000);
        TEST_ASSERT_EQUALS(table.entries[7].type,  MemoryMapEntryType::RESERVED);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01000000, 0x03000000, MemoryMapEntryType::PERSISTENT_MEMORY, MemoryMapEntryType::RESERVED), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            4);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00010000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x01010000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED_BY_KERNEL);
        TEST_ASSERT_EQUALS(table.entries[2].start, 0x01011000);
        TEST_ASSERT_EQUALS(table.entries[2].size,  0x004EF000);
        TEST_ASSERT_EQUALS(table.entries[2].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[3].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[3].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[3].type,  MemoryMapEntryType::RESERVED);



        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01000000, 0x03000000, MemoryMapEntryType::RESERVED_BY_KERNEL, MemoryMapEntryType::RESERVED), NgosStatus::OK);

        TEST_ASSERT_EQUALS(table.count,            2);
        TEST_ASSERT_EQUALS(table.entries[0].start, 0x01000000);
        TEST_ASSERT_EQUALS(table.entries[0].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[0].type,  MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[1].start, 0x02000000);
        TEST_ASSERT_EQUALS(table.entries[1].size,  0x00500000);
        TEST_ASSERT_EQUALS(table.entries[1].type,  MemoryMapEntryType::RESERVED);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_E820_E820_H
