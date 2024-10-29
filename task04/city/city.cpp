//
// Created by Tim Zolleis on 29.10.24.
//

#include "city.h"


namespace tz {
    City::City(const Position &position, const std::string pois[], int poiLength): position(position) {
        for (int i = 0; i < poiLength; i++) {
            this->pointsOfInterest.push_back(pois[i]);
        }
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

    unsigned long City::getNumberOfPOIs() const {
        return this->pointsOfInterest.size();
    }

    const std::string &City::getPOI(const int index) {
        return this->pointsOfInterest.at(index);
    }

    void City::setPOI(const int index, const std::string &poi) {
        this->pointsOfInterest.at(index) = poi;
    }
}
