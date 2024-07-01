// COMSC-110 Lab Exercise 9
// Conor Ney
//
// This program creates arrays of int, double, char and string data types
// using the initialization lists.
// Use for-loops and range-base for-loop to display the content of array
#include <iomanip>
#include <iostream>

using namespace std;
int main() {
    cout << "Lab Exercise 9 by Conor Ney\n\n";
    const int SIZE = 10;
    // create 4 arrays with different data types using the initialization list
    int array_i[SIZE] = {1, 2, 3, 4, 5,
                         6, 7, 8, 9, 10};  // assign the values you like
    double array_d[SIZE] = {
        1.2, 2.3, 3.4, 4.5, 5.6,
        6.7, 7.8, 8.9, 9.1, 10.11};  // assign the values you like
    char array_c[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f',
                          'g', 'h', 'i', 'j'};  // assign the values you like
    string array_s[SIZE] = {
        "why", "on",   "earth", "am", "i", "spending",
        "my",  "time", "this",  "way"};  // assign the values you like

    // Use a for-loop to display the content of array of int, double and char
    cout << "Use a for-loop to display the int, double and char arrays" << endl;
    cout << setw(10) << "INDEX" << setw(10) << "ARRAY1" << setw(10) << "ARRAY2"
         << setw(10) << "ARRAY3" << endl;
    for (int i = 0; i < 40; i++)
        cout << "=";
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << setw(10) << i;
        cout << setw(10) << array_i[i];
        cout << setw(10) << array_d[i];
        cout << setw(10) << array_c[i];
        cout << endl;
    }
    // Use a range-base for-loop to display the content of array
    cout << "Use a range-base for-loop to display the string array" << endl;
    for (auto val : array_s) {
        cout << setw(10) << val << endl;
    }
    cout << endl;
    return 0;
}
