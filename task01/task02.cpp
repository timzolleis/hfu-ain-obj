//
// Created by Tim Zolleis on 02.10.24.
//


#include <cassert>

bool toInt(const char character, int *theInt) {
    if (character >= '0' && character <= '9') {
        //Subtracting the ASCII value of '0' from the character gives us the integer value of the character
        *theInt = character - '0';
        return true;
    }
    return false;
}

void toIntTest() {
    int result = -1;
    const int isValid = toInt('0', &result);
    assert(isValid && result == 0);
    result = -1;
    const int isValid2 = toInt('9', &result);
    assert(isValid2 && result == 9);
    result = -1;
    const int isValid3 = toInt('x', &result);
    assert(!isValid3 && result == -1);
}

int main() {
    toIntTest();
}
