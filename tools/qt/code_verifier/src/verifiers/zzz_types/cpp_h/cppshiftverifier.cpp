#include "cppshiftverifier.h"

#include "src/other/codeverificationfiletype.h"



CppShiftVerifier::CppShiftVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mShiftRegexp("(?:\\*|\\/) *(0x[0-9a-fA-F]+|[1-9]\\d*(?:\\.\\d+)?)")
{
    // Nothing
}

void CppShiftVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppShiftVerifier");
        removeComments(line);
        removeStrings(line);



        if (line.contains("_ASSERT"))
        {
            continue;
        }



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

bool CppShiftVerifier::isPowerOf2(const QString &number)
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



    return !(value & (value - 1)); // (value & (value - 1)) == 0
}



CppShiftVerifier cppShiftVerifierInstance;
