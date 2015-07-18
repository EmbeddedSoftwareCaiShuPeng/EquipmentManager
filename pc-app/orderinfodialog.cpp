#include <QString>

#include "orderinfodialog.h"


OrderInfoDialog::OrderInfoDialog(QWidget *parent)
    :QDialog(parent)
{
    equipment_id_line = new QLineEdit(this);
    equipment_id_line->setGeometry(QRect(QPoint(150, 20), QSize(200, 30)));

    student_id_line = new QLineEdit(this);
    student_id_line->setGeometry(QRect(QPoint(150, 80), QSize(200, 30)));

    student_phone_line = new QLineEdit(this);
    student_phone_line->setGeometry(QRect(QPoint(150, 140), QSize(200, 30)));

    equipment_id_label = new QLabel(this);
    equipment_id_label->setGeometry(QRect(QPoint(40, 20), QSize(120, 30)));
    equipment_id_label->setText("器材Id");

    student_id_label = new QLabel(this);
    student_id_label->setGeometry(QRect(QPoint(40, 80), QSize(80, 30)));
    student_id_label->setText("学生Id");

    student_phone_label = new QLabel(this);
    student_phone_label->setGeometry(QRect(QPoint(40, 140), QSize(120, 30)));
    student_phone_label->setText("手机");

    cancel_button = new QPushButton("Button", this);
    cancel_button->setGeometry(QRect(QPoint(80, 210), QSize(80, 30)));
    cancel_button->setText("取消");
    connect(cancel_button, SIGNAL(clicked()), this, SLOT(cancel_clicked()));

    confirm_button = new QPushButton("Button", this);
    confirm_button->setGeometry(QRect(QPoint(220, 210), QSize(80, 30)));
    confirm_button->setText("确定");
    connect(confirm_button, SIGNAL(clicked()), this, SLOT(confirm_clicked()));
}

string OrderInfoDialog::getStudentId() {
    return studentId_;
}

string OrderInfoDialog::getStudentPhone() {
    return studentPhone_;
}

string OrderInfoDialog::getEquipmentId() {
    return equipmentId_;
}


void OrderInfoDialog::confirm_clicked()
{
    equipmentId_ = equipment_id_line->text().toStdString();
    studentId_ = student_id_line->text().toStdString();
    studentPhone_ = student_phone_line->text().toStdString();
    accept();
}

void OrderInfoDialog::cancel_clicked()
{
    reject();
}
