#include <iostream>
int main() {
    int x = 5;
    int y = 10;
    int a = 20;
    int b = 1;
    int m = 100;
    int j = 1000;

    if (a == b && (m < j || x < y)) {
        std::cout << "TRUE";
    }
    return 0;
}
