#include <iostream>
unsigned long sum(unsigned int n);
unsigned long sum_recursive(unsigned int n);

int main() {
    int n{};
    unsigned long sum_i{}, sum_r{};

    std::cout << "Lab Exercise 12-2 by Conor Ney\n\n";
    std::cout
        << "** This program will find the cumulative sum of a number **\n";
    std::cout << "Enter a non-negative number: ";
    std::cin >> n;
    while (n < 0) {
        std::cout << "The number should be non-negative. Enter a new number: ";
        std::cin >> n;
    }

    // cast user input to unsigned after validating it as non-negative
    unsigned u_n{static_cast<unsigned>(n)};

    std::cout << "Calculating cumulative sum using an iterative method...\n";
    sum_i = sum(u_n);
    std::cout << "The cumulative sum from 1 to " << n << " is " << sum_i
              << '\n';

    std::cout << "Calculating cumulative sum using an recursive method...\n";
    sum_r = sum_recursive(u_n);
    std::cout << "The cumulative sum from 1 to " << n << " is " << sum_r
              << '\n';

    return 0;
}

unsigned long sum(unsigned int n) {
    unsigned long sum{};
    for (unsigned num{n}; num > 0; num--) {
        sum += num;
    }
    return sum;
}

unsigned long sum_recursive(unsigned int n) {
    if (n == 1) {
        return n;
    }
    return n + sum_recursive(n - 1);
}
