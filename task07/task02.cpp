//
// Created by Tim Zolleis on 19.11.24.
//


#include <iostream>

#include "../shared/position/position.h"
#include "../shared/city/city.h"


void printPosition() {
    tz::Position position("Mordor", 47, 11);
    std::cout<< position <<std::endl;
}

void printCity() {
    std::string pois[]={"Sauron", "Minas Morgul", "Orodruin"};
    tz::City city("Mordor", 47, 11,pois,3);
    std::cout<< city <<std::endl;
}

int main() {
    printPosition();
    printCity();
}
