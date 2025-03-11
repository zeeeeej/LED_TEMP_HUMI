#ifndef DHT11_H
#define DHT11_H


class dht11
{


private:
    int fd = -1;
public:
    dht11();
    void dht11_init();
    bool dht11_read(unsigned char*temp,unsigned char*humi);
    ~dht11();

};

#endif // DHT11_H
