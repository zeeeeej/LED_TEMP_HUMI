#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "led.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked(){
    static int status = 1;
    /* 2.ctrl LED */


    g_led.led_control(status);
    status = !status;
    if(status){
        qDebug()<<"LED clicked on !";
    }else{
        qDebug()<<"LED clicked off !";
    }

}

