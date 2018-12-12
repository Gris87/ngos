#ifndef BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_COMBOBOXPARAMETERWIDGET_H
#define BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_COMBOBOXPARAMETERWIDGET_H



#include "src/widgets/parameters/parameterwidget.h"

#include "src/widgets/common/trackingcombobox.h"



class ComboboxParameterWidget : public ParameterWidget
{
    Q_OBJECT

public:
    explicit ComboboxParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent = 0); // TEST: NO

    void setValue(const QString &value) override; // TEST: NO

protected:
    QString generatePrivateDetails() override; // TEST: NO

private slots:
    void comboboxCurrentIndexChanged(qint32 index); // TEST: NO

private:
    TrackingComboBox        *mComboBox;
    QHash<QString, QString>  mOptionsDescriptions;
    QStringList              mOptionsList;
};



#endif // BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_COMBOBOXPARAMETERWIDGET_H
