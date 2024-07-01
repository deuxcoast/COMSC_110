#include <iomanip>
#include <iostream>

double calculate_cost(int);

int main() {
    int units_sold;
    double cost;

    std::cout << "** This program will calculate the cost of software "
                 "purchased. **\n";

    std::cout << "Please enter the number of units sold: ";
    std::cin >> units_sold;

    while (units_sold < 0) {
        std::cout
            << "Error! The number of units sold should be greater than 0.\n";
        std::cout << "Please enter the number of units sold: ";
        std::cin >> units_sold;
    }
    cost = calculate_cost(units_sold);

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "The total charge for " << units_sold << " is $" << cost
              << std::endl;
}

double calculate_cost(int units) {
    const double RETAIL = 99.00;
    double discount = 0;
    if (units > 100) {
        discount = 0.45;
    } else if (units > 50) {
        discount = 0.35;
    } else if (units > 20) {
        discount = 0.25;
    } else if (units > 10) {
        discount = 0.15;
    }

    double pre_discount_cost = RETAIL * units;
    double cost = pre_discount_cost - (pre_discount_cost * discount);
    return cost;
}
