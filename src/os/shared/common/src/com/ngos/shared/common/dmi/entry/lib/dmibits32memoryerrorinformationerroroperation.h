#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS32MEMORYERRORINFORMATIONERROROPERATION_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS32MEMORYERRORINFORMATIONERROROPERATION_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiBits32MemoryErrorInformationErrorOperation: u8
{
    NONE          = 0,
    OTHER         = 1,
    UNKNOWN       = 2,
    READ          = 3,
    WRITE         = 4,
    PARTIAL_WRITE = 5
};



inline const char8* enumToString(DmiBits32MemoryErrorInformationErrorOperation operation) // TEST: NO
{
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



    switch (operation)
    {
        case DmiBits32MemoryErrorInformationErrorOperation::NONE:          return "NONE";
        case DmiBits32MemoryErrorInformationErrorOperation::OTHER:         return "OTHER";
        case DmiBits32MemoryErrorInformationErrorOperation::UNKNOWN:       return "UNKNOWN";
        case DmiBits32MemoryErrorInformationErrorOperation::READ:          return "READ";
        case DmiBits32MemoryErrorInformationErrorOperation::WRITE:         return "WRITE";
        case DmiBits32MemoryErrorInformationErrorOperation::PARTIAL_WRITE: return "PARTIAL_WRITE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiBits32MemoryErrorInformationErrorOperation operation) // TEST: NO
{
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%02X (%s)", operation, enumToString(operation));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS32MEMORYERRORINFORMATIONERROROPERATION_H
