#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLATTRIBUTEOPERATION_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLATTRIBUTEOPERATION_H



#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



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
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



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
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%08X (%s)", operation, enumToString(operation));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLATTRIBUTEOPERATION_H
