#include <cassert>
#include <iostream>
#include <ostream>
#include <string>

namespace tz {
    class Position {
    public:
        Position(const std::string &name, const int x, const int y): name(name), x(x), y(y) {
        }

        const std::string &getName() const {
            return this->name;
        }

        int getX() const {
            return this->x;
        }

        int getY() {
            return this->y;
        }

    private:
        std::string name;
        int x = -1;
        int y = -1;
    };
}

void positionTest() {
    std::string mordor = "mordor";
    tz::Position position(mordor, 47, 11);
    assert(position.getName() == "mordor");
    assert(position.getX() == 47);
    assert(position.getY() == 11);

    mordor[0] = 'X';
    assert(position.getName() == "mordor");
}


int main() {
    positionTest();
}
