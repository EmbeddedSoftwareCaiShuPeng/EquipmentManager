#include "userpage.h"
#include "userinfodialog.h"

#include <QMessageBox>
#include <QFont>
#include <string>
using std::string;


UserPage::UserPage(QWidget *parent)
    : QWidget(parent)
{
    userManager_ = new UserManager();

    search_line = new QLineEdit(this);
    search_line->setGeometry(QRect(QPoint(30, 10), QSize(320, 30)));

    search_button = new QPushButton("搜索", this);
    search_button->setGeometry(QRect(QPoint(360, 10), QSize(90, 28)));
    search_button->setIcon(QIcon("image/search.jpg"));
    search_button->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    connect(search_button, SIGNAL(clicked()), this, SLOT(search_clicked()));

    add_button = new QPushButton("添加", this);
    add_button->setGeometry(QRect(QPoint(510, 100), QSize(100, 61)));
    //add_button->setIcon(QIcon("image/add.jpg"));
    add_button->setFont(QFont("Times",18,QFont::Bold));
    add_button->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    connect(add_button, SIGNAL(clicked()), this, SLOT(add_clicked()));

    delete_button = new QPushButton("删除", this);
    delete_button->setGeometry(QRect(QPoint(510, 200), QSize(100, 61)));
    delete_button->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    //delete_button->setIcon(QIcon("image/delete.jpg"));
    delete_button->setFont(QFont("Times",18,QFont::Bold));
    connect(delete_button, SIGNAL(clicked()), this, SLOT(delete_clicked()));

    edit_button = new QPushButton("编辑", this);
    edit_button->setGeometry(QRect(QPoint(510, 300), QSize(100, 61)));
    edit_button->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    //edit_button->setIcon(QIcon("image/edit.jpg"));
    edit_button->setFont(QFont("Times",18,QFont::Bold));
    connect(edit_button, SIGNAL(clicked()), this, SLOT(edit_clicked()));

    info = new QTableWidget(this);
    info->setColumnCount(4);
    info->setRowCount(5);
    info->setGeometry(QRect(QPoint(30, 50), QSize(435, 370)));
    info->setEditTriggers(QAbstractItemView::NoEditTriggers);
    info->setSelectionBehavior(QAbstractItemView::SelectRows);
    info->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    QStringList headers;
    headers << "用户名" << "密码" << "学生Id" << "手机";
    info->setHorizontalHeaderLabels(headers);
    table_init();
    //info->setItem(0, 0, new QTableWidgetItem(QString("1")));
    //info->setItem(0, 1, new QTableWidgetItem(tr("20100112")));
}

void UserPage::table_init() {
    list<User> userList;
    int size, i;

    userList = userManager_->getAllUser();
    size = userList.size();

    info->setRowCount(size);
    for (i = 0; i < size; i++) {
        info->setItem(i, 0, new QTableWidgetItem(tr(userList.front().getName().data())));
        info->setItem(i, 1, new QTableWidgetItem(tr(userList.front().getPassword().data())));
        info->setItem(i, 2, new QTableWidgetItem(tr(userList.front().getStudentId().data())));
        info->setItem(i, 3, new QTableWidgetItem(tr(userList.front().getStudentPhone().data())));
        userList.pop_front();
    }
}

void UserPage::add_clicked()
{
    UserInfoDialog *dialog = new UserInfoDialog;
    User user;

    dialog->exec();
    user.setName(dialog->getName());
    user.setPassword(dialog->getPassword());
    user.setStudentId(dialog->getStudentId());
    user.setStudentPhone(dialog->getStudentPhone());
    if (userManager_->addUser(user)) {
        QMessageBox::information(this,tr("hello"),tr("添加成功!"));
        table_init();
    } else {
        QMessageBox::information(this,tr("hello"),tr("添加失败!\n"));
    }

    delete dialog;
}

void UserPage::delete_clicked()
{
    User user;
    int row;

    row = info->currentRow();
    if (row == -1) {
        QMessageBox::information(this,tr("hello"),tr("请选择一个目标行!\n"));
        return;
    }
    user.setName(info->item(row, 0)->text().toStdString());
    user.setPassword(info->item(row, 1)->text().toStdString());
    user.setStudentId(info->item(row, 2)->text().toStdString());
    user.setStudentPhone(info->item(row, 3)->text().toStdString());
    if (userManager_->deleteUser(user) ) {
         QMessageBox::information(this,tr("hello"),tr("删除成功!"));
         table_init();
    }else {
         QMessageBox::information(this,tr("hello"),tr("删除失败!\n"));
    }
}

void UserPage::edit_clicked()
{
    User user;
    UserInfoDialog *dialog = new UserInfoDialog;
    int row;

    row = info->currentRow();
    if (row == -1) {
        QMessageBox::information(this,tr("hello"),tr("请选择一个目标行!\n"));
        return;
    }
    dialog->setName(info->item(row, 0)->text().toStdString());
    dialog->setPassword(info->item(row, 1)->text().toStdString());
    dialog->setStudentId(info->item(row, 2)->text().toStdString());
    dialog->setStudentPhone(info->item(row, 3)->text().toStdString());
    dialog->init();
    dialog->exec();

    user.setName(dialog->getName());
    user.setPassword(dialog->getPassword());
    user.setStudentId(dialog->getStudentId());
    user.setStudentPhone(dialog->getStudentPhone());

    if (userManager_->editUser(user) ) {
         QMessageBox::information(this,tr("hello"),tr("编辑成功!"));
         table_init();
    }else {
         QMessageBox::information(this,tr("hello"),tr("编辑失败!"));
    }

    delete dialog;
}

void UserPage::search_clicked()
{
    list<User> userList;
    int size, i;

    userList = userManager_->searchUser(search_line->text().toStdString());
    size = userList.size();

    info->setRowCount(size);
    for (i = 0; i < size; i++) {
        info->setItem(i, 0, new QTableWidgetItem(tr(userList.front().getName().data())));
        info->setItem(i, 1, new QTableWidgetItem(tr(userList.front().getPassword().data())));
        info->setItem(i, 2, new QTableWidgetItem(tr(userList.front().getStudentId().data())));
        info->setItem(i, 3, new QTableWidgetItem(tr(userList.front().getStudentPhone().data())));
        userList.pop_front();
    }
}
