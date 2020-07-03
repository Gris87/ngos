#ifndef CONSOLE_CONSOLE_H
#define CONSOLE_CONSOLE_H



#include <QString>
#include <QTextStream>



class Console
{
public:
    static void out(const QString &text); // TEST: NO
    static void err(const QString &text); // TEST: NO

private:
    Console(); // TEST: NO

    static QTextStream sStdout;
    static QTextStream sStderr;
};



#endif // CONSOLE_CONSOLE_H
