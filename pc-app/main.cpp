#include "configdialog.h"
#include "logindialog.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <string>

QSqlDatabase conn;
QSqlQuery query;

std::string current_user;
std::string role;

int main(int argc, char *argv[])
{
    conn = QSqlDatabase::addDatabase("QMYSQL");
    conn.setHostName("localhost");
    conn.setDatabaseName("test");
    conn.setUserName("root");
    conn.setPassword("CAISHUPENG");
    if(!conn.open()) {
        QMessageBox::critical(0,QObject::tr("Database Error"),conn.lastError().text());
    }else {
        query = QSqlQuery(conn);
    }

    QApplication a(argc, argv);
    LoginDialog login;
    login.setWindowTitle("登录");
    if(login.exec() == QDialog::Accepted){
        ConfigDialog dialog;
        dialog.setWindowTitle("实验室器材管理中心");
        return dialog.exec();
    }
    return 0;
}
