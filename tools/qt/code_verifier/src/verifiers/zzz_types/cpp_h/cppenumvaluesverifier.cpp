#include "cppenumvaluesverifier.h"

#include "src/other/codeverificationfiletype.h"



CppEnumValuesVerifier::CppEnumValuesVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mDefinitionRegExp("^ *[_A-Z][_A-Z0-9]*(?: *=.*)?,?(?: *\\/\\/.*)?$")
{
    // Nothing
}

void CppEnumValuesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppEnumValuesVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        if (
            line.startsWith("enum ")
            &&
            (
             i < lines.length() - 1
             &&
             lines.at(i + 1) == '{'
            )
           )
        {
            i += 2;

            while (i < lines.length() && lines.at(i) != "};")
            {
                QString anotherLine = lines.at(i);

                if (
                    anotherLine != ""
                    &&
                    !anotherLine.trimmed().startsWith("//")
                   )
                {
                    QRegularExpressionMatch match = mDefinitionRegExp.match(anotherLine);

                    if (!match.hasMatch())
                    {
                        worker->addError(path, i, "Invalid enum value");
                    }
                }



                ++i;
            }
        }
    }
}



CppEnumValuesVerifier cppEnumValuesVerifierInstance;
