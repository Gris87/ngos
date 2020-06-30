#include "textparameterwidget.h"

#include <QDebug>
#include <QVBoxLayout>

#include "src/com/ngos/devtools/build_config_gui/widgets/common/trackinggroupbox.h"



TextParameterWidget::TextParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent)
    : ParameterWidget(id, metaInformation, options, parent)
    , mLineEdit(nullptr)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);



    TrackingGroupBox *groupBox = new TrackingGroupBox(mName, this);
    layout->addWidget(groupBox);



    QVBoxLayout *layout2 = new QVBoxLayout(groupBox);

    layout2->setSpacing(4);
    layout2->setContentsMargins(4, 4, 4, 4);



    QString newValue = mValue;

    if (
        newValue.length() > 1
        &&
        newValue.startsWith('\"')
        &&
        newValue.endsWith('\"')
       )
    {
        newValue = newValue.mid(1, newValue.length() - 2);
    }



    mLineEdit = new TrackingLineEdit(newValue, groupBox);
    layout2->addWidget(mLineEdit);



    connect(mLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(lineEditTextChanged(const QString &)));
    connect(mLineEdit, SIGNAL(entered()),                    this, SLOT(widgetEntered()));
    connect(mLineEdit, SIGNAL(leaved()),                     this, SLOT(widgetLeaved()));
    connect(groupBox,  SIGNAL(entered()),                    this, SLOT(widgetEntered()));
    connect(groupBox,  SIGNAL(leaved()),                     this, SLOT(widgetLeaved()));
}

void TextParameterWidget::setValue(const QString &value)
{
    QString newValue = value;

    if (
        newValue.length() > 1
        &&
        newValue.startsWith('\"')
        &&
        newValue.endsWith('\"')
       )
    {
        newValue = newValue.mid(1, newValue.length() - 2);
    }

    ParameterWidget::setValue('\"' + newValue + '\"');



    mLineEdit->setText(newValue);
}

QString TextParameterWidget::generatePrivateDetails()
{
    return  "<h2>Values:</h2>"
            "<b>Default:</b> " + mDefault + "<br>" +
            "<b>Current:</b> " + mValue;
}

void TextParameterWidget::lineEditTextChanged(const QString &text)
{
    setValue(text);
}
