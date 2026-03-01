#include "plane.h"

plane::plane(std::string brand) {
    this->brand = brand;
    this->type = "plane";
    this->volume_of_engine = -1;
    this->max_speed = -1;
    this->cost = -1;
    this->radio = false;
    this->name_of_song = "...";
    this->transmission = -1;
    this->gearbox = "mechanics";
    this->work = false;
}

void plane::start_the_transport() {
    this->work = true;
}

void plane::change_transmission(int) {
    std::cout << "plane: transmission is not supported\n";
}

void plane::change_the_song(std::string name_of_song) {
    if (this->radio == true) {
        this->name_of_song = name_of_song;
    }
    else {
        std::cout << "radio doesn't work\n";
    }
}

void plane::turn_on_the_radio() {
    radio = false;
    std::cout << "Plane has no radio\n";
}