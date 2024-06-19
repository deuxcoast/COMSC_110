#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
int main() {
    double weight, height;

    std::cout << "*** This phone calculates the BMI (Body Mass Index) ***\n";

    std::cout << "Please enter your weight in pounds: ";
    std::cin >> weight;

    std::cout << "Please enter your height in inches: ";
    std::cin >> height;

    // Calculate BMI
    const int CONVERSION_FACTOR = 703;
    double bmi = (weight * CONVERSION_FACTOR) / pow(height, 2.0);

    std::cout << std::setprecision(1) << std::fixed << std::endl;

    std::cout << std::left << std::setw(40) << "Your weight in pounds:";
    std::cout << std::right << std::setw(5) << weight << "\n";

    std::cout << std::left << std::setw(40) << "Your height in inches:";
    std::cout << std::right << std::setw(5) << height << "\n";

    std::cout << std::left << std::setw(40) << "Your Body Mass Index (BMI) is:";
    std::cout << std::right << std::setw(5) << bmi << "\n\n";

    std::cout << "            << Body Mass Index >>\n";
    std::cout << "=============================================\n";

    std::cout << "Overweight with BMI > 25\n";
    std::cout << "Optimal weight for 25 >= BMI >= 18.5\n";
    std::cout << "Underweight with BMI < 18.5\n";

    std::cout << "=============================================\n";

    if (bmi > 25.0) {
        std::cout << "Your BMI is high.\n";
        std::cout << "That is okay as long as you are happy.\n";
    } else if (bmi <= 25.0 && bmi >= 18.5) {
        std::cout << "Your BMI is in the optmial region for your weight and "
                     "height.\n";
        std::cout << "Keep doing whatever you're doing.\n";
    } else if (bmi < 18.5 && bmi > 0) {
        std::cout << "Your BMI is low.\n";
        std::cout << "That is okay as long as you are happy.\n";
    } else {
        std::cout << "Incorrect measurements.\n";
        std::cout << "This is not a valid BMI, please try again.\n";
    }

    return 0;
}
