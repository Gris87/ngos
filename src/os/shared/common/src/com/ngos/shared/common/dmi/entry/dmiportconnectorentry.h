#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTCONNECTORENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTCONNECTORENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiportconnectorporttype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiportconnectortype.h>



struct DmiPortConnectorEntry
{
    DmiEntryHeader           header;
    DmiStringId              internalReferenceDesignator;
    DmiPortConnectorType     internalConnectorType;
    DmiStringId              externalReferenceDesignator;
    DmiPortConnectorType     externalConnectorType;
    DmiPortConnectorPortType portType;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTCONNECTORENTRY_H
