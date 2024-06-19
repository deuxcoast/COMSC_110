#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    std::cout << "*** Geometry Area Calculator ***\n";

    int userChoice;
    double area;

    // Menu options
    const int CIRCLE_CHOICE = 1, RECTANGLE_CHOICE = 2, TRIANGLE_CHOICE = 3,
              QUIT_CHOICE = 4;

    std::cout << "1. Calculate the area of a circle.\n";
    std::cout << "2. Calculate the area of a rectangle.\n";
    std::cout << "3. Calculate the area of a triangle.\n";
    std::cout << "4. Quit.\n";
    std::cout << "Enter your choice (1-4): ";
    std::cin >> userChoice;

    std::cout << std::setprecision(2) << std::fixed;

    // Calculate area on shape determined by user input
    switch (userChoice) {
    case CIRCLE_CHOICE: {
        const double PI = 3.14159;
        double radius;
        std::cout << "Please enter the value for the radius: ";
        std::cin >> radius;

        // Validate input
        if (radius < 0) {
            std::cout << "The radius should be non-negative. Please run the "
                         "program again.\n";
            break;
        }

        // Calculate area
        area = PI * pow(radius, 2.0);

        std::cout << "The area of the circle is: " << area << "\n";
        break;
    }
    case RECTANGLE_CHOICE: {
        double length, width;
        std::cout << "Please enter the width of the rectangle: ";
        std::cin >> width;
        std::cout << "Please enter the length of the rectangle: ";
        std::cin >> length;

        // Validate input
        if (width < 0 || length < 0) {
            std::cout << "Both the length and width should be non-negative. "
                         "Please run the program again.\n";
            break;
        }

        // Calculate area
        area = width * length;

        std::cout << "The area of the rectangle is: " << area << "\n";
        break;
    }
    case TRIANGLE_CHOICE: {
        double base, height;
        std::cout << "Please enter the base of the triangle: ";
        std::cin >> base;
        std::cout << "Please enter the height of the triangle: ";
        std::cin >> height;

        // Validate input
        if (base < 0 || height < 0) {
            std::cout << "Both the base and height should be non-negative. "
                         "Please run the program again.\n";
            break;
        }

        // Calculate area
        area = base * height * 0.5;

        std::cout << "The area of the triangle is: " << area << "\n";

        break;
    }
    case QUIT_CHOICE: {
        std::cout << "Adios amigo.\n";
        break;
    }
    default: {
        std::cout << "Invalid input. Please run the program again.\n";
        break;
    }
    }

    return 0;
}
