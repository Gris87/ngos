#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMBOOTENTRY_H                                                                                                                                            // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMBOOTENTRY_H                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>                                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystembootstatus.h>                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiSystemBootEntry                                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiEntryHeader      header;                                                                                                                                                                          // Colorize: green
    u8                  __reserved[6];                                                                                                                                                                   // Colorize: green
    DmiSystemBootStatus bootStatus;                                                                                                                                                                      // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMBOOTENTRY_H                                                                                                                                          // Colorize: green