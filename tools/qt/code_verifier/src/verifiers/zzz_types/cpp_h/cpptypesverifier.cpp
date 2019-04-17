#include "cpptypesverifier.h"

#include "src/other/codeverificationfiletype.h"



CppTypesVerifier::CppTypesVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mDefinitionRegExp("\\b(((signed|unsigned) *(char|short|int|long)?)|short|int|long)\\b")
{
    // Nothing
}

void CppTypesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    if (path.contains("include/ngos/types.h"))
    {
        return;
    }



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppTypesVerifier");
        removeComments(line);
        removeStrings(line);



        QRegularExpressionMatchIterator matches = mDefinitionRegExp.globalMatch(line);

        while (matches.hasNext())
        {
            QRegularExpressionMatch match = matches.next();

            if (match.hasMatch())
            {
                worker->addWarning(path, i, QString("Please use more formal data type: %1").arg(path.contains("/src/os/configure/") ? "u8/i8/u16/i16/u32/i32/u64/i64" : "quint8/qint8/quint16/qint16/quint32/qint32/quint64/qint64"));
            }
        }
    }
}



CppTypesVerifier cppTypesVerifierInstance;
