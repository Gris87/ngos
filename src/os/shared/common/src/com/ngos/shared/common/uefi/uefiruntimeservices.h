#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIRUNTIMESERVICES_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIRUNTIMESERVICES_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/ueficapsuleheader.h>
#include <com/ngos/shared/common/uefi/uefimemorydescriptor.h>
#include <com/ngos/shared/common/uefi/uefiresettype.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>
#include <com/ngos/shared/common/uefi/uefitableheader.h>
#include <com/ngos/shared/common/uefi/uefitime.h>
#include <com/ngos/shared/common/uefi/uefitimecapabilicies.h>
#include <com/ngos/shared/common/uefi/uefivariableattributeflags.h>



struct UefiRuntimeServices
{
    UefiTableHeader header;

    UefiStatus (UEFI_API *getTime)(UefiTime *time, UefiTimeCapabilities *capabilities); // TEST: NO
    UefiStatus (UEFI_API *setTime)(UefiTime *time); // TEST: NO
    UefiStatus (UEFI_API *getWakeupTime)(bool *enabled, bool *pending, UefiTime *time); // TEST: NO
    UefiStatus (UEFI_API *setWakeupTime)(bool enable, UefiTime *time); // TEST: NO

    UefiStatus (UEFI_API *setVirtualAddressMap)(bad_uint64 memoryMapSize, bad_uint64 descriptorSize, bad_uint32 descriptorVersion, UefiMemoryDescriptor *virtualMap); // TEST: NO
    UefiStatus (UEFI_API *convertPointer)(bad_uint64 debugDisposition, void **address); // TEST: NO

    UefiStatus (UEFI_API *getVariable)(const char16 *variableName, Guid *vendorGuid, UefiVariableAttributeFlags *attributes, bad_uint64 *dataSize, bad_uint8 *data); // TEST: NO
    UefiStatus (UEFI_API *getNextVariableName)(bad_uint64 *variableNameSize, const char16 *variableName, Guid *vendorGuid); // TEST: NO
    UefiStatus (UEFI_API *setVariable)(const char16 *variableName, Guid *vendorGuid, uefi_variable_attribute_flags attributes, bad_uint64 dataSize, bad_uint8 *data); // TEST: NO

    UefiStatus (UEFI_API *getNextHighMonotonicCount)(bad_uint32 *highCount); // TEST: NO
    UefiStatus (UEFI_API *resetSystem)(UefiResetType resetType, UefiStatus resetStatus, bad_uint64 dataSize, char16 *resetData); // TEST: NO

    UefiStatus (UEFI_API *updateCapsule)(UefiCapsuleHeader **capsuleHeaderArray, bad_uint64 capsuleCount, bad_uint64 scatterGatherList); // TEST: NO
    UefiStatus (UEFI_API *queryCapsuleCapabilities)(UefiCapsuleHeader **capsuleHeaderArray, bad_uint64 capsuleCount, bad_uint64 *maximumCapsuleSize, UefiResetType *resetType); // TEST: NO
    UefiStatus (UEFI_API *queryVariableInfo)(uefi_variable_attribute_flags attributes, bad_uint64 *maximumVariableStorageSize, bad_uint64 *remainingVariableStorageSize, bad_uint64 *maximumVariableSize); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIRUNTIMESERVICES_H
