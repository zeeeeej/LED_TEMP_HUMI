#ifndef DHT11THREAD_H
#define DHT11THREAD_H

#include <QThread>
#include "dht11.h"

using DHT11Callback  = void(*)(int,int);

class DHT11Thread:public QThread
{
public:
    DHT11Thread();
    void  stop();

    void setCallback(DHT11Callback callback);

protected:
    void run() override;

private:
    bool m_stop =false;
    dht11 dht;
    DHT11Callback cb;


};



#endif // DHT11THREAD_H
