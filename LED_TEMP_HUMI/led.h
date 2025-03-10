#ifndef LED_H
#define LED_H



class led
{
public:
    led();
    void led_init();
    void led_control(int on);
};

extern led g_led;

#endif // LED_H
