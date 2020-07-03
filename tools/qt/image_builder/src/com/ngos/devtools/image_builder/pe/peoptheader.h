#ifndef IMAGE_BUILDER_SRC_COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_PEOPTHEADER_H
#define IMAGE_BUILDER_SRC_COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_PEOPTHEADER_H



#include <Qt>

#include "com/ngos/devtools/image_builder/pe/datadirectory.h"



#define NUMBER_OF_RVA_AND_SIZES 6

#define IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x010B // 32 bit executable image.
#define IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x020B // 64 bit executable image
#define IMAGE_ROM_OPTIONAL_HDR_MAGIC  0x0107 // ROM image

#define IMAGE_SUBSYSTEM_UNKNOWN                  0  // Unknown subsystem
#define IMAGE_SUBSYSTEM_NATIVE                   1  // No subsystem required (device drivers and native system processes)
#define IMAGE_SUBSYSTEM_WINDOWS_GUI              2  // Windows graphical user interface (GUI) subsystem
#define IMAGE_SUBSYSTEM_WINDOWS_CUI              3  // Windows character-mode user interface (CUI) subsystem
#define IMAGE_SUBSYSTEM_OS2_CUI                  5  // OS/2 CUI subsystem
#define IMAGE_SUBSYSTEM_POSIX_CUI                7  // POSIX CUI subsystem
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI           9  // Windows CE system
#define IMAGE_SUBSYSTEM_UEFI_APPLICATION         10 // Unified Extensible Firmware Interface (UEFI) application
#define IMAGE_SUBSYSTEM_UEFI_BOOT_SERVICE_DRIVER 11 // UEFI driver with boot services
#define IMAGE_SUBSYSTEM_UEFI_RUNTIME_DRIVER      12 // UEFI driver with run-time services
#define IMAGE_SUBSYSTEM_UEFI_ROM                 13 // UEFI ROM image
#define IMAGE_SUBSYSTEM_XBOX                     14 // Xbox system
#define IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION 16 // Boot application



struct PEOptHeader
{
    quint16       signature;
    quint8        majorLinkerVersion;
    quint8        minorLinkerVersion;
    quint32       sizeOfCode;
    quint32       sizeOfInitializedData;
    quint32       sizeOfUninitializedData;
    quint32       addressOfEntryPoint;
    quint32       baseOfCode;
    quint64       imageBase;
    quint32       sectionAlignment;
    quint32       fileAlignment;
    quint16       majorOSVersion;
    quint16       minorOSVersion;
    quint16       majorImageVersion;
    quint16       minorImageVersion;
    quint16       majorSubsystemVersion;
    quint16       minorSubsystemVersion;
    quint32       win32VersionValue;
    quint32       sizeOfImage;
    quint32       sizeOfHeaders;
    quint32       checksum;
    quint16       subsystem;
    quint16       dllCharacteristics;
    quint64       sizeOfStackReserve;
    quint64       sizeOfStackCommit;
    quint64       sizeOfHeapReserve;
    quint64       sizeOfHeapCommit;
    quint32       loaderFlags;
    quint32       numberOfRvaAndSizes;
    DataDirectory dataDirectories[NUMBER_OF_RVA_AND_SIZES];

    void print(); // TEST: NO
    bool verify(); // TEST: NO
};



#endif // IMAGE_BUILDER_SRC_COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_PEOPTHEADER_H
