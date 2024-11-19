//
// Created by Tim Zolleis on 19.11.24.
//


#include <iostream>

#include "../shared/position/position.h"
#include "../shared/city/city.h"

int main() {
    tz::City city("Test", 12, 14,  new std::string[2]{"Test1", "Test2"}, 2);
    std::cout << city << std::endl;
}
