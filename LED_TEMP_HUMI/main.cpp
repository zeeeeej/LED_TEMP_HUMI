#include "mainwindow.h"

#include <QApplication>

#include "rpc_client.h"

#include "dht11thread.h"

#include <stdio.h>


 QLabel *tmepLabel;
 QLabel *humiLabel;
 QLabel *ledLabel;

void onDTH11Changed(int humi,int temp,int led){
    char buff[20];
    if(tmepLabel){
        if(-1==temp){
            tmepLabel->setText("loading");
        }else{
            sprintf(buff,"temp:%d",temp);
            tmepLabel->setText(buff);
        }

    }
    if(humiLabel){
        if(-1==humi){
            humiLabel->setText("loading");
        }else{
            sprintf(buff,"humi:%d%%",humi);
            humiLabel->setText(buff);
        }
    }
    if(ledLabel){
        if(led==-1){
            ledLabel->setText("LOADING");
        }
        else if(led==0){
            ledLabel->setText("OFF");
        }else{
            ledLabel->setText("ON");
        }
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
     ledLabel = w.GetLed();
     tmepLabel->setText("loading");
     humiLabel->setText("loading");
     ledLabel->setText("loading");
    w.show();

    /* create dht11 thread */
    DHT11Thread dht11Thread ;
    dht11Thread.setCallback(onDTH11Changed);
    dht11Thread.start();


    return a.exec();
}
