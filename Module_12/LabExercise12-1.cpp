#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
// display the contents of the array
void showValues(int* arr, std::size_t size);
// fill up array elements between low and high
int* fillArray(std::size_t size, int low, int high);

int main() {
    int low{}, high{};
    std::size_t size{};

    std::cout << "Assignment 12 by Conor Ney\n\n";
    std::cout << "** This program will generate random integers between "
                 "[low] and [high] **\n";
    std::cout << "How many random integers would you like to create? ";
    std::cin >> size;
    std::cout << "Please enter an integer value for the lower bound: ";
    std::cin >> low;
    std::cout << "Please enter an integer value for the upper bound: ";
    std::cin >> high;

    while (high < low) {
        std::cout
            << "The upper bound must be a value less than the lower bound. ";
        std::cout << "(Less than " << low << ").\n";
        std::cout << "Please enter an integer value for the upper bound: ";
        std::cin >> high;
    }
    std::cout << std::endl << std::endl;

    int* array{};
    array = fillArray(size, low, high);

    std::cout << "The " << size << " random integers between " << low << " and "
              << high << " are:\n";
    showValues(array, size);

    // deallocate memory for array
    delete[] array;
    array = nullptr;

    return 0;
}

// dynamically alloactes memory for an array of size `size`. fills the array
// with random values within the range `low` - `high`. returns a pointer to the
// array. memory must be released by caller
int* fillArray(std::size_t size, int low, int high) {
    int* array = new int[size];
    // seed random number generator
    std::srand(static_cast<unsigned>(time(0)));
    for (std::size_t i{0}; i < size; i++) {
        array[i] = rand() % (high - low + 1) + low;
    }
    return array;
}
void showValues(int* arr, std::size_t size) {
    for (std::size_t i{0}; i < (size / 10); i++) {
        for (std::size_t j{0}; j < 10; j++) {
            std::cout << std::setw(6) << arr[i * 10 + j];
        }
        std::cout << std::endl << std::endl;
    }
}
