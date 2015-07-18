#ifndef USERINFODIALOG
#define USERINFODIALOG

#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <string>

using std::string;

class UserInfoDialog : public QDialog
{
    Q_OBJECT
public:
    //construct function
    UserInfoDialog(QWidget *parent = 0);
    void init();
    string getName();
    void setName(string name);
    string getPassword();
    void setPassword(string password);
    string getStudentPhone();
    void setStudentPhone(string phone);
    string getStudentId();
    void setStudentId(string id);

private slots:
    void confirm_clicked();
    void cancel_clicked();

private:
    QLabel *user_name_label;
    QLabel *user_password_label;
    QLabel *student_id_label;
    QLabel *student_phone_label;
    QLineEdit *user_name_line;
    QLineEdit *user_password_line;
    QLineEdit *student_id_line;
    QLineEdit *student_phone_line;
    QPushButton *confirm_button;
    QPushButton *cancel_button;

    string userName_;
    string password_;
    string studentId_;
    string studentPhone_;
};

#endif // USERINFODIALOG

