#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPORTCONNECTORENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPORTCONNECTORENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmiportconnectorporttype.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmiportconnectortype.h>



struct DmiPortConnectorEntry
{
    DmiEntryHeader           header;
    DmiStringId              internalReferenceDesignator;
    DmiPortConnectorType     internalConnectorType;
    DmiStringId              externalReferenceDesignator;
    DmiPortConnectorType     externalConnectorType;
    DmiPortConnectorPortType portType;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPORTCONNECTORENTRY_H
