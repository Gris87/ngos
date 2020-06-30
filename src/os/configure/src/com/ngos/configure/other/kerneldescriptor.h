#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_OTHER_KERNELDESCRIPTOR_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_OTHER_KERNELDESCRIPTOR_H



#include <ngos/types.h>



struct KernelDescriptor
{
    u64 imageSize;      // Decompressed kernel image size
    u64 contentSize;    // Compressed kernel image size. It is equals to decompressed image size if there is no any compression
    u8  content[0];     // [De]compressed kernel image. It is decompressed image if there is no any compression
};



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_OTHER_KERNELDESCRIPTOR_H
