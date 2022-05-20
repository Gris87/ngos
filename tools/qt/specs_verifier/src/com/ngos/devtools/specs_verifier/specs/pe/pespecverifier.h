#ifndef PESPECVERIFIER_H                                                                                                                                                                                 // Colorize: green
#define PESPECVERIFIER_H                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/specs_verifier/specs/specverifier.h>                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QHash>                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class PeSpecVerifier: public SpecVerifier                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    PeSpecVerifier(); // TEST: NO                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void verify(SpecVerifyThread *thread) override; // TEST: NO                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    void checkWithSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                       // Colorize: green
    void checkPeSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                         // Colorize: green
    void checkPeHeader(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkPeHeaderSignature(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                       // Colorize: green
    void checkPeCoffHeader(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeCoffHeaderMachine(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeCoffHeaderCharacteristics(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeOptionalHeader(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeOptionalHeaderMagic(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeOptionalHeaderSubsystem(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeOptionalHeaderDllCharacteristics(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeDataDirectory(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeDataDirectoryType(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeSectionHeader(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
    void checkPeSectionHeaderCharacteristics(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QHash<QString, QString> mPeTypeToNgosTypeMap; // PE type => NGOS type                                                                                                                                // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // PESPECVERIFIER_H                                                                                                                                                                               // Colorize: green
