//
// Created by Tim Zolleis on 05.11.24.
//


#include <cassert>
#include <string>
#include "city/city.h"

void testCity() {
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    tz::City mordor("Mordor", 47, 11, pois, 3);
    auto copy = mordor;
    mordor.setPOI(2, "Cirith Ungol");
    assert(copy.getPOI(2) == "Orodruin");
}

int main() {
    testCity();
    return 0;
}
