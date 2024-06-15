#include <iostream>
using namespace std;

int main() {
    // PART ONE
    int int1 = 28, int2 = 32, int3 = 37, int4 = 24, int5 = 33;
    int i_sum, i_average;

    // Calculate sum
    i_sum = int1 + int2 + int3 + int4 + int5;

    // Calculate average
    i_average = i_sum / 5;

    // Print sum and findings
    cout << "[[ Part 1 ]]\n";
    cout << "The sum of " << int1 << " , " << int2 << " , " << int3 << " , "
         << int4 << " , and " << int5 << " is: " << i_sum << endl;

    cout << "The average of " << int1 << " , " << int2 << " , " << int3 << " , "
         << int4 << " , and " << int5 << " is: " << i_average << endl
         << endl;

    // PART TWO
    double d1 = 28.0, d2 = 32.0, d3 = 37.0, d4 = 24.0, d5 = 33.0;
    double d_sum, d_average;

    // Calculate sum
    d_sum = d1 + d2 + d3 + d4 + d5;

    // Calculate average
    d_average = d_sum / 5.0;

    cout << "[[ Part 2 ]]\n";
    cout << "The sum of " << d1 << " , " << d2 << " , " << d3 << " , " << d4
         << " , and " << d5 << " is: " << d_sum << endl;

    cout << "The average of " << d1 << " , " << d2 << " , " << d3 << " , " << d4
         << " , and " << d5 << " is: " << d_average << endl;
}
