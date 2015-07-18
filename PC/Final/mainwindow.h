#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void open();

    Ui::MainWindow *ui;
    QAction * user_action;
    QAction * equipment_action;
    QAction * order_action;
    QPushButton *pButton ;
};

#endif // MAINWINDOW_H
