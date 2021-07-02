#ifndef ELFSPECVERIFIER_H                                                                                                                                                                                // Colorize: green
#define ELFSPECVERIFIER_H                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/specs_verifier/specs/specverifier.h>                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QHash>                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class ElfSpecVerifier: public SpecVerifier                                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    ElfSpecVerifier(); // TEST: NO                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void verify(SpecVerifyThread *thread) override; // TEST: NO                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    void checkWithSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                       // Colorize: green
    void checkElfHeader(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkElfHeaderIdentification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                 // Colorize: green
    void checkElfClass(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfData(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                 // Colorize: green
    void checkElfFileVersion(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                          // Colorize: green
    void checkElfVersion(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                          // Colorize: green
    void checkElfOsAbi(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfType(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfMachine(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfSectionHeaderTableEntry(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfSectionTypes(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfSectionFlags(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfSymbol(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfSymbolInfo(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfSymbolBind(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfSymbolType(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfSymbolOther(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
    void checkElfSymbolVisibility(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QHash<QString, QString> mElfTypeToNgosTypeMap; // ELF type => NGOS type                                                                                                                              // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // ELFSPECVERIFIER_H                                                                                                                                                                              // Colorize: green
