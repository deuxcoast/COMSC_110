// COMSC-110 Ch6 Module 9
// Conor Ney
//
// This program modified from Assignment 4 including few function
// displays a menu to allow the user to choose
// and find the area of a circle, rectangle or triangle
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
    int user_choice;

    do {
        showMenu();
        // read input and only accept numbers
        if (!(std::cin >> user_choice)) {
            break;
            std::cout << "Please enter numbers only.\n\n";
            // clear the error on the flag on cin
            std::cin.clear();
            // skip to the new line
            std::cin.ignore(10000, '\n');
            // exit this iteration of do-while loop
            continue;
        }

        while (user_choice < CIRCLE_CHOICE || user_choice > QUIT_CHOICE) {
            std::cout << "Please enter a valid menu choice: ";
            std::cin >> user_choice;
        }

        if (user_choice != QUIT_CHOICE) {
            // setup formatting for future cout output
            std::cout << std::setprecision(2) << std::fixed;

            // Calculate area on shape determined by user input
            switch (user_choice) {
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
                default: {
                    std::cout
                        << "Invalid input. Please run the program again.\n";
                    break;
                }
            }
        }

    } while (user_choice != QUIT_CHOICE);
    std::cout << "Adios amigo.\n";
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

    // Validate radius is non-negative
    if (radius < 0) {
        std::cout << "The radius should be non-negative. Please run the "
                     "program again.\n";
        std::cout << "Please enter the value for the radius: ";
        std::cin >> radius;
    }

    // Calculate area
    area = PI * pow(radius, 2.0);

    std::cout << "The area of the circle is: " << area << "\n\n";
}

void areaRectangle() {
    double length, width, area;

    std::cout << "Please enter the width of the rectangle: ";
    std::cin >> width;

    // validate width is postive number
    while (width < 0) {
        std::cout << "The width should be non-negative.\n";
        std::cout << "Please enter the width of the rectangle: ";
        std::cin >> width;
    }
    // validate length is positive number
    std::cout << "Please enter the length of the rectangle: ";
    std::cin >> length;
    while (length < 0) {
        std::cout << "The length should be non-negative.\n";
        std::cout << "Please enter the length of the rectangle: ";
        std::cin >> length;
    }

    // Calculate area
    area = width * length;

    std::cout << "The area of the rectangle is: " << area << "\n\n";
}

void areaTriangle() {
    double base, height, area;
    std::cout << "Please enter the base of the triangle: ";
    std::cin >> base;

    // validate base is non-negative
    while (base < 0) {
        std::cout << "The base should be non-negative.\n";
        std::cout << "Please enter the base of the triangle: ";
        std::cin >> base;
    }
    std::cout << "Please enter the height of the triangle: ";
    std::cin >> height;

    // validate height is non-negative
    while (height < 0) {
        std::cout << "The height should be non-negative.\n";
        std::cout << "Please enter the height of the triangle: ";
        std::cin >> height;
    }

    // Calculate area
    area = base * height * 0.5;

    std::cout << "The area of the triangle is: " << area << "\n\n";
}
