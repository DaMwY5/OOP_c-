#include "car.h"
#include "plane.h"
#include "electric_car.h"

int main() {
    car c("BMW");
    c.turn_on_the_radio();
    c.change_the_song("Organ Penguin Version");
    c.setCost(40000);
    c.setMax_speed(280);
    c.start_the_transport();
    c.change_transmission(1);
    c.printInfo();

    plane p("Boeing");
    p.setCost(100000000);
	
    p.setMax_speed(900);
    p.start_the_transport();
    p.turn_on_the_radio();
    p.change_the_song("antidepressant");
    p.change_transmission(3);
    p.printInfo();

    electric_car e("Tesla");
    e.turn_on_the_radio();
    e.change_the_song("Kopendos");
    e.setCost(60000);
    e.setMax_speed(250);
    e.start_the_transport();
    e.change_transmission(1);
    e.printInfo();

    return 0;
}