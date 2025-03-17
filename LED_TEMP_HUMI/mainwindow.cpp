#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "rpc_client.h"

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


QLabel *MainWindow::GetTemp(){
    return  ui->label_temp;
}

QLabel *MainWindow::GetHumi(){
    return  ui->label_humi;
}

QLabel *MainWindow::GetLed(){
    return  ui->label_led;
}


void MainWindow::on_pushButton_clicked(){
    static int status = 1;
    /* 2.ctrl LED */


    int ret = rpc_led_control(status);
    status = !status;
    if(status){
        qDebug()<<"LED clicked on !";
    }else{
        qDebug()<<"LED clicked off !";
    }

}

