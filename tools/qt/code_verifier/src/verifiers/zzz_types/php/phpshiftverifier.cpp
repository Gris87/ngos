#include "phpshiftverifier.h"

#include "src/other/codeverificationfiletype.h"



PhpShiftVerifier::PhpShiftVerifier()
    : BaseCodeVerifier(VerificationFileType::PHP)
    , mShiftRegexp("(?:\\*|\\/) *(0x[0-9a-fA-F]+|[1-9]\\d*(?:\\.\\d+)?)")
{
    // Nothing
}

void PhpShiftVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpShiftVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        QRegularExpressionMatchIterator matches = mShiftRegexp.globalMatch(line);

        while (matches.hasNext())
        {
            QRegularExpressionMatch match = matches.next();

            if (match.hasMatch() && isPowerOf2(match.captured(1)))
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



    return !((value - 1) & value); // ((value - 1) & value) == 0
}



PhpShiftVerifier phpShiftVerifierInstance;
