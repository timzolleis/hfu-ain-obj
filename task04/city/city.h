//
// Created by Tim Zolleis on 29.10.24.
//
#pragma once
#include <string>
#include <vector>


#ifndef CITY_H
#define CITY_H
#include "../poi//poi.h"

namespace tz {
    class City {
    private:
        std::string name;
        int x;
        int y;
        std::vector<POI> pointsOfInterest;

    public:
        City(const std::string &name, int x, int y);

        const std::string &getName();

        int getX() const;

        int getY() const;

        unsigned long getNumberOfPOIs() const;

        POI &getPOI(int index);

        void setPOI(int index, const POI &poi);
    };
} // tz

#endif //CITY_H
