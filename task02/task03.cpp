#include <cassert>
#include <string>

namespace tz {
    class Position {
    public:
        void set(const std::string &name, int x, int y) {
            this->name = name;
            this->x = x;
            this->y = y;
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

    void positionTest() {
        Position mordor;
        mordor.set("Mordor", 3, 4);
        assert(mordor.getName() == "Mordor");
        assert(mordor.getX() == 3);
        assert(mordor.getY() == 4);
    }
}



int main() {
    tz::positionTest();
}
