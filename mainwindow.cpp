#include "mainwindow.h"
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton * button_on = new QPushButton();
    QPushButton * button_off = new QPushButton();
    QPushButton * button_refresh = new QPushButton();

    QMenuBar * menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu * fileMenu = menuBar->addMenu("File");

    QAction *newFileAction = fileMenu->addAction("New file");
    // add Actions

    QMenu * editMenu = menuBar->addMenu("Edit");
    //add Actions

    QMenu * controlMenu = menuBar->addMenu("Control");
    QAction *laser = controlMenu->addAction("Laser On/Off");
    QAction *spectrometer = controlMenu->addAction("Spectrometer Status? or Reset");
    QAction *arduino = controlMenu->addAction("Arduino Status? or Reset?");
    //add Actions

    QWidget * mainWidget = new QWidget();
    QWidget * graphWidget = new QWidget();

    QVBoxLayout * layout = new QVBoxLayout();

    QHBoxLayout * hbox_1 = new QHBoxLayout();
    QHBoxLayout * hbox_2 = new QHBoxLayout();

    QListView * historyList = new QListView();
    QListView * compareList = new QListView();

    QLabel * logo_label = new QLabel();
    QLabel * status_label = new QLabel();
    QPixmap * logo_pixmap = new QPixmap();
    //    logo_pixmap->load("logo");
    QPixmap * laser_on = new QPixmap();
    QPixmap * laser_off = new QPixmap();
    // 레이저 상태 추가하는 곳
    QLabel * test = new QLabel("fdsfsd");

    layout->addLayout(hbox_1,1);
    layout->addWidget(graphWidget,3);
    layout->addLayout(hbox_2,1);

    hbox_1->addWidget(logo_label);
    hbox_1->addWidget(status_label);

    hbox_2->addWidget(historyList);
    hbox_2->addWidget(compareList);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
    setGeometry(300,300,500,500);


}

MainWindow::~MainWindow()
{
}

