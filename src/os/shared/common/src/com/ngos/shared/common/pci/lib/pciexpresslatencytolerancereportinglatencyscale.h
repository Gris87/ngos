#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLATENCYTOLERANCEREPORTINGLATENCYSCALE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLATENCYTOLERANCEREPORTINGLATENCYSCALE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressLatencyToleranceReportingLatencyScale: bad_uint8
{
    _1_NS        = 0,
    _32_NS       = 1,
    _1024_NS     = 2,
    _32768_NS    = 3,
    _1048576_NS  = 4,
    _33554432_NS = 5
};



inline const char8* enumToString(PciExpressLatencyToleranceReportingLatencyScale scale) // TEST: NO
{
    // COMMON_LT((" | scale = %u", scale)); // Commented to avoid bad looking logs



    switch (scale)
    {
        case PciExpressLatencyToleranceReportingLatencyScale::_1_NS:        return "1_NS";
        case PciExpressLatencyToleranceReportingLatencyScale::_32_NS:       return "32_NS";
        case PciExpressLatencyToleranceReportingLatencyScale::_1024_NS:     return "1024_NS";
        case PciExpressLatencyToleranceReportingLatencyScale::_32768_NS:    return "32768_NS";
        case PciExpressLatencyToleranceReportingLatencyScale::_1048576_NS:  return "1048576_NS";
        case PciExpressLatencyToleranceReportingLatencyScale::_33554432_NS: return "33554432_NS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressLatencyToleranceReportingLatencyScale scale) // TEST: NO
{
    // COMMON_LT((" | scale = %u", scale)); // Commented to avoid bad looking logs



    static char8 res[19];

    sprintf(res, "0x%02X (%s)", (bad_uint8)scale, enumToString(scale));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLATENCYTOLERANCEREPORTINGLATENCYSCALE_H
