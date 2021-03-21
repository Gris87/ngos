#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_PEHEADER_H
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_PEHEADER_H



#include <Qt>

#include <com/ngos/devtools/image_builder/pe/coffheader.h>
#include <com/ngos/devtools/image_builder/pe/imagesectionheader.h>
#include <com/ngos/devtools/image_builder/pe/peoptheader.h>



#define PE_HEADER_SIGNATURE 0x00004550 // PE\nullptr\nullptr

#define SECTION_RELOC  0
#define SECTION_CONFIG 1
#define SECTION_KERNEL 2



struct PEHeader
{
    quint32            signature;
    COFFHeader         coffHeader;
    PEOptHeader        optHeader;
    ImageSectionHeader sections[NUMBER_OF_SECTIONS];

    void print(); // TEST: NO
    bool verify(); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_PEHEADER_H
