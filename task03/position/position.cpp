//
// Created by Tim Zolleis on 22.10.24.
//

#include "position.h"

namespace tz {
    Position::Position(const std::string &name, const int x, const int y): name(name), x(x), y(y) {
    }

    const std::string &Position::getName() {
        return this->name;
    }

    int Position::getX() {
        return this->x;
    }

    int Position::getY() {
        return this->y;
    }

    int Position::compare(Position &other) {
        if (this->name != other.name) {
            return this->name < other.name ? -1 : 1;
        }
        if (this->x != other.x) {
            return this->x < other.x ? -1 : 1;
        }
        if (this->y != other.y) {
            return this->y < other.y ? -1 : 1;
        }
        return 0;
    }
}
