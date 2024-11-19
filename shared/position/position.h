//
// Created by Tim Zolleis on 22.10.24.
//
#pragma once
#include <string>

#ifndef POSITION_H
#define POSITION_H

namespace tz {
    class Position {
    public:
        Position(const std::string &name, int x, int y);

        const std::string &getName() const;

        int getX() const;

        int getY() const;

        bool operator==(const Position &other);

        bool operator!=(const Position &other);

        int operator<=>(const Position &other);

    private:
        int compare(const Position &other);

        friend std::ostream &operator<<(std::ostream &os, const Position &city);

        std::string name;
        int x;
        int y;
    };
}

#endif //POSITION_H
