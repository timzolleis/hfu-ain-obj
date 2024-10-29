//
// Created by Tim Zolleis on 29.10.24.
//

#include "city.h"

#include <iostream>


namespace tz {
    City::City(const Position &position, const std::string pointsOfInterest[], int poiLength): position(position) {
        this->pointsOfInterest = new std::string[poiLength];
        for (int i = 0; i < poiLength; i++) {
            this->pointsOfInterest[i] = pointsOfInterest[i];
        }
        this->currentSize = poiLength;
    }

    City::~City() {
        delete[] pointsOfInterest;
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

    const std::string &City::getPOI(const int index) {
        if (index >= this->getNumberOfPOIs()) {
            throw std::invalid_argument("Index out of bounds");
        }
        return this->pointsOfInterest[index];
    }

    void City::setPOI(const int index, const std::string &poi) {
        if (index >= this->getNumberOfPOIs()) {
            throw std::invalid_argument("Index out of bounds");
        }
        this->pointsOfInterest[index] = poi;
    }
}
