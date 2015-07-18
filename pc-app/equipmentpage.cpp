#include "equipmentpage.h"
#include "equipmentinfodialog.h"

#include <QMessageBox>
#include <QFont>
#include <string>
using std::string;

extern string current_user;

EquipmentPage::EquipmentPage(QWidget *parent)
    : QWidget(parent)
{
    equipmentManager_ = new EquipmentManager();

    search_line = new QLineEdit(this);
    search_line->setGeometry(QRect(QPoint(30, 10), QSize(320, 30)));

    search_button = new QPushButton("搜索", this);
    search_button->setGeometry(QRect(QPoint(360, 10), QSize(90, 28)));
    search_button->setIcon(QIcon("image/search.jpg"));
    search_button->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    connect(search_button, SIGNAL(clicked()), this, SLOT(search_clicked()));

    if (current_user == "admin") {

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
}
    info = new QTableWidget(this);
    info->setColumnCount(4);
    info->setRowCount(5);
    info->setEditTriggers(QAbstractItemView::NoEditTriggers);
    info->setSelectionBehavior(QAbstractItemView::SelectRows);
    info->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    info->setGeometry(QRect(QPoint(30, 50), QSize(435, 370)));
    QStringList headers;
    headers << "器材Id" << "器材名" << "器材类型" << "器材状态";
    info->setHorizontalHeaderLabels(headers);
    table_init();
}

void EquipmentPage::table_init() {
    list<Equipment> equipmentList;
    int size, i;

    equipmentList = equipmentManager_->getAllEquipment();
    size = equipmentList.size();

    info->setRowCount(size);
    for (i = 0; i < size; i++) {
        info->setItem(i, 0, new QTableWidgetItem(tr(equipmentList.front().getId().data())));
        info->setItem(i, 1, new QTableWidgetItem(tr(equipmentList.front().getName().data())));
        info->setItem(i, 2, new QTableWidgetItem(tr(equipmentList.front().getType().data())));
        info->setItem(i, 3, new QTableWidgetItem(tr(equipmentList.front().getState().data())));
        equipmentList.pop_front();
    }
}

void EquipmentPage::add_clicked()
{
    EquipmentInfoDialog *dialog = new EquipmentInfoDialog;
    Equipment equipment;

    dialog->exec();
    equipment.setId(dialog->getId());
    equipment.setName(dialog->getName());
    equipment.setType(dialog->getType());
    equipment.setState(dialog->getState());
    if (equipmentManager_->addEquipment(equipment)) {
        QMessageBox::information(this,tr("hello"),tr("添加成功!"));
        table_init();
    } else {
        QMessageBox::information(this,tr("hello"),tr("添加失败!\n"));
    }

    delete dialog;
}

void EquipmentPage::delete_clicked()
{
    Equipment equipment;
    int row;

    row = info->currentRow();
    if (row == -1) {
        QMessageBox::information(this,tr("hello"),tr("请选择一个目标行!\n"));
        return;
    }
    equipment.setId(info->item(row, 0)->text().toStdString());
    equipment.setName(info->item(row, 1)->text().toStdString());
    equipment.setType(info->item(row, 2)->text().toStdString());
    equipment.setState(info->item(row, 3)->text().toStdString());

    if (equipmentManager_->deleteEquipment(equipment) ) {
         QMessageBox::information(this,tr("hello"),tr("删除成功!"));
         table_init();
    }else {
         QMessageBox::information(this,tr("hello"),tr("删除失败!\n"));
    }
}

void EquipmentPage::edit_clicked()
{
    EquipmentInfoDialog *dialog = new EquipmentInfoDialog;
    Equipment equipment;
    int row;

    row = info->currentRow();
    if (row == -1) {
        QMessageBox::information(this,tr("hello"),tr("请选择一个目标行!\n"));
        return;
    }
    dialog->setId(info->item(row, 0)->text().toStdString());
    dialog->setName(info->item(row, 1)->text().toStdString());
    dialog->setType(info->item(row, 2)->text().toStdString());
    dialog->setState(info->item(row, 3)->text().toStdString());
    dialog->init();
    dialog->exec();

    equipment.setId(dialog->getId());
    equipment.setName(dialog->getName());
    equipment.setType(dialog->getType());
    equipment.setState(dialog->getState());

    if (equipmentManager_->editEquipment(equipment) ) {
         QMessageBox::information(this,tr("hello"),tr("编辑成功!"));
         table_init();
    }else {
         QMessageBox::information(this,tr("hello"),tr("编辑失败!\n"));
    }

    delete dialog;
}

void EquipmentPage::search_clicked()
{
    list<Equipment> equipmentList;
    int size, i;

    equipmentList = equipmentManager_->searchEquipment(search_line->text().toStdString());
    size = equipmentList.size();

    info->setRowCount(size);
    for (i = 0; i < size; i++) {
        info->setItem(i, 0, new QTableWidgetItem(tr(equipmentList.front().getId().data())));
        info->setItem(i, 1, new QTableWidgetItem(tr(equipmentList.front().getName().data())));
        info->setItem(i, 2, new QTableWidgetItem(tr(equipmentList.front().getType().data())));
        info->setItem(i, 3, new QTableWidgetItem(tr(equipmentList.front().getState().data())));
        equipmentList.pop_front();
    }
}

