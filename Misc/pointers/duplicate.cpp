#include <iostream>
#include <memory>
#include <ostream>
int* duplicateArray(int*, int);
int main() {
    int* ptr = nullptr;
    int my_array[5] = {10, 30, 50, 70, 90};

    ptr = duplicateArray(my_array, 5);

    for (int i = 0; i < 5; i++) {
        std::cout << *(ptr + i) << std::endl;
    }
    delete[] ptr;
    ptr = nullptr;
}

int* duplicateArray(int* arr, int size) {
    int* new_array = nullptr;
    // validate size. if invalid size then return a null pointer
    if (size <= 0) {
        return nullptr;
    }
    new_array = new int[size];

    for (int i = 0; i < size; i++) {
        new_array[i] = arr[i];
    }
    return new_array;
    std::unique_ptr<>
}
