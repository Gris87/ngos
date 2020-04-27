#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H



#include <common/src/bits64/dmi/entry/lib/dmibiosextendedromsizeunit.h>
#include <common/src/bits64/log/log.h>
#include <macro/constants.h>



struct DmiBiosExtendedRomSize
{
    u64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        switch ((DmiBiosExtendedRomSizeUnit)unit)
        {
            case DmiBiosExtendedRomSizeUnit::MEGABYTES: return (u64)value * MB;
            case DmiBiosExtendedRomSizeUnit::GIGABYTES: return (u64)value * GB;

            default:
            {
                COMMON_LF(("Unknown BIOS extended rom size unit %s, %s:%u", enumToFullString((DmiBiosExtendedRomSizeUnit)unit), __FILE__, __LINE__));

                return 0;
            }
            break;
        }



        return value;
    }



    union
    {
        struct
        {
            u16 value: 14;
            u16 unit:  2;    // TODO: Use enum DmiBiosExtendedRomSizeUnit
        };

        u16 value16;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
