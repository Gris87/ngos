#ifndef OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFILOGFILE_H
#define OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFILOGFILE_H



#include <buildconfig.h>
#include <ngos/status.h>
#include <ngos/types.h>
#include <uefi/uefifileprotocol.h>



#if NGOS_BUILD_LOG_TO_UEFI_FILE == OPTION_YES



class UefiLogFile
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus print(char8 ch); // TEST: NO
    static NgosStatus print(const char8 *str); // TEST: NO
    static NgosStatus println(); // TEST: NO
    static NgosStatus println(char8 ch); // TEST: NO
    static NgosStatus println(const char8 *str); // TEST: NO

    static NgosStatus noMorePrint(); // TEST: NO
    static bool canPrint(); // TEST: NO

private:
    static NgosStatus initBlockIoProtocol(Guid *protocol, u64 size); // TEST: NO
    static NgosStatus initBlockIoProtocol(Guid *protocol, u64 size, uefi_handle *blockIoHandles); // TEST: NO

    static NgosStatus write(u8 *data, u64 size); // TEST: NO

    static bool              sIsAborted;
    static UefiFileProtocol *sLogFile;
};



#endif



#endif // OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFILOGFILE_H
