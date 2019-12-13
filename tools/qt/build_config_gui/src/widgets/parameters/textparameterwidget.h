#ifndef BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_TEXTPARAMETERWIDGET_H
#define BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_TEXTPARAMETERWIDGET_H



#include "src/widgets/parameters/parameterwidget.h"

#include "src/widgets/common/trackinglineedit.h"



class TextParameterWidget: public ParameterWidget
{
    Q_OBJECT

public:
    explicit TextParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent = 0); // TEST: NO

    void setValue(const QString &value) override; // TEST: NO

protected:
    QString generatePrivateDetails() override; // TEST: NO

private slots:
    void lineEditTextChanged(const QString &text); // TEST: NO

private:
    TrackingLineEdit *mLineEdit;
};



#endif // BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_TEXTPARAMETERWIDGET_H
