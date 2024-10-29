//
// Created by Tim Zolleis on 29.10.24.
//

#include "city.h"

namespace tz {
    City::City(const std::string &name, const int x, const int y): name(name), x(x), y(y) {
    }

    const std::string &City::getName() {
        return this->name;
    }

    int City::getX() const {
        return this->x;
    }

    int City::getY() const {
        return this->y;
    }

    unsigned long City::getNumberOfPOIs() const {
        return this->pointsOfInterest.size();
    }

    POI &City::getPOI(const int index) {
        return this->pointsOfInterest.at(index);
    }

    void City::setPOI(const int index, const POI &poi) {
        this->pointsOfInterest.at(index) = poi;
    }
}
