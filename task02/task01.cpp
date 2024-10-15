#include <cassert>

bool toInt(const char character, int *theInt) {
    if (character >= '0' && character <= '9') {
        //Subtracting the ASCII value of '0' from the character gives us the integer value of the character
        *theInt = character - '0';
        return true;
    }
    return false;
}

void toIntTestAccordingToTask2() {
    int number = -1;
    toInt('0', &number);
    assert(number == 0);
    number = -1;
    toInt('9', &number);
    assert(number == 9);
    number = -1;
    toInt('x', &number);
    assert(number == -1);
}

int main() {
    toIntTestAccordingToTask2();
}