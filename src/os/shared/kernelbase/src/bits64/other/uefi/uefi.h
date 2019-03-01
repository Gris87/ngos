#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_UEFI_UEFI_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_UEFI_UEFI_H



#include <bootparams/uefimemorymapinfo.h>
#include <buildconfig.h>
#include <ngos/status.h>
#include <uefi/config/uefiacpi20configurationtable.h>
#include <uefi/config/uefiacpiconfigurationtable.h>
#include <uefi/config/uefidebuginfoconfigurationtable.h>
#include <uefi/config/uefidxeservicesconfigurationtable.h>
#include <uefi/config/uefihcdpconfigurationtable.h>
#include <uefi/config/uefihoblistconfigurationtable.h>
#include <uefi/config/uefilzmadecompressconfigurationtable.h>
#include <uefi/config/uefimemoryattributesconfigurationtable.h>
#include <uefi/config/uefimemorystatuscoderecordconfigurationtable.h>
#include <uefi/config/uefimemorytypeinformationconfigurationtable.h>
#include <uefi/config/uefimpsconfigurationtable.h>
#include <uefi/config/uefipropertiesconfigurationtable.h>
#include <uefi/config/uefisalsystemconfigurationtable.h>
#include <uefi/config/uefismbios3configurationtable.h>
#include <uefi/config/uefismbiosconfigurationtable.h>
#include <uefi/config/uefisystemresourceconfigurationtable.h>
#include <uefi/config/uefiugaioconfigurationtable.h>
#include <uefi/uefisystemtable.h>



class UEFI
{
public:
    static NgosStatus initMemoryMap(); // TEST: NO
    static NgosStatus initSystemTable(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initConfigurationTables(); // TEST: NO
    static NgosStatus initMemoryAttributes(); // TEST: NO
    static bool isGuidEquals(const UefiGuid &guid1, const UefiGuid &guid2);

    static UefiMemoryMapInfo                             sMemoryMap;
    static UefiSystemTable                               sSystemTable;
    static UefiAcpi20ConfigurationTable                 *sAcpi20Config;
    static UefiAcpiConfigurationTable                   *sAcpiConfig;
    static UefiDebugInfoConfigurationTable              *sDebugInfoConfig;
    static UefiDxeServicesConfigurationTable            *sDxeServicesConfig;
    static UefiHcdpConfigurationTable                   *sHcdpConfig;
    static UefiHobListConfigurationTable                *sHobListConfig;
    static UefiLzmaDecompressConfigurationTable         *sLzmaDecompressConfig;
    static UefiMemoryAttributesConfigurationTable       *sMemoryAttributesConfig;
    static UefiMemoryStatusCodeRecordConfigurationTable *sMemoryStatusCodeRecordConfig;
    static UefiMemoryTypeInformationConfigurationTable  *sMemoryTypeInformationConfig;
    static UefiMpsConfigurationTable                    *sMpsConfig;
    static UefiPropertiesConfigurationTable             *sPropertiesConfig;
    static UefiSalSystemConfigurationTable              *sSalSystemConfig;
    static UefiSmbios3ConfigurationTable                *sSmbios3Config;
    static UefiSmbiosConfigurationTable                 *sSmbiosConfig;
    static UefiSystemResourceConfigurationTable         *sSystemResourceConfig;
    static UefiUgaIoConfigurationTable                  *sUgaIoConfig;
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_UEFI_UEFI_H
