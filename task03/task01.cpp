#include <cassert>

void sort(int *numbers, int size) {
    for (int i = 1; i < size; ++i) {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

void test_sort(int *numbers, const int size) {
    sort(numbers, size);
    for (int i = 0; i < size - 1; i++) {
        assert(numbers[i] <= numbers[i + 1]);
    }
}


void sortTest() {
    int testCases[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    for (int i = 0; i < 4; i++) {
        test_sort(testCases[i], 4);+
    }
}

int main() {
    sortTest();
    return 0;
}
