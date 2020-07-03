#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_UEFI_UEFI_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_UEFI_UEFI_H



#include <com/ngos/shared/common/bootparams/uefimemorymapinfo.h>
#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/config/uefiacpi20configurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefiacpiconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefidebuginfoconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefidxeservicesconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefihcdpconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefihoblistconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefilzmadecompressconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefimemoryattributesconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefimemorystatuscoderecordconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefimemorytypeinformationconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefimpsconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefipropertiesconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefisalsystemconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefismbios3configurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefismbiosconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefisystemresourceconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefiugaioconfigurationtable.h>
#include <com/ngos/shared/common/uefi/uefisystemtable.h>



class UEFI
{
public:
    static NgosStatus initMemoryMap(); // TEST: NO
    static NgosStatus initSystemTable(); // TEST: NO

    static UefiSmbios3ConfigurationTable* getSmbios3Config(); // TEST: NO
    static UefiSmbiosConfigurationTable* getSmbiosConfig(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initConfigurationTables(); // TEST: NO
    static NgosStatus initMemoryAttributes(); // TEST: NO

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



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_UEFI_UEFI_H
