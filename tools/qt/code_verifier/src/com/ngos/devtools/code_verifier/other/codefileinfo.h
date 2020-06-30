#ifndef CODE_VERIFIER_SRC_OTHER_CODEFILEINFO_H
#define CODE_VERIFIER_SRC_OTHER_CODEFILEINFO_H



#include <QString>

#include "src/other/codeverificationfiletype.h"



class CodeFileInfo
{
public:
    CodeFileInfo(const QString &path, CodeVerificationFileType verificationFileType); // TEST: NO

    QString getPath() const; // TEST: NO
    CodeVerificationFileType getVerificationFileType() const; // TEST: NO

private:
    QString                  mPath;
    CodeVerificationFileType mVerificationFileType;
};



#endif // CODE_VERIFIER_SRC_OTHER_CODEFILEINFO_H
