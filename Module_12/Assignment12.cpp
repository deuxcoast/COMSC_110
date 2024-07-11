
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
// display the contents of the array
void showValues(int* arr, std::size_t size);
// fill up array elements between low and high
int* fillArray(std::size_t size, int low, int high);
// combine both two arrays into a single array and return pointer
int* combineArrays(int* arr1, int* arr2, std::size_t size1, std::size_t size2);

void sortArray(int* array, std::size_t size);
void swap(int*, int*);

int main() {
    int lowA{}, highA{}, lowB{}, highB{};
    int sizeASigned{}, sizeBSigned{};
    std::size_t sizeA{}, sizeB{};
    int* arrayA{};
    int* arrayB{};
    int* arrayC{};

    std::cout << "Assignment 12 by Conor Ney\n\n";
    std::cout << "** This program will combine two arrays into one **\n\n";

    // -------------------------------------------------------------------------
    // Array A
    std::cout << "Please enter a positive integer for the size of the "
                 "first array: ";
    std::cin >> sizeASigned;
    while (sizeASigned < 0) {
        std::cout << "The size of the array should be greater than 0. Please "
                     "enter a new value: ";
        std::cin >> sizeASigned;
    }
    sizeA = static_cast<std::size_t>(sizeASigned);
    std::cout << "Please enter an integer value for the lower bound of the "
                 "first array: ";
    std::cin >> lowA;
    std::cout << "Please enter an integer value for the upper bound of the "
                 "first array: ";
    std::cin >> highA;

    while (highA < lowA) {
        std::cout << "The upper bound must be a value less than the lower "
                     "bound. ";
        std::cout << "(Less than " << lowA << ").\n";
        std::cout << "Please enter an integer value for the upper bound: ";
        std::cin >> highA;
    }
    std::cout << std::endl << std::endl;

    arrayA = fillArray(sizeA, lowA, highA);

    std::cout << "The " << sizeA << " random integers between " << lowA
              << " and " << highA << " are:\n";
    showValues(arrayA, sizeA);

    // -------------------------------------------------------------------------
    // Array B
    std::cout << "Please enter a positive integer for the size of the "
                 "second array: ";
    std::cin >> sizeBSigned;
    while (sizeBSigned < 0) {
        std::cout << "The size of the array should be greater than 0. Please "
                     "enter a new value: ";
        std::cin >> sizeBSigned;
    }
    sizeB = static_cast<std::size_t>(sizeBSigned);
    std::cout << "Please enter an integer value for the lower bound of the "
                 "second array: ";
    std::cin >> lowB;
    std::cout << "Please enter an integer value for the upper bound of the "
                 "second array: ";
    std::cin >> highB;

    while (highB < lowB) {
        std::cout << "The upper bound must be a value less than the lower "
                     "bound. ";
        std::cout << "(Less than " << lowB << ").\n";
        std::cout << "Please enter an integer value for the upper bound: ";
        std::cin >> highB;
    }
    std::cout << std::endl << std::endl;

    arrayB = fillArray(sizeB, lowB, highB);

    std::cout << "The " << sizeB << " random integers between " << lowB
              << " and " << highB << " are:\n";
    showValues(arrayB, sizeB);

    // -------------------------------------------------------------------------
    // Combine Array A and Array B into Array C
    arrayC = combineArrays(arrayA, arrayB, sizeA, sizeB);

    std::cout << "\n\n";
    std::cout << "Combine two arrays into ONE...\n";
    std::cout << "The content of the new array:\n";

    // calculate size of arrayC
    std::size_t sizeC{sizeA + sizeB};
    showValues(arrayC, sizeC);

    std::cout << "\n\n";

    // -------------------------------------------------------------------------
    // Sort arrayC
    std::cout << "The content of the new array after sorting:\n";

    sortArray(arrayC, sizeC);
    showValues(arrayC, sizeC);

    // deallocate memory for arrays
    delete[] arrayA;
    arrayA = nullptr;
    delete[] arrayB;
    arrayB = nullptr;
    delete[] arrayC;
    arrayC = nullptr;

    return 0;
}

// dynamically alloactes memory for an array of size `size`. fills the array
// with random values within the range `low` - `high`. returns a pointer to
// the array. memory must be released by caller
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

int* combineArrays(int* arr1, int* arr2, std::size_t size1, std::size_t size2) {
    int* newArray{new int[size1 + size2]{}};

    // fill in first half of newArray with elements from arr1
    for (std::size_t i{0}; i < size1; i++) {
        newArray[i] = arr1[i];
    }

    // fill in second half of newArray with elements from arr2
    for (std::size_t i{0}; i < size1; i++) {
        newArray[size1 + i] = arr2[i];
    }
    return newArray;
}

// Implements insertion sort
void sortArray(int* numbers, std::size_t size) {
    for (std::size_t i{1}; i < size; i++) {
        // int key{*(numbers + i)};
        int key{numbers[i]};
        int j{static_cast<int>(i) - 1};

        while (j >= 0 && *(numbers + j) > key) {
            swap(numbers + j, (numbers + (j + 1)));
            j--;
        }
    }
}

// swaps two elements in an array
void swap(int* a, int* b) {
    int tmp{*a};
    *a = *b;
    *b = tmp;
}
