#include <QtGui>
#include <QGroupBox>
#include <QComboBox>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QSpinBox>
#include <QStackedWidget>
#include <QPixmap>
#include <QPalette>

#include "configdialog.h"
#include "homepage.h"
#include "userpage.h"
#include "equipmentpage.h"
#include "orderpage.h"
#include <iostream>
using namespace std;
extern string current_user;

ConfigDialog::ConfigDialog()
{
    contentsWidget = new QListWidget;
    contentsWidget->setViewMode(QListView::IconMode);
    contentsWidget->setIconSize(QSize(96, 84));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setMaximumWidth(128);
    contentsWidget->setSpacing(12);

    pagesWidget = new QStackedWidget;
    pagesWidget->resize(500,500);
    pagesWidget->addWidget(new HomePage);
    pagesWidget->addWidget(new OrderPage);
    pagesWidget->addWidget(new EquipmentPage);

    if (current_user == "admin") pagesWidget->addWidget(new UserPage);

    QPushButton *closeButton = new QPushButton(tr("退出"));
    closeButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

    QLabel *logo_label = new QLabel(this);
    logo_label->setText("中山大学软件学院C.C.C团队制作.");
    QLabel *hello_label = new QLabel(this);
    string hello_line = current_user + ",  你好!";
    hello_label->setText(QString::fromStdString(hello_line));
    hello_label->setGeometry(QRect(QPoint(670, 0), QSize(100, 40)));


    createIcons();
    contentsWidget->setCurrentRow(0);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(contentsWidget);
    horizontalLayout->addWidget(pagesWidget, 1);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(logo_label);
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(closeButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    this->setAutoFillBackground(true);
    this->setWindowTitle(tr("111"));

    QPalette palette;
    QPixmap pixmap("image/background.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    setWindowTitle(tr("Config Dialog"));
    setFixedSize(800, 494);
}

void ConfigDialog::createIcons()
{
    QListWidgetItem *configButton = new QListWidgetItem(contentsWidget);
    configButton->setIcon(QIcon(":/images/config.png"));
    configButton->setText(tr("        主页       "));
    configButton->setTextAlignment(Qt::AlignHCenter);
    configButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *updateButton = new QListWidgetItem(contentsWidget);
    updateButton->setIcon(QIcon("image/order.jpg"));
    updateButton->setText(tr("信息"));
    updateButton->setTextAlignment(Qt::AlignHCenter);
    updateButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *queryButton = new QListWidgetItem(contentsWidget);
    queryButton->setIcon(QIcon("image/equipment.jpg"));
    queryButton->setText(tr("器材"));
    queryButton->setTextAlignment(Qt::AlignHCenter);
    queryButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    if (current_user == "admin") {
    QListWidgetItem *userButton = new QListWidgetItem(contentsWidget);
    userButton->setIcon(QIcon("image/user.jpg"));
    userButton->setText(tr("用户"));
    userButton->setTextAlignment(Qt::AlignHCenter);
    userButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    }

    connect(contentsWidget,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
}

void ConfigDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    pagesWidget->setCurrentIndex(contentsWidget->row(current));
}
