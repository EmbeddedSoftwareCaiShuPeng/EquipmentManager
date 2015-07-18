#ifndef ORDERPAGE
#define ORDERPAGE

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QStringList>

#include "OrderManager.h"

class OrderPage : public QWidget
{
     Q_OBJECT

public:
    explicit OrderPage(QWidget *parent = 0);
    void table_init();

private slots:
    void lend_clicked();
    void return_clicked();
    void search_clicked();

private:
    QPushButton *search_button;
    QPushButton *add_button;
    QPushButton *delete_button;
    QLineEdit *search_line;
    QTableWidget *info;

    OrderManager *orderManager_;
};

#endif // ORDERPAGE

