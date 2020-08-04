#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_IMAGESECTIONHEADER_H
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_IMAGESECTIONHEADER_H



#include <Qt>



#define IMAGE_SCN_TYPE_NO_PAD            0x00000008 // The section should not be padded to the next boundary. This flag is obsolete and is replaced by IMAGE_SCN_ALIGN_1BYTES
#define IMAGE_SCN_CNT_CODE               0x00000020 // The section contains executable code
#define IMAGE_SCN_CNT_INITIALIZED_DATA   0x00000040 // The section contains initialized data
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA 0x00000080 // The section contains uninitialized data
#define IMAGE_SCN_LNK_OTHER              0x00000100 // Reserved
#define IMAGE_SCN_LNK_INFO               0x00000200 // The section contains comments or other information. This is valid only for object files
#define IMAGE_SCN_LNK_REMOVE             0x00000800 // The section will not become part of the image. This is valid only for object files
#define IMAGE_SCN_LNK_COMDAT             0x00001000 // The section contains COMDAT data. This is valid only for object files
#define IMAGE_SCN_NO_DEFER_SPEC_EXC      0x00004000 // Reset speculative exceptions handling bits in the TLB entries for this section
#define IMAGE_SCN_GPREL                  0x00008000 // The section contains data referenced through the global pointer
#define IMAGE_SCN_MEM_PURGEABLE          0x00020000 // Reserved
#define IMAGE_SCN_MEM_LOCKED             0x00040000 // Reserved
#define IMAGE_SCN_MEM_PRELOAD            0x00080000 // Reserved
#define IMAGE_SCN_ALIGN_1BYTES           0x00100000 // Align data on a 1-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_2BYTES           0x00200000 // Align data on a 2-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_4BYTES           0x00300000 // Align data on a 4-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_8BYTES           0x00400000 // Align data on a 8-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_16BYTES          0x00500000 // Align data on a 16-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_32BYTES          0x00600000 // Align data on a 32-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_64BYTES          0x00700000 // Align data on a 64-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_128BYTES         0x00800000 // Align data on a 128-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_256BYTES         0x00900000 // Align data on a 256-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_512BYTES         0x00A00000 // Align data on a 512-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_1024BYTES        0x00B00000 // Align data on a 1024-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_2048BYTES        0x00C00000 // Align data on a 2048-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_4096BYTES        0x00D00000 // Align data on a 4096-byte boundary. This is valid only for object files
#define IMAGE_SCN_ALIGN_8192BYTES        0x00E00000 // Align data on a 8192-byte boundary. This is valid only for object files
#define IMAGE_SCN_LNK_NRELOC_OVFL        0x01000000 // The section contains extended relocations. The count of relocations for the section exceeds the 16 bits that is reserved for it in the section header. If the numberOfRelocations field in the section header is 0xFFFF, the actual relocation count is stored in the virtualAddress field of the first relocation. It is an error if IMAGE_SCN_LNK_NRELOC_OVFL is set and there are fewer than 0xFFFF relocations in the section
#define IMAGE_SCN_MEM_DISCARDABLE        0x02000000 // The section can be discarded as needed
#define IMAGE_SCN_MEM_NOT_CACHED         0x04000000 // The section cannot be cached
#define IMAGE_SCN_MEM_NOT_PAGED          0x08000000 // The section cannot be paged
#define IMAGE_SCN_MEM_SHARED             0x10000000 // The section can be shared in memory
#define IMAGE_SCN_MEM_EXECUTE            0x20000000 // The section can be executed as code
#define IMAGE_SCN_MEM_READ               0x40000000 // The section can be read
#define IMAGE_SCN_MEM_WRITE              0x80000000 // The section can be written to



struct ImageSectionHeader
{
    char name[8];
    union
    {
        quint32 physicalAddress;
        quint32 virtualSize;
    } misc;
    quint32 virtualAddress;
    quint32 sizeOfRawData;
    quint32 pointerToRawData;
    quint32 pointerToRelocations;
    quint32 pointerToLinenumbers;
    quint16 numberOfRelocations;
    quint16 numberOfLineNumbers;
    quint32 characteristics;

    void print(); // TEST: NO
    bool verify(); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_IMAGESECTIONHEADER_H
