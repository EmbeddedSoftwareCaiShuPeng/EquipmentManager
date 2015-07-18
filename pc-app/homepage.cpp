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
#include <QPixmap>

#include "homepage.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label = new QLabel(this);
    label->setPixmap(QPixmap("image/homePage.png"));
    label->setGeometry(QRect(QPoint(0, 0), QSize(800, 400)));
    QGroupBox *ruleGroup = new QGroupBox(tr(""));
    QLabel *rule1 = new QLabel(tr(""));
    QLabel *rule2 = new QLabel(tr(""));
    QLabel *rule3 = new QLabel(tr(""));
    QLabel *rule4 = new QLabel(tr(""));
    QLabel *rule5 = new QLabel(tr(""));
    QLabel *rule6 = new QLabel(tr(""));
    QLabel *rule7 = new QLabel();
    QLabel *rule8 = new QLabel(tr(""));
    QLabel *rule9 = new QLabel(tr(""));
    QLabel *rule11 = new QLabel(tr(""));
    QLabel *rule12 = new QLabel(tr(""));
    QLabel *rule13 = new QLabel(tr(""));
    QLabel *rule14 = new QLabel(tr(""));
    QLabel *rule15 = new QLabel(tr(""));
    QLabel *rule16 = new QLabel(tr(""));
    QLabel *rule17 = new QLabel(tr(""));
    QLabel *rule18 = new QLabel(tr(""));
    QLabel *rule19 = new QLabel(tr(""));

    QVBoxLayout *updateLayout = new QVBoxLayout;
    updateLayout->addWidget(rule1);
    updateLayout->addWidget(rule2);
    updateLayout->addWidget(rule3);
    updateLayout->addWidget(rule4);
    updateLayout->addWidget(rule5);
    updateLayout->addWidget(rule6);
    updateLayout->addWidget(rule7);
    updateLayout->addWidget(rule8);
    updateLayout->addWidget(rule9);
    updateLayout->addWidget(rule11);
    updateLayout->addWidget(rule12);
    updateLayout->addWidget(rule13);
    updateLayout->addWidget(rule14);
    updateLayout->addWidget(rule15);
    updateLayout->addWidget(rule16);
    updateLayout->addWidget(rule17);
    updateLayout->addWidget(rule18);
    updateLayout->addWidget(rule19);
    ruleGroup->setLayout(updateLayout);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(ruleGroup);
    mainLayout->addSpacing(12);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}



