#ifndef COM_NGOS_CONFIGURE_OTHER_KERNELDESCRIPTOR_H
#define COM_NGOS_CONFIGURE_OTHER_KERNELDESCRIPTOR_H



#include <com/ngos/shared/common/ngos/types.h>



struct KernelDescriptor
{
    i64 imageSize;      // Decompressed kernel image size
    i64 contentSize;    // Compressed kernel image size. It is equals to decompressed image size if there is no any compression
    u8  content[0];     // [De]compressed kernel image. It is decompressed image if there is no any compression
};



#endif // COM_NGOS_CONFIGURE_OTHER_KERNELDESCRIPTOR_H
