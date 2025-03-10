#include "led.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <QDebug>



led::led()
{


}


void led::led_init()
{
    /**
      *  echo 131 > /sys/class/gpio/export
      *  echo out > /sys/class/gpio/gpio131/direction
      */
    int fd;
    fd = open("/sys/class/gpio/export",O_WRONLY);
    if(fd<0){
        qDebug() << "led_init open /sys/class/gpio/export fail";
        return;
    }
    write(fd,"131\n",4);
    close(fd);

    fd = open("/sys/class/gpio/gpio131/direction",O_WRONLY);
    if(fd<0){
        qDebug() << "led_init open /sys/class/gpio/gpio131/direction fail";
        return;
    }
    write(fd,"out\n",4);
    close(fd);

}

void led::led_control(int on)
{
    /**
      *  echo 0 > /sys/class/gpio/gpio131/value
      *  echo 1 > /sys/class/gpio/gpio131/value
      */
    static int fd = -1;
    if(-1==fd){
         fd = open("/sys/class/gpio/gpio131/value",O_RDWR);
    }

    if(fd<0){
        qDebug() << "led_control open /sys/class/gpio/gpio131/value fail";
        return;
    }
    if(on){
         write(fd,"0\n",2);
    }else{
         write(fd,"1\n",2);
    }

    //close(fd);

}
