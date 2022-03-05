#include "basedocsverifier.h"                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QList<BaseDocsVerifier *> BaseDocsVerifier::sVerifiers;                                                                                                                                                  // Colorize: green
qint64                    BaseDocsVerifier::sAmountOfChecks = 0;                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
BaseDocsVerifier::BaseDocsVerifier(DocsVerificationFileType verification)                                                                                                                                // Colorize: green
    : BaseDocsVerifier((qint64)verification)                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
BaseDocsVerifier::BaseDocsVerifier(qint64 verification)                                                                                                                                                  // Colorize: green
    : mVerification(verification)                                                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    sVerifiers.append(this);                                                                                                                                                                             // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void BaseDocsVerifier::verifyAll(DocsWorkerThread *worker, DocsFileInfo *fileInfo, const QString &content, const QStringList &lines)                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    for (qint64 i = 0; i < sVerifiers.size(); ++i)                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        BaseDocsVerifier *verifier = sVerifiers.at(i);                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (((qint64)fileInfo->getVerificationFileType() & verifier->mVerification) != 0)                                                                                                                // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            verifier->verify(worker, fileInfo->getPath(), content, lines);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            ++sAmountOfChecks;                                                                                                                                                                           // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
qint64 BaseDocsVerifier::getAmountOfChecks()                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return sAmountOfChecks;                                                                                                                                                                              // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void BaseDocsVerifier::removeComments(QString &line)                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    for (qint64 i = 0; i < line.length(); ++i)                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Skip escaped character                                                                                                                                                                        // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            if (line.at(i) == '\\')                                                                                                                                                                      // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                ++i;                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                continue;                                                                                                                                                                                // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Skip "text"                                                                                                                                                                                   // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            if (line.at(i) == '\"')                                                                                                                                                                      // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                ++i;                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                while (i < line.length())                                                                                                                                                                // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    if (line.at(i) == '\\')                                                                                                                                                              // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        i += 2;                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        continue;                                                                                                                                                                        // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (line.at(i) == '\"')                                                                                                                                                              // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    ++i;                                                                                                                                                                                 // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                continue;                                                                                                                                                                                // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // If we found single line comment then remove it and terminate                                                                                                                                  // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            if (                                                                                                                                                                                         // Colorize: green
                i > 0                                                                                                                                                                                    // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                line.at(i - 1) == '/'                                                                                                                                                                    // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                line.at(i) == '/'                                                                                                                                                                        // Colorize: green
               )                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                line = line.left(i - 1);                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                break;                                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void BaseDocsVerifier::removeStrings(QString &line)                                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    for (qint64 i = 0; i < line.length(); ++i)                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Skip escaped character                                                                                                                                                                        // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            if (line.at(i) == '\\')                                                                                                                                                                      // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                ++i;                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                continue;                                                                                                                                                                                // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // If we found "text" then remove it                                                                                                                                                             // Colorize: green
        if (line.at(i) == '\"')                                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            qint64 startIndex = i;                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            ++i;                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            while (i < line.length())                                                                                                                                                                    // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (line.at(i) == '\\')                                                                                                                                                                  // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    i += 2;                                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    continue;                                                                                                                                                                            // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (line.at(i) == '\"')                                                                                                                                                                  // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++i;                                                                                                                                                                                     // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            line.remove(startIndex, i - startIndex + 1);                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            i = startIndex - 1;                                                                                                                                                                          // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
