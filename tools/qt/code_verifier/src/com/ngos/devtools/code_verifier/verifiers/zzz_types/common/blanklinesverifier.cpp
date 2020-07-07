#include "blanklinesverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



BlankLinesVerifier::BlankLinesVerifier()
    : BaseCodeVerifier(VERIFICATION_ANY_FILE_TYPE)
{
    // Nothing
}

void BlankLinesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    quint64 blockSize = 0;

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        if (line == "")
        {
            ++blockSize;
        }
        else
        {
            if (blockSize > 0)
            {
                if (blockSize != 1 && blockSize != 3)
                {
                    worker->addWarning(path, i - 1, "Invalid amount of blank lines. Only 1 or 3 blank lines allowed");
                }

                blockSize = 0;
            }
        }
    }

    if (blockSize != 1)
    {
        if (blockSize == 0)
        {
            worker->addError(path, lines.length(), "No blank line at the end");
        }
        else
        {
            worker->addError(path, lines.length(), "Too many blank lines at the end");
        }
    }
}



BlankLinesVerifier blankLinesVerifierInstance;
