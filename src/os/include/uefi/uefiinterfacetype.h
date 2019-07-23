#ifndef UEFI_UEFIINTERFACETYPE_H
#define UEFI_UEFIINTERFACETYPE_H



#include <ngos/types.h>



enum class UefiInterfaceType: u32
{
    NATIVE_INTERFACE = 0,
    PCODE_INTERFACE  = 1
};



inline const char* uefiInterfaceTypeToString(UefiInterfaceType type) // TEST: NO
{
    switch (type)
    {
        case UefiInterfaceType::NATIVE_INTERFACE: return "NATIVE_INTERFACE";
        case UefiInterfaceType::PCODE_INTERFACE:  return "PCODE_INTERFACE";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFIINTERFACETYPE_H
