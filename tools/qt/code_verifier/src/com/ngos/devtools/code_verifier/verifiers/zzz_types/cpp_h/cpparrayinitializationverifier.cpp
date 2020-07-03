#include "cpparrayinitializationverifier.h"

#include "com/ngos/devtools/code_verifier/other/codeverificationfiletype.h"



CppArrayInitializationVerifier::CppArrayInitializationVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

inline bool isSpaceOrEmpty(const QChar &ch)
{
    return ch.isNull() || ch == ' ';
}

inline bool validateSignOpenBracketCase1(const QChar &/*chPrev1*/, const QChar &chNext1)
{
    // Cases:
    //      "{{"
    //      "{ "
    //       ^

    return chNext1 == '{'
            ||
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignOpenBracketCase2(const QChar &chPrev1, const QChar &/*chNext1*/)
{
    // Cases:
    //      "{{"
    //        ^

    return chPrev1 == '{';
}

inline bool validateSignOpenBracket(const QChar &chPrev1, const QChar &chNext1)
{
    return validateSignOpenBracketCase1(chPrev1, chNext1)
            ||
            validateSignOpenBracketCase2(chPrev1, chNext1);
}

inline bool validateSignCloseBracketCase1(const QChar &/*chPrev1*/, const QChar &chNext1)
{
    // Cases:
    //      "}}"
    //      "};"
    //      "},"
    //      "} "
    //       ^

    return chNext1 == '}'
            ||
            chNext1 == ';'
            ||
            chNext1 == ','
            ||
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignCloseBracketCase2(const QChar &chPrev1, const QChar &/*chNext1*/)
{
    // Cases:
    //      "}}"
    //        ^

    return chPrev1 == '%';
}

inline bool validateSignCloseBracket(const QChar &chPrev1, const QChar &chNext1)
{
    return validateSignCloseBracketCase1(chPrev1, chNext1)
            ||
            validateSignCloseBracketCase2(chPrev1, chNext1);
}

inline bool validateChar(const QChar &ch, const QChar &chPrev1, const QChar &chNext1)
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
        case '{': return validateSignOpenBracket(chPrev1, chNext1);
        case '}': return validateSignCloseBracket(chPrev1, chNext1);

        default: return true;
    }
}

void CppArrayInitializationVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// CppArrayInitializationVerifier");
        removeComments(line);
        removeStrings(line);



        qint64 index = line.indexOf('{');

        if (index >= 0)
        {
            qint64 index2 = line.indexOf('}', index + 1);

            if (index2 >= 0)
            {
                QChar chPrev1;
                QChar ch      = index > 0 ? line.at(index - 1) : QChar(); // Ignore CppZeroConditionVerifier
                QChar chNext1 = line.at(index);

                for (qint64 j = index; j < line.length(); ++j)
                {
                    chPrev1 = ch;
                    ch      = chNext1;
                    chNext1 = j < line.length() - 1 ? line.at(j + 1) : QChar();



                    if (!validateChar(ch, chPrev1, chNext1))
                    {
                        worker->addWarning(path, i, QString("Whitespace is missing after '%1' character in position %2").arg(ch).arg(j + 1));
                    }
                }
            }
        }
    }
}



CppArrayInitializationVerifier cppArrayInitializationVerifierInstance;
