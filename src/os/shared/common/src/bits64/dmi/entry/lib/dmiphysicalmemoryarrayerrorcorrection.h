#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYERRORCORRECTION_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYERRORCORRECTION_H



#include <ngos/types.h>



enum class DmiPhysicalMemoryArrayErrorCorrection: u8
{
    NULL           = 0,
    OTHER          = 1,
    UNKNOWN        = 2,
    NONE           = 3,
    PARITY         = 4,
    SINGLE_BIT_ECC = 5,
    MULTI_BIT_ECC  = 6,
    CRC            = 7
};



inline const char8* dmiPhysicalMemoryArrayErrorCorrectionToString(DmiPhysicalMemoryArrayErrorCorrection correction) // TEST: NO
{
    // COMMON_LT((" | correction = %u", correction)); // Commented to avoid bad looking logs



    switch (correction)
    {
        case DmiPhysicalMemoryArrayErrorCorrection::NULL:           return "NULL";
        case DmiPhysicalMemoryArrayErrorCorrection::OTHER:          return "OTHER";
        case DmiPhysicalMemoryArrayErrorCorrection::UNKNOWN:        return "UNKNOWN";
        case DmiPhysicalMemoryArrayErrorCorrection::NONE:           return "NONE";
        case DmiPhysicalMemoryArrayErrorCorrection::PARITY:         return "PARITY";
        case DmiPhysicalMemoryArrayErrorCorrection::SINGLE_BIT_ECC: return "SINGLE_BIT_ECC";
        case DmiPhysicalMemoryArrayErrorCorrection::MULTI_BIT_ECC:  return "MULTI_BIT_ECC";
        case DmiPhysicalMemoryArrayErrorCorrection::CRC:            return "CRC";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYERRORCORRECTION_H