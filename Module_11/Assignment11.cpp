#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>

using namespace std;

void showValues(const int*, int);
void fillArray(int*, int, int, int);
bool searchValue(const int*, int, int);
void sortArray(int*, int);
void swap(int*, int*);
void printStats(int*, int);

int main() {
    constexpr int kArraySize{50};
    int numbers[kArraySize];

    int low{}, high{}, value{};

    cout << "Assignment 11 by Conor Ney" << endl << endl;

    cout << "**This program will generate 50 random integers between [low] and "
            "[high]**"
         << endl;

    cout << "Please enter an integer value for the lower bound: ";
    cin >> low;
    cout << "Please enter an integer value for the higher bound: ";
    cin >> high;

    if (low >= high)  // swap the low and high
    {
        int tmp{low};
        low = high;
        high = tmp;
    }

    cout << "Please enter an value between " << low << " and " << high
         << " to search: ";
    cin >> value;
    while (value < low || value >= high) {
        cout << "The value to search for should be within the range." << endl;
        cout << "Please enter an value between " << low << " and " << high
             << " to search: ";
        cin >> value;
    }

    // fill out the random numbers in the array
    fillArray(numbers, kArraySize, low, high);
    cout << "The 50 random integers between " << low << " and " << high
         << " are:" << endl;
    cout << fixed << setprecision(2);
    showValues(numbers, kArraySize);

    if (searchValue(numbers, kArraySize, value))
        cout << value << " is found from the random numbers!" << endl;
    else
        cout << value << " can't be found from the random numbers!" << endl;

    cout << "Display the 10 random integers in an ascending order: " << endl;
    sortArray(numbers, kArraySize);
    showValues(numbers, kArraySize);

    return 0;
}

void showValues(const int* nums, int size) {
    // show values with 10 numbers per row
    for (int i{0}; i < (size / 10); i++) {
        for (int j{0}; j < 10; j++) {
            cout << setw(4) << *(nums + (i * 10) + j) << " ";
        }
        // new line every 10 numbers
        cout << endl;
    }
}
// This function will fill out the nums array with random values between low and
// high
void fillArray(int* nums, int size, int low, int high) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i{0}; i < size; i++)
        *(nums + i) = rand() % (high - low) + low;
}

bool searchValue(const int* nums, int size, int value) {
    bool found = false;
    // write a for-loop to search for the matched value
    for (int i{0}; i < size; i++) {
        if (*(nums + i) == value) {
            found = true;
            break;
        }
    }
    return found;
}

// Implements insertion sort
void sortArray(int* numbers, int size) {
    for (int i{1}; i < size; i++) {
        int key{*(numbers + i)};
        int j{i - 1};

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
