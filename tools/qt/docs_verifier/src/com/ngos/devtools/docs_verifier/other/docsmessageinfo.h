#ifndef DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_OTHER_DOCSMESSAGEINFO_H
#define DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_OTHER_DOCSMESSAGEINFO_H



#include <QString>



class DocsMessageInfo
{
public:
    DocsMessageInfo(const QString &path, qint64 line, const QString &message); // TEST: NO

    bool operator<(const DocsMessageInfo &another) const; // TEST: NO
    bool operator==(const DocsMessageInfo &another) const; // TEST: NO

    QString toString() const; // TEST: NO

private:
    QString mPath;
    qint64  mLine;
    QString mMessage;
};



#endif // DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_OTHER_DOCSMESSAGEINFO_H
