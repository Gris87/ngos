#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPAYLOADSIZE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPAYLOADSIZE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressPayloadSize: bad_uint8
{
    _128_BYTES  = 0,
    _256_BYTES  = 1,
    _512_BYTES  = 2,
    _1024_BYTES = 3,
    _2048_BYTES = 4,
    _4096_BYTES = 5
};



inline const char8* enumToString(PciExpressPayloadSize size) // TEST: NO
{
    // COMMON_LT((" | size = %u", size)); // Commented to avoid bad looking logs



    switch (size)
    {
        case PciExpressPayloadSize::_128_BYTES:  return "128_BYTES";
        case PciExpressPayloadSize::_256_BYTES:  return "256_BYTES";
        case PciExpressPayloadSize::_512_BYTES:  return "512_BYTES";
        case PciExpressPayloadSize::_1024_BYTES: return "1024_BYTES";
        case PciExpressPayloadSize::_2048_BYTES: return "2048_BYTES";
        case PciExpressPayloadSize::_4096_BYTES: return "4096_BYTES";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressPayloadSize size) // TEST: NO
{
    // COMMON_LT((" | size = %u", size)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", (bad_uint8)size, enumToString(size));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPAYLOADSIZE_H
