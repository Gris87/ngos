#include "whitespaceverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



WhitespaceVerifier::WhitespaceVerifier()
    : BaseCodeVerifier(VERIFICATION_ANY_FILE_TYPE)
{
    // Nothing
}

void WhitespaceVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);

        if (line.endsWith(' ') || line.endsWith('\t'))
        {
            worker->addWarning(path, i, "Trailing whitespaces found");
        }
    }
}



WhitespaceVerifier whitespaceVerifierInstance;
