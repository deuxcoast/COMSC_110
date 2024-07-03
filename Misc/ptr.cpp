#include <iostream>
#include <ostream>
using namespace std;

void doubleArray(int* const ptr, int);
int main() {
    const int SIZE = 4;
    int nums[SIZE] = {10, 11, 25, 33};
    int* const ptr = nums;

    doubleArray(nums, SIZE);

    for (int val : nums) {
        cout << val << endl;
    }
}

void doubleArray(int* const ptr, int size) {
    for (int i = 0; i < size; i++) {
        // *(ptr + i) *= 2;
        *(ptr + i) = i * 10;
    }
}
