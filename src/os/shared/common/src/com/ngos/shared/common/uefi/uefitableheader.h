#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFITABLEHEADER_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFITABLEHEADER_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiTableHeader
{
    bad_uint64 signature;
    bad_uint32 revision;
    bad_uint32 headerSize;
    bad_uint32 crc32;
    bad_uint32 __reserved;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFITABLEHEADER_H
