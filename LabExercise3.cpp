#include <iomanip>
#include <iostream>
int main() {
  const int TEST_COUNT = 5;

  int score1, score2, score3, score4, score5;
  double total, avg;

  std::cout
      << "*** This program calculates the average of five test scores ***\n";
  std::cout << "Please provide the five test scores separated by a space:\n";
  std::cin >> score1 >> score2 >> score3 >> score4 >> score5;

  total = score1 + score2 + score3 + score4 + score5;
  avg = total / TEST_COUNT;

  std::cout << "Test Scores Analysis\n";
  std::cout << "====================\n";
  std::cout << "Test 1:" << std::setw(6) << score1 << std::endl;
  std::cout << "Test 2:" << std::setw(6) << score2 << std::endl;
  std::cout << "Test 3:" << std::setw(6) << score3 << std::endl;
  std::cout << "Test 4:" << std::setw(6) << score4 << std::endl;
  std::cout << "Test 5:" << std::setw(6) << score5 << std::endl;
  std::cout << "Total :" << std::setw(6) << total << std::endl;
  std::cout << "====================\n";
  std::cout << "Average: " << std::setprecision(3) << avg << std::endl;

  return 0;
}
