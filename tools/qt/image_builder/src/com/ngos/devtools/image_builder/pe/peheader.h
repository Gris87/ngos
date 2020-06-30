#ifndef IMAGE_BUILDER_SRC_PE_PEHEADER_H
#define IMAGE_BUILDER_SRC_PE_PEHEADER_H



#include <Qt>

#include "src/pe/coffheader.h"
#include "src/pe/imagesectionheader.h"
#include "src/pe/peoptheader.h"



#define PE_HEADER_SIGNATURE 0x00004550 // PE\0\0

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



#endif // IMAGE_BUILDER_SRC_PE_PEHEADER_H
