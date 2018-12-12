#ifndef OS_COMMON_SRC_BITS64_CPU_MSR_MSR_H
#define OS_COMMON_SRC_BITS64_CPU_MSR_MSR_H



#include <ngos/status.h>
#include <ngos/types.h>



class MSR
{
public:
    static NgosStatus setBit(u32 msr, u8 bit); // TEST: NO
    static NgosStatus clearBit(u32 msr, u8 bit); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus setMsrBit(u32 msr, u8 bit, bool enabled); // TEST: NO
};



#endif // OS_COMMON_SRC_BITS64_CPU_MSR_MSR_H
