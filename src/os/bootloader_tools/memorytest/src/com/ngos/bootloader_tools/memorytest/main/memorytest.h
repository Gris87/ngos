#ifndef COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_MAIN_MEMORYTEST_H
#define COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_MAIN_MEMORYTEST_H



#include <com/ngos/shared/common/ngos/status.h>



class MemoryTest
{
public:
    static NgosStatus init(); // TEST: NO

    static bad_uint64 getCpuSpeed(); // TEST: NO

private:
    static NgosStatus initCpuSpeed(); // TEST: NO

    static bad_uint64 sCpuSpeed;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_MAIN_MEMORYTEST_H
