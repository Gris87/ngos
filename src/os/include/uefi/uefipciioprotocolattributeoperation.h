#ifndef UEFI_UEFIPCIIOPROTOCOLATTRIBUTEOPERATION_H
#define UEFI_UEFIPCIIOPROTOCOLATTRIBUTEOPERATION_H



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



#endif // UEFI_UEFIPCIIOPROTOCOLATTRIBUTEOPERATION_H
