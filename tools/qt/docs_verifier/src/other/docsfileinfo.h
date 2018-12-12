#ifndef DOCS_VERIFIER_SRC_OTHER_DOCSFILEINFO_H
#define DOCS_VERIFIER_SRC_OTHER_DOCSFILEINFO_H



#include <QString>

#include "src/other/docsverificationfiletype.h"



class DocsFileInfo
{
public:
    DocsFileInfo(const QString &path, VerificationFileType verificationFileType); // TEST: NO

    QString getPath() const; // TEST: NO
    VerificationFileType getVerificationFileType() const; // TEST: NO

private:
    QString              mPath;
    VerificationFileType mVerificationFileType;
};



#endif // DOCS_VERIFIER_SRC_OTHER_DOCSFILEINFO_H
