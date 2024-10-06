//
// Created by Tim Zolleis on 02.10.24.
//


#include <cassert>
#include <stdexcept>

bool toInt(const char character, int *theInt) {
    if (character >= '0' && character <= '9') {
        //Subtracting the ASCII value of '0' from the character gives us the integer value of the character
        *theInt = character - '0';
        return true;
    }
    return false;
}

void toIntTest() {
    int result = 0;
    int isValid = toInt('1', &result);
    assert(isValid && result == 1);
    int isValid2 = toInt('9', &result);
    assert(isValid2 && result == 9);
    int isValid3 = toInt('a', &result);
    assert(!isValid3);
}


int main() {
    toIntTest();
}
