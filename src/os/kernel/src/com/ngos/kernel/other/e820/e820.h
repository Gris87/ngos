#ifndef COM_NGOS_KERNEL_OTHER_E820_E820_H
#define COM_NGOS_KERNEL_OTHER_E820_E820_H



#include <buildconfig.h>
#include <com/ngos/kernel/other/e820/e820table.h>
#include <com/ngos/shared/common/ngos/status.h>



class E820
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus updateRange(bad_uint64 start, bad_uint64 size, MemoryMapEntryType oldType, MemoryMapEntryType newType); // TEST: NO
    static NgosStatus updateRangeKExec(bad_uint64 start, bad_uint64 size, MemoryMapEntryType oldType, MemoryMapEntryType newType); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus insertRangeInTable(E820Table *table, bad_uint64 index, bad_uint64 start, bad_uint64 size, MemoryMapEntryType type);
    static NgosStatus removeRangeInTable(E820Table *table, bad_uint64 index);
    static NgosStatus updateRangeInTable(E820Table *table, bad_uint64 start, bad_uint64 size, MemoryMapEntryType oldType, MemoryMapEntryType newType);

    static E820Table sTable;
    static E820Table sTableKExec;
    static E820Table sTableFirmware;
};



#endif // COM_NGOS_KERNEL_OTHER_E820_E820_H
