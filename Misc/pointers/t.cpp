#include <iomanip>
#include <iostream>
#include <ostream>

void showTable(int*);

int main() {
    int* iptr = nullptr;
    iptr = new int[100];

    for (int i = 0; i < 100; i++) {
        iptr[i] = i;
    }
    showTable(iptr);

    delete[] iptr;
}

void showTable(int* ptr) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int idx = (i * 10) + j;
            std::cout << std::setw(6) << ptr[idx];
        }
        std::cout << std::endl;
    }
}
