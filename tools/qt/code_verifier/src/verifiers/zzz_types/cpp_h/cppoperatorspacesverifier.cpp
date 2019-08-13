#include "cppoperatorspacesverifier.h"

#include "src/other/codeverificationfiletype.h"



CppOperatorSpacesVerifier::CppOperatorSpacesVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
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

inline bool validateSignPlusCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignPlusCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignPlus(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignPlusCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignPlusCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateSignMinusCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignMinusCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignMinusCase3(const QChar &/*chPrev1*/, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      "->"
    //      "-[a-z0-9]"
    //       ^

    return chNext1 == '>'
            ||
            chNext1.isLetterOrNumber();
}

inline bool validateSignMinus(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignMinusCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMinusCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMinusCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateSignMultiplyCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignMultiplyCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignMultiplyCase3(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      " *[a-z_]"
    //      "(*[a-z_]"
    //      ")*[a-z_]"
    //      " *("
    //      "(*("
    //      ")*("
    //        ^

    return (
                isVariableStart(chNext1)
                ||
                chNext1 == '('
            )
            &&
            (
                isSpaceOrEmpty(chPrev1)
                ||
                chPrev1 == '('
                ||
                chPrev1 == ')'
            );
}

inline bool validateSignMultiplyCase4(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      "[a-z0-9]* "
    //               ^

    return chPrev1.isLetterOrNumber()
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignMultiplyCase5(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      " *> "
    //      " *>>"
    //      " *>("
    //      " *>&"
    //      " *>:"
    //        ^

    return chNext1 == '>'
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            (
                isSpaceOrEmpty(chNext2)
                ||
                chNext2 == '>'
                ||
                chNext2 == '('
                ||
                chNext2 == '&'
                ||
                chNext2 == ':'
            );
}

inline bool validateSignMultiplyCase6(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      " *)[a-z0-9]"
    //      " *)("
    //      " *)&"
    //      " *),"
    //      " *); "
    //        ^

    return chNext1 == ')'
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            (
                chNext2.isLetterOrNumber()
                ||
                chNext2 == '('
                ||
                chNext2 == '&'
                ||
                chNext2 == ','
                ||
                (
                    chNext2 == ';'
                    &&
                    isSpaceOrEmpty(chNext3)
                )
            );
}

inline bool validateSignMultiplyCase7(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      " *, "
    //        ^

    return chNext1 == ','
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignMultiplyCase8(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      ">* "
    //        ^

    return chPrev1 == '>'
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignMultiply(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignMultiplyCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMultiplyCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMultiplyCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMultiplyCase4(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMultiplyCase5(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMultiplyCase6(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMultiplyCase7(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMultiplyCase8(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateSignDivideCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignDivideCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignDivideCase3(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignDivide(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignDivideCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignDivideCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignDivideCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateSignLessCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignLessCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignLessCase3(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignLessCase4(const QChar &/*chPrev1*/, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &/*chNext1*/, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &line, const qint64 index)
{
    // Cases:
    //      "<...>"
    //       ^

    return line.indexOf('>', index + 1) >= 0;
}

inline bool validateSignLess(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignLessCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignLessCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignLessCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignLessCase4(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateSignMoreCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &/*chNext1*/, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      "->"
    //        ^

    return chPrev1 == '-';
}

inline bool validateSignMoreCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignMoreCase3(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignMoreCase4(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignMoreCase5(const QChar &/*chPrev1*/, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &/*chNext1*/, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &line, const qint64 index)
{
    // Cases:
    //      "<...>"
    //           ^

    return line.lastIndexOf('<', index - 1) >= 0;
}

inline bool validateSignMore(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignMoreCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMoreCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMoreCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMoreCase4(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignMoreCase5(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateSignEqualCase1(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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
            )
            &&
            isSpaceOrEmpty(chPrev2)
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignEqualCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      " == "
    //        ^

    return chNext1 == '='
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            isSpaceOrEmpty(chNext2);
}

inline bool validateSignEqualCase3(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignEqual(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignEqualCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignEqualCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignEqualCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateSignAndCase1(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignAndCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignAndCase3(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      " &[a-z_]"
    //      "(&[a-z_]"
    //      ")&[a-z_]"
    //      " &("
    //      "(&("
    //      ")&("
    //        ^

    return (
                isVariableStart(chNext1)
                ||
                chNext1 == '('
            )
            &&
            (
                isSpaceOrEmpty(chPrev1)
                ||
                chPrev1 == '('
                ||
                chPrev1 == ')'
            );
}

inline bool validateSignAndCase4(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      "[a-z0-9]& "
    //               ^
    //
    //      ">& "
    //        ^

    return (
                chPrev1.isLetterOrNumber()
                ||
                chPrev1 == '>'
            )
            &&
            isSpaceOrEmpty(chNext1);
}

inline bool validateSignAndCase5(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      " &))"
    //        ^

    return chNext1 == ')'
            &&
            isSpaceOrEmpty(chPrev1)
            &&
            chNext2 == ')';
}

inline bool validateSignAndCase6(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
{
    // Cases:
    //      " &/*"
    //        ^

    return chNext1 == '/'
            &&
            chNext2 == '*'
            &&
            isSpaceOrEmpty(chPrev1);
}

inline bool validateSignAnd(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignAndCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignAndCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignAndCase3(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignAndCase4(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignAndCase5(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignAndCase6(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateSignOrCase1(const QChar &chPrev1, const QChar &chPrev2, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &/*chNext2*/, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignOrCase2(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignOr(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignOrCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index)
            ||
            validateSignOrCase2(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateSignXorCase1(const QChar &chPrev1, const QChar &/*chPrev2*/, const QChar &/*chPrev3*/, const QChar &chNext1, const QChar &chNext2, const QChar &/*chNext3*/, const QString &/*line*/, const qint64 /*index*/)
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

inline bool validateSignXor(const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
{
    return validateSignXorCase1(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
}

inline bool validateChar(const QChar &ch, const QChar &chPrev1, const QChar &chPrev2, const QChar &chPrev3, const QChar &chNext1, const QChar &chNext2, const QChar &chNext3, const QString &line, const qint64 index)
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



    // Cases:
    //      "operator?("
    //      "operator??("
    //               ^
    //
    //      "operator??("
    //                ^
    if (
        (
         chPrev3 == 't'
         &&
         chPrev2 == 'o'
         &&
         chPrev1 == 'r'
         &&
         chNext1 == '('
        )
        ||
        (
         chPrev3 == 't'
         &&
         chPrev2 == 'o'
         &&
         chPrev1 == 'r'
         &&
         chNext2 == '('
        )
        ||
        (
         chPrev3 == 'o'
         &&
         chPrev2 == 'r'
         &&
         chNext1 == '('
        )
       )
    {
        return true;
    }



    switch (ch.unicode())
    {
        case '+': return validateSignPlus(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
        case '-': return validateSignMinus(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
        case '*': return validateSignMultiply(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
        case '/': return validateSignDivide(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
        case '<': return validateSignLess(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
        case '>': return validateSignMore(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
        case '=': return validateSignEqual(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
        case '&': return validateSignAnd(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
        case '|': return validateSignOr(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);
        case '^': return validateSignXor(chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, index);

        default: return true;
    }
}

void CppOperatorSpacesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppOperatorSpacesVerifier");
        removeComments(line);



        if (
            line.length() > 1
            &&
            !line.contains("#include")
           )
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



                if (!validateChar(ch, chPrev1, chPrev2, chPrev3, chNext1, chNext2, chNext3, line, j))
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



CppOperatorSpacesVerifier cppOperatorSpacesVerifierInstance;
