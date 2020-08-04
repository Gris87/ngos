#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_DATADIRECTORY_H
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_DATADIRECTORY_H



#include <Qt>



struct DataDirectory
{
    quint32 virtualAddress;
    quint32 size;

    void print(); // TEST: NO
    bool verify(); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_PE_DATADIRECTORY_H
