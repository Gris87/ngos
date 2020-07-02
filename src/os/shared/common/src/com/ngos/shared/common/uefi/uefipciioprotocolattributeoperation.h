#ifndef UEFI_UEFIPCIIOPROTOCOLATTRIBUTEOPERATION_H
#define UEFI_UEFIPCIIOPROTOCOLATTRIBUTEOPERATION_H



#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class UefiPciIoProtocolAttributeOperation: u32
{
    GET,
    SET,
    ENABLE,
    DISABLE,
    SUPPORTED,
    MAXIMUM
};



inline const char8* enumToString(UefiPciIoProtocolAttributeOperation operation) // TEST: NO
{
    switch (operation)
    {
        case UefiPciIoProtocolAttributeOperation::GET:       return "GET";
        case UefiPciIoProtocolAttributeOperation::SET:       return "SET";
        case UefiPciIoProtocolAttributeOperation::ENABLE:    return "ENABLE";
        case UefiPciIoProtocolAttributeOperation::DISABLE:   return "DISABLE";
        case UefiPciIoProtocolAttributeOperation::SUPPORTED: return "SUPPORTED";
        case UefiPciIoProtocolAttributeOperation::MAXIMUM:   return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiPciIoProtocolAttributeOperation operation) // TEST: NO
{
    static char8 res[23];

    sprintf(res, "0x%08X (%s)", operation, enumToString(operation));

    return res;
}



#endif // UEFI_UEFIPCIIOPROTOCOLATTRIBUTEOPERATION_H
