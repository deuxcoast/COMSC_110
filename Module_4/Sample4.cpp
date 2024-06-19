// COMSC-110 Chapter 4 Lab Exercise 4 sample file
// LabExercise4_sample.cpp
// This program creates random coordinates of two points between 0~50
// in two-digit in decimal
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib> // rand and srand
#include <ctime>   // For the time function
using namespace std;
int main() {
    double x1, x2, y1, y2;
    double slope, distance;
    // Get the system time.
    unsigned seed = (unsigned)time(0);
    // Seed the random number generator.
    srand(seed);
    // Assign the random coordinates between 0~50 with 2-digits in decimal
    x1 = rand() % 50 + rand() % 100 * 0.01;
    x2 = rand() % 50 + rand() % 100 * 0.01;
    y1 = rand() % 50 + rand() % 100 * 0.01;
    y2 = rand() % 50 + rand() % 100 * 0.01;
    // Display the coordinates of the two points in the console
    cout << setprecision(2) << showpoint << fixed;
    cout << left << setw(40) << "The coordinates of the first point:";
    cout << right << "(" << setw(5) << x1 << ", " << setw(5) << y1 << ")"
         << endl;
    cout << left << setw(40) << "The coordinates of the second point:";
    cout << right << "(" << setw(5) << x2 << ", " << setw(5) << y2 << ")"
         << endl;
    // calcuate the slope and the distance between two points
    //  Use the slope formula to calculate the slope from the two points
    //  Use the distance formula to calculate the distance between the two
    //  points Display the slope between and distance 3-digit in decimal
    cout << setprecision(3) << showpoint << fixed;
    cout << left << setw(40) << "The slope between the two points:" << right
         << setw(14) << slope << endl;
    cout << left << setw(40) << "The distance between the two points:" << right
         << setw(14) << distance << endl;
    // use if-else statement check the slope to display "downhill" or "uphill"
    // use if-else statement check the distance to display "long-distance" or
    // "short-
    // distance "
    return 0;
}
