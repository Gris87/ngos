#include "cpppowerof2verifier.h"

#include "src/other/codeverificationfiletype.h"



CppPowerOf2Verifier::CppPowerOf2Verifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mPowerOf2Regexp("^(.*[^\\w])?(1|2|4|8|16|32|64|128|256|512)([lL]{1,2}[uU]?|[uU][lL]?) *<<.*$")
{
    // Nothing
}

void CppPowerOf2Verifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppPowerOf2Verifier");
        removeComments(line);



        QRegularExpressionMatch match = mPowerOf2Regexp.match(line);

        if (match.hasMatch())
        {
            worker->addWarning(path, i, "You should use ULL suffix for power of 2");
        }
    }
}



CppPowerOf2Verifier cppPowerOf2VerifierInstance;
