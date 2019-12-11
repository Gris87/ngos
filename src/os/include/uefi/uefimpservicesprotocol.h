#ifndef UEFI_UEFIMPSERVICESPROTOCOL_H
#define UEFI_UEFIMPSERVICESPROTOCOL_H



#include <uefi/macros.h>
#include <uefi/types.h>
#include <uefi/uefiprocessorinformation.h>
#include <uefi/uefistatus.h>



#define UEFI_MP_SERVICES_PROTOCOL_GUID \
    { 0x3FDDA605, 0xA76E, 0x4F46, {0xAD, 0x29, 0x12, 0xF4, 0x53, 0x1B, 0x3D, 0x08} }



typedef void (UEFI_API *uefi_ap_procedure) (void *buffer);



struct UefiMpServicesProtocol
{
    UefiStatus (UEFI_API *getNumberOfProcessors)(UefiMpServicesProtocol *obj, u64 *numberOfProcessors, u64 *numberOfEnabledProcessors); // TEST: NO
    UefiStatus (UEFI_API *getProcessorInfo)(UefiMpServicesProtocol *obj, u64 processorNumber, UefiProcessorInformation *processorInfoBuffer); // TEST: NO
    UefiStatus (UEFI_API *startupAllAPs)(UefiMpServicesProtocol *obj, uefi_ap_procedure procedure, bool singleThread, uefi_event waitEvent, u64 timeoutInMicroSeconds, void *procedureArgument, u64 **failedCpuList); // TEST: NO
    UefiStatus (UEFI_API *startupThisAP)(UefiMpServicesProtocol *obj, uefi_ap_procedure procedure, u64 processorNumber, uefi_event waitEvent, u64 timeoutInMicroSeconds, void *procedureArgument, bool *finished); // TEST: NO
    UefiStatus (UEFI_API *switchBSP)(UefiMpServicesProtocol *obj, u64 processorNumber, bool enableOldBSP); // TEST: NO
    UefiStatus (UEFI_API *enableDisableAP)(UefiMpServicesProtocol *obj, u64 processorNumber, bool enableAP, UefiProcessorInformationStatusFlags *health); // TEST: NO
    UefiStatus (UEFI_API *whoAmI)(UefiMpServicesProtocol *obj, u64 *processorNumber); // TEST: NO
};



#endif // UEFI_UEFIMPSERVICESPROTOCOL_H
