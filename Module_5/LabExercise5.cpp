// COMSC-110 Lab Exercise 5
#include <iostream>

int main() {
    char ch;
    // Difference between the ASCII codes for lowercase and uppercase letters
    // e.g. 'A' is 65 and 'a' is 97
    const int LOWER_TO_UPPER_DIFF = 32;

    // Get a character from the user.
    std::cout << "Enter a lowercase letter, I will convert it to an uppercase "
                 "letter: ";
    ch = std::cin.get();
    std::cout << "The letter you entered is: " << ch << "\n";
    // Use if statement to check if the letter from the user input is a
    // lowercase letter then convert it to a uppercase letter
    ch = (ch >= 'a' && ch <= 'z') ? (ch - LOWER_TO_UPPER_DIFF) : ch;

    std::cout << "The uppercase letter is: " << ch << "\n\n";

    int radius = 5;
    radius = radius >= 0 ? radius : 0;

    // remove '\n' from keyboard buffer
    std::cin.ignore();

    std::cout << "Enter an uppercase letter, I will convert it to a lowercase "
                 "letter: ";
    ch = std::cin.get();
    std::cout << "The letter you entered is: " << ch << "\n";

    ch = (ch >= 'A' && ch <= 'Z') ? (ch + LOWER_TO_UPPER_DIFF) : ch;
    std::cout << "The lowercase letter is: " << ch << "\n\n";

    return 0;
}
