#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>

class transport {
protected:
    std::string type;
    std::string brand;
    float volume_of_engine;
    int max_speed;
    int cost;
    bool radio;
    std::string name_of_song;
    int transmission;
    std::string gearbox;
    bool work;

public:
    // геттеры
    std::string getType();
    std::string getBrand();
    float getVolume_of_engine();
    int getMax_speed();
    int getCost();
    int getTransmission();
    std::string getGearbox();

    // сеттеры
    void setType(std::string type);
    void setBrand(std::string brand);
    void setVolume_of_engine(float volume_of_engine);
    void setMax_speed(int max_speed);
    void setCost(int cost);
    void setGearbox(std::string gearbox);

    void printInfo() const;

    // чисто виртуальные функции
    virtual void start_the_transport() = 0;
    virtual void turn_on_the_radio() = 0;
    virtual void change_the_song(std::string name_of_song) = 0;
    virtual void change_transmission(int transmission) = 0;

    virtual ~transport() {} // виртуальный деструктор
};

#endif