//
// Created by Tim Zolleis on 22.10.24.
//
#include <cassert>
#include <iostream>

#include "../shared/position/position.h"

void sortPositions(tz::Position *positions, int size) {
    for (int outerIndex = 1; outerIndex < size; ++outerIndex) {
        tz::Position currentPosition = positions[outerIndex];
        int innerIndex = outerIndex - 1;
        while (innerIndex >= 0 && positions[innerIndex] > currentPosition) {
            positions[innerIndex + 1] = positions[innerIndex];
            innerIndex = innerIndex - 1;
        }
        positions[innerIndex + 1] = currentPosition;
    }
}

void test_sort(tz::Position *positions, const int size) {
    sortPositions(positions, size);
    for (int index = 0; index < size - 1; index++) {
        tz::Position currentPosition = positions[index];
        tz::Position nextPosition = positions[index + 1];
        assert(currentPosition < nextPosition);
    }
}

void sortPositionsTest() {
    tz::Position testCases[5] = {
        tz::Position("Nordor", 47, 11),
        tz::Position("Mordor", 47, 11),
        tz::Position("Zordor", 47, 11),
        tz::Position("Mordor", 48, 11),
        tz::Position("Mordor", 47, 12)
    };
    std::cout << "Test 1" << std::endl;
    test_sort(testCases, 5);
}

int main() {
    sortPositionsTest();
    return 0;
}
