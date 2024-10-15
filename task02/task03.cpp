#include <cassert>
#include <string>

class Position {
public:
    void set(const std::string &name, int x, int y);

    const std::string &getName() const {
        return name;
    }

    int getX() const {
        return x;
    }

    int getY() {
        return y;
    }

private:
    std::string name;
    int x = -1;
    int y = -1;
};

void Position::set(const std::string &name, int x, int y) {
    this->name = name;
    this->x = x;
    this->y = y;
}

void positionTest() {
    Position mordor;
    mordor.set("Mordor", 3, 4);
    assert(mordor.getName() == "Mordor");
    assert(mordor.getX() == 3);
    assert(mordor.getY() == 4);
}


int main() {
    positionTest();
}
