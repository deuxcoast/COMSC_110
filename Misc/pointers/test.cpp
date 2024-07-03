#include <iostream>
#include <ostream>
int main() {
    int* ptr;
    int arr[10] = {0};
    ptr = arr;
    ptr = ptr + 5;
    *ptr = 100;
    for (auto val : arr) {
        std::cout << val << std::endl;
    }
}
