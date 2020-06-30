#ifndef DOCS_VERIFIER_SRC_VERIFIERS_BASEDOCSVERIFIER_H
#define DOCS_VERIFIER_SRC_VERIFIERS_BASEDOCSVERIFIER_H



#include <QList>

#include "src/other/docsfileinfo.h"
#include "src/threads/docsworkerthread.h"



#define VERIFIER_IGNORE(line, comment) \
    if (line.contains(comment)) \
    { \
        continue; \
    }

#define VERIFIER_IGNORE_REGION(lines, i, line, comment) \
    if (line.contains(comment " [BEGIN]")) \
    { \
        do \
        { \
            ++i; \
        } while(i < lines.length() && !lines.at(i).contains(comment " [END]")); \
        \
        continue; \
    } \
    else \
    { \
        VERIFIER_IGNORE(line, comment) \
    }



class BaseDocsVerifier
{
public:
    BaseDocsVerifier(DocsVerificationFileType verification); // TEST: NO
    BaseDocsVerifier(quint64 verification); // TEST: NO

    static void verifyAll(DocsWorkerThread *worker, DocsFileInfo *fileInfo, const QString &content, const QStringList &lines); // TEST: NO

    static quint64 getAmountOfVerifications(); // TEST: NO

protected:
    virtual void verify(DocsWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines); // TEST: NO

    inline void removeComments(QString &line) // TEST: NO
    {
        for (qint64 i = 0; i < line.length(); ++i)
        {
            if (line.at(i) == '\\')
            {
                ++i;

                continue;
            }

            if (line.at(i) == '\"')
            {
                ++i;

                while (i < line.length())
                {
                    if (line.at(i) == '\\')
                    {
                        i += 2;

                        continue;
                    }

                    if (line.at(i) == '\"')
                    {
                        break;
                    }

                    ++i;
                }

                continue;
            }

            if (
                i > 0
                &&
                line.at(i - 1) == '/'
                &&
                line.at(i) == '/'
               )
            {
                line = line.left(i - 1);

                break;
            }
        }
    }

    inline void removeStrings(QString &line) // TEST: NO
    {
        for (qint64 i = 0; i < line.length(); ++i)
        {
            if (line.at(i) == '\\')
            {
                ++i;

                continue;
            }

            if (line.at(i) == '\"')
            {
                qint64 startIndex = i;



                ++i;

                while (i < line.length())
                {
                    if (line.at(i) == '\\')
                    {
                        i += 2;

                        continue;
                    }

                    if (line.at(i) == '\"')
                    {
                        break;
                    }

                    ++i;
                }



                line.remove(startIndex, i - startIndex + 1);

                i = startIndex - 1;
            }
        }
    }

private:
    static QList<BaseDocsVerifier *> sVerifiers;
    static quint64                   sAmountOfVerifications;

    quint64 mVerification;
};



#endif // DOCS_VERIFIER_SRC_VERIFIERS_BASEDOCSVERIFIER_H
