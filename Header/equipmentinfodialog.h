#ifndef EQUIPMENTINFODIALOG
#define EQUIPMENTINFODIALOG

#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <string>

using std::string;

class EquipmentInfoDialog : public QDialog
{
    Q_OBJECT
public:
    //construct function
    EquipmentInfoDialog(QWidget *parent = 0);
    void init();
    string getName();
    void setName(string name);
    string getId();
    void setId(string id);
    string getType();
    void setType(string state);
    string getState();
    void setState(string state);

private slots:
    void confirm_clicked();
    void cancel_clicked();

private:
    QLabel *id_label;
    QLabel *name_label;
    QLabel *type_label;
    QLabel *state_label;
    QLineEdit *id_line;
    QLineEdit *name_line;
    QLineEdit *type_line;
    QLineEdit *state_line;
    QPushButton *confirm_button;
    QPushButton *cancel_button;

    string id_;
    string name_;
    string type_;
    string state_;
};


#endif // EQUIPMENTINFODIALOG

