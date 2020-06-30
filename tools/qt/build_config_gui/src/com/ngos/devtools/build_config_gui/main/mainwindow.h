#ifndef BUILD_CONFIG_GUI_SRC_COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_MAIN_MAINWINDOW_H
#define BUILD_CONFIG_GUI_SRC_COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_MAIN_MAINWINDOW_H



#include <QMainWindow>

#include <QCloseEvent>
#include <QHash>
#include <QTreeWidgetItem>

#include "src/com/ngos/devtools/build_config_gui/other/optioninfo.h"
#include "src/com/ngos/devtools/build_config_gui/widgets/parameters/parameterwidget.h"



namespace Ui
{
    class MainWindow;
}



class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); // TEST: NO
    ~MainWindow(); // TEST: NO

    void loadBuildConfigFile(); // TEST: NO

protected:
    void closeEvent(QCloseEvent *event) override; // TEST: NO

private slots:
    void on_actionReload_triggered(); // TEST: NO
    void on_actionSave_triggered(); // TEST: NO
    void on_actionExit_triggered(); // TEST: NO
    void on_actionAbout_triggered(); // TEST: NO
    void on_actionReset_triggered(); // TEST: NO
    void on_categoriesTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous); // TEST: NO

    void parameterValueChanged(); // TEST: NO
    void parameterDetailsUpdated(const QString &details); // TEST: NO

private:
    void parseBuildConfigFile(const QStringList &lines); // TEST: NO
    void buildParameters(const QHash<QString, QHash<QString, QString>> &parameters, const QStringList &parametersIds); // TEST: NO

    void saveWindowState(); // TEST: NO
    void loadWindowState(); // TEST: NO

    Ui::MainWindow                    *ui;
    QHash<QString, OptionInfo>         mOptions;
    QHash<QString, ParameterWidget *>  mParameters;
};



#endif // BUILD_CONFIG_GUI_SRC_COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_MAIN_MAINWINDOW_H
