#include "hexverifier.h"

#include "src/other/codeverificationfiletype.h"



HexVerifier::HexVerifier()
    : BaseCodeVerifier(VERIFICATION_ANY_FILE_TYPE)
    , mHexRegExp("0x(?:[0-9a-fA-F]+|%\\w+)")
{
    // Nothing
}

void HexVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    if (
        path.endsWith("src/os/shared/uefibase/test/bits64/sections/section0/__shared/common/bits64/printf/printf.h")
        ||
        path.endsWith("tools/tracers/linux.sh")
       )
    {
        return;
    }



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        if (!line.contains("https://0xax.gitbooks.io"))
        {
            QRegularExpressionMatchIterator matches = mHexRegExp.globalMatch(line);

            while (matches.hasNext())
            {
                QRegularExpressionMatch match = matches.next();

                QString hex        = match.captured(0);
                QString hexTrimmed = hex.mid(2);

                if (hexTrimmed.startsWith('%'))
                {
                    if (hexTrimmed.at(hexTrimmed.length() - 1).isLetter())
                    {
                        if (
                            hexTrimmed != "%p"
                            &&
                            hexTrimmed != "%02X"
                            &&
                            hexTrimmed != "%04X"
                            &&
                            hexTrimmed != "%08X"
                            &&
                            hexTrimmed != "%016lX"
                           )
                        {
                            worker->addError(path, i, QString("Unexpected hex format %1. Expecting for: 0x%p, 0x%02X, 0x%04X, 0x%08X, 0x%016lX").arg(hex));
                        }
                    }
                    else
                    {
                        for (qint64 j = 1; j < hexTrimmed.length(); ++j)
                        {
                            if (!hexTrimmed.at(j).isNumber())
                            {
                                worker->addError(path, i, QString("Only numeric symbols are allowed in format %1").arg(hex));

                                break;
                            }
                        }
                    }
                }
                else
                {
                    if (
                        hexTrimmed.length() != 2
                        &&
                        hexTrimmed.length() != 4
                        &&
                        hexTrimmed.length() != 8
                        &&
                        hexTrimmed.length() != 16
                       )
                    {
                        worker->addError(path, i, QString("Hex length of %1 should be 2, 4, 8 or 16").arg(hex));
                    }

                    for (qint64 j = 0; j < hexTrimmed.length(); ++j)
                    {
                        if (hexTrimmed.at(j).isLower())
                        {
                            worker->addError(path, i, QString("Capital letters should be used for hex %1").arg(hex));

                            break;
                        }
                    }
                }
            }
        }
    }
}



HexVerifier hexVerifierInstance;
