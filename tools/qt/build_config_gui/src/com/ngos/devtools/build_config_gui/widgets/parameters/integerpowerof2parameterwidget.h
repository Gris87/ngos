#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_INTEGERPOWEROF2PARAMETERWIDGET_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_INTEGERPOWEROF2PARAMETERWIDGET_H



#include <com/ngos/devtools/build_config_gui/widgets/parameters/parameterwidget.h>

#include <com/ngos/devtools/build_config_gui/widgets/common/trackingcombobox.h>



class IntegerPowerOf2ParameterWidget: public ParameterWidget
{
    Q_OBJECT

public:
    explicit IntegerPowerOf2ParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent = nullptr); // TEST: NO

    void setValue(const QString &value) override; // TEST: NO

protected:
    QString generatePrivateDetails() override; // TEST: NO

private slots:
    void comboboxCurrentIndexChanged(qint32 index); // TEST: NO

private:
    TrackingComboBox *mComboBox;
    QString           mMinimum;
    QString           mMaximum;
    QStringList       mOptionsList;
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_INTEGERPOWEROF2PARAMETERWIDGET_H
