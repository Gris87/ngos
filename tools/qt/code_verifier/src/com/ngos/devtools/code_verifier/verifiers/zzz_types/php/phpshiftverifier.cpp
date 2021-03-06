#include "phpshiftverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



PhpShiftVerifier::PhpShiftVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
    , mShiftRegexp("(?:\\*|\\/) *(0x[0-9a-fA-F]+|[1-9]\\d*(?:\\.\\d+)?)")
{
    // Nothing
}

void PhpShiftVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpShiftVerifier");
        removeComments(line);
        removeStrings(line);



        QRegularExpressionMatchIterator matches = mShiftRegexp.globalMatch(line);

        while (matches.hasNext())
        {
            QRegularExpressionMatch match = matches.next();

            if (isPowerOf2(match.captured(1)))
            {
                worker->addWarning(path, i, QString("%1 can be replaced with shift").arg(match.captured(0)));
            }
        }
    }
}

bool PhpShiftVerifier::isPowerOf2(const QString &number)
{
    bool    ok;
    quint64 value;



    if (number.startsWith("0x"))
    {
        value = number.mid(2).toULongLong(&ok, 16);
    }
    else
    {
        value = number.toULongLong(&ok);
    }



    if (!ok)
    {
        return false;
    }



    return (value & (value - 1)) == 0;
}



PhpShiftVerifier phpShiftVerifierInstance;
