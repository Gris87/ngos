#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEMESSAGEINFO_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEMESSAGEINFO_H



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



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEMESSAGEINFO_H
