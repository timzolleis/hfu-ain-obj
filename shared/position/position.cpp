//
// Created by Tim Zolleis on 22.10.24.
//

#include "position.h"

#include <ostream>

namespace tz {
    Position::Position(const std::string &name, const int x, const int y): name(name), x(x), y(y) {
    }

    const std::string &Position::getName() const {
        return this->name;
    }

    int Position::getX() const {
        return this->x;
    }

    int Position::getY() const {
        return this->y;
    }

    bool Position::operator==(const Position &other) {
        return this->compare(other) == 0;
    }

    bool Position::operator!=(const Position &other) {
        return this->compare(other) != 0;
    }

    int Position::operator<=>(const Position &other) {
        return this->compare(other);
    }

    int Position::compare(const Position &other) {
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

    std::ostream &operator<<(std::ostream &os, const Position &position) {
        os << position.getName() << ", x = " << position.getX() << ", y = " << position.getY() << std::endl;
        return os;
    }
}
