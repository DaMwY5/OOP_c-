#include "transport.h"

// геттеры
std::string transport::getType() { return type; }
std::string transport::getBrand() { return brand; }
float transport::getVolume_of_engine() { return volume_of_engine; }
int transport::getMax_speed() { return max_speed; }
int transport::getCost() { return cost; }
int transport::getTransmission() { return transmission; }
std::string transport::getGearbox() { return gearbox; }

// сеттеры
void transport::setType(std::string type) { this->type = type; }
void transport::setBrand(std::string brand) { this->brand = brand; }
void transport::setVolume_of_engine(float volume_of_engine) { this->volume_of_engine = volume_of_engine; }
void transport::setMax_speed(int max_speed) { this->max_speed = max_speed; }
void transport::setCost(int cost) { this->cost = cost; }

void transport::setGearbox(std::string gearbox) {
    if (gearbox == "mechanics") {
        this->gearbox = "mechanics";
    }
    else if (gearbox == "automatic") {
        this->gearbox = "automatic";
    }
    else {
        this->gearbox = "unknown";
    }
}

void transport::printInfo() const {
    std::cout << "Type: " << type << "\n";
    std::cout << "Brand: " << brand << "\n";

    if (volume_of_engine == -1)
        std::cout << "Engine volume: unknown\n";
    else if (volume_of_engine == 0)
        std::cout << "Engine volume: this transport does not have this feature.\n";
    else
        std::cout << "Engine volume: " << volume_of_engine << "\n";

    if (max_speed == -1)
        std::cout << "Max speed: unknown\n";
    else
        std::cout << "Max speed: " << max_speed << " km/h" << "\n";

    if (cost == -1)
        std::cout << "Cost: unknown\n";
    else
        std::cout << "Cost: " << cost << " $" << "\n";

    if (gearbox == "unknown")
        std::cout << "Gearbox: unknown\n";
    else
        std::cout << "Gearbox: " << gearbox << "\n";

    if (!work)
        std::cout << "Engine: off\n";
    else
        std::cout << "Engine: running\n";

    if (!radio)
        std::cout << "Radio: off \n";
    else
        std::cout << "Radio: playing \"" << name_of_song << "\"\n";

    std::cout << "Transmission: ";

    if (transmission == 0)
        std::cout << "N\n";
    else if (transmission == -1)
        std::cout << "not supported\n";
    else
        std::cout << transmission << "\n";

    std::cout << "---------------------------\n";
}