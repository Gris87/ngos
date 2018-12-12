#include "categorytreewidgetitem.h"

#include <QLabel>



CategoryTreeWidgetItem::CategoryTreeWidgetItem(const QString &title, QWidget *parent)
    : QTreeWidgetItem(QStringList() << title)
    , mPage(new QScrollArea(parent))
{
    QWidget *scrollAreaWidgetContents = new QWidget(parent);
    mPage->setWidgetResizable(true);
    mPage->setWidget(scrollAreaWidgetContents);



    QVBoxLayout *layout = new QVBoxLayout(scrollAreaWidgetContents);

    layout->setSpacing(4);
    layout->setContentsMargins(4, 4, 4, 4);



    mLayout = new QVBoxLayout();

    mLayout->setSpacing(4);
    mLayout->setContentsMargins(0, 0, 0, 0);

    layout->addLayout(mLayout);
    layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));



    QLabel *titleLabel = new QLabel(title, mPage);

    QFont font;
    font.setPointSize(16);
    titleLabel->setFont(font);

    mLayout->addWidget(titleLabel);
}

QScrollArea* CategoryTreeWidgetItem::getPage() const
{
    return mPage;
}

QVBoxLayout* CategoryTreeWidgetItem::getLayout() const
{
    return mLayout;
}
