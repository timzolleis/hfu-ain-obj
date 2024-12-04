//
// Created by Tim Zolleis on 03.12.24.
//
#pragma once
#include <locale>
#ifndef SORT_H
#define SORT_H

template<typename T>
void sort(T *elements, int size) {
    for (int outerIndex = 1; outerIndex < size; ++outerIndex) {
        T currentElement = elements[outerIndex];
        int innerIndex = outerIndex - 1;
        while (innerIndex >= 0 && std::tolower(elements[innerIndex]) > std::tolower(currentElement)) {
            elements[innerIndex + 1] = elements[innerIndex];
            innerIndex = innerIndex - 1;
        }
        elements[innerIndex + 1] = currentElement;
    }
}


void sort(char *characters, int size) {
    sort<char>(characters, size);
    for (int outerIndex = 1; outerIndex < size; ++outerIndex) {
        char currentElement = characters[outerIndex];
        char nextElement = characters[outerIndex + 1];
        if (currentElement == std::toupper(nextElement)) {
            char currentTemp = currentElement;
            characters[outerIndex] = nextElement;
            characters[outerIndex + 1] = currentTemp;
        }
    }
}

#endif //SORT_H
