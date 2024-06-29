// This program successfully uses both
// II cin >>and cin.get() for keyboard input.
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "Please enter a number: ";
    cin >> choice;

    cout << choice << endl;

    for (int i = 0; i < 20; i++) {
        cin >> choice;
        if (cin.fail()) {
            cout << "cin failed.\n";
        }
        cout << choice << endl;
    }
}
