#ifndef COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H                                                                                                                                                            // Colorize: green
#define COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/status.h>                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class Crc                                                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    static good_U32 crc32(const good_U8 *data, good_I64 length);                                                                                                                                               // Colorize: green
    static good_U64 crc64(const good_U8 *data, good_I64 length);                                                                                                                                               // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H                                                                                                                                                          // Colorize: green
