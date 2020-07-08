#ifndef NETWORKTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_MAIN_NETWORKTEST_H
#define NETWORKTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_MAIN_NETWORKTEST_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/types.h>



class NetworkTest
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initSimpleNetworkProtocols(); // TEST: NO
    static NgosStatus initSimpleNetworkProtocols(Guid *protocol, u64 size); // TEST: NO
    static NgosStatus initSimpleNetworkProtocols(Guid *protocol, u64 size, uefi_handle *handles); // TEST: NO
};



#endif // NETWORKTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_MAIN_NETWORKTEST_H
