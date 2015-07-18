#ifndef ORDERINFODIALOG
#define ORDERINFODIALOG

#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <string>

using std::string;

class OrderInfoDialog : public QDialog
{
    Q_OBJECT
public:
    //construct function
    OrderInfoDialog(QWidget *parent = 0);
    string getStudentId();
    string getStudentPhone();
    string getEquipmentId();

private slots:
    void confirm_clicked();
    void cancel_clicked();

private:
    QLabel *equipment_id_label;
    QLabel *student_id_label;
    QLabel *student_phone_label;
    QLineEdit *equipment_id_line;
    QLineEdit *student_id_line;
    QLineEdit *student_phone_line;
    QPushButton *confirm_button;
    QPushButton *cancel_button;

    string equipmentId_;
    string studentId_;
    string studentPhone_;
};

#endif // ORDERINFODIALOG

