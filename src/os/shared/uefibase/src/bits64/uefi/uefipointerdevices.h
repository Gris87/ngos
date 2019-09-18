#ifndef OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFIPOINTERDEVICES_H
#define OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFIPOINTERDEVICES_H



#include <guid/guid.h>
#include <ngos/status.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefisimplepointerprotocol.h>



class UefiPointerDevices
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initAbsolutePointerDevices(); // TEST: NO
    static NgosStatus initAbsolutePointerDevices(Guid *protocol, u64 size); // TEST: NO
    static NgosStatus initAbsolutePointerDevices(Guid *protocol, u64 size, uefi_handle *pointersHandles); // TEST: NO
    static NgosStatus initSimplePointerDevices(); // TEST: NO
    static NgosStatus initSimplePointerDevices(Guid *protocol, u64 size); // TEST: NO
    static NgosStatus initSimplePointerDevices(Guid *protocol, u64 size, uefi_handle *pointersHandles); // TEST: NO

private:
    static UefiAbsolutePointerProtocol **sAbsolutePointers;
    static u8                            sAbsolutePointersCount;
    static UefiSimplePointerProtocol   **sSimplePointers;
    static u8                            sSimplePointersCount;
};



#endif // OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFIPOINTERDEVICES_H
