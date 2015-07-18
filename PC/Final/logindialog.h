#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "LoginManager.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void confirm_clicked();
    void cancel_clicked();

private:
    Ui::LoginDialog *ui;
    QLineEdit *name_line;
    QLineEdit *password_line;
    QPushButton *confirm_button;
    QPushButton *cancel_button;
    QLabel *name_label;
    QLabel *password_label;

    LoginManager loginManager_;
};

#endif // LOGINDIALOG_H
