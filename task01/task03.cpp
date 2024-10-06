#include <assert.h>
#include <stdexcept>

bool toInt(const char character, int *theInt) {
    if (character >= '0' && character <= '9') {
        //Subtracting the ASCII value of '0' from the character gives us the integer value of the character
        *theInt = character - '0';
        return true;
    }
    return false;
}


int decode(const char *line) {
    int firstDigit = -1, lastDigit = -1, currentDigit;
    for (int iterator = 0; line[iterator] != '\0'; ++iterator) {
        if (toInt(line[iterator], &currentDigit)) {
            if (firstDigit == -1) firstDigit = currentDigit;
            lastDigit = currentDigit;
        }
    }
    if (firstDigit == -1) throw std::invalid_argument("no digits found");
    return (firstDigit * 10) + lastDigit;
}

void decodeTest() {
    assert(decode("1xyz2") == 12);
    assert(decode("abc3pqr8ijk") == 38);
    assert(decode("x1y2z3v4w5q") == 15);
    assert(decode("hello7world") == 77);
}

int main() {
    decodeTest();
    return 0;
}
