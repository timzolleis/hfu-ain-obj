#include <cassert>
#include <string>

#include "./city/city.h"
//
// Created by Tim Zolleis on 02.12.24.
//
void testCopy() {
    std::string pois_morder[] = {"Sauron", "Minas Morgul", "Orodruin"};
    tz::City left("Mordor", 47, 11, pois_morder, 3);
    std::string pois_arrakis[] = {"Arrakeen", "Desert"};
    tz::City right("Arrakis", 23, 42, pois_arrakis, 2);
    left = right;
    assert(left.getName() == "Arrakis");
    assert(left.getX() == 23);
    assert(left.getY() == 42);
    assert(left.getNumberOfPOIs() == 2);
    assert(left[0] == pois_arrakis[0]);
    assert(left[1] == pois_arrakis[1]);
}

int main() {
    testCopy();
    return 0;
}
