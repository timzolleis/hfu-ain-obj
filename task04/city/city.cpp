//
// Created by Tim Zolleis on 29.10.24.
//

#include "city.h"

#include <iostream>


namespace tz {
    City::City(const Position &position, const std::string pointsOfInterest[], int poiLength): position(position),
        pointsOfInterest(initializePointsOfInterest(pointsOfInterest, poiLength)), currentSize(poiLength) {
    }

    City::~City() {
        delete[] pointsOfInterest;
    }

    std::string *City::initializePointsOfInterest(const std::string pointsOfInterest[], int length) {
        auto *result = new std::string[length];
        for (int i = 0; i < length; i++) {
            result[i] = pointsOfInterest[i];
        }
        return result;
    }


    const std::string &City::getName() {
        return this->position.getName();
    }

    int City::getX() const {
        return this->position.getX();
    }

    int City::getY() const {
        return this->position.getY();
    }

    int City::getNumberOfPOIs() const {
        return this->currentSize;
    }

    const std::string &City::getPOI(const int index) const {
        this->validateIndexOrThrow(index);
        return this->pointsOfInterest[index];
    }

    void City::setPOI(const int index, const std::string &poi) const {
        this->validateIndexOrThrow(index);
        this->pointsOfInterest[index] = poi;
    }

    void City::validateIndexOrThrow(int index) const {
        if (index < 0 || index >= this->getNumberOfPOIs()) {
            throw std::invalid_argument("Index out of bounds");
        }
    }
}
