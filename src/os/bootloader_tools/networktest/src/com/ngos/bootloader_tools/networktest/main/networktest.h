#ifndef COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_MAIN_NETWORKTEST_H
#define COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_MAIN_NETWORKTEST_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/types.h>



class NetworkTest
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initSimpleNetworkProtocols(); // TEST: NO
    static NgosStatus initSimpleNetworkProtocols(Guid *protocol, bad_uint64 size); // TEST: NO
    static NgosStatus initSimpleNetworkProtocols(Guid *protocol, bad_uint64 size, uefi_handle *handles); // TEST: NO
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_MAIN_NETWORKTEST_H
