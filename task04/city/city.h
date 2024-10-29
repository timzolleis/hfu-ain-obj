//
// Created by Tim Zolleis on 29.10.24.
//
#pragma once
#include <string>
#include <vector>
#include "../../task03/position/position.h"


#ifndef CITY_H
#define CITY_H

namespace tz {
    class City {
    private:
        Position position;
        std::string *pointsOfInterest;

        void updateSize(int newSize);

        int currentSize = 0;

    public:
        City(const Position &position, const std::string pointsOfInterest[], int poiLength);

        ~City();

        const std::string &getName();

        int getX() const;

        int getY() const;

        unsigned long getNumberOfPOIs() const;

        const std::string &getPOI(int index);

        void setPOI(int index, const std::string &poi);
    };
} // tz

#endif //CITY_H
