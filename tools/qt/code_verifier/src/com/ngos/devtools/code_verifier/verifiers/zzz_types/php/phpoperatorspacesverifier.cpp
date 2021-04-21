#include "phpoperatorspacesverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



PhpOperatorSpacesVerifier::PhpOperatorSpacesVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
{
    // Nothing
}

inline bool isSpaceOrEmpty(const QChar &ch)
{
    return ch.isNull() || ch == ' ';
}

inline bool isVariableStart(const QChar &ch)
{
    return ch.isLetter() || ch == '_';
}

inline bool validateSignPlusCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      "++"
    //        ^
    //
    //      "++"
    //       ^

    return chPrev1 == '+'
            ||
            chNext1 == '+';
}

inline bool validateSignPlusCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " += "
    //        ^

    return chNext1 == '='
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignPlus(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignPlusCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignPlusCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignMinusCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      "--"
    //        ^
    //
    //      "--"
    //       ^

    return chPrev1 == '-'
            ||
            chNext1 == '-';
}

inline bool validateSignMinusCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " -= "
    //        ^

    return chNext1 == '='
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignMinusCase3(const QChar &/*chPrev1*/, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      "->"
    //      "-[a-z0-9]"
    //      "-$"
    //       ^

    return chNext1 == '>'
            ||
            chNext1.isLetterOrNumber()
            ||
            chNext1 == '$';
}

inline bool validateSignMinus(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignMinusCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignMinusCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignMinusCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignMultiplyCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      "**"
    //      "/*"
    //        ^
    //
    //      "**"
    //      "*/"
    //       ^

    return chPrev1 == '*'
            ||
            chPrev1 == '/'
            ||
            chNext1 == '*'
            ||
            chNext1 == '/';
}

inline bool validateSignMultiplyCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " *= "
    //        ^

    return chNext1 == '='
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignMultiply(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignMultiplyCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignMultiplyCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignDivideCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      "*/"
    //        ^
    //
    //      "/*"
    //       ^

    return chPrev1 == '*'
            ||
            chNext1 == '*';
}

inline bool validateSignDivideCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " /= "
    //      " // "
    //        ^

    return (
                chNext1 == '='
                ||
                chNext1 == '/'
            )
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignDivideCase3(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      " // "
    //         ^

    return chPrev1 == '/'
            &&
            isSpaceOrEmpty(chPrev2)
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignDivide(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignDivideCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignDivideCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignDivideCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignLessCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " <= "
    //        ^

    return chNext1 == '='
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignLessCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    // Cases:
    //      " << "
    //      " <<= "
    //        ^

    return chNext1 == '<'
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            (
                isSpaceOrEmpty(chNext2)
                ||
                (
                    chNext2 == '='
                    &&
                    isSpaceOrEmpty(chNext3)
                )
            );
}

inline bool validateSignLessCase3(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " << "
    //      " <<= "
    //         ^

    return chPrev1 == '<'
            &&
            isSpaceOrEmpty(chPrev2)
            &&
            (
                isSpaceOrEmpty(chNext1)
                ||
                (
                    chNext1 == '='
                    &&
                    isSpaceOrEmpty(chNext2)
                )
            );
}

inline bool validateSignLessCase4(const QChar &/*chPrev1*/, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    // Cases:
    //      "<?php"
    //       ^

    return chNext1 == '?'
            &&
            chNext2 == 'p'
            &&
            chNext3 == 'h';
}

inline bool validateSignLess(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignLessCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignLessCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignLessCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignLessCase4(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignMoreCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &/*chNext1*/, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      "->"
    //        ^

    return chPrev1 == '-';
}

inline bool validateSignMoreCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " >= "
    //        ^

    return chNext1 == '='
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignMoreCase3(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    // Cases:
    //      " >> "
    //      " >>= "
    //        ^

    return chNext1 == '>'
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            (
                isSpaceOrEmpty(chNext2)
                ||
                (
                    chNext2 == '='
                    &&
                    isSpaceOrEmpty(chNext3)
                )
            );
}

inline bool validateSignMoreCase4(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " >> "
    //      " >>= "
    //         ^

    return chPrev1 == '>'
            &&
            isSpaceOrEmpty(chPrev2)
            &&
            (
                isSpaceOrEmpty(chNext1)
                ||
                (
                    chNext1 == '='
                    &&
                    isSpaceOrEmpty(chNext2)
                )
            );
}

inline bool validateSignMoreCase5(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      " ?> "
    //      " => "
    //         ^

    return (
                chPrev1 == '?'
                ||
                chPrev1 == '='
            )
            &&
            isSpaceOrEmpty(chPrev2)
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignMore(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignMoreCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignMoreCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignMoreCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignMoreCase4(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignMoreCase5(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignEqualCase1(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      " += "
    //      " -= "
    //      " *= "
    //      " /= "
    //      " %= "
    //      " <= "
    //      " >= "
    //      " == "
    //      " != "
    //      " &= "
    //      " |= "
    //      " ^= "
    //      " .= "
    //         ^

    return (
                chPrev1 == '+'
                ||
                chPrev1 == '-'
                ||
                chPrev1 == '*'
                ||
                chPrev1 == '/'
                ||
                chPrev1 == '%'
                ||
                chPrev1 == '<'
                ||
                chPrev1 == '>'
                ||
                chPrev1 == '='
                ||
                chPrev1 == '!'
                ||
                chPrev1 == '&'
                ||
                chPrev1 == '|'
                ||
                chPrev1 == '^'
                ||
                chPrev1 == '.'
            )
            &&
            isSpaceOrEmpty(chPrev2)
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignEqualCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " == "
    //      " => "
    //        ^

    return (
                chNext1 == '='
                ||
                chNext1 == '>'
            )
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignEqualCase3(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      " <<= "
    //      " >>= "
    //      " &&= "
    //      " ||= "
    //          ^

    return (
                chPrev1 == '<'
                ||
                chPrev1 == '>'
                ||
                chPrev1 == '&'
                ||
                chPrev1 == '|'
            )
            &&
            chPrev2 == chPrev1
            &&
            isSpaceOrEmpty(chPrev3)
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignEqualCase4(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    // Cases:
    //      " === "
    //        ^

    return chNext1 == '='
            &&
            chNext2 == '='
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext3);
}

inline bool validateSignEqualCase5(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " === "
    //      " !== "
    //         ^

    return chNext1 == '='
            &&
            (
                chPrev1 == '='
                ||
                chPrev1 == '!'
            )
            &&
            isSpaceOrEmpty(chPrev2)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignEqualCase6(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      " === "
    //      " !== "
    //          ^

    return chPrev1 == '='
            &&
            (
                chPrev2 == '='
                ||
                chPrev2 == '!'
            )
            &&
            isSpaceOrEmpty(chPrev3)
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignEqual(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignEqualCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignEqualCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignEqualCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignEqualCase4(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignEqualCase5(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignEqualCase6(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignAndCase1(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      " && "
    //         ^

    return chPrev1 == '&'
            &&
            isSpaceOrEmpty(chPrev2)
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignAndCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " &= "
    //      " && "
    //        ^

    return (
                chNext1 == '='
                ||
                chNext1 == '&'
            )
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignAndCase3(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " &$[a-z_]"
    //        ^

    return chNext1 == '$'
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isVariableStart(chNext2);
}

inline bool validateSignAnd(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignAndCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignAndCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignAndCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignOrCase1(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/)
{
    // Cases:
    //      " || "
    //         ^

    return chPrev1 == '|'
            &&
            isSpaceOrEmpty(chPrev2)
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignOrCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " |= "
    //      " || "
    //        ^

    return (
                chNext1 == '='
                ||
                chNext1 == '|'
            )
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignOr(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignOrCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3)
            ||
            validateSignOrCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignXorCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " ^= "
    //        ^

    return chNext1 == '='
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignXor(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignXorCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateSignDotCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/)
{
    // Cases:
    //      " .= "
    //        ^

    return chNext1 == '='
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignDot(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    return validateSignDotCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
}

inline bool validateChar(const QChar &ch, const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3)
{
    // Cases:
    //      "'?'"
    //      " ? "
    //        ^
    if (
        (
         chPrev1 == '\''
         &&
         chNext1 == '\''
        )
        ||
        (
         isSpaceOrEmpty(chPrev1)
         &&
         isSpaceOrEmpty(chNext1)
        )
       )
    {
        return true;
    }



    switch (ch.unicode())
    {
        case '+': return validateSignPlus(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '-': return validateSignMinus(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '*': return validateSignMultiply(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '/': return validateSignDivide(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '<': return validateSignLess(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '>': return validateSignMore(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '=': return validateSignEqual(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '&': return validateSignAnd(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '|': return validateSignOr(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '^': return validateSignXor(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);
        case '.': return validateSignDot(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3);

        default: return true;
    }
}

void PhpOperatorSpacesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpOperatorSpacesVerifier");
        removeComments(line);



        if (line.length() > 1)
        {
            QChar ch;
            QChar chPrev1;
            QChar chPrev2;
            QChar chPrev3;
            QChar chNext1 = line.at(0);
            QChar chNext2 = line.at(1);
            QChar chNext3 = line.length() > 2 ? line.at(2) : QChar();

            for (qint64 j = 0; j < line.length(); ++j)
            {
                chPrev3 = chPrev2;
                chPrev2 = chPrev1;
                chPrev1 = ch;
                ch      = chNext1;
                chNext1 = chNext2;
                chNext2 = chNext3;
                chNext3 = j < line.length() - 3 ? line.at(j + 3) : QChar();



                if (ch == '\\')
                {
                    ++j;

                    chPrev3 = chPrev2;
                    chPrev2 = chPrev1;
                    chPrev1 = ch;
                    ch      = chNext1;
                    chNext1 = chNext2;
                    chNext2 = chNext3;
                    chNext3 = j < line.length() - 3 ? line.at(j + 3) : QChar();

                    continue;
                }
                else
                if (ch == '\"')
                {
                    ++j;

                    while (j < line.length())
                    {
                        ch = line.at(j);

                        if (ch == '\\')
                        {
                            j += 2;

                            continue;
                        }

                        if (ch == '\"')
                        {
                            break;
                        }

                        ++j;
                    }

                    chPrev1 = j >= 1                ? line.at(j - 1) : QChar();
                    chPrev2 = j >= 2                ? line.at(j - 2) : QChar();
                    chNext1 = j < line.length() - 1 ? line.at(j + 1) : QChar();
                    chNext2 = j < line.length() - 2 ? line.at(j + 2) : QChar();
                    chNext3 = j < line.length() - 3 ? line.at(j + 3) : QChar();

                    continue;
                }



                if (!validateChar(ch, chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3))
                {
                    worker->addError(path, i, QString("Whitespace is missing for operator '%1' in position %2").arg(ch).arg(j + 1));
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



PhpOperatorSpacesVerifier phpOperatorSpacesVerifierInstance;
