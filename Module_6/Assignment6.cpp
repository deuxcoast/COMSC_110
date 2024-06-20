#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>

int main() {
    int count = 1;
    do {
        int answer, guess;
        srand(time(NULL));
        int num1 = rand() % ((99 - 10) + 1) + 10;
        int num2 = rand() % ((99 - 10) + 1) + 10;
        answer = num1 + num2;

        std::cout << "Question " << count << ": ";
        std::cout << num1 << " + " << num2 << " = ";
        std::cin >> guess;

        while (guess != answer) {
            std::cout << "Sorry! your answer is incorrect. Please try again.\n";
            std::cout << "Question " << count << ": ";
            std::cout << num1 << " + " << num2 << " = ";
            std::cin >> guess;
        }
        std::cout << "Correct answer! " << num1 << " + " << num2 << " = "
                  << answer << std::endl;

        std::cout << "Move to the next question.\n";
        count++;
    } while (count <= 3);

    std::cout << "Congratulations! You completed all 3 questions!\n";

    return 0;
}
