#include "mainwindow.h"

#include <QApplication>

#include "led.h"

led g_led;

int main(int argc, char *argv[])
{

    /* 1.init LED */
    g_led.led_init();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
