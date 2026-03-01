#include "electric_car.h"

electric_car::electric_car(std::string brand) {
    this->brand = brand;
    this->type = "electric_car";
    this->volume_of_engine = 0;
    this->max_speed = -1;
    this->cost = -1;
    this->radio = false;
    this->name_of_song = "...";
    this->transmission = 0;
    this->gearbox = "automatic";
    this->work = false;
}

void electric_car::start_the_transport() {
    this->work = true;
}

void electric_car::change_transmission(int transmission) {
    if (this->work == true) {
        if (transmission == 0 || transmission == 1 || transmission == 2) {
            this->transmission = transmission;
        }
        else {
            std::cout << "electric_car: transmission can be only 0(N), 1(D), 2(R)\n";
        }
    }
    else {
        std::cout << type << " doesn't work\n";
    }
}

void electric_car::change_the_song(std::string name_of_song) {
    if (this->radio == true) {
        this->name_of_song = name_of_song;
    }
    else {
        std::cout << "radio doesn't work\n";
    }
}

void electric_car::turn_on_the_radio() {
    this->radio = !this->radio;
}