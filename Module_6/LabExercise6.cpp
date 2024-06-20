// COMSC-110 Lab Exercise
// LabExercise6_Sample.cpp
// This program prompts for the user inputs of travel speed and time
// Apply while-loop to do the input validation
// at the end using a while-loop to display the hourly travelled distance
#include <ios>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double speed; // the speed of the vehicle
    int time;     // the travelled time in hours

    // get the travel speed
    cout << "What is the speed of the vehicle (miles/hour): ";
    cin >> speed;
    while (speed < 0) {
        cout << "Invalid input! The speed of the vehicle must be greater or "
                "equal to zero\n";
        cout << "What is the speed of the vehicle (miles/hour): ";
        cin >> speed;
    }
    // get the travel time
    cout << "How many hours has it travelled (integer only): ";
    cin >> time;

    while (time < 1) {
        cout << "Invalid input! The travelled time can't be under one hour.\n";

        cout << "How many hours has it travelled (integer only): ";
        cin >> time;
    }
    // Use a while-loop to display the output in a table format
    // how to set the precision?
    // Display the title of the table
    cout << setw(8) << "Hour" << setw(30) << "Distance Travelled (miles)"
         << endl;
    cout << "============================================" << endl;

    cout << setprecision(1) << fixed;
    // set a count
    int count = 1;
    while (count <= time) {
        cout << setw(8) << count << setw(30) << speed * count << endl;
        count++;
    }
    return 0;
}
