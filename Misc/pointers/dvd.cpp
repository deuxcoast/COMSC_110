#include <iomanip>
#include <iostream>
#include <ostream>
void displayarray7(int (*)[7]);
int main() {}

void displayarray7(int (*ptr)[7], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            std::cout << std::setw(4) << *(*(ptr + i) + j);
        }
        std::cout << std::endl;
    }
}
