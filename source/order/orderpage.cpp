#include <QMessageBox>
#include <QFont>
#include <string>

#include "orderpage.h"
#include "orderinfodialog.h"

using std::string;
extern string current_user;

OrderPage::OrderPage(QWidget *parent)
    : QWidget(parent)
{
    orderManager_ = new OrderManager(current_user);

    search_line = new QLineEdit(this);
    search_line->setGeometry(QRect(QPoint(30, 10), QSize(320, 30)));

    search_button = new QPushButton("搜索", this);
    search_button->setGeometry(QRect(QPoint(360, 10), QSize(90, 28)));
    search_button->setIcon(QIcon("image/search.jpg"));
    search_button->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    connect(search_button, SIGNAL(clicked()), this, SLOT(search_clicked()));

    add_button = new QPushButton("借出", this);
    add_button->setGeometry(QRect(QPoint(130, 360), QSize(100, 61)));
   // add_button->setIcon(QIcon("image/add.png"));
    add_button->setFont(QFont("Times",18,QFont::Bold));
    add_button->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    connect(add_button, SIGNAL(clicked()), this, SLOT(lend_clicked()));

    delete_button = new QPushButton("归还", this);
    delete_button->setGeometry(QRect(QPoint(330, 360), QSize(100, 61)));
    delete_button->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    //delete_button->setIcon(QIcon("image/delete.png"));
    delete_button->setFont(QFont("Times",18,QFont::Bold));
    connect(delete_button, SIGNAL(clicked()), this, SLOT(return_clicked()));

    info = new QTableWidget(this);
    info->setColumnCount(6);
    info->setRowCount(5);
    info->setGeometry(QRect(QPoint(10, 50), QSize(620, 300)));
    info->setEditTriggers(QAbstractItemView::NoEditTriggers);
    info->setSelectionBehavior(QAbstractItemView::SelectRows);
    info->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    info->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    info->setColumnWidth(0,60);
    info->setColumnWidth(1,100);
    info->setColumnWidth(2,80);
    info->setColumnWidth(3,80);
    info->setColumnWidth(4,110);
    info->setColumnWidth(5,200);
    QStringList headers;
    headers << "Id" << "器材Id" << "用户Id" <<"学生Id" << "手机" << "时间";
    info->setHorizontalHeaderLabels(headers);
    table_init();
}

void OrderPage::table_init() {
    list<Order> orderList;
    int size, i;

    orderList = orderManager_->getAllOrder();
    size = orderList.size();

    info->setRowCount(size);
    for (i = 0; i < size; i++) {
        info->setItem(i, 0, new QTableWidgetItem(tr(orderList.front().getId().data())));
        info->setItem(i, 1, new QTableWidgetItem(tr(orderList.front().getEquipmentId().data())));
        info->setItem(i, 2, new QTableWidgetItem(tr(orderList.front().getUserId().data())));
        info->setItem(i, 3, new QTableWidgetItem(tr(orderList.front().getStudentId().data())));
        info->setItem(i, 4, new QTableWidgetItem(tr(orderList.front().getStudentPhone().data())));
        info->setItem(i, 5, new QTableWidgetItem(tr(orderList.front().getDate().data())));
        orderList.pop_front();
    }
}

void OrderPage::lend_clicked()
{
    OrderInfoDialog *dialog = new OrderInfoDialog;
    Order order;

    dialog->exec();
    order.setEquipmentId(dialog->getEquipmentId());
    order.setStudentId(dialog->getStudentId());
    order.setStudentPhone(dialog->getStudentPhone());
    if (orderManager_->lendEquipment(order)) {
        QMessageBox::information(this,tr("hello"),tr("登记成功!"));
        table_init();
    } else {
        QMessageBox::information(this,tr("hello"),tr("登记失败"));
    }

    delete dialog;
}

void OrderPage::return_clicked()
{
    Order order;
    int row;

    row = info->currentRow();
    if (row == -1) {
        QMessageBox::information(this,tr("hello"),tr("请选择一个目标行!\n"));
        return;
    }
    order.setId(info->item(row, 0)->text().toStdString());
    order.setEquipmentId(info->item(row, 1)->text().toStdString());
    order.setUserId(info->item(row, 2)->text().toStdString());
    order.setStudentId(info->item(row, 3)->text().toStdString());
    order.setStudentPhone(info->item(row, 4)->text().toStdString());
    order.setDate(info->item(row, 5)->text().toStdString());
    if (orderManager_->returnEquipment(order) ) {
         QMessageBox::information(this,tr("hello"),tr("归还成功!"));
         table_init();
    }else {
         QMessageBox::information(this,tr("hello"),tr("归还失败!\n"));
    }
}

void OrderPage::search_clicked()
{
    list<Order> orderList;
    int size, i;

    orderList = orderManager_->searchOrder(search_line->text().toStdString());
    size = orderList.size();

    info->setRowCount(size);
    for (i = 0; i < size; i++) {
        info->setItem(i, 0, new QTableWidgetItem(tr(orderList.front().getId().data())));
        info->setItem(i, 1, new QTableWidgetItem(tr(orderList.front().getEquipmentId().data())));
        info->setItem(i, 2, new QTableWidgetItem(tr(orderList.front().getUserId().data())));
        info->setItem(i, 3, new QTableWidgetItem(tr(orderList.front().getStudentId().data())));
        info->setItem(i, 4, new QTableWidgetItem(tr(orderList.front().getStudentPhone().data())));
        info->setItem(i, 5, new QTableWidgetItem(tr(orderList.front().getDate().data())));
        orderList.pop_front();
    }
}

