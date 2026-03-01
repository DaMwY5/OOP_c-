#include "car.h"

car::car(std::string brand) {
    this->brand = brand;
    this->type = "car";
    this->volume_of_engine = -1;
    this->max_speed = -1;
    this->cost = -1;
    this->radio = false;
    this->name_of_song = "...";
    this->transmission = 0;
    this->gearbox = "mechanics";
    this->work = false;
}

void car::start_the_transport() {
    this->work = true;
}

void car::change_transmission(int transmission) {
    if (this->work == true) {
        this->transmission = transmission;
    }
    else {
        std::cout << type << " doesn't work\n";
    }
}

void car::change_the_song(std::string name_of_song) {
    if (this->radio == true) {
        this->name_of_song = name_of_song;
    }
    else {
        std::cout << "radio doesn't work\n";
    }
}

void car::turn_on_the_radio() {
    this->radio = !this->radio;
}