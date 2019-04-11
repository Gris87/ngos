#include "phppunctuationverifier.h"

#include "src/other/codeverificationfiletype.h"



PhpPunctuationVerifier::PhpPunctuationVerifier()
    : BaseCodeVerifier(VerificationFileType::PHP)
{
    // Nothing
}

void PhpPunctuationVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpPunctuationVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        for (qint64 j = 0; j < line.length() - 1; ++j)
        {
            QChar ch = line.at(j);

            if (
                ch == ','
                ||
                ch == ';'
                ||
                ch == ':'
               )
            {
                QChar chNext1 = j < line.length() - 1 ? line.at(j + 1) : QChar();

                if (
                    !
                    (
                     chNext1 == ' '
                     ||
                     chNext1 == '\"'
                    )
                    &&
                    !
                    (
                     ch == ':'
                     &&
                     (
                      chNext1 == '/'
                     )
                    )
                    &&
                    !line.contains("regexp", Qt::CaseInsensitive)
                   )
                {
                    worker->addWarning(path, i, QString("Whitespace is missing after '%1' character in position %2").arg(ch).arg(j + 1));
                }
            }
        }
    }
}



PhpPunctuationVerifier phpPunctuationVerifierInstance;
