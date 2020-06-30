#ifndef CODE_VERIFIER_SRC_OTHER_CODEMESSAGEINFO_H
#define CODE_VERIFIER_SRC_OTHER_CODEMESSAGEINFO_H



#include <QString>



class CodeMessageInfo
{
public:
    CodeMessageInfo(const QString &path, qint64 line, const QString &message); // TEST: NO

    bool operator<(const CodeMessageInfo &another) const; // TEST: NO
    bool operator==(const CodeMessageInfo &another) const; // TEST: NO

    QString toString() const; // TEST: NO

private:
    QString mPath;
    qint64  mLine;
    QString mMessage;
};



#endif // CODE_VERIFIER_SRC_OTHER_CODEMESSAGEINFO_H
