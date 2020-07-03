#include "asciitextverifier.h"

#include "com/ngos/devtools/code_verifier/other/codeverificationfiletype.h"



AsciiTextVerifier::AsciiTextVerifier()
    : BaseCodeVerifier(VERIFICATION_ANY_FILE_TYPE)
{
    // Nothing
}

void AsciiTextVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    if (path.endsWith(".ts"))
    {
        return;
    }



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        for (qint64 j = 0; j < line.length(); ++j)
        {
            QChar   ch      = line.at(j);
            quint16 unicode = ch.unicode();

            if (
                (
                 unicode < 0x20
                 ||
                 unicode > 0x7F
                )
                &&
                unicode != '\t'
               )
            {
                worker->addError(path, i, QString("Non-ascii character found: %1").arg(ch));
            }
        }
    }
}



AsciiTextVerifier asciiTextVerifierInstance;
