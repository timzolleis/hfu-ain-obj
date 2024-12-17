//
// Created by Tim Zolleis on 03.12.24.
//
#pragma once
#include <locale>

#include "CustomChar.h"
#ifndef SORT_H
#define SORT_H

template<typename T>
bool greaterThan(T a, T b) {
    return a > b;
}

template<>
inline bool greaterThan<char>(char a, char b) {
    const char aLower = std::tolower(a);
    const char bLower = std::tolower(b);
    if (aLower == bLower) {
        return std::isupper(a) > std::isupper(b);
    }
    return aLower > bLower;
}


template<typename T>
void sort(T *elements, int size) {
    for (int outerIndex = 1; outerIndex < size; ++outerIndex) {
        T currentElement = elements[outerIndex];
        int innerIndex = outerIndex - 1;
        while (innerIndex >= 0 && greaterThan(elements[innerIndex], currentElement)) {
            elements[innerIndex + 1] = elements[innerIndex];
            innerIndex = innerIndex - 1;
        }
        elements[innerIndex + 1] = currentElement;
    }
}
#endif //SORT_H
