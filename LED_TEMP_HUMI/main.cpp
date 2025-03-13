#include "mainwindow.h"

#include <QApplication>

#include "rpc_client.h"

#include "dht11thread.h"

#include <stdio.h>


 QLabel *tmepLabel;
  QLabel *humiLabel;

void onDTH11Changed(int humi,int temp){
    char buff[20];
    if(tmepLabel){
        sprintf(buff,"temp:%d",temp);
        tmepLabel->setText(buff);
    }
    if(humiLabel){
         sprintf(buff,"humi:%d%%",humi);
        humiLabel->setText(buff);
    }
}

int main(int argc, char *argv[])
{

    /* 1.init LED */
    RPC_Client_Init();

    QApplication a(argc, argv);
    MainWindow w;
     tmepLabel = w.GetTemp();
     humiLabel = w.GetHumi();
    w.show();

    /* create dht11 thread */
    DHT11Thread dht11Thread ;
    dht11Thread.setCallback(onDTH11Changed);
    dht11Thread.start();


    return a.exec();
}
