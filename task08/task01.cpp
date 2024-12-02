//
// Created by Tim Zolleis on 02.12.24.
//


#include "../shared/city/city.h"
#include <cassert>
#include <string>

tz::City createCity(){
    std::string mordor = "Mordor";
    std::string pois[]={"Sauron", "Minas Morgul", "Orodruin"};
    tz::City result(mordor, 47, 11, pois, 3);
    return result;
}

void testIndexOperator() {
    auto city = createCity();
    assert(city[0] == "Sauron");
    assert(city[1] == "Minas Morgul");
    assert(city[2] == "Orodruin");
    try {
        city[3];
        assert(false);
    } catch (...) {
    }
    try {
        city[-1];
        assert(false);
    } catch (...) {
    }
    city[0] = "Gandalf";
    assert(city[0] == "Gandalf");
    try {
        city[3] = "Gandalf";
        assert(false);
    } catch (...) {
    }
    try {
        city[-1] = "Gandalf";
        assert(false);
    } catch (...) {
    }
    const auto constCity = createCity();
    assert(constCity[0] == "Sauron");
}

int main() {
    testIndexOperator();
    return 0;
}
