// COMSC-110  Module 10 Chapter 8 Lab Exercise 10
// LabExercise10_sample.cpp
// This program demonstrates how to fill up an int array with random values from
// Assignment10.cpp Write 3 functions by pasing an array to search and sort the
// array

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

// Function prototype
void showValues(const int[], int);     // From Assignment 9
void fillArray(int[], int, int, int);  // From Assignment 9

bool searchValue(const int[], int, int);  // For Lab Exercise 10
void sortArrayAscending(int[], int);      // For Lab Exercise 10
void sortArrayDescending(int[], int);     // For Lab Exercise 10

int main() {
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE];
    srand(static_cast<unsigned>(time(0)));
    int low = 0, high = 1, value = 0;

    cout << "Lab Exercise 10 by Conor Ney" << endl << endl;

    cout << "**This program will generate 10 random integers between [low] and "
            "[high]**"
         << endl;

    cout << "Please enter an integer value for the lower bound: ";
    cin >> low;
    cout << "Please enter an integer value for the higher bound: ";
    cin >> high;

    if (low >= high)  // swap the low and high
    {
        int tmp = low;
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
    fillArray(numbers, ARRAY_SIZE, low, high);
    cout << "The 10 random integers between " << low << " and " << high
         << " are:" << endl;
    cout << fixed << setprecision(2);
    showValues(numbers, ARRAY_SIZE);

    if (searchValue(numbers, ARRAY_SIZE, value))
        cout << value << " is found from the random numbers!" << endl;
    else
        cout << value << " can't be found from the random numbers!" << endl;

    cout << "Display the 10 random integers in an ascending order: " << endl;
    sortArrayAscending(numbers, ARRAY_SIZE);
    showValues(numbers, ARRAY_SIZE);

    cout << "Display the 10 random integers in a descending order: " << endl;
    sortArrayDescending(numbers, ARRAY_SIZE);
    showValues(numbers, ARRAY_SIZE);

    return 0;
}

void showValues(const int nums[], int size) {
    for (int index = 0; index < size; index++)
        cout << setw(4) << nums[index] << " ";
    cout << endl;
}
// This function will fill out the nums array with random values between low and
// high
void fillArray(int nums[], int size, int low, int high) {
    for (int index = 0; index < size; index++)
        nums[index] = rand() % (high - low) + low;
    cout << endl;
}

bool searchValue(const int nums[], int size, int value) {
    bool found = false;
    // write a for-loop to search for the matched value
    for (int i = 0; i < size; i++) {
        if (nums[i] == value) {
            found = true;
            break;
        }
    }
    return found;
}

// Implements insertion sort
void sortArrayAscending(int numbers[], int size) {  // sort in ascending order
    for (int i = 1; i < size; i++) {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key) {
            swap(numbers[j], numbers[j + 1]);
            j--;
        }
    }
}

void sortArrayDescending(int numbers[], int size) {  // sort in ascending order
    for (int i = 1; i < size; i++) {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] < key) {
            swap(numbers[j], numbers[j + 1]);
            j--;
        }
    }
}

// swaps two elements in an array
void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
