#include <iomanip>
#include <iostream>
#include <ostream>
void celsius(int, int);

int main() {
    int low, high;

    std::cout << "Enter the low value: ";
    std::cin >> low;
    std::cout << "Enter the high value: ";
    std::cin >> high;

    if (low <= high) {
        celsius(low, high);
    } else {
        celsius(high, low);
    }

    return 0;
}

void celsius(int low, int high) {
    std::cout << "**Temperature Convert Table**" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "  Fahrenheit       Celsius" << std::endl;
    std::cout << "=============================" << std::endl;

    for (int i = low; i <= ((high - low) + low); i++) {
        int c = ((i - 32) * 5) / 9;
        std::cout << std::setw(9) << i;
        std::cout << std::setw(14) << c << std::endl;
    }
}
