#include "cppngoslogsverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



CppNgosLogsVerifier::CppNgosLogsVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mDefinitionRegExp("^(?:L(?:[FCEWID]|V{1,3})|(?:TEST_)?ASSERT(_EXECUTION)?)\\(.*$")
{
    // Nothing
}

void CppNgosLogsVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    QString logPrefix = logPrefixFromPath(path);

    bool checkUefi   = (logPrefix != "UEFI");
    bool checkEarly  = (logPrefix != "EARLY");
    bool checkCommon = (logPrefix != "COMMON");



    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);

        if (checkUefi)
        {
            qint64 index = line.indexOf("UEFI_");

            if (
                index >= 0
                &&
                mDefinitionRegExp.match(line.mid(index + 5)).hasMatch()
               )
            {
                worker->addError(path, i, "UEFI logging is prohibited");
            }
        }

        if (checkEarly)
        {
            qint64 index = line.indexOf("EARLY_");

            if (
                index >= 0
                &&
                mDefinitionRegExp.match(line.mid(index + 6)).hasMatch()
               )
            {
                worker->addError(path, i, "EARLY logging is prohibited");
            }
        }

        if (checkCommon)
        {
            qint64 index = line.indexOf("COMMON_");

            if (
                index >= 0
                &&
                mDefinitionRegExp.match(line.mid(index + 7)).hasMatch()
               )
            {
                worker->addError(path, i, "COMMON logging is prohibited");
            }
        }
    }
}



CppNgosLogsVerifier cppNgosLogsVerifierInstance;
