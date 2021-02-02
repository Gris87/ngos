#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICETYPEDETAILFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICETYPEDETAILFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint16 dmi_memory_device_type_detail_flags;

enum class DmiMemoryDeviceTypeDetailFlag: dmi_memory_device_type_detail_flags
{
    NONE          = 0,
    OTHER         = (1ULL << 1),
    UNKNOWN       = (1ULL << 2),
    FAST_PAGED    = (1ULL << 3),
    STATIC_COLUMN = (1ULL << 4),
    PSEUDO_STATIC = (1ULL << 5),
    RAMBUS        = (1ULL << 6),
    SYNCHRONOUS   = (1ULL << 7),
    CMOS          = (1ULL << 8),
    EDO           = (1ULL << 9),
    WINDOW_DRAM   = (1ULL << 10),
    CACHE_DRAM    = (1ULL << 11),
    NON_VOLATILE  = (1ULL << 12),
    REGISTERED    = (1ULL << 13),
    UNBUFFERED    = (1ULL << 14),
    LRDIMM        = (1ULL << 15)
};

DEFINE_FLAGS(DmiMemoryDeviceTypeDetailFlags, dmi_memory_device_type_detail_flags); // TEST: NO



inline const char8* flagToString(DmiMemoryDeviceTypeDetailFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiMemoryDeviceTypeDetailFlag::NONE:          return "NONE";
        case DmiMemoryDeviceTypeDetailFlag::OTHER:         return "OTHER";
        case DmiMemoryDeviceTypeDetailFlag::UNKNOWN:       return "UNKNOWN";
        case DmiMemoryDeviceTypeDetailFlag::FAST_PAGED:    return "FAST_PAGED";
        case DmiMemoryDeviceTypeDetailFlag::STATIC_COLUMN: return "STATIC_COLUMN";
        case DmiMemoryDeviceTypeDetailFlag::PSEUDO_STATIC: return "PSEUDO_STATIC";
        case DmiMemoryDeviceTypeDetailFlag::RAMBUS:        return "RAMBUS";
        case DmiMemoryDeviceTypeDetailFlag::SYNCHRONOUS:   return "SYNCHRONOUS";
        case DmiMemoryDeviceTypeDetailFlag::CMOS:          return "CMOS";
        case DmiMemoryDeviceTypeDetailFlag::EDO:           return "EDO";
        case DmiMemoryDeviceTypeDetailFlag::WINDOW_DRAM:   return "WINDOW_DRAM";
        case DmiMemoryDeviceTypeDetailFlag::CACHE_DRAM:    return "CACHE_DRAM";
        case DmiMemoryDeviceTypeDetailFlag::NON_VOLATILE:  return "NON_VOLATILE";
        case DmiMemoryDeviceTypeDetailFlag::REGISTERED:    return "REGISTERED";
        case DmiMemoryDeviceTypeDetailFlag::UNBUFFERED:    return "UNBUFFERED";
        case DmiMemoryDeviceTypeDetailFlag::LRDIMM:        return "LRDIMM";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiMemoryDeviceTypeDetailFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (dmi_memory_device_type_detail_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiMemoryDeviceTypeDetailFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[189];

    FLAGS_TO_STRING(res, flags.flags, DmiMemoryDeviceTypeDetailFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiMemoryDeviceTypeDetailFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[198];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiMemoryDeviceTypeDetailFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICETYPEDETAILFLAGS_H
