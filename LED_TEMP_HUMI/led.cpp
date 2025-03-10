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

/*
 * ./led_test <0|1|2|..>  on
 * ./led_test <0|1|2|..>  off
 * ./led_test <0|1|2|..>
 */

void led::led_init()
{

    fd = open("/dev/100ask_led",O_RDWR);
    if(fd<0){
        qDebug() << "led_init open /dev/100ask_led fail";
        return;
    }
}

void led::led_control(int on)
{
    char buf[2];
    if(fd<0){
        qDebug() << "led_control /dev/100ask_led not opened.";
        return;
    }
    // open first led.
    buf[0]=0;
    if(on){
        buf[1] = 0;
    }else{
      buf[1] = 1;
    }
 write(fd,buf,2);

}

led::~led(){
    if(fd){
          close(fd);
    }

}
