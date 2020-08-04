#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIINTERFACETYPE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIINTERFACETYPE_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class UefiInterfaceType: u32
{
    NATIVE_INTERFACE = 0,
    PCODE_INTERFACE  = 1
};



inline const char8* enumToString(UefiInterfaceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiInterfaceType::NATIVE_INTERFACE: return "NATIVE_INTERFACE";
        case UefiInterfaceType::PCODE_INTERFACE:  return "PCODE_INTERFACE";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiInterfaceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%08X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIINTERFACETYPE_H
