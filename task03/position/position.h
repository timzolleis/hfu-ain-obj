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

        const std::string &getName();

        int getX() const;

        int getY() const;

        int compare(const Position &other);

    private:
        std::string name;
        int x;
        int y;
    };
}

#endif //POSITION_H
