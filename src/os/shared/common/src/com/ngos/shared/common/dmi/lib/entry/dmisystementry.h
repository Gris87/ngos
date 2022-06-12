#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMENTRY_H                                                                                                                                                // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMENTRY_H                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>                                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>                                                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystemwakeuptype.h>                                                                                                                                // Colorize: green
#include <com/ngos/shared/common/uuid/uuid.h>                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
// Verified with DmiSpecVerifier [BEGIN] // https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.4.0.pdf                                                                               // Colorize: green
struct DmiSystemEntry                                                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiEntryHeader header;                                                                                                                                                                  // Colorize: green
    DmiStringId    manufacturer; // Number of null-terminated string                                                                                                                                     // Colorize: green
    DmiStringId    productName;  // Number of null-terminated string                                                                                                                                     // Colorize: green
    DmiStringId    version;      // Number of null-terminated string                                                                                                                                     // Colorize: green
    DmiStringId    serialNumber; // Number of null-terminated string                                                                                                                                     // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiSystemEntryV21: public DmiSystemEntry                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Uuid                uuid;       // Universal unique ID number; see 7.2.1.                                                                                                                            // Colorize: green
    DmiSystemWakeUpType wakeUpType; // Identifies the event that caused the system to power up. See 7.2.2.                                                                                               // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiSystemEntryV24: public DmiSystemEntryV21                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiStringId skuNumber; // Number of null-terminated string This text string identifies a particular computer configuration for sale. It is sometimes also called a product ID or purchase order number. This number is frequently found in existing fields, but there is no standard format. Typically for a given system board from a given OEM, there are tens of unique processor, memory, hard drive, and optical drive configurations. // Colorize: green
    DmiStringId family;    // Number of null-terminated string This text string identifies the family to which a particular computer belongs. A family refers to a set of computers that are similar but not identical from a hardware or software point of view. Typically, a family is composed of different computer models, which have different configurations and pricing points. Computers in the same family often have similar branding and cosmetic features. // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
// Verified with DmiSpecVerifier [END] // https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.4.0.pdf                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMENTRY_H                                                                                                                                              // Colorize: green
