#include <cassert>
#include <stdexcept>
#include <string>

namespace tz {
    bool toInt(const char character, int *theInt) {
        if (character >= '0' && character <= '9') {
            //Subtracting the ASCII value of '0' from the character gives us the integer value of the character
            *theInt = character - '0';
            return true;
        }
        return false;
    }

    int decode(const std::string &line) {
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
        const std::string lines[] = {
            "1abc2",
            "pqr3stu8vwx",
            "a1b2c3d4e5f",
            "treb7uchet"
        };
        constexpr int expected[]{12, 38, 15, 77};
        for (int i = 0; i < 4; ++i) {
            assert(decode(lines[i]) == expected[i]);
        }
        try {
            decode("no digit");
            assert(false);
        } catch (std::invalid_argument &e) {
            assert(true);
        }
    }
}

int main() {
    tz::decodeTest();
}
