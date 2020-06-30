#ifndef BUILD_CONFIG_GUI_SRC_COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_BOOLEANPARAMETERWIDGET_H
#define BUILD_CONFIG_GUI_SRC_COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_BOOLEANPARAMETERWIDGET_H



#include "src/com/ngos/devtools/build_config_gui/widgets/parameters/parameterwidget.h"

#include "src/com/ngos/devtools/build_config_gui/widgets/common/trackingcheckbox.h"



class BooleanParameterWidget: public ParameterWidget
{
    Q_OBJECT

public:
    explicit BooleanParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent = 0); // TEST: NO

    void setValue(const QString &value) override; // TEST: NO

protected:
    QString generatePrivateDetails() override; // TEST: NO

private slots:
    void checkboxToggled(bool checked); // TEST: NO

private:
    TrackingCheckBox *mCheckBox;
    QString           mTrueValue;
    QString           mFalseValue;
    QString           mTrueDescription;
    QString           mFalseDescription;
};



#endif // BUILD_CONFIG_GUI_SRC_COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_BOOLEANPARAMETERWIDGET_H
