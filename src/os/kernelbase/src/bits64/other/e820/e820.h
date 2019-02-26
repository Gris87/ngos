#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_E820_E820_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_E820_E820_H



#include <buildconfig.h>
#include <ngos/status.h>
#include <src/bits64/other/e820/e820table.h>



class E820
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus updateRange(u64 start, u64 size, MemoryMapEntryType oldType, MemoryMapEntryType newType); // TEST: NO
    static NgosStatus updateRangeKExec(u64 start, u64 size, MemoryMapEntryType oldType, MemoryMapEntryType newType); // TEST: NO

    static const char* getTypeName(MemoryMapEntryType type); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus updateRangeInTable(E820Table *table, u64 start, u64 size, MemoryMapEntryType oldType, MemoryMapEntryType newType); // TEST: NO

    static E820Table sTable;
    static E820Table sTableKExec;
    static E820Table sTableFirmware;
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_E820_E820_H
