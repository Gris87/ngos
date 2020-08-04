#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H



#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/macro/constants.h>



struct DmiBiosRomSize
{
    u64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (value + 1) * 64 * KB;
    }



    u8 value;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H
