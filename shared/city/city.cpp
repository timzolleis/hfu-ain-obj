//
// Created by Tim Zolleis on 29.10.24.
//

#include "city.h"

#include <iostream>
#include <ostream>


namespace tz {
    City::City(const City &other): position(other.position),
                                   pointsOfInterest(
                                       initializePointsOfInterest(other.pointsOfInterest, other.currentSize)),
                                   currentSize(other.currentSize) {
    }

    City::City(const std::string &name, int x, int y, std::string *pois, int length): City(Position(name, x, y), pois,
        length) {
    }


    City::City(const Position &position, const std::string pointsOfInterest[], int poiLength): position(position),
        pointsOfInterest(initializePointsOfInterest(pointsOfInterest, poiLength)), currentSize(poiLength) {
    }

    City::City(const std::string &name, int x, int y): position(Position(name, x, y)),
                                                       pointsOfInterest(nullptr) {
    }

    City::~City() {
        delete[] pointsOfInterest;
    }

    std::string *City::initializePointsOfInterest(const std::string *pointsOfInterest, int length) {
        if (length > 0 && pointsOfInterest == nullptr) {
            throw std::invalid_argument("Please provide matching pointer and length");
        }
        auto *result = new std::string[length];
        for (int i = 0; i < length; i++) {
            result[i] = pointsOfInterest[i];
        }
        return result;
    }


    const std::string &City::getName() const {
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

    void City::add(const std::string &poiName) {
        const int oldSize = this->currentSize;
        this->currentSize++;
        this->resizePointsOfInterest(this->currentSize, oldSize);
        this->setPOI(oldSize, poiName);
    }

    //This could be much smaller with std::remove_if, but im not sure if we're allowed to use that^^
    bool City::remove(const std::string &poiName) {
        const int newSize = determineNewSize(poiName);
        if (newSize == this->currentSize) {
            return false;
        }
        auto *newPointsOfInterest = new std::string[newSize];
        int newIndex = 0;
        for (int i = 0; i < this->currentSize; ++i) {
            auto pointOfInterest = this->pointsOfInterest[i];
            if (pointOfInterest != poiName) {
                newPointsOfInterest[newIndex++] = pointOfInterest;
            }
        }
        delete[] this->pointsOfInterest;
        this->pointsOfInterest = newPointsOfInterest;
        this->currentSize = newSize;
        return true;
    }

    int City::determineNewSize(const std::string &poiToRemove) const {
        int newSize = 0;
        for (int i = 0; i < this->currentSize; i++) {
            if (this->pointsOfInterest[i] != poiToRemove) {
                newSize++;
            }
        }
        return newSize;
    }


    void City::resizePointsOfInterest(int newSize, int oldSize) {
        auto *newPointsOfInterest = new std::string[newSize];
        for (int i = 0; i < oldSize; i++) {
            newPointsOfInterest[i] = this->pointsOfInterest[i];
        }
        delete[] this->pointsOfInterest;
        this->pointsOfInterest = newPointsOfInterest;
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

    const Position &City::getPosition() {
        return this->position;
    }

    std::ostream &operator<<(std::ostream &os, const City &city) {
        os << city.position;
        for (int i = 0; i < city.currentSize; i++) {
            os << city.pointsOfInterest[i] << std::endl;
        }
        return os;
    }

    std::string &City::operator[](int index) {
        this->validateIndexOrThrow(index);
        return pointsOfInterest[index];
    }

    const std::string &City::operator[](int index) const {
        this->validateIndexOrThrow(index);
        return pointsOfInterest[index];
    }

    City &City::operator=(const City &other) {
        if (this != &other) {
            this->position = other.position;
            this->currentSize = other.currentSize;
            delete[] this->pointsOfInterest;
            this->pointsOfInterest = initializePointsOfInterest(other.pointsOfInterest, other.currentSize);
        }
        return *this;
    }
}
