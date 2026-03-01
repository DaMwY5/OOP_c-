#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H

#include "transport.h"

class electric_car : public transport {
public:
    electric_car(std::string brand);

    void start_the_transport() override;
    void change_transmission(int transmission) override;
    void change_the_song(std::string name_of_song) override;
    void turn_on_the_radio() override;
};

#endif