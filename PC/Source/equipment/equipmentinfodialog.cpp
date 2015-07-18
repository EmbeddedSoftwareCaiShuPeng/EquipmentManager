#include "equipmentinfodialog.h"
#include <QString>
EquipmentInfoDialog::EquipmentInfoDialog(QWidget *parent)
    :QDialog(parent)
{
    id_line = new QLineEdit(this);
    id_line->setGeometry(QRect(QPoint(150, 20), QSize(200, 30)));

    name_line = new QLineEdit(this);
    name_line->setGeometry(QRect(QPoint(150, 60), QSize(200, 30)));

    type_line = new QLineEdit(this);
    type_line->setGeometry(QRect(QPoint(150, 100), QSize(200, 30)));

    state_line = new QLineEdit(this);
    state_line->setGeometry(QRect(QPoint(150, 140), QSize(200, 30)));

    id_label = new QLabel(this);
    id_label->setGeometry(QRect(QPoint(40, 20), QSize(80, 30)));
    id_label->setText("器材Id");

    name_label = new QLabel(this);
    name_label->setGeometry(QRect(QPoint(40, 60), QSize(80, 30)));
    name_label->setText("器材名");

    type_label = new QLabel(this);
    type_label->setGeometry(QRect(QPoint(40, 100), QSize(80, 30)));
    type_label->setText("器材类型");

    state_label = new QLabel(this);
    state_label->setGeometry(QRect(QPoint(40, 140), QSize(120, 30)));
    state_label->setText("器材状态");

    cancel_button = new QPushButton("Button", this);
    cancel_button->setGeometry(QRect(QPoint(80, 210), QSize(80, 30)));
    cancel_button->setText("取消");
    connect(cancel_button, SIGNAL(clicked()), this, SLOT(cancel_clicked()));

    confirm_button = new QPushButton("Button", this);
    confirm_button->setGeometry(QRect(QPoint(220, 210), QSize(80, 30)));
    confirm_button->setText("确定");
    connect(confirm_button, SIGNAL(clicked()), this, SLOT(confirm_clicked()));
}

void EquipmentInfoDialog::init() {
    id_line->setText(QString::fromStdString(id_));
    name_line->setText(QString::fromStdString(name_));
    type_line->setText(QString::fromStdString(type_));
    state_line->setText(QString::fromStdString(state_));
}

string EquipmentInfoDialog::getName() {
    return name_;
}

void EquipmentInfoDialog::setName(string name) {
    name_ = name;
}

string EquipmentInfoDialog::getId() {
    return id_;
}

void EquipmentInfoDialog::setId(string id) {
    id_ = id;
}

string EquipmentInfoDialog::getType() {
    return type_;
}

void EquipmentInfoDialog::setType(string type) {
    type_ = type;
}

string EquipmentInfoDialog::getState() {
    return state_;
}

void EquipmentInfoDialog::setState(string state) {
    state_ = state;
}

void EquipmentInfoDialog::confirm_clicked()
{
    id_ = id_line->text().toStdString();
    name_ = name_line->text().toStdString();
    type_ = type_line->text().toStdString();
    state_ = state_line->text().toStdString();
    accept();
}

void EquipmentInfoDialog::cancel_clicked()
{
    reject();
}


