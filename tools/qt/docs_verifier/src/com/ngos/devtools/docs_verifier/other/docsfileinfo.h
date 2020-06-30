#ifndef DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_OTHER_DOCSFILEINFO_H
#define DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_OTHER_DOCSFILEINFO_H



#include <QString>

#include "src/com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h"



class DocsFileInfo
{
public:
    DocsFileInfo(const QString &path, DocsVerificationFileType verificationFileType); // TEST: NO

    QString getPath() const; // TEST: NO
    DocsVerificationFileType getVerificationFileType() const; // TEST: NO

private:
    QString                  mPath;
    DocsVerificationFileType mVerificationFileType;
};



#endif // DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_OTHER_DOCSFILEINFO_H
