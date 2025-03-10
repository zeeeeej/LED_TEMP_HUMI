#ifndef LED_H
#define LED_H



class led
{

private:
    int fd;
public:
    led();
    void led_init();
    void led_control(int on);
    ~led();
};

extern led g_led;

#endif // LED_H
