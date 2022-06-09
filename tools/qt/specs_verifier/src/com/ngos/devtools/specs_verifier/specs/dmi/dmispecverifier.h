#ifndef DMISPECVERIFIER_H                                                                                                                                                                                // Colorize: green
#define DMISPECVERIFIER_H                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/specs_verifier/specs/specverifier.h>                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QHash>                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class DmiSpecVerifier: public SpecVerifier                                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    DmiSpecVerifier(); // TEST: NO                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void verify(SpecVerifyThread *thread) override; // TEST: NO                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    bool downloadSpecification(SpecVerifyThread *thread, const QString &url, QString &specContent); // TEST: NO                                                                                                                           // Colorize: green
    void checkWithSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                       // Colorize: green
    void checkDmiSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiEntryHeader(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiStringId(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiBiosEntry(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiBiosRomSize(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiBiosCharacteristics(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiBiosCharacteristicsBiosReserved(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiBiosCharacteristicsSystemReserved(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiBiosExtendedRomSize(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiBiosExtendedRomSizeUnit(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiSystemEntry(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
    void checkDmiSystemWakeUpType(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QHash<QString, QString> mDmiTypeToNgosTypeMap; // DMI type => NGOS type                                                                                                                              // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // DMISPECVERIFIER_H                                                                                                                                                                              // Colorize: green
