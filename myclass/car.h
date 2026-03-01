#ifndef CAR_H
#define CAR_H

#include "transport.h"

class car : public transport {
public:
    car(std::string brand);

    void start_the_transport() override;
    void change_transmission(int transmission) override;
    void change_the_song(std::string name_of_song) override;
    void turn_on_the_radio() override;
};

#endif