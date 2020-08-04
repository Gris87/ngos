#ifndef COM_NGOS_SHARED_UEFIBASE_UEFI_UEFILOGFILE_H
#define COM_NGOS_SHARED_UEFIBASE_UEFI_UEFILOGFILE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefifileprotocol.h>



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
    static NgosStatus initVolume(uefi_handle handle); // TEST: NO

    static bool              sIsAborted;
    static UefiFileProtocol *sLogFile;
};



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_UEFI_UEFILOGFILE_H
