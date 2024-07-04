// Conor Ney
// COMSC-110 Chapter 9  Example 6
// Ch9_Example9.cpp
// This program uses a pointer to display the contents of an array.

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 8;
    int set[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};
    int* numPtr = nullptr;  // Pointer
    int count;              // Counter variable for loops
    numPtr = set;           // Make numPtr point to the set array.

    int* otherPtr = set;

    // Use the pointer to display the array contents.
    cout << "The numbers in set are:\n";
    for (count = 0; count < SIZE; count++) {
        cout << *numPtr << " ";
        numPtr++;
    }
    cout << endl;
    // Display the array contents in reverse order.
    cout << "The numbers in set backward are:\n";
    for (count = 0; count < SIZE; count++) {
        numPtr--;
        cout << *numPtr << " ";
    }
    cout << endl;

    // ANSWER: this is comparing lvalues - the addresses held in each pointer
    // are being compared.
    if (otherPtr == numPtr) {
        cout << "otherPtr = " << otherPtr << endl;
        cout << "numPtr = " << numPtr << endl;
    }

    // ANSWER: this is comparing rvalues - the values held at the address stored
    // in otherPtr and numPtr
    if (*otherPtr == *numPtr) {
        cout << "*otherPtr = " << *otherPtr << endl;
        cout << "*numPtr = " << *numPtr << endl;
    }

    // ANSWER: this is comparing the addresses for the second element in the
    // array. We are using pointer arithmetic to incremented the address by
    // 1 * sizeof(int)
    if (otherPtr + 1 == numPtr + 1) {
        cout << "(otherPtr + 1) = " << (otherPtr + 1) << endl;
        cout << "(numPtr + 1)= " << (numPtr + 1) << endl;
    }

    // ANSWER: here we are dereferencing the value held at the address of the
    // second element in the array. This syntax is equivalent to set[1] or even
    // otherPtr[1] or numPtr[1]. We are comparing rvalues.
    if (*(otherPtr + 1) == *(numPtr + 1)) {
        cout << "*(otherPtr + 1) = " << *(otherPtr + 1) << endl;
        cout << "*(numPtr + 1)= " << *(numPtr + 1) << endl;
    }

    // Question 2
    // We can use pointer notation with array names and we can use bracket
    // notation with pointers, the two are interchangable.

    cout << "Displaying the numbers backwards using bracket notation with an "
            "array:\n";
    for (int i = SIZE - 1; i >= 0; i--) {
        cout << otherPtr[i] << " ";
    }

    return 0;
}
