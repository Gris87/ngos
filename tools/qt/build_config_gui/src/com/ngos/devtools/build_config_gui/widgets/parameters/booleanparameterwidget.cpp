#include "booleanparameterwidget.h"

#include <QDebug>
#include <QRegularExpression>
#include <QVBoxLayout>



BooleanParameterWidget::BooleanParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent)
    : ParameterWidget(id, metaInformation, options, parent)
    , mCheckBox(nullptr)
    , mTrueValue()
    , mFalseValue()
    , mTrueDescription()
    , mFalseDescription()
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);



    mCheckBox = new TrackingCheckBox(mName, this);
    layout->addWidget(mCheckBox);



    QString metaValues           = metaInformation.value("Values");
    QString metaValueDescription = metaInformation.value("Value description");

    QRegularExpression valuesRegExp("^true *=(.*), *false *=(.*)$");



    QRegularExpressionMatch match = valuesRegExp.match(metaValues);

    if (match.hasMatch())
    {
        mTrueValue  = match.captured(1).trimmed();
        mFalseValue = match.captured(2).trimmed();
    }
    else
    {
        qCritical() << "Unexpected format for values" << metaValues << "specified for Boolean parameter" << mId;

        return;
    }



    match = valuesRegExp.match(metaValueDescription);

    if (match.hasMatch())
    {
        mTrueDescription  = match.captured(1).trimmed();
        mFalseDescription = match.captured(2).trimmed();
    }
    else
    {
        qCritical() << "Unexpected format for value descriptions" << metaValueDescription << "specified for Boolean parameter" << mId;

        return;
    }



    if (
        mDefault != mTrueValue
        &&
        mDefault != mFalseValue
       )
    {
        qCritical() << "Invalid default value" << mDefault << "specified for Boolean parameter" << mId;

        return;
    }



    if (mValue == mTrueValue)
    {
        mCheckBox->setChecked(true);
    }
    else
    if (mValue == mFalseValue)
    {
        mCheckBox->setChecked(false);
    }
    else
    {
        qCritical() << "Invalid value" << mValue << "specified for Boolean parameter" << mId;

        return;
    }



    connect(mCheckBox, SIGNAL(toggled(bool)), this, SLOT(checkboxToggled(bool)));
    connect(mCheckBox, SIGNAL(entered()),     this, SLOT(widgetEntered()));
    connect(mCheckBox, SIGNAL(leaved()),      this, SLOT(widgetLeaved()));
}

void BooleanParameterWidget::setValue(const QString &value)
{
    ParameterWidget::setValue(value);



    if (mValue == mTrueValue)
    {
        mCheckBox->setChecked(true);
    }
    else
    if (mValue == mFalseValue)
    {
        mCheckBox->setChecked(false);
    }
    else
    {
        qCritical() << "Invalid value" << mValue << "specified for Boolean parameter" << mId;

        return;
    }
}

QString BooleanParameterWidget::generatePrivateDetails()
{
    QString defaultValue;
    QString currentValue;

    QString trueValue  = QString("true  - %1")
                                    .arg(mTrueDescription);
    QString falseValue = QString("false - %1")
                                    .arg(mFalseDescription);

    trueValue  = trueValue.replace(' ',  "&nbsp;");
    falseValue = falseValue.replace(' ', "&nbsp;");


    if (mValue == mTrueValue)
    {
        currentValue = trueValue;
    }
    else
    if (mValue == mFalseValue)
    {
        currentValue = falseValue;
    }
    else
    {
        qCritical() << "Invalid value" << mValue << "specified for Boolean parameter" << mId;
    }



    if (mDefault == mTrueValue)
    {
        defaultValue = trueValue;
        trueValue    = "<b>" + trueValue + "</b>";
    }
    else
    if (mDefault == mFalseValue)
    {
        defaultValue = falseValue;
        falseValue   = "<b>" + falseValue + "</b>";
    }
    else
    {
        qCritical() << "Invalid default value" << mDefault << "specified for Boolean parameter" << mId;
    }



    return  "<h2>Values:</h2>" +
            trueValue + "<br>" +
            falseValue + "<br>" +
            "<br>" +
            "<b>Default:</b> " + defaultValue + "<br>" +
            "<b>Current:</b> " + currentValue;
}

void BooleanParameterWidget::checkboxToggled(bool checked)
{
    setValue(checked ? mTrueValue : mFalseValue);
}
