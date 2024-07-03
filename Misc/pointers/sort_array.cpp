
#include <iomanip>
#include <iostream>
#include <ostream>
void sort_array(int**, int);
void swap(int*, int*);
void show_array(int* arr[], int size);

int main() {
    const int SIZE = 12;
    int donations[SIZE] = {5, 100, 5, 25, 10, 5, 15, 50, 35, 10, 5, 10};

    int* donations_ptrs[SIZE];

    for (int i = 0; i < SIZE; i++) {
        donations_ptrs[i] = &donations[i];
    }
    show_array(donations_ptrs, SIZE);
    sort_array(donations_ptrs, SIZE);
    show_array(donations_ptrs, SIZE);
}

void sort_array(int* ptr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int idx = i, minIdx = i;
        int* minElem = ptr[i];
        for (int j = i + 1; j <= size; j++) {
            if (*(ptr[idx]) < *minElem) {
                minElem = ptr[idx];
                minIdx = idx;
            }
        }
        ptr[minIdx] = ptr[i];
        ptr[i] = minElem;
        // i = minIdx;
    }
}

void swap(int* a, int* b) {
    int* temp = nullptr;
    temp = a;
    a = b;
    b = temp;
}

void show_array(int* arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(6) << *(arr[i]);
    }

    std::cout << std::endl << std::endl;
}
