#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_MAIN_MAINWINDOW_H                                                                                                                                             // Colorize: green
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_MAIN_MAINWINDOW_H                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QMainWindow>                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QCloseEvent>                                                                                                                                                                                   // Colorize: green
#include <QHash>                                                                                                                                                                                         // Colorize: green
#include <QTreeWidgetItem>                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/build_config_gui/other/optioninfo.h>                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/build_config_gui/widgets/categorytreewidgetitem.h>                                                                                                                           // Colorize: green
#include <com/ngos/devtools/build_config_gui/widgets/parameters/parameterwidget.h>                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
namespace Ui                                                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    class MainWindow;                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class MainWindow: public QMainWindow                                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_OBJECT                                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    explicit MainWindow(QWidget *parent = nullptr); // TEST: NO                                                                                                                                          // Colorize: green
    ~MainWindow(); // TEST: NO                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
protected:                                                                                                                                                                                               // Colorize: green
    void closeEvent(QCloseEvent *event) override; // TEST: NO                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private slots:                                                                                                                                                                                           // Colorize: green
    void on_actionReload_triggered(); // TEST: NO                                                                                                                                                        // Colorize: green
    void on_actionSave_triggered(); // TEST: NO                                                                                                                                                          // Colorize: green
    void on_actionExit_triggered(); // TEST: NO                                                                                                                                                          // Colorize: green
    void on_actionAbout_triggered(); // TEST: NO                                                                                                                                                         // Colorize: green
    void on_actionReset_triggered(); // TEST: NO                                                                                                                                                         // Colorize: green
    void on_categoriesTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous); // TEST: NO                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void parameterValueChanged(); // TEST: NO                                                                                                                                                            // Colorize: green
    void parameterDetailsUpdated(const QString &details); // TEST: NO                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    void loadBuildConfigFile(); // TEST: NO                                                                                                                                                              // Colorize: green
    void parseBuildConfigFile(const QStringList &lines); // TEST: NO                                                                                                                                     // Colorize: green
    void buildParameters(const QHash<QString, QHash<QString, QString>> &parameters, const QStringList &parametersIds); // TEST: NO                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    CategoryTreeWidgetItem* getOrCreateTopCategoryItem(const QString &topCategory); // TEST: NO                                                                                                                                    // Colorize: green
    CategoryTreeWidgetItem* getOrCreateSubCategoryItem(CategoryTreeWidgetItem *categoryItem, const QString &subCategory); // TEST: NO                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void saveWindowState(); // TEST: NO                                                                                                                                                                  // Colorize: green
    void loadWindowState(); // TEST: NO                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    Ui::MainWindow                    *ui;                                                                                                                                                               // Colorize: green
    QHash<QString, OptionInfo>         mOptions;    // Option ID => Option                                                                                                                                                      // Colorize: green
    QHash<QString, ParameterWidget *>  mParameters; // Parameter ID => Parameter Widget                                                                                                                                                     // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_MAIN_MAINWINDOW_H                                                                                                                                           // Colorize: green
