#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
// display the contents of the array
void showValues(const std::vector<int>& a);
// fill up array elements between low and high
void fillArray(std::vector<int>& a, int low, int high);
// return the highest value from the passing array
int maximum(const std::vector<int>& a);
// return the lowest value from the passing array
int minimum(const std::vector<int>& a);
// return the average of the passing array
double average(const std::vector<int>& a);
void printStats(const std::vector<int>& a);

int main() {
    int low{}, high{};
    std::vector<int>::size_type size{};

    std::cout << "Assignment 10 by Conor Ney\n\n";
    std::cout << "** This program will generate random integers between "
                 "[low] and [high] **\n";

    std::cout << "How many random integers would you like to create? ";
    std::cin >> size;

    // create a vector with a.size() determined by the users input
    std::vector<int> random_values(size);

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

    fillArray(random_values, low, high);

    std::cout << "The " << random_values.size() << " random integers between "
              << low << " and " << high << " are:\n";

    showValues(random_values);
    printStats(random_values);

    return 0;
}

void fillArray(std::vector<int>& a, int low, int high) {
    // seed random number generator
    srand(static_cast<unsigned>(time(0)));
    for (auto& num : a) {
        num = rand() % (high - low + 1) + low;
    }
}

void showValues(const std::vector<int>& a) {
    for (const auto& num : a) {
        std::cout << std::setw(6) << num;
    }
    std::cout << std::endl << std::endl;
}

int maximum(const std::vector<int>& a) {
    int max = a[0];
    for (const auto& num : a) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

int minimum(const std::vector<int>& a) {
    int min = a[0];
    for (const auto& num : a) {
        if (num < min) {
            min = num;
        }
    }
    return min;
}

double average(const std::vector<int>& a) {
    double avg;
    int sum = 0;

    for (const auto& num : a) {
        sum += num;
    }
    avg = static_cast<double>(sum) / a.size();
    return avg;
}

void printStats(const std::vector<int>& a) {
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "The greatest value from the random numbers is: " << maximum(a)
              << std::endl;
    std::cout << "The smallest value from the random numbers is: " << minimum(a)
              << std::endl;
    std::cout << "The average from the random numbers is: " << average(a)
              << std::endl;
}
