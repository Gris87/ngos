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

    UefiStatus (UEFI_API *setVirtualAddressMap)(u64 memoryMapSize, u64 descriptorSize, u32 descriptorVersion, UefiMemoryDescriptor *virtualMap); // TEST: NO
    UefiStatus (UEFI_API *convertPointer)(u64 debugDisposition, void **address); // TEST: NO

    UefiStatus (UEFI_API *getVariable)(const char16 *variableName, Guid *vendorGuid, UefiVariableAttributeFlags *attributes, u64 *dataSize, u8 *data); // TEST: NO
    UefiStatus (UEFI_API *getNextVariableName)(u64 *variableNameSize, const char16 *variableName, Guid *vendorGuid); // TEST: NO
    UefiStatus (UEFI_API *setVariable)(const char16 *variableName, Guid *vendorGuid, uefi_variable_attribute_flags attributes, u64 dataSize, u8 *data); // TEST: NO

    UefiStatus (UEFI_API *getNextHighMonotonicCount)(u32 *highCount); // TEST: NO
    UefiStatus (UEFI_API *resetSystem)(UefiResetType resetType, UefiStatus resetStatus, u64 dataSize, char16 *resetData); // TEST: NO

    UefiStatus (UEFI_API *updateCapsule)(UefiCapsuleHeader **capsuleHeaderArray, u64 capsuleCount, u64 scatterGatherList); // TEST: NO
    UefiStatus (UEFI_API *queryCapsuleCapabilities)(UefiCapsuleHeader **capsuleHeaderArray, u64 capsuleCount, u64 *maximumCapsuleSize, UefiResetType *resetType); // TEST: NO
    UefiStatus (UEFI_API *queryVariableInfo)(uefi_variable_attribute_flags attributes, u64 *maximumVariableStorageSize, u64 *remainingVariableStorageSize, u64 *maximumVariableSize); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIRUNTIMESERVICES_H
