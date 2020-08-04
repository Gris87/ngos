#ifndef COM_NGOS_SHARED_UEFIBASE_UEFI_UEFIPOINTERDEVICES_H
#define COM_NGOS_SHARED_UEFIBASE_UEFI_UEFIPOINTERDEVICES_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerprotocol.h>
#include <com/ngos/shared/common/uefi/uefisimplepointerprotocol.h>



class UefiPointerDevices
{
public:
    static NgosStatus init(); // TEST: NO
    static NgosStatus cleanUp(); // TEST: NO

    static u8 getAbsolutePointersCount(); // TEST: NO
    static UefiAbsolutePointerProtocol* getAbsolutePointer(u8 index); // TEST: NO
    static u8 getSimplePointersCount(); // TEST: NO
    static UefiSimplePointerProtocol* getSimplePointer(u8 index); // TEST: NO

private:
    static NgosStatus initAbsolutePointerDevices(); // TEST: NO
    static NgosStatus initAbsolutePointerDevices(Guid *protocol, u64 size); // TEST: NO
    static NgosStatus initAbsolutePointerDevices(Guid *protocol, u64 size, uefi_handle *pointersHandles); // TEST: NO
    static NgosStatus initSimplePointerDevices(); // TEST: NO
    static NgosStatus initSimplePointerDevices(Guid *protocol, u64 size); // TEST: NO
    static NgosStatus initSimplePointerDevices(Guid *protocol, u64 size, uefi_handle *pointersHandles); // TEST: NO

private:
    static u8                            sAbsolutePointersCount;
    static UefiAbsolutePointerProtocol **sAbsolutePointers;
    static u8                            sSimplePointersCount;
    static UefiSimplePointerProtocol   **sSimplePointers;
};



#endif // COM_NGOS_SHARED_UEFIBASE_UEFI_UEFIPOINTERDEVICES_H
