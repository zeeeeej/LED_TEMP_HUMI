#include "dht11thread.h"
#include <QtDebug>
#include "rpc_client.h"


DHT11Thread::DHT11Thread()
{
    this->m_stop = false;
//    this->dht.dht11_init();
}

void DHT11Thread::run(){
    int temp;
    int humi;
    int led;
    int ret ;
    int ret2 ;
    //char buf[100];
    while (!m_stop) {
            msleep(1000);
         //qDebug()<<"DHT11Thread dht11_read .....";
        ret = rpc_dht11_read(&temp,&humi);
        ret2 = rpc_led_read(&led);
        if(ret==0 && 0== ret2){
            if(cb){
                //sprintf(buf,"DHT11Thread DHT11Callback temp:%d humi:%d",temp,humi);
                //qDebug()<<"DHT11Thread DHT11Callback " << buf;
                cb(temp,humi,led);
            }else{
                    qDebug()<<"DHT11Thread DHT11Callback is null";
            }
        }else{
             qDebug()<<"DHT11Thread dht11_read fail :" <<ret;
        }


    }
}

void DHT11Thread::stop(){
    m_stop = true;
}

void DHT11Thread::setCallback(DHT11Callback callback){
    cb = callback;
}


