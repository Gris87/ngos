#ifndef UEFI_UEFIRUNTIMESERVICES_H
#define UEFI_UEFIRUNTIMESERVICES_H



#include <uefi/types.h>
#include <uefi/ueficapsuleheader.h>
#include <uefi/uefiguid.h>
#include <uefi/uefimemorydescriptor.h>
#include <uefi/uefiresettype.h>
#include <uefi/uefistatus.h>
#include <uefi/uefitableheader.h>
#include <uefi/uefitime.h>
#include <uefi/uefitimecapabilicies.h>



struct UefiRuntimeServices
{
    UefiTableHeader header;

    UefiStatus (UEFI_API *getTime)(UefiTime *time, UefiTimeCapabilities *capabilities); // TEST: NO
    UefiStatus (UEFI_API *setTime)(UefiTime *time); // TEST: NO
    UefiStatus (UEFI_API *getWakeupTime)(bool *enabled, bool *pending, UefiTime *time); // TEST: NO
    UefiStatus (UEFI_API *setWakeupTime)(bool enable, UefiTime *time); // TEST: NO

    UefiStatus (UEFI_API *setVirtualAddressMap)(u64 memoryMapSize, u64 descriptorSize, u32 descriptorVersion, UefiMemoryDescriptor *virtualMap); // TEST: NO
    UefiStatus (UEFI_API *convertPointer)(u64 debugDisposition, void **address); // TEST: NO

    UefiStatus (UEFI_API *getVariable)(uefi_char16 *variableName, UefiGuid *vendorGuid, u32 *attributes, u64 *dataSize, void *data); // TEST: NO
    UefiStatus (UEFI_API *getNextVariableName)(u64 *variableNameSize, uefi_char16 *variableName, UefiGuid *vendorGuid); // TEST: NO
    UefiStatus (UEFI_API *setVariable)(uefi_char16 *variableName, UefiGuid *vendorGuid, u32 attributes, u64 dataSize, void *data); // TEST: NO

    UefiStatus (UEFI_API *getNextHighMonotonicCount)(u32 *highCount); // TEST: NO
    UefiStatus (UEFI_API *resetSystem)(UefiResetType resetType, UefiStatus resetStatus, u64 dataSize, uefi_char16 *resetData); // TEST: NO

    UefiStatus (UEFI_API *updateCapsule)(UefiCapsuleHeader **capsuleHeaderArray, u64 capsuleCount, u64 scatterGatherList); // TEST: NO
    UefiStatus (UEFI_API *queryCapsuleCapabilities)(UefiCapsuleHeader **capsuleHeaderArray, u64 capsuleCount, u64 *maximumCapsuleSize, UefiResetType *resetType); // TEST: NO
    UefiStatus (UEFI_API *queryVariableInfo)(u32 attributes, u64 *maximumVariableStorageSize, u64 *remainingVariableStorageSize, u64 *maximumVariableSize); // TEST: NO
};



#endif // UEFI_UEFIRUNTIMESERVICES_H
