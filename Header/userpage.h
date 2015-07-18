#ifndef USERPAGE
#define USERPAGE

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QStringList>

#include "UserManager.h"

class UserPage : public QWidget
{
     Q_OBJECT

public:
    explicit UserPage(QWidget *parent = 0);
    void table_init();

private slots:
    void add_clicked();
    void delete_clicked();
    void edit_clicked();
    void search_clicked();

private:
    QPushButton *search_button;
    QPushButton *add_button;
    QPushButton *delete_button;
    QPushButton *edit_button;
    QLineEdit *search_line;
    QTableWidget *info;

    UserManager *userManager_;
};

#endif // USERPAGE

