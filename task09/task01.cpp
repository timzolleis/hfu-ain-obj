//
// Created by Tim Zolleis on 03.12.24.
//


#include <cassert>
#include "./sort/sort.h"
#include "./city/city.h"

tz::City createCity() {
    std::string mordor = "Mordor";
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    tz::City result(mordor, 47, 11, pois, 3);
    return result;
}

void testSortNumbers() {
    int nums[4] = {1, 4, 2, 5};
    int expected[4] = {1, 2, 4, 5};
    sort(nums, 4);
    for (int i = 0; i < 4; ++i) {
        assert(nums[i] == expected[i]);
    }
}

void testSortChars() {
    char chars[4]{'B', 'a', 'A', 'x'};
    char expected[4]{'a', 'A', 'B', 'x'};
    sort(chars, 4);
    for (int i = 0; i < 4; ++i) {
        assert(chars[i]==expected[i]);
    }
}


void testCity() {
    auto city = createCity();
    assert(city[0] == "Sauron");
    assert(city[1] == "Minas Morgul");
    assert(city[2] == "Orodruin");
    try {
        city[3];
        assert(false);
    } catch (...) {
    }
    city[2] = "Gandalf";
    assert(city[2] == "Gandalf");
    city.add("Whatever");
    assert(city[3] == "Whatever");
    city = createCity();
    try {
        city[3];
        assert(false);
    } catch (...) {
    }
}

int main() {
    testSortNumbers();
    testCity();
    return 0;
}
