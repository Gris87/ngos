#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEFILEINFO_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEFILEINFO_H



#include <QString>

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



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



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEFILEINFO_H
