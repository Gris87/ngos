#include "utils.h"                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QString bytesToString(qint64 bytes)                                                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    if (bytes >= 1000000000000)                                                                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return QString::number(bytes / 1000000000000) + "TB";                                                                                                                                            // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (bytes >= 1000000000)                                                                                                                                                                             // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return QString::number(bytes / 1000000000) + "GB";                                                                                                                                               // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return QString::number(bytes / 1000000) + "MB";                                                                                                                                                      // Colorize: green
}                                                                                                                                                                                                        // Colorize: green