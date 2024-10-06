#include <cassert>
#include <stdexcept>

//Helper function to determine the current position at the start, since we pick digits from the right
int determinePosition(int number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    if (count % 2 == 0) {
        return 1;
    }
    return 0;
}


int alternatingCrossSum(int number) {
    if (number < 0) {
        throw std::invalid_argument("number must be positive");
    }
    int currentPosition = determinePosition(number);
    int sum = 0;
    while (number > 0) {
        if (currentPosition % 2 == 0) {
            sum += number % 10;
        } else {
            sum -= number % 10;
        }
        number = number / 10;
        currentPosition++;
    }
    return sum;
}

void alternatingCrossSumTest() {
    assert(alternatingCrossSum(471) == -2);
    assert(alternatingCrossSum(4711) == -3);
    assert(alternatingCrossSum(111) == 1);
    assert(alternatingCrossSum(0) == 0);
    try {
        alternatingCrossSum(-10);
        assert(false);
    } catch (std::invalid_argument &e) {
        assert(true);
    }
}


int main() {
    alternatingCrossSumTest();
    return 0;
}
