#include "console.h"



QTextStream Console::sStdout(stdout);
QTextStream Console::sStderr(stderr);



Console::Console()
{
    // Nothing
}

void Console::out(const QString &text)
{
    sStdout << text << Qt::endl;
    sStdout.flush();
}

void Console::err(const QString &text)
{
    sStderr << text << Qt::endl;
    sStderr.flush();
}
