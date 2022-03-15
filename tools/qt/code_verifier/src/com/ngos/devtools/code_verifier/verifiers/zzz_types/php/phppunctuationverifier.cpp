#include "phppunctuationverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



PhpPunctuationVerifier::PhpPunctuationVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
{
    // Nothing
}

inline bool isSpaceOrEmpty(const QChar &ch)
{
    return ch.isNull() || ch == ' ';
}

inline bool validateSignCommaCase1(const QChar &/*chPrev1*/, const QChar &/*chNext1*/, const QChar &/*chNext2*/)
{
    return false;
}

inline bool validateSignComma(const QChar &chPrev1, const QChar &chNext1, const QChar &chNext2)
{
    return validateSignCommaCase1(chPrev1, chNext1, chNext2);
}

inline bool validateSignSemiColonCase1(const QChar &/*chPrev1*/, const QChar &/*chNext1*/, const QChar &/*chNext2*/)
{
    return false;
}

inline bool validateSignSemiColon(const QChar &chPrev1, const QChar &chNext1, const QChar &chNext2)
{
    return validateSignSemiColonCase1(chPrev1, chNext1, chNext2);
}

inline bool validateSignColonCase1(const QChar &/*chPrev1*/, const QChar &chNext1, const QChar &chNext2)
{
    // Cases:
    //      "://"
    //       ^

    return chNext1 == '/'
            ||
            chNext2 == '/';
}

inline bool validateSignColon(const QChar &chPrev1, const QChar &chNext1, const QChar &chNext2)
{
    return validateSignColonCase1(chPrev1, chNext1, chNext2);
}

inline bool validateChar(const QChar &ch, const QChar &chPrev1, const QChar &chNext1, const QChar &chNext2)
{
    // Cases:
    //      "'?'"
    //        ^
    //
    //      "\"?"
    //         ^
    //
    //      "?\""
    //      "?\\"
    //      "? "
    //       ^
    if (
        (
         chPrev1 == '\''
         &&
         chNext1 == '\''
        )
        ||
        chPrev1 == '\"'
        ||
        chNext1 == '\"'
        ||
        chNext1 == '\\'
        ||
        isSpaceOrEmpty(chNext1)
       )
    {
        return true;
    }



    switch (ch.unicode())
    {
        case ',': return validateSignComma(chPrev1, chNext1, chNext2);
        case ';': return validateSignSemiColon(chPrev1, chNext1, chNext2);
        case ':': return validateSignColon(chPrev1, chNext1, chNext2);

        default: return true;
    }
}

void PhpPunctuationVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpPunctuationVerifier");
        removeComments(line);



        if (
            line.length() > 1
            &&
            !line.contains("regexp", Qt::CaseInsensitive)
           )
        {
            QChar ch;
            QChar chPrev1;
            QChar chNext1 = line.at(0);
            QChar chNext2 = line.at(1);

            for (qint64 j = 0; j < line.length(); ++j)
            {
                chPrev1 = ch;
                ch      = chNext1;
                chNext1 = chNext2;
                chNext2 = j < line.length() - 2 ? line.at(j + 2) : QChar();



                if (!validateChar(ch, chPrev1, chNext1, chNext2))
                {
                    worker->addWarning(path, i, QString("Whitespace is missing after '%1' character in position %2")
                                                        .arg(ch)
                                                        .arg(j + 1)
                    );
                }



                if (
                    ch == '/'
                    &&
                    chNext1 == '/'
                   )
                {
                    break;
                }
            }
        }
    }
}



PhpPunctuationVerifier phpPunctuationVerifierInstance;
