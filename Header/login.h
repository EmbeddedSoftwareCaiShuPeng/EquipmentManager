#ifndef LOGIN
#define LOGIN

#include <QDialog>

namespace Ui {
    class Login;
}

class Login : public QDialog {
    Q_OBJECT
public:
    Login(QWidget *parent = 0);
    ~Login();

private:
    Ui::Login *ui;
};

#endif // LOGIN


