#ifndef COM_NGOS_DEVTOOLS_SHARED_CONSOLE_CONSOLE_H                                                                                                                                                       // Colorize: green
#define COM_NGOS_DEVTOOLS_SHARED_CONSOLE_CONSOLE_H                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QString>                                                                                                                                                                                       // Colorize: green
#include <QTextStream>                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class Console                                                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    static void out(const QString &text); // TEST: NO                                                                                                                                                    // Colorize: green
    static void err(const QString &text); // TEST: NO                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    Console(); // TEST: NO                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static QTextStream sStdout;                                                                                                                                                                          // Colorize: green
    static QTextStream sStderr;                                                                                                                                                                          // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_SHARED_CONSOLE_CONSOLE_H                                                                                                                                                     // Colorize: green
