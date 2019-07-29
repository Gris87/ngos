#include "cppngoslogsverifier.h"

#include "src/other/codeverificationfiletype.h"



CppNgosLogsVerifier::CppNgosLogsVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mDefinitionRegExp("^(?:L(?:[FCEWID]|V{1,3})|(?:TEST_)?ASSERT(_EXECUTION)?)\\(.*$")
{
    // Nothing
}

void CppNgosLogsVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    QString logPrefix = logPrefixFromPath(path);

    bool checkUefi   = true;
    bool checkEarly  = true;
    bool checkCommon = true;

    if (logPrefix == "UEFI")
    {
        checkUefi = false;
    }

    if (logPrefix == "EARLY")
    {
        checkEarly = false;
    }

    if (logPrefix == "COMMON")
    {
        checkCommon = false;
    }



    for (qint64 i = 0; i < lines.length(); ++i)
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
                worker->addError(path, i, "UEFI logging is prohibited");
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
                worker->addError(path, i, "UEFI logging is prohibited");
            }
        }
    }
}



CppNgosLogsVerifier cppNgosLogsVerifierInstance;
