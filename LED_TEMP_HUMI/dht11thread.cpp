#include "dht11thread.h"
#include <QtDebug>


DHT11Thread::DHT11Thread()
{
    this->m_stop = false;
       msleep(2000);
    this->dht.dht11_init();
}

void DHT11Thread::run(){
    unsigned char temp;
    unsigned char humi;
    bool ret ;
    while (!m_stop) {
            msleep(2000);
         //qDebug()<<"DHT11Thread dht11_read .....";
        ret = dht.dht11_read(&temp,&humi);
        if(ret){
            if(cb){
                 //qDebug()<<"DHT11Thread DHT11Callback "<<(int)temp <<"," <<(int)humi;
                cb((int)temp,(int)humi);
            }else{
                    qDebug()<<"DHT11Thread DHT11Callback is null";
            }
        }else{
             //qDebug()<<"DHT11Thread dht11_read fail";
        }


    }
}

void DHT11Thread::stop(){
    m_stop = true;
}

void DHT11Thread::setCallback(DHT11Callback callback){
    cb = callback;
}


