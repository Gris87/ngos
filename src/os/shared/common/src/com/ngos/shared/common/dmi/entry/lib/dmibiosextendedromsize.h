#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H



#include <com/ngos/shared/common/dmi/entry/lib/dmibiosextendedromsizeunit.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/macro/constants.h>



struct DmiBiosExtendedRomSize
{
    bad_uint64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        switch ((DmiBiosExtendedRomSizeUnit)unit)
        {
            case DmiBiosExtendedRomSizeUnit::MEGABYTES: return (bad_uint64)value * MB;
            case DmiBiosExtendedRomSizeUnit::GIGABYTES: return (bad_uint64)value * GB;

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
            bad_uint16 value: 14;
            bad_uint16 unit:  2;    // TODO: Use enum DmiBiosExtendedRomSizeUnit
        };

        bad_uint16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
