#ifndef COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSRIA32BIOSSIGNID_H                                                                                                                                          // Colorize: green
#define COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSRIA32BIOSSIGNID_H                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct MsrIa32BiosSignId // TODO: Validate with spec_verifier // https://cdrdv2.intel.com/v1/dl/getContent/671098                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_U64 _reserved:         32;                                                                                                                                                              // Colorize: green
            good_U64 microcodeRevision: 32;                                                                                                                                                              // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        good_U64 value64;                                                                                                                                                                                // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSRIA32BIOSSIGNID_H                                                                                                                                        // Colorize: green