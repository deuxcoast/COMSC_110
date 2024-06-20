// COMSC-110 Ch5 (Module 7)
// LabExercise7.cpp
// This program uses nested for loops to display a multiplication (10 x 10)
// table.

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int SIZE = 10;
    const string TITLE = "**Multiplication Table**";

    // Display the header of the title
    // Use a for-loop to print the dash line according to the SIZE
    for (int i = 0; i <= SIZE; i++) {
        cout << setw(4) << "====";
    }
    cout << endl;
    // Calculate the spaces to make the title displayed in the center (next
    // line)
    int titleOffset = (SIZE / 2) - ((TITLE.length() / 4) / 2);

    for (int i = 0; i < titleOffset; i++) {
        cout << setw(4) << " ";
    }

    cout << TITLE << endl;

    // Use a for-loop to print the dash line according to the SIZE
    for (int i = 0; i <= SIZE; i++) {
        cout << setw(4) << "====";
    }
    cout << endl;

    cout << setw(4) << " ";

    // Part A - Use a for-loop to display 1 ~ 10 each digit in 4-space
    for (int i = 1; i <= 10; i++) {
        cout << setw(4) << i;
    }

    cout << endl;

    // Use a for-loop to display the dash line
    for (int i = 0; i <= SIZE; i++) {
        cout << setw(4) << "----";
    }
    cout << endl;

    for (int i = 1; i <= 10; i++) {
        // Part C - Display the beginning numbers
        cout << setw(3) << i << "|";
        for (int j = 1; j <= 10; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;  // add a new line at the end
    }

    return 0;
}
