//
// Created by Tim Zolleis on 05.11.24.
//

//
// Created by Tim Zolleis on 29.10.24.
//
#include <cassert>
#include <iostream>
#include <string>
#include "city/city.h"


tz::Position createPosition() {
    std::string mordor = "Mordor";
    tz::Position result(mordor, 47, 11);
    return result;
}

tz::City createCity() {
    auto position = createPosition();
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    tz::City result(position.getName(), position.getX(), position.getY(), pois, 3);
    return result;
}

void testCtor() {
    auto position = createPosition();
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    tz::City city(position.getName(), position.getX(), position.getY(), pois, 3);
    pois[0] = "Gandalf";
    assert(city.getPOI(0)=="Sauron");
}

void testGetNameXY() {
    auto position = createPosition();
    tz::City city(position.getName(), position.getX(), position.getY(), nullptr, 0);
    assert(city.getName()=="Mordor");
    assert(city.getX()==47);
    assert(city.getY()==11);
}


void testGetPOI() {
    auto city = createCity();
    assert(city.getPOI(0)=="Sauron");
    assert(city.getPOI(1)=="Minas Morgul");
    assert(city.getPOI(2)=="Orodruin");
    try {
        city.getPOI(3);
        assert(false);
    } catch (...) {
    }
    try {
        city.getPOI(-1);
        assert(false);
    } catch (...) {
    }
}

void testSetPOI() {
    auto city = createCity();
    city.setPOI(0, "Gandalf");
    assert(city.getPOI(0)=="Gandalf");

    try {
        city.setPOI(3, "Gandalf");
        assert(false);
    } catch (...) {
    }
    try {
        city.setPOI(-1, "Gandalf");
        assert(false);
    } catch (...) {
    }
}

void testGetNumberOfPOIs() {
    auto city = createCity();
    assert(city.getNumberOfPOIs()==3);
}


void testCity() {
    testCtor();
    testGetNameXY();
    testGetPOI();
    testSetPOI();
    testGetNumberOfPOIs();
}

int main() {
    testCity();
    return 0;
}
