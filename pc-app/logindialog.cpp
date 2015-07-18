#include <QMessageBox>
#include <QPixmap>
#include <QPalette>
#include <iostream>
using namespace std;

#include "logindialog.h"
#include "ui_logindialog.h"

extern string current_user;

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    this->setWindowTitle(tr("Login Dialog"));
    ui->setupUi(this);

    name_line = new QLineEdit(this);
    name_line->setGeometry(QRect(QPoint(140, 70), QSize(200, 30)));

    password_line = new QLineEdit(this);
    password_line->setEchoMode(QLineEdit::Password);
    password_line->setGeometry(QRect(QPoint(140, 140), QSize(200, 30)));

    name_label = new QLabel(this);
    name_label->setGeometry(QRect(QPoint(50, 70), QSize(80, 30)));
    name_label->setText("用户");

    password_label = new QLabel(this);
    password_label->setGeometry(QRect(QPoint(50, 140), QSize(80, 30)));
    password_label->setText("密码");

    cancel_button = new QPushButton("Button", this);
    cancel_button->setGeometry(QRect(QPoint(100, 220), QSize(80, 30)));
    cancel_button->setText("取消");
    connect(cancel_button, SIGNAL(clicked()), this, SLOT(cancel_clicked()));

    confirm_button = new QPushButton("Button", this);
    confirm_button->setGeometry(QRect(QPoint(250, 220), QSize(80, 30)));
    confirm_button->setText("确定");
    connect(confirm_button, SIGNAL(clicked()), this, SLOT(confirm_clicked()));

    QPalette palette;
    QPixmap pixmap("image/background.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::confirm_clicked()
{
    string name, password;

    name = this->name_line->text().toStdString();
    password = this->password_line->text().toStdString();

    if (loginManager_.isAdmin(name, password)) {
        current_user = name;
        accept();
    }else if (loginManager_.isUser(name, password)) {
        current_user = name;
        accept();
    }else {
        QMessageBox::warning(this,tr("Warnning"),tr("用户或密码错误!"),QMessageBox::Yes);
        this->name_line->clear();
        this->password_line->clear();
    }
}

void LoginDialog::cancel_clicked()
{
    conn.close();
    reject();
}
