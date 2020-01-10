#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPORTCONNECTORENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPORTCONNECTORENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmiportconnectorporttype.h>
#include <common/src/bits64/dmi/entry/lib/dmiportconnectortype.h>



struct DmiPortConnectorEntry
{
    DmiEntryHeader           header;
    u8                       internalReferenceDesignatorStringId;
    DmiPortConnectorType     internalConnectorType;
    u8                       externalReferenceDesignatorStringId;
    DmiPortConnectorType     externalConnectorType;
    DmiPortConnectorPortType portType;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPORTCONNECTORENTRY_H
