#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_USBBOOTMAKERGENERATOR_H                                                                                                               // Colorize: green
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_USBBOOTMAKERGENERATOR_H                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/code_generator/generators/generator.h>                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QList>                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class UsbBootMakerGenerator: public Generator                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    UsbBootMakerGenerator(); // TEST: NO                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static bool generateAll(const QString &path); // TEST: NO                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
protected:                                                                                                                                                                                               // Colorize: green
    virtual bool generate(const QString &path) = 0; // TEST: NO                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    static QList<UsbBootMakerGenerator *> sGenerators;                                                                                                                                                   // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_USBBOOTMAKERGENERATOR_H                                                                                                             // Colorize: green
