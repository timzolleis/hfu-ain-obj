//
// Created by Tim Zolleis on 09.12.24.
//

#ifndef CUSTOMCHAR_H
#define CUSTOMCHAR_H
#include <locale>


class CustomChar {
private:
    char value;

public:
    char getValue() const {
        return this->value;
    }

    void setValue(char value) {
        this->value = value;
    }


    std::strong_ordering operator<=>(const CustomChar &other) const {
        char thisLower = std::tolower(this->value);
        char otherLower = std::tolower(other.value);
        if (thisLower == otherLower) {
            // Ensure lowercase comes before uppercase
            if (this->value != other.value) {
                return std::isupper(this->value) <=> std::isupper(other.value);
            }
            return std::strong_ordering::equal;
        }
        return thisLower <=> otherLower;
    }
};


#endif //CUSTOMCHAR_H
