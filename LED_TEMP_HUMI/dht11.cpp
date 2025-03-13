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


 int dht11::dht11_read(unsigned char*temp,unsigned char*humi)
{
     if(fd<0){
          fd = open("/dev/mydht11", O_RDWR | O_NONBLOCK);
               qDebug() << "dht11_read open /dev/mydht1 not opened!";
     }
       if(fd<0){
              qDebug() << "dht11_read open /dev/mydht1 fail fd:"<<fd;
              return -1;
       }
     unsigned char buf[2] ={0};




            if (read(fd, buf, 2) == 2)
            {
              *temp = buf[0];
              *humi = buf[1];
//                if(fd<0){
//                    close(fd);
//                    fd=-1;
//                }
               return 0;

            }else{
//                if(fd<0){
//                    close(fd);
//                    fd=-1;
//                }
                return  -2;
            }




}

dht11::~dht11()
{

    if(fd>=0){
        close(fd);
        fd=-1;
    }
}
