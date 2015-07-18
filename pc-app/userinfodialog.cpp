#include "userinfodialog.h"
#include <QString>
UserInfoDialog::UserInfoDialog(QWidget *parent)
    :QDialog(parent)
{
    user_name_line = new QLineEdit(this);
    user_name_line->setGeometry(QRect(QPoint(150, 20), QSize(200, 30)));

    user_password_line = new QLineEdit(this);
    user_password_line->setGeometry(QRect(QPoint(150, 60), QSize(200, 30)));

    student_id_line = new QLineEdit(this);
    student_id_line->setGeometry(QRect(QPoint(150, 100), QSize(200, 30)));

    student_phone_line = new QLineEdit(this);
    student_phone_line->setGeometry(QRect(QPoint(150, 140), QSize(200, 30)));

    user_name_label = new QLabel(this);
    user_name_label->setGeometry(QRect(QPoint(40, 20), QSize(80, 30)));
    user_name_label->setText("用户");

    user_password_label = new QLabel(this);
    user_password_label->setGeometry(QRect(QPoint(40, 60), QSize(80, 30)));
    user_password_label->setText("密码");

    student_id_label = new QLabel(this);
    student_id_label->setGeometry(QRect(QPoint(40, 100), QSize(80, 30)));
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

void UserInfoDialog::init() {
    user_name_line->setText(QString::fromStdString(userName_));
    user_password_line->setText(QString::fromStdString(password_));
    student_id_line->setText(QString::fromStdString(studentId_));
    student_phone_line->setText(QString::fromStdString(studentPhone_));
}

string UserInfoDialog::getName() {
    return userName_;
}

void UserInfoDialog::setName(string name) {
    userName_ = name;
}

string UserInfoDialog::getPassword() {
    return password_;
}

void UserInfoDialog::setPassword(string password){
    password_ = password;
}

string UserInfoDialog::getStudentPhone() {
    return studentPhone_;
}

void UserInfoDialog::setStudentPhone(string phone) {
    studentPhone_ = phone;
}

string UserInfoDialog::getStudentId() {
    return studentId_;
}

void UserInfoDialog::setStudentId(string id) {
    studentId_ = id;
}

void UserInfoDialog::confirm_clicked()
{
    userName_ = user_name_line->text().toStdString();
    password_ = user_password_line->text().toStdString();
    studentId_ = student_id_line->text().toStdString();
    studentPhone_ = student_phone_line->text().toStdString();
    accept();
}

void UserInfoDialog::cancel_clicked()
{
    reject();
}

