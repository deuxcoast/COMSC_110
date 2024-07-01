#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
// display the contents of the array
void showValues(const int a[], int size);
// fill up array elements between low and high
void fillArray(int a[], int size, int low, int high);
// return the highest value from the passing array
int maximum(const int a[], int size);
// return the lowest value from the passing array
int minimum(const int a[], int size);
// return the average of the passing array
double average(const int a[], int size);
void printStats(const int a[], int size);

int main() {
    const int SIZE = 10;
    int low, high;
    int random_values[SIZE];

    std::cout << "Assignment 9 by Conor Ney\n\n";
    std::cout << "** This program will generate 10 random integers between "
                 "[low] and [high] **\n";

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

    fillArray(random_values, SIZE, low, high);

    std::cout << "The " << SIZE << " random integers between " << low << " and "
              << high << " are:\n";

    showValues(random_values, SIZE);
    printStats(random_values, SIZE);

    return 0;
}

void fillArray(int a[], int size, int low, int high) {
    // seed random number generator
    srand(time(0));
    for (int i = 0; i < size; i++) {
        a[i] = rand() % (high - low + 1) + low;
    }
}

void showValues(const int a[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(6) << a[i];
    }
    std::cout << std::endl << std::endl;
}

int maximum(const int a[], int size) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int minimum(const int a[], int size) {
    int min = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

double average(const int a[], int size) {
    double avg;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    avg = static_cast<double>(sum) / size;
    return avg;
}

void printStats(const int a[], int size) {
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "The greatest value from the random numbers is: "
              << maximum(a, size) << std::endl;
    std::cout << "The smallest value from the random numbers is: "
              << minimum(a, size) << std::endl;
    std::cout << "The average from the random numbers is: " << average(a, size)
              << std::endl;
}
