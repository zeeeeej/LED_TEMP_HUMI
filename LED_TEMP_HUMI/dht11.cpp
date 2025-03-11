#include "dht11.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <QDebug>

dht11::dht11():fd(-1)
{

}

void dht11::dht11_init(){
    fd = open("/dev/mydht11", O_RDWR | O_NONBLOCK);
    if(fd<0){
           qDebug() << "dht11_read open /dev/mydht1 fail fd:"<<fd;
    }
}


 bool dht11::dht11_read(unsigned char*temp,unsigned char*humi)
{
     if(fd<0){
               qDebug() << "dht11_read open /dev/mydht1 not opened!";
         return false;
     }
     unsigned char buf[2] ={0};




            if (read(fd, buf, 2) == 2)
            {
              *temp = buf[0];
              *humi = buf[1];
               return true;

            }else{
                return  false;
            }




}

dht11::~dht11()
{

    if(fd>=0){
        close(fd);
        fd=-1;
    }
}
