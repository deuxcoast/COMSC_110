#include <cmath>
#include <iomanip>
#include <iostream>
#include <ostream>

// Menu options
const int CIRCLE_CHOICE = 1, RECTANGLE_CHOICE = 2, TRIANGLE_CHOICE = 3,
          QUIT_CHOICE = 4;

void showMenu();    // display the menu
void areaCircle();  // ask for user input and validate the value of radius until
                    // it is >= 0 then display the area

void areaRectangle();  // ask for user input and validate the values of length
                       // and width until both are >= 0 then display the area

void areaTriangle();  // ask for user input and validate the values of base and
                      // height until both are >= 0 then display the area

int main() {
    int userChoice;
    double area;

    showMenu();
    std::cin >> userChoice;

    std::cout << std::setprecision(2) << std::fixed;

    // Calculate area on shape determined by user input
    switch (userChoice) {
        case CIRCLE_CHOICE: {
            areaCircle();
            break;
        }
        case RECTANGLE_CHOICE: {
            areaRectangle();
            break;
        }
        case TRIANGLE_CHOICE: {
            areaTriangle();
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

void showMenu() {
    std::cout << "*** Geometry Area Calculator ***\n";

    std::cout << "1. Calculate the area of a circle.\n";
    std::cout << "2. Calculate the area of a rectangle.\n";
    std::cout << "3. Calculate the area of a triangle.\n";
    std::cout << "4. Quit.\n";
    std::cout << "Enter your choice (1-4): ";
}

void areaCircle() {
    const double PI = 3.14159;

    double radius, area;
    std::cout << "Please enter the value for the radius: ";
    std::cin >> radius;

    // Validate input
    if (radius < 0) {
        std::cout << "The radius should be non-negative. Please run the "
                     "program again.\n";
        std::cout << "Please enter the value for the radius: ";
        std::cin >> radius;
    }

    // Calculate area
    area = PI * pow(radius, 2.0);

    std::cout << "The area of the circle is: " << area << "\n";
}

void areaRectangle() {
    double length, width, area;
    std::cout << "Please enter the width of the rectangle: ";
    std::cin >> width;
    std::cout << "Please enter the length of the rectangle: ";
    std::cin >> length;

    // Validate input
    while (width < 0 || length < 0) {
        std::cout << "Both the length and width should be non-negative.\n";
        std::cout << "Please enter the width of the rectangle: ";
        std::cin >> width;
        std::cout << "Please enter the length of the rectangle: ";
        std::cin >> length;
    }

    // Calculate area
    area = width * length;

    std::cout << "The area of the rectangle is: " << area << "\n";
}

void areaTriangle() {
    double base, height, area;
    std::cout << "Please enter the base of the triangle: ";
    std::cin >> base;
    std::cout << "Please enter the height of the triangle: ";
    std::cin >> height;

    // Validate input
    while (base < 0 || height < 0) {
        std::cout
            << "Both the base and the height must be greater than zero.\n";
        std::cout << "Please enter the base of the triangle: ";
        std::cin >> base;
        std::cout << "Please enter the height of the triangle: ";
        std::cin >> height;
    }

    // Calculate area
    area = base * height * 0.5;

    std::cout << "The area of the triangle is: " << area << "\n";
}
