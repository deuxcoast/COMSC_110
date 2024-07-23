#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>

void printArray(double* d_ptr, int size);
void fillDoubleArray(double* d_ptr, int size, int low, int high, int digits);

int main() {
    constexpr int kSize{20};
    double arr[kSize];
    fillDoubleArray(arr, kSize, -50, 50, 3);
    printArray(arr, kSize);
}

void fillDoubleArray(double* d_ptr, int size, int low, int high, int digits) {
    int precision_mod{static_cast<int>(std::pow(10.0, digits))};
    srand(static_cast<unsigned>(time(0)));

    if (low > high) {
        int temp{low};
        low = high;
        high = temp;
    }

    for (int i{}; i < size; i++) {
        double num{rand() % (high - low) + low +
                   rand() % precision_mod * (1.0 / precision_mod)};
        d_ptr[i] = num;
    }
}

void printArray(double* d_ptr, int size) {
    for (int i{}; i < size; i++) {
        if (i % 10 == 0) {
            std::cout << '\n';
        }
        std::cout << std::fixed << std::setprecision(3);
        std::cout << std::setw(10) << d_ptr[i];
    }
}
