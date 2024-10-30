//
// Created by Tim Zolleis on 29.10.24.
//

#include "city.h"

#include <iostream>


namespace tz {
    //This approach can be used if we HAVE to use initializers instead of a constructor
    /*std::string *initializeArray(const std::string pointsOfInterest[], int length) {
        std::string *result = new std::string[length];
        for (int i = 0; i < length; i++) {
            result[i] = pointsOfInterest[i];
        }
        return result;
    }*/

    City::City(const Position &position, const std::string pointsOfInterest[], int poiLength): position(position),
        currentSize(poiLength) {
        this->pointsOfInterest = new std::string[poiLength];
        for (int i = 0; i < poiLength; i++) {
            this->pointsOfInterest[i] = pointsOfInterest[i];
        }
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

    const std::string &City::getPOI(const int index) const {
        if (!this->validateIndex(index)) {
            throw std::invalid_argument("Index out of bounds");
        }
        return this->pointsOfInterest[index];
    }

    void City::setPOI(const int index, const std::string &poi) const {
        if (!this->validateIndex(index)) {
            throw std::invalid_argument("Index out of bounds");
        }
        this->pointsOfInterest[index] = poi;
    }

    bool City::validateIndex(int index) const {
        return index >= 0 && index < this->getNumberOfPOIs();
    }
}
