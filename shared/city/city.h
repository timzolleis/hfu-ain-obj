//
// Created by Tim Zolleis on 29.10.24.
//
#pragma once
#include <vector>
#include "../../shared/position/position.h"


#ifndef CITY_H
#define CITY_H

namespace tz {
    class City {
    private:
        Position position;
        std::string *pointsOfInterest;
        int currentSize = 0;

        void validateIndexOrThrow(int index) const;

        const Position &getPosition();

        friend std::ostream &operator<<(std::ostream &os, const City &city);

        static std::string *initializePointsOfInterest(const std::string pointsOfInterest[], int length);

        City(const Position &position, const std::string pointsOfInterest[], int poiLength);

        void resizePointsOfInterest(int newSize, int oldSize);

        int determineNewSize(const std::string &poiToRemove) const;

    public:
        City(const City &other);

        City(const std::string &name, int x, int y, std::string *pois, int length);

        City(const std::string &name, int x, int y);

        const std::string &getPOI(int index) const;

        void setPOI(int index, const std::string &poi) const;

        ~City();

        const std::string &getName() const;

        int getX() const;

        int getY() const;

        int getNumberOfPOIs() const;

        std::string &operator[](int index);

        const std::string &operator[](int index) const;

        City &operator=(const City &other);


        void add(const std::string &poiName);

        bool remove(const std::string &poiName);
    };
} // tz

#endif //CITY_H
