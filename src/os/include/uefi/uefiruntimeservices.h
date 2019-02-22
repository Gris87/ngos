#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIRUNTIMESERVICES_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIRUNTIMESERVICES_H



#include "src/bits64/a_uefi/uefi/lib/eficapsuleheader.h"
#include "src/bits64/a_uefi/uefi/lib/efiguid.h"
#include "src/bits64/a_uefi/uefi/lib/efimemorydescriptor.h"
#include "src/bits64/a_uefi/uefi/lib/efiresettype.h"
#include "src/bits64/a_uefi/uefi/lib/efitableheader.h"
#include "src/bits64/a_uefi/uefi/lib/efitime.h"
#include "src/bits64/a_uefi/uefi/lib/efitimecapabilicies.h"
#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



struct EfiRuntimeServices
{
    EfiTableHeader header;

    EfiStatus (EFIAPI *getTime)(EfiTime *time, EfiTimeCapabilities *capabilities); // TEST: NO
    EfiStatus (EFIAPI *setTime)(EfiTime *time); // TEST: NO
    EfiStatus (EFIAPI *getWakeupTime)(bool *enabled, bool *pending, EfiTime *time); // TEST: NO
    EfiStatus (EFIAPI *setWakeupTime)(bool enable, EfiTime *time); // TEST: NO

    EfiStatus (EFIAPI *setVirtualAddressMap)(u64 memoryMapSize, u64 descriptorSize, u32 descriptorVersion, EfiMemoryDescriptor *virtualMap); // TEST: NO
    EfiStatus (EFIAPI *convertPointer)(u64 debugDisposition, void **address); // TEST: NO

    EfiStatus (EFIAPI *getVariable)(efi_char16 *variableName, EfiGuid *vendorGuid, u32 *attributes, u64 *dataSize, void *data); // TEST: NO
    EfiStatus (EFIAPI *getNextVariableName)(u64 *variableNameSize, efi_char16 *variableName, EfiGuid *vendorGuid); // TEST: NO
    EfiStatus (EFIAPI *setVariable)(efi_char16 *variableName, EfiGuid *vendorGuid, u32 attributes, u64 dataSize, void *data); // TEST: NO

    EfiStatus (EFIAPI *getNextHighMonotonicCount)(u32 *highCount); // TEST: NO
    EfiStatus (EFIAPI *resetSystem)(EfiResetType resetType, EfiStatus resetStatus, u64 dataSize, efi_char16 *resetData); // TEST: NO

    EfiStatus (EFIAPI *updateCapsule)(EfiCapsuleHeader **capsuleHeaderArray, u64 capsuleCount, efi_physical_address scatterGatherList); // TEST: NO
    EfiStatus (EFIAPI *queryCapsuleCapabilities)(EfiCapsuleHeader **capsuleHeaderArray, u64 capsuleCount, u64 *maximumCapsuleSize, EfiResetType *resetType); // TEST: NO
    EfiStatus (EFIAPI *queryVariableInfo)(u32 attributes, u64 *maximumVariableStorageSize, u64 *remainingVariableStorageSize, u64 *maximumVariableSize); // TEST: NO
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIRUNTIMESERVICES_H
