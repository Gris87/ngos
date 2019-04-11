#include "phpoperatorspacesverifier.h"

#include "src/other/codeverificationfiletype.h"



PhpOperatorSpacesVerifier::PhpOperatorSpacesVerifier()
    : BaseCodeVerifier(VerificationFileType::PHP)
{
    // Nothing
}

void PhpOperatorSpacesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpOperatorSpacesVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        if (line.length() > 1)
        {
            for (qint64 j = 0; j < line.length(); ++j)
            {
                QChar ch = line.at(j);

                if (
                    ch == '-'
                    ||
                    ch == '+'
                    ||
                    ch == '*'
                    ||
                    ch == '/'
                    ||
                    ch == '<'
                    ||
                    ch == '>'
                    ||
                    ch == '='
                    ||
                    ch == '&'
                    ||
                    ch == '|'
                    ||
                    ch == '^'
                   )
                {
                    QChar chPrev1 = j >= 1                ? line.at(j - 1) : QChar();
                    QChar chPrev2 = j >= 2                ? line.at(j - 2) : QChar();
                    QChar chPrev3 = j >= 3                ? line.at(j - 3) : QChar();
                    QChar chNext1 = j < line.length() - 1 ? line.at(j + 1) : QChar();
                    QChar chNext2 = j < line.length() - 2 ? line.at(j + 2) : QChar();
                    QChar chNext3 = j < line.length() - 3 ? line.at(j + 3) : QChar();



                    if (
                        !
                        (
                         chPrev1 == '\"'
                         ||
                         chNext1 == '\"'
                         ||
                         (
                          chPrev1 == '\''
                          &&
                          chNext1 == '\''
                         )
                         ||
                         (
                          (
                           chPrev1.isNull()
                           ||
                           chPrev1 == ' '
                          )
                          &&
                          (
                           chNext1.isNull()
                           ||
                           chNext1 == ' '
                          )
                         )
                         ||
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
                        &&
                        !
                        (
                         ch == '-'
                         &&
                         (
                          chNext1 == '>'
                          ||
                          chPrev1 == '-'
                          ||
                          chNext1 == '-'
                          ||
                          (
                           chNext1 == '='
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                          ||
                          chNext1.isLetterOrNumber()
                          ||
                          line.contains('\"')
                         )
                        )
                        &&
                        !
                        (
                         ch == '+'
                         &&
                         (
                          chPrev1 == '+'
                          ||
                          chNext1 == '+'
                          ||
                          (
                           chNext1 == '='
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                          ||
                          chNext1.isLetterOrNumber()
                          ||
                          line.contains('\"')
                         )
                        )
                        &&
                        !
                        (
                         ch == '*'
                         &&
                         (
                          chPrev1 == '*'
                          ||
                          chPrev1 == '/'
                          ||
                          chNext1 == '*'
                          ||
                          chNext1 == '/'
                          ||
                          chNext1 == '>'
                          ||
                          (
                           chNext1 == '='
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                          ||
                          (
                           (
                            chPrev1 == '_'
                            ||
                            chPrev1.isLetterOrNumber()
                           )
                           &&
                           (
                            chNext1.isNull()
                            ||
                            chNext1 == ' '
                            ||
                            chNext1 == ')'
                           )
                          )
                          ||
                          (
                           (
                            chNext1 == '_'
                            ||
                            chNext1 == '('
                            ||
                            chNext1 == ')'
                            ||
                            chNext1.isLetter()
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                            ||
                            chPrev1 == '('
                            ||
                            chPrev1 == ')'
                           )
                          )
                          ||
                          line.contains('\"')
                         )
                        )
                        &&
                        !
                        (
                         ch == '/'
                         &&
                         (
                          chPrev1 == '*'
                          ||
                          chNext1 == '*'
                          ||
                          (
                           chPrev1 == '/'
                           &&
                           (
                            chPrev2.isNull()
                            ||
                            chPrev2 == ' '
                           )
                           &&
                           (
                            chNext1.isNull()
                            ||
                            chNext1 == ' '
                           )
                          )
                          ||
                          (
                           (
                            chNext1 == '/'
                            ||
                            chNext1 == '='
                           )
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                          ||
                          line.contains("#include")
                          ||
                          line.contains('\"')
                         )
                        )
                        &&
                        !
                        (
                         ch == '<'
                         &&
                         (
                          (
                           chPrev1 == '<'
                           &&
                           (
                            chPrev2.isNull()
                            ||
                            chPrev2 == ' '
                           )
                           &&
                           (
                            chNext1.isNull()
                            ||
                            chNext1 == ' '
                            ||
                            (
                             chNext1 == '='
                             &&
                             (
                              chNext2.isNull()
                              ||
                              chNext2 == ' '
                             )
                            )
                           )
                          )
                          ||
                          (
                           chNext1 == '<'
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                            ||
                            (
                             chNext2 == '='
                             &&
                             (
                              chNext3.isNull()
                              ||
                              chNext3 == ' '
                             )
                            )
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                          ||
                          (
                           chNext1 == '='
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                          ||
                          line.indexOf('>', j + 1) >= 0
                         )
                        )
                        &&
                        !
                        (
                         ch == '>'
                         &&
                         (
                          chPrev1 == '-'
                          ||
                          (
                           chPrev1 == '>'
                           &&
                           (
                            chPrev2.isNull()
                            ||
                            chPrev2 == ' '
                           )
                           &&
                           (
                            chNext1.isNull()
                            ||
                            chNext1 == ' '
                            ||
                            (
                             chNext1 == '='
                             &&
                             (
                              chNext2.isNull()
                              ||
                              chNext2 == ' '
                             )
                            )
                           )
                          )
                          ||
                          (
                           chNext1 == '>'
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                            ||
                            (
                             chNext2 == '='
                             &&
                             (
                              chNext3.isNull()
                              ||
                              chNext3 == ' '
                             )
                            )
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                          ||
                          (
                           chNext1 == '='
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                          ||
                          line.lastIndexOf('<', j - 1) >= 0
                         )
                        )
                        &&
                        !
                        (
                         ch == '='
                         &&
                         (
                          (
                           (
                            chPrev1 == '-'
                            ||
                            chPrev1 == '+'
                            ||
                            chPrev1 == '*'
                            ||
                            chPrev1 == '/'
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
                           (
                            chPrev2.isNull()
                            ||
                            chPrev2 == ' '
                            ||
                            (
                             chPrev1 == '='
                             &&
                             chPrev2 == '='
                            )
                            ||
                            (
                             (
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
                             (
                              chPrev3.isNull()
                              ||
                              chPrev3 == ' '
                             )
                            )
                           )
                           &&
                           (
                            chNext1.isNull()
                            ||
                            chNext1 == ' '
                           )
                          )
                          ||
                          (
                           chNext1 == '='
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                            ||
                            chNext2 == '='
                            ||
                            chNext2 == '\"'
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                            ||
                            chPrev1 == '='
                           )
                          )
                         )
                        )
                        &&
                        !
                        (
                         ch == '&'
                         &&
                         (
                          chPrev1 == '>'
                          ||
                          chNext1 == '>'
                          ||
                          (
                           chPrev1 == '&'
                           &&
                           (
                            chPrev2.isNull()
                            ||
                            chPrev2 == ' '
                           )
                           &&
                           (
                            chNext1.isNull()
                            ||
                            chNext1 == ' '
                           )
                          )
                          ||
                          (
                           (
                            chNext1 == '&'
                            ||
                            chNext1 == '='
                           )
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                          ||
                          (
                           chNext1 == '/'
                           &&
                           chNext2 == '*'
                          )
                          ||
                          (
                           (
                            chPrev1 == '_'
                            ||
                            chPrev1.isLetterOrNumber()
                           )
                           &&
                           (
                            chNext1.isNull()
                            ||
                            chNext1 == ' '
                            ||
                            chNext1 == ')'
                           )
                          )
                          ||
                          (
                           (
                            chNext1 == '_'
                            ||
                            chNext1 == '('
                            ||
                            chNext1 == ')'
                            ||
                            chNext1.isLetter()
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                            ||
                            chPrev1 == '('
                            ||
                            chPrev1 == ')'
                           )
                          )
                         )
                        )
                        &&
                        !
                        (
                         ch == '|'
                         &&
                         (
                          (
                           chPrev1 == '|'
                           &&
                           (
                            chPrev2.isNull()
                            ||
                            chPrev2 == ' '
                           )
                           &&
                           (
                            chNext1.isNull()
                            ||
                            chNext1 == ' '
                           )
                          )
                          ||
                          (
                           (
                            chNext1 == '|'
                            ||
                            chNext1 == '='
                           )
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                         )
                        )
                        &&
                        !
                        (
                         ch == '^'
                         &&
                         (
                          (
                           chNext1 == '='
                           &&
                           (
                            chNext2.isNull()
                            ||
                            chNext2 == ' '
                           )
                           &&
                           (
                            chPrev1.isNull()
                            ||
                            chPrev1 == ' '
                           )
                          )
                         )
                        )
                        &&
                        !line.contains("regexp", Qt::CaseInsensitive)
                       )
                    {
                        worker->addWarning(path, i, QString("Whitespace is missing for operator '%1' in position %2").arg(ch).arg(j + 1));
                    }
                }



                if (
                    ch == '/'
                    &&
                    j < line.length() - 1
                    &&
                    line.at(j + 1) == '/'
                   )
                {
                    break;
                }
            }
        }
    }
}



PhpOperatorSpacesVerifier phpOperatorSpacesVerifierInstance;
