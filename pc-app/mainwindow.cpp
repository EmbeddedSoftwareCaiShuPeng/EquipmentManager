#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QPushButton>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle(tr("Main Window"));

    user_action = new QAction(QIcon(""), tr("&User..."), this);
    user_action->setShortcuts(QKeySequence::Open);
    user_action->setStatusTip(tr("Show Uset List"));
    connect(user_action, &QAction::triggered, this, &MainWindow::open);

    equipment_action = new QAction(QIcon(""), tr("&Equipment..."), this);
    equipment_action->setShortcuts(QKeySequence::Open);
    equipment_action->setStatusTip(tr("Show Equipment List"));
    connect(equipment_action, &QAction::triggered, this, &MainWindow::open);

    order_action = new QAction(QIcon(""), tr("&Order..."), this);
    order_action->setShortcuts(QKeySequence::Open);
    order_action->setStatusTip(tr("Show Order List"));
    connect(order_action, &QAction::triggered, this, &MainWindow::open);

    QToolBar *tool_bar = addToolBar(tr("&Menu"));
    tool_bar->addAction(user_action);
    tool_bar->addAction(equipment_action);
    tool_bar->addAction(order_action);

    pButton = new QPushButton("Button", this);
    pButton->setGeometry(QRect(QPoint(460, 100), QSize(80, 40)));
    pButton->setText("h ");

    statusBar();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open() {
    QMessageBox::information(this, tr("Information"), tr("Open"));
}
