#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H



#include <common/src/bits64/dmi/entry/lib/dmibiosextendedromsizeunit.h>
#include <common/src/bits64/log/log.h>



struct DmiBiosExtendedRomSize
{
    union
    {
        struct
        {
            u16 value: 14;
            u16 unit:  2;    // TODO: Use enum DmiBiosExtendedRomSizeUnit
        };

        u16 value16;
    };

    u64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        switch ((DmiBiosExtendedRomSizeUnit)unit)
        {
            case DmiBiosExtendedRomSizeUnit::MEGABYTES: return (u64)value << 20;
            case DmiBiosExtendedRomSizeUnit::GIGABYTES: return (u64)value << 30;

            default:
            {
                COMMON_LF(("Unknown BIOS extended rom size unit %s", enumToFullString((DmiBiosExtendedRomSizeUnit)unit)));

                return 0;
            }
            break;
        }



        return value;
    }
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
