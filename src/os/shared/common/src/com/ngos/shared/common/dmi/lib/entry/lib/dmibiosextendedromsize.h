#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibiosextendedromsizeunit.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/macro/constants.h>



struct DmiBiosExtendedRomSize
{
    good_U64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        switch (unit)
        {
            case DmiBiosExtendedRomSizeUnit::MEGABYTES: return static_cast<good_U64>(value) * MB;
            case DmiBiosExtendedRomSizeUnit::GIGABYTES: return static_cast<good_U64>(value) * GB;

            default:
            {
                COMMON_LF(("Unknown BIOS extended rom size unit %s, %s:%u", enumToFullString(unit), __FILE__, __LINE__));

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
            good_U16                   value: 14;
            DmiBiosExtendedRomSizeUnit unit:  2;
        };

        good_U16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
