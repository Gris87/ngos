#include "parameterwidget.h"



ParameterWidget *ParameterWidget::sHoveredWidget;



ParameterWidget::ParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &/*options*/, QWidget *parent)
    : QWidget(parent)
    , mId(id)
    , mName(metaInformation.value("Name"))
    , mDescription(metaInformation.value("Description"))
    , mEnabled(metaInformation.value("Enabled"))
    , mDefault(metaInformation.value("Default"))
    , mValue(metaInformation.value("Value"))
{
    if (mDefault != mValue)
    {
        QFont font;
        font.setBold(true);
        setFont(font);
    }
}

void ParameterWidget::setValue(const QString &value)
{
    if (mValue != value)
    {
        mValue = value;



        QFont font;

        if (mDefault != mValue)
        {
            font.setBold(true);
        }

        setFont(font);



        if (sHoveredWidget)
        {
            emit detailsUpdated(sHoveredWidget->generateDetails());
        }

        emit valueChanged();
    }
}

QString ParameterWidget::value() const
{
    return mValue;
}

void ParameterWidget::reset()
{
    if (mValue != mDefault)
    {
        setValue(mDefault);
    }
}

void ParameterWidget::handleValueChanged(const QHash<QString, ParameterWidget *> &parameters)
{
    if (mEnabled != "")
    {
        QHashIterator<QString, ParameterWidget *> it(parameters);

        while (it.hasNext())
        {
            it.next();

            QString id = it.key();

            if (mEnabled.startsWith(id + " == "))
            {
                QString value = mEnabled.mid(id.length() + 4).trimmed();

                setEnabled(value == it.value()->value());

                break;
            }
        }
    }
}

void ParameterWidget::widgetEntered()
{
    sHoveredWidget = this;

    emit detailsUpdated(generateDetails());
}

void ParameterWidget::widgetLeaved()
{
    sHoveredWidget = nullptr;

    emit detailsUpdated("");
}

QString ParameterWidget::generatePrivateDetails()
{
    return "";
}

QString ParameterWidget::generateDetails()
{
    return  "<h1>" + mName + "</h1>" +
            "<h2><b>Description:</b></b></h2>" +
            mDescription.replace('\n', "<br>") +
            generatePrivateDetails();
}
