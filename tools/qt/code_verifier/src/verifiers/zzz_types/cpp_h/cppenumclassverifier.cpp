#include "cppenumclassverifier.h"

#include "src/other/codeverificationfiletype.h"



CppEnumClassVerifier::CppEnumClassVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mDefinitionRegExp("^ *enum( +class)?(?: +(\\w+))? *(: *\\w+)?$")
{
    // Nothing
}

void CppEnumClassVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppEnumClassVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        QRegularExpressionMatch match = mDefinitionRegExp.match(line);

        if (match.hasMatch())
        {
            QString enumClass = match.captured(1);
            QString enumName  = match.captured(2);
            QString enumType  = match.captured(3);

            if (enumClass == "")
            {
                worker->addError(path, i, "Expected enum class definition");
            }

            if (enumName == "")
            {
                worker->addError(path, i, "Expected enum name");
            }

            if (enumType == "")
            {
                worker->addError(path, i, "Expected enum type");
            }
        }
    }
}



CppEnumClassVerifier cppEnumClassVerifierInstance;
