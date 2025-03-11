#include "mainwindow.h"

#include <QApplication>

#include "led.h"

#include "dht11thread.h"

#include <stdio.h>

led g_led;
 QLabel *tmepLabel;
  QLabel *humiLabel;

void onDTH11Changed(int temp,int humi){
    char buff[20];
    if(tmepLabel){
        sprintf(buff,"%d",temp);
        tmepLabel->setText(buff);
    }
    if(humiLabel){
         sprintf(buff,"%d",humi);
        humiLabel->setText(buff);
    }
}

int main(int argc, char *argv[])
{

    /* 1.init LED */
    g_led.led_init();



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
