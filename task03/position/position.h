//
// Created by Tim Zolleis on 22.10.24.
//
#include <string>

#ifndef POSITION_H
#define POSITION_H

namespace tz {
    class Position {
    public:
        Position(const std::string &name, int x, int y);

        const std::string &getName();

        int getX();

        int getY();

        int compare(Position &other);

    private:
        std::string name;
        int x;
        int y;
    };
}

#endif //POSITION_H
