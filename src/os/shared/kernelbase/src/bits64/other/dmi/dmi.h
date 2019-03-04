#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMI_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMI_H



#include <ngos/status.h>
#include <uefi/config/uefismbios3configurationtable.h>
#include <uefi/config/uefismbiosconfigurationtable.h>



class DMI
{
public:
    static NgosStatus init(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initFromSmbios3(UefiSmbios3ConfigurationTable *smbios3);
    static NgosStatus initFromSmbios(UefiSmbiosConfigurationTable *smbios);

    static u8 checksum(u8 *address, u64 size, u8 checksumValue);
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMI_H
