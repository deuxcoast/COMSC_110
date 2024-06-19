#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

int main() {
    double x1, y1, x2, y2, m, distance;

    // seed random number generator
    unsigned seed = time(0);
    srand(seed);

    // generate two coordinates within range 0.00 - 49.99
    x1 = rand() % 50 + rand() % 100 * .01;
    y1 = rand() % 50 + rand() % 100 * .01;

    x2 = rand() % 50 + rand() % 100 * .01;
    y2 = rand() % 50 + rand() % 100 * .01;

    // calculate slope
    m = (y2 - y1) / (x2 - x1);

    // calculate distance
    distance = sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));

    // print coordinates
    std::cout << std::setprecision(2) << std::fixed;

    // print first point
    std::cout << std::left << std::setw(40)
              << "The coordinates of the first point: " << std::right << "("
              << std::setw(5) << x1 << ", " << std::setw(5) << y1 << ")\n";

    // print second point
    std::cout << std::left << std::setw(40)
              << "The coordinates of the second point: " << std::right << "("
              << std::setw(5) << x2 << ", " << std::setw(5) << y2 << ")\n";

    // print slope
    std::cout << std::setprecision(3);
    std::cout << std::left << std::setw(40)
              << "The slope between the two points: " << std::right
              << std::setw(14) << m << "\n";

    // print distance between points
    std::cout << std::left << std::setw(40)
              << "The distance between the two points: " << std::right
              << std::setw(14) << distance << "\n";

    // print information about slope
    std::cout << std::left << "It is a ";

    // print slope direction
    if (m > 0) {
        std::cout << "uphill and ";
    } else if (m < 0) {
        std::cout << "downhill and ";
    } else {
        std::cout << "straight line and ";
    }

    if (distance >= 30) {
        std::cout << "long-distance travel.\n";
    } else {
        std::cout << "short-distance travel.\n";
    }

    return 0;
}
