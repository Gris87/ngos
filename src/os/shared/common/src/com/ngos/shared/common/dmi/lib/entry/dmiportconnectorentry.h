#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTCONNECTORENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTCONNECTORENTRY_H



#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiportconnectorporttype.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiportconnectortype.h>



struct DmiPortConnectorEntry
{
    DmiEntryHeader           header;
    DmiStringId              internalReferenceDesignator;
    DmiPortConnectorType     internalConnectorType;
    DmiStringId              externalReferenceDesignator;
    DmiPortConnectorType     externalConnectorType;
    DmiPortConnectorPortType portType;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTCONNECTORENTRY_H
